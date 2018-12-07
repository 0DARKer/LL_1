#include"../include/1.h"
#include<vector>
#include<iostream>
using namespace std;

void PAT::print_first(){//打印first集
    map<char,vector<char>>::iterator i;
    for(i=FIRST_SET.begin();i!=FIRST_SET.end();i++){
        cout<< i->first<<" ";
        for(char &j:i->second)
            cout<<j<<" ";
        cout<<endl;
    }
}
//static会存在于一整个程序运行周期,多遍运行函数会出现莫名其妙的错误.
vector<char> G::get_FIRST(const char *c){
    vector<char> FIRST;
    map<char,vector<char>> s;
    bool sum[255]={0};
//    const char *c=a;
    int is_epsion=0;
    int not_end=1;
    for(int i=0;c[i]!=0;i++){
        if(in(c[i],Vn)){
            get_FIRST_Vn(c[i],s,sum);//if error here ?
//            FIRST=s[c[i]];//error..happened
            for(char &j: s[c[i]]){
                if(j!='~'){
                    if(!in(j,FIRST))FIRST.push_back(j);
                }
                else is_epsion=1;
            }
            if(!is_epsion){
                not_end=0;
                break;
            }
            else continue;
        }
        else if(in(c[i],Vt)){
            FIRST.push_back(c[i]);
            not_end=0;
            break;
        }
        else {
            cout <<"wrong!";
            throw -1;
        }
    }
    if(not_end&&!in('~',FIRST))FIRST.push_back('~');
    return FIRST;
}
void G::get_FIRST_Vn(const char &c,map<char,vector<char>> &s,bool *sum){//求出一个Vn元素的first集,如果包含其他元素的first集,则递归求出.sum对已经递归求出的元素的first集,标记为1,此为初始化.
    if(sum[c])return ;//如果标记为1,则说明此first集已经求出,跳过.
    for(pair<char,vector<char>> &i:P){
        if(i.first==c){//求每一个产生式左边为字符c的first集.
            int ck=0;//在以下的循环中,ck=0表示暂未找到first,ck=1表示已经找到first,
            for(char &j:i.second){//...一般不需要后移.对第一个字符分类讨论,如果是Vn,递归求first集,如果是Vt,则加入first集.
                if(in(j,Vt)){
                    if(!in(j,s[c]))s[c].push_back(j);
                    ck=1;
                    break;
                }
                else if(in(j,Vn)){
                    get_FIRST_Vn(j,s,sum);
                    ck=1;
                    for(char &t:s[j]){
                        if(!in(t,s[c])&&t!='~')s[c].push_back(t);
                        else if(t=='~'){
                            ck=2;
                        }
                    }
                    if(ck==2)continue;
                    else if(ck)break;
                }
                else {
                    cout <<"wrong!";
                    throw -1;
                }
            }
            if(ck==2&&!in('~',s[c]))s[c].push_back('~');
        }
    }
    sum[c]=1;//递归完成后,标记已经求得.
}
vector<vector<char>> G::get_FIRSTS(){
    vector<vector<char>> FIRSTS;
    int i=0;
    for(pair<char,vector<char>> &i:P){
        vector<char> FIRST=get_FIRST(vec_char(i.second));
        FIRSTS.push_back(FIRST);
    }
    return FIRSTS;
}

