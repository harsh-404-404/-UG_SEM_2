const add = (a,b) => {
    return a + b;
}

const sub = (a,b) => {
    return a - b;
}
//console.log(add(6,6))
//module.exports can only be used onece and can only exports one thing
// module.exports = "Shrey"
// module.exports = 5
module.exports = {
    addition : add,
    sub                             //if your key and value are same then you can just write it once
};