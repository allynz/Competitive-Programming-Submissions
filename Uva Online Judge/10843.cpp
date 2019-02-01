// Anne's game

#include<bits/stdc++.h>

using namespace std ;
typedef long long ll ;

#define mv 2000000011

ll modexp(ll x, ll n, ll m){
	if(n == 0) return 1%m ;
	else if(n & 1) return x*modexp(x, n-1, m) % m ;
	else return modexp((x*x)%m, n/2, m) % m ;
}

void solve(int i){
    int n ; cin >> n ;
    cout << "Case #" << i << ": " ;
	if(n <= 2)
		cout << "1\n" ;
	else
		cout << modexp(n, n-2, mv) << "\n" ;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	#endif

	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;

	int t ; cin >> t ;
	for(int i = 1 ; i <= t ; i++) solve(i) ;

	return 0 ;
}
