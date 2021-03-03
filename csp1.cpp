//
// Created by niuyb on 2021/2/8.
//
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    set<int> st;
    vector<pair<int,int>> vtr;
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        vtr.push_back(make_pair(a,b));
        st.insert(a);
    }
    for(auto s=st.begin();s!=st.end();s++){
        int cnt=0;
        for(int i=0;i<vtr.size();i++){
            int cur = 0;
            if(vtr[i].first >= *s){
                cur=1;
            }
            if(cur==vtr[i].second){
                cnt++;
            }
        }
        mp[*s]=cnt;
    }
    vector<int>ans;
    int mx=0;
    for(auto &m:mp){
        mx=max(mx,m.second);
    }
    for(auto &m:mp){
        if(m.second==mx){
            ans.push_back(m.first);
        }
    }
    sort(ans.begin(),ans.end());
    printf("%d",ans[ans.size()-1]);
    printf("niuyb");
    return 0;

}
