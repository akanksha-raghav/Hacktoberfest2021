// Higher order and call back function
// callback function - passes as an argumnet within another func
const add = (a,b) =>{
    return a+b
}
const sub = (a,b) =>{
    return a-b
}
const mul = (a,b) =>{
    return a*b
}
const div = (a,b) =>{
    return a-b
}

//  higher order function - takes a function as an argument

const calculator = (num1,num2,oper)=>{
    return oper(num1,num2);
}
console.log(calculator(8,4,add));