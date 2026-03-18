const http = require("http");

//res.write() can only send string or Buffers (raw binary data).
//a built-in class used to represent a fixed-length sequence of bytes, designed to handle raw binary data efficiently
// When you use the fs module to read a PDF, an image, or an audio file, it reads that file as a "Buffer." 
// We will pass that raw Buffer directly into res.write() to send files to the user.

const app = http.createServer((req,res) => {
    
    if(req.url == "/"){
        console.log("User Requested Home page");
        res.writeHead(200, { 'Content-Type': 'text/json' }); //this tell browser html not text!!
        res.write("<h1>Hello page</h1>");
        res.write("<h6>Hello page</h6>");
        res.end();
    }
    else if(req.url == "/about"){
        res.write("welcome to about page");
        res.end();
    }
    else if(req.url == "/contact"){
        res.write("welcome to contact page");
        res.end();
    }
    else{
        res.writeHead(404, { 'Content-Type': 'text/html' }); //this tell browser html not text!!
        res.write("<h1>404 Page not found !!</h1>");
        res.write("<h1>!! maybe you made a mistake !! </h1>");
        res.end();
        //you can not write more then one end() //because it is used to end request
        //res.end();
        //res.end();
        //response.end() can only be used once it's primery task is to close titcke/request
        //but you can send data useing response.end()
    }   
});

app.listen(3000, () =>{
    console.log("Server is runninng......")
});