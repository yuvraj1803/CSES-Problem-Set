#include <bits/stdc++.h>
#define int	long long

using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int n,m;
	cin >> n >> m;

	vector<pair<int,int>> adj[n];

	for(int i=0;i<m;i++){
		int x,y,w;
		cin >> x >> y >> w;
		--x,--y;
		adj[x].push_back({y,w});
	}
	
	priority_queue<pair<int,int>> q;

	vector<int> dist(n, 1e18);
	dist[0] = 0;
	q.push({0,0}); // 0 being the source
	vector<int> vis(n);
	while(q.size()){
		
		int a = q.top().second;
		q.pop();
		if(vis[a]) continue;
		vis[a] = 1;

		for(auto u: adj[a]){
			int b = u.first;
			int w = u.second;

			if(dist[b] > dist[a] + w){
				dist[b] = dist[a] + w;
				q.push({-dist[b], b});
			}
		}
	}

	for(auto i: dist){
		cout << i << ' ';
	}
	cout << '\n';

}

