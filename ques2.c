#include <stdio.h>
#include <stdlib.h>

struct Enrollment
{
    int id;
    char student[40];
    char course[45];
    int duration;
};

int main()
{
    int n, i, add, total;
    struct Enrollment *e;

    printf("Enter initial number of enrollments: ");
    scanf("%d", &n);


    e = (struct Enrollment *)malloc(n * sizeof(struct Enrollment));

    if (e == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

   
    for (i = 0; i < n; i++)
    {
        printf("\nEnter enrollment %d details:\n", i + 1);

        printf("Enrollment ID: ");
        scanf("%d", &e[i].id);

        printf("Student Name: ");
        scanf(" %s", e[i].student);

        printf("Course Name: ");
        scanf(" %s", e[i].course);

        printf("Duration (months): ");
        scanf("%d", &e[i].duration);
    }

   
    printf("\nNo of new enrollments: ");
    scanf("%d", &add);

    total = n + add;

    e = (struct Enrollment *)realloc(e, total * sizeof(struct Enrollment));

    if (e == NULL)
    {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    for (i = n; i < total; i++)
    {
        printf("\nEnter enrollment %d details:\n", i + 1);

        printf("Enrollment ID: ");
        scanf("%d", &e[i].id);

        printf("Student Name: ");
        scanf(" %s", &e[i].student);

        printf("Course Name: ");
        scanf(" %s", &e[i].course);

        printf("Duration (months): ");
        scanf("%d", &e[i].duration);
    }

    
    printf("\n--- Enrollment Records ---\n");

    for (i = 0; i < total; i++)
    {
        printf("\nID: %d", e[i].id);
        printf("\nStudent: %s", e[i].student);
        printf("\nCourse: %s", e[i].course);
        printf("\nDuration: %d months\n", e[i].duration);
    }

    
    int searchId, found = 0;

    printf("\nEnter Enrollment ID to search: ");
    scanf("%d", &searchId);

    for (i = 0; i < total; i++)
    {
        if (e[i].id == searchId)
        {
            printf("\nRecord Found!");
            printf("\nStudent: %s", e[i].student);
            printf("\nCourse: %s", e[i].course);
            printf("\nDuration: %d months\n", e[i].duration);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nRecord not found!\n");

   
    free(e);

    return 0;
}
