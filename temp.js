let http = require("http")
let fs = require("fs")



http.createServer((req,res) => {
    if(req.url === "/" && req.method === "GET"){
        fs.readFile("xyz.json","utf-8",(error,data) => {
            if(error) {
                res.writeHead(500, { "content-Type" : "Plain/text" });
                res.end();
            }
            data = JSON.parse(data);
            data_filtred = data.filter(x => x.stock > 0);
            res.writeHead(404, { "content-Type" : "application/json" });
            res.end(JSON.stringify(data_filtred));
        })
    }
}).listen(3000, () => { 
    console.log("Server is running....");
})