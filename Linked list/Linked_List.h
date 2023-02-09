#ifndef _LINKED_LIST
#define _LINKED_LIST
//#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))
typedef struct List list;
struct List {
	int data;
	list* next;
};

list* BuildList();
void PrintList(list*);
list* BuildNode(int);
list* addToHead(list*, int);
list* addToTail(list*, int);
list* addToIndex(list*, int, int);
void SelectionSort(list*);
list* FreeList(list*);
list* Delete(list*, int);
int Listcounter(list*);
list* add_sorted_node(list*, int);
void Search_num(list*, int);
int sum_List(list*);
int mul_even(list*);
list* reverse_List(list*);
#endif
