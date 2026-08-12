const express = require("express")
const path = require("path")

const aboutFileLocation = path.join(__dirname,"about.html")

const app = express();

app.get("/", (req,res) => {
    //To send data
    res.send("I am on Home page");
    
});

app.get("/about", (req,res) => {
    res.sendFile(aboutFileLocation); 
    res.json({
        name : "Shrey",
        university : "shoolini",
        year : 2026
    });
});
app.listen(3001, () => {
    console.log("server is running...");
});