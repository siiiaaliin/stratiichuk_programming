#include <iostream>
#include <cstdlib>

int main(){
    char str[11];
    unsigned long long x, y;
    y=0;
    while(std::cin.get(str, 11)){
        x=atoi(str);
        // x=strtoull(str, NULL, 10);
        y+=x;
    }
    std::cout<<"y="<<y<<std::endl;
}