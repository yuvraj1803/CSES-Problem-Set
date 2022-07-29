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

	const int INF = 1e18;

	int a,b;
	cin >> a >> b;

	vector<vector<int>> dp(a+1, vector<int> (b+1)); // dp[i][j] = minimum possible moves for a ixj rectangle

	for(int i=0;i<=a;i++){
		for(int j=0;j<=b;j++){
			if(i == j) dp[i][j] = 0;
			else{
				dp[i][j] = INF;
				for(int k=1;k<i;k++){
					dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
				}

				for(int k=1;k<j;k++){
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
				}

			}
		}
	}

	cout << dp[a][b] << '\n';


}

