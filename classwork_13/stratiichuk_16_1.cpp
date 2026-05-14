#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Person{
    public:
    string name;
    unsigned byear;
public:
    int input();
    void show();
    string getname();
};
    
int Person::input(){
    cout<<"введіть ПІБ і рік народження: ";
    cin>>name>>byear;
    return 0;
}

void Person::show(){
    cout<<"ПІБ: "<<name<<endl;
    cout<<"рік народження: "<<byear<<endl;
}

string Person::getname(){
    return name;
}


class Friend:
public Person{
    public:
    string phone;
public:
    int input();
    void show();
    void setphone(string p);
    string getphone(){
        return phone;
    }
};

int Friend::input(){
    Person::input();
    cout<<"введіть номер телефону: ";
    cin>>phone;
    return 0;
}

void Friend::show(){
    Person::show();
    cout<<"телефон: "<<phone<<"\n";
}

void Friend::setphone(string p){
    this->phone=p;
}


class PhoneBook{
    int n;
    vector<Friend> f;
    string filename;
public:
void append(const Friend& f);
void del(const string& name);
void change(const string &name, const string& phone);
string getphone(const string& name);
PhoneBook();
};

void PhoneBook::append(const Friend& f){
    this->f.push_back(f);
    n++;
}

void PhoneBook::del(const string& name){
    for(Friend& x:f){
        if(x.getname()==name){
            f.erase(f.begin()+(&x-&f[0]));
        }
    }
}

void PhoneBook::change(const string &name, const string& phone){
    for(Friend& x:f){
        if(x.getname()==name){
            x.setphone(phone);
        }
    }
}

string PhoneBook::getphone(const string& name){
    for(Friend& x:f){
        if(x.getname()==name){
            return x.getphone();
        }
    }
    return "такого друга немає в телефонній книзі";
}

PhoneBook::PhoneBook(){
    filename="pb.txt";
    fstream b(filename.c_str());
    while(!b.eof()){
        Friend c;
        b>>c.name>>c.byear>>c.phone;
        n++;
        c.show();
        f.push_back(c);
    }
}

int main(){
    PhoneBook pb;
    Friend f;
    f.input();
    pb.append(f);
    
    return 0;
}