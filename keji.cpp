//
// Created by niuyb on 2021/2/8.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int f[N], pre[N];
int n, m, w, h;
struct Poi{
    int w, h, num;
    bool operator < (const Poi &A) const {
        if(w == A.w) return h < A.h;
        return w < A.w;
    }
}p[N]; int g;

int main()
{
    int n;
    cin >>n;
    for(int i = 1; i <= n; i++) {
        int a, b;

        scanf("%d%d",&p[i].w,&p[i].h);
        p[i].num=i;
    }
    sort(p + 1, p + 1 + n);

    int Ma = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j < i; j++)
            if(p[i].w > p[j].w && p[i].h < p[j].h && f[j] + 1 > f[i]) {
                pre[i] = j;
                f[i] = f[j] + 1;
                if(f[i] > f[Ma]) Ma = i;
            }

    vector<int> ans;
    for(int i = Ma; i; i = pre[i]) ans.push_back(p[i].num);
    reverse(ans.begin(), ans.end());
    int len = ans.size();
    printf("%d\n", len);
    for(int i = 0; i < len; i++) {
        printf("%d %d\n",p[ans[i]].w,p[ans[i]].h);
    }

    return 0;
}

/*
5 10 10
22 23
17 19
13 17
8 12
2 6
*/
