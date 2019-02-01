// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1410
// Simple

#include<bits/stdc++.h>

using namespace std ;
typedef long long ll ;

void solve(ll a, ll b){

	ll num = 0 ;
	int n = 0 ;
	ll temp = max(a, b) ;
	while(temp){
        n++ ;
        temp = temp >> 1 ;
	}

	for(int i = 0 ; i < n ; i++){
		if(a&1 && b&1){
            // do nothing
            // not continue as update have to be done in each iteration
		} else if(a&1 || b&1)
			num += (ll)pow(2, i) ;
        a = a >> 1 ; b = b >> 1 ;
	}

	cout << num << "\n" ;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	#endif

	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;

	ll a, b ;
	while(cin >> a >> b)
		solve(a, b) ;

	return 0 ;
}
