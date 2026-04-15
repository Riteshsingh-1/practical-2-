#include <stdio.h>
#include <stdlib.h>


struct Vehicle
{
    char Vehicle_No[20];
    char owner[50];
    char type[20];
    int year;
};

int main()
{
    int n;
    struct Vehicle *v;
    char searchNum[20];
    int found = 0;

    printf("Enter number of vehicles: ");
    scanf("%d", &n);

    
    v = (struct Vehicle *)calloc(n, sizeof(struct Vehicle));

    if (v == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

  
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details for vehicle %d\n", i + 1);

        printf("Vehicle Number: ");
        scanf("%s", v[i].Vehicle_No);

        printf("Owner Name: ");
        scanf(" %s", v[i].owner);

        printf("Vehicle Type: ");
        scanf("%s", v[i].type);

        printf("Registration Year: ");
        scanf("%d", &v[i].year);
    }

   
    printf("\n--- Vehicle Records ---\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nVehicle %d", i + 1);
        printf("\nNumber: %s", v[i].Vehicle_No);
        printf("\nOwner: %s", v[i].owner);
        printf("\nType: %s", v[i].type);
        printf("\nYear: %d\n", v[i].year);
    }

   
    printf("\nEnter vehicle number to search: ");
    scanf("%s", searchNum);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(v[i].Vehicle_No, searchNum) == 0)
        {
            printf("\nVehicle Found!");
            printf("\nNumber: %s", v[i].Vehicle_No);
            printf("\nOwner: %s", v[i].owner);
            printf("\nType: %s", v[i].type);
            printf("\nYear: %d\n", v[i].year);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nVehicle not in records\n");

    
    free(v);

    return 0;
}
