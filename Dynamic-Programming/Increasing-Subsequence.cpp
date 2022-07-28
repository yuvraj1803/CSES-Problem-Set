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

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	vector<int> LIS; // the longest-increasing-subsequence (initially empty).

	for(int i=0;i<n;i++){
		if(LIS.size() == 0){
			LIS.push_back(a[i]);
		}else{
			if(LIS.back() < a[i]){
				LIS.push_back(a[i]);
			}else{
				auto it = lower_bound(LIS.begin(), LIS.end(), a[i]);
				int index = it - LIS.begin();
				LIS[index] = a[i];
			}
		}	
	}
	
	cout << LIS.size() << '\n';
}
