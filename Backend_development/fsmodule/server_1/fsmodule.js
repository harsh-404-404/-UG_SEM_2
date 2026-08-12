const http = require("http");
const fs = require("fs/promises");

const app = http.createServer( async (req, res) => {
    
    // --- 1. Write in a file ---
    
    // Sync
    fs.writeFileSync("example_sync.txt", "Data from writeFileSync\n");
    
    // Async
    fs.writeFile("example_async.txt", "Data from writeFile()\n", (error) => {
        if(error) console.log("Error writing async file:", error);
        else console.log("Async write: Data Written...");
    });
    
    try{
        await fs.writeFile("Example.text","im God");
    }catch(error){
        console.log(error)
    }        
    
    
    // --- 2. Append in a file ---
    
    // Sync
    try{
        fs.appendFileSync("example_sync.txt", "Appending in a file (Sync)\n");
    }catch(error){
        console.log(error);
    }
    
    // Async
    fs.appendFile("example_async.txt", "Appending in a file (Async)\n", (error) => {
        if(error) console.log("Error appending async file:", error);
        else console.log("Async append: Data appended...");
    });

    // --- 3. Read in a file ---
    
    // Sync
    try {
        const readDataSync = fs.readFileSync("example_sync.txt", "utf-8");
        console.log("Sync read data:\n", readDataSync);
    } catch (err) {
        console.log("Error reading sync file:", err);
    }
    
    // Async
    fs.readFile("example_async.txt", "utf-8", (error) => {
        if(error) console.log("Error reading async file:", error);
        else console.log("Async read data:\n", data);
    });

    // --- 4. Copy a file ---
    
    // Sync
    try {
        fs.cpSync("example_sync.txt", "copy_of_example_sync.txt");
        console.log("Sync copy completed...");
    } catch (err) {
        console.log("Error copying sync file:", err);
    }
    
    // Async
    fs.cp("example_async.txt", "copy_of_example_async.txt", (error) => {
        if(error) console.log("Error copying async file:", error);
        else console.log("Async copy completed...");
    });

    // --- 5. Stats of a file ---
    
    // Sync
    try {
        let statDataSync = fs.statSync("example_sync.txt");
        console.log("Sync file stats size:", statDataSync.size, "bytes");
    } catch (err) {
        console.log("Error getting sync stats:", err);
    }
    
    // Async
    fs.stat("example_async.txt", (error, stats) => {
        if(error) console.log("Error getting async stats:", error);
        else console.log("Async file stats size:", stats.size, "bytes");
    });

    // --- 6. Delete a file ---
    // (Note: Deleting happens fast, it might delete before async reads finish if not careful.
    // Wrapped in timeouts here just to ensure previous async operations have time to log)
    
    setTimeout(() => {
        // Sync
        try {
            fs.unlinkSync("copy_of_example_sync.txt");
            console.log("Sync delete completed...");
        } catch (err) {
            console.log("Error deleting sync file:", err);
        }
        
        // Async
        fs.unlink("copy_of_example_async.txt", (error) => {
            if(error) console.log("Error deleting async file:", error);
            else console.log("Async delete completed...");
        });
    }, 2000);

    res.writeHead(200, { 'Content-Type': 'text/plain' });
    res.write("File operations executed. Check terminal for logs.");
    res.end();
});

app.listen(3000, () => {
    console.log("Server is running on port 3000.......");
});

