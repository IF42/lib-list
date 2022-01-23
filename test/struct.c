#include "struct.h"


struct _Human
{
    int age;
    char* name;  
};


struct _ListHuman
{
    List list;
    Human * s;
};



ListHuman *
list_human_new()
{

}


ListHuman *
list_human_add(
    ListHuman * list
    , Human * human)
{

}


void
list_human_finalize(ListHuman * list)
{
    while(list != list_empty)
    {
        human_finalize(list->s);
        ListHuman * tmp = 
    }
}


Human * 
human_new(
    int age
    , char * name)
{
    Human * human = malloc(sizeof(Human));

    if(human != NULL)
    {
        human->age = age;
        human->name = strdup(name);
    }

    return human;
}


void
human_finalize(Human * human)
{
    if(human != NULL)
    {
        free(human->name);
        free(human);
    }
}
