#include <bits/stdc++.h>
#ifdef debug
	#include "yuvraj/debug.h"
#else
	#define bug(x) 18
#endif

#define int	long long
using namespace std;

const int MOD = 1e9 + 7;
const int mxN = 1e5 + 7;
int n,m;
vector<vector<int>> adj(mxN), revadj(mxN); // adjacency list and reverse-adjacency list
vector<int> vis2(mxN);
vector<int> topo;
int cycle = 0;

void dfs2(int i){ 
	vis2[i] = 1;

	for(auto node: adj[i]){
		if(!vis2[node]){
			dfs2(node);
		}
	}
	topo.push_back(i);
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		--a, --b;
		adj[a].push_back(b);
		revadj[b].push_back(a);
	}
	
	for(int i=0;i<n;i++){
		if(vis2[i] == 0){
			dfs2(i);
		}
	}

	reverse(topo.begin(), topo.end());

	vector<int> dp(n); // dp[i] = number of ways of reaching node i from node 0.
	dp[0] = 1;

	for(auto i:topo){
		for(auto j:revadj[i]){
			(dp[i] += dp[j])%=MOD;
		}
	}

	cout << dp[n-1]%MOD << '\n';
	
	
}

