#include"../include/1.h"
#include<vector>
#include<iostream>
using namespace std;
bool in(char vc, const std::vector<char> &vn){//判断一个char是否属于一个vector容器里面
//    std::vector<char>::iterator i;
    for(const char &i:vn)
        if(vc==i)return 1;
    return 0;
}
void print_mcvc(const std::map<char,std::vector<char>> &a){
//     map<char,vector<char>>::iterator const i;
    for(const pair<char,vector<char>> &i:a){
        cout<< i.first<<" ";
        for(const char &j:i.second)
            cout<<j<<" ";
        cout<<endl;
    }
}
void print_vc(const vector<char> &a){
    for(const char &i:a){
        cout<<i<<" ";
    }
    cout<<endl;
}
char * vec_char(const vector<char> &a){
    char *c=new char[a.size()+1];//这不能直接char*c[a.size()+1],得到的空间会在未来被释放.
    int j=0;
    for(const char &i:a){
        c[j++]=i;
//        if(j==a.size())break;
    }
    c[j++]='\0';
    return c;
}
void print_vvc(const vector<vector<char>> &a){
    for(int i=0;i<a.size();i++){
        cout << i<<" ";
        for(const char & j:a[i])
            cout << j<<" ";
        cout << endl;
    }
}
