// program a normal calculator and use vanilla javascript 
// if you have any problems please contact us on the discussions tab of the github repo


window.onload =  function(){

	mapping = ["c","=","+","b","1","2","3","/","4","5","6","-","7","8","9","*","(",")","0","**"];

	x = document.querySelectorAll(".number-layer button ");

	for(var i = 0; i<x.length; ++i)
	{
		if( i < 2  )
		{
			x[i].style.background = "rgba(255,255,255,0.1)";
		}

		x[i].index = i;

		x[i].addEventListener("click", 
						
						function () {
							document.getElementById("output").style.color = "rgba(255,255,255, 0.4)";
							document.getElementById("output").style.fontWeight = "400";
							var pre_string = document.getElementById("input").value;
							var final_string = "";

							if( mapping[this.index] == "b" ){
							 	final_string = pre_string.slice(0, pre_string.length - 1);
							 	document.getElementById("input").value = final_string;
								document.getElementById("output").innerText = eval ( final_string );
							}
							else if(mapping[this.index] == "=") {
								final_string = pre_string;  
								document.getElementById("output").style.color = "black";
								document.getElementById("output").style.fontWeight = "700";
								document.getElementById("input").value = final_string;
								document.getElementById("output").innerText = eval ( final_string );
							}
							else if(mapping[this.index] != "c" ){ 
								final_string = pre_string + mapping[this.index] ; 
								document.getElementById("input").value = final_string;
								document.getElementById("output").innerText = eval ( final_string );
							}
							else{
								final_string = ""; 
								document.getElementById("input").value = final_string;
								document.getElementById("output").innerText  = "=";
							}
							
						}
		);
	}

}