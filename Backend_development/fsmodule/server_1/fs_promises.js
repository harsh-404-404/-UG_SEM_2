const fs = require("fs/promises");

async function everythingAsync(){
    try{
        await fs.writeFile("writeFile.txt","This is writen 1st\n");
        
        await fs.appendFile("writeFile.txt", "This is appended via appendFile\n");
        
        let read = await fs.readFile("writeFile.txt","utf-8");
        console.log(read);

        await fs.cp("writeFile.txt","copy-of-writeFile.txt");

        await fs.unlink("copy-of-writeFile.txt");
        
        let states = await fs.stat("writeFile.txt");
        console.log(states);
    }   
    catch(error){
        console.log(error);
    }
}
everythingAsync()