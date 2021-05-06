//
// Created by niuyb on 2021/4/16.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mem[30][30][31];
    string s1_,s2_;
    void set_string(string &s1, string &s2){
        s1_ = s1;
        s2_ = s2;
    }
    bool is_equal(int first, int second, int len){
        map<int,int> mp;
        for(int i=first;i<first+len;i++){
            mp[s1_[i]-'a']++;
        }
        for(int i=second;i<second+len;i++){
            mp[s2_[i]-'a']--;
        }
        for(auto &m:mp){
            if(m.second != 0){
                return false;
            }
        }
        return true;
    }
    bool bfs(int first, int second, int len){
        if(mem[first][second][len]){
            return mem[first][second][len] == 1;
        }
        if(!is_equal(first,second,len)){
            mem[first][second][len] = -1;
            return false;
        }
        for(int i=1;i<len;i++){
            if(bfs(first,second,i)&&bfs(first+i,second+i,len-i)){
                mem[first][second][len] = 1;
                return true;
            }
            if(bfs(first,second+len-i,i)&&bfs(first+i,second,len-i)){
                mem[first][second][len] = 1;
                return true;

            }
        }
        mem[first][second][len] = -1;
        return false;
    }
    bool isScramble(string s1, string s2) {
        memset(mem,0,sizeof(mem));
        set_string(s1,s2);
        return bfs(0,0,s1.size());


    }
};
int  main(){
    string s1 = "great";
    string s2 = "rgeat";
    Solution s = Solution();
    s.isScramble(s1,s2);
    long long tt = 4869;
    printf("%ld",tt%60);
}
