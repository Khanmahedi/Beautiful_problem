#include<bits/stdc++.h>
using namespace std;
#define ll      long long
#define pb      push_back
#define TT ll time;        cin >> time; while(time--)
#define FastIo  ios_base::sync_with_stdio(false);cin.tie(NULL) ;
const ll mod =   1e9+7  , N = 1e6+10 , INF = 5e18, block = 400 ;
#ifndef ONLINE_JUDGE
#include "algodebug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

pair < ll , ll > tree[4*N] ;
ll ar[N] ;
pair < ll , ll > Build(ll node , ll b , ll e){
  if(b == e) {
    return tree[node] = {ar[b] , b};
  }
  ll mid = (b + e) / 2 ;
  Build(node*2 , b , mid) ;
  Build(node*2+1, mid+1, e) ;
  return tree[node] = max(tree[node*2] , tree[node*2+1]) ;
}

void Update(ll node , ll b, ll e, ll point , ll val){
  if(b == e and b == point){
     tree[node] = {val, b} ;
     ar[b] = val ;
     return ;
  }
  if(b > point or e < point) return;
  ll mid = ( b + e) / 2 ;
  Update(node*2, b, mid , point, val) ;
  Update(node*2+1, mid + 1, e , point , val) ;
  tree[node] =  max(tree[node*2] , tree[node*2 +1]) ;
}

pair < ll , ll > query(ll node , ll b, ll e, ll l , ll r){
  if(b > r or e  < l) return {-2, -2} ;
  if(l <= b and r >= e) return tree[node] ;
  ll mid  = (b + e) /2 ; 
  auto one = query(node*2 , b , mid , l  , r) ;
  auto two = query(node*2+1, mid+1, e , l , r) ;
  return max(one, two) ; 
}

set < pair < ll , ll > > s ;

int main(){
  FastIo ;
  ll n , k ;
  cin >> n >> k ;
  string ans ;
  ans.assign(n+1 , '#') ;
  ll L[n+10] = {} , R[n+10] = {} ;
  for( ll i = 1 ; i <= n; i++) cin >> ar[i] , s.insert({ar[i] , i}) ;
  for( ll i = 1 ; i <= n ; i++){
    L[i] = i - 1 ;
    R[i] = i + 1 ;
  }
  Build(1 , 1 , n) ;
  pair < ll , ll > mx = query(1 , 1, n , 1 , n) ;
  ll cnt = 1  ;
  while(mx.first != -1){
    ll mxind = mx.second , c = 0,Ri = mxind , Le = mxind ;
    debug(mxind , mx.first);
    Update(1, 1, n , mxind , -1) ;
    if(cnt) ans[mxind] = '1' ;
    else ans[mxind] = '2' ;
    for( ll i = R[mxind] ; i <= n ; i = R[i]) {
      debug("R" ,i) ;
      if(ar[i] == -1) break ;
      if(cnt) ans[i] = '1' , c++;
      else ans[i] = '2' , c++;
      Update(1, 1 , n , i , -1) ;
      Ri = i ;
      if(c == (k)) break ;
    }
    c = 0 ;
    for( ll i = L[mxind] ; i >= 1 ; i = L[i]){
      debug("L" , i , cnt) ;
      if(ar[i] == -1) break ;
      if(cnt) ans[i] = '1' , c++;
      else ans[i] = '2' , c++;
      if(i != mxind)
      Update(1, 1, n , i , - 1) ;
      Le = i ;
      if(c == k) break ;
    }
    cnt^=1 ;
    mx = query(1, 1, n , 1, n) ;
    debug(Le, Ri) ;
    L[R[Ri]] = L[Le] , R[L[Le]] = R[Ri] ;
    // cout << "arr" << endl ;
    // for( ll i = 0 ; i <= n +1 ; i++) cout << L[i]  << " " ;
    //   cout << endl ;
    // for( ll i = 0 ; i <= n+1 ; i++) cout << R[i] << " " ;
    //   cout << endl ;
  }

  ans.erase(ans.begin()) ;
  cout << ans << endl ;
  
  
}
