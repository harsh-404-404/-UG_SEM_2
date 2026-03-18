let api = "https://jsonplaceholder.typicode.com/posts"

//console.log(fetch(api)); //Promise { <pending> } this is a promise in pending state

fetch(api)
.then((data) => {
    return data.json()   //data it self well be metadata of api responce and to parse data we use .json()
})
.then()
.catch((error) => {   //this is for error handleing because promise faild
    console.log(error);
})
.then()