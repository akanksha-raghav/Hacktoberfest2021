var drumButton = document.querySelectorAll(".drum").length;


for(var i = 0 ; i < drumButton ; i++){
    document.querySelectorAll(".drum")[i].addEventListener("click", function(e){
        var buttonInnerHTML=this.innerHTML;
        console.log("inside click")
        makeSound(buttonInnerHTML);
        buttonAnimation(buttonInnerHTML);
});

}



document.addEventListener("keydown",function(event){
      
    makeSound(event.key);
    buttonAnimation(event.key);

 });


 function makeSound(value){

    switch(value){
        case "w":
               var  audio = new Audio('/sounds/tom-1.mp3');
                    audio.play();
                    break;
      case "a":
               var  audio = new Audio('/sounds/tom-2.mp3');
                    audio.play();
                    break;
     case "s":
                     var  audio = new Audio('/sounds/tom-3.mp3');
                          audio.play();
                          break;

     case "d":
                     var  audio = new Audio('/sounds/tom-4.mp3');
                                  audio.play();
                                  break;
          case "j":
                     var  audio = new Audio('/sounds/crash.mp3');
                          audio.play();
                                          break;
                                          case "k":
                                             var  audio = new Audio('/sounds/kick.mp3');
                                                  audio.play();
                                                  break;
                                                  case "l":
                                                     var  audio = new Audio('/sounds/snare.mp3');
                                                          audio.play();
                                                          break;

                                                          default: console.log(value)
                                                                             
 }


 }


 function buttonAnimation(currentKey){
    var activeButton = document.querySelector("."+currentKey);
    activeButton.classList.add("pressed");

    setTimeout(function(){
       activeButton.classList.remove("pressed");
    },100)
 }

