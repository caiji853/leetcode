//
// Created by niuyb on 2021/3/10.
//
#include <bits/stdc++.h>
using namespace std;
struct Point{
    int x;
    int y;
};
static bool cmp(pair<int,int> &a, pair<int, int> &b){
    if(a.first < b.first) return true;

    if(a.first == b.first){
        return a.second < b.second;
    }
    return false;
}
int main(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<pair<int,int> > points;
    for(int i=0;i<n;i++){
        Point point;
        cin>>point.x>>point.y;
        int dis=(x-point.x)*(x-point.x)+(y-point.y)*(y-point.y);
        points.push_back({dis,i+1});

    }
    sort(points.begin(),points.end(),cmp);
    for(int i=0;i<3;i++){
        printf("%d\n",points[i].second);
    }

}
