#include"../include/1.h"
#include<vector>
#include<fstream>
#include<iostream>
#include<map>
#include<cstring>
using namespace std;
void  G::print_G(){//打印文法
        vector<pair<char,vector<char>>>::iterator Pi;
        for(Pi=P.begin();Pi!=P.end();Pi++){
            cout<<Pi->first<<"->";
            for(int i=0;i!=Pi->second.size();i++){
                cout<<Pi->second[i];
            }
            cout <<endl;
        }
}
G::G(const char *filename){//从文件对文法进行初始化
    ifstream fin(filename);
    if(!fin) {
        throw -1;
        return ;
    }
    while(1){
        vector<char> temp;
        char index;
        index=fin.get();
        if(fin.eof())break;
        if(index=='\n')break;
        {
            fin.get();
            fin.get();
        }
        while(1){
            char a;
            a=fin.get();
            if(a=='\n'||fin.eof())break;
            temp.push_back(a);
        }
        P.push_back(pair<char,vector<char>>(index,temp));
        temp.clear();
    }
    vector<pair<char,vector<char>>>::iterator Pi;
    for(Pi=P.begin();Pi!=P.end();Pi++){
        if(!in(Pi->first,Vn))Vn.push_back(Pi->first);
    }
    for(Pi=P.begin();Pi!=P.end();Pi++)
        for(char &vc:Pi->second)
            if(!in(vc,Vt)&&!in(vc,Vn))Vt.push_back(vc);
    s=P.begin()->first;
}
