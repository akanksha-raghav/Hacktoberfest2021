// const getLyrics = require('./src/lyrics')

console.log('client side working')

const lyricForm = document.querySelector('form')
const artist = document.querySelector('#artist')
const song = document.querySelector('#song')
const para = document.querySelector('.lyrics')
const link = document.querySelector('a')
reFresh = document.querySelector('.color-change')

var bgcolorlist = ['#84ED0C', '#EB2D2D', '#EBE52D', '#92EB2D','#2DEB3C','#2DEB9C','#2DA8EB','#9C2DEB'];


  var randomNumber = Math.floor(Math.random()*bgcolorlist.length)


reFresh.style.backgroundColor = bgcolorlist[randomNumber]

lyricForm.addEventListener('submit', async(e)=>{
    e.preventDefault()
    para.textContent = " "
    const response = await fetch("https://shazam.p.rapidapi.com/search?term="+artist.value+" "+song.value+"&locale=en-US&offset=0&limit=5", {
        "method": "GET",
        "headers": {
            "x-rapidapi-key": process.env.RAPID_API_KEY,
            "x-rapidapi-host": "shazam.p.rapidapi.com"
        }
    })
    const data = await response.json()
    const _id = data.tracks.hits[0].track.key

    const songR = await fetch("https://shazam.p.rapidapi.com/songs/get-details?key="+_id+"&locale=en-US", {
        "method": "GET",
        "headers": {
            "x-rapidapi-key": process.env.RAPID_API_KEY,
            "x-rapidapi-host": "shazam.p.rapidapi.com"
        }
    })
    const songResult = await songR.json()
    if(songResult.sections[1].type !="LYRICS"){
        // para.textContent = 'Please check the artist/song name or try again in 10 seconds.'
        const r = await fetch("https://genius.p.rapidapi.com/search?q="+artist.value+" "+song.value, {
            "method": "GET",
            "headers": {
                "x-rapidapi-key": process.env.RAPID_API_KEY,
                "x-rapidapi-host": "genius.p.rapidapi.com"
            }
        })

        const d = await r.json()
        const id = d.response.hits[0].result.id

        const result = await fetch("https://genius.p.rapidapi.com/songs/"+id, {
            "method": "GET",
            "headers": {
                "x-rapidapi-key": process.env.RAPID_API_KEY,
                "x-rapidapi-host": "genius.p.rapidapi.com"
            }
        })

        const d1 = await result.json()
        link.href = d1.response.song.url
        link.target = "_blank"
        link.textContent = d1.response.song.url
    }
    else{
           songResult.sections[1].text.forEach((line) => {
               para.textContent += line + "\n"
           });
       

    }
    // para.textContent = data.lyrics
    
})