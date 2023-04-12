#include <stdio.h>
#include <string.h>
union id
{
    int id_num;
    char name[20];
};
void set_id(union id *item);
void show_id(union id item);
int main()
{
    system("cls");
    union id item = {10, "hi"};
    set_id(&item);
    show_id(item);
    return 0;
}
void set_id(union id *item)
{
    item->id_num = 42;
    strcpy(item->name, "Ramesh K P");
}
void show_id(union id item)
{
    printf("ID is %d\n", item.id_num);
    printf("Name is %s\n", item.name);
}