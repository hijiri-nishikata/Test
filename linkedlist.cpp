#include <iostream>
using namespace std;

//select type
#define T int

/* List object */
typedef struct LinkedList
{
    T data;
    struct LinkedList* next;
}List;

void constructor();
void add(T d);
void display();
void deleteList(T d);
void searchList(T x);
bool search(T x, List* searchPtr);

/* root config */
List root;
void constructor()
{
    root.next=NULL;
    root.data=0;
}

/* add Method */
void add(T d)
{
    /* virtual pointer*/
    List* virtualPtr=new List;
    virtualPtr->data=d;
    virtualPtr->next=NULL;
    
    /* add element */
    List* searchPtr=&root;//First element
    List* xptr;
    
    for(xptr=searchPtr->next; xptr != NULL; xptr=xptr->next)
    {
        searchPtr=xptr;
    }
    
    searchPtr->next=virtualPtr;
}

void display()
{
    List* pointer=root.next;
    while(pointer != NULL)
    {
        cout << pointer->data << "  " << flush;
        pointer=pointer->next;
    }
}

void deleteList(T d)
{
    List* searchPtr=&root;
    List* deleteData;
    for(deleteData=searchPtr->next; deleteData != NULL; deleteData=deleteData->next)
    {
        if(deleteData->data == d)
        {
            if(deleteData->next != NULL)
            {
                searchPtr->next=deleteData->next;
                delete deleteData;
                return;
            }
            
            searchPtr->next=NULL;
            delete deleteData;
            return;
        }
        searchPtr=searchPtr->next;
    }
    cout << "Not found." << endl;
}

void searchList(T x)
{
    bool judge;
    judge=search(x, root.next);
    if(judge)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
}


bool search(T x, List* searchPtr)
{
    if(searchPtr->next == NULL)
    {
        return false;
    }
    else if(searchPtr->data == x)
    {
        return true;
    }
    else
    {
        return search(x, searchPtr->next);
    }
}

int main (int argc, char *argv[])
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
