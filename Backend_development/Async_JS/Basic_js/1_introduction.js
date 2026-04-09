//setTimeout(callback function,timeInMS)
//setTImeout(callback funciton)

console.log("First") //this is Synchronous 

setTimeout(() => {
    console.log("Third")
},100) //this is asyncrynus

console.log("secound") //this is Synchronus

//clearTimeout(refrence)

setTimeout(() => {
    console.log("1s")
},1000) 
let secoundTimeout = setTimeout(() => {
    console.log("2s")
},2000) 
setTimeout(() => {
    console.log("3s")
},3000) 
clearTimeout(secoundTimeout)
