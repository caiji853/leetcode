//
// Created by niuyb on 2021/4/27.
//
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ll time;

    ll ss,mm,hh;
    int mod = 24*60*60;
    cin>>time;
    ll n =time;
    time /= 1000;
    ll m_sec = time % mod;
    ll second = m_sec % 60;
    ll minu = m_sec / 60;
    ll t2 = minu % 60;
    ll hour = minu / 60;
    printf("%02ld:%02ld:%02ld\n",hour,t2,second);


    n /= 1000;
    ss = n % 60;
    n /= 60;
    mm = n % 60;
    n /= 60;
    hh = n % 24;
    printf("%02lld:%02lld:%02lld\n", hh, mm, ss);
    return 0;

}

