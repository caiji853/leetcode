//
// Created by niuyb on 2021/2/8.
//
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
class Base{
public:
    virtual ~Base(){}
};
class Derive: public Base{
public:

};

int main()
{


    vector<shared_ptr<Base>> ptr_nodes;
    vector<shared_ptr<Base>> ptr2_nodes;
    shared_ptr<Base> b1 = make_shared<Derive>();
    shared_ptr<Base> b2 = make_shared<Derive>();
    ptr_nodes.emplace_back(b1);
    ptr_nodes.emplace_back(b2);

    ptr2_nodes.emplace_back(b1);
    ptr2_nodes.emplace_back(b2);

    printf("%p %p",&ptr_nodes[0],&ptr2_nodes[0]);

    vector<shared_ptr<Base>>().swap(ptr_nodes);

    return 0;

}
