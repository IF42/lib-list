#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>



/*
** mocro for dynamic creation of list type names
** similar like template in C++
*/
#define List(T) List##T


/*
** macro for construction of list type
*/
#define STRUCT_LIST(T)           \
struct List(T);                  \
typedef struct List(T) List(T)


/*
** definition of empty list
*/
#define list_empty(T) (List(T)*) NULL


/*
** base list class declaration
*/
struct List;
typedef struct List List;


/*
** base list container type construction
*/
STRUCT_LIST(Ptr);
STRUCT_LIST(int);


/*
** Function for adding new list node into List of Pointers
*/
List(Ptr) * 
list_ptr_add(
    List(Ptr) * list
    , void * value);


/*
** Function for adding of new list node into List of integers
*/
List(int) *
list_int_add(
    List(int) * list
    , int value);


/*
** Generic macro for adding of new list node into List of given type
*/
#define list_add(T, v)                     \
    _Generic(                              \
        (T)                                \
        , List(Ptr)* : list_ptr_add        \
        , List(int)* : list_int_add)       \
            (T, v) 



/*
** Function for construction of List of pointers from array
*/
List(Ptr) * 
list_ptr_from_array(
    size_t size
    , void* array[size]);


/*
** Function for construction of List of tegers from array
*/
List(int) *
list_int_from_array(
    size_t size
    , int array[size]);


/*
** Generic macro for construction of List of given type from array
*/
#define list_from_array(s, T)               \
    _Generic(                               \
        (T)                                 \
        , void **: list_ptr_from_array      \
        , int *   : list_int_from_array)    \
            (s, T)
        

/*
** Macro for checking if the list if empty
*/
#define list_is_empty(T)         \
    _Generic(                    \
        (T)                      \
        , List *     : T == NULL \
        , List(Ptr)* : T == NULL \
        , List(int)* : T == NULL)



/*
** Function for returning tail of list from List base class  
*/
List * 
list_base_tail(List * list);


/*
** Generic macro for returning tail of list with type checking
** (input parameter must be derived from List base class)
*/
#define list_tail(T)                                             \
    _Generic(                                                    \
        (T)                                                      \
        , List(Ptr)* : (List(Ptr)*) list_base_tail((List*) T)    \
        , List(int)* : (List(int)*) list_base_tail((List*) T))   


/*
** Function for returning data value from head list node of the 
** List of pointers
*/
void * 
list_ptr_head(List(Ptr) * list);


/*
** Function for returning data value from head list node of the 
** List of integers
*/
int 
list_int_head(List(int) * list);


/*
** Generic macro for returning data value from head list node of the
** list of given type
*/
#define list_head(T)                        \
    _Generic(                               \
        (T)                                 \
        , List(Ptr) * : list_ptr_head       \
        , List(int *  : list_int_head))     \
            (T)


/*
** Function for counting list nodes in base class list 
*/
size_t
list_base_length(List * list);


/*
** Generic macro for counting list nodes in list with type checking
** (input parameter must be derived from List base class)
*/
#define list_length(T)                      \
    _Generic(                               \
        (T)                                 \
        , List(Ptr) * : list_base_length    \
        , List(int) * : list_base_length)   \
            ((List*) T)


/*
** Function for returning of last list node from base class list 
*/
List *
list_base_last(List * list);


/*
** Generic macro for returning of last list node from list with type checking
** (input parameter must be derived from List base class)
*/
#define list_last(T)                                              \
    _Generic(                                                     \
        (T)                                                       \
        , List(Ptr) * : (List(Ptr)*) list_base_last((List*) T)    \
        , List(int) * : (List(int)*) list_base_last((List*) T)) 
           

/*
** TODO: treat releasing of data pointers
*/

/*
List * 
list_base_pop_front (List * list);


#define list_pop_front(T)                    \
    _Generic(                                \
        (T)                                  \
        , List(Ptr)* : list_base_pop_front   \
        , List(int)* : list_base_pop_front)  \
            ((List*) T)




List * 
list_base_pop_back (List * list);


#define list_pop_back(T)                    \
    _Generic(                               \
        (T)                                 \
        , List(Ptr)* : list_base_pop_back   \
        , List(int)* : list_base_pop_back)  \
            ((List*) T)

*/


/*
** Function for unit of two separated lists into one list
*/
List * 
list_base_unit(
    List * t1
    , List * t2);


/*
** Generic macro for unit of two separated lists into one list with 
*/
#define list_unit(T1, T2)                                                    \
    _Generic(                                                                \
        (T1)                                                                 \
        , List(Ptr)* : (List(Ptr)*) list_base_unit((List*) T1, (List*) T2)   \
        , List(int)* : (List(int)*) list_base_unit((List*) T1, (List*) T2)) 
    


/*
** Destructor for list without releasing data pointers memory
*/
void
list_base_finalize(List * list);


/*
** Generic macro for releasing list base on List base class
*/
#define list_finalize(T)                      \
    _Generic(                                 \
        (T)                                   \
        , List(Ptr) *: list_base_finalize     \
        , List(int) * : list_base_finalize)   \
            ((List*) T)

#endif









