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
#define pii pair<ll,ll>
 
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
 
vi adj[100001];
vi res;
int in[100001]; // Array storing indegree of each node
//In degree is the degree of node i.e the number of nodes pointing towards it
 
bool kahn(int n){
    priority_queue<int,vi,gi>q; //Since we need lexographically minimum thus instead of queue we use min heap
 
    for(int i = 1;i<=n;i++){
        if(in[i] == 0)
            q.push(i);
    }
 
 
    while(!q.empty()){
 
        int curr = q.top();
        q.pop();
 
        res.pb(curr);
 
        for(int node :adj[curr]){
            in[node]--;
 
            if(in[node] == 0){
                q.push(node);
            }
 
        }
 
 
    }
 
    
    return res.size() == n;
 
 
}
 
 
void solve(){
 
    int n , m , x , y;
    cin>>n>>m;
 
    while(m--){
        cin>>x>>y;
 
        //edge from x to y directed edge
        adj[x].pb(y);
        in[y]++;
    }
 
    if(!kahn(n)){
        cout<<"IMPOSSIBLE";
    }else{
        for(auto&x : res){
            cout<<x<<" ";
        }
    }
 
 
}
 
 
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    solve();
 
}