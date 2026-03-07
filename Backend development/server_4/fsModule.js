const http = require("http")
const fs = require("fs");
const { error } = require("console");

const app = http.createServer((req, res) => {
    // Writing in file
    // Reading in a file

    // appending in a file
    fs.appendFileSync("exmaple.txt","Appending in a file\n");

    fs.appendFile("example.txt", "\nAppending in a file-Async", (err, data) => {
        if(err) console.log(err);
        else console.log("Data appended");
    });
    
    // Copy in a file

    fs.cpSync("example.txt","copy_of_example.txt")

    // Deleting a file

    fs.unlink("copy_of_example.txt", (error,data) => {
        if(error) console.log(error);
            else console.log("File deleted successfully...");
    })
    // Stats of a file
    let statData = fs.statSync("example.txt");
    console.log(statData);

    res.end();

})

app.listen(3000, ()=>{
    console.log("server running...");
})