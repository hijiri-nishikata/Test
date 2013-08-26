#include <iostream>
#include "list.h"
using namespace std;

/* root config */
List root;
void constructor()
{
	int a;
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
        cout << pointer->data << " " << flush;
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

