#include <bits/stdc++.h>
#define int	long long

using namespace std;

// solved using Floyd-Warshall Algorithm

int dist[501][501];

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,t;
	cin >> n >> m >> t;
	
	for(int i=0;i<501;i++){
		for(int j=0;j<501;j++){
			dist[i][j] = 1e18;
		}
	}



	for(int i=0;i<m;i++){
		int a,b,w;
		cin >> a >> b >> w;
		--a,--b;
		dist[a][a] = 0;
		dist[b][b] = 0;
		dist[a][b] = min(dist[a][b],w);
		dist[b][a] = min(dist[b][a],w);
	}

	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	while(t--){
		int s,d;
		cin >> s >> d;
		--s,--d;
		int ans = min(dist[s][d], dist[d][s]);
		if(ans == 1e18) cout << -1;
		else cout << ans;

		cout << '\n';
	}

}
