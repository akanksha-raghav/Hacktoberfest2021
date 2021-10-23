#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	
	for(int i=0;i<(1<<n);i++)
	{
	    int x=i^(i>>1);
	    bitset<16>bset(x);
	    for(int i=n-1;i>=0;i--)
	    cout<<bset[i];
	    cout<<endl;
	}
	return 0;
}
