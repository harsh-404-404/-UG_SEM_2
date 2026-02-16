let api = "https://jsonplaceholder.typicode.com/posts"

//console.log(fetch(api)); //Promise { <pending> } this is a promise in pending state

fetch(api)
.then((data) => {
    return data.json();   //data it self well be metadata of api responce and to parse data we use .json()
})
.then((responce) => {
    console.log(responce)
})
.catch(() => {   //this is for error handleiing because promise faild
    
})