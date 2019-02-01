// 10325

#include<bits/stdc++.h>

using namespace std ;
typedef long long ll ;

ll gcd(ll a, ll b){
    if(a == 0) return b ;
    return gcd(b%a, a) ;
}

int a[20] ;

// used cardinality and math(use lcm, not product)
void solve(int n, int m){

    for(int i = 0 ; i < m ; i++) cin >> a[i] ;

	ll ans = 0 ;

	for(int i = 1 ; i < (1 << m) ; i++){

		int temp = i, v = m-1 ;
		ll pro = 1, g = 0, lcm = 1 ;
		while(temp){
			if(temp & 1){
				g = gcd(lcm, (ll)a[v]) ;
				lcm *= (a[v] / g) ;
			}
			if(lcm > n) break ;
			temp = temp >> 1 ;
			v-- ;
		}

		if(lcm > n) continue ;
		else{
			int parity = __builtin_popcount(i) ;
			if(parity & 1)
				ans += n/lcm ;
			else
				ans -= n/lcm ;
		}

	}

	cout << n - ans << "\n" ;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	#endif

	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;

	int n, m ;
	while(cin >> n >> m) solve(n, m) ;

	return 0 ;
}
