var wbt = document.getElementById('white') ;
var bbt = document.getElementById('black');
var lbt = document.getElementById('blue');

wbt.addEventListener('click',function(){
  document.getElementById('defimg').src = "watchwhite.jpg" ;
});
bbt.addEventListener('click',function(){
   document.getElementById('defimg').src = "watchblack.jpg" ;
});
lbt.addEventListener('click',function(){
  document.getElementById('defimg').src = "watchblue.jpg" ;
});

