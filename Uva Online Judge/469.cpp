// UVa 469
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=410

#include<bits/stdc++.h>
#include<stdio.h>

using namespace std ;

char s[105][105] ;
bool visited[105][105] ;
int m, n ;
int rd[8], cd[8] ;

int ff(int i, int j){

	if(i < 0 || j < 0 || i >= n || j >= m) return 0 ;
	else{

		if(visited[i][j]) return 0 ;
		else{
			visited[i][j] = 1 ;
			if(s[i][j] == 'W'){
				int ans = 1 ;
				for(int k = 0 ; k < 8 ; k++) ans += ff(i + rd[k], j + cd[k]) ;
				return ans ;
			} else return 0 ;

		}

	}

}

void solve(){

	char str[105] ;

	n = 0 ;

		while(gets(str) && (str[0] == 'W' || str[0] == 'L')){
			sscanf(str, "%s", s[n]) ; n++ ;
		}

		m = strlen(s[0]) ;

		do{
		    for(int i = 0 ; i < n + 5 ; i++) for(int j = 0 ; j < m + 5 ; j++) visited[i][j] = 0 ;
			int a, b ;
			sscanf(str, "%d %d", &a, &b) ;
			//cout << a << " " << b << " " ;
			int ans = ff(a - 1, b - 1) ;
			cout << ans << endl ;
		} while(gets(str) && str[0] != '\0') ;

}

int main(){

	int rd1[] = { 0, -1, -1, -1, 0, 1, 1, 1 } ;
	int cd1[] = { -1, -1, 0, 1, 1, 1, 0, -1 } ;
	for(int i = 0 ; i < 8 ; i++){ rd[i] = rd1[i] ; cd[i] = cd1[i] ;}

	int t ; cin >> t ; char temp[105] ; gets(temp) ; gets(temp) ;
	while(t--){ solve() ; if(t) cout << endl ; }

	return 0 ;
} 