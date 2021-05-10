//
// Created by niuyb on 2021/3/24.
//
#include <bits/stdc++.h>
using namespace std;
int check(string &s,vector<int> &pos){
    int i=0,j=s.size()-1;
    pos.clear();
    int ans=0;
    while(i<j){
        if(s[i]!=s[j])
        {
            ans++;
            pos.push_back(i);
            pos.push_back(j);
        }
        i++;
        j--;
    }

    return ans;
}
void replace_str(string &s,int left,int right){
    if(s[left]<s[right]){
        s[right] =s[left];
    }
    else{
        s[left] = s[right];
    }
}
void check_num(string &s){
    int i;
    for(i=0;i<s.size();i++){
        if(s[i]!='0'){
            break;
        }
    }
    s[i]='0';
}
int main(){
    int m;
    cin>>m;

    int pp=1;
    while(m--){
        int n;
        cin>>n;
        string str;
        cin>>str;
        vector<int> pos;
        if(check(str,pos)==0){
            printf("%s\n",str.c_str());
        }
        else if(check(str,pos)==1){
            printf("%d %d\n",pos[0],pos[1]);
            if(pos.size()==2)
            {
                replace_str(str,pos[0],pos[1]);
                printf("%s\n",str.c_str());
            }

        }
        else{
            check_num(str);
            printf("%s\n",str.c_str());
        }

    }

}
