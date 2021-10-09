// searching : Array.prototype.indexOf()
var names = ["Akku","tanu","bittu","tutu"];
console.log(names.indexOf("tanu")); //forward search
console.log(names.lastIndexOf("tutu")); //backward search
console.log(names.includes("tanu")); // an element is present or not only forward search
// find
//  arr.find(callback(element[, index[, array]])[, thisArg])
const prices = [100,231,400,432,543,231,654,856];
const findElem = prices.find((val)=>{
    return val > 400 ;
});
console.log(findElem); //only one element is given
//findIndex
console.log(prices.findIndex((val)=> val>400));
// default values(when something is not present in Array)
console.log(prices.find((val)=> val>1400)); // undefined
console.log(prices.findIndex((val)=> val>1400)); // -1

// filter method
const price = prices.filter((ele)=>{
  return ele>400 ;
})
console.log(price); // all the elements are returned in form of an array
// if condition is not satisfied it returns an empty array.

//Map method
const array =[1,4,9,25];
let newarr = array.map((val,index,arr)=>{
  return val>9;
})
console.log(array);
console.log(newarr);
let ind = array.map((val,index,arr)=>{
  return `Index ${index}` ;
})
console.log(ind);