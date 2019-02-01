// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=439
// implementation heavy C++ stringstream and presentation

#include<bits/stdc++.h>

using namespace std ;
typedef long long ll ;

void f(vector <ll> &c, vector <ll> &x){
    
    ll cnt = 0 ;
    for(auto i : x){
        
        ll val = 0 ;

        for(ll j = c.size() - 1, k = 0 ; k < c.size() && j >= 0 ; j--, k++){
            val += c[k]*(ll)pow(i,j) ;
            //cout << val << " " ;
        }

        cout << val ;
        if(cnt+1 < x.size()) cout << " " ;
        cnt++ ;

    }

    cout << "\n" ;

}

void solve(string s){

    stringstream ss(s) ;

    vector <ll> vec, vec1 ; vec.clear() ;
    while(!ss.eof()){
        ll x ; ss >> x ;
        //cout << x << " " ;
        vec.push_back(x) ;
    }

    string s1 ; getline(cin, s1) ;
    stringstream ss1(s1) ;

    //cout << s << "\n" << s1 << "\n" ;

    vec1.clear() ;
    while(!ss1.eof()){
        ll x ; ss1 >> x ;
        vec1.push_back(x) ;
    }

    f(vec, vec1) ;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	#endif

	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;

	string s ;
	while(getline(cin, s)){
	    if(s == "") break ;
		solve(s) ;
	}

	return 0 ;
}
