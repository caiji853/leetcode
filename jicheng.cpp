//
// Created by niuyb on 2021/4/6.
//
#include <bits/stdc++.h>
using namespace std;
class Base{
private:
    int num_;
    string name_;
public:
    Base(const string &name){
         name_ = name;
    }
    void set_name(const string &name){
        name_ = name;
    }
    virtual void print_name(){
        for(auto &s:name_){
            printf("%c ",s);
        }
    }
    void single_print(){
        printf("Derived;\n");
    }
};
class Derived: public Base{
public:
    Derived(const string &name) : Base(name) {};
    void derived_print(){
        printf("niu yu bin\n");
    }
//    virtual void print_name(){
//        //printf("this is derived\n");
//    }

    void test_print(){
        print_name();
        Base::print_name();
    }
};
int main(){
    Derived derived = Derived("derived");
    Base *base1 = new Base("base");
    Base *base = &derived;

    base->print_name();


    return 0;
}
