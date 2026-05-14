#include <iostream>
#include <string>

using namespace std;

class Word{
    string prefix, prefix2, root, suffix, ending; 
    
    public:
    Word(){}
    Word(string r){
        root=r;
    }
    
    string getprefix(){
        return prefix;
    }
    string getprefix2(){
        return prefix2;
    }
    string getroot(){
        return root;
    }
    string getsuffix(){
        return suffix;
    }
    string getending(){
        return ending;
    }
    
    void setprefix(string s){
        prefix=s;
    }
    void setprefix2(string s){
        prefix2=s;
    }
    void setroot(string s){
        root=s;
    }
    void setsuffix(string s){
        suffix=s;
    }
    void setending(string s){
        ending=s;
    }
    
    void show(){
        cout<<prefix<<prefix2<<root<<suffix<<ending<<"\n";
    }
};


class Noun: public Word{
    public:
    Noun(string r): Word(r){}
    
    void plural(){
        string r=getroot();
        int n=r.length();
        char last=r[n-1];
        char second_last=r[n-2];

        if(last=='y' && second_last!='a' && second_last!='e' && second_last!='i' && second_last!='o' && second_last!='u'){
            setroot(r.substr(0, n-1));
            setending("ies");
            return;
        }
        
        if(last=='h' && (second_last=='c' || second_last=='s')){
            setending("es");
            return;
        }
        
        if(last=='s' || last=='x' || last=='z'){
            setending("es");
            return;
        }
        
        if(last=='o' && second_last!='a' && second_last!='e' && second_last!='i' && second_last!='o' && second_last!='u'){
            setending("es");
            return;
        }
        
        setending("s");
    }

    
    void singular(){
        setending("");
    }
};


class Verb: public Word{
    public:
    Verb(string r): Word(r){}
    
    void third(){
        string r=getroot();
        int n=r.length();
        char last=r[n-1];
        char second_last=r[n-2];

        if(last=='y' && second_last!='a' && second_last!='e' && second_last!='i' && second_last!='o' && second_last!='u'){
            setroot(r.substr(0, n-1));
            setending("ies");
            return;
        }
        
        if(last=='h' && (second_last=='c' || second_last=='s')){
            setending("es");
            return;
        }
        
        if(last=='s' || last=='x' || last=='z'){
            setending("es");
            return;
        }
        
        if(last=='o'){
            setending("es");
            return;
        }
        
        setending("s");
    }
    
    void plural(){
        setending("");
    }
};


class Adjective: public Word{
    public:
    Adjective(string r): Word(r){}
};


int main(){
    Noun n("house");
    cout<<"noun: ";
    n.show();
    n.plural();
    cout<<"plural: ";
    n.show();
    
    Verb v("go");
    cout<<"\nverb: ";
    v.show();
    v.third();
    cout<<"third person: ";
    v.show();
    v.plural();
    cout<<"plural: ";
    v.show();

    Adjective a("big");
    cout<<"\nadjective: ";
    a.show();
    
    return 0;
}