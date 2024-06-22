#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>




void login();
void newacc();
void fpass();
void clear();
void addrec();
void remrec();
void listrec();
void Modify();

struct inventory
{
    char Item[50];
    int  Quantity;
    float rate;
    float  Total;

}godam;



struct signup
{
    char uname[50];
    char pass[20];
    unsigned long long int ph;
}sform;

 FILE *fp,*ft;

int main()
{
    int log ,sign, choice;
   
    fp=fopen("signup.txt","a+");
    ft=fopen("Inventorylist.txt","a+");
    if(fp==NULL)
	{
		puts("FILE CANNOT OPEN");
		exit(0);
	}
    if(ft==NULL)
    {
        puts("File Cannot Open");
        exit(0);
    }    
    re:
    clear();
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
        newacc();
        break;

        case 2:
        login();
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

void newacc()
{
    char repass[20];
    reform:
    clear();
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
    scanf("%lld",&sform.ph);
    
    if(strcmp(sform.pass,repass)!=0)
    {
        printf("The password donot match.Please re-enter.");
        printf("\n\n\n\n \t\t Press any key to continue...");
        getchar();

        goto reform;
    }
    fwrite(&sform,sizeof(sform),1,fp);
    printf("\n \n SIGNUP SUCESSFULL.  WELCOME !!!");
    printf("\n\n \t\t Press any key to continue... \n");
    getchar;

    
}

void login()
{
    
    int i=0,n=0, choice,passforget;
    char inp_Name[50],inp_Pass[20],ch;
    relog:
    clear();
    printf("\n========================= Login Form ======================\n");
    fflush(stdin);
    printf("User_Name: \n");
    fgets(inp_Name,sizeof(inp_Name),stdin);
    fflush(stdin);
    printf("Password:  \n");
    fflush(stdin);
    fgets(inp_Pass,sizeof(inp_Pass),stdin);
    fread(&sform,sizeof(sform),1,fp);
    rewind(fp);
    while (fread(&sform,sizeof(sform),1,fp)==1)
    {
  
    

    
        if(strcmp(sform.pass,inp_Pass)==0 && strcmp(sform.uname,inp_Name)!=0);
        {
            n++;
            printf("Incorrect Password or User_Name. Please try again.  ");
            if (n>3)
            {   
                getchar();
                clear();
                printf("====================================================");
                printf("1.  Forgot Password");
                printf("2.  Retry");
                printf("3.  Exit");
                printf("Enter your choice :");
                scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                fpass();
                break;
                




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
            else
            {
        
                printf(" \n\n\n WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
                printf("\n\n\n\t\t\t\tPress any key to continue...");
                getchar();
                goto relog;
            }

        }
    }
}    


void fpass()
{
    char fname[50],fpsw[20];
    unsigned long long int fph;
    forget:
    clear();
    printf("=========================== Password Change Form ==================================");
    printf("User_Name:");
    fflush(stdin);
    fgets(fname,sizeof(fname),stdin);
    printf("Contact number:");
    fflush(stdin);
    scanf("%lld",&fph);
    rewind(fp);
  
        while(fread(&sform,sizeof(sform),1,fp)==1)
        {

            if(strcmp(fname,sform.uname)==0 && sform.ph==fph)
            {
                printf("Password:");
                fgets(sform.pass,sizeof(sform),stdin);
                printf("Conform_password:");
                fgets(fpsw,sizeof(fpsw),stdin);
                if(strcmp(fpsw,sform.pass)==0)
                {
                    fwrite(&sform,sizeof(sform),1,fp);
                    printf("Passeord changed sucessfully");
                    getchar();
                }
                else
                {
                    printf("Both password donot match ");
                    printf("Redirecting to Change passeord form");
                    goto forget;

                }
                

            }
            else
            {
                printf("your Username or Details do not match. Redirecting to change passord form.");
                goto forget;

            }

        }
}
void clear()
{
    system("cls");
}

void addrec()
{
    char option;
    rewind(ft);
    clear();
    readd:
    printf("================ Item Page ===============\n");
    printf(" Item_Name : \n");
    fgets(godam.Item,sizeof(godam.Item),stdin);
    fflush(stdin);
    printf(" Quantity :\n");
    scanf("%d",godam.Quantity);
    fflush(stdin);
    printf(" Price :\n");
    scanf("%f",godam.rate);
    getchar();
    fwrite(&godam,sizeof(godam),1,ft);
    printf("Do you want to add more item? (Y/N)\n");
    fgets(&option,sizeof(option),stdin);
    toupper(option);
    if (option=='Y')
    {
        goto readd;
    }



}


void listrec()
{
    rewind(ft);
    while(fread(&godam,sizeof(godam),1,ft)==1)
    {
        print("Name: \t\t\t Price: \t\t\t  Quantity: \t\t\t Total: \t\t\t\n");
        godam.Total=godam.rate*godam.Quantity;
        printf(" %s \t\t\t .2%f \t\t\t %d \t\t\t\n ");
    }
}

void Modify()
{


}

void remrec()
{


}