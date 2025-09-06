#ifndef LIBRARY_H
#define LIBRARY_H

#include<stdio.h>
#include<string.h>
 
struct Book
{
    int id,issued;
    char author[50],title[100];
};

void Add_Book();
void Display();
void Search();
void Issue();
void Return();


void Add_Book()
    {
        FILE *fp=NULL;
        fp = fopen("Book.dat","a");
        if(fp==NULL)
        {
            printf("\nError Creating File :(\n");
            return;
        }
        struct Book b;
        printf("Enter Book ID: ");
        scanf("%d",&b.id);
        getchar();
        printf("Enter Title: ");
        fgets(b.title,sizeof(b.title),stdin);
        b.title[strcspn(b.title,"\n")]=0;
        printf("Enter Author: ");
        fgets(b.author,sizeof(b.author),stdin);
        b.author[strcspn(b.author,"\n")]=0;
        b.issued=0;
        fwrite(&b,sizeof(b),1,fp);
        fclose(fp);
        printf("\n|Book added Successfully|\n");
    }

    //displaying books function :)
    void Display()
    {
        struct Book b;
        FILE *fp =NULL;
        fp =fopen("Book.dat","rb");
        if(fp==NULL)
        {
            printf("\nSorry Unable to find the file :(\n");
            return;
        }
        printf("\n%-5s %-30s %-20s %-10s\n","ID","Title","Author","Satus");
        printf("\n----------------------------------------------------------------------\n");
        while(fread(&b,sizeof(b),1,fp))
        {
            printf("%-5d %-30s %-20s %-10s\n",b.id,b.title,b.author,(b.issued?"Not Available":"Available"));
        }
        return;
    }

    //Book Searching function (ni ok alle muthe)
    
    void Search()
    {
        FILE *fp=NULL;
        fp = fopen("Book.dat","rb");
        if(fp==NULL)
        {
            printf("\nNo book found!\n");
            return;
        }
        int found=0,id;
        struct Book b;
        printf("Enter the Book ID: ");
        scanf("%d",&id);
        while(fread(&b,sizeof(b),1,fp))
        {
            if(id==b.id)
            {
                printf("|BOOK FOUND!|\n");
                printf("+------------------------------------------+\n");
                printf("| ID     : %-30d |\n", b.id);
                printf("| Title  : %-30s |\n", b.title);
                printf("| Author : %-30s |\n", b.author);
                printf("| Status : %-30s |\n", (b.issued ? "Not Available" : "Available"));
                printf("+------------------------------------------+\n");
                //printf("|ID: %d\n|Title: %s\n|Authour: %s\n|Status: %s\n",b.id,b.title,b.author,(b.issued?"Not Available":"Available"));
                found=1;
                break;
            }
        }
        if(!found)
        printf("----------------\n");
        printf("|No Book Found!|\n");
        printf("----------------\n");
    }

    //book issuing function (hehe yeah boi!!)

    void Issue()
    {
        FILE *fp=NULL;
        fp = fopen("Book.dat","rb+");
        if(fp==NULL)
        {
            printf("\nError No file found!\n");
            return;
        }
        struct Book b;
        int found=0,id;
        printf("Enter the book ID: ");
        scanf("%d",&id);
        while(fread(&b,sizeof(b),1,fp))
        {
            if(id==b.id)
            {
                found=1;
                if(b.issued)
                {
                    printf("\n|Already Issued|\n");
                    return;
                }
                else
                {
                    b.issued=1;
                    fseek(fp,-sizeof(b),SEEK_CUR);
                    fwrite(&b,sizeof(b),1,fp);
                    printf("\n|Book issued successfully :)|\n");
                }
            }
        }
        if(!found)
        printf("\n|Sorry No book found!|\n");
    }

    void Return()
    {
        FILE *fp=NULL;
        fp =fopen("Book.dat","rb+");
        if(fp==NULL)
        {
            printf("\nSorry error Returnint this book!\n");
        }
        int id,found=0;
        printf("Enter the ID: ");
        scanf("%d",&id);
        struct Book b;
        while(fread(&b,sizeof(b),1,fp))
        {
            if(id==b.id)
            {
                found=1;
                if(!b.issued)
                {
                    printf("\nYou can't return unissued book!\n");
                }
                else
                {
                    b.issued=0;
                    fseek(fp,-sizeof(b),SEEK_CUR);
                    fwrite(&b,sizeof(b),1,fp);
                    printf("\nBook returned successfully!\n");
                }
            }
        }
        if(!found)
        printf("\nBook not found\n");
    }


#endif
