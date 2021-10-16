const getElementById = (id) => document.getElementById(id);
const getColorNumberElement = () => getElementById("numberOfColors");
const getRandomNumber = (limit) => Math.floor(Math.random() * limit);
const createElement = (tag, className, id) => {
  const newElement = document.createElement(tag);
  if (className !== undefined) newElement.className = className;
  if (id !== undefined) newElement.id = id;
  return newElement;
};
const getRandomHex = () => {
  let hex = Number(getRandomNumber(256)).toString(16);
  if (hex.length < 2) hex = "0" + hex;
  return hex;
};

function getRandomColor() {
  const red = getRandomHex();
  const green = getRandomHex();
  const blue = getRandomHex();
  return `#${red}${green}${blue}`;
}
const getTextColor = (hexColor) => {
  const r = parseInt(hexColor.slice(1, 3), 16) * 299;
  const g = parseInt(hexColor.slice(3, 5), 16) * 587;
  const b = parseInt(hexColor.slice(5), 16) * 114;
  const sum = Math.round((r + g + b) / 1000);
  return sum > 128 ? "black" : "white";
};
function copyToClipboard(dataToCopy) {
  function listener(event) {
    event.clipboardData.setData("text/plain", dataToCopy);
    event.preventDefault();
  }
  document.addEventListener("copy", listener);
  document.execCommand("copy");
  document.removeEventListener("copy", listener);
}
function getNewColorDiv(bgColor) {
  const newColorDiv = createElement("div", "pallete-color");
  newColorDiv.style.backgroundColor = bgColor;
  const newHexSpan = createElement("span", "hex-code-span");
  newHexSpan.innerText = bgColor;
  newHexSpan.style.color = getTextColor(bgColor);
  newColorDiv.addEventListener("click", () => {
    copyToClipboard(bgColor);
    newHexSpan.innerText = "Copied";
    setTimeout(() => (newHexSpan.innerText = bgColor), 1500);
  });
  newColorDiv.appendChild(newHexSpan);
  return newColorDiv;
}

class ColorsCounter {
  constructor() {
    let totalNumberOfColors = 5;
    this.incrementNumberOfColors = () => {
      if (totalNumberOfColors < 7)
        getColorNumberElement().innerText = ++totalNumberOfColors;
    };
    this.decrementNumberOfColors = () => {
      if (totalNumberOfColors > 3)
        getColorNumberElement().innerText = --totalNumberOfColors;
    };
    this.getNumberOfColors = () => totalNumberOfColors;
    this.setNumberOfColors = (numberOfColors) => {
      totalNumberOfColors = numberOfColors;
    };
  }
}
const colorCounter = new ColorsCounter();

class PalleteList {
  constructor() {
    let listOfPallete = new Array();
    let currentIndex = -1;
    const fixedLengthOfPalletes = 1000;
    this.incrementCurrentIndex = () => {
      if (currentIndex < listOfPallete.length - 1) currentIndex++;
    };
    this.decrementCurrentIndex = () => {
      if (currentIndex > 0) currentIndex--;
    };
    this.addNewPallate = () => {
      if (listOfPallete.length == fixedLengthOfPalletes) {
        listOfPallete.shift();
        currentIndex--;
      }
      let colorsList = new Array();
      for (let count = 0; count < colorCounter.getNumberOfColors(); count++) {
        colorsList.push(getRandomColor());
      }
      listOfPallete.splice(currentIndex + 1);
      listOfPallete.push(colorsList);
      currentIndex++;
    };
    this.getCurrentPallate = () => listOfPallete[currentIndex];
  }
}
const palleteListhandler = new PalleteList();

function changeTitleColors(currentColors) {
  let count = 1;
  for (let index = 0; count < 8; count++, index++) {
    if (index === currentColors.length) index = 0;
    document.documentElement.style.setProperty(
      `--title-color-${count}`,
      currentColors[index]
    );
  }
}
function generatePallete() {
  const palleteDiv = getElementById("colorPallete");
  palleteDiv.innerHTML = "";
  const colorsList = palleteListhandler.getCurrentPallate();
  changeTitleColors(colorsList);
  getColorNumberElement().innerText = colorsList.length;
  document.documentElement.style.setProperty(
    "--number-of-colors",
    colorsList.length
  );
  colorCounter.setNumberOfColors(colorsList.length);
  colorsList.forEach((currentColor) => {
    const newColorDiv = getNewColorDiv(currentColor);
    palleteDiv.appendChild(newColorDiv);
  });
}
function changeTitleToCopied() {
  const title = getElementById("title");
  title.innerHTML = "";
  const newTitleLetters = "Copied!".split("");
  newTitleLetters.forEach((currentLetter, index) => {
    const newSpan = createElement("span", `text-color${index + 1}`);
    newSpan.innerText = currentLetter;
    title.appendChild(newSpan);
  });
}
function addEventListeners() {
  getElementById("decreaseColorNumber").addEventListener("click", () => {
    colorCounter.decrementNumberOfColors();
  });
  getElementById("increaseColorNumber").addEventListener("click", () => {
    colorCounter.incrementNumberOfColors();
  });
  getElementById("undoButton").addEventListener("click", () => {
    palleteListhandler.decrementCurrentIndex();
    generatePallete();
  });
  getElementById("redoButton").addEventListener("click", () => {
    palleteListhandler.incrementCurrentIndex();
    generatePallete();
  });
  getElementById("generateButton").addEventListener("click", () => {
    palleteListhandler.addNewPallate();
    generatePallete();
  });
  getElementById("copyPaletteButton").addEventListener("click", () => {
    const currentPallete = palleteListhandler.getCurrentPallate();
    let colorPalleteString = `:root {\n/* usage => var(--color-{number}) */\n`;
    currentPallete.forEach((color, index) => {
      colorPalleteString += `--color-${index + 1} : ${color};\n`;
    });
    copyToClipboard(colorPalleteString + "}");
    const originalTitle = `<span class="text-color1">C</span><span class="text-color2">o</span
    ><span class="text-color3">l</span><span class="text-color2">o</span
    ><span class="text-color4">r</span>&nbsp;<span class="text-color5"
      >F</span
    ><span class="text-color6">u</span><span class="text-color7">n</span>`;
    changeTitleToCopied();
    setTimeout(() => {
      getElementById("title").innerHTML = originalTitle;
    }, 1500);
  });
  document.addEventListener("keydown", function (event) {
    if (event.ctrlKey && event.code === "KeyZ" && !event.shiftKey)
      getElementById("undoButton").click();

    if (
      (event.ctrlKey && event.code === "KeyZ" && event.shiftKey) ||
      (event.ctrlKey && event.code === "KeyY")
    )
      getElementById("redoButton").click();
    if (event.code === "Space") getElementById("generateButton").click();
  });
}

function changeColor() {
  let collection = document.getElementsByClassName("pallete-color");
  for (let index = 0; index < collection.length; index++) {
    collection[index].style.backgroundColor = getRandomColor();
  }
}
function initiate() {
  addEventListeners();
  getElementById("generateButton").click();
}

window.onload = initiate;
