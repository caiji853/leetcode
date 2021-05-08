//
// Created by niuyb on 2021/5/7.
//
#include <bits/stdc++.h>
using namespace std;
map<int,vector<pair<int,int>> >mp;
bool is_prime(int num){
    for(int i=2;i<=num/2;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

static bool cmp(pair<int,int> &a, pair<int,int> &b){
    if(a.first!=b.first){
        return a.first >= b.first;
    }
    return a.second >= b.second;
}
vector<pair<int,int> > prime_nums(int num){
    vector<pair<int,int> > ans;
    for(int i=2;i<=num/2;i++){
        if(is_prime(i)&& is_prime(num-i)){
            ans.push_back(make_pair(i,num-i));
        }
    }
}

void bfs(vector<pair<int,int>> &ans_vec){

}
int main(){
    int m,n;
    cin>>m>>n;
    for(int i=m;i<=n;i++){
        if(i%2==0){
            vector<pair<int,int> > tmp = prime_nums(i);
            mp.insert({i,tmp});
        }
    }
}

