#include<stdio.h>
#include<string.h>
#include<stdlib.h>




int login();
int newacc();
int fpass();


struct signup
{
    char uname[50];
    char pass[20];
    long long int ph;
}sform;



int main()
{
    int log ,sign, choice;
    //menu
    re:
    printf("\n========================= WELCOME  =========================");
    printf("\n      1. Signup ");
    printf("\n      2. Login ");
    printf("\n      3. Exit");
    printf("\n  Enter your choice  ");
    scanf("%d",&choice);
    fflush(stdin);
    switch(choice)
    {
        case 1:
        log=newacc();
        break;

        case 2:
        sign=login();
        break;

        case 3:
        printf("====================== Thankyou For Your Time====================");
        exit(0);

        deafult:
        printf("The input is incorrect. Please input the number of the choices");
        goto re;
    }

    return 0;




}

int newacc()
{
    char repass[20];
    reform:
    printf("========================= Signup Form =====================");
    printf("\n User_name:  \n");
    fflush(stdin);
    fgets(sform.uname,sizeof(sform.uname),stdin);
    printf(" Password : \n");
    fflush(stdin);
    fgets(sform.pass,sizeof(sform.pass),stdin);
    printf("Conform_password:\n");
    fflush(stdin);
    fgets(repass,sizeof(repass),stdin);
    fflush(stdin);
    printf("Phone_number:\n");
    scanf("%lld",sform.ph);
    if(strcmp(sform.pass,repass)!=0)
    {
        printf("The password donot match.Please re-enter.");
        printf("\n\n\n\n \t\t Press any key to continue...");
        getchar();

        goto reform;
    }
    printf("\n \n SIGNUP SUCESSFULL.  WELCOME !!!");
    printf("\n\n \t\t Press any key to continue... \n");
    getchar;

    return 1;
}

int login()
{
    
    int i=0,n=0, choice,passforget;
    char inp_Name[50],inp_Pass[20],ch;
    relog:
    printf("\n========================= Login Form ======================\n");
    fflush(stdin);
    printf("User_Name: \n");
    fgets(inp_Name,sizeof(inp_Name),stdin);
    fflush(stdin);
    printf("Password:  \n");
    fflush(stdin);
    fgets(inp_Pass,sizeof(inp_Pass),stdin);

        /*printf("\nLoading");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".");
        Sleep(1000);*/
    if(strcmp(sform.pass,inp_Pass)==0 && strcmp(sform.uname,inp_Name)==0);
    {
        printf(" \n\n\n WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
        printf("\n\n\n\t\t\t\tPress any key to continue...");
        getchar();
        
        return 1;
    }
    n++;
    printf("Incorrect Password or User_Name. Please try again.  ");
    if (n>3)
    {
        getchar();
        printf("====================================================");
        printf("1.  Forgot Password");
        printf("2.  Retry");
        printf("3.  Exit");
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            passforget=fpass();




            case 2:
            goto relog;

            case 3:
            printf("=====================Thankyou for your Time ==========");
            exit(0);

            default:
            printf("-------------------Invalid Input-----------------------");
            goto relog;


        }

    }
    goto relog;
    
}


