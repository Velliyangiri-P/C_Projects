#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"

void PrintMenu(void);

int main (void)
{
    //clears the screen
    system("cls");

    PrintMenu();

    printf("Enter a number of option\r\n");
    uint32_t Option=0;
    scanf("%d", &Option);

    printf("Helllo !world %d\r\n",Option);
    return 0;
}

void PrintMenu(void)
{
    printf("Select a option from below:\r\n" 
            "1. Add a student\r\n"  
            "2. Delete a student\r\n"
            "3. Search for a student\r\n"
            "4. Display all student\r\n"
            "5. Save all student data\r\n"
            "6. Load student data from a file\r\n"
            );
}