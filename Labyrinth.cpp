#include <bits/stdc++.h>
#define int	long long
 
using namespace std;
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin >> n >> m;
 
	vector<vector<int>> a(n, vector<int>(m));
 
	int dx[4] = {1,-1,0,0};
	int dy[4] = {0,0,-1,1};
	string dir = "DULR";
 
	pair<int,int> start, stop;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char c;
			cin >> c;
			a[i][j] = (c != '#');
			if(c == 'A') start = make_pair(i,j);
			if(c == 'B') stop  = make_pair(i,j);
		}
	}
	vector<vector<int>> vis(n, vector<int>(m));
	queue<pair<int,int>> q;
	q.push(start);
	vis[start.first][start.second] = 1;
	map<pair<int,int>, int> prev;
	while(q.size()){
		pair<int,int> u = q.front();
		q.pop();
		int x = u.first;
		int y = u.second;
		
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= n or nx < 0 or ny<0 or ny>=m) continue;
			if(vis[nx][ny]) continue;
			if(a[nx][ny] == 0) continue;
			vis[nx][ny] = 1;
			prev[make_pair(nx,ny)] = i;
			q.push(make_pair(nx,ny));
		}
	}
 
	
 
	vector<int> steps;
	if(vis[stop.first][stop.second] == 0){
		cout << "NO" << '\n';
	}else{
		cout << "YES" << '\n';
	 	while(stop!=start){
			int p = prev[stop];
			stop.first -= dx[p];
			stop.second -= dy[p];
			steps.push_back(p);
		}
 
	reverse(steps.begin(), steps.end());
 
	cout << steps.size() << '\n';
	
	for(auto i:steps){
		cout << dir[i];
	}
	cout << '\n';
	}
 
 
 
}
