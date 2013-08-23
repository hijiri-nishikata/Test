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
    List* searchptr=&root;//First element
    List* xptr;
    
    for(xptr=searchptr->next; xptr != NULL; xptr=xptr->next)
    {
        searchptr=xptr;
    }
    
    searchptr->next=virtualPtr;
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
    List* searchptr=&root;
    List* deleteData;
    for(deleteData=searchptr->next; deleteData != NULL; deleteData=deleteData->next)
    {
        if(deleteData->data == d)
        {
            if(deleteData->next != NULL)
            {
                searchptr->next=deleteData->next;
                delete deleteData;
                return;
            }
            
            searchptr->next=NULL;
            delete deleteData;
            return;
        }
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
    constructor();
    add(10);
    add(20);
    add(30);
    display();
    
    cout << endl;
    deleteList(10);
    display();
    
    cout << endl;
    searchList(20);
    return 0;
}

