#include<bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
#define ll       long long
#define pb      push_back
#define TT ll time;        cin >> time; while(time--)
#define FastIo  ios_base::sync_with_stdio(false);cin.tie(NULL) ;
const ll int INF = 9223372036854775807 , nmax = 2501 , block = 350 , N = 3e6+20 , mod = 998244353;
#ifndef ONLINE_JUDGE
#include "algodebug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

vector < ll > ad[N] ;
ll a[N] , dp[N] ;
void dfs(ll node, ll par){
  for(auto it: ad[node]){
    if(par != it){
      dfs(it, node) ;
    }
  }
  if(par != -1)
  dp[par] = dp[par] + max(dp[node], 0ll) ;
}

void dfs1(ll node, ll par){
    ll val ;
    if(par != -1) val = dp[par] - max(dp[node], 0ll) ;
    if(node != 1){
      dp[node] = max(dp[node],dp[node] + val) ;
    }
  for(auto it: ad[node]){
    if(par != it)
     dfs1(it, node) ;

  }


}



int main(){
  FastIo ;
  
  ll n , m ;
  cin >> n ;
  for( ll i = 1 ; i <= n  ;  i++){
    ll x ;
    cin >> x ;
    dp[i] = (x == 0)?-1:1 ;
  }
  for( ll i = 0 ; i < n -1 ; i++){
    ll x , y ;
    cin >> x >> y ;
    ad[x].pb(y) ;
    ad[y].pb(x) ;
  }

  dfs(1, -1) ;
  dfs1(1, -1) ;

  for( ll i = 1 ; i <= n ; i++) cout << dp[i] << " " ;
    cout << endl ;

 

  }




 
 
