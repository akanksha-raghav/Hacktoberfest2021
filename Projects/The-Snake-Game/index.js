// game constansts & variables

let inputDir ={x:0 ,y:0};
let foodSound=new Audio('music/food.mp3');
let gameOverSound=new Audio('music/gameover.mp3');
let moveSound=new Audio('music/move.mp3');
let musicSound =new Audio('music/bgmusic.mp3');
let speed =10; 
let lastPaintTime=0;
let score =0;
let snakeArr=[
    {x:13,y:15}
];
 food={x:6,y:7};

// game functions

//   ctime -current time
// game loops :  instead of set intervals we use requestAnimationFrame 

function main(ctime)
{
    // console.log(ctime);
    window.requestAnimationFrame(main);
   if((ctime-lastPaintTime)/1000 < 1/speed)    //jab tak for eg. speed =2 , then it will not print screen until 0.5 seconds
 {
    return;
 }   
 lastPaintTime =ctime;
 gameEngine();
}

function isCollide(sarr)
{
    // agar khud ko kha liya to 
    for(let i =1;i<sarr.length;i++)
    {
            // agar uska muh khud ki puch se takra gya , uska code
        if(sarr[i].x ===sarr[0].x && sarr[i].y ===sarr[0].y)
        {
            return true;
        }
    }
    // agar snake grid se takra gya to uska code
        if(sarr[0].x >=18  || sarr[0].x <=0 ||  sarr[0].y >=18  || sarr[0].y <=0 )
        {
            return true;
        }
    
}

function gameEngine()
{
    // Part 1: updating the snake array
    //1/ Agar snake kahi takrayega to isCollide
            if(isCollide(snakeArr))
            {
                gameOverSound.play();
                musicSound.pause();
                inputDir ={x:0 ,y:0};
                alert("game over , Press any key to play again!");
                snakeArr= [{ x:13 ,y:15}];
                musicSound.play();
                score =0;
            }


            // Agar snake ne khana kha liya to . food ki location change karni hogi

            if(snakeArr[0].y ===food.y && snakeArr[0].x ===food.x)  // agar snake ki mundi , food se match kar degi to hi body add hogi
            {
                foodSound.play();
                score+=1;
                scoreBox.innerHTML="Score :" +score;
                snakeArr.unshift({x : snakeArr[0].x +inputDir.x , y : snakeArr[0].y +inputDir.y });  // snake ki arr mei x mei input add karunga wrt to x and y
                
                let a=2;  
                let b=16;
                food ={ x:Math.round(a + (b-a)*Math.random() ),y:Math.round(a + (b-a)*Math.random() )   }
            // this above code is generated beacase we have to place food anywhere else(random no. is generated and a and b will be limit between where the no. will be generated)
            
        }
     
        // Moving the snake 

        for(let i=snakeArr.length-2;i>=0;i--)
        {
            // const element =snakeArr[i];
            snakeArr[i+1] ={...snakeArr[i]};
        }
        snakeArr[0].x +=inputDir.x;
        snakeArr[0].y +=inputDir.y;
   // Part 2: Display the snake and Food
                // Code to  Display the snake

                board.innerHTML = "";
                snakeArr.forEach((e, index)=>{
                    snakeElement = document.createElement('div');
                    snakeElement.style.gridRowStart = e.y;
                    snakeElement.style.gridColumnStart = e.x;

                    if(index === 0){
                        snakeElement.classList.add('head');
                    }
                    else{
                        snakeElement.classList.add('snake');
                    }
                    board.appendChild(snakeElement);
                });

                //Code to  Display the food
                foodElement = document.createElement('div');
                foodElement.style.gridRowStart = food.y;
                foodElement.style.gridColumnStart = food.x;
                foodElement.classList.add('food')
                board.appendChild(foodElement);


}


// logic starts here
window.requestAnimationFrame(main);
window.addEventListener('keydown',e=>{
    inputDir ={ x:0 ,y:1};     //Start the game
    moveSound.play();
    switch(e.key)
    {
        case "ArrowUp":console.log("Arrow Up");
                        inputDir.x=0;
                        inputDir.y=-1;
                        break;

        case "ArrowDown":console.log("Arrow Down");
                        inputDir.x=0;
                        inputDir.y=1;
                        break;

        case "ArrowLeft":console.log("Arrow Left");
                        inputDir.x=-1;
                        inputDir.y=0;
                        break;

        case "ArrowRight":console.log("Arrow Right");
                        inputDir.x=1;
                        inputDir.y=0;
                        break;

        default: 
        break;
    }
});
