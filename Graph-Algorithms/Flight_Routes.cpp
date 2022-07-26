#include <bits/stdc++.h>
#ifdef debug
	#include "yuvraj/debug.h"
#else
	#define bug(x) 18
#endif

#define int	long long
using namespace std;

// here, we maintain a priority queue for each node have its k-best distances.


signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m,k;
	cin >> n >> m >> k;

	vector<vector<pair<int,int>>> adj(n);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	priority_queue<int> best[n];

	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		--a, --b;
		adj[a].push_back({b,c});
	}	
	best[0].push(0);
	pq.push({0,0});

	while(pq.size()){
		int a = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if(d > best[a].top()) continue;
		
		for(auto i: adj[a]){
			int b = i.first;
			int dd = i.second;

			int curr_d = d + dd;

			if((int)best[b].size() < k){
				best[b].push(curr_d);
				pq.push({curr_d, b});
			}else if(curr_d < best[b].top()){
				best[b].pop();
				best[b].push(curr_d);
				pq.push({curr_d, b});
			}	
		}
	}

	vector<int> ans;

	while(best[n-1].size()){
		ans.push_back(best[n-1].top());
		best[n-1].pop();
	}
	reverse(ans.begin(), ans.end());
	for(auto i:ans) cout << i << ' ';
	cout << '\n';

}
