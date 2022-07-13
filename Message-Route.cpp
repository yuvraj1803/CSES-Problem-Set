#include <bits/stdc++.h>
#define int	long long

using namespace std;
class DSU{
public:
	set<int> s;
	vector<int> parent;
	vector<int> rank;
	DSU(int n){
		parent.resize(n);
		rank.resize(n);
		for(int i=0;i<n;i++){
			s.insert(i);
			parent[i] = i;
			rank[i] = 0;
		}
	}

	int Find(int x){
		if(parent[x]!=x){
			parent[x] = Find(parent[x]);
		}
		return parent[x];
	}

	void Union(int x, int y){
		int xR = Find(x);
		int yR = Find(y);

		if(xR == yR){
			return;
		}

		if(rank[xR] < rank[yR]){
			parent[xR] = yR;
		}else if(rank[xR] > rank[yR]){
			parent[yR] = xR;
		}else{
			parent[xR] = yR;
			rank[yR]++;
		}
	}

	int Same(int x, int y){
		return Find(x) == Find(y);
	}
};

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	cin >> n >> m;
	DSU d(n);
	vector<int> adj[n];

	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		--x,--y;
		d.Union(x,y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	// NODES ARE ZERO BASED HERE!.
	// I am using a DSU to check if 0 and n-1 are in the same component or not.
	// Although this can also be done using DFS.
	
	if(!d.Same(0,n-1)){
		// they belong to two differnt components so we can't connect them.
		cout << "IMPOSSIBLE\n";
	}else{
		// finding the shortest path between 0 and n-1. This is done using BFS.

		queue<int> q;
		vector<int> vis(n);
		q.push(0);
		vis[0] = 1;
		vector<int> prev(n);
		while(q.size()){
			int i = q.front();
			q.pop();
			
			for(auto node: adj[i]){
				if(!vis[node]){\
					prev[node] = i;
					q.push(node);
					vis[node] = 1;
				}
			}
		}

		// retracing the path from node (n-1) to node (0);

		vector<int> path;

		int curr = n-1;
		path.push_back(curr);
		while(curr != 0){
			curr = prev[curr];
			path.push_back(curr);
		}

		cout << path.size() << '\n';
		reverse(path.begin(), path.end());
		for(auto i:path){
			cout << i + 1 << ' ';
		}
		cout << '\n';


	}



	




}
