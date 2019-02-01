// PRINT
// https://www.spoj.com/problems/PRINT/

#include<bits/stdc++.h>
 
using namespace std ;
typedef long long ll ;
 
bool isprime[(ll)1e6 + 5], iscomposite[(ll)1e6] ;
vector <ll> primes ;
 
// store all primes less than 10^5 in a vector
void preprocess(){
    
	primes.clear() ;
	
	for(ll i = 2 ; i < (ll)1e5 ; i++)
	    if(!iscomposite[i])
	        for(ll j = 2*i ; j <= (ll)1e5 ; j += i) iscomposite[j] = 1 ;
	        
	 for(ll i = 2 ; i < (ll)1e5 ; i++) if(!iscomposite[i]) primes.push_back(i) ;
	 
}
 
void segmented_sieve(ll low, ll high){
	
	ll lim = sqrt(high) + 1 ;
 
	for(ll i = 0 ; primes[i] <= lim ; i++){
		ll nmul = low/primes[i] ; nmul = max(nmul, 2LL) ;
		for(ll j = nmul*primes[i] ; j <= high ; j += primes[i]) isprime[j-low] = 0 ;
	}
 
}
 
void solve(){
	
	ll low, high ; cin >> low >> high ;
 
	for(ll i = low ; i <= high ; i++) isprime[i-low] = 1 ; // assume all prime
 
	segmented_sieve(low, high) ;
 
	for(ll i = low ; i <= high ; i++) if(isprime[i-low]) cout << i << '\n' ;
 
}
 
int main(){
    
    ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    
    preprocess() ;
	
	ll t ; cin >> t ;
	while(t--) solve() ;
 
	return 0 ;
} 