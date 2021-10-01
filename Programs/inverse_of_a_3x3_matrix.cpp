#include <iostream>
using namespace std;
int n=3;
const int x=3;
const int y=3;
int getDet(float b[x][y]);
int main()
{
float a[3][3];
int adj[3][3];
 cout<<"Enter Numbers in Matrix: "<<endl;
for(int i =0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>a[i][j];
    }
}
cout<<"Your Matrix is:"<<endl;
for(int i =0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<a[i][j]<<" ";
    }
    cout<<"\n";
}
int det= getDet( a);

cout<<"Determinant of given 3*3 Matrix is: "<<det<<endl;
if (det==0) cout<<"No Inverse possible";
 else {cout<<"Inverse of matrix is: "<<endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            cout<<((a[(j+1)%3][(i+1)%3] * a[(j+2)%3][(i+2)%3]) - (a[(j+1)%3][(i+2)%3] * a[(j+2)%3][(i+1)%3]))/det<<" ";
        
        cout<<"\n";
    }}
return 0;
}
int getDet(float b[x][y]){
    float c1= (b[1][1]*b[2][2])-(b[2][1]*b[1][2]);
float c2= (b[1][2]*b[2][0])-(b[1][0]*b[2][2]);
float c3= (b[1][0]*b[2][1])-(b[1][1]*b[2][0]);
float determinant= (b[0][0]*c1)+(b[0][1]*c2)+(b[0][2]*c3);
return determinant;
}
