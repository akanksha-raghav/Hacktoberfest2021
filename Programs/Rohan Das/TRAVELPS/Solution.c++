#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string a;
        int N, A, B, totalTime=0;
        cin>>N>>A>>B;
        cin>>a;
        for(int i=0; i<N; ++i){
            if(a[i]=='0')
                totalTime+=A;
            else if(a[i]=='1')
                totalTime+=B;
        }
        cout<<totalTime<<endl;
    }
    return 0;
}