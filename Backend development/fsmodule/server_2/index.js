const http = require("http");
const fs = require("fs/promises");


const app = http.createServer( async (req,res)=> {
    if(req.url === "/available" && req.method === "GET"){
        try{
            const data = await fs.readFile("inventory.json");
            
            json_data = JSON.parse(data);
            filterd_json = json_data.filter(item => item.quantity > 0);
            final_return = JSON.stringify(filterd_json)
            
            res.writeHead(200,{ "content-Type" : "application/json "});
            res.end(final_return);
        }catch(error){
            res.writeHead(404,{ "content-Type" : "text/plain" });
            console.log(error);
        }
    }
    else{
        res.writeHead(404,{ "content-Type" : "text/plain" });
        res.end();
    }
})
.listen(3000, () => {
    console.log("server is running....")
});