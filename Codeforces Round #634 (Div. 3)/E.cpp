
#include <iostream>
#include <cstdlib>
#include <queue>
#include <cstdio>
#include <cstring>
#include <stack>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std ;
typedef long long ll ;
const int maxn = 200000  + 10 ;
const int maxc = 200 + 3 ;
int test_case ;

int n ;
int a[maxn] ;

int main() {
    scanf("%d",&test_case) ;

    while (test_case--) {
        int res = 0 ;
        vector<vector<int>> pos(201) ;
        scanf("%d",&n) ;
        vector<vector<int>> dp(n + 1 , vector<int> (201 , 0)) ;
        for (int i = 1 ; i <= n ; ++i) {
            scanf("%d",&a[i]) ;
            pos[a[i]].push_back(i) ;
            for (int j = 1 ; j <= 200 ; ++j) {
                dp[i][j] = dp[i - 1][j] ;
            }
            dp[i][a[i]]++ ;
            res = max(res , dp[i][a[i]]) ;
        }

        for (int c = 1 ; c <= 200 ; ++c) {
            for (int i = 1 ; i * 2 <= pos[c].size() ; ++i) {
                int l = pos[c][i - 1] , r = pos[c][pos[c].size() - i] ;
                int t = 0 ;
                for (int j = 1 ; j <= 200 ; ++j) {
                    t = max(t , dp[r - 1][j] - dp[l][j]) ;
                }
                res = max(res , i * 2 + t) ;
            }
        }
        printf("%d\n",res) ;
    }
    
    return 0 ;

}

