#include <bits/stdc++.h>
#ifdef debug
	#include "yuvraj/debug.h"
#else
	#define bug(x) 18
#endif

#define int	long long
using namespace std;

// basic topological sorting is required. before that check if the graph is a DAG or not!

const int mxN = 1e5 + 10;
int n,m;
vector<vector<int>> adj(mxN);
vector<int> vis1(mxN), vis2(mxN);
vector<int> topo;
int cycle = 0;

int dfs1(int i){ // dfs1 checks if graph is DAG?
	vis1[i] = 1;

	for(auto node: adj[i]){
		if(vis1[node] == 1){
			cycle = 1;
			return 1;
		}else if(vis1[node] == 0){
			if(dfs1(node)) return 1;
		}
	}

	vis1[i] = 2;
	return 0;
}

void dfs2(int i){ //building the toposort
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
	}
	
	for(int i=0;i<n;i++){
		if(vis1[i] == 0 and dfs1(i)) break;	
	}

	if(cycle){
		cout << "IMPOSSIBLE" << '\n';
		return 0;
	}

	for(int i=0;i<n;i++){
		if(vis2[i] == 0){
			dfs2(i);
		}
	}

	reverse(topo.begin(), topo.end());

	for(auto i:topo) cout << i+1 << ' ';
	cout << '\n';

}
