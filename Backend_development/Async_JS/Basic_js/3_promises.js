let cgpaScored = true;

let newPeomise = new Promise((resolve,reject) => {   //order of resolve and reject matters!!
    if(cgpaScored){
        resolve({'name':'harsh',"mohan":"roy"})
        console.log("i scored more then 9 cgpa")
    }else{
        console.log("I did not score more then 9 cgpa")
        reject("shrey Khandelwala is gadar")    
    }
});

newPeomise
.then((data) =>{
    console.log(`Promise is resolved : ${data.name}`)
})
.catch((data) =>{
    console.log(`Promise is not resolved: ${data}`)
})
.finally(() => {
    console.log("i was here")
});