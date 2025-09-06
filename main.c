#include "library.h"
int main()
{
    int choice;
    while(1)
    {
        printf("\n===== Library Management System (By Adhish V) =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        getchar();
        

        switch(choice)
        {
            case 1:
            Add_Book();
            break;

            case 2:
            Display();
            break;

            case 3:
            Search();
            break;

            case 4:
            Issue();
            break;

            case 5:
            Return();
            break;

            case 6:
            return 0;
            break;

            default:
            printf("Enter the valid Number :(\n");
        }
    }
}
