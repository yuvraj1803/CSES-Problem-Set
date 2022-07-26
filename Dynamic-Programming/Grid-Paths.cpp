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

	int MOD = 1e9 + 7;

	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));

	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		for(int j=0;j<n;j++){
			a[i][j] = (s[j] == '*'); // traps are denoted by 1 and others by 0.
		}
	}

	int dp[n][n];
	memset(dp, 0, sizeof(dp));
	
	for(int i=0;i<n;i++){
		if(a[i][0] == 1) break;
		else dp[i][0] = 1;
	}		

	for(int i=0;i<n;i++){
		if(a[0][i] == 1) break;
		else dp[0][i] = 1;
	}

	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(a[i][j] == 1) dp[i][j] = 0;
			else (dp[i][j] += dp[i-1][j] + dp[i][j-1])%=MOD;
		}
	}

	cout << dp[n-1][n-1]%MOD << '\n';
}
