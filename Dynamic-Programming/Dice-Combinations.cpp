#include <bits/stdc++.h>
#ifdef debug
	#include "yuvraj/debug.h"
#else
	#define bug(x) 18
#endif

#define int	long long
using namespace std;

const int mxN = 1e6;
int MOD = 1e9 + 7;
int dp[mxN+1];

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for(int i=4;i<=mxN;i++){
		for(int j=1;j<=6;j++){
			if(i - j >= 0){
				(dp[i] += dp[i-j])%=MOD;
			}
		}
	}

	int n;
	cin >> n;

	cout << dp[n]%MOD << '\n';


}
