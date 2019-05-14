
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#include "my_header.h"

void addrecord( )
{
    system("cls");

    FILE *fp ;
    char another = 'Y' ,time[10], check_password;
    struct record e ;
    char filename[15];
    int flag;

    printf("\n\t\t********************************");
    printf("\n\t\t* WELCOME TO THE ADD NOTE MENU *");
    printf("\n\t\t********************************");

    check_password = password();
    if(check_password != 0)
    {
        return ;
    }

    printf("\n\n\n\tENTER DATE OF YOUR RECORD:[yyyy-mm-dd] : ");
    fflush(stdin);
    gets(filename);

    fp = fopen (filename, "ab+" ) ;
    if ( fp == NULL )
    {
        fp=fopen(filename,"wb+");
        if(fp==NULL)
        {
            printf("\nSYSTEM ERROR...");
            printf("\nPRESS ANY KEY TO EXIT");
            getch();
            return ;
        }
    }

    while ( another == 'Y'|| another=='y' )
    {
        flag = 0;

        //fflush(stdin);
        printf ( "\n\tENTER TIME:[hh:mm]:");
        fflush(stdin);
        scanf("%s",time);

        rewind(fp);
        while(fread(&e, sizeof(e), 1, fp) == 1)
        {
            if(strcmp(e.time, time) == 0)
            {
                printf("\n\tTHE RECORD ALREADY EXISTS.\n");
                flag=1;
            }
        }

        if(flag == 0)
        {
            strcpy(e.time, time);
            fflush(stdin);

            printf("\tENTER NAME:");
            gets(e.name);
            fflush(stdin);

            printf("\tENTER PLACE:");
            gets(e.place);
            fflush(stdin);

            printf("\tENTER DURATION:");
            gets(e.duration);
            fflush(stdin);

            printf("\tNOTE:");
            gets(e.note);
            fwrite ( &e, sizeof(e), 1, fp ) ;

            printf("\nYOUR RECORD IS ADDED...\n");
        }

        printf ( "\n\tADD ANOTHER RECORD...(Y/N) " ) ;
        fflush ( stdin ) ;
        another = getchar( ) ;
    }

    fclose ( fp ) ;

    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();
}
