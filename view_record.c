
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#include<string.h>
#include "my_header.h"

void viewrecord( )
{
    system("cls");

    FILE *fp;
    struct record e;

    char another = 'Y', check_password, time[6], filename[14];
    int ch;

    printf("\n\t\t****************************");
    printf("\n\t\t* HERE IS THE VIEWING MENU *");
    printf("\n\t\t****************************");

    check_password = password();
    if(check_password != 0)
    {
        return ;
    }

    while(another=='Y'||another=='y')
    {
        printf("\n\n\n\tENTER THE DATE OF RECORD TO BE VIEWED:[yyyy-mm-dd] : ");
        fflush(stdin);
        gets(filename);

        fp = fopen ( filename, "rb" ) ;
        if ( fp == NULL )
        {
            puts ( "\nTHE RECORD DOES NOT EXIST...\n" ) ;
            printf("PRESS ANY KEY TO EXIT...");
            getch();
            return ;
        }
        system("cls");

        printf("\n\tHOW WOULD YOU LIKE TO VIEW\n");
        printf("\n\t1.WHOLE RECORD OF THE DAY.");
        printf("\n\t2.RECORD OF FIX TIME.");

        printf("\n\n\n\t\tENTER YOUR CHOICE : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nTHE WHOLE RECORD FOR %s IS : ",filename);
                while ( fread ( &e, sizeof(e), 1, fp ) == 1 )
                {
                    printf("\n");
                    printf("\nTIME: %s",e.time);
                    printf("\nMEETING WITH: %s",e.name);
                    printf("\nMEETING AT: %s",e.place);
                    printf("\nDURATION: %s",e.duration);
                    printf("\nNOTE: %s",e.note);
                    printf("\n");
                }
                break;

            case 2:
                fflush(stdin);
                printf("\nENTER TIME:[hh:mm] : ");
                gets(time);

                while ( fread ( &e, sizeof (e), 1, fp ) == 1 )
                {
                    if(strcmp(e.time, time)==0)
                    {
                        printf("\nYOUR RECORD IS:");
                        printf("\nTIME: %s",e.time);
                        printf("\nMEETING WITH: %s",e.name);
                        printf("\nMEETING AT: %s",e.place);
                        printf("\nDUARATION: %s",e.duration);
                        printf("\nNOTE: %s",e.note);
                    }
                }
                break;

            default:
                printf("\nYOU TYPED SOMETHING ELSE...\n");
                break;
            }

            printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");
            fflush(stdin);
            scanf("%c",&another);
    }

    fclose ( fp ) ;
    return ;
}
