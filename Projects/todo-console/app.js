let userinput = prompt("what would you like to do? | type 'quit' if not seeing instructions on screen");
const todos = ["homework", "making breakfast"];

while (userinput !== "quit") {
  if (userinput == "list") {
    console.log("#############");
    for (let i = 0; i < todos.length; i++) {
      console.log(`${i}: ${todos[i]}`);
    }
    console.log("#############");
  } else if (userinput == "new") {
    const newtodo = prompt("what is the new todo?");
    todos.push(newtodo);
    console.log(`${newtodo} added to the list`);
  } else if (userinput == "remove") {
    const removetodo = prompt("enter the index which you want to remove!");
    const deleted = todos.splice(removetodo, 1);
    console.log(`you removed ${deleted[0]}`);
  }

  userinput = prompt("what would you like to do?  | type 'quit' if not seeing instructions on screen");
}
console.log("you quited the app!");
