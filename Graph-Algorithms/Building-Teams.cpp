#include <bits/stdc++.h>
#define int	long long

using namespace std;

void dfs(int i, vector<int> adj[], vector<int> &color){
	if(color[i] == -1) color[i] = 1;

	for(auto node: adj[i]){
		if(color[node] == -1){
			color[node] = 1 - color[i];
			dfs(node, adj, color);
		}

		if(color[node] == color[i]){
			color[node] = 3; // If two adjacent nodes are of the same color, then we color the node with 3 to indicate the graph is NOT BIPARTITE.
		}
	}
}
	
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	 /*
		Here, we just run a bipartite check and if the graph is bipartite, then we color it with colors 1 and 2.
		Otherwise, the answer doesn't exist, hence print IMPOSSIBLE.
	 */

	int n,m;
	cin >> n >> m;

	vector<int> adj[n];
	
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		--x,--y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	vector<int> color(n,-1);

	for(int i=0;i<n;i++){
		if(color[i] == -1){
			dfs(i, adj, color);
		}
	}
	for(auto i:color){
		if(i == 3){ // this is if the graph is not bipartite. Check LINE 16.
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}

	for(auto i:color){
		cout << i + 1 << ' ';
	}
	cout << '\n';



}
