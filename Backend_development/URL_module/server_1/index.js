const http = require("http");

const app = http.createServer((req,res) => {

    if(req.url == "/"){
        console.log("Welcome to home page");
        res.write("Hello page");
        res.end();
    }   
    else if(req.url == "/submit"){
        console.log("user requested submit page");
        res.write("Form submitted!");
        res.end();
    }   
});

app.listen(3000, () =>{
    console.log("Server is runninng......")
});