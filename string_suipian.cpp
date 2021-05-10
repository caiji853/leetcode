//
// Created by niuyb on 2021/5/7.
//
#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    set<string> st;
    string cur="";
    cur.push_back(str[0]);
    for(int i=1;i<str.size();i++){
        if(str[i]==str[i-1]){
            cur.push_back(str[i]);
        }
        else{
            st.insert(cur);
            cur=str[i];
        }
    }
    if(cur!=""){
        st.insert(cur);
    }
    for(auto it=st.begin();it!=st.end();++it){
        printf("%s ",it->c_str());
    }
}

