#include <bits/stdc++.h>
#define int	long long

using namespace std;

const int inf = 1e18;

/*

	solve for maximum distance between 0 to n-1 using bellman-ford
	print -1 if it contains a negative cycle.
	important: on the nth cycle check if the nodes that change are reachable from 0 and n-1. if they do print -1.
 */


void dfs(int i, vector<int> &vis, vector<vector<int>> adj){
	vis[i] = 1;

	for(auto node: adj[i]){
		if(!vis[node]){
			dfs(node, vis, adj);
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin >> n >> m;
	vector<vector<int>> a(n), b(n);	
	vector<tuple<int,int,int>> edges(m);
	vector<int> adj[n];
	for(int i=0;i<m;i++){
		int x,y,w;
		cin >> x >> y >> w;
		--x,--y;
		a[x].push_back(y);
		b[y].push_back(x);
		edges[i] = {x,y,-w};
	}

	vector<int> vis0(n), visn(n);
	dfs(0,vis0,a);
	dfs(n-1,visn,b);

	vector<int> dist(n, inf);
	dist[0] = 0;
	int negCycle = 0;
	for(int i=0;i<n;i++){
		for(auto e: edges){
			int a,b,w;
			tie(a,b,w) = e;
			if(dist[b] > dist[a] + w){
				dist[b] = dist[a] + w;
				if(i == n-1 and vis0[a] and visn[b]) negCycle = 1;
			}
		}
	}	

	if(negCycle){
		cout << -1 << '\n';
	}else{
		cout << -dist[n-1] << '\n';
	}
	
	

}
