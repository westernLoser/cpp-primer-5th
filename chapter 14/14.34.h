/*
  author : szz
  date : 2019/07/18
*/
#ifndef C_14_34_H
#define C_14_34_H

class if_then_else {
public:
    int operator()(bool condition, int statement1, int statement2) {
        return condition ? statement1 : statement2; 
    }
}; 

#endif