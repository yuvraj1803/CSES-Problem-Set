#include <bits/stdc++.h>
#ifdef debug
	#include "yuvraj/debug.h"
#else
	#define bug(x) 18;
#endif

using namespace std;

// 0-1 Knapsack Problem


signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,x;
	cin >> n >> x;

	vector<int> val(n), wt(n);

	for(int i=0;i<n;i++) cin >> wt[i];
	for(int i=0;i<n;i++) cin >> val[i];

	vector<vector<int>> dp(n+1, vector<int> (x+1)); // dp[i][j] = maximum value obtained with knapsack capacity of 'j' and considering the first 'i' elements.

	for(int i=1;i<=n;i++){
		for(int j=1;j<=x;j++){
				if(wt[i-1] <= j){
					dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j]);	
				}else{
					dp[i][j] = dp[i-1][j];
				}	
		}
	}

	cout << dp[n][x] << '\n';
	
}
