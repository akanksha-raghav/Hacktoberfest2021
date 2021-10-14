# Print the pattern of the board 
function drawWall(){
	return "------------------------------------------------------------------------"
}
function drawStars(){
	return "**********************************";
}

function printWelcomeMessage(){
	printf("\n\t\033[36m%s WELCOME TO MINESWEEPER %s \033[0m \n\t", drawStars(), drawStars())
	printf(" You Have %d lives.\n\t Enter any Position separated by space eg. '1-2' as '1 2' given in table.\n\t If you step on 🧨  ...You loose one life.\n", lives)
	printf("\n\t\033[36m%s\033[36m\t\n", drawWall());
}

# Create positional Values of each box in rectangular board
function createPositionArray (){
	for(row=0;row<10;row++){
		for(column=1;column<10;column++){
			boxPositionArray[row,column]=row"-"column
		}
	}
}
# Create hidden number values and bomb
function createValueArray(){
	for(row=0;row<10;row++){
		for(column=1;column<10;column++){
			random1=int(rand()*10)
			random2=int(rand()*10)
			 if(random1==random2){
		         boxValueArray[row,column]="🧨"
			 }
			 else{
				 totalValues+=1
				 boxValueArray[row,column]= "🟩";
			 }
		}
	}
}

# Reveal the value of position entered 
function revealValue(){
	boxPositionArray[$1,$2] = boxValueArray[$1,$2]
	if(boxPositionArray[$1,$2]== "🧨"){
		lives-=1;
		printf("\n\nLives left----> %d\n\n",lives)
	}
	else{
		revealedValues+=1
	}
}

# Print the game board
function printMineBoard(){
	printf("\n\t\033[32m%s%s\t\033[0m\n",drawWall(),drawWall());

	for(row=0;row<10;row++){	
		printf("\t")
		for(column=1;column<10;column++){
			printf("\033[32m|\033[0m\t%s\t",boxPositionArray[row,column])
		}
		printf("\033[32m|\033[0m\t")
			printf("\n\t\033[32m%s%s\t\033[0m\n",drawWall(),drawWall());
	}
}

BEGIN{
	srand()
	lives=5
	revealedValues=0
	totalValues=0
	printWelcomeMessage();
	createValueArray()
	createPositionArray()
	printMineBoard()
}	
boxPositionArray[$1,$2]~/[^0-9]/{
	revealValue()
	printMineBoard()
	if(lives == 0){
		printf("\n\tyour score is ----> %d.Total values were ----> %d\n",revealedValues,totalValues)
		exit;
	}
	if(revealedValues == totalValues){
		print"\n\t*********************************** YOU WON! ***********************************\n"
		exit;
	}
	next
}
{
	print"PLEASE ENTER A VALID POSITION"
}
END{
}
