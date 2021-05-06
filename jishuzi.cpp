//
// Created by niuyb on 2021/3/27.
//
//
// Created by niuyb on 2021/3/24.
//
#include <bits/stdc++.h>
using namespace std;
int nums[1000007];
int main(){
    int n,k;
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int left =0;
    int cur = 0,ans=0;
    for(int right =0;right<n;right++){

        while(left<=right&&right-left<k){
            ans=max(ans,cur);
            cur^=nums[left];
            left++;
        }
        cur^=nums[right];
    }
    printf("%d\n",ans);

}
