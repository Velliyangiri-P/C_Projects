#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"

typedef enum {
    add_student =1,
    delete_student,
    search_student,
    display_all_student,
    save_to_file,
    load_from_file,
    exit_menu,
} Menu;

void PrintMenu(void);

int main (void)
{
    //clears the screen
    system("cls");

    PrintMenu();

    printf("Enter a number of option: ");
    Menu Option=0;
    scanf("%d", &Option);

    switch(Option)
    {
        case add_student:
        {
            break;
        }
        case delete_student:
        {
            break;
        }
        case search_student:
        {
            break;
        }
        case display_all_student:
        {
            break;
        }
        case save_to_file:
        {
            break;
        }
        case load_from_file:
        {
            break;
        }
        case exit_menu:
        {
            printf("Closing Application\r\n");
            return 0;
        }
        default:
        {
            printf("Wrong option\r\nClosing Application....!\r\n");
            break;
        }
    }

    return 0;
}

void PrintMenu(void)
{
    printf("Select a option from below:\r\n" 
            "1. Add Student\r\n"  
            "2. Delete Student\r\n"
            "3. Search Student\r\n"
            "4. Display All Students\r\n"
            "5. Save to File\r\n"
            "6. Load from File\r\n"
            "7. Exit\r\n"
            );
}