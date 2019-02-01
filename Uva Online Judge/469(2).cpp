// Uva 469 with DP
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=410

#include<bits/stdc++.h>

using namespace std ;
typedef long long ll ;

string s, m[105] ;
int dr[10], dc[10], rows, cols, color[105][105], val[105][105] ;
vector < pair<int, int> > vec ;

int ff(int i, int j){
	
	if(i < 0 || j < 0 || i >= rows || j >= cols) return 0 ;
	else if(m[i][j] == 'L') return 0 ;
	else if(color[i][j] == 1) return 0 ;
	
	vec.push_back(make_pair(i, j)) ;

	color[i][j] = 1 ;
	int ans = 1 ;
	for(int k = 0 ; k < 8 ; k++) ans += ff(i + dr[k], j + dc[k]) ;

	return ans ;

}

void solve(){
    
    vec.clear() ;
    
    rows = 0 ;
    int i, j ;
	while(getline(cin, s)){
	    if(s == "") break ;
	    else if(s[0] == 'L' || s[0] == 'W'){
	        m[rows] = s ;
		    rows++ ;
		    cols = m[0].length() ;
		    for(int j = 0 ; j <= cols ; j++){ color[rows-1][j] = 0 ; val[rows-1][j] = 0 ; }
	    } else{
    		sscanf(s.c_str(), "%d%d", &i, &j) ;
    		if(val[i-1][j-1] == 0) val[i-1][j-1] = ff(i-1, j-1) ;
    		for(int k = 0 ; k < vec.size() ; k++) val[vec[k].first][vec[k].second] = val[i-1][j-1] ;
    		vec.clear() ;
    		cout << val[i-1][j-1] << '\n' ;
	    }
	}

}

int main(){
        
    int next1 = 0, next2 = 0 ;
	for(int i = -1 ; i <= 1 ; i++)
		for(int j = -1 ; j <= 1 ; j++){
			if(i == 0 && j == 0) continue ;
			dr[next1] = i ; next1++ ;
			dc[next2] = j ; next2++ ;
		}
	
	int t ; cin >> t ; scanf("%*c") ; getline(cin, s) ;
	while(t--){
		solve() ;
		if(t != 0) cout << '\n' ;
	}

	return 0 ;

}