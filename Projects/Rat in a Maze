#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;
vector<int> v1,v2;
bool solveMazeUtil( int** arr, int x, int y, int** sol,int n); 

void printSolution(int** sol,int n) 
{ 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) 
            {
            	if(sol[i][j]==1)
            	{
            		v1.push_back(i);
            		v2.push_back(j);
				}
			}
    } 
} 

bool isSafe(int** maze, int x, int y,int n) 
{ 
    if ( x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1) 
        return true; 
  
    return false; 
} 
  
/* This function solves the Maze problem  
using Backtracking. It mainly uses  
solveMazeUtil() to solve the problem.  
It returns false if no path is possible,  
otherwise return true and prints the path  
in the form of 1s. Please note that there  
may be more than one solutions, this  
function prints one of the feasible  
solutions.*/
bool solveMaze(int** arr,int n) 
{ 
    int** sol=new int*[n];
    for(int i=0;i<n;i++)
    {
    	sol[i]=new int[n];
    	for(int j=0;j<n;j++)
    	sol[i][j]=0;
	}
    if (solveMazeUtil( arr, 0, 0, sol,n)  == false) { 
        printf("Solution doesn't exist"); 
        return false; 
    } 
  
    printSolution(sol,n); 
    return true; 
} 
  
/* A recursive utility function  
to solve Maze problem */
bool solveMazeUtil( int** arr, int x, int y, int** sol,int n) 
{ 
    // if (x, y is goal) return true 
    if (  x == n - 1 && y == n - 1  && arr[x][y] == 1) { 
        sol[x][y] = 1; 
        return true; 
    } 
  
    // Check if maze[x][y] is valid 
    if (isSafe(arr, x, y,n) == true) { 
        // mark x, y as part of solution path 
        sol[x][y] = 1; 
  
        /* Move forward in x direction */
        if (solveMazeUtil(  arr, x + 1, y, sol,n) == true) 
            return true; 
  
        
        if (solveMazeUtil( arr, x, y + 1, sol,n)  == true) 
            return true; 
        sol[x][y] = 0; 
        return false; 
    } 
  
    return false; 
}

main()
{
    int n;
	cin >> n;
	int** arr=new int*[n];
	for(int i=0;i<n;i++)
	{
	arr[i]=new int[n];
   } 
   for(int i=0;i<n;i++)
   {
   	for(int j=0;j<n;j++)
   	cin >> arr[i][j];
   }
   solveMaze(arr,n);
   int t=400/n;
	initwindow(1000,1000);
//	int gd=DETECT,gm,i,j;
//	initgraph(&gd,&gm," ");
	settextstyle(10,4,4);
	outtextxy(500,50,"RAT-MAZE");
	settextstyle(8,4,1);
	outtextxy(600,80,"CROSS-OBSTACLE");
	outtextxy(600,110,"GREEN-SOURCE AND DESTINATION");
	outtextxy(600,140,"YELLOW-PATH");
	setcolor(YELLOW);
	line(200,200,600,200);
	line(200,200,200,600);
	line(200,600,600,600);
	line(600,200,600,600);
	
	for(int i=1;i<n;i++)
	{
		line(200,200+i*t,600,200+i*t);
	}
	for(int j=1;j<n;j++)
	{
		line(200+j*t,200,200+j*t,600);
	}
	setcolor(RED);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]==0)
			{
				line(200+j*t,200+i*t,200+(j+1)*t,200+(i+1)*t);
				line(200+j*t,200+(i+1)*t,200+(j+1)*t,200+i*t);
			}
		}
	}
	if(v1.size()!=2*n-1)
	{
		setcolor(WHITE);
		settextstyle(10,0,5);
		outtextxy(0,700,"RAT_IS_TRAPPED_U_CHEATED");
	}
	else
	{
	setcolor(WHITE);
	for(int i=0;i<v1.size();i++)
	{
		if(i==0||i==v1.size()-1)
		{
			setcolor(GREEN);
		}
		else
		setcolor(WHITE);
		circle(200+(v2[i]*t+(v2[i]+1)*t)/2,200+(v1[i]*t+(v1[i]+1)*t)/2,t/2);
		delay(500);
		//line(200+v2[i]*t,200+v1[i]*t,200+(v2[i]+1)*t,200+(v1[i]+1)*t);
	}
	outtextxy(0,700,"WE_REACHED");
   }
	getch();
}
