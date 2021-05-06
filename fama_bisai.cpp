//
// Created by niuyb on 2021/4/19.
//
//
// Created by niuyb on 2021/4/19.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//int main(){
//    int n;
//    cin>>n;
//    vector<int> nums(n);
//    set<int> st;
//    for(int i=0;i<n;i++){
//        cin>>nums[i];
//    }
//
//    time_t begin,end;
//    double ret;
//    begin = clock();
//    ll sum = 1<<n;
//    for(ll i=0;i<sum;i++){
//        for(ll j=0;j<sum;j++){
//            if(i!=j){
//                ll cur = 0;
//                for(int k=0;k<n;k++){
//                    if((i>>k)&1){
//                        cur+=nums[k];
//                    }
//                }
//                ll cur_sec = 0;
//                for(int m=0;m<n;m++){
//                    if((j>>m)&1){
//                        cur_sec+=nums[m];
//                    }
//                }
//                if(abs(cur-cur_sec)!=0){
//                    st.insert(abs(cur-cur_sec));
//                }
//            }
//        }
//    }
//
//    end=clock();
//    ret=double(end-begin)/CLOCKS_PER_SEC;
//    cout<<"runtime:   "<<ret<<endl;
//    printf("%d\n",st.size());
//    return 0;
//}

int main(){
    time_t begin,end;
    double ret;
    vector<int> nums(1000);
    for(int i=0;i<nums.size();i++){
        if(i%2==1){
            nums[i]=5*i-1;
        }
        else{
            nums[i]=6*i-5;
        }
    }
    begin = clock();
    for(int i=1;i<=1000;i++){

        sort(nums.begin(),nums.end());
    }
    end = clock();
    ret=double(end-begin)/CLOCKS_PER_SEC;
    cout<<"run:"<<ret<<endl;
    return 0;

}

