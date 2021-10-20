var game = document.getElementById("game-container");
var card_container = document.getElementById('help-container');
var btn = document.getElementById("play-button");
var span = document.getElementById("help");
var body = document.getElementsByTagName('body')[0];

btn.onclick = function() {
  game.style.display = "flex";
  card_container.style.display = "none";
  span.style.display = "block";
  body.style.backgroundImage = "url(./Assets/bg2.jpg)";
}

span.onclick = function() {
  game.style.display = "none";
  card_container.style.display = "block";
  span.style.display = "none";
  body.style.backgroundImage = "url(./Assets/bg5.jpg)";
}

chosenRow = -1;

chosenStix = []

machineScore = 0
yourScore = 0

  function newGame() {
    setWinner("");
    over = false;
    chosenRow = -1;
    isUserNext = 0;
    winner = null;
    // sticks = [];
    // for(var i = 0; i < 4; i++) {
    //   sticks[i] = [];
    // }
    // sticks[0] = Array(1).fill(null);
    // sticks[1] = Array(3).fill(null);
    // sticks[2] = Array(5).fill(null);
    // sticks[3] = Array(7).fill(null);
    for(let i = 1; i <= 4; i++) {
      var id = "row" + (i);
      id = id.toString();
      var stix = document.getElementById(id);
      for(let j = 0; j < stix.children.length; j++) {
        stix.children[j].classList.remove('hide');
      }
    }
    
  }

  isUserNext = 2;
  over = false;

  function hideStick(i, j) {
    // console.log("Function called!");
    // console.log(i, j, chosenRow);
    if(chosenRow == -1) {
      chosenRow = i;
    } else if(chosenRow != i) {
      return;
    }
    isUserNext = 2;
    var id = "row" + (i+1);
    id = id.toString();
    var stix = document.getElementById(id);
    
    var singleStic = stix.children[j];
    console.log(stix, singleStic);

    var id = i + "#" + j;

    if(chosenStix.includes(id)) {
      singleStic.classList.remove("hide");
      const index = chosenStix.indexOf(id);
      if (index > -1) {
        chosenStix.splice(index, 1);
      }
      if(chosenStix.length === 0) {
        isUserNext = 1;
      }
    } else {
      chosenStix.push(id);
      singleStic.classList.add("hide");
    }

    isGameOver("Machine");
  }

  function isWinningPosition(rowsCount) {
    console.log(rowsCount);
    var a =  (rowsCount[1] ^ rowsCount[2] ^ rowsCount[3] ^ rowsCount[4]) == 0;
    var b = (rowsCount[1] | rowsCount[2] | rowsCount[3] | rowsCount[4]) == 1;

    return a !== b;
  }

  function isGameOver(winz) {
    var flag = true;
    for(let i = 1; i <= 4; i++) {
      var id = "row" + (i);
      id = id.toString();
      var stix = document.getElementById(id);
      let count = 0;
      for(let j = 0; j < stix.children.length; j++) {
        if(!(stix.children[j].classList.contains('hide')))
          count++;
      }
      if(count != 0) {
        flag = false;
        break;
      }
    }
    if(flag) {
      over = true;
      if(winz == "Machine") {
        machineScore++;
      } else {
        yourScore++;
      }
      setScores(machineScore, yourScore);
      setWinner(winz);
    }
  }

  function setScores(mS, yS) {
    document.getElementById("machine-score").innerHTML = mS;
    document.getElementById("your-score").innerHTML = yS;
  }

  function setWinner(winner) {
    if(winner == "") {

    } else if(winner == "Machine") {
      winner = "Beep Boop, the computer defeated you!"
    } else {
      winner = "Way to go mortal, you're a winner!";
    }

    document.getElementById("winner-div").innerHTML = winner;
  }

  function computerMove() {
    if(isUserNext == 1 || over)
      return;
    chosenStix = [];
    isUserNext = 1;
    chosenRow = -1;
    let rowsCount = [5];
    
    for(let i = 1; i <= 4; i++) {
      var id = "row" + (i);
      id = id.toString();
      var stix = document.getElementById(id);
      let count = 0;
      for(let j = 0; j < stix.children.length; j++) {
        if(!(stix.children[j].classList.contains('hide')))
          count++;
      }
      rowsCount[i] = count;
      console.log(count);
    }

    var flag = false;
    for(let i = 1;  i <= 4; i++) {
      let temp = rowsCount[i];
      for(let j = rowsCount[i] - 1; j >=0; j--) {
        rowsCount[i] = j;
        if(isWinningPosition(rowsCount)) {
          let toDelete = temp - j;
          var id = "row" + (i);
          console.log(id);
          id = id.toString();
          var stix = document.getElementById(id);
          
          for(let j = 0; j < stix.children.length; j++) {
            if(!(stix.children[j].classList.contains('hide'))) {
              stix.children[j].classList.add('hide');
              toDelete--;
            }
            if(toDelete == 0) {
              flag = true;
              break;
            }
          }
        }
        if(flag == true)
          break;
      }

      if(flag == false)
        rowsCount[i] =temp;
      
      if(flag == true)
        break;
    }

    if(!flag) {
      var arr = [1,2,3,4];
      arr = shuffle(arr);
      console.log(arr);
      for(let i = 0; i < 4; i++) {
        if(rowsCount[arr[i]] > 0) {
          var toDelete = 1 + Math.floor(Math.random() * Math.floor(rowsCount[arr[i]] - 1));
          var id = "row" + (arr[i]);
          id = id.toString();
          var stix = document.getElementById(id);
          
          for(let j = 0; j < stix.children.length; j++) {
            if(!(stix.children[j].classList.contains('hide'))) {
              stix.children[j].classList.add('hide');
              toDelete--;
            }
            if(toDelete == 0)
              break;
          }
          break;
        }
      }
    }

    isGameOver("You");
  }

  function shuffle(array) {
    var currentIndex = array.length, temporaryValue, randomIndex;
  
    // While there remain elements to shuffle...
    while (0 !== currentIndex) {
  
      // Pick a remaining element...
      randomIndex = Math.floor(Math.random() * currentIndex);
      currentIndex -= 1;
  
      // And swap it with the current element.
      temporaryValue = array[currentIndex];
      array[currentIndex] = array[randomIndex];
      array[randomIndex] = temporaryValue;
    }
  
    return array;
  }

  function nextMove() {
    if(!isUserNext) {
      computerMove();
    }
  }
