#include <iostream>
#include <list>
#include <algorithm>
#include <ctime>
#include <iterator>

using namespace std;

clock_t gen(){
    return clock();
}

int main(){
    list<clock_t> l;

    generate_n(back_inserter(l), 10, gen);

    l.sort();
    l.unique();

    cout<<"result: ";
    copy(l.begin(), l.end(), ostream_iterator<clock_t>(cout, " "));
    cout<<"\n";

    return 0;
}