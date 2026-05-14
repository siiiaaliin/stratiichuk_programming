#include <iostream>

#include "postgrad.h"

void PostGrad::show(){
    std::cout<<pib<<" ,"<<age<<" ,"<<(gender?"male":"female")<<"\n";
    std::cout<<posada<<" ,"<<VUZ<<"\n";
    std::cout<<grupa<<" ,"<<kurs<<"\n";
}

int PostGrad::input(){
    Lecturer::input();
    std::cout<<"Grupa, kurs: ";
    std::cin>>grupa;
    std::cin>>kurs;
    return 0;
}


int main(){
    Humanoid* mas[20];
    int n;
    std::cout<<"number of persons (N=): ";
    std::cin>>n;

    for(int i=0; i<n; i++){
        std::cout<<"Input person (L, S, A): ";
        std::string tmp;
        std::cin>>tmp;

        if(tmp.length()>0){
            if(tmp[0]=='l'){
                Lecturer l;
                l.input();
                mas[i]=new Lecturer(l);
            }
            else if(tmp[0]=='s'){
                Student s;
                s.input();
                mas[i]=new Student(s);
            }
            else if(tmp[0]=='a'){
                PostGrad p;
                p.input();
                mas[i]=new PostGrad(p);
            }
        }
    }

    std::cout<<"Out:\n";
        for(int i=0; i<n; i++){
            Lecturer* l=dynamic_cast<Lecturer*>(mas[i]);
            if(l){
                std::cout<<"\n Number"<<i<<"\ncasted to lecturer: ";
                l->outVUZ();
            }
            else{
                mas[i]->show();
                std::cout<<"\n not casted to lecturer";
            }
        }
    
    for(int i=0; i<n; i++){
        delete mas[i];
    }
}