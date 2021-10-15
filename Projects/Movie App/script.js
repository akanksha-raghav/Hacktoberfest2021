/******************************************
 *  Author : Pratibha Singh  
 *******************************************/

const GET_API = 'https://api.themoviedb.org/3/discover/movie?sort_by=popularity.desc&api_key=3fd2be6f0c70a2a598f084ddfb75487c&page=2';
const IMG_PATH = 'https://image.tmdb.org/t/p/w1280';
const SEARCH_API = 'https://api.themoviedb.org/3/search/movie?api_key=3fd2be6f0c70a2a598f084ddfb75487c&query=';

const container = document.querySelector('.movie-container');
const form = document.querySelector('form');
const input = document.getElementById('search-input');

getMovies(GET_API);

form.addEventListener('submit', (event) => {
    event.preventDefault();

    const searchValue = input.value;
    input.value = '';

    if (searchValue) {
        getMovies(SEARCH_API + searchValue);
        console.log(SEARCH_API + searchValue);
    } else {
        window.location.reload();
    }
});

async function getMovies(url) {
    const result = await fetch(url);
    const data = await result.json();
    showResult(data.results);
}

function showResult(movies) {
    container.innerHTML = '';

    movies.forEach(movie => {
        const { title, poster_path, vote_average, overview } = movie;

        if (poster_path) {
            const movieElement = document.createElement('div');
            movieElement.classList.add('movie');
            container.appendChild(movieElement);

            movieElement.innerHTML = `
                <img src="${IMG_PATH + poster_path}" alt="${title}">
                <div class="info">
                    <div class="title">
                        <h3>${title}</h3>
                    </div>
                    <div class="rating">
                        <p class="${getClassByRate(vote_average)}">${vote_average}</p>
                    </div>
                </div>
                <p class="overview">${overview}</p>`;
        }
    });
}

function getClassByRate(vote) {
    if (vote >= 8) {
        return 'green';
    } else if (vote >= 5) {
        return 'orange';
    } else {
        return 'red';
    }
}