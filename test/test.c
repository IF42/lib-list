#include <stdlib.h>
#include <stdio.h>
//#include "struct.h"

#include <list.h>


int 
main(void)
{
    int arr[4] = {1, 2, 3, 4};

    List(int) * l1 = 
        list_from_array(
            4
            , arr);
 
    List(int) * l2 =
        list_from_array(
            4
            , arr);

    List(int) * iter = list_unit(l1, l2);

    while(!list_is_empty(iter)) 
    {
        printf("%d\n" , list_head(iter));        
        iter = list_tail(iter);
    }  
    
    list_finalize(iter);


    printf("Linked list test\n");
    return EXIT_SUCCESS;
}
