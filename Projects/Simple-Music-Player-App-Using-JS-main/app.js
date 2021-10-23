const song = document.getElementById("song");
const playBtn = document.getElementById("play");
const title = document.querySelector(".mainTitle");
const singer = document.querySelector(".subTitle");
const previousBtn = document.querySelector("#previous");
const nextBtn = document.querySelector("#next");
const songImage = document.querySelector("#image");

const progress = document.querySelector(".pBar");
const cTime = document.querySelector(".ctime");
const totalTime = document.querySelector(".totalTime");
const progressBar = document.querySelector(".progressBar");



let isPlaying = false;

// Array of objects

const songs = [{
        name: "1.mp3",
        title1: "Cheap Thrills",
        artist: "Sia Furler",
        cover: "1.jpg"
    },
    {
        name: "2.mp3",
        title1: "Angry Bird",
        artist: "John Wilson",
        cover: "2.jpg"
    },
    {
        name: "3.mp3",
        title1: "O Brave",
        artist: "Albert Forge",
        cover: "3.jpg"
    }
];

function playMusic() {
    isPlaying = true;
    song.play();
    playBtn.classList.replace('fa-play', 'fa-pause');
    songImage.classList.add('anime');
}

function pauseMusic() {
    isPlaying = false;
    song.pause();
    playBtn.classList.replace('fa-pause', 'fa-play');
    songImage.classList.remove('anime');
}

playBtn.addEventListener('click', () => {
    if (isPlaying) {
        pauseMusic();
    } else {
        playMusic();
    }
});



// Changing song title and artist name

function Play(songs) {
    title.textContent = songs.title1;
    singer.textContent = songs.artist;
    song.src = songs.name;
    songImage.src = songs.cover;
    playMusic();
}




let songCount = 0;

nextSongPlay = () => {
    if (songCount === 2) {
        songCount = -1;
    }
    Play(songs[++songCount]);
}

nextBtn.addEventListener('click', () => {
    nextSongPlay();
});

previousSongPlay = () => {
    --songCount;
    if (songCount === -1) {
        songCount = 2;
    }
    Play(songs[songCount]);
}

previousBtn.addEventListener("click", () => {
    previousSongPlay();
});


// Progress Bar

let cMins = 0;

window.addEventListener('load', () => {
    song.addEventListener('timeupdate', (event) => {

        const { duration, currentTime } = event.srcElement;

        var duratiosn = (currentTime / duration) * 100;
        progress.style.width = `${duratiosn}%`;

        // Updating total Duration

        let secondss = Math.floor(duration % 60);
        let minss = Math.floor(duration / 60);

        if (duration) {
            totalTime.textContent = `${minss}:${secondss}`;
        }

        // Continuously updating another time    


        let cSecondss = Math.floor(currentTime % 60);
        let cMinss = Math.floor(currentTime / 60);

        if (cSecondss < 10) {
            cSecondss = "0" + cSecondss;
        }

        cTime.textContent = `${cMinss}:${cSecondss}`;
    });
});

song.addEventListener('ended', () => {
    songImage.classList.remove("anime");
    nextSongPlay();
});

progressBar.addEventListener("click", (event) => {
    var clientWidth = event.srcElement.clientWidth;
    var offsetX = event.offsetX;

    var time = ((offsetX / clientWidth) * song.duration);

    song.currentTime = time;
});