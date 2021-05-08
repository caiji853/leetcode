//
// Created by niuyb on 2021/5/8.
//
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a = {-90,-32,12,16,24,36,45,59,98,120};

    int target;
    while(cin>>target) {
        bool flag = false;
        int cnt = 1;
        int l = 0,r = a.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (a[m] == target) {
                printf("%d %d\n", m + 1, cnt);
                flag = true;
                break;

            } else if (a[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
            cnt++;
            printf("%d %d %d\n",l,r,cnt);
        }
        if (flag == false) {
            printf("查找失败:%d\n", cnt-1);
        }
    }
}

