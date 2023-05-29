#include <stdio.h>
#include <string.h>
struct course
{
    int id;
    char title[40];
    float hours;
};
void update_course(struct course *class);
void display_course(struct course class);
int main()
{
    system("cls");
    struct course cs2 = {100, "Check", 10.00};
    printf("%d\t%s\t%3.2f\n", cs2.id, cs2.title, cs2.hours);
    update_course(&cs2);
    display_course(cs2);
    return 0;
}
void update_course(struct course *class)
{
    strcpy(class->title, "C++ Fundamentals");
    class->id = 111;
    class->hours = 12.30;
}
void display_course(struct course class)
{
    printf("%d\t%s\t%3.2f\n", class.id, class.title, class.hours);
}