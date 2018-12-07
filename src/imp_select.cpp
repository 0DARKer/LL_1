#include"../include/1.h"
#include<iostream>
using namespace std;
vector<char> G::get_SELECT(const char *chars){
    vector<char> select;
    char left = chars[0];
    vector<char> right;
    for(int i=3;chars[i]!=0;i++)
    {
        right.push_back(chars[i]);
    }
    int line;
    {
        line=-1;
        int j=0;
        for(pair<char,vector<char>> &i:P){
            if(left==i.first){
                if(right == i.second)line=j;
            }
            j++;
        }
    }
    if(line==-1){cout << "wrong when get select!";throw -1;}
    vector<char> first = get_FIRST(vec_char(right));
    for(char &i:first){
        if(i=='~'){
            vector<char> follow=get_FOLLOW(left);//求follow集合.
            for(char &j:follow){
                if(!in(j,select))select.push_back(j);
            }

        }
        else if(!in(i,select))select.push_back(i);//...
    }
    return select;
}

vector<vector<char>> G::get_SELECTS(){
    int m=0;
    vector<char> temp;
    vector<vector<char>> FIRSTS=get_FIRSTS();
    map<char,vector<char>> FOLLOWS=get_FOLLOWS();
    vector<vector<char>> SELECTS;
    for(vector<char> &i:FIRSTS){
        if(in('~',i)){
            for(char & j : i)
                if(j=='~')continue;
                else temp.push_back(j);
            for(char &j:FOLLOWS[P[m].first])
                if(!in(j,temp))temp.push_back(j);
        }
        else temp=i;
        SELECTS.push_back(temp);
        m++;
        temp.clear();
    }
    return SELECTS;

}
