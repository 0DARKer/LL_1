#ifndef a1_H
#define a1_H
//#include<iostream>
#include<vector>
#include<map>
//char ~ denote non_set epsion
struct PAT{//predicting analysis table
    std::map<char,std::vector<char>> FIRST_SET;
    std::map<char,std::vector<char>> FOLLOW_SET;
    std::map<char,std::map<char,std::vector<char>>> SELECT_SET;
    friend class G;
};
class FIRST{
    std::map<char,std::vector<char>> FIRST_SET;
    friend class G;
public:
    void print_F();
};

class G{
    std::vector<char> Vt;
    std::vector<char> Vn;
    std::pair<char,std::vector<char>> Pi;
    std::vector<std::pair<char,std::vector<char>>> P;
    int s;
    void fresh_FIRST(const char &,FIRST &);
//    char FIRST_GET_(const char&,FIRST &);
public:
    G(const char*);
    void print_G();
    FIRST get_first();
//    PAT get_PAT();
//    void join_Vn(char);
//    void join_Vt(char);
//    FIRST FIRST_GET();
//    char FOLLOW_GET(const char &,PAT &);
//    char SELECT_GET(const char&,PAT &);
};
bool in(char , const std::vector<char> &);

#endif // 1_H
