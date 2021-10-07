#include<bits/stdc++.h>
using namespace std;



#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<long long>
#define gi greater<int>
#define endl "\n"
#define pii pair<long long ,long long >

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

struct edge {
	int a;
	int b;
	int w;
};


edge ar[100001];
int par[10001];

bool cmp(edge x , edge y){
	return x.w<y.w;
}

int find(int a){
	if(par[a] == -1)
		return a;

	return par[a] = find(par[a]);
}

void merge(int a , int b){
	par[a] = b;
}


int main() {
    fastio();

    int n , m;
    cin>>n>>m;

    for(int i = 1;i<=n;i++){
    	par[i] = -1;
    }

    for(int i = 0;i<m;i++){
    	cin>>ar[i].a>>ar[i].b>>ar[i].w;
    }

    sort(ar , ar+m , cmp);

    int x , y , sum = 0;
    for(int i = 0;i<m;i++){
    	x = find(ar[i].a);
    	y = find(ar[i].b);

    	if(x != y){
    		sum += ar[i].w;
    		merge(x,y);
    	}

    }
    cout<<sum<<endl;


}