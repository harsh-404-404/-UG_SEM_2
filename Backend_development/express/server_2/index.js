const express = require("express")
const path = require("path")

const app = express();

app.get("/", (req,res) => {
    //To send data
    res.send("I am on Home page");
    
});

app.get("/about", (req,res) => {
    res.sendFile(path.join(__dirname,"about.html")); 
    res.json({
        name : "Shrey",
        university : "shoolini",
        year : 2026
    });
});


// .json files are by default exported

users_data = require("./users.json")
app.get("/api/user", (req, res) => {
    res.json(users_data);  
})


//Dynamic Routing
app.get("/api/user/:id", (req, res) => {
    // const requestedId = +(req.params.id)
    // const requestedId = parseInt(req.params.id)
    const reqId = Number(req.params.id)   //it will return NaN if id is not a number
    if(isNaN(reqId)){
        res.json({
            success : false,
            msg : "Plase enter valid user id"
        })
    }else{
        const user = users_data.find((user) => { return (user.id === reqId); })
        if(!user){
            res.json({
                success : false,
                msg : "Plase enter valid user id"
            })
        }else{
            res.json(user);
        }
        
    }
})

app.listen(3000, () => {
    console.log("server is running...");
});