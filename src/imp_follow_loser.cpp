//#include"../include/1.h"
//#include<iostream>
//#include<map>
//#include<vector>
//using namespace std;
//void PAT::print_follow(){//打印first集
//    map<char,vector<char>>::iterator i;
//    for(i=FOLLOW_SET.begin();i!=FOLLOW_SET.end();i++){
//        cout<< i->first<<" ";
//        for(char &j:i->second)
//            cout<<j<<" ";
//        cout<<endl;
//    }
//}

//void G::fresh_FOLLOW(const char &c,map<char,vector<char>> &s,bool *su,map<char,vector<char>>& FIRST,bool exists){
////    short int ck=0;
//////    bool exits=0;
////    if(su[c])return ;
////    for(pair<char,vector<char>> &i:P){
////        for(char &j:i.second){
////            if(j==c&&ck==0){
//////                exists=1;
////                ck=1;
////                continue;
////            }
////            if(ck==1){
////                if(in(j,Vt))if(!in(j,s[c])){
////                    s[c].push_back(j);//如果是空集,则有另外的操作,这里先不考虑
////                    ck=2;
////                    break;
////                }
////                if(in(j,Vn)){//如果first集不为空,则将整个first集归到follow集;如果为空继续向下讨论;如果first集合中有'~'则也向下讨论.
////                    for(char &k:FIRST[j]){//
////                        if(k=='~'){
////                            ck=-1;
////                        }
////                        else{
////                            if(!in(k,s[c]))s[c].push_back(k);
////                        }
////                    }
////                    if(ck>0){//如果ck<0则first集合中有空集,如果ck是二的倍数则说明first集合不为空,如果ck==1则first集合为空
////                        if(j==c)ck=1;//如果当前元素是c,则说明两个c连在一起.
////                        else ck=0;
////                        continue;
////                    }
////                    else{//continue 讨论本产生式右边下一个元素.
////                        ck=1;
////                        continue;
////                    }
////                }
////            }
////        }
////        if(ck==1&&i.first!=c){
////            ck=0;
////            fresh_FOLLOW(i.first,s,su,FIRST,exists);
////            for(char &k:s[i.first])
////                if(!in(k,s[c]))s[c].push_back(k);
////        }
////        else if(i.first==c){
////            ck=0;
////            continue;
////        }
////    }
////    su[c]=1;
//////    if(ck==1)if(!in('#',s[c]))s[c].push_back('#');
//}
//map<char,vector<char>> G::get_follow(){
//    map<char,vector<char>> FIRST;
//    {
//        bool sum[100]={0};
//        for(char &i:Vn){
//            FIRST_prodo(i,FIRST,sum);
//        }
//    }
////    map<char,vector<char>> s;
////    bool su[255]={0};
////    s[P.begin()->first].push_back('#');
////    for(char &i:Vn){
////        fresh_FOLLOW(i,s,su,FIRST,0);
////    }
////    return s;
//}


