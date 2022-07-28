#include <bits/stdc++.h>
#ifdef debug
	#include "yuvraj/debug.h"
#else
	#define bug(x) 18;
#endif

#define int	long long
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	const int MOD = 1e9 + 7;

	int dp[n][m+1];
	memset(dp, 0, sizeof(dp));
	
	if(a[0] == 0){
		for(int i=1;i<=m;i++) dp[0][i] = 1;
	}else{
		dp[0][a[0]] = 1;
	}

	for(int i=1;i<n;i++){
		if(a[i] == 0){
			for(int j=1;j<=m;j++){
				dp[i][j] += dp[i-1][j];
				if(j - 1 >= 1) dp[i][j] += dp[i-1][j-1];
				if(j + 1 <= m) dp[i][j] += dp[i-1][j+1];
				dp[i][j] %= MOD;
			}
		}else{
			dp[i][a[i]] += dp[i-1][a[i]];
			if(a[i] - 1 >= 1) dp[i][a[i]] += dp[i-1][a[i] -1];
			if(a[i] + 1 <= m) dp[i][a[i]] += dp[i-1][a[i] +1];
			dp[i][a[i]]%=MOD;
		}
	}	

	int ans = 0;
	for(int i=1;i<=m;i++){
		(ans += dp[n-1][i])%=MOD;
	}

	cout << ans << '\n';


}

