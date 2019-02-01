// Cows and Cars

#include<bits/stdc++.h>

using namespace std ;
typedef long long ll ;

void solve(int a, int b, int c){

	int n = a + b ;

	int v1 = a*b + b*(b-1), v2 = n*(n-c-1) ;

	double v = v1 / (1.0 * v2) ;

	printf("%.5f\n", v) ;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	#endif

	int a, b, c ;
	while(cin >> a >> b >> c)
		solve(a, b, c) ;

	return 0 ;
}
