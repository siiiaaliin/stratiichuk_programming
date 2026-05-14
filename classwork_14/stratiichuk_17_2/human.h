#pragma once
#include <iostream>
#include <string>
#include <cctype>

class Humanoid{
    protected:
    std::string pib;
    unsigned age;
    bool gender;
    
    public:
    Humanoid(){}
    Humanoid(std::string name, unsigned age_, std::string sex);

    virtual ~Humanoid(){} 

    virtual void show();

    int input();

    virtual void outVUZ()=0;
};