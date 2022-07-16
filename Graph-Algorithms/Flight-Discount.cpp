#include <bits/stdc++.h>
#define int	long long

using namespace std;
	
const int INF = 1e18;

vector<int> dijkstra(int src, vector<vector<pair<int,int>>> adj){
		int n = adj.size();

		vector<int> dist(n, INF);
		vector<int> vis(n);
		dist[src] = 0;
		priority_queue<pair<int,int>> pq;
		pq.push({0,src});

		while(pq.size()){
			int a = pq.top().second;
			pq.pop();
			if(vis[a]) continue;
			vis[a] = 1;
			for(auto node: adj[a]){

				int b = node.first;
				int w = node.second;
				if(dist[b] > dist[a] + w){
					dist[b] = dist[a] + w;
					pq.push({-dist[b], b});
				}
					
			}
		}

		return dist;
		
}

/*

   For every edge from vertices A and B, we check the minimum distance from 1 to A and minimum distance from B to N. This can be done using Dijkstra's Shortest Path Algorithm.

   Now, we apply the coupon to the edge from A to B and sum the values on the path that is, dist(1->A) + weight(AB)/2 + dist(B->N).

*/


signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin >> n >> m;

	vector<vector<pair<int,int>>> adj(n), revAdj(n);
	map<pair<int,int>, int> edges;
	
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		--a,--b;
		adj[a].push_back({b,c});
		revAdj[b].push_back({a,c});
		edges[make_pair(a,b)] = c;
	}

	vector<int> dist0 = dijkstra(0, adj);
	vector<int> distn = dijkstra(n-1,revAdj);
	


	int ans = INF;
	
	for(auto e:edges){
		pair<int,int> edge = e.first;
		int w = e.second;
		ans = min(ans, dist0[edge.first] + w/2  + distn[edge.second]);
	}

	cout << ans << '\n';

		
}
