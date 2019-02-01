// Tri-du

#include<bits/stdc++.h>

using namespace std ;
typedef long long ll ;

void solve(int a, int b){
	
	if(a == b)
		cout << a << "\n" ;
	else 
		cout << max(a, b) << "\n" ;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	#endif

	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;

	int a, b ;
	while(cin >> a >> b)
		solve(a, b) ;

	return 0 ;
}
