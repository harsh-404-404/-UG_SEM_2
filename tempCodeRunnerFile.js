const http = require("http");

//res.write() can only send string only and only string
//response.end() can only be used once it's primery task is to close titcke/request
    //but you can send data useing response.end()
const app = http.createServer((req,res) => {

    if(req.url == "/"){
        console.log("Welcome to home page");
        res.write("Hello page");
        res.end();
    }
    else if(req.url == "/about"){
        res.write("welcome to about page");
        res.end();
    }
    else if(req.url == "/contact"){
        res.write("welcome to contact page");
    }
    else{
        res.write("<h1>404 Page not found !!</h1>");
        res.write("<h1>!! maybe you made a mistake !! </h1>");
        res.end();
        //you can not write more then one end() //because it is used to end request
        //res.end();
        //res.end();
    }   
});

app.listen(3000, () =>{
    console.log("Server is runninng......")
});