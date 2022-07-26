#include <bits/stdc++.h>
#ifdef debug
	#include "yuvraj/debug.h"
#else
	#define bug(x) 18
#endif
 
#define int	long long
using namespace std;
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s,t;
	cin >> s >> t;
 
	int n = s.size();
	int m = t.size();
 
	vector<vector<int>> dp(n+1, vector<int> (m+1));
 
	dp[0][0] = 0;
	for(int i=0;i<=n;i++){
		dp[i][0] = i;
	}
	for(int i=0;i<=m;i++){
		dp[0][i] = i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1] != t[j-1]){
				dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
			}else{
				dp[i][j] = dp[i-1][j-1];
			}
		}
	}
 
	cout << dp[n][m] << '\n';
 
