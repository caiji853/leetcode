#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumScore(int a, int b, int c) {

        vector<int>ans;
        ans.push_back(a);
        ans.push_back(b);
        ans.push_back(c);
        int cur = 0,res=0;
        sort(ans.begin(),ans.end());
        printf("%d %d %d",ans[0],ans[1],ans[2]);
        while(true){
            if(ans[0]==0) cur++;
            if(ans[1]==0) cur++;
            if(ans[2]==0) cur++;
            if(cur >=2 ) break;
            if(ans[0]) {
                ans[0]--;
                ans[2]--;
            }
            else if(ans[1]!=0){
                ans[1]--;
                ans[2]--;
            }
            res++;


        }
        return res;


    }
};
int main() {
    Solution *s= new Solution();
    vector<vector<int>>ss={{1,2,4},{3,4,3},{2,3,10}};
    string s1="cabaa";
    string s2="bcaaa";
    s->maximumScore(2,4,6);
}
