#ifndef a1_H
#define a1_H
#include<vector>
#include<map>
//char ~ denote non_set epsion
struct PAT{//predicting analysis table
    std::map<char,std::vector<char>> FIRST_SET;
    std::map<char,std::vector<char>> FOLLOW_SET;
    std::map<char,std::map<char,std::vector<char>>> SELECT_SET;
    friend class G;
public:
    void print_first();
    void print_follow();
};

class G{
    std::vector<char> Vt;
    std::vector<char> Vn;
    std::pair<char,std::vector<char>> Pi;
    std::vector<std::pair<char,std::vector<char>>> P;
    int s;
    void get_FIRST_Vn(const char &,std::map<char,std::vector<char>> &,bool *);
    void get_FOLLOW(const char &,std::map<char,std::vector<char>> &, std::map<char,std::vector<char>>&);

//    void  fresh_FOLLOW(const char & , std::map<char,std::vector<char>> &,bool *,std::map<char,std::vector<char>>&,bool);
public:
    G(const char*);
    void print_G();
    std::vector<char> get_FIRST( const char *);
    std::vector<std::vector<char>> get_FIRSTS();
    std::vector<char> get_FOLLOW(const char &);
    std::map<char,std::vector<char>> get_FOLLOWS();
    std::vector<char> get_SELECT(const char *);
    std::vector<std::vector<char>> get_SELECTS();
};
bool in(char , const std::vector<char> &);
void print_mcvc(const std::map<char,std::vector<char>> &);
void print_vc(const std::vector<char>&);
char * vec_char(const std::vector<char> &);
void print_vvc(const std::vector<std::vector<char>> &);
#endif // 1_H
