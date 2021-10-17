let addFrm = document.addfrm;
let text = addFrm.add;
let ul = document.querySelector(".todos");
let addItem = (item) => {
    let str = `<li class="list-group-item d-flex justify-content-between align-items-center">
    <span>${item}</span>
    <i class="far fa-trash-alt delete"></i>
</li>`;
    ul.innerHTML += str;
};

addFrm.addEventListener("submit", (e) => {
    e.preventDefault();
    let item = text.value;
    if (item.length > 0) {
        addItem(item);
        text.value = "";
    }
});

ul.addEventListener("click", (e) => {
    if (e.target.nodeName === "I") {
        e.target.parentElement.remove();
    }
});
let searchItem = (text) => {
    let listItems = ul.children;
    for (let li of listItems) {
        if (li.innerText.toLowerCase().indexOf(text) == -1)
            li.classList.add("filtered");
        else li.classList.remove("filtered");
    }
};

let searchText = document.querySelector(".search input");
searchText.addEventListener("keyup", (e) => {
    searchItem(searchText.value.toLowerCase());
});