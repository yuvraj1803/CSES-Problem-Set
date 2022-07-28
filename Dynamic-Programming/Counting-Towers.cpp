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
	
	const int mxN = 1e6 + 7;
	const int MOD = 1e9 + 7;

	vector<vector<int>> dp(mxN, vector<int> (2));

	dp[1][0] = dp[1][1] = 1;

	for(int i=2;i<mxN;i++){
		dp[i][0] += 2*dp[i-1][0];
		dp[i][1] += dp[i-1][0];
		dp[i][0] += dp[i-1][1];
		dp[i][1] += 4*dp[i-1][1];

		dp[i][0]%=MOD;
		dp[i][1]%=MOD;
	}
	

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		cout << (dp[n][1] + dp[n][0])%MOD << '\n';
	}

}

