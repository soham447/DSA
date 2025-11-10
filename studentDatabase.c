#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student
{
    int roll;
    char name[50];
    float marks;
};

struct Student students[MAX];
int count = 0;

void addStudent()
{
    if (count < MAX)
    {
        printf("Enter Roll No: ");
        scanf("%d", &students[count].roll);
        printf("Enter Name: ");
        scanf("%s", students[count].name);
        printf("Enter Marks: ");
        scanf("%f", &students[count].marks);
        count++;
    }
    else
    {
        printf("Database full!\n");
    }
}

void updateStudent()
{
    int roll, i, found = 0;
    printf("Enter Roll No to Update: ");
    scanf("%d", &roll);
    for (i = 0; i < count; i++)
    {
        if (students[i].roll == roll)
        {
            printf("Enter New Name: ");
            scanf("%s", students[i].name);
            printf("Enter New Marks: ");
            scanf("%f", &students[i].marks);
            found = 1;
            continue;
        }
    }
    if (!found)
    {
        printf("Student not found!\n");
    }
}

void searchStudent()
{
    int roll, i, found = 0;
    printf("Enter Roll No to Search: ");
    scanf("%d", &roll);
    for (i = 0; i < count; i++)
    {
        if (students[i].roll == roll)
        {
            printf("Roll: %d, Name: %s, Marks: %.2f\n", students[i].roll, students[i].name, students[i].marks);
            found = 1;
            continue;
        }
    }
    if (!found)
    {
        printf("Student not found!\n");
    }
}

void sortStudents()
{
    int i, j;
    struct Student temp;
    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (students[i].marks < students[j].marks)
            {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Records sorted by performance.\n");
}

void displayStudents()
{
    int i;
    if (count == 0)
    {
        printf("No records found!\n");
        return;
    }
    for (i = 0; i < count; i++)
    {
        printf("Roll: %d, Name: %s, Marks: %.2f\n", students[i].roll, students[i].name, students[i].marks);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("Student Database Menu\n");
        printf("1. Add Student\n");
        printf("2. Update Student\n");
        printf("3. Search Student\n");
        printf("4. Sort by Marks\n");
        printf("5. Display All\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            continue;
        case 2:
            updateStudent();
            continue;
        case 3:
            searchStudent();
            continue;
        case 4:
            sortStudents();
            continue;
        case 5:
            displayStudents();
            continue;
        case 6:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}
