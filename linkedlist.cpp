#include <iostream>
#include "list.h"
using namespace std;


int main (int argc, char **argv)
{
    cout << "\n" << endl;
    constructor();
    add(10);
    add(20);
    add(30);
    add(40);
    add(50);
    display();
    cout << "\n" << endl;
    
    deleteList(30);
    display();
    cout << "\n" << endl;
    
    cout << "Search 20" << endl;
    searchList(20);
    cout << "Search 30" << endl;
    searchList(30);
    return 0;
}
