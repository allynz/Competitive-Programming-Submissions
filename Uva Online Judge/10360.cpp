// 10360 - Rat Attack
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1301

#include<bits/stdc++.h>

using namespace std ;

typedef long long ll ;
#define pb push_back
#define mp make_pair

void solve() ;
void explode(ll, ll, ll, ll) ;

ll mat[1050][1050] ;

int main(){
	
	ll t_ ; cin >> t_ ;

	while(t_--) solve() ;

	return 0 ;
}

void solve(){
	
	ll d ; cin >> d ;
	ll n ; cin >> n ;

	// clear mat but more optimally than this
	for(ll i = 0 ; i <= 1025 ; i++){
		for(ll j = 0 ; j <= 1025 ; j++){
			mat[i][j] = 0 ;
		}
	}

	vector < pair <ll, ll> > vec ;
	vector <ll> sizes ;
	
	vec.clear() ; sizes.clear() ;

	for(ll i = 0 ; i < n ; i++){
		ll x, y, z ; cin >> x >> y >> z ;
		vec.pb(mp(x,y)) ;
		sizes.pb(z) ;
	}

	for(ll i = 0 ; i < n ; i++){
		explode(vec[i].first, vec[i].second, d, sizes[i]) ;
	}

	ll maxval = 0, c1 = 0, c2 = 0 ;

	for(ll i = 0 ; i < 1025 ; i++){
		for(ll j = 0 ; j < 1025 ; j++){
			if(mat[i][j] > maxval){
				maxval = mat[i][j] ;
				c1 = i ; c2 = j ;
			}
		}
	}

	cout << c1 << " " << c2 << " " << maxval << endl ;
}

void explode(ll x, ll y, ll d, ll val){

	ll x1 = x - d ; ll y1 = y - d ;
	ll x2 = x + d ; ll y2 = y + d ;

	x1 = max((ll)0, x1) ; y1 = max((ll)0, y1) ;
	x2 = min((ll)1025, x2) ; y2 = min((ll)1025, y2) ;
	
	for(ll i = x1 ; i <= x2 ; i++){
		for(ll j = y1 ; j <= y2 ; j++){
			mat[i][j] += val ;
		}
	}

}