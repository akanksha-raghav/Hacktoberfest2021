const HOURSTIME = document.querySelector("#hr-hand");
const MINUTESTIME = document.querySelector("#min-hand");
const SECONDTIME = document.querySelector("#sec-hand");


function clockIntervalTick() {
    var date = new Date();
    console.log(date);
    
    let hr = date.getHours();
    let min = date.getMinutes();
    let sec = date.getSeconds();
    
    console.log("Hour: " + hr + " Minutes: " + min + " Seconds: " + sec);
    
    let hrPosition = (hr*360/12)+(min*(360/60)/12);
    let minPosition = (min*360/60)+(sec*(360/60)/60);
    let secPosition = (sec*360/60);
    
    HOURSTIME.style.transform = "rotate(" + hrPosition + "deg)";
    MINUTESTIME.style.transform = "rotate(" + minPosition + "deg)";
    SECONDTIME.style.transform = "rotate(" + secPosition + "deg)";
    
}

var clockInterval = setInterval(clockIntervalTick, 1000);
