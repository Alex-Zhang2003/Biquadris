#ifndef CMDL_H
#define CMDL_H
#include <string>

class CMDL {

    int num;
    std::string* str;
    
public: 

    CMDL(std::string* str, int num);
    ~CMDL();
    void startGame();


};

#endif
