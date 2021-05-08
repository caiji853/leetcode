//
// Created by niuyb on 2021/5/8.
//
#include <bits/stdc++.h>
using namespace std;
struct student_t{
    char name[1000];
    int score[3];
    int sum_score=0;
};

static bool cmp(student_t &a, student_t &b){
    return a.sum_score >= b.sum_score;
}
int main(){
    int n;
    cin>>n;
    vector<student_t> students;
    students.resize(n);
    for(int i=0;i<n;i++){

        scanf("%s",students[i].name);

        for(int j=0;j<3;j++){
            cin>>students[i].score[j];
            students[i].sum_score += students[i].score[j];
        }


    }

    for(int i=0;i<n;i++){
        bool flag = false;
        for(int j=0;j<3;j++){
            if(students[i].score[j] < 60){
                flag = true;
                break;
            }
        }
        if(flag == true){
            printf("*name:%s ",students[i].name);
            printf("score:");
            for(int j=0;j<3;j++){
                printf("%d ",students[i].score[j]);
            }
            printf("\n");
        }
    }

    sort(students.begin(),students.end(),cmp);
    for(int i=0;i<n;i++){
        printf("[%d] name:",i+1);
        printf("%s ",students[i].name);
        for(int j=0;j<3;j++){
            printf("%d ",students[i].score[j]);
        }
        printf("\n");
    }
    return 0;
}

