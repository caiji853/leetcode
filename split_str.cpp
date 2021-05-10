//
// Created by niuyb on 2021/4/14.
//
#include <bits/stdc++.h>
using namespace std;
struct Student_t{
    char *name_;
    int grade_;
    int level_;
    int id_;
};
/**以’|‘分割字符串
 *
 * @param str
 * @param strs
 * @return
 */
bool split_str(string &str, vector<string> &strs){
    strs.clear();
    int index = 0;
    while(index < str.size()){
        if(str[index] != '|'){
            int add_index = index;
            string cur;
            while(add_index < str.size() && str[add_index] != '|'){
                cur += str[add_index];
                add_index++;
            }
            strs.push_back(cur);
            index = add_index;
        }
        else{
            index++;
        }
    }
    if(strs.size() < 1){
        return false;
    }
    return true;
}

bool split_str_by_colon(string &str, string &key, string &value){
    if(str.size() == 0){
        return false;
    }
    int pos = str.find(':',0);
    if(pos >= str.size()){
        return false;
    }
    key = str.substr(0,pos);
    value = str.substr(pos+1);
    return true;

}

bool get_student_info(string &str, Student_t &student){
    vector<string> strs;
    if(!split_str(str, strs)){
        return false;
    }
    if(strs.size() != 4){
        return false;
    }

    for(int i=0;i<strs.size();i++){
        string key,value;
        if(!split_str_by_colon(strs[i],key,value)){
            return false;
        }
        if(key == "id_"){
            student.id_ = stoi(value);
        }
        else if(key == "name_"){
            student.name_ = new char[value.size()+1];
            memcpy(student.name_, value.c_str(),value.size()+1);

        }
        else if(key == "grade_"){
            student.grade_ = stoi(value);
        }
        else if(key == "level_"){
            student.level_ = stoi(value);
        }
        else{
            return false;
        }
    }
    return true;

}

void print_str(vector<string> &strs){
    for(auto &s:strs){
        printf("%s ",s.c_str());
    }
}

int main(){
    string str = "id_:20162505|name_:niuyb|grade_:94|level_:1";

    ifstream myfile("../split.txt");


    vector<string> stu_strs;
    string temp;
    while(getline(myfile,temp)){
        stu_strs.push_back(temp);
    }

    printf("%d\n",stu_strs.size());
    for(int i=0;i<stu_strs.size();i++){
        printf("%s\n",stu_strs[i].c_str());
    }

    vector<Student_t> stu_infos;
    stu_infos.resize(stu_strs.size());
    for(int i=0;i<stu_strs.size();i++){
        if(!get_student_info(stu_strs[i],stu_infos[i])){
            return -1;
        }
    }

    for(int i=0;i<stu_infos.size();i++){
        printf("id:%d grade:%d name:%s level:%d\n",stu_infos[i].id_,stu_infos[i].grade_,stu_infos[i].name_,stu_infos[i].level_);
    }

    return 0;
}
