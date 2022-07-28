#include <bits/stdc++.h>
#ifdef debug
	#include "yuvraj/debug.h"
#else
	#define bug(x) 18
#endif
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,x;
	cin >> n >> x;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	vector<int> dp(x + 1, 0); // dp[i] = number of ways to construct sum of i. 
	dp[0] = 1;
	
	// notice the order of these for loops below. They are the exact opposite in Coin Combinations I. This means that, this order of for-loops gives an "ordered" solution.

	for(int i=0;i<n;i++){
		for(int j=0;j<=x;j++){
			if(j - a[i] >= 0){
				dp[j] += dp[j - a[i]];
				dp[j]%=MOD;
			}
		}
	}

	cout << dp[x]  << '\n';

	
}

