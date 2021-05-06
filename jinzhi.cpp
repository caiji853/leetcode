//
// Created by niuyb on 2021/4/13.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1e9+7;
/**快速幂
 *
 * @param a
 * @param b
 * @return
 */
ll ksc(ll a, ll b) {
    ll ans = 1;
    while(b != 0) {
        if(b & 1 != 0) {
            (ans *= a) %= mod;
        }
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}
/**十进制转二进制
 *
 * @param num
 * @return
 */
string ten_to_two(ll &num){
    string ans;
    while(num > 0){
        ans.push_back(num % 2+'0');
        num /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

/**二进制转十进制
 *
 * @param strs
 * @return
 */
ll two_to_ten(string &strs){
    ll num = 0;
    reverse(strs.begin(),strs.end());
    for(int index = 0; index < strs.size(); ++index){
        num += (strs[index]-'0') * ksc(2, index);
        num %= mod;
    }
    return num;
}


int main(){
    //测试二进制转十进制
    string strs = "1101010101111101100010101010100000111110000";
    printf("%ld\n", two_to_ten(strs));
    //测试十进制转二进制
    ll num = 123434;
    printf("%s\n", ten_to_two(num).c_str());


}

