// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1243

#include<bits/stdc++.h>

using namespace std ;
typedef long long ll ;

void solve(ll n){

	// simple formula is there (already known)
	// but learn the mathematics for knowledge and can be used in other equations

	ll val = (n * (n + 1)) / 2LL ;

	cout << val*val << "\n" ;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	#endif

	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;

	ll n ;
	while(cin >> n)
		solve(n) ;

	return 0 ;
}
