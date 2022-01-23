#include "list.h"


struct List
{
    List * next;
};


struct List(Ptr)
{
    List super;
    void * value;
};


struct List(int)
{
    List super;
    int value;
};


List(Ptr) * 
list_ptr_add(
    List(Ptr) * list
    , void * value)
{
    List(Ptr) * node = malloc(sizeof(List(Ptr)));
    
    if(node != NULL)
    {
        node->super.next = (List*) list_empty(Ptr);
        node->value = value;

        if(!list_is_empty(list))
            node->super.next = (List*) list;
        
        return node;
    }

    return list_empty(Ptr);
}


List(int) *
list_int_add(
    List(int) * list
    , int value)
{
    List(int) * node = malloc(sizeof(List(int)));
    
    if(node != NULL)
    {
        node->super.next = (List*) list_empty(int);
        node->value = value;

        if(!list_is_empty(list))
            node->super.next = (List*) list;
        
        return node;
    }

    return list_empty(int);
}


List(Ptr) * 
list_ptr_from_array(
    size_t size
    , void* array[size])
{
    List(Ptr) * node = list_empty(Ptr); 

    for(size_t i = 0; i < size; i++)
    {
        node = list_ptr_add(node, array[i]);
    }

    return node;
}


List(int) *
list_int_from_array(
    size_t size
    , int array[size])
{
    List(int) * node = list_empty(int); 

    for(size_t i = 0; i < size; i++)
    {
        node = list_int_add(node, array[i]);
    }

    return node;
}


List * 
list_base_tail(List * list)
{
    if(!list_is_empty(list))
      return list->next;

    return NULL;
}


void * 
list_ptr_head(List(Ptr) * list)
{
    if(!list_is_empty(list))
        return list->value;

    return NULL;
}


int 
list_int_head(List(int) * list)
{
    if(!list_is_empty(list))
        return list->value;

    return 0;
}


size_t
list_base_length(List * list)
{
    size_t length = 0;

    while(!list_is_empty(list))
    {
        list = list_base_tail(list);
        length ++;
    }

    return length;
}



List *
list_base_last(List * list)
{
    while(!list_is_empty(list->next))
        list = list->next;

    return list;
}


List * 
list_base_pop_front(List * list) 
{
	if(!list_is_empty(list)) 
    {
	    List * next = list->next;
	    free(list);
	
	    return next;
    }
    
    return NULL;
}


List * 
list_base_pop_back(List * list) 
{
    List * head = list;
    List * prev = NULL;

    while(!list_is_empty(list)) 
    {
        if(!list_is_empty(list->next))
        {
            prev->next = NULL;
            free(list);
        }
        else
        {
            prev = list;  
            list = list->next;
        }
    }
	
	return head;
}


void
list_base_finalize(List * list)
{
    while(!list_is_empty(list))
    {
        List * tmp = list;
        list = list_base_tail(list);
        free(tmp);
    }
}


List * 
list_base_unit(
    List * t1
    , List * t2)
{
    if(list_is_empty(t1))
        return t2;
    else if(list_is_empty(t2))
        return t1;
    else
    {
        List * last = list_base_last(t1);
        last->next = t2;
        
        return t1;
    }
}




