#ifndef CMDL_H
#define CMDL_H
#include <string>

class CMDL {

    int num;
    char** str;
    
public: 

    CMDL(std::string* str, int num);
    ~CMDL();
    void startGame();


};

#endif
