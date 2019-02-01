// 927	Integer Sequences from Addition of Terms
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=9

#include<bits/stdc++.h>

using namespace std ; 

typedef long long ll ;
typedef double db ;

void solve() ;

int main(){

	ll t_ ; cin >> t_ ;
	while(t_--) solve() ;

	return 0 ;
}

void solve(){

	vector <ll> vec_deg ;
	
	ll deg ; cin >> deg ;
	for(ll i = 0 ; i <=  deg ; i++){
		ll x ; cin >> x ;
		vec_deg.push_back(x) ;
	}

	ll d, k ; cin >> d >> k ;

	double D = sqrt(pow(d, 2) + (8 * k * d)) ;

	db n = (-d + D) / (2.0*d) ;
	n = ceil(n) ;

	ll  val = 0 ;
	for(ll i = 0 ; i <= deg ; i++){
		val += pow(n, i) * vec_deg[i] ;
	}

	cout << val << endl ;

}