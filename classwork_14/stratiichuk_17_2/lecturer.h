#pragma once
#include "human.h"

class Lecturer : virtual public Humanoid{
    std::string VUZ1;
    protected:
    std::string posada;
    std::string salary;

    public:
    Lecturer(){}
    Lecturer(std::string name, unsigned age_, std::string sex, std::string VUZ_, std::string pos, std::string zp):
    Humanoid(name, age_, sex), VUZ1(VUZ_), posada(pos), salary(zp){}

    void show();
    int input();
    void outVUZ(){
        std::cout<<"LecturerVUZ: "<<VUZ1;
    }
};