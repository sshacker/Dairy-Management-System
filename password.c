#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#include "my_header.h"


void get_password_input(char arr[]);

int password()
{
    char ch, pass[15]= {0}, saved_pass[15]= {0};
    int i,j;
    FILE *fp;

    printf("\n\n:: FOR SECURITY PURPOSE :: :: ONLY THREE TRIALS ARE ALLOWED ::");

    for(j=0; j<3; j++)
    {
        printf("\n\n\tENTER THE PASSWORD : ");
        get_password_input(pass);

        fp=fopen("secure","r");
        if (fp==NULL)
        {
            printf("\nERROR WITH THE SYSTEM FILE...[FILE MISSING]\nTRY EDIT PASWORD...\n");
            getch();
            return 1;
        }

        i=0;
        while(1)
        {
            ch=fgetc(fp);

            if(ch==EOF)
            {
                saved_pass[i]='\0';
                break;
            }

            saved_pass[i]=ch-5;
            i++;
        }

        if(strcmp(pass, saved_pass)==0)
        {
            printf("\n\n\tACCESS GRANTED...\n");
            return 0;
        }
        else
        {
            printf("\n\n\tWRONG PASSWORD..\n\n\tACCESS DENIED...\n");
        }
    }

    printf("\n\n\t:: YOU ENTERED WRONG PASSWORD\n\n\t:: YOU ARE NOT ALLOWED TO ACCESS ANY FILE\n\n\t:: PRESS ANY KEY TO GO BACK...");
    getch();
    return 1;
}

void editpassword()
{
    system("cls");

    char ch, pass[15]= {0}, confirm_pass[15]= {0};
    int choice, i, check_pw;
    FILE *fp;

    fp=fopen("secure","rb");
    if(fp==NULL)
    {
        fp=fopen("secure","wb");
        if(fp==NULL)
        {
            printf("\n\nSYSTEM ERROR...");
            getch();
            return ;
        }
        fclose(fp);
        printf("\n\nSYSTEM RESTORED...\nYOUR PASSWORD IS 'ENTER'\n PRESS ENTER TO CHANGE PASSWORD\n\n");
        getch();
    }
    fclose(fp);

    check_pw = password();
    if(check_pw==1)
    {
        return ;
    }

    do
    {
        if(check_pw==0)
        {
            choice=0;

            printf("\n\n\tENTER THE NEW PASSWORD:");
            get_password_input(pass);

            printf("\n\tCONFIRM PASSWORD:");
            get_password_input(confirm_pass);

            if(strcmp(pass, confirm_pass)==0)
            {
                fp=fopen("secure","wb");
                if(fp==NULL)
                {
                    printf("\n\t\tSYSTEM ERROR");
                    getch();
                    return ;
                }

                i=0;
                while(pass[i]!='\0')
                {
                    ch=pass[i];
                    putc(ch+5,fp);
                    i++;
                }

                putc(EOF,fp);
                fclose(fp);
            }
            else
            {
                printf("\n\tTHE NEW PASSWORD DOES NOT MATCH.");
                choice=1;
            }
        }
    }while(choice==1);

    printf("\n\n\tPASSWORD CHANGED...\n\n\tPRESS ANY KEY TO GO BACK...");
    getch();
}

void get_password_input(char pass_arr[])
{
        int i=0;

        pass_arr[0]=getch();
        while(pass_arr[i]!='\r')
        {
            if(pass_arr[i]=='\b')
            {
                i--;
                printf("\b");
                printf(" ");
                printf("\b");
                pass_arr[i]=getch();
            }
            else
            {
                printf("*");
                i++;
                pass_arr[i]=getch();
            }
        }
        pass_arr[i]='\0';
}
