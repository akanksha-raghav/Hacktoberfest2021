const express = require('express')
const socket = require('socket.io')
const redis = require('redis')
const dotenv = require('dotenv')
const JSONCache = require('redis-json')
const randomWords = require('random-words');

const client = redis.createClient(process.env.REDIS_URL)
const jsonCache = new JSONCache(client)

client.on("error", error => {
  console.error(error)
})

dotenv.config()

const app = express()

// Start Server 🎉
const PORT = process.env.PORT || 3001
let server = app.listen(PORT, () => {
  console.log(`Web server listening on ${PORT}`)
})

const io = socket(server, {
  cors: {
    origin: '*',
  },
})

const onConnection = socket => {
  socket.on('gathering:join', async gatheringId => {
    const attendees = await jsonCache.get(gatheringId)
    if (!attendees) {
      socket.emit('gathering', 404)
    } else {
      socket.join(gatheringId)
      socket.emit('gathering', {gatheringId, attendees})
    }
  })

  socket.on('gathering:create', async () => {
    let id = randomWords()
    while (true) {
      const collision = await jsonCache.get(id)
      console.log(id)
      if (collision === undefined) {
        break
      } else {
        id = randomWords()
      }
    }
    const attendees = []
    jsonCache.set(id, attendees)
    socket.join(id)
    io.in(id).emit('gathering', {id, attendees})
  })

  socket.on('gathering:add', async socials => {
    const [, gatheringId] = Array.from(socket.rooms)
    if (gatheringId) {
      let attendees = await jsonCache.get(gatheringId)
      attendees = [...attendees, socials]
      jsonCache.set(gatheringId, attendees)
      io.in(gatheringId).emit('gathering', {gatheringId, attendees})
    }
  })
}

io.on('connection', onConnection)
