
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#include "my_header.h"

void editrecord()
{
    system("cls");

    FILE *fp ;
    struct record e ;
    char check_pw, another, time[6], filename[14];
    int num, count=0;

    printf("\n\n\t\t*******************************\n");
    printf("\t\t* WELCOME TO THE EDITING MENU *");
    printf("\n\t\t*******************************\n\n");

    check_pw = password();

    if(check_pw != 0)
    {
        return ;
    }

    do
    {
        printf("\n\tENTER THE DATE OF RECORD TO BE EDITED:[yyyy-mm-dd]:");
        fflush(stdin);
        gets(filename);

        printf("\n\tENTER TIME:[hh:mm]:");
        gets(time);

        fp = fopen ( filename, "rb+" ) ;

        if ( fp == NULL )
        {
            printf( "\nRECORD DOES NOT EXISTS:" ) ;
            printf("\nPRESS ANY KEY TO GO BACK");
            getch();
            return;
        }

        while ( fread ( &e, sizeof ( e ), 1, fp ) == 1 )
        {
            if(strcmp(e.time,time)==0)
            {
                printf("\nYOUR OLD RECORD WAS AS:");
                printf("\nTIME: %s",e.time);
                printf("\nMEETING WITH: %s",e.name);
                printf("\nMEETING AT: %s",e.place);
                printf("\nDURATION: %s",e.duration);
                printf("\nNOTE: %s",e.note);

                printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");
                printf("\n1.TIME.");
                printf("\n2.MEETING PERSON.");
                printf("\n3.MEETING PLACE.");
                printf("\n4.DURATION.");
                printf("\n5.NOTE.");
                printf("\n6.WHOLE RECORD.");
                printf("\n7.GO BACK TO MAIN MENU.");

                do
                {
                    printf("\n\tENTER YOUR another:");
                    fflush(stdin);
                    scanf("%d",&num);
                    fflush(stdin);

                    switch(num)
                    {
                        case 1:
                            printf("\nENTER THE NEW DATA:");
                            printf("\nNEW TIME:[hh:mm]:");
                            gets(e.time);
                            break;

                        case 2:
                            printf("\nENTER THE NEW DATA:");
                            printf("\nNEW MEETING PERSON:");
                            gets(e.name);
                            break;

                        case 3:
                            printf("\nENTER THE NEW DATA:");
                            printf("\nNEW MEETING PLACE:");
                            gets(e.place);
                            break;

                        case 4:
                            printf("\nENTER THE NEW DATA:");
                            printf("\nDURATION:");
                            gets(e.duration);
                            break;

                        case 5:
                            printf("ENTER THE NEW DATA:");
                            printf("\nNOTE:");
                            gets(e.note);
                            break;

                        case 6:
                            printf("\nENTER THE NEW DATA:");

                            printf("\nNEW TIME:[hh:mm]:");
                            gets(e.time);

                            printf("\nNEW MEETING PERSON:");
                            gets(e.name);

                            printf("\nNEW MEETING PLACE:");
                            gets(e.place);

                            printf("\nDURATION:");
                            gets(e.duration);

                            printf("\nNOTE:");
                            gets(e.note);

                            break;

                        case 7:
                            printf("\nPRESS ANY KEY TO GO BACK...\n");

                            getch();
                            return ;
                            break;

                        default:
                            printf("\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n");
                            break;
                    }
                }while(num<1||num>8);

                fseek(fp,-sizeof(e),SEEK_CUR);
                fwrite(&e,sizeof(e),1,fp);

                fseek(fp,-sizeof(e),SEEK_CUR);
                fread(&e,sizeof(e),1,fp);

                another=5;
                break;
            }
        }

        if(another==5)
        {
            system("cls");

            printf("\n\t\tEDITING COMPLETED...\n");
            printf("--------------------\n");
            printf("THE NEW RECORD IS:\n");
            printf("--------------------\n");
            printf("\nTIME: %s",e.time);
            printf("\nMEETING WITH: %s",e.name);
            printf("\nMEETING AT: %s",e.place);
            printf("\nDURATION: %s",e.duration);
            printf("\nNOTE: %s",e.note);

            fclose(fp);
            printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)");
            scanf("%c",&another);
            count++;
        }
        else
        {
            printf("\nTHE RECORD DOES NOT EXIST::\n");
            printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");
            scanf("%c",&another);
        }
    }while(another=='Y'||another=='y');

    fclose ( fp ) ;

    if(count==1)
        printf("\n%d FILE IS EDITED...\n",count);
    else if(count>1)
        printf("\n%d FILES ARE EDITED..\n",count);
    else
        printf("\nNO FILES EDITED...\n");

    printf("\tPRESS ENTER TO EXIT EDITING MENU.");
    getch();
}
