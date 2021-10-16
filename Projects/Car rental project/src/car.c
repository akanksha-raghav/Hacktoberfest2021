#include <stdio.h>
#include <string.h>
#include "conio2.h"
#include "car.h"
#include <time.h>
void addAdmin()
{
    FILE *fp=fopen("admin.bin","rb");
    if(fp==NULL)
    {
        fp=fopen("admin.bin","wb");
        User u[2]={{"admin","test","ravi"},{"super","demo","anil"}};
        fwrite(u,sizeof(u),1,fp);

    }
    fclose(fp);
}

void permanentemployee()
{
    FILE *fp=fopen("emp.bin","rb");
    if(fp==NULL)
    {
        fp=fopen("emp.bin","wb");
        User u[2]={{"Emp-1","ayush","ayush"},{"Emp-2","test","test"}};
        fwrite(u,sizeof(u),1,fp);
    }
    fclose(fp);
}
User* getInput()
{
    int i;
    clrscr();
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<=80;i++)
        printf("%c",247);

    gotoxy(32,5);
    printf("* LOGIN PANEL *");

    gotoxy(1,7);
    textcolor(LIGHTCYAN);
    for(i=1;i<=80;i++)
        printf("%c",247);

    gotoxy(1,15);
    for(i=1;i<=80;i++)
      printf("%c",247);

    gotoxy(60,8);
    textcolor(WHITE);
    printf("Press 0 to exit");
    textcolor(LIGHTCYAN);
    gotoxy(25,10);
    printf("Enter Userid:");
    textcolor(WHITE);
    static User u;
    fflush(stdin);
    fgets(u.userid,20,stdin);
    char *pos;
    pos=strchr(u.userid,'\n');
    if(pos!=NULL)
    {
        *pos='\0';
    }
    if(strcmp(u.userid,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(30,17);
        printf("Login Cancelled");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    textcolor(LIGHTCYAN);
    gotoxy(25,11);
    printf("Enter Password:");
    fflush(stdin);
    i=0;
    textcolor(WHITE);
    for(;;)
    {
        u.pwd[i]=getch();
        if(u.pwd[i]==13)
        {
            break;
        }
        printf("*");
        if(u.pwd[i]==8)
        {
            printf("\b\b  \b\b");
            i=i-2;
        }
        i++;
    }
    u.pwd[i]='\0';
    if(strcmp(u.pwd,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(30,17);
        printf("Login cancelled");
        getch();
        textcolor(YELLOW);
        return NULL;
    }

    getch();
    return &u;


}
int checkUserExist(User u,char *usertype)
{
    if(strlen(u.userid)==0|| strlen(u.pwd)==0)
    {
        gotoxy(28,20);
        textcolor(LIGHTRED);
        printf("Both fields are mandatory. Try again");
        getch();
        gotoxy(28,20);
        printf("\t\t\t\t\t\t\t\t\t");
        return 0;
    }
    FILE *fp;
    if(strcmp(usertype,"admin")==0)
    {
       fp=fopen("admin.bin","rb");
    }
    else
    {
        fp=fopen("emp.bin","rb");
    }
    if(fp==NULL)
    {
         gotoxy(28,20);
        textcolor(LIGHTRED);
        printf("Sorry! cannot open the file");
        getch();
        gotoxy(28,20);
        printf("\t\t\t\t\t\t\t\t\t");
        return -1;
    }
    int found=0;
    User user;
    while(fread(&user,sizeof(user),1,fp)==1)
    {
        if(strcmp(u.userid,user.userid)==0&&strcmp(u.pwd,user.pwd)==0)
        {
            found=1;
            break;
        }
    }
    if(found==0)
    {
        gotoxy(28,20);
        textcolor(LIGHTRED);
        printf("invalid userid/password. Try again");
        getch();
        gotoxy(28,20);
        printf("\t\t\t\t\t\t\t\t\t");

    }
    else
    {
        gotoxy(28,20);
        textcolor(LIGHTGREEN);
        printf("LOGIN SUCCESSFULL!");
        getch();
        gotoxy(28,20);
        printf("\t\t\t\t\t\t\t\t\t");

    }
    fclose(fp);
    return found;

}

int adminMenu()
{
    int i,choice;
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGREEN);
    gotoxy(35,6);
    printf("ADMIN MENU\n");
    for(i=1;i<=80;i++)
    {
        printf("*");
    }
    textcolor(YELLOW);
    gotoxy(32,8);
    printf("1. Add Employee");
    gotoxy(32,9);
    printf("2. Add Car Details");
     gotoxy(32,10);
    printf("3. Show Employee");
     gotoxy(32,11);
    printf("4. Show car Details");
     gotoxy(32,12);
    printf("5. Delete Employee");
     gotoxy(32,13);
    printf("6. Delete Car Details");
     gotoxy(32,14);
    printf("7. Exit");
     gotoxy(32,16);
    printf(" Enter Choice:");
    textcolor(WHITE);
    scanf("%d",&choice);
    return choice;


}

/*void addEmployee()
{
    char empid[10]={"EMP-"};
    char temp[10];
    char choice;
    User u;
    FILE *fp=fopen("emp.bin","ab+");
    fseek(fp,0,SEEK_END);
    long total_rec=ftell(fp)/sizeof(User);
    total_rec++;
    sprintf(temp,"%d",total_rec);
    strcat(empid,temp);
    strcpy(u.userid,empid);

    do
    {

        clrscr();
        gotoxy(32,2);
        textcolor(LIGHTRED);
        printf("CAR RENTAL APP");
        textcolor(LIGHTGREEN);
        int i;
        gotoxy(1,3);
        for(i=0;i<=80;i++)
            printf("~");
        textcolor(WHITE);
        gotoxy(25,5);
        printf("***** Add Employee Details *****");
        gotoxy(1,8);
        textcolor(YELLOW);
        printf("Enter Employee Name:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.name,20,stdin);
        char *pos;
        pos=strchr(u.name,'\n');
        if(pos!=NULL)
        {
            *pos='\0';
        }
        textcolor(YELLOW);
        printf("Enter Employee Pwd:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.pwd,20,stdin);
        pos=strchr(u.pwd,'\n');
        if(pos!=NULL)
        {
            *pos='\0';
        }
        fwrite(&u,sizeof(u),1,fp);
        gotoxy(30,15);
        textcolor(LIGHTGREEN);
        printf("EMPLOYEE ADDED SUCCESSFULLY!");
        printf("\n EMPLOYEE ID is %s",u.userid);
        getch();

        gotoxy(1,20);
        textcolor(LIGHTRED);
        printf("Do you want to add more employees(Y/N)?");
        textcolor(WHITE);
        fflush(stdin);
        scanf("%c",&choice);
        if(choice=='N')
           break;
        total_rec++;
        sprintf(u.userid,"EMP-%d",total_rec);



    }while(1);
    fclose(fp);
}*/

void addEmployee()
{
    char choice;
    char temp[10];
    char *pos;
    User u;
    FILE *fp=fopen("emp.bin","ab+");
    fseek(fp,0,SEEK_END);
    long total_rec=ftell(fp)/sizeof(User);
    if(total_rec!=0)
    {
        fseek(fp,-60,SEEK_END);
        fread(temp,sizeof(temp),1,fp);
        printf("temp is %s",temp);
        getch();
        pos=strchr(temp,'-');
        total_rec=atoi(pos+1);
        printf("\ntotal rec is %d",total_rec);
        getch();

    }
    total_rec++;
    sprintf(u.userid,"Emp-%d",total_rec);
    fseek(fp,0,SEEK_END);
    do
    {
      clrscr();
      gotoxy(32,2);
      textcolor(LIGHTRED);
      printf("CAR RENTAL APP");
      textcolor(LIGHTGREEN);
      int i;
      gotoxy(1,3);
      for(i=1;i<=80;i++)
        printf("~");
      textcolor(WHITE);
      gotoxy(25,5);
      printf("***** ADD EMPLOYEE DETAILS *****");
      gotoxy(1,8);
      textcolor(YELLOW);
      printf("Enter Employee Name:");
      fflush(stdin);
      textcolor(WHITE);
      fgets(u.name,20,stdin);
      char *pos;
      pos=strchr(u.name,'\n');
      if(pos!=NULL)
      {
          *pos='\0';
      }
      textcolor(YELLOW);
      printf("Enter Employee pwd:");
      fflush(stdin);
      textcolor(WHITE);
      fgets(u.pwd,20,stdin);
      pos=strchr(u.pwd,'\n');
      if(pos!=NULL)
      {
          *pos!='\0';
      }
      fwrite(&u,sizeof(u),1,fp);
      gotoxy(30,15);
      textcolor(LIGHTGREEN);
      printf("EMPLOYEE ADDED SUCCESSFULLY!");
      printf("\nEMPLOYEE ID is %s",u.userid);
      getch();
      gotoxy(1,20);
      textcolor(LIGHTRED);
      printf("Do you want to add more employees (Y/N)?");
      textcolor(WHITE);
      fflush(stdin);
      scanf("%c",&choice);
      if(choice=='N')
        break;
      total_rec++;
      sprintf(u.userid,"EMP-%d",total_rec);

    }while(1);
    fclose(fp);

}

void addCarDetails()
{

    char choice;
    Car c;
    FILE *fp=fopen("car.bin","ab+");
    fseek(fp,0,SEEK_END);
    int total_rec=ftell(fp)/sizeof(Car);
    total_rec++;
    c.car_id=total_rec;

    do
    {

        clrscr();
        gotoxy(32,2);
        textcolor(LIGHTRED);
        printf("CAR RENTAL APP");
        textcolor(LIGHTGREEN);
        int i;
        gotoxy(1,3);
        for(i=0;i<=80;i++)
            printf("~");
        textcolor(WHITE);
        gotoxy(25,5);
        printf("***** ADD CAR DETAILS *****");
        gotoxy(1,8);
        textcolor(YELLOW);
        printf("Enter Car Model:");
        fflush(stdin);

        textcolor(WHITE);
        fgets(c.car_name,50,stdin);
        char *pos;
        pos=strchr(c.car_name,'\n');
        if(pos!=NULL)
        {
            *pos='\0';
        }
        textcolor(YELLOW);
        printf("Enter Car Capacity:");
        fflush(stdin);
        textcolor(WHITE);
        scanf("%d",&c.capacity);
        textcolor(YELLOW);
        printf("Enter Car Count:");
        textcolor(WHITE);
        scanf("%d",&c.car_count);
        textcolor(YELLOW);
        printf("Enter Car price for per day:");
        textcolor(WHITE);
        scanf("%d",&c.price);


        fwrite(&c,sizeof(c),1,fp);
        gotoxy(30,15);
        textcolor(LIGHTGREEN);
        printf("CAR ADDED SUCCESSFULLY!");
        printf("\n CAR ID is %d",c.car_id);
        getch();

        gotoxy(1,20);
        textcolor(LIGHTRED);
        printf("Do you want to add more Cars(Y/N)?");
        textcolor(WHITE);
        fflush(stdin);
        scanf("%c",&choice);
        if(choice=='N')
           break;
        total_rec++;
        c.car_id=total_rec;




    }while(1);
    fclose(fp);
}


/*
void viewEmployee()
{
    clrscr();
    User u;
    FILE *fp;
    fp=fopen("emp.bin","rb");
    if(fp==NULL)
    {
        printf("Sorry! Cannot open the file");
        return 1;
    }

        clrscr();
        gotoxy(32,2);
        textcolor(LIGHTRED);
        printf("CAR RENTAL APP");
        textcolor(YELLOW);
        int i;
        gotoxy(1,3);
        for(i=0;i<=80;i++)
            printf("%c",247);
        textcolor(WHITE);
        gotoxy(28,6);
        printf("***** Employee Details *****");
        gotoxy(1,10);
        textcolor(LIGHTGREEN);
         for(i=0;i<=80;i++)
            printf("%c",247);


         gotoxy(2,12);
         printf("\tEMPLOYEE ID\t\t\t");

         printf("NAME\t\t\t");
         printf("PASSWORD");
         gotoxy(1,14);
         for(i=0;i<=80;i++)
            printf("%c",247);
        textcolor(YELLOW);
        while( fread(&u,sizeof(User),1,fp)==1)
        {
            printf("\n");
            printf("\t%s\t\t\t\t",u.userid);
            printf("%s\t\t\t",u.name);
            printf("%s\n",u.pwd);
        }
        getch();


}

*/
void viewEmployee()
{
    FILE *fp=fopen("emp.bin","rb");
    User ur;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(int i=1;i<=80;i++)
    {
        printf("%c",247);
    }
    gotoxy(31,5);
    printf("* EMPLOYEE DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(int i=1;i<=80;i++)
        printf("%c",247);

    if(fp==NULL)
    {
        gotoxy(31,9);
        textcolor(LIGHTRED);
        printf("Sorry! No Employee added yet!");
        getch();
        return;
    }
    gotoxy(1,8);
    printf("Employee ID\t\t\tName\t\t\tPassword");
    gotoxy(1,9);
    for(int i=1;i<=80;i++)
        printf("%c",247);
    int row=10;
    textcolor(YELLOW);
    while(fread(&ur,sizeof(ur),1,fp)==1)
    {
        gotoxy(2,row);
        printf("%s",ur.userid);
        gotoxy(33,row);
        printf("%s",ur.name);
        gotoxy(57,row);
        printf("%s",ur.pwd);
        row++;

    }
    fclose(fp);
    getch();

}
int deleteEmp()
{
    FILE *fp1=fopen("emp.bin","rb");
    char empid[10];
    int i,result;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<=80;i++)
    {
        printf("%c",247);
    }
    gotoxy(29,5);
    printf("* DELETE EMPLOYEE RECORD *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1;i<=80;i++)
    {
        printf("%c",247);
    }
    gotoxy(1,12);
    for(i=1;i<=80;i++)
    {
        printf("%c",247);
    }
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        gotoxy(32,10);
        printf("No Employees added yet!");
        return -1;
    }
    FILE *fp2=fopen("temp.bin","wb");
    if(fp2==NULL)
    {
        textcolor(LIGHTRED);
        gotoxy(32,10);
        printf("Sorry ! cannot create temp file");
        return -1;
    }
    gotoxy(10,9);
    textcolor(YELLOW);
    printf("Enter employee id to delete the record:");
    textcolor(WHITE);
    scanf("%s",empid);
    User u;
    int found=0;
    /* 1. Run a loop which reads one record from fp1 at a time
       2. check whether empid is matching with tempid given by the user
       3. if it is not matching then write the record in fp2
       4. otherwise simply set found to 1 */

    while(fread(&u,sizeof(u),1,fp1)==1)
    {
        if(strcmp(u.userid,empid)!=0)
            fwrite(&u,sizeof(u),1,fp2);
        else
            found=1;
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("temp.bin");
    }
    else
    {
        result=remove("emp.bin");
        if(result!=0)
            return 2;
        result=rename("temp.bin","emp.bin");
        if(result!=0)
            return 2;
    }
    return found;

}

int empMenu()
{

    int choice,i;
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGREEN);
    gotoxy(35,6);
    printf("EMPLOYEE MENU\n");
    for(i=1;i<=80;i++)
        printf("*");
    textcolor(YELLOW);
    gotoxy(32,8);
    printf("1. Rent A Car");
    gotoxy(32,9);
    printf("2. Booking Details");
    gotoxy(32,10);
    printf("3. Available car details");
    gotoxy(32,11);
    printf("4. Show All car details");
    gotoxy(32,12);
    printf("5. Exit");
    gotoxy(32,15);
    printf("Enter choice:");
    scanf("%d",&choice);
    return choice;
}

int selectCarModel()
{

    FILE *fp=fopen("car.bin","rb");
    int flag;
    int choice,rowno=9;
    Car C;
    gotoxy(34,rowno);
    int carCount=0;
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        if(C.car_count>0)
        {
            printf("%d . %s",C.car_id,C.car_name);
            gotoxy(34,++rowno);
            ++carCount;

        }
    }
    if(carCount==0)
    {
       fclose(fp);
        return -2;
    }

    gotoxy(34,rowno+2);
    printf("Enter your choice(0 to quit):");
    while(1)
    {

        flag=0;
        scanf("%d",&choice);
        if(choice==0)
        {
            fclose(fp);
            return 0;
        }
        rewind(fp);
        while(fread(&C,sizeof(C),1,fp)==1)
        {
            if(C.car_id==choice&&C.car_count>0)
            {
               flag=1;
               break;

            }
        }
        if(flag==1)
        {

            fclose(fp);
            return flag;
        }
        gotoxy(37,rowno+4);
        textcolor(LIGHTRED);
        printf("Wrong input");
        getch();
        gotoxy(35,rowno+4);
        printf("\t\t\t");
        gotoxy(52,rowno+2);
        printf("\t\t\t");
        gotoxy(52,rowno+2);
        textcolor(WHITE);

    }
}
int isValidDate(struct tm dt)
{

    if(dt.tm_year>=2021&&dt.tm_year<=2022)
    {
        if(dt.tm_mon>=1&&dt.tm_mon<=12)
        {
            if((dt.tm_mday>=1&&dt.tm_mday<=31)&&(dt.tm_mon==1||dt.tm_mon==3||dt.tm_mon==5||dt.tm_mon==7||dt.tm_mon==8||dt.tm_mon==10||dt.tm_mon==12))
            {
                return 1;
            }
            else if((dt.tm_mday>=1&&dt.tm_mday<=30)&&(dt.tm_mon==4||dt.tm_mon==6||dt.tm_mon==9||dt.tm_mon==11))
            {
                return 1;

            }
            else if((dt.tm_mday>=1&&dt.tm_mday<=28)&&dt.tm_mon==2)
                return 1;
            else if((dt.tm_mday>=1&&dt.tm_mday<=29)&&dt.tm_mon==2&&(dt.tm_year%400==0||(dt.tm_year%4==0&&dt.tm_year%100!=0)))
                return 1;

        }
    }
    return 0;
}

int checkDate(struct tm sd,struct tm ed)
{


    time_t obj=time(0);
    //char *p=ctime(&obj);
   // printf("%s",p);
    //Another function
    struct tm *p=localtime(&obj);
    //printf("%d",1900+p->tm_year);
    //printf("\nMonth:%d",1+p->tm_mon);
    //printf("\nDay:%d",p->tm_mday);
    //return 0;
    if(sd.tm_year>=1900+p->tm_year)
    {
        if(sd.tm_mon>=1+p->tm_mon)
        {
            if(sd.tm_mday>=p->tm_mday)
            {
                if(sd.tm_year<=ed.tm_year)
                {
                    if(sd.tm_mon<=ed.tm_mon)
                    {
                        if(sd.tm_mday<=ed.tm_mday)
                        {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;

}

void updateCarCount(int c_id)
{
    FILE* fp=fopen("car.bin","rb+");
    if(fp==NULL)
    {
        printf("Sorry file cannot be open!");
        getch();
        return;
    }
    Car C;
    while(fread(&C,sizeof(Car),1,fp)==1)
    {
        if(C.car_id==c_id)
        {
            int x=C.car_count;
            x--;
            fseek(fp,-8,SEEK_CUR);

            fwrite(&x,sizeof(int),1,fp);
            break;
            //fseek(fp,4,SEEK_CUR);
        }
    }
    fclose(fp);
}

void bookedCarDetails()
{

    clrscr();
    FILE *fp=fopen("customer.bin","rb");
    Customer_Car_Details CC;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<=80;i++)
    {
        printf("%c",247);

    }
    gotoxy(31,5);
    printf("* BOOKED CAR DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1;i<=80;i++)
        printf("%c",247);
    gotoxy(1,8);
    printf("MODEL\t    CustNAME\t   Pick UP\t    S_Date\t   E_Date");
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
    for(i=1;i<=80;i++)
        printf("%c",247);
    int row=10;
    textcolor(YELLOW);
    while(fread(&CC,sizeof(Customer_Car_Details),1,fp)==1)
    {
        gotoxy(1,row);
        printf("%s",getCarName(CC.car_id));
        gotoxy(13,row);
        printf("%s",CC.cust_name);
        gotoxy(27,row);
        printf("%s",CC.pickup);
        gotoxy(44,row);
        printf("%s",CC.drop);
        gotoxy(58,row);
        printf("%d-%d-%d",CC.sd.tm_mday,CC.sd.tm_mon,CC.sd.tm_year);
        gotoxy(70,row);
        printf("%d-%d-%d",CC.ed.tm_mday,CC.ed.tm_mon,CC.ed.tm_year);

        row++;
    }


    fclose(fp);

}

char* getCarName(int c_id)
{

    FILE*fp=fopen("car.bin","rb");
    if(fp==NULL)
    {
        printf("Sorry! file cannot be opened");
        return NULL;
    }
    static Car C;
    while(fread(&C,sizeof(C),1,fp))
    {
        if(C.car_id==c_id)
        {
            break;
        }
    }
    fclose(fp);
    return C.car_name;

}

int rentCar()
{
   Customer_Car_Details CC;

   int c,i;
   textcolor(LIGHTRED);
   gotoxy(32,2);
   printf("CAR RENTAL SYSTEM");
   textcolor(LIGHTGREEN);
   gotoxy(35,6);
   printf("EMPLOYEE MENU\n");
   for(i=1;i<=80;i++)
   {
       printf("*");
   }
   textcolor(YELLOW);
   gotoxy(32,8);
   c=selectCarModel();
   if(c==0||c==-2)
   {
       return c;
   }
   CC.car_id=c;
   clrscr();
    textcolor(LIGHTRED);
   gotoxy(32,2);
   printf("CAR RENTAL SYSTEM");
   textcolor(LIGHTGREEN);
   gotoxy(35,6);
   printf("EMPLOYEE MENU\n");
   for(i=1;i<=80;i++)
   {
       printf("*");
   }
   gotoxy(1,17);
   for(i=1;i<=80;i++)
   {
       printf("*");
   }
   textcolor(YELLOW);
   gotoxy(27,9);
   printf("Enter Customer Name:");
   fflush(stdin);
   textcolor(WHITE);
   fgets(CC.cust_name,30,stdin);
   char *pos;
   pos=strchr(CC.cust_name,'\n');
   *pos='\0';
   gotoxy(27,10);
   textcolor(YELLOW);
   printf("Enter pickup point:");
   textcolor(WHITE);
   fflush(stdin);
   fgets(CC.pickup,30,stdin);

   pos=strchr(CC.pickup,'\n');
   *pos='\0';
   gotoxy(27,11);
   textcolor(YELLOW);
   printf("Enter drop point:");
   textcolor(WHITE);
   fflush(stdin);
   fgets(CC.drop,30,stdin);

   pos=strchr(CC.drop,'\n');
   *pos='\0';
   gotoxy(27,12);
   textcolor(YELLOW);
   printf("Enter start date(dd/mm/yyyy):");
   textcolor(WHITE);
   do
   {
       scanf("%d/ %d/ %d",&CC.sd.tm_mday,&CC.sd.tm_mon,&CC.sd.tm_year);
       int datevalid=isValidDate(CC.sd);
       if(datevalid==1)
       {
               break;
       }

       gotoxy(27,18);
       textcolor(LIGHTRED);
       printf("Wrong date");
       getch();
       gotoxy(27,18);
       printf("\t\t\t");
       gotoxy(56,12);
       printf("\t\t\t");
       gotoxy(56,12);
       textcolor(WHITE);
   }while(1);

   gotoxy(27,13);
   textcolor(YELLOW);
   printf("Enter end date(dd/mm/yyyy):");
   textcolor(WHITE);
   do
   {
       scanf("%d/ %d/ %d",&CC.ed.tm_mday,&CC.ed.tm_mon,&CC.ed.tm_year);
       int datevalid=isValidDate(CC.ed);
       if(datevalid==1)
            break;
       gotoxy(27,18);
       textcolor(LIGHTRED);
       printf("Wrong date");
       getch();
       gotoxy(27,18);
       printf("\t\t\t");
       gotoxy(54,13);
       printf("\t\t\t");
       gotoxy(54,13);
       textcolor(WHITE);
   }while(1);

   //Now Validate the dates against current date as well as against each other.
   int correctdate=checkDate(CC.sd,CC.ed);
   if(correctdate==1)
   {
        FILE*fp;
        fp=fopen("customer.bin","ab");
        if(fp==NULL)
        {
         gotoxy(27,18);
         textcolor(LIGHTRED);
         printf("Sorry! File cannot be opened");
         return -1;
        }
         fwrite(&CC,sizeof(Customer_Car_Details),1,fp);
         gotoxy(27,18);
         textcolor(WHITE);

         printf("Booking done for Car %d",CC.car_id);
         printf("\nPress any key to continue");
         getch();
         fclose(fp);
         updateCarCount(CC.car_id);
         bookedCarDetails();

         return 1;
   }
   else
   {
      gotoxy(32,18);
      textcolor(LIGHTRED);
      printf("Wrong date ");
      gotoxy(27,19);
      printf("Booking cannot be done");
      getch();
   }



   //getdate();

}

void availCarDetails()
{
    FILE* fp= fopen("car.bin","rb");
    Car C;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    textcolor(LIGHTGREEN);
    for(i=1;i<=80;i++)
        printf("%c",247);
    gotoxy(32,5);
    textcolor(YELLOW);
    printf("* AVAILABLE CAR DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1;i<=80;i++)
        printf("%c",247);

    if(fp==NULL)
    {
          gotoxy(32,8);
          textcolor(LIGHTRED);
          printf("Sorry File Cannot be opened!");
          getch();
          return;
    }
    gotoxy(1,8);
    printf("Car ID\t   Model\t\t   Capacity\tAvailable\tprice/Day");
    gotoxy(1,9);
    for(i=1;i<=80;i++)
        printf("%c",247);
    int row=10;
    textcolor(YELLOW);

    while(fread(&C,sizeof(C),1,fp)==1)
    {
        if(C.car_count>0)
        {
            gotoxy(2,row);
            printf("%d",C.car_id);
            gotoxy(13,row);
            printf("%s",C.car_name);
            gotoxy(35,row);
            printf("%d",C.capacity);
            gotoxy(50,row);
            printf("%d",C.car_count);
            gotoxy(68,row);
            printf("%d",C.price);
            row++;

        }
    }
    fclose(fp);

}
void showCarDetails()
{
    FILE* fp= fopen("car.bin","rb");
    Car C;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    textcolor(LIGHTGREEN);
    for(i=1;i<=80;i++)
        printf("%c",247);
    gotoxy(32,5);
    textcolor(YELLOW);
    printf("* ALL CAR DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1;i<=80;i++)
        printf("%c",247);

    if(fp==NULL)
    {
          gotoxy(32,8);
          textcolor(LIGHTRED);
          printf("Sorry File Cannot be opened!");
          getch();
          return;
    }
    gotoxy(1,8);
    printf("Car ID\t   Model\t\t   Capacity\tAvailable\tprice/Day");
    gotoxy(1,9);
    for(i=1;i<=80;i++)
        printf("%c",247);
    int row=10;
    textcolor(YELLOW);

    while(fread(&C,sizeof(C),1,fp)==1)
    {


            gotoxy(2,row);
            printf("%d",C.car_id);
            gotoxy(13,row);
            printf("%s",C.car_name);
            gotoxy(35,row);
            printf("%d",C.capacity);
            gotoxy(50,row);
            printf("%d",C.car_count);
            gotoxy(68,row);
            printf("%d",C.price);
            row++;


    }
    fclose(fp);
}

