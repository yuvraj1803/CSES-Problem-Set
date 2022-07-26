#include <bits/stdc++.h>
#ifdef debug
	#include "yuvraj/debug.h"
#else
	#define bug(x) 18
#endif

#define int	long long
using namespace std;

// Subset Sum Problem

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	int sum = 0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		sum += a[i];
	}

	int T = sum;

	vector<vector<int>> dp(n+1, vector<int> (T+1));

	for(int i=0;i<=n;i++) dp[i][0] = 1;
	for(int i=0;i<=T;i++) dp[0][i] = 0;
	dp[0][0] = 1;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=T;j++){
			int notTake = dp[i-1][j];
			int take = 0;
			if(j - a[i-1] >= 0) take = dp[i-1][j - a[i-1]];

			dp[i][j] = take | notTake;
		}
	}


	vector<int> ans;
	for(int i=1;i<=T;i++){
		if(dp[n][i]){
			ans.push_back(i);
		}
	}

	cout << ans.size() << '\n';

	for(auto i:ans){
		cout << i << ' ';
	}
	cout << '\n';

}
