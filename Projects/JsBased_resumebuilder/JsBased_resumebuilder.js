
function printpdf()
{
        var content=document.getElementById("print");
        var button2=document.getElementById("skilladd");
        var button6=document.getElementById("eduadd");
        var button7=document.getElementById("secadd");
        button2.classList.add("none");
        button6.classList.add("none");
        button7.classList.add("none");
        html2pdf(content,{
            html2canvas:{scale:1,logging:true,dpi:600}
        });
        button2.classList.remove("none");
        button6.classList.remove("none");
        button7.classList.remove("none");
}


function addedu()
{
    const head=document.createElement('div');
    document.getElementById("education").appendChild(head);
    head.innerHTML=('<div class="edublock"><div class="degree" contenteditable="true">Degree name</div><div class="institute" contenteditable="true">Name of the institute</div><div class="date" contenteditable="true">Date of passing</div></div>');

}
function addskill()
{
    const head=document.createElement('div');
    document.getElementById("skills").appendChild(head);
    head.innerHTML=('<div class="skill" contenteditable="true">Your skill goes here</div>');
}
function addsec()
{
    const head=document.createElement('div');
    document.getElementById("newsec").appendChild(head);
    head.innerHTML=('<div class="title" contenteditable="true">NEW SECTION</div><div class="secdesc" contenteditable="true">This is the description part of your new section. Try to stay within limit and write something which has less than 200 words. The spaces and symbols you use will also be included so use them for an indentation effect.</div>');
}
function saveresume()
{
    var sec=document.getElementById("print");
    value1=sec.innerHTML;
    var info=document.getElementById("custinfo");
    info.value=value1;
}
setInterval(saveresume,1000);