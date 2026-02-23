const http = require("http");
//console.log(http) // http is object of fuction use this to see allkeys


//http:localhost:3000
const app = http.createServer((req,res) => {
    console.log("i got request");
    //console.log(req);

    console.log(req.url) //with req.url we can know which path is request
    if(req.url == "/"){
        console.log("Welcome to home page");
    }
    else if(req.url == "/about"){
        console.log("welcome to about page");
    }
    else if(req.url == "/contact"){
        console.log("welcome to contact page");
    }
    else{
        console.log("404 Page not found !!");
    }

}); //our server is called app

app.listen(3000, () => {
    console.log("Server is runninng......")
});
