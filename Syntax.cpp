#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
int A();
void disp();
void error();
char s[20];
int i;
int main()
{
    printf("S -> cAd\n");
    printf("A -> ab/a\n");
    printf("Enter the String:\n");
    scanf("%s", &s);
    i = 0;
    if (s[i++] == 'c' && A())
    {
        if (s[++i] == 'd' && s[i + 1] == NULL)
            disp();
        else
            error();
    }
    else
        error();
    return 0;
}
int A()
{
    if (s[i++] == 'a' && s[i] == 'b')
        return (1);
    else if (s[--i] == 'a')
        return (1);
    else
        return (0);
}
void disp()
{
    printf("\n string is valid\n");
    getch();

}
void error()
{
    printf("\n string is invalid\n");
    getch();
}
