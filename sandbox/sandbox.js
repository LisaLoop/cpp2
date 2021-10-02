const person = {
    name: "bob"
}

var {name} = person;
person.name = "doug";
name = "sally";
console.log("name: ", name);
console.log("person.name: ", person.name);