text = document.getElementById("text");
change = document.getElementById("change");
dont = document.getElementById("dont");

let timer = null;
let is_original = true;

change.addEventListener("click", () =>{

    if (timer) clearTimeout(timer);  // to clear previous timer if use clicks miltiple time
    
    timer = setTimeout(() => {
        
        if (is_original){
            text.textContent = "This is changed";
            change.textContent = "revert";
            is_original = false;
        }
        else{
            text.textContent= "Lorem ipsum dolor sit amet."
            change.textContent = "change";
            is_original = true;
        } 
        timer = null; // Clean up
    },1500);
});

dont.addEventListener("click",() => {
    if(timer){
        clearTimeout(timer);
        timer = null;
    }
});
