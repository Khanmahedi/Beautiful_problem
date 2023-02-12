#include<bits/stdc++.h>
using namespace std;
#define ll      long long int
#define pb      push_back
#define TT ll time;        cin >> time; while(time--)
#define FastIo  ios_base::sync_with_stdio(false);cin.tie(NULL) ;
const ll mod =   1e9+7  , N = 1e6+10 , INF = 5e18, block = 400 ;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair < ll , ll > , null_type, less<pair <ll , ll > >, rb_tree_tag,
             tree_order_statistics_node_update>
  ordered_set;
  //order_of_key(k) Number of items striclty smaller than k
  //find_by_order(k) K-th element in a set (counting from index zero)
  //order_of_key(k) Number of items striclty smaller than k
  //find_by_order(k) K-th element in a set (counting from index zero)
#ifndef ONLINE_JUDGE
#include "algodebug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

ll ar[2010][2010] , d1[N], d2[N] , final[2010];

int main(){
  FastIo ;
  
  ll n ;
  cin >> n ;
  for( ll i = 0 ; i < n ; i++){
    for( ll j = 0 ; j < n ; j++){ 
      cin >> ar[i][j] ;
      d1[i+j]+=ar[i][j] ;
      d2[i - j + n ]+=ar[i][j] ;
    }
  }
  


 ll tot = 0 , temp = -1 , x1 , y1 , x2, y2 , tot1 = 0 , temp1 = -1  ;

 for( ll i = 0 ; i < n ; i++){
  for( ll j = 0 ; j < n ; j++){
      if((i + j)&1){
        tot = d1[i+j] + d2[i - j + n] - ar[i][j] ;
        if(tot > temp){
          temp = tot ;
          x1 = i+1 ;
          y1 = j+1 ;
        }
      }
      if((i+j)&1^1){
        tot1 = d1[i+j] + d2[i - j + n] - ar[i][j] ;
        if(tot1 > temp1){
            temp1 = tot1 ;
            x2 = i+1 ;
            y2 = j+1 ;
        }
      }
    }
 }

   cout << (temp1 + temp) << endl ;
   cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl ;
}
