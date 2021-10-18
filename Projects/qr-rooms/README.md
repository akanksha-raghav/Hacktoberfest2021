# QR Rooms

QR Rooms is a mobile web app that enables groups of people unfamiliar with each other to connect up with social medias. Optimal use would 3-10 people. 

Without the use of QR Rooms, a group of people would each have to go to each person and exchange socials media usernames. 

With QR Rooms, a person would set up a room by going to QR Rooms site then when everyone is located to the site by simply scanning the qr code (or typing in the simple url which uses basic nouns as the room id), users would then input their usernames and then everyone in the room would be able to add them on their inputted social media.

The idea came from being at poker table and realising how inefficient it would be to go to each person and exchange usernames. However, the scenario doesn't happen enough for the app to be regularly used, but the idea shows how QR Codes and Sockets can bring people together from a physical space to a digital space at a scan.

[**Live Demo**](https://confident-booth-024076.netlify.app/) - Since I'm using a free heroku deployment, the api may fall asleep (you may need to refresh the page after a few seconds, as soon as you open the link a room should be generated, visible by a room id (random noun) being generated at the end of the link `/sand`)

Try the web app out on mobile and scan the QR code to join people to the room.

(This web app is not scalable or secure)

## Tech Stack

React, Bootstrap, Sass, Socket.io, Node.js, Express, Redis.

For the QR Code generate I have used the `react-qr-code` library.

For the id generation I have used the `random-words` library.

## Runing the app locally

Requires Node, Npm and Redis.

### Front

Create a `.env` and input the `REACT_APP_DEV_SOCKET` as seen by the `.env.example` file.

`cd front` (in front directory)
`npm i`
`npm start`

### Back

Create a `.env` and input the `REDIS_URL` as seen by the `.env.example` file.

Redis needs to be installed and running on your machine. The url for the redis will most likely be `redis://localhost:6379`.

Download here: https://redis.io/download

(In a new terminal)
`cd back` (in back directory) || `cd ../back` (from front directory)
`npm i`
`npm start` or `node index`


