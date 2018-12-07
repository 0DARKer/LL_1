#include"../include/1.h"
#include<iostream>
#include<map>
#include<vector>
using namespace std;


int main(){
    G a("/home/darker/1.txt");
    a.print_G();
    cout <<"FIRST:"<<endl;
    print_vc(a.get_FIRST("Cb"));
    cout << "FIRSTS:"<<endl;
    print_vvc(a.get_FIRSTS());
    std::map<char,std::vector<char>> FOLLOW=a.get_FOLLOWS();
//    vector<char> follow_i=a.FOLLOW_i(A,FOLLOW,FIRST);
    cout <<"FOLLOWS:"<<endl;
    print_mcvc(FOLLOW);
    vector<char> select=a.get_SELECT("C->E");
    cout << "select:"<<endl;
    print_vc(select);
    cout << "SELECTS:"<<endl;
    print_vvc(a.get_SELECTS());
}
