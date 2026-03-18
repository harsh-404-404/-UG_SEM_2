let api = "https://jsonplaceholder.typicode.com/posts";   //this url is kinda broken so error is expected!


async function getMeData(){
  try{
  
    let metadata = await fetch(api);
    let res = await metadata.json();
    console.log(res);
  
  }catch (error){
    console.log(error);
  }

}
getMeData();