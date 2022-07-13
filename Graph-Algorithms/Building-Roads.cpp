#include <bits/stdc++.h>
#define pb              push_back
#define int             long long
#define ff              first
#define ss              second
#define all(a)          a.begin(),a.end()
#define ed              '\n'
#define print(x)        cout << #x << " = " << x << "\n";
#define ins             insert
#define mp				make_pair
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
 
void dfs(int i, vi adj[], vi &vis){
	if(vis[i]) return;
	vis[i] = 1;
	for(auto node:adj[i]){
		if(!vis[node]){
			dfs(node, adj, vis);
		}
	}
}
 
void solve(){
 
	int n,m;
	cin >> n >> m;
 
	vi ans;
 
	vi vis(n);
	vi adj[n];
	for(int i=0;i<m;i++){
		int x,y;
		cin >>x >> y;
		--x,--y;
		adj[x].pb(y);
		adj[y].pb(x);
	}	
 
	for(int i=0;i<n;i++){
		if(vis[i] == 0){
			ans.pb(i);
			dfs(i, adj, vis);
		}
	}
 
	cout << ans.size() -1 << ed;
	for(int i=0;i<(int)ans.size()-1;i++){
		cout << ans[i] + 1 <<  ' ' << ans[i+1] + 1 << ed;
	}	
 
 
 
}
 
signed main(){
      ios_base::sync_with_stdio(0);cin.tie(0);
      solve(); 
}
 
