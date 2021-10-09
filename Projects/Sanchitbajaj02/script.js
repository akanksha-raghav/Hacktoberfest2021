const fill = document.querySelector(".fill");
const empties = document.querySelectorAll(".empty");

// Fill listeners
fill.addEventListener("dragstart", dragStart);
fill.addEventListener("dragend", dragEnd);

// Loop through empties
for (const empty of empties) {
  empty.addEventListener("dragover", dragOver);
  empty.addEventListener("dragenter", dragEnter);
  empty.addEventListener("dragleave", dragLeave);
  empty.addEventListener("drop", drop);
}

// dragStart function
function dragStart() {
  this.className += " hold";
  setTimeout(() => {
    this.className += " invisible";
  }, 0);
}

// dragEnd function
function dragEnd() {
  this.className = " fill";
  // fill.classList.remove("hold", "invisible");
}

function dragOver(e) {
  e.preventDefault();
  // console.log("over");
}

function dragEnter(e) {
  e.preventDefault();
  this.className += " hovered";
  // console.log("enter");
}

function dragLeave() {
  this.className = "empty";
  // console.log("leave");
}

function drop() {
  this.className = "empty";
  this.append(fill);
  // console.log("drop");
}
