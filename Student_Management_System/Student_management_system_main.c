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

typedef struct Student{
    uint32_t id;
    unsigned char Name[50];
    uint8_t age;
    float gpa;
    struct Student* next;
}Student;

void PrintMenu(void);
void addStudent(Student** head);
void deleteStudent(Student** head, int id);
Student * searchStudent (Student** head, int id);
void displayAll(Student** head);
void saveToFile(Student** head, const char* fileName);
void loadFromFile(Student** head, const char *filename);

int main (void)
{
    Student* head = NULL;

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
            addStudent(&head);
            break;
        }
        case delete_student:
        {
            int student_id=0;
            printf("Enter student id: ");
            scanf("%d", &student_id);
            deleteStudent(&head, student_id);
            break;
        }
        case search_student:
        {
            int student_id=0;
            printf("Enter student id: ");
            scanf("%d", &student_id);
            Student * student_info = searchStudent(&head, student_id);
            if(student_info != NULL)
            {
                printf("\r\nID: %d Name: %s Age: %d GPA: %.2f\r\n", student_info->id, student_info->Name, student_info->age, student_info->gpa);
            }
            else
            {
                printf("\r\nStudent not found\r\n");
            }
            break;
        }
        case display_all_student:
        {
            displayAll(&head);
            break;
        }
        case save_to_file:
        {
            saveToFile(&head, "Database.txt");
            break;
        }
        case load_from_file:
        {
            loadFromFile(&head, "Database.txt");
            break;
        }
        case exit_menu:
        {
            printf("Closing Application\r\n");
            exit(0);
            break;
        }
        default:
        {
            printf("\r\nWrong option\r\nClosing Application....!\r\n");
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

// Function to add a new student
void addStudent(Student** head)
{
    Student * New_student = malloc(sizeof(Student));

    printf("\r\nEnter Student ID: ");
    scanf("%d",&New_student->id);
    
    printf("\r\nEnter Student Name: ");
    scanf("%s",&New_student->Name);

    printf("\r\nEnter Student Age: ");
    scanf("%d",&New_student->age);

    printf("\r\nEnter Student GPA: ");
    scanf("%f",&New_student->gpa);

    New_student->next = *head;

    *head = New_student;
}

void deleteStudent(Student** head, int id)
{
    Student * temp = *head;
    Student * prev;

    if((temp !=NULL) && (temp->id == id))
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while((temp !=NULL) && (temp->id == id))
    {
        prev = temp;
        temp = prev->next;
    }

    if(temp == NULL)
    {
        printf("Student not found\r\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Student deleted successfully\r\n");
    return;
}

Student * searchStudent (Student** head, int id)
{
    Student* current_node = *head;
    if(current_node != NULL)
    {
        while(current_node->id == id)
        {
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL;
}

void displayAll(Student** head)
{
    Student* current_node = *head;
    while(current_node != NULL)
    {
        printf("\r\nID: %d Name: %s Age: %d GPA: %.2f", current_node->id, current_node->Name, current_node->age, current_node->gpa);
        current_node = current_node->next;
    }
}

void saveToFile(Student** head, const char* fileName)
{
    FILE * file = fopen(fileName, "w");
    if(file != NULL)
    {
        printf("\r\nCould not open file for writing");
        return;
    }

    Student* current_student = *head;
    while(current_student != NULL)
    {
        fprintf(file, "%d,%s,%d,%.2f\r\n", current_student->id, current_student->Name, current_student->age, current_student->gpa);
        current_student = current_student->next;
    }

    fclose(file);
    printf("\r\nData saved to file successfully");
}

void loadFromFile(Student** head, const char *filename)
{
    FILE * file = fopen(filename, "r");

    if(file == NULL)
    {
        printf("\r\nCould not open file for writing");
        return;
    }

    Student* current_student = NULL;
    Student* New_student;
    char line[100];

    while(*head != NULL)
    {
        Student* temp = *head;
        *head = temp->next;
        free(temp);
    }

    while(fgets(line, sizeof(line), file))
    {
        New_student = malloc(sizeof(Student));
        sscanf(line, "%d,%49[^,],%d,%f", &New_student->id, &New_student->Name, &New_student->age, &New_student->gpa);
        New_student->next = NULL;

        if(current_student == NULL)
        {
            *head = New_student;
            current_student = New_student;
        }
        else
        {
            current_student->next = New_student;
            current_student = New_student;
        }
    }

    fclose(file);
    printf("\r\nData loaded from file successfully");
}