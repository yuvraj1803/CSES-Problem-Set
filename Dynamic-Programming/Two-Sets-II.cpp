#include <bits/stdc++.h>
#ifdef debug
	#include "yuvraj/debug.h"
#else
	#define bug(x) 18;
#endif

#define int	long long
using namespace std;

// s + s == n*(n + 1)/2
// if n*(n+1)/2 is odd, we print 0.
// else we print the number of ways to make the subset sum n*(n+1)/4 using DP.


signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
		
	const int MOD = 1e9 + 7;
		
	int n;
	cin >> n;

	vector<int> a(n);  

	int s = n*(n + 1)/2;

	if(s%2 == 1){
		cout << 0 << '\n';
		return 0;
	}else s/=2;

	vector<vector<int>> dp(n, vector<int> (s + 1)); // dp[i][j] = number of ways to get subset_sum 'j' using first 'i' elements of the array.

	dp[0][0] = 1;

	for(int i=1;i<n;i++){
		for(int j=0;j<=s;j++){
			int not_take = dp[i-1][j];
			int take = 0;
			if(j - i >=0) take = dp[i-1][j - i];

			(dp[i][j] = take + not_take)%=MOD;
		}
	}
	

	cout << dp[n-1][s] << '\n';


}

