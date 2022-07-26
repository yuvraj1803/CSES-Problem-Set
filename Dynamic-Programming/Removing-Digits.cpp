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

	int n;
	cin >> n;

	vector<int> dp(1000001,1e18); // dp[i] = minimum number of steps needed to make i -> 0.
	
	// if i = abcde... where a,b,c,d,e... are the digits in i, dp[i] can be defined as min(dp[i-a] + 1, dp[i-b] + 1, dp[i-c] + 1, ...)

	// base cases.
	dp[0] = 0;
	for(int i=1;i<=9;i++) dp[i] = 1;
	
	for(int i=10;i<=1000000;i++){
		int j = i;
		while(j > 0){
			int d = j%10;
			if(d != 0) dp[i] = min(dp[i], dp[i-d] + 1);
			j/=10;
		}		
	}
	cout << dp[n] << '\n';

}

