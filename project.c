#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>



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

 FILE *fp,*ft,*rt;

int main()
{
    int log ,sign, choice;
    re:
    clear();
    printf("\n========================= WELCOME  =========================");
    printf("\n      1. Signup \n");
    printf("\n      2. Login \n");
    printf("\n      3. Exit\n");
    printf("\n  Enter your choice \n ");
    scanf("%d",&choice);
    fflush(stdin);
    switch(choice)
    {
        case 1:
        newacc();
        goto re;
        break;

        case 2:
        login();
        break;

        case 3:
        printf("====================== Thankyou For Your Time====================\n");
        exit(0);

        deafult:
        printf("The input is incorrect. Please input the number of the choices\n");
        goto re;
    }

    return 0;




}

void newacc()
{
    fp=fopen("signup.txt","a+");
    if(fp==NULL)
    {
        puts("File Cannot Open");
        exit(0);
    }   
    char repass[20];
    reform:
    clear();
    printf("========================= Signup Form =====================");
    printf("\n User_name:  ");
    fflush(stdin);
    fgets(sform.uname,sizeof(sform.uname),stdin);
    printf(" \nPassword : ");
    fflush(stdin);
    fgets(sform.pass,sizeof(sform.pass),stdin);
    printf("\nConform_password:");
    fflush(stdin);
    fgets(repass,sizeof(repass),stdin);
    fflush(stdin);
    printf("\nPhone_number:\n");
    scanf("%lld",&sform.ph);
    
    if(strcmp(sform.pass,repass)!=0)
    {
        printf("The password donot match.Please re-enter.\n");
        printf("\n\n\n\n \t\t Press any key to continue...");
        getchar();

        goto reform;
    }
    else
    {
        fwrite(&sform,sizeof(sform),1,fp);
        printf("\n \n SIGNUP SUCESSFULL.  WELCOME !!!\n");
        printf("\n\n \t\t Press any key to continue... \n");
        getchar;
    }
    fclose(fp);
    
}

void login()
{

    fp=fopen("signup.txt","a+");
    if(fp==NULL)
    {
        puts("File Cannot Open");
        exit(0);
    }   
    
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
    
    rewind(fp);
    while (fread(&sform,sizeof(sform),1,fp)==1)
    {
  
    

    
        if(strcmp(sform.pass,inp_Pass)!=0 || strcmp(sform.uname,inp_Name)!=0)
        {
            n++;
            printf("Incorrect Password or User_Name. Please try again.  \n");
            if (n>3)
            {   
                getchar();
                clear();
                printf("====================================================\n");
                printf("1.  Forgot Password\n");
                printf("2.  Retry\n");
                printf("3.  Exit\n");
                printf("Enter your choice :\n");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                    fpass();
                    break;
                




                    case 2:
                    goto relog;

                    case 3:
                    printf("=====================Thankyou for your Time ==========\n");
                    exit(0);

                    default:
                    printf("-------------------Invalid Input-----------------------\n");
                    printf("Redirecting");
                    fflush(stdout);
                    usleep(10000);
                    printf(".");
                    usleep(10000);
                    printf(".");
                    usleep(10000);
                    printf(".");
                    goto relog;
                }

            }
            goto relog;

        }
        else
        {
        
            printf(" \n\n\n WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
            printf("\n\n\n\t\t\t\tRedirecting");
            fflush(stdout);
            usleep(10000);
            printf(".");
            usleep(10000);
            printf(".");
            usleep(10000);
            printf(".");
           
            
        }
    }
    fclose(fp);
}    


void fpass()
{
    fp=fopen("signup.txt","a+");
    if(fp==NULL)
    {
        puts("File Cannot Open");
        exit(0);
    }   
    char fname[50],fpsw[20];
    unsigned long long int fph;
    forget:
    clear();
    printf("=========================== Password Change Form ==================================\n");
    printf("User_Name:\n");
    fflush(stdin);
    fgets(fname,sizeof(fname),stdin);
    printf("Contact number:\n");
    fflush(stdin);
    scanf("%lld",&fph);
    rewind(fp);
        while(fread(&sform,sizeof(sform),1,fp)==1)
        {

            if(strcmp(fname,sform.uname)==0 && sform.ph==fph)
            {
                printf("Password:\n");
                fflush(stdin);
                fgets(sform.pass,sizeof(sform),stdin);
                printf("Conform_password:\n");
                fflush(stdin);
                fgets(fpsw,sizeof(fpsw),stdin);
                if(strcmp(fpsw,sform.pass)==0)
                {
                    fwrite(&sform,sizeof(sform),1,fp);
                    printf("Password changed sucessfully\n");
                    getchar();
                }
                else
                {
                    printf("Both password donot match \n");
                    printf("Redirecting");
                    fflush(stdout);
                    usleep(10000);
                    printf(".");
                    usleep(10000);
                    printf(".");
                    usleep(10000);
                    printf(".");
                    goto forget;

                }
                

            }
            else
            {
                printf("Your Username or Details do not match. Redirecting to change passord form....\n");
                goto forget;

            }

        }
        fclose(fp);
}
void clear()
{
    system("cls");
}

void addrec()
{

    ft=fopen("Inventorylist.txt","a+");
    if(ft==NULL)
	{
		puts("FILE CANNOT OPEN");
		exit(0);
	}
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

    fclose(ft);

}


void listrec()
{

    ft=fopen("Inventorylist.txt","a+");
    if(ft==NULL)
	{
		puts("FILE CANNOT OPEN");
		exit(0);
	}
    rewind(ft);
    clear();
    printf("========== Item List ============\n");
    while (fread(&godam,sizeof(godam),1,ft)==1)
    {
        godam.total=godam.Quantity*godam.rate;
        printf("\nItem Name: \t\t Quantity: \t\t Price: \t\t Total Value: \t\n");
        printf("%s \t\t %d \t\t .2%f \t\t %f\t\t\n");
    }
    
    fclose(ft);
}


void Modify()
{

    ft=fopen("Inventorylist.txt","a+");
    if(ft==NULL)
	{
		puts("FILE CANNOT OPEN");
		exit(0);
	}
    int opt;
    char name[50],ch;
    clear();
    rewind(fp);
    remodify:
    printf("================ Modification Menu ============\n");
    printf("1.Quantity \t\t\n 2.Price\t\t\n 3.Exit\n");
    switch(opt)
    {
        case 1:
        printf("Enter the Name of product: \n");
        fflush(stdin);
        fgets(name,sizeof(name),stdin);
        while (fread(&godam,sizeof(godam),1,ft)==1);
        {
            if(strcmp(godam.Item,name)==0)
            {
                printf("Enter New Quantity: \n");
                scanf("%d",godam.Quantity);
                fseek(fp,-sizeof(godam),SEEK_CUR);
                fwrite(&godam,sizeof(godam),1,ft);
                break;
            }    
        }
        printf("DO you want to Modify more Quantity? (Y/N)\n");
        fflush(stdin);
        scanf("%c",&ch);
        ch=toupper(ch);
        if(ch=="Y")
        {
            goto remodify;
        }
        break;

        case 2:
        printf("Enter the Name of product\n");
        fflush(stdin);
        fgets(name,sizeof(name),stdin);
        while (fread(&godam,sizeof(godam),1,ft)==1);
        {
            if(strcmp(godam.Item,name)==0)
            {
                printf("Enter New Prce: \n");
                scanf("%d",godam.rate);
                fseek(fp,-sizeof(godam),SEEK_CUR);
                fwrite(&godam,sizeof(godam),1,ft);
                break;
            }    
        }
        printf("DO you want to Modify more Price? (Y/N)\n");
        fflush(stdin);
        scanf("%c",&ch);
        toupper(ch);
        if(ch=="Y")
        {
            goto remodify;
        }
        break;

        case 3:
        exit(0);

        default:
        printf("Invalid inpt. Redirecting");
        fflush(stdout);
        usleep(10000);
        printf(".");
        usleep(10000);
        printf(".");
        usleep(10000);
        printf(".");
        
        goto remodify;

    }

    fclose(ft);    
}

void remrec()
{
    char itemname[50];
    char option;
    rt=fopen("Tempinventory.txt","a+");
    ft=fopen("Inventorylist.txt","a+");
    if(ft==NULL)
    {
        printf("File not found!!!");
        exit(0);
    }
    reremove:
    printf(" Item Name:\n");
    fflush(stdin);
    fgets(itemname,sizeof(itemname),stdin);
    while(fread(&godam,sizeof(godam),1,ft)==1)
    {
        if(strcmp(itemname,godam.Item)!=0)
        {
            fwrite(&godam,sizeof(godam),1,rt);
        }
    }
    fclose(rt);
    fclose(ft);
    remove("Inventorylist.txt");
    rename("Tempinventory.txt","Inventorylist.txt");
    printf("Do you want to remove more Items.(Y/N) ");
    scanf("%c",&option);
    if (option=='Y')
    {
        goto reremove;
    }
}