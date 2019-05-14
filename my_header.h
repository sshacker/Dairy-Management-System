
int password();
void addrecord();
void viewrecord();
void editrecord();
void editpassword();
void deleterecord();

struct record
{
    char time[6];
    char name[30];
    char place[25];
    char duration[10];
    char note[500];
} ;
