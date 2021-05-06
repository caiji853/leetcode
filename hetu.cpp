#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
const int inf=0x3f3f3f3f;
const int maxn=1e3+5;
const int N=3e5+5;
const LL mod=998244353;
const double pi=acos(-1);
vector<int>mid;
int n,res,a[maxn],sum,f[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]),sum+=a[i];
    for(int i=1;i<=n;i++)
    {
        mid.clear();
        mid.push_back(sum+a[i]); mid.push_back(sum-a[i]);
        for(int j=0;j<=2*sum;j++)
            if(f[j])
            {
                if(j-a[i]>=0) mid.push_back(j-a[i]);
                mid.push_back(j+a[i]);
            }
        for(int j=0;j<mid.size();j++) f[mid[j]]=1;
    }
    for(int i=sum+1;i<=2*sum;i++) if(f[i]) res++;
    printf("%d\n",res);
    return 0;
}

