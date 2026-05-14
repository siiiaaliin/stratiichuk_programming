#include <iostream>
#include <stack>

namespace n{
    template <typename T>
    class Stack{
        T* mass;
        int size;
        int top;

        public:
        Stack(int n){
            size=n;
            mass=new T[n];
            top=-1;
        }

        ~Stack(){
            delete[] mass;
        }

        void push(T x){
            if(top==size-1){
                std::cout<<"stack is full\n";
                return;
            }
            mass[++top]=x;
        }

        bool empty(){
            return top==-1;
        }

        T pop(){
            if(top==-1){
                std::cout<<"stack is empty\n";
                return T();
            }
            return mass[top--];
        }
    };
}

void input_mass(n::Stack<int>& st){
    do{
        int x;
        std::cin>>x;
        if(x==0){
            break;
        }
        st.push(x);
    }while(true);
}

void output_mass(n::Stack<int>& st){
    while(!st.empty()){
        std::cout<<st.pop()<<"\n";
    }
}

int main(){
    n::Stack<int> s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout<<s.pop()<<"\n";
    std::cout<<s.pop()<<"\n";
    std::cout<<s.pop()<<"\n";
    std::cout<<s.pop()<<"\n";

    n::Stack<std::string> s2(3);
    s2.push("abc");
    s2.push("def");
    std::cout<<s2.pop()<<"\n";
    std::cout<<s2.pop()<<"\n";
    std::cout<<s2.pop()<<"\n";

    n::Stack<char> s3(3);
    s3.push('a');
    s3.push('b');
    s3.push('c');
    std::cout<<s3.pop()<<"\n";
    std::cout<<s3.pop()<<"\n";
    std::cout<<s3.pop()<<"\n";


    n::Stack<int> st(100);
    std::cout<<"input numbers, 0 to stop:\n";
    input_mass(st);
    output_mass(st);
    

    return 0;
}