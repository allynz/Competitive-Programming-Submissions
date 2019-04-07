// SPOJ CERC07K

#include<bits/stdc++.h>

using namespace std ;
using ll = long long ;
const int INF = 100005 ;

int n, m ;
string s[105] ;
bool visited[105][105][(1 << 5)] ;

struct State{

    int x, y ;
    int key_mask ;
    int dist ;

    bool in_bounds(){
        if(x >= 0 && x < n && y >= 0 && y < m)
            return 1 ;
        else
            return 0 ;
    }

    bool not_a_wall(){
        if(s[x][y] != '#')
            return 1 ;
        else
            return 0 ;
    }

    bool got_keys(){

        char arr[] = {'B', 'G', 'R', 'Y'} ;

        for(int i = 0 ; i < 4 ; ++i){
            if(arr[i] == s[x][y]){
                if( key_mask & (1 << i) ){
                    continue ;
                } else{
                    return 0 ;
                }
            }
        }

        return 1 ;

    }

    bool is_visited(){
        if(visited[x][y][key_mask] == 1)
            return 1 ;
        else
            return 0 ;
    }

    void update_keys(){

        char arr[] = {'b', 'g', 'r', 'y'} ;

        for(int i = 0 ; i < 4 ; ++i){
            if(arr[i] == s[x][y]){
                key_mask = key_mask | (1 << i) ;
            }
        }

    }

    void update_visited(){
        visited[x][y][key_mask] = 1 ;
    }

} ;

int bfs(int st_x, int st_y){

    queue < State > q ;
    while(!q.empty())
        q.pop() ;

    State ss = {
        st_x, st_y,
        0,
        0
    } ;

    visited[st_x][st_y][0] = 1 ;
    q.push(ss) ;

    int dirx[] = { -1, 0, 1, 0 } ;
    int diry[] = { 0, -1, 0, 1 } ;

    int ans = INF ;

    while(!q.empty()){

        State top = q.front() ;
        q.pop() ;

        if(s[top.x][top.y] == 'X'){
            ans = min(ans, top.dist) ;
            continue ;
        }

        State neighbours[] = {
            top, top, top, top
        } ;

        for(int i = 0 ; i < 4 ; ++i){
            neighbours[i].x += dirx[i] ;
            neighbours[i].y += diry[i] ;
            ++neighbours[i].dist ;
        }

        for(int i = 0 ; i < 4 ; ++i){

            if(neighbours[i].in_bounds() && neighbours[i].not_a_wall()){

                neighbours[i].update_keys() ;

                if(neighbours[i].got_keys() && !neighbours[i].is_visited()){
                    neighbours[i].update_visited() ;
                    q.push(neighbours[i]) ;
                }

            }

        }

    }

    return ans ;

}

void solve(){

    for(int i = 0 ; i < n ; ++i)
        cin >> s[i] ;

    // clear visited array
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j)
            for(int k = 0 ; k < (1 << 4) ; ++k)
                visited[i][j][k] = 0 ;

    int st_x = -1, st_y = -1 ;
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j)
            if(s[i][j] == '*'){
                st_x = i ;
                st_y = j ;
            }

    if(st_x < 0 || st_y < 0){
        cout << "The poor student is trapped!\n" ;
    }

    int ans = bfs(st_x, st_y) ;

    if(ans >= INF){
        cout << "The poor student is trapped!\n" ;
    } else{
        cout << "Escape possible in " << ans << " steps." << "\n" ;
    }

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    #endif

    ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;

    cin >> n >> m ;
    while(n > 0 && m > 0){
        solve() ;
        cin >> n >> m ;
    }

    return 0 ;
}
