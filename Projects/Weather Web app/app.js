const apiKey = 'b48f2fff5f1f52d7948e000544803467';
const form = document.querySelector('form'); 
const temp = document.querySelector('.temp');
const t_minmax = document.querySelector('.t_minmax');
const loc = document.querySelector('.loc');
const type = document.querySelector('.type');
const humanDate = document.querySelector('.date');
const humid = document.querySelector('.humid');
const pressure = document.querySelector('.pressure');

const clearWeather = "https://img4.goodfon.com/wallpaper/nbig/e/cc/nebo-oblaka-iasnaia-pogoda-solntse-priroda.jpg";
const cloudyWeather = "https://www.wallpapertip.com/wmimgs/174-1740905_cloudy-weather-wallpaper-hd.jpg";
const haze = "https://images.unsplash.com/36/STzPBJUsSza3mzUxiplj_DSC09775.JPG?ixid=MnwxMjA3fDB8MHxzZWFyY2h8MXx8aGF6ZXxlbnwwfHwwfHw%3D&ixlib=rb-1.2.1&w=1000&q=80";
const drizzle = "https://images.unsplash.com/photo-1519692933481-e162a57d6721?ixid=MnwxMjA3fDB8MHxzZWFyY2h8Nnx8cmFpbnxlbnwwfDB8MHx8&ixlib=rb-1.2.1&auto=format&fit=crop&w=500&q=60";


function getWeather(city){
fetch(`https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${apiKey}&units=metric`)
    .then((res)=>{
        return res.json();
    })
    .then((data)=>{
        console.dir(data);
        const tempData = data.main.temp;
        const mintemp = data.main.temp_min;
        const maxtemp = data.main.temp_max;
        const place = data.name;
        const country = data.sys.country;
        const w_type = data.weather[0].main;
        const w_pres = data.main.pressure;
        const w_humid = data.main.humidity;
       
        const unixDate = data.dt;
        const ms = unixDate*1000;
        const dateObject = new Date(ms);
        const day = dateObject.toLocaleString("en-US", {weekday:"long"});
        const month = dateObject.toLocaleString("en-US", {month:"long"});
        const date = dateObject.toLocaleString("en-US", {day:"numeric"});
        const hr = dateObject.toLocaleString("en-US", {hour:"numeric", minute: "numeric", hour12: true});
        
        humanDate.textContent = `${day}, ${date} ${month} ${hr}`;
        loc.textContent = `${place}, ${country}`;
        temp.textContent = `${tempData.toFixed(1)} °C`;
        t_minmax.textContent = `Hi: ${maxtemp.toFixed(1)}°C | Lo: ${mintemp.toFixed(1)}°C`;
        type.textContent = `${w_type}`;
        humid.textContent = `Humidity: ${w_humid}%`;
        pressure.textContent = `Pressure: ${w_pres} hPa`;

        if(w_type=='Clouds' || 'Thunderstorm'){
            document.body.style.backgroundImage = `url(${cloudyWeather})`;
        }
        if(w_type=='Clear'){
            document.body.style.backgroundImage = `url(${clearWeather})`;
        }
        if(w_type=='Haze' || w_type=='Mist'){
            document.body.style.backgroundImage = `url(${haze})`;
        }
        if(w_type=='Drizzle' || w_type=='Rain'){
            document.body.style.backgroundImage = `url(${drizzle})`;
        }
    })
    
    .catch((err)=>{
        alert("Invalid city name. Please try again!");
    });
}


form.addEventListener('submit', (e) => {
    e.preventDefault();

    const city = form.elements[0].value;
    getWeather(city);

    form.elements[0].value="";
})
