#include <bits/stdc++.h>
using namespace std;



void CalcPrime(int N) {

    int prime[N];

    for(int i=1; i<=N; i++) prime[i] = 1;
    prime[0] = prime[1] = 0;

    for(int i=2; i*i<=N; i++) {

        if(prime[i]) {

            for(int j=i*i; j<=N; j+=i) 
                prime[j] = 0;
        }        
    }

    for(int i=1; i<=N; i++)
        if(prime[i]) 
            cout<<i<<endl;
}

int main(){
    

    CalcPrime(100);

    
}