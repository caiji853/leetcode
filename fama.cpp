#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <ctime>
using namespace std;

const int maxn = 1e4 + 50;

int n, w[maxn], m, q;
int dp[101][10150];

int main() {
        int n;
        cin>>n;
        memset(dp, 0, sizeof(dp));


        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for(int i=1;i<=n;i++){
            scanf("%d", &w[i]);
        }


        time_t begin,end;
        begin = clock();
        double ret;
        for (int i = 1; i <= n; i++) {

            for (int j = 0; j <= 1e4; j++) {
                dp[i][j] |= dp[i-1][j];
                dp[i][j + w[i]] |= dp[i-1][j];
                dp[i][abs(j - w[i])] |= dp[i-1][j];
            }
        }

        int ans = 0;
        for(int i=1;i<=1e4;i++){
            if(dp[n][i]){
                ans++;
            }
        }

        end=clock();
        ret=double(end-begin)/CLOCKS_PER_SEC;
        cout<<"runtime:   "<<ret<<endl;
        printf("%d",ans);

       return 0;
}

