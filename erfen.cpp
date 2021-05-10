//
// Created by niuyb on 2021/4/26.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=110,inf=0x3f3f3f3f;
ll n,a[N],ans=0;
bool use[N];
unordered_map<ll,bool>vis;
void dfs(ll x)
{
    for(ll i=1;i<=n;i++)
    {
        if(!use[i])
        {
            use[i]=1;
            // 加
            ll y1=x+a[i];
            if(!vis[y1])
            {
                ans++;
                vis[y1]=1;
                dfs(y1);
                y1-=a[i]; // 还原
            }
            // 减
            ll y2=x-a[i];
            if(y2>0&&!vis[y2])
            {
                ans++;
                vis[y2]=1;
                dfs(y2);
                y2+=a[i]; // 还原
            }
            use[i]=0; // 还原
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,greater<ll>());
    time_t begin,end;
    double ret;
    begin = clock();
    dfs(0);
    end=clock();
    ret=double(end-begin)/CLOCKS_PER_SEC;

    printf("%lld\n",ans);
    cout<<"runtime:   "<<ret<<endl;
    return 0;
}


