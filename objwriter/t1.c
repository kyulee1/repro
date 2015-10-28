#include <stdio.h>

extern int foo();
int main()
{
int a = foo();
printf("hello world %d\n", a);
}

void goo()
{
printf("this is goo\n");
}
