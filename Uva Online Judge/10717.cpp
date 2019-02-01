// Mint

#include<bits/stdc++.h>

using namespace std ;
typedef long long ll ;

ll h[55], tab[15] ;
vector <ll> lcm_vec, vec ;

ll findLCM(vector <ll> &a){
	ll lcm = a[0] ;
	for(int i = 1 ; i < 4 ; i++){
		lcm *= a[i] / __gcd(lcm, a[i]) ;
	}
	return lcm ;
}

void gen_subsets(int level, int indx, int n){

	if(level == 0){
		ll lcm = findLCM(vec) ;
		lcm_vec.push_back(lcm) ;
		return ;
	}

	for(int i = indx ; i < n ; i++){
		vec.push_back(h[i]) ;
		gen_subsets(level-1, i+1, n) ;
		vec.pop_back() ;
	}

}

void solve(int n, int t){

	for(int i = 0 ; i < n ; i++) cin >> h[i] ;
	for(int i = 0 ; i < t ; i++) cin >> tab[i] ;

	vec.clear() ;
	lcm_vec.clear() ;
	gen_subsets(4, 0, n) ;

    for(int j = 0 ; j < t ; j++){

        vector <ll> nearl, nearr ;
        nearl.clear() ; nearr.clear() ;

        for(auto i : lcm_vec){

            ll q = tab[j] / i ;
            if(tab[j] % i == 0){
                nearl.push_back(tab[j]) ;
                nearr.push_back(tab[j]) ;
            } else{
                nearl.push_back(i * q) ;
                nearr.push_back(i * (q+1)) ;
            }

        }

        cout << *max_element(nearl.begin(), nearl.end()) << " " << *min_element(nearr.begin(), nearr.end()) << "\n" ;

    }

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	#endif

	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;

	int n, t ;
	while(cin >> n >> t)
		solve(n, t) ;

	return 0 ;
}
