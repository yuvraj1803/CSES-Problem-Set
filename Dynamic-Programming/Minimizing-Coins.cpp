#include <bits/stdc++.h>
#ifdef debug
	#include "yuvraj/debug.h"
#else
	#define bug(x) 18
#endif
#define int long long
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,x;
	cin >> n >> x;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	vector<int> dp(x + 1, INT_MAX); // dp[i] = minimum number of coins required to obtain a weight of i.

	dp[0] = 0;

	for(int i=1;i<=n;i++){
		for(int j=0;j<=x;j++){
			if(j - a[i-1] >= 0) dp[j] = min(dp[j], dp[j - a[i-1]] + 1);
		}
	}

	cout << (dp[x] == INT_MAX ? -1 : dp[x])  << '\n';

	
}

