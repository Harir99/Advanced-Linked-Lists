//
// Created by harir on 2020-03-29.
//
//------------Definitions-----------------//
#define SUCCESS 0
#define FAIL 1
#define SORTED_ORDER 1
#define INSERTED_ORDER 0

#ifndef ASSGN4_SORTEDLIST_H
#define ASSGN4_SORTEDLIST_H

#endif //ASSGN4_SORTEDLIST_H

//------------Type Definitions------------//
typedef int value_t;
typedef double Key_t;

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



//------------function declarations for A4Q1A------------//
int printSortedList(Sorted_list* mySortedList);
int size (Sorted_list*);
int sortList (Sorted_list*, Node*);
int push (Sorted_list*, value_t, Key_t);
int append (Sorted_list*, value_t, Key_t);
int rmX_nNodeFromList (Sorted_list*, Node*);
int rmSortedNode (Sorted_list*, Node*);
int rmX_nNodeFromListChar (Sorted_list*, Node*);
int rmSortedNodeChar (Sorted_list*, Node*);
int remove_first (Sorted_list*, value_t*, Key_t*);
int remove_last (Sorted_list*, value_t*, Key_t*);
int remove_smallest_key (Sorted_list*, value_t*, Key_t*);
int remove_largest_key (Sorted_list*, value_t*, Key_t*);
void empty_list(Sorted_list*);
void destroy_list (Sorted_list* userSortedList);
void print_list_sort (Sorted_list*);
void print_list_all (Sorted_list*);
Sorted_list* create_list();
void free_list (Sorted_list* sorted_list);
//------------function declarations for A4Q1B------------//
Sorted_list * map ( Sorted_list * list, value_t (*fn_ptr)(value_t) );
value_t map_reduce ( Sorted_list * list, value_t (*map)(value_t),value_t (*reduce)(value_t, value_t),value_t init,int order);
value_t map_2_reduce ( Sorted_list * list,Sorted_list * list2, value_t (*map)(value_t,value_t),value_t (*reduce)(value_t,value_t),int order);
value_t reduce(Sorted_list * list, value_t (*reduce)(value_t, value_t), value_t init,int order );
value_t sum_sq(value_t userValue, int value);
value_t sum_of_sq_diff(Sorted_list * list,Sorted_list * list2, int order);
value_t add(value_t userValue, int number);
value_t sum(Sorted_list * list,int order);
value_t deduct(value_t userValue, int number);
Sorted_list* diff(Sorted_list * list,Sorted_list * list2, int order);
Sorted_list* square(Sorted_list * list);
value_t squares(value_t userValue);
value_t mult(value_t userValue, int value);
Sorted_list * map_2_array( Sorted_list * list,Sorted_list * list2, value_t (*fn_ptr)(value_t,value_t),int order);

//------------function declarations for A4Q2------------//

int remove_nth (Sorted_list* userSortedList, value_t* userValue, Key_t* userKey,int n,int order);
Node * nth_node ( Node * node , int n);
int nth  ( Sorted_list * list , int n, value_t*  value,Key_t* userKey, int order);
int count_up(int n);
int count_down(int n);
