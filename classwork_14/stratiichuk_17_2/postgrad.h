#pragma once
#include "student.h"
#include "lecturer.h"

class PostGrad : public Student, public Lecturer{

    public:
    PostGrad(){}
    PostGrad(std::string name, unsigned age_, std::string sex, std::string VUZ_, std::string pos, std::string zp, int kurs_, std::string grupa_):
    Humanoid(name, age_, sex),
    Student(name, age_, sex, kurs_, grupa_, VUZ_),
    Lecturer(name, age_, sex, VUZ_, pos, zp){
        kurs=kurs_; this->grupa=grupa_;
    }

    void show();
    int input();

    void outVUZ(){
        std::cout<<"post grad VUZ: "<<VUZ;
    }
};