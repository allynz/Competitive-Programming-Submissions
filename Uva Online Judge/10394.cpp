#include<bits/stdc++.h>

using namespace std ;
typedef long long ll ;

#define INF (2LL*(int)1e7 + 5)

bool iscomposite[20000005] ;
vector <int> prime ;
vector < pair <int, int> > vec ;

void preprocess(){

	for(ll i = 2 ; i < INF ; i++)
		if(!iscomposite[i]){
			prime.push_back(i) ;
			for(ll j = 2*i ; j < INF ; j += i)
				iscomposite[j] = 1 ;
		}

	for(int i = 0 ; i < prime.size() - 1 ; i++){
		if(prime[i+1] == prime[i] + 2)
			vec.push_back(make_pair(prime[i], prime[i+1])) ;
	}

}

int main(){
    
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	#endif
    
	//ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;

	preprocess() ;

	int n ;
	while(cin >> n)
    	cout << "(" << vec[n-1].first << ", " << vec[n-1].second << ")\n" ;

	return 0 ;
}
