const inp = document.querySelector('input');
const list = document.getElementById('list');
const todo_arr = [];

inp.addEventListener('keypress',(e) => {
    if(e.which === 13 && inp.value!=""){
        let todoText = inp.value;

        const div = document.createElement("div");
        div.className = "items";

        let task_box = document.createElement("input");
        task_box.setAttribute('type','text');
        task_box.className = 'task';
        task_box.value = todoText;

        //buttons
        const del = document.createElement("i");
        del.classList.add("fas","fa-trash-alt");
        const edit = document.createElement("i");
        edit.classList.add("fas","fa-edit");
        const up = document.createElement("i");
        up.classList.add("fas","fa-chevron-up");
        const down = document.createElement("i");
        down.classList.add("fas","fa-chevron-down");

        //create
        div.append(task_box,del,edit,up,down);
        list.append(div);
        todo_arr.push(todoText);

        task_box.disabled = true;
        inp.value="";

        //delete
        del.addEventListener('click',(e)=> {
            e.target.parentElement.remove();
        });

        //modify
        edit.addEventListener('click', (e)=> {
            if(task_box.disabled == true){
            let first = e.target.parentElement.firstChild;
            first.disabled = false;
            }
            else task_box.disabled = true;
                   
        });

        //shift up
        up.addEventListener("click", (e) => {
            const val = e.target.parentElement.firstChild.value;
            index = todo_arr.findIndex((item) => item == val);
            let list = document.getElementById("list");
            let node = list.getElementsByTagName("div")[index];
            if (index > 0) {
              let temp = todo_arr[index - 1];
              todo_arr[index - 1] = todo_arr[index];
              todo_arr[index] = temp;
              let list = document.getElementById("list");
              let node = list.getElementsByTagName("div")[index];
              list.insertBefore(node, list.getElementsByTagName("div")[index - 1]);
            }
          });

        //shift down
        down.addEventListener('click',(e)=> {
            const val = e.target.parentElement.firstChild.value;
            index = todo_arr.findIndex((item) => item == val);
            let list = document.getElementById("list");
            let node = list.getElementsByTagName("div")[index];
            if (index < todo_arr.length-1) {
              let temp = todo_arr[index + 1];
              todo_arr[index + 1] = todo_arr[index];
              todo_arr[index] = temp;
              let list = document.getElementById("list");
              let node = list.getElementsByTagName("div")[index];
              list.insertBefore(list.getElementsByTagName("div")[index + 1], node);
            }
        });

    }
}); 