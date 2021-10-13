#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int x,y,z;
    int b,c;
    cout<<"Enter three numbers:"<<endl;
    cin>>x>>y>>z;
    int a=max(x,max(y,z));
    if(a==x){
        b=y;
        c=z;
    }
    else if (a==y)
    {
        b=x;
        c=z;
    }
    else if (a==z)
    {
        b=x;
        c=y;
    }
    
    if(a*a==b*b+c*c){
        cout<<"It is Pythagorian Triplet";
    }
    else{
        
        cout<<"It is NOT a Pythagorian Triplet";
    }
    
    return 0;
}
