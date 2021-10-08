// Ques 1 : Find square root
let arr = [25,36,49,64,81,100];
let sqrt = arr.map((currElement)=>{
    return Math.sqrt(currElement)
})
console.log(sqrt);

// Ques 2
let arr1 = [2,3,4,5,6,7,8,9];
let item = arr1.map((val)=>{
    return val*2 ;
}).filter((val)=>{
    return val >10 ;
})
console.log(item);
// One line
 // let item = arr1.map((val)=>val*2).filter((val)=>val >10);

 // Reduce Method
 let arr2 = [5,4,6,2,7,8,9];
 let red = arr2.reduce((accumulator,val,index,arr)=>{
     return accumulator+=val ;
 })
 console.log(red);
 let red2 = arr2.reduce((accumulator,val)=>{
    return accumulator+=val ;
 },4) //initial value
 console.log(red2);
 // chainable method

 let chain = arr2.map((value)=> value*2).filter((value)=> value>10).reduce((accumulator,value)=>accumulator+=value);
 console.log(chain);

 // multi to 1d array(flaten)
 const multi = [
     ['z1','z2'],
     ['z3','z4'],
     ['z5','z6'],
     ['z7',['z8','z9']]
    ];
let Arr = multi.reduce((accu,val)=>{
    return accu.concat(val);
})
console.log(Arr);