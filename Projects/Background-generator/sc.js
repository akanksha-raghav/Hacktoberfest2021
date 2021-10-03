const body= document.querySelector("body");
const h1= document.querySelector(".ram");
const right=document. querySelector(".Right");
const left= document.querySelector(".left");
const cssOutput = document.querySelector(".css-output");


let leftcolor = left.value;
let rightcolor = right.value;

console.log(rightcolor);

const changebackground = () => {
    const cssstring= `linear-gradient(to left, ${leftcolor}, ${rightcolor})`;

    body.style.background= cssstring;
  cssOutput.textContent=  `background: ${cssstring};`;
};



left.addEventListener("change",(event)=>{
    leftcolor=event.target.value;
    changebackground();
});

right.addEventListener("change",(event)=>{
    rightcolor=event.target.value;
    changebackground();
});

changebackground();

