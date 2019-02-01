// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1753
// Don't forget the even check!!

#include<bits/stdc++.h>

using namespace std ;
typedef long long ll ;

void solve(){

	ll a, b ; cin >> a >> b ;
	if((a+b)%2 || (a-b)%2){
        cout << "impossible\n" ;
        return ;
	}
	ll x = (a + b) / 2LL , y = (a - b) / 2LL ;


	if(x >= 0 && y >= 0)
		cout << max(x, y) << " " << min(x, y) << "\n" ;
	else
		cout << "impossible\n" ;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	#endif

	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;

	int t ; cin >> t ;
	while(t--)
		solve() ;

	return 0 ;
}
