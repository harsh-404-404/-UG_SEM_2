let cgpaScored = true;

let newPeomise = new Promise((resolve,reject) => {   //order of resolve and reject matters!!
    if(cgpaScored){
        resolve("Shrey Khandelwala")
        console.log("i scored more then 9 cgpa")
    }else{
        console.log("I did not score more then 9 cgpa")
        reject()
    }
});

newPeomise.then((data) =>{
    console.log(`Promise is resolved : ${data}`)
})
.catch(() =>{
    console.log("Promise is not resolved")
})
.finally(() => {
    console.log("i was here")
});