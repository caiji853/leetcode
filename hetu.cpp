//
// Created by niuyb on 2021/3/15.
//
#include <bits/stdc++.h>
using namespace std;
struct Goods{
    int number;
    int date;
    
};
int main(){
    vector<int> nums={13,16,52,16,20,21,22,25,35,25,25,30,33,33,19,35,22,35,35,15,35,36,40,45,25,46,70};
    sort(nums.begin(),nums.end());
    for(auto &num:nums){
        printf("%d ",num);
    }
    return 0;
}

