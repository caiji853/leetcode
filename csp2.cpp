//
// Created by niuyb on 2021/3/16.
//
#include <bits//stdc++.h>
using namespace std;
int d_value[10005];
int get_total_sum(vector<int> &nums){
    int ans=0;
    int index=nums.size()-1;
    while(index>=0&&nums[index]<=0){
        ans+=nums[index];
        index--;
    }
    if(index>=0){
        ans+=nums[index];
    }
    return ans;
}
bool get_d_value(vector<int>& nums){
    int i=0;
    while(i<nums.size()) {
        int j = i+1;
        int cur_sum = nums[j-1];
        while (j < nums.size() && nums[j] <= 0) {
            cur_sum += nums[j];
            j++;
        }
        if (j < nums.size() && nums[j] > 0) {
            if (cur_sum > nums[j]) {
                return true;
            }
        }
        i = j;
    }
    return false;

}

int  get_e_value(int n){
     int ans=0;
     for(int i=0;i<n;i++){
         if(d_value[i%n]==1&&d_value[(i+1)%n]==1&&d_value[(i+2)%n]==1){
             ans++;
         }
     }
     return ans;
}
int main(){
    int n;
    int ans=0,d_num=0,e_num=0;
    cin>>n;
    memset(d_value,0, sizeof(d_value));
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        vector<int> nums;
        for(int j=0;j<m;j++){
            int num;
            cin>>num;
            nums.push_back(num);
        }
        ans+=get_total_sum(nums);
        if(get_d_value(nums)){
            d_value[i]=1;
            d_num++;
        }
    }
    printf("%d %d %d",ans,d_num,get_e_value(n));
}

