#ifndef _STRUCT_H_
#define _STRUCT_H_ 



struct _Human;
typedef struct _Human Human;

struct _ListHuman;
typedef struct _ListHuman ListHuman;


ListHuman *
list_human_new();


ListHuman *
list_human_add(
    ListHuman * list
    , Human * human);


void
list_human_finalize(ListHuman * list);


Human * 
human_new(
    int age
    , char * name);


void
human_finalize(Human * human);



#endif
