// Uva 908
// kruskal(done) and prims(to be done)

#include<bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair < pair<ll, ll>, ll > ppi ;

#define fi first
#define se second
#define pb push_back

ll mst_cost ;
vector < pair < pair<ll, ll>, ll > > edgeList, mst_edges ;

bool comparator(ppi a, ppi b){
	return a.se < b.se ;
}

class DisjointSets{
    
    public:
	
	int n ;
	vector <int> p ;
	vector <int> csize ;

	DisjointSets(int len){ // constructor
		n = len ;
		p.resize(n+1) ; csize.resize(n+1) ;
		memset(csize, 1, sizeof(csize)) ; // size of each node is 1 in beginning
		for(int i = 0 ; i < n ; i++) p[i] = i ; // all are their own parent in beginning
	}
	
	int parent(int a){
		while(p[a] != a) a = p[a] ;
		return a ;
	}

	// union by rank
	void join(int a, int b){

		int p1 = parent(a), p2 = parent(b) ;
		int c1 = csize[p1], c2 = csize[p2] ;

		if(c1 < c2){ p[p1] = p2 ; csize[p2] += c1 ; }
		else{ p[p2] = p1 ; csize[p1] += c2 ; }

	}

	// compresses path for whole set
	void compress_path(){
		for(int i = 0 ; i < n ; i++)
			p[i] = parent(i) ;
	}

} ;

void kruskals(ll n){
	
	DisjointSets v(n) ;

	sort(edgeList.begin(), edgeList.end(), comparator) ;

	mst_cost=0 ;

	for(auto i : edgeList){
		if(v.parent(i.fi.fi) != v.parent(i.fi.se)){
			mst_edges.pb(i) ;
			mst_cost += i.se ;
			v.join(i.fi.fi, i.fi.se) ;
		}
	}

}

void prims(){

	
	
}

void solve(ll n){

	ll ans1 = 0 ; edgeList.clear() ;

	for(ll i = 1 ; i < n ; i++){
		ll x, y, weight ; cin >> x >> y >> weight ;
		ans1 += weight ;
	}
	
	ll k ; cin >> k ;
	for(ll i = 0 ; i < k ; i++){
		ll x, y, weight ; cin >> x >> y >> weight ;
		pair < pair <ll, ll>, ll > a = {{x, y}, weight} ;
		edgeList.pb(a) ;
	}

	ll m ; cin >> m ;
	for(ll i = 0 ; i < m ; i++){
		ll x, y, weight ; cin >> x >> y >> weight ;
		pair < pair <ll, ll>, ll > a = {{x, y}, weight} ;
		edgeList.pb(a) ;
	}

	kruskals(n) ;

	cout << ans1 << '\n' << mst_cost << "\n" ;

} 

int main(){
	
	ll N, i = 0 ;
	while(cin >> N){
	    if(i!=0)cout << '\n' ;
		solve(N) ;
		i++ ;
	}

	return 0 ;
}