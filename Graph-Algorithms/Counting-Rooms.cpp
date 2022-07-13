#include <bits/stdc++.h>
 
using namespace std;
 
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

 
void dfs(int x, int y, vector<vector<int>> &vis){
	int N = vis.size();
	int M = vis[0].size();
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(0 <= nx && nx < N && 0 <= ny && ny < M && !vis[nx][ny])
            dfs(nx,ny, vis);
    }
}
 
int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> vis(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            char c;
            cin >> c;
            vis[i][j] = (c == '#');
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!vis[i][j]){
                dfs(i, j, vis);
                ans++;
            }
        }
    }
    cout << ans << '\n';
}
