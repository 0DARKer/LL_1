#include"../include/1.h"
#include<iostream>
#include<map>
#include<vector>
using namespace std;
void G::get_FOLLOW(const char &a,map<char,vector<char>> &FOLLOW,map<char,vector<char>>&FIRST){
    if(!in(a,Vn)){throw -1;}
    int ck=-1;
    bool exists=0;
	for(pair<char,vector<char>> &i:P){
		for(char &j:i.second){
			if(ck==-1){//-1
                if(/*!in(j,Vn)||*/j!=a)continue;
				ck=0;
                exists = 1;
                continue;
			}
            if(ck==0||ck==21){//0 ,2.11
				if(in(j,Vt)){//1
					if(!in(j,FOLLOW[a]))FOLLOW[a].push_back(j);
					ck=-1;
					break;
				}
				else if(in(j,Vn)){
                    ck=22;
                    for(const char &k:FIRST[j]){
						if(k=='~'){
                            ck=21;
						}
                        else if(!in(k,FOLLOW[a]))FOLLOW[a].push_back(k);
					}
                    if(ck==22){
						ck=-1;
						break;
					}
				}
				else {throw -1;}
			}
		}
	if(ck==-1){
		continue;
	}

    else if(ck==21||ck==0){//2.12 , 0 , 3
        get_FOLLOW(i.first,FOLLOW,FIRST);
		for(char &m:FOLLOW[i.first]){
			if(!in(m,FOLLOW[a]))FOLLOW[a].push_back(m);
		}
		ck=-1;
	}
	}
    if(!exists)if(!in('~',FOLLOW[a]))FOLLOW[a].push_back('~');
//    return FOLLOW[a];
}
//情况4 首非终结符

std::map<char,std::vector<char>> G::get_FOLLOWS(){

    map<char,vector<char>> FIRST;
    map<char,vector<char>> FOLLOW_SET;

    {
        bool sum[100]={0};
        for(char &i:Vn){
            get_FIRST_Vn(i,FIRST,sum);
        }
    }
   for(char &i:Vn)
        get_FOLLOW(i,FOLLOW_SET,FIRST);
   return FOLLOW_SET;
}
vector<char> G::get_FOLLOW(const char &a){
    map<char,vector<char>> FOLLOW;
    map<char,vector<char>> FIRSTS_Vn;
    {
        bool sum[255];
        for(char &i:Vn){
            get_FIRST_Vn(i,FIRSTS_Vn,sum);
        }
    }
    get_FOLLOW(a,FOLLOW,FIRSTS_Vn);
    return FOLLOW[a];
}
