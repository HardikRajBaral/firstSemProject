#include<stdio.h>
#include<string.h>
#include<stdlib.h>




void login();
void newacc();
void fpass();


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
    if(fp==NULL)
		{
			puts("FILE CANNOT OPEN");
			exit(0);
		}
    

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
    printf("\n========================= Login Form ======================\n");
    fflush(stdin);
    printf("User_Name: \n");
    fgets(inp_Name,sizeof(inp_Name),stdin);
    fflush(stdin);
    printf("Password:  \n");
    fflush(stdin);
    fgets(inp_Pass,sizeof(inp_Pass),stdin);
    fread(&sform,sizeof(sform),1,fp);

    
    if(strcmp(sform.pass,inp_Pass)==0 && strcmp(sform.uname,inp_Name)!=0);
    {
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
    
            printf(" \n\n\n WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
            printf("\n\n\n\t\t\t\tPress any key to continue...");
            getchar();
   

    
        goto relog;
    
    }
}    


void fpass()
{
    char fname[50],fpsw;
    unsigned long long int fph;
    forget:
    printf("=========================== Password Change Form ==================================");
    printf("User_Name:");
    fflush(stdin);
    fgets(fname,sizeof(fname),stdin);
    printf("Contact number:");
    fflush(stdin);
    scanf("%lld",&fph);
  
        while(fread(&sform,sizeof(sform),1,fp)==1)
        {

            if(strcmp(fname,sform.uname)==0 && sform.ph==fph)
            {
                printf("Password:");
                fgets(sform.ph,sizeof(sform),stdin);
                printf("Conform_password:");
                scanf(&fpsw,sizeof(fpsw),stdin);
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