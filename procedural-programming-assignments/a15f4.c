#include <genlib.h>
#include "simpio.h"
#include "stdio.h"

int MenuChoice();
double Converter(int);


int main()
{
    int choice;
    double money;
    choice = 1;
    do
    {
        choice = MenuChoice();
        money = Converter(choice);
    }
    while(choice != 6);
    return 0;
}

int MenuChoice()
{
    int choice;
    printf("\n1. Metatroph se dollaria\n");
    printf("2. Metatroph se lires\n");
    printf("3. Metatroph se fraga Elbetias\n");
    printf("4. Metatroph se dollaria Canada\n");
    printf("5. Metatroph se gien\n");
    printf("6. Exodos\n");
    choice = GetInteger();
    return choice;
}

double Converter(int choice)
{
    double money;
    if (choice != 6)
    {
    printf("Dwse poso xrimatwn: ");
    money = GetReal();
    }
    switch (choice)
    {
    case 1:
        money = money * 0.89;
        printf("H metatropi se dollaria einai: %g\n", money);
    break;
    case 2:
        money = money * 0.618;
        printf("H metatropi se lires einai: %g\n", money);
    break;
    case 3:
        money = money * 1.5465;
        printf("H metatropi se fragka elvetias einai: %g\n", money);
    break;
    case 4:
        money = money * 1.3565;
        printf("H metatropi se dollaria canada einai: %g\n", money);
    break;
    case 5:
        money = money * 109.22;
        printf("H metatropi se gien einai: %g\n", money);
    break;
    case 6:
        return 0.0;
    break;
    }

}
