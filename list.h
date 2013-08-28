#ifndef TEST_LIST_VER0
#define TEST_LIST_VER0

//select type
#define T int

/* List object */
typedef struct LinkedList
{
    T data;
    struct LinkedList* next;
}List;

void constructor();
void add(T);
void display();
void deleteList(T);
void searchList(T);
bool search(T, List*);


#endif
