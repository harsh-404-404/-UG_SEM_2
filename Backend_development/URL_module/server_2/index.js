const http = require("http");
const url = require("url");

const app = http.createServer((req,res) => {

    const myUrl = url.parse(req.url,true);  ///here by changeing default to true it will make url.query in form of object
    if(myUrl.pathname == "/"){
        console.log("Welcome to home page");
        res.write("Hello page");
        res.end(); 
    }   
    else if(myUrl.pathname == "/submit"){
        console.log("user requested submit page");
        res.write("<h1>Form submitted by " +  myUrl.query.name + " Who was born in " + myUrl.query.year + "!</h1><br>");
        res.end();
    }   
});

app.listen(3000, () =>{
    console.log("Server is runninng......")
});