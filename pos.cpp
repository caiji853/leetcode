//
// Created by niuyb on 2021/4/11.
//
#include <bits/stdc++.h>
using namespace std;
static bool comp(int &a, int &b){
    string a_str = to_string(a);
    string b_str = to_string(b);

    int index = 0;
    while(index < a_str.size() || index < b_str.size()){
        if(a_str[index] > b_str[index]){
            return true;
        }
        if(a_str[index] < b_str[index]){
            return false;
        }
        index++;
    }

    if(!(index == a_str.size() && index == b_str.size())){
        string new_b = b_str + a_str;
        string new_a = a_str + b_str;
        return new_a > new_b;
    }
    return true;



}
int main(){
    int a = 3;
    int b= 30;
    if(comp(a,b)==1){
        printf("true");
    }
    else{
        printf("false");
    }
    return 0;

}
