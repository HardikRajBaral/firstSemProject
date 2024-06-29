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
    int log ,sign, choice,n;
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
        printf("====================== Thankyou For Your Time ====================\n");
        exit(0);

        deafult:
        printf("The input is incorrect. Please input the number of the choices\n");
        goto re;
    }
    clear();
    printf("Loading");
    fflush(stdout);
    usleep(10000);
    printf(".");
    usleep(10000);
    printf(".");
    usleep(10000);
    printf(".");
    while(1)
    {
    
        clear();
        printf("===================== Inventory Management System =========================\n");
        printf(" 1.Add Item \n 2.List Item \n 3.Modify Item\n 4.Delete Item\n 5.Exit");
        printf("\nEnter your Choice: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            addrec();
            
            case 2:
            listrec();
            
            case 3:
            Modify();
            

            case 4 :
            remrec();
            

            case 5:
            printf("------------------Thankyou For Your Time ------------------");
            exit(0);

            default:
            printf("Invalid Input. Reidrecting to Home");
            
        }

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
    while(1)
    {
        unsigned long long int temp;
        int count;
        label:
        clear();
        printf("========================= Signup Form =====================");
        printf("\n User_name:  ");
        fflush(stdin);
        fgets(sform.uname,sizeof(sform.uname),stdin);
        sform.uname[strcspn(sform.uname, "\n")] = 0; 
        printf(" \nPassword : ");
        fflush(stdin);
        fgets(sform.pass,sizeof(sform.pass),stdin);
        sform.pass[strcspn(sform.pass, "\n")] = 0; 
        printf("\nConfirm_password:");
        fflush(stdin);
        fgets(repass,sizeof(repass),stdin);
        repass[strcspn(repass,"\n")]=0;
        printf("(Phone number should be exactly 10 digits.\n)");
        fflush(stdin);
        printf("\nPhone_number:\n");
        scanf("%lld",&sform.ph);
        temp=sform.ph;
        while(temp!=0)
        {
            temp=temp/10;
            count++;

            
        }
        if(count!=10)
        {
            printf("Phone number does not meet the requriement.");
            goto label;
        }
        
        if(strcmp(sform.pass,repass)!=0)
        {
            printf("The password donot match.Please re-enter.\n");
            printf("\n\n\n\n \t\t Press any key to continue...");
            getchar();
        }
        else
        {
            fwrite(&sform,sizeof(sform),1,fp);
            printf("\n \n SIGNUP SUCESSFULL.  WELCOME !!!\n");
            printf("\n\n \t\t Press any key to continue... \n");
            getchar();
            break;
        }
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
    while(1)
    {
        int found;
        relog:
        clear();
        printf("\n========================= Login Form ======================\n");
        fflush(stdin);
        printf("User_Name: \n");
        fgets(inp_Name,sizeof(inp_Name),stdin);
        inp_Name[strcspn(inp_Name, "\n")] = 0; 
        fflush(stdin);
        printf("Password:  \n");
        fflush(stdin);
        fgets(inp_Pass,sizeof(inp_Pass),stdin);
        inp_Pass[strcspn(inp_Pass, "\n")] = 0; 
        rewind(fp);
        while (fread(&sform,sizeof(sform),1,fp)==1)
        {
            if(strcmp(sform.pass,inp_Pass)==0 && strcmp(sform.uname,inp_Name)==0)
            {
                found=1;
                break;
                
            }
        }    
        if(found==1)
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
            break;
        }    
        else
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
    int found;
    clear();
    printf("=========================== Password Change Form ==================================\n");
    printf("User_Name:\n");
    fflush(stdin);
    fgets(fname,sizeof(fname),stdin);
    fname[strcspn(fname, "\n")] = 0; 
    printf("Contact number:\n");
    fflush(stdin);
    scanf("%lld",&fph);
    rewind(fp);
        while(fread(&sform,sizeof(sform),1,fp)==1)
        {

            if(strcmp(fname,sform.uname)==0 && sform.ph==fph)
            {
                found=1;
            }
             

        }
        if(found==1)
        {
              printf("New_Password:\n");
                fflush(stdin);
                fgets(sform.pass,sizeof(sform),stdin);
                sform.pass[strcspn(sform.pass ,"\n")] = 0; 
                printf("Confirm_password:\n");
                fflush(stdin);
                fgets(fpsw,sizeof(fpsw),stdin);
                fpsw[strcspn(fpsw, "\n")] = 0; 
                if(strcmp(fpsw,sform.pass)==0)
                {
                    fseek(fp,-sizeof(godam),SEEK_CUR);
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
    while(1)
    {
        
        clear();
        readd:
        printf("================ Item Page ===============\n");
        printf(" Item_Name : \n");
        fgets(godam.Item,sizeof(godam.Item),stdin);
        godam.Item[strcspn(godam.Item, "\n")] = 0;
        fflush(stdin);
        printf(" Quantity :\n");
        scanf("%d",&godam.Quantity);
        fflush(stdin);
        printf(" Price :\n");
        scanf("%f",&godam.rate);
        fwrite(&godam,sizeof(godam),1,ft);
        fflush(stdin);
        printf("Do you want to add more item? (Y/N)\n");
        fgets(&option,sizeof(option),stdin);
        //option=toupper(option);
        option=getchar();
        while(option!='\n')
        {
            
            if (option= 'N')
            {
                return;
            }

        }

    }

    fclose(ft);

}


void listrec()
{

    ft=fopen("Inventorylist.txt","r");
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
        godam.Total=godam.Quantity*godam.rate;
        printf("\nItem Name: \t\t Quantity: \t\t Price: \t\t Total Value: \t\n");
        printf("%s \t\t %d \t\t .2%f \t\t %f\t\t\n",godam.Item,godam.Quantity,godam.rate,godam.Total);
    }
    printf("Thankyou  For visiting ");
    fflush(stdout);
    usleep(10000);
    printf(".");
    usleep(10000);
    printf(".");
    usleep(10000);
    printf(".");
    
    fclose(ft);
}

void Modify()
{

    ft=fopen("Inventorylist.txt","a+");
    if(ft==NULL)
	{
		puts("FILE CANNOT OPEN\n");
		exit(0);
	}
    int opt;
    char name[50],ch;
    while(1)
    {
        clear();
        rewind(ft);
        
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
                    scanf("%d",&godam.Quantity);
                    fseek(ft,-sizeof(godam),SEEK_CUR);
                    fwrite(&godam,sizeof(godam),1,ft);
                    break;
                }    
            }
            printf("DO you want to Modify more Quantity? (Y/N)\n");
            fflush(stdin);
            scanf("%c",&ch);
            ch=toupper(ch);
            if(ch='N')
            {
                return;
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
                    printf("Enter New Price: \n");
                    scanf("%d",&godam.rate);
                    fseek(ft,-sizeof(godam),SEEK_CUR);
                    fwrite(&godam,sizeof(godam),1,ft);
                    break;
                }    
            }
            printf("DO you want to Modify more Price? (Y/N)\n");
            fflush(stdin);
            scanf("%c",&ch);
            ch=toupper(ch);
            if(ch=='N')
            {
                return;
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

        }
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
    while(1)
    {

        printf(" Item Name:\n");
        fflush(stdin);
        fgets(itemname,sizeof(itemname),stdin);
        itemname[strcspn(itemname, "\n")] = 0; 
        while(fread(&godam,sizeof(godam),1,ft)==1)
        {
            if(strcmp(itemname,godam.Item)!=0)
            {
                fwrite(&godam,sizeof(godam),1,rt);
            }
        }
        remove("Inventorylist.txt");
        rename("Tempinventory.txt","Inventorylist.txt");
        printf("Do you want to remove more Items.(Y/N) ");
        fflush(stdin);
        scanf("%c",&option);
        if (option=='N')
        {
            return;
        }
    }
    fclose(rt);
    fclose(ft);
}