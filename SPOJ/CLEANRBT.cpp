// SPOJ CLEANRBT

#include<bits/stdc++.h>

using namespace std ;
using ll = long long ;
using pii = pair <int, int> ;
const int INF = 5000 ;

int n, m, dt_cnt ;
string s[25] ;
bool visited[25][25][(1 << 10)] ;
vector <pii> vec ;

struct state{

    int x, y ; // position
    int dist ; // dist in bfs(not included in visited dp as only the other 2 values matter)
    int mask ; // what dirty tiles have been cleaned

    // is state valid or not
    bool in_bound(){

        if(x >= 0 && x < n && y >= 0 && y < m)
            return 1 ;

        return 0 ;

    }

    bool not_obstacle(){

        if(s[x][y] != 'x')
            return 1 ;

        return 0 ;

    }

    bool not_visited(){

        if(visited[x][y][mask] == 0)
            return 1 ;

        return 0 ;

    }

    void update_mask(){

        // update mask based on x, y

        if(s[x][y] == '*')
            for(int i = 0 ; i < vec.size() ; ++i)
                if(vec[i].first == x && vec[i].second == y){
                    mask = mask | (1 << i) ;
                    break ;
                }

    }

    void update_visited(){

        visited[x][y][mask] = 1 ;

    }


} ;

int bfs(int stx, int sty){

    state start = {
        stx, sty,
        0,
        0
    } ;

    visited[stx][sty][0] = 1 ;

    queue <state> q ; while(!q.empty()) q.pop() ;
    q.push(start) ;

    int dirx[] = {-1, 0, 1, 0} ;
    int diry[] = {0, -1, 0, 1} ;

    int ans = INF ;
    while(!q.empty()){

        state top = q.front() ;
        q.pop() ;

        //cout << top.x << " " << top.y << " " << top.mask << "\n" ;

        int dt = (1 << vec.size()) - 1 ;
        if(top.mask == dt){
            ans = min(ans, top.dist) ;
            continue ;
        }

        // find neighbours
        state neighbour[] = {
            top, top, top, top, top // 5'th added if mask is updated
        } ;

        for(int i = 0 ; i < 4 ; ++i){

            neighbour[i].x += dirx[i] ;
            neighbour[i].y += diry[i] ;
            ++neighbour[i].dist ;

        }

        neighbour[4].update_mask() ;
        if(neighbour[4].not_visited()){
            neighbour[4].update_visited() ;
            q.push(neighbour[4]) ;
            continue ;
        }

        // put neighbours in queue if valid
        for(int i = 0 ; i < 4 ; ++i){

            if(neighbour[i].in_bound() && neighbour[i].not_obstacle()){
                if(neighbour[i].not_visited()){
                    neighbour[i].update_visited() ;
                    q.push(neighbour[i]) ;
                }
            }

        }

    }

    return ans ;

}

void solve(){

    for(int i = 0 ; i < n ; ++i)
        cin >> s[i] ;

    int stx, sty ;
    vec.clear() ;

    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j){

            for(int k = 0 ; k < (1 << 10) ; ++k)
                visited[i][j][k] = 0 ;

            if(s[i][j] == 'o'){
                stx = i ;
                sty = j ;
            } else if(s[i][j] == '*'){
                vec.push_back({i, j}) ;
            }

        }

    int ans = bfs(stx, sty) ;

    if(ans >= INF){
        cout << "-1\n" ;
    } else{
        cout << ans << "\n" ;
    }

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    #endif

    ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;

    cin >> m >> n ;
    while(n > 0 && m > 0){
        solve() ;
        cin >> m >> n ;
    }

    return 0 ;
}
