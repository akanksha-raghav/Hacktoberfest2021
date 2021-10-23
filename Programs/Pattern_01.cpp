#include <iostream>
using namespace std ; 
int main() {

int i , j , row , col ; 
cout<<"Enter No of rows" ; 
cin>>row ; 
cout<<"Enter No of Columns" ; 
cin>>col ;

for (i = 0; i < col; i++)
{
    for ( j = 0; j < row ; j++)
    {
        cout<<"* " ; 
    }
    row-- ; 
    cout<<endl ; 
    
}


    return 0 ; 
}
