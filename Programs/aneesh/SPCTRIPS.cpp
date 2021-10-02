#include <bits/stdc++.h>
using namespace std;

struct node {
    int count=1;
    vector<int> factors;
    
    node() {
        factors = vector<int> (1,1);
    }
    
};


int main() {
	// your code goes here
// 	int abc = 0;

    int lim = 1e5+1;
    
    vector<node> v(lim, node());
    
	for(int i=2; i<lim; ++i) {
        for(int j=2*i; j<lim; j+=i) {
            v[j].count++;
            v[j].factors.push_back(i);
	    }
	}

    // for(int i=0; i<v[12].factors.size(); ++i) {
    //     cout<<v[12].factors[i]<<" ";
    // }
    
	int t,n;
	int num;
	int first;
	int second;
	
	cin>>t;
	while(t--) {
	    cin>>n;
	    
	    int ans = 0;
	   
	    for(int i=2; i<=n; ++i) {
	        num = n%i;
	        auto it = upper_bound(v[i].factors.begin(), v[i].factors.end(), num);
	        if(it == v[i].factors.end()) {
	            first = v[i].count;
	            second = 0;
	        } else {
	            first =  it - v[i].factors.begin();
	            second = v[i].factors.end() - it;
	        }
	        
	       ans += (n/i +1 )*first + (n/i)*second;
	    } 
	   
	    
	    cout<<ans<<"\n";
	    
	}
	
	
	return 0;
}
