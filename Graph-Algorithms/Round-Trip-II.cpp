#include <bits/stdc++.h>
#define int	long long
 
using namespace std;
 
 
int dfs(int i, vector<int> adj[], vector<int> &vis, vector<int> &parent, int &start, int &stop){
	vis[i] = 1;
	
	for(auto node: adj[i]){
	
 
		if(vis[node] == 1){
			start = node;
			stop = i;
			return 1;
		}else if(vis[node] == 0){
			parent[node] = i;
			if(dfs(node, adj, vis, parent, start, stop)){
				return 1;
			}	
		}
	}
 	vis[i] = 2;
	return 0;
}
 
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i=0;i<m;i++){
		int x,y;
		cin >>x  >> y;
		--x,--y;
		adj[x].push_back(y);
	}
 
 
	vector<int> vis(n);
	vector<int> parent(n,-1);	
	
	int start = -1;
	int stop = -1;
 
	for(int i=0;i<n;i++){
		if(!vis[i] and dfs(i,adj, vis,parent, start, stop)){
			break;
		}
	}
 
 
	int possible = 1;
	if(start == -1){
		possible = 0;
	}
	vector<int> path;
	path.push_back(stop);
	int curr = parent[stop];
 
	while(curr!=parent[start]){
		path.push_back(curr);
		curr = parent[curr];
	}
 
 
	reverse(path.begin(), path.end());
 
	path.push_back(path[0]);
	

 
	if(possible){
		cout << path.size() << '\n';
		for(auto i:path) cout << i+1 << ' ';
		cout << '\n';
	}else{
		cout << "IMPOSSIBLE\n";
	}
 
 
 
}
