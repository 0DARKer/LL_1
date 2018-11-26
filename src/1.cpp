#include"../include/1.h"
#include<iostream>
int main(){
    G a("/home/darker/1.txt");
    a.print_G();
//    FIRST afirst=a.FIRST_GET();
//    afirst.print_F();
    FIRST afirst=a.get_first();
    afirst.print_F();


}
