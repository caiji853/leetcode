//
// Created by niuyb on 2021/2/8.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string s = word1+word2;
        if(s.size() <= 1)
            return s.size();

        std::vector<std::vector<int> > dp(s.size(), std::vector<int>(s.size(), 0));
        for(int i = 0; i < s.size(); ++i)
            dp[i][i] = 1;

        /*
         * 递归的动态规划是从最大范围递归到单个字符然后逐层返回
         * 非递归就是实现逐层返回的方法，从单个字符扩展到最大范围
         */
        for(int i = s.size() - 1; i >= 0; --i)
        {
            for(int j = i + 1; j < s.size(); ++j)
            {
                if(i<word1.size()&&j>=word1.size()){
                    if(s[i] == s[j])
                    {
                        dp[i][j] = 2;
                        if(i + 1 <= j - 1)
                            dp[i][j] += dp[i + 1][j - 1];
                    }
                    else
                    {
                        dp[i][j] = std::max(dp[i][j - 1], dp[i + 1][j]);
                    }
                }

            }
        }

        return dp[0][s.size() - 1]==1?0:dp[0][s.size() - 1];
    }
};
int main(){
    Solution *s = new Solution();
    vector<int> nums={4,3,2,7,8,2,3,1};
    string ss="1111";
    string s1="ceebeddc";
    string s2="d";
    s->longestPalindrome(s1,s2);

    return 0;
}
