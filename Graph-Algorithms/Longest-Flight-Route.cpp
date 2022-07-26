#include <bits/stdc++.h>
#ifdef debug
	#include "yuvraj/debug.h"
#else
	#define bug(x) 18
#endif

#define int	long long
using namespace std;

// first build the topological sort and use dynamic-programming to find longest path between 0 and n-1. The path can be traced back by having a parent array.


const int mxN = 1e5 + 10;
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
	
	vector<int> dp(n); // dp[i] = longest path from node 0 to node i.
	vector<int> parent(n,-1);
	dp[0] = 1;
		
	for(auto i:topo){
		for(auto j: revadj[i]){
			if(dp[i] < dp[j] + 1 and dp[j]){
				dp[i] = dp[j] + 1;
				parent[i] = j;
			}
		}
	}


	int curr = n-1;
	vector<int> path;
	while(curr != -1){
		path.push_back(curr);
		curr = parent[curr];
	}

	reverse(path.begin(), path.end());
	if(dp[n-1] < 2){
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	cout << dp[n-1] << '\n';
	for(auto i:path) cout << i+1 << ' ';
	cout << '\n';

}
