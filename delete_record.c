
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#include "my_header.h"

void deleterecord( )
{
    system("cls");

    FILE *fp,*fptr ;
    struct record file ;
    char check_pw, another = 'Y', filename[15],time[10];;
    int choice, check;

    printf("\n\n\t\t*************************\n");
    printf("\t\t* WELCOME TO DELETE MENU*");
    printf("\n\t\t*************************\n\n");

    check_pw = password();

    if(check_pw == 1)
    {
        return ;
    }

    while ( another == 'Y' || another == 'y')
    {
        printf("\n\n\tHOW WOULD YOU LIKE TO DELETE.");
        printf("\n\n\t#DELETE WHOLE RECORD\t\t\t[1]");
        printf("\n\t#DELETE A PARTICULAR RECORD BY TIME\t[2]\n\n");

        do
        {
            printf("\n\t\tENTER YOU CHOICE:");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1:
                    printf("\n\tENTER THE DATE OF RECORD TO BE DELETED:[yyyy-mm-dd]:");
                    fflush(stdin);
                    gets(filename);

                    fp = fopen (filename, "wb" ) ;

                    if ( fp == NULL )
                    {
                        printf("\nTHE FILE DOES NOT EXISTS");
                        printf("\nPRESS ANY KEY TO GO BACK.");
                        getch();
                        return ;
                    }

                    fclose(fp);
                    remove(filename);
                    printf("\nDELETED SUCCESFULLY...");
                    break;

                case 2:
                    printf("\n\tENTER THE DATE OF RECORD:[yyyy-mm-dd]:");
                    fflush(stdin);
                    gets(filename);

                    fp = fopen (filename, "rb" ) ;

                    if ( fp == NULL )
                    {
                        printf("\nTHE FILE DOES NOT EXISTS");
                        printf("\nPRESS ANY KEY TO GO BACK.");
                        getch();
                        return ;
                    }

                    fptr=fopen("temp","wb");

                    if(fptr==NULL)
                    {
                        printf("\nSYSTEM ERROR");
                        printf("\nPRESS ANY KEY TO GO BACK");
                        getch();
                        return ;
                    }

                    printf("\n\tENTER THE TIME OF RECORD TO BE DELETED:[hh:mm]:");
                    fflush(stdin);
                    gets(time);

                    while(fread(&file, sizeof(file), 1, fp) == 1)

                    {
                        if(strcmp(file.time,time)!=0)
                            fwrite(&file,sizeof(file),1,fptr);
                    }

                    fclose(fp);
                    fclose(fptr);
                    remove(filename);
                    rename("temp",filename);

                    printf("\nDELETED SUCCESFULLY...");
                    break;

                default:
                    printf("\n\tYOU ENTERED WRONG CHOICE");
                    break;
            }
        }while(choice<1||choice>2);

        printf("\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");
        fflush(stdin);
        scanf("%c",&another);
    }

    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();
}
