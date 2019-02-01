// https://code.google.com/codejam/contest/3324486/dashboard#s=p2

#include<bits/stdc++.h>

using namespace std ;
typedef long long ll ;

#define mv 1000000007LL
#define MAX 1000005

ll fact[MAX], inv[MAX], invfact[MAX], pow2[MAX], mc[MAX] ;
ll n, m ;

void preprocess(){

	fact[0] = pow2[0] = fact[1] = inv[1] = invfact[1] = 1 ;
	pow2[1] = 2 ;
	ll m = mv ;
	for(int i = 2 ; i < 1000005 ; i++){
		pow2[i] = (2LL * pow2[i-1]) % m ;
		fact[i] = ((ll)fact[i-1] * i) % m ;
    	inv[i] = (m - (m/i) * (ll)inv[m%i] % m) % m ;
    	invfact[i] = ((ll)invfact[i-1]*inv[i]) % m ;
    }

}


// values from mC1 to mCm
void preprocess1(ll m){

	for(ll i = 1 ; i < m ; i++){
		mc[i] = (fact[m] * invfact[i]) % mv ;
		mc[i] = ( mc[i] * invfact[m-i] ) % mv ;
	}

	mc[m] = mc[0] = 1 % mv ;

}

ll solve(){

	cin >> n >> m ;

	preprocess1(m) ;

	n = 2LL * n ;

	ll val = 0 ;
	for(ll i = 1 ; i <= m ; i++){
		ll v = 0 ;
		v += ( pow2[i] * fact[n-i] ) % mv ;
		v *= mc[i] ;
		v %= mv ;
		val += v * pow(-1, (i+1)%2) ;
		val += 2LL*mv ;
		val %= mv ;
	}

	val %= mv ;

	ll fin = (fact[n] - val + 5LL*mv) % mv ;

	return fin ;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("outsub.txt", "w", stdout) ;
	#endif

	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;

	preprocess() ;

	int t ; cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		cout << "Case #" << i << ": " << solve() << "\n" ;
	}

	return 0 ;
}
