#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod=1e9+7;
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<int, vector<int>, less<int> > buy;
        priority_queue<int, vector<int>, greater<int> > sell;
        map<int,int> buy_mp;
        map<int,int> sell_mp;
        for(auto & o:orders){
            if(o[2]==0){
                for(int i=0;i<o[1];i++){
                    if(sell_mp.size()==0){
                        buy_mp[o[0]]++;
                        continue;
                    }
                    if(o[0]>=sell_mp.rbegin()->first){

                        sell_mp.rbegin()->second--;
                        int key = sell_mp.rbegin()->first;
                        if(sell_mp.rbegin()->second == 0){
                            auto finder = sell_mp.find(key);
                            if(finder!=sell_mp.end()){
                                sell_mp.erase(finder);
                            }
                        }

                    }
                    else{
                        buy_mp[o[0]]++;
                    }
                }
            }
            else if(o[2]==1){
                for(int i=0;i<o[1];i++){
                    if(buy_mp.size()==0){
                        sell_mp[o[0]]++;
                        continue;
                    }
                    if(o[0]<=buy_mp.rbegin()->first){

                        buy_mp.rbegin()->second--;
                        int key = buy_mp.rbegin()->first;
                        if(buy_mp.rbegin()->second == 0){
                            auto finder = buy_mp.find(key);
                            if(finder!=buy_mp.end()){
                                buy_mp.erase(finder);
                            }
                        }

                    }
                    else{
                        sell_mp[o[0]]++;
                    }
                }
            }
        }
        return (buy.size()+sell.size())%mod;

    }
};
int main() {
    Solution *s= new Solution();
    vector<vector<int>>ss={{10,5,0},{15,2,1},{25,1,1},{30,4,0}};
    s->getNumberOfBacklogOrders(ss);
    string s1="cabaa";
    string s2="bcaaa";
    //s->maximumScore(2,4,6);
}
