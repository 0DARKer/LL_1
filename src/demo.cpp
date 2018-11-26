#include"../include/1.h"
#include<vector>
#include<fstream>
#include<iostream>
#include<map>
#include<cstring>
using namespace std;
void  G::print_G(){
        vector<pair<char,vector<char>>>::iterator Pi;
        for(Pi=P.begin();Pi!=P.end();Pi++){
            cout<<Pi->first<<"->";
            for(int i=0;i!=Pi->second.size();i++){
                cout<<Pi->second[i];
            }
            cout <<endl;
        }
}
bool in(char vc, const std::vector<char> &vn){
//    std::vector<char>::iterator i;
    for(const char &i:vn)
        if(vc==i)return 1;
    return 0;
}
void FIRST::print_F(){
    map<char,vector<char>>::iterator i;
    for(i=FIRST_SET.begin();i!=FIRST_SET.end();i++){
        cout<< i->first<<" ";
        for(char &j:i->second)
            cout<<j<<" ";
        cout<<endl;
    }
}
G::G(const char *filename){
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
//        Vn.push_back(Pi->first);

    }
    for(Pi=P.begin();Pi!=P.end();Pi++)
        for(char &vc:Pi->second)
            if(!in(vc,Vt)&&!in(vc,Vn))Vt.push_back(vc);//Vt.push_back(vc);
    s=P.begin()->first;
}
//char G::FIRST_GET_(const char&c,FIRST &a_first){
//    static bool sum[27];
//    memset(sum,0,sizeof(bool)*27);
//   vector<pair<char,vector<char>>>::iterator Pi;
//   for(Pi=P.begin();Pi!=P.end();Pi++){
//        if(in(c,Vt)||c==0)return c;
//        if(in(c,Vn)){
//            char vc_temp;
//            for(char &vc:Pi->second){
//                if(in(vc,Vt)){
//                    if(!in(vc,a_first.FIRST_SET[c]))a_first.FIRST_SET[c].push_back(vc);
//                    vc_temp=vc;
//                    break;
//                }
//                if(in(vc,Vn)){
//                    char temp;
//                    temp=FIRST_GET_(vc,a_first);
//                    if(temp==0)continue;
//                }
//            }
//            return vc_temp;
//        }
//   }
//}
void G::fresh_FIRST(const char &c,FIRST &s){
    static bool sum[128]={0};
    if(sum[(int)c])return ;
//    memset(sum,0,sizeof(bool)*128);
    for(pair<char,vector<char>> &i:P){
        if(i.first==c){
            for(char &j:i.second){
                if(in(j,Vt)){
                    if(!in(j,s.FIRST_SET[c]))s.FIRST_SET[c].push_back(j);
                    break;
                }
                if(in(j,Vn)){
                    fresh_FIRST(j,s);
                    for(char &t:s.FIRST_SET[j])
                        if(!in(t,s.FIRST_SET[c]))s.FIRST_SET[c].push_back(t);
                    break;
//                    s.FIRST_SET[c]+=s.FIRScT_SET[j];
                }
            }
        }
    }
    sum[(int)c]=1;
}
FIRST G::get_first(){
    FIRST s;
    for(char &i:Vn)
        fresh_FIRST(i,s);
    return s;
}
//PAT G::get_PAT(){
//   PAT a;
//}
