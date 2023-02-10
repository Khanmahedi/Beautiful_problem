#include<bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
#define ll      long long
#define pb      push_back
#define TT ll time;        cin >> time; while(time--)
#define FastIo  ios_base::sync_with_stdio(false);cin.tie(NULL) ;
const ll int INF = 5e18 , nmax = 2501 , block = 350 , N = 1e6+10 , mod = 998244353;
#ifndef ONLINE_JUDGE
#include "algodebug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
vector < ll > g[N] ;
string s ;
ll par[3000][3000] , dp[3000][3000] ;
void dfs(ll u , ll p , ll v){
  par[v][u] = p ;
  for(auto it: g[u]){
    if(it == p) continue ;
    dfs(it , u , v) ;
  }
}


ll go(ll u , ll v){
  if(u == v) return 1 ;
  if(par[u][v] == u or par[v][u] == v){
    if(s[u] == s[v]) return 2 ;
    else return 1 ;
  }
  if(dp[u][v] != -1) return dp[u][v] ;
  ll ret = 0 ;
  if(s[u] == s[v]) ret  = 2 + go(par[v][u] , par[u][v]) ;
  else ret = max({ret , go(par[v][u] , v) , go(u , par[u][v])}) ;
  return dp[u][v] = ret ;

}

int main(){
  FastIo ;
  TT{
  ll n ;
  cin >> n ;
  cin >> s  ;
  s = '#' + s ;
  for(ll i = 1 ; i <= n ; i++) g[i].clear() ;
  for(ll i = 1 ; i < n ; i++){
    ll x, y ;
    cin >> x >> y ;
    g[x].pb(y) ;
    g[y].pb(x) ;
  }
  for(ll u = 1 ; u <= n ; u++)
          dfs(u , -1, u) ;

  for(ll i = 1 ; i <= n ; i++)
    for(ll j = 1 ; j <= n ; j++)
      dp[i][j] = - 1 ;
    
  

  ll ans = 0 ;
  for(ll i = 1 ; i <= n ; i++)
    for(ll j = 1 ; j <= n ; j++)
      ans = max(ans, go(i , j)) ;
    

   cout << ans << endl ;
}
  
} 
