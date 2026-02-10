let arr = [1,2,3,4,5];

//map is used to perform operation on each and every element of array.
//arrarName.map(function)

arr.map((i) => {
    //console.log(i * 2);
})  

let mappedArray = arr.map((i) => {
    return i*3;
}).map((value) => {
    return value + 1;
});
console.log(mappedArray);


//filter
//Used to filter elemts,if condition satisfes,we keep the element else pop it out

let filterArray = mappedArray.filter((value) => {
    return value % 2 == 0;
});
console.log(filterArray);

//reduce will return a single value (e.g:sum,avg)
//arrayName.reduce((accumulator, currentvalue) => {});

let newArray = [1,2,3,4,5]
let reducedArray = newArray.reduce((acc, curr) => {
    return acc + curr;
}, 0); // <-- this 0 is default value of accumulator
console.log(reducedArray);



//you can chain map,filter,reduce

let xyz = [1,2,3,4,5]
xyz = xyz.map((value) => value * 3)
.filter((value) => value % 2 == 0)
.reduce((acc,curr) => acc + curr,0)
console.log(xyz);