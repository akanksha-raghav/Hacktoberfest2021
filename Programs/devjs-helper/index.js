const { compareObjects } = require("./lib/object");
const { compareArrays } = require("./lib/array");

const arr = compareArrays([], []);

console.log(arr);