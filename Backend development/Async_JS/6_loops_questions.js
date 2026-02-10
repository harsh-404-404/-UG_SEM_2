let people = [
  { id: 1, name: "Aarav", age: 21 },
  { id: 2, name: "Riya", age: 19 },
  { id: 3, name: "Kabir", age: 23 },
  { id: 4, name: "Sneha", age: 20 },
  { id: 5, name: "Vikram", age: 25 },
  { id: 6, name: "Ananya", age: 18 },
  { id: 7, name: "Rahul", age: 22 },
  { id: 8, name: "Priya", age: 24 },
  { id: 9, name: "Neha", age: 21 },
  { id: 10, name: "Arjun", age: 26 }
];

// for(let i = 0; i < 9;++i){
//     console.log(people[i]["name"])
// }
let arr = people.map((user) => {
    console.log(user.name);
});

let age = people.filter((user) => user.age > 28).map((user) => user.name)
console.log(age)