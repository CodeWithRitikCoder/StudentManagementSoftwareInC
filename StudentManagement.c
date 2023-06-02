//Student management Project in C programming.
//Write a program to ------------ with RitikCoder.
#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
#include"windows.h"
#include"string.h"

//Function Declaration is here.
void gotoxy(int, int);
void mainMenu();
void addRecord();
void viewRecord();
void searchRecord();
void modifyRecord();
void deleteRecord();

//Structur is here of this Project.
struct student{
    char name[20];
    char phoneNo[10];
    int rollNo;
    char course[20];
    char branch[20];
};

int main(){
    printf("Student management project in C programming\n");
    gotoxy(30, 8);
    printf("********** Student Record Management System **********");
    gotoxy(30, 15);
    printf("Press any key to continue.......");

    getch();
    mainMenu();
    
    //getch();
    return(0);
}

//Functions definition is here.
void gotoxy(int x, int y){
    COORD c;
    c.X= x;
    c.Y= y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void mainMenu(){
    int choice;
    system("cls");
    gotoxy(10, 1);
    printf("********** Student Record Management System **********");
    gotoxy(10, 3);
    printf("Main menu");
    gotoxy(13, 5);
    printf("** Please choose an option. **");
    gotoxy(10, 7);
    printf("1. Add Record");
    gotoxy(10, 8);
    printf("2. View Record");
    gotoxy(10, 9);
    printf("3. Search Record");
    gotoxy(10, 10);
    printf("4. Modify Record");
    gotoxy(10, 11);
    printf("5. Delete Record");
    gotoxy(10, 12);
    printf("6. Exit");
    gotoxy(10, 14);

    printf("Enter your choice here : ");
    scanf("%d", &choice);

    switch(choice){
        case 1:{
            addRecord();
            break;
        }
        case 2:{
            viewRecord();
            break;
        }
        case 3:{
            searchRecord();
            break;
        }
        case 4:{
            modifyRecord();
            break;
        }
        case 5:{
            deleteRecord();
            break;
        }
        case 6:{
            exit(0);
            break;
        }
        default :{
            printf("!!-Invalid input.");
        }
    }

}

void addRecord(){
    struct student s1;
    FILE *fptr= NULL;
    char another1= 'y';
    system("cls");
    fptr= fopen("record.txt", "ab+");
    if(fptr== NULL){
        printf("file is not opened.");
        exit(1);
    }else{
        while(another1== 'y'){
            gotoxy(10, 2);
            printf("Student Details");
            gotoxy(10, 5);
            fflush(stdin);

            printf("Enter Student's Name : ");
            gets(s1.name);
            fflush(stdin);
            gotoxy(10, 6);
            fflush(stdin);

            printf("Enter Phone No : ");
            gets(s1.phoneNo);
            fflush(stdin);
            gotoxy(10, 7);

            printf("Enter Roll No : ");
            scanf("%d", &s1.rollNo);
            fflush(stdin);
            gotoxy(10, 8);
            fflush(stdin);

            printf("Enter Course : ");
            gets(s1.course);
            fflush(stdin);
            gotoxy(10, 9);

            printf("Enter Branch : ");
            gets(s1.branch);
            fflush(stdin);

            fwrite(&s1, sizeof(s1), 1, fptr);
            //fclose(fptr);

            gotoxy(10, 15);
            printf("Do you want another record then press 'y' otherwis 'n'");
            another1= getch();
            system("cls");
        }

        fclose(fptr);
        gotoxy(10, 18);
        printf("Press any key to continue....");
        mainMenu();
    }
}

void viewRecord(){
    FILE *fptr= NULL;
    int i= 1, j;
    struct student s1;
    system("cls");

    gotoxy(40, 3);
    printf("View Student Record");

    gotoxy(7, 5);
    printf("|********|********************|****************|*********|***************|************|");
    gotoxy(10, 6);
    printf("S.NO    Name_Of_Student       Mobile_No       Roll.No     Course         Branch");
    gotoxy(7, 7);
    printf("|********|********************|****************|*********|***************|************|");
    fptr= fopen("record.txt", "rb+");
    if(fptr== NULL){
        printf("File is not opened");
        exit(1);
    }else{
        j= 10;
        while(fread(&s1, sizeof(s1), 1, fptr)== 1){
            gotoxy(10, j-1);

            printf("%-4d \t  %-15s \t%-10s \t %-5d     %-10s      %-15s \t ", i, s1.name, s1.phoneNo, s1.rollNo, s1.course, s1.branch);
            j++; i++;
        }
        gotoxy(7, j-1);
        printf("|********|********************|****************|*********|***************|************|");
        fclose(fptr);
        gotoxy(10, j+ 3);
        printf("Press any key to continue...");
        getch();
        mainMenu();
    }
}

void searchRecord(){
    FILE *fptr= NULL;
    struct student s1;
    char name[20];
    system("cls");

    gotoxy(10, 2);
    printf("** Search Record **");

    gotoxy(10, 4);
    printf("Enter name of student : ");
    fflush(stdin);
    gets(name);

    fptr= fopen("record.txt", "rb+");
    if(fptr== NULL){
        printf("File is not opened");
        exit(1);
    }else{
        while(fread(&s1, sizeof(s1), 1, fptr)== 1){
            if(strcmp(name, s1.name)== 0){
                gotoxy(10, 7);
                printf("Name of student is : %s", s1.name);
                gotoxy(10, 8);
                printf("Phone of student is : %s", s1.phoneNo);
                gotoxy(10, 9);
                printf("Roll no of student is : %d", s1.rollNo);
                gotoxy(10, 10);
                printf("Course of student is : %s", s1.course);
                gotoxy(10, 11);
                printf("Branch of student is : %s", s1.branch);
            }
        }
    }
    fclose(fptr);
    gotoxy(10, 14);
    printf("Press any key to continue...");
    getch(); 
    mainMenu();
}

void modifyRecord(){
    char name[20];
    FILE *fptr= NULL;
    struct student s1;
    long int isFound;
    system("cls");

    gotoxy(10, 3);
    printf("** Modify Record **");

    gotoxy(10, 5);
    printf("Enter name of student to modifing : ");
    fflush(stdin);
    gets(name);

    fptr= fopen("record.txt", "rb+");
    if(fptr== NULL){
        printf("!File is not opened");
        exit(1);
    }else{
        rewind(fptr);
        while(fread(&s1, sizeof(s1), 1, fptr)== 1){
            if(strcmp(name, s1.name)== 0){
                gotoxy(10, 7);
                printf("Enter Student' name : ");
                gets(s1.name);
                fflush(stdin);

                gotoxy(10, 8);
                printf("Enter Phone No : ");
                gets(s1.phoneNo);

                gotoxy(10, 9);
                printf("Enter Roll no : ");
                scanf("%d", &s1.rollNo);
                fflush(stdin);

                gotoxy(10, 10);
                fflush(stdin);
                printf("Enter Course : ");
                gets(s1.course);
                fflush(stdin);

                gotoxy(10, 11);
                printf("Enter Branch : ");
                gets(s1.branch);

                fseek(fptr, -sizeof(s1), SEEK_CUR);
                fwrite(&s1, sizeof(s1), 1, fptr);
                break;
            }
        }
        fclose(fptr);
        gotoxy(10, 15);
        printf("Press any key to continue..");
        getch();
        mainMenu();
    }
}

void deleteRecord(){
    char name[20];
    FILE *fptr= NULL, *fptr1= NULL;
    struct student s1;
    system("cls");

    gotoxy(10, 3);
    printf("** Delete Record **");

    gotoxy(10, 5);
    printf("Enter name of student to delete record : ");
    fflush(stdin);
    gets(name);

    fptr= fopen("record.txt", "rb+");
    if(fptr== NULL){
        printf("!File is not opened.");
        exit(1);
    }else{
        fptr1= fopen("temp.txt", "wb+");
        if(fptr1== NULL){
            printf("!File is not opened");
            exit(1);
        }else{
            while(fread(&s1, sizeof(s1), 1, fptr)== 1){
                if(strcmp(name, s1.name)!= 0){
                    fwrite(&s1, sizeof(s1), 1, fptr1);
                }
            }
            fclose(fptr);
            fclose(fptr1);
            remove("record.txt");
            rename("temp.txt", "record.txt");

            gotoxy(10, 10);
            printf("* Record Successfully Deleted *");

            gotoxy(10, 15);
            printf("Press any key to continue....");
            getch();
            mainMenu();
        }
    }
}