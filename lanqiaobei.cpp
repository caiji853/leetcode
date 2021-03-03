//
// Created by niuyb on 2021/2/8.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solve(int n){
    int ans=0;
    while(n){
        ans+=n%10;
        n/=10;
    }
    return ans;
}
bool isprime(int n){
    for(int i=2;i<=n/2;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int ans=0;
    printf("%d",solve(4)+solve(15));
    for(int i=2;i<=8080;i+=2){
        int cur=solve(i)+solve(i+1);

        if(isprime(cur)) ans++;
    }
    printf("%d",ans);

    return 0;
}

