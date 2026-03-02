const http = require("http");
const fs = require("fs");
const { errorMonitor } = require("events");


const app = http.createServer((request,response) => {

    // Writing in file
    // Reading in a file
    // Copy in a file
    // Deleting a file
    // Stats of a file


// Write in a file
    
    //Sync
    fs.writeFileSync("Example.txt", "Data from writeFileSync");
    //Async
    fs.writeFile("example2.txt","Data from writeFile()", (error,data) => {
        if(error) console.log("Data Written !!");
        else console.log("Data Written...")
    })


// Read in a file
    
    //Sync
    const readedData = fs.readFileSync("example.txt", "utf-8")
    console.log(readedData)
    //Async
    const readedData2 = fs.readFile("example.txt", "utf-8",(error,data) => {
        if(error) console.log(error)
        else console.log(data)
    })
    console.log(readedData2)
})  

app.listen(3000, ()=> {
    console.log("Server is running .......")
    // console.log(fs)
})