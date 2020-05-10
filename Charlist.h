//------------Type Definitions------------//
typedef char value_t[80];
typedef int Key_t;

//------------Definitions-----------------//
#define SUCCESS 0
#define FAIL 1

#ifndef ASSGN4_SORTEDLIST_H
#define ASSGN4_SORTEDLIST_H

#endif //ASSGN4_SORTEDLIST_H


//------------Node related VARs------------//
typedef struct NODE {
    value_t value;
    Key_t key;
    struct NODE* next;
    struct NODE* sort;
} Node;


//------------List related VARs------------//
typedef struct Sorted_list
{
    struct NODE* head;                      //Used for insertion order
    struct NODE* head_sort;                //Used for key sort order
    struct NODE* tail;                    //Used for insertion order
    struct NODE* tail_sort;              //Used for key sort order
    struct NODE* prev_tail;             //Points to tail nodes
    struct NODE* prev_tail_sorted;     //Points to tail nodes
    int size;                         //stores the node count (number of elements in the list)
}Sorted_list;



//------------function declarations------------//
int size (Sorted_list*);
int sortList (Sorted_list*, Node*);
int push_char (Sorted_list*, value_t, Key_t);
int append_char (Sorted_list*, value_t, Key_t);
int rmX_nNodeFromList (Sorted_list*, Node*);
int rmSortedNode (Sorted_list*, Node*);
int rmX_nNodeFromListChar (Sorted_list*, Node*);
int rmSortedNodeChar (Sorted_list*, Node*);
int remove_first_char (Sorted_list*, value_t*, Key_t*);
int remove_last_char (Sorted_list*, value_t*, Key_t*);
int remove_smallest_key_char (Sorted_list*, value_t*, Key_t*);
int remove_largest_key_char (Sorted_list*, value_t*, Key_t*);
void empty_list(Sorted_list*);
void destroy_list (Sorted_list* userSorted_list);
Sorted_list* create_list();
void print_list_sorted_char (Sorted_list *);
void print_list_char (Sorted_list *);
//-----------------------------------------------------------
