#include<windows.h> //For SetConsoleCursorPosition()
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>
#include <stdlib.h>
struct Book{   //use to store almost all the information of the book
	int BookId;
    char *name;
    char *author;
	float price;
	int quantiy;
    int bookCategory;
   int ShelfNo;


};

struct UserLogin //used to login to use the program by entering correct details
{
	char name[100];
	char Password[20];

};
void returnfunc(void);
void mainmenu(void);
void addbooks(void);
void deletebooks(void);
void editbooks(void);
void searchbooks(void);
void viewbooks(void);
void closeapplication(void);
int  getdata();
int  checkid(int);
void Password();
void loaderanim();
struct Book ExpensiveBook(double);
struct Book ExpensiveBook(double a)
{
		struct Book book;

			struct Book book1;

		FILE *bookread;
		book.name=(char*)malloc(100*sizeof(char));
			book.author=(char*)malloc(100*sizeof(char));
			book1.name=(char*)malloc(100*sizeof(char));
			book1.author=(char*)malloc(100*sizeof(char));
				bookread=fopen("Book.txt","r");
		system("cls");
	        printf("\n\n\t\t\tExpensive Book In The Library\n");
	    printf("BookId\t\tName\t\tAuthor\t\tPrice\t\tQuantity\t\tShelfNumber\nt");
        float max=-100;
		while(fread(&book,sizeof(book),1,bookread))
		{
	          if(book.price>max)
	          {
	          	book1.BookId=book.BookId;
	             strcpy(book1.name,book.name);
	             strcpy(book1.author,book.author);
	          	book1.price=book.price;
	          	book1.quantiy=book.quantiy;
	          	book1.ShelfNo=book.ShelfNo;
	          	book1.bookCategory=book.bookCategory;
	          	max=book.price;
			  }
        }
         	printf("\t\t\tBookId:%d\n",book1.BookId);
				printf("\t\t\tBookName:%s\n",book1.name);
				printf("\t\t\tBook Author:%s",book1.author);
				printf("\t\t\tPrice:%f\n",book1.price);
				printf("\t\t\tQuantity:%d\n",book1.quantiy);
			
              char * code=(char*)malloc(100*sizeof(char));
    switch(book1.bookCategory)
    {
    	case 1:
		code="CS";
    		break;
    		case 2:
    			code="EE";
    			break;
    			case 3:
    				code="ELE";
    				break;
    				case 4:
    					code="ME";
    					break;
    					case 5:
    						code="CE";
    						break;
    						case 6:
    							code="AR";
								break;
	}
	printf("\t\t\tShelfNumber:%s-%d",code,book1.ShelfNo);
        
        fclose(bookread);
        printf("\n\n\t\t\tPress Any Key To Continue\n");
        getch();
   return book1;    
}
int Books_Category()
{

system("cls");
  printf("\n\n\n\t\t\tChoose The Department Of Book\n");
  printf("\t\t\t1)Computer Science(CS)\n");
printf("\t\t\t2)Electrical Engineering(EE)\n");
printf("\t\t\t3)Electronic(ELE)\n");
printf("\t\t\t4)Mechanical(ME)\n");
printf("\t\t\t5)Civil(CE)\n");
printf("\t\t\t6)Architecture(AR)\n");
printf("\n\t\t\tChoose The Department:");
int a;
scanf("%d",&a);
if(a<=6 && a>=1)
{
	return a;
}else{
	printf("\n\n\n\t\t\tChoose The Department:");

scanf("%d",&a);
}

}
void EditBook() //we can change the details of book by using this function
{


	       system("cls");
	       printf("\n\n\n\t\t\t\tEdit The Book");
	       printf("\n\n\t\t\tEnter The Book Id :");
	       int a ;
	       scanf("%d",&a);

		struct Book book;
		FILE *bookread;
		bookread=fopen("Book.txt","r+");
    int flag=0;
    book.name=(char*)malloc(100*sizeof(char));
    book.author=(char*)malloc(100*sizeof(char));
		while(fread(&book,sizeof(book),1,bookread) && flag!=1)
		{
			if(book.BookId==a)
			{
				 char * code=(char*)malloc(5*sizeof(char));
    switch(book.bookCategory)
    {
    	case 1:
		code="CS";
    		break;
    		case 2:
    			code="EE";
    			break;
    			case 3:
    				code="ELE";
    				break;
    				case 4:
    					code="ME";
    					break;
    					case 5:
    						code="CE";
    						break;
    						case 6:
    							code="AR";
								break;
	}

				printf("\n\t\t\tPrevious Book Information");
				flag=1;
				printf("\n\t\t\tBookId:%d\n\t\t\tBookName:%s\n\t\t\tAuthor:%s\n\t\t\tPrice:%f\n\t\t\tQuantity:%d\t\tSelfNumber:%s-%d\n",book.BookId,book.name,book.author,book.price,book.quantiy,code,book.ShelfNo);
				printf("\n\t\t\tAre You Sure You Want To Change BookName:(Y/N)");
				char c;
   fflush(stdin);

				scanf("%c",&c);
				if(c=='Y' || c=='y')
				{

			  printf("\n\t\t\tBook Name:");
       fflush(stdin);
      
    gets(book.name);
				}
   	printf("\t\t\tAre You Sure You Want To Change Author(Y/N):");
				char c1;
   fflush(stdin);

				scanf("%c",&c1);
				if(c1=='Y' || c1=='y')
				{

			    printf("\n\t\t\tEnter Author:");
			    fflush(stdin);
			   
   gets(book.author);
				}
 printf("\n\t\t\tAre You Sure You Want To Change Book Price(Y/N):");
				char c2;
				   fflush(stdin);

				scanf("%c",&c2);
				if(c2=='Y' || c2=='y')
				{


			  fflush(stdin);
    printf("\n\t\t\tEnter Book Price:");
        scanf("%f",&book.price);
				}
     printf("\n\t\t\tAre You Sure You Want To Change Book Quantity(Y/N):");
				char c3;
				   fflush(stdin);

				scanf("%c",&c3);
				if(c3=='Y' || c3=='y')
				{



    printf("\n\t\t\tEnter Book Quantity:");
    scanf ("%d",&book.quantiy);

							}


			fseek(bookread,c-sizeof(book),SEEK_CUR);
			fwrite(&book,sizeof(book),1,bookread);

           	}


		}

	
		printf("Press Enter  To Continue");

	getch();
}
void addBook()  //use to store books in the program
{
	struct Book book;
	int a=Books_Category();
	system("cls");
	
    printf("\n\n\n\t\t\t\tEnter The Book Information");
    switch(a)
    {
    	case 1:

    		printf("\n\n\t\t\tDepartment Name:Computer Science\n");
    		book.bookCategory=1;
    		break;
        case 2:
        	printf("\n\t\t\tDepartment Name:Electrical Engineering\n");
        		book.bookCategory=2;
        		break;
        	case 3:
        		printf("\n\t\t\tDepartment Name:Electronic Engineering\n");
        			book.bookCategory=3;
        			break;
        		case 4:
        		printf("\n\t\t\tDepartment Name:Mechanical Engineering\n");
        			book.bookCategory=4;
        			break;
        			case 5:
        		printf("\n\t\t\tDepartment Name:Civil Engineering\n");
        			book.bookCategory=5;
        			break;
        			case 6:
        				printf("\n\t\t\tDepartment Name:Architecture\n");
        				book.bookCategory=6;
        				break;


	}

    printf("\n\t\t\tBook Id:");
    scanf("%d",&book.BookId);
    printf("\n\t\t\tBook Name:");
       fflush(stdin);
       book.name=(char*)malloc(100*sizeof(char));
    gets(book.name);
    
	printf("\n\t\t\tAuthor:");
       book.author=(char*)malloc(100*sizeof(char));
   gets(book.author);
     fflush(stdin);
    printf("\n\t\t\tPrice:");
    scanf("%f",&book.price);
    printf("\n\t\t\tQuantity:");
    scanf ("%d",&book.quantiy);
    char * code=(char*)malloc(5*sizeof(char));
    switch(book.bookCategory)
    {
    	case 1:
		code="CS";
    		break;
    		case 2:
    			code="EE";
    			break;
    			case 3:
    				code="ELE";
    				break;
    				case 4:
    					code="ME";
    					break;
    					case 5:
    						code="CE";
    						break;
    						case 6:
    							code="AR";
								break;
	}

    printf("\n\t\t\tEnter The Shelf Number:%s-",code);
    
    int a1;
    scanf("%d",&a1);
    book.ShelfNo=a1;

    printf("\t\t\tAre You Sure You Want To Safe(y/n):");
    char c;
      fflush(stdin);
    scanf("%c",&c);

    if(c=='Y' || c=='y')
    {
    	FILE *bookfile;
    	bookfile=fopen("Book.txt","a");
    	if(bookfile==NULL)
    	{
    		printf("File DoesNot Exist");

		}
		fwrite(&book,sizeof(book),1,bookfile);
		if(fwrite!=0)
		{
			printf("\n\n\t\t\tBook Enter Successfully!!!");
		}else{
				printf("Write Does not Gets Sussessfully");
		}
		fclose(bookfile);
		
	
	}
     printf("\n\n\n\t\t\tAdd More Book(y/n):");
     char c2;
     fflush(stdin);
     scanf("%c",&c2);
     	if(c2=='Y' || c2=='y')
     	{
     		addBook();
		 }else{
		 	printf("\n\n\n\t\t\tPress Enter To Continue...");
		 	getch();
		 	
		 }

}
COORD coordinate={0,0};
void GotoXY(int x,int y)//To write any where on the screen
{
	coordinate.X=x;
	coordinate.Y=y;
	 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}
void CloseTheApplication()  //it is use to close the application
{
	system("cls");
	char c;
	printf("\n\n\n\t\t\tLIBRARY MANAGEMENT SYSTEM");
	printf("\n\n\n\t\t\tAre You Sure You Want To Close The Application(Y/N)");
	fflush(stdin);
    scanf("%c",&c);
    if(c=='Y' || c=='y')
    {
    	printf("\n\n\n\t\t\tGood Bye!!!!");

    	exit(0);
	}
	
		printf("\n\n\t\t\tPress Enter To Continue");
		getch();
		
		remove("Book.txt");
}
void ViewBook()  //used to view book which are already added previously
{
		struct Book book;
		FILE *bookread;
		bookread=fopen("Book.txt","r+");
		system("cls");

	    printf("BookId\t\tName\t\t\tAuthor\t\tPrice\t\tQuantity\t\tShelfNumber\n\n");
       book.name=(char*)malloc(100*sizeof(char));
       book.author=(char*)malloc(100*sizeof(char));
       char* code=(char*)malloc(5*sizeof(char));
       rewind(bookread);
		while(fread(&book,sizeof(book),1,bookread))
		{
			 
    switch(book.bookCategory)
    {
    	case 1:
		code="CS";
    		break;
    		case 2:
    			code="EE";
    			break;
    			case 3:
    				code="ELE";
    				break;
    				case 4:
    					code="ME";
    					break;
    					case 5:
    						code="CE";
    						break;
    						case 6:
    							code="AR";
								break;
	}
	
			printf("%d\t\t%s\t\t\t%s\t\t%f\t\t%d\t\t%s-%d\n\n",book.BookId,book.name,book.author,book.price,book.quantiy,code,book.ShelfNo);
	       if(feof(bookread))
	       {
	       	break;
		   }
		}
		 fclose(bookread);
		 printf("Press Enter To Continue....");
		 getch();
}
void SearchById() //program search the book by the Id of the book
{	printf("\n\n\n");
	system("cls");
	printf("\n\n\n\t\t\tEdit Boon Info");
	printf("\t\t\tEnter The Book Id");
	int a;
	scanf("%d",&a);

		struct Book book;
		FILE *bookread;
		bookread=fopen("Book.txt","r+");
	int flag=0;
	  book.name=(char*)malloc(100*sizeof(char));
	  book.author=(char*)malloc(100*sizeof(char));
		while(fread(&book,sizeof(book),1,bookread) && flag!=1)
		{

			if(a==book.BookId)
			{
				flag=1;
                          break;
			}
		}
		if(flag==1)
		{
			printf("\n\n\n");
				printf("\t\t\tBookId:%d\n",book.BookId);
				printf("\t\t\tBookName:%s\n",book.name);
				printf("\t\t\tBook Author:%s\n",book.author);
				printf("\t\t\tPrice:%f\n",book.price);
				printf("\t\t\tQuantity:%d\n",book.quantiy);
			   char * code=(char*)malloc(100*sizeof(char));
    switch(book.bookCategory)
    {
    	case 1:
		code="CS";
    		break;
    		case 2:
    			code="EE";
    			break;
    			case 3:
    				code="ELE";
    				break;
    				case 4:
    					code="ME";
    					break;
    					case 5:
    						code="CE";
    						break;
    						case 6:
    							code="AR";
								break;
	}
      printf("\t\t\tShelfNumber:%s-%d",code,book.ShelfNo);

		}else{
			printf("\t\t\tBook Does Not Exist\n");
		}
		printf("\n\t\t\tEnter To Continue...");
		getch();
		fclose(bookread);
}
/*void SearchByName() //Program search the book by the name of the book
{
	system("cls");
	printf("\t\t\tEnter The BookName:");
	char a[20];
	scanf("%s",&a);
	printf("\n\n\n");
		struct Book book;
		FILE *bookread;
		bookread=fopen("Book.dat","r+");
	int flag=0;
		while(fread(&book,sizeof(struct Book),1,bookread) && flag!=1)
		{
			if(strcmp(a,book.name)==0)
			{
				flag=1;
                          break;
			}
		}
		if(flag==1)
		{
				printf("\t\t\tBookId:%d\n",book.BookId);
				printf("\t\t\tBookName:%s\n",book.name);
				printf("\t\t\tBook Author:%s",book.author);
				printf("\t\t\tPrice:%f\n",book.price);
				printf("\t\t\tQuantity:%d\n",book.quantiy);
              char * code=(char*)malloc(100*sizeof(char));
    switch(book.bookCategory)
    {
    	case 1:
		code="CS";
    		break;
    		case 2:
    			code="EE";
    			break;
    			case 3:
    				code="ELE";
    				break;
    				case 4:
    					code="ME";
    					break;
    					case 5:
    						code="CE";
    						break;
    						case 6:
    							code="AR";
								break;
	}
	printf("\t\t\tShelfNumber:%s-%d",code,book.ShelfNo);

		}
		else{
			printf("\t\t\tBook Does Not Exist");
		}
		printf("\t\t\tEnter To Continue...");
		getch();
		fclose(bookread);

}



void SearchByAuthor() //Program search the book by the name of the author
{
	   system("cls");
	printf("\t\t\tEnter The Book Auhtor:");
	char a[100];
	scanf("%s",&a);
	printf("\n\n");

		struct Book book;
		FILE *bookread;
		bookread=fopen("Book.dat","r+");
	int flag=0;
		while(fread(&book,sizeof(struct Book),1,bookread) && flag!=1)
		{
			if(strcmp(a,book.author)==0)
			{
				flag=1;
                          break;
			}
		}
		if(flag==1)
		{

				printf("\t\t\tBookId:%d\n",book.BookId);
				printf("\t\t\tBookName:%s\n",book.name);
				printf("\t\t\tBook Author:%s",book.author);
				printf("\t\t\tPrice:%f\n",book.price);
				printf("\t\t\tQuantity:%d\n",book.quantiy);
				 char * code;
    switch(book.bookCategory)
    {
    	case 1:
		code="CS";
    		break;
    		case 2:
    			code="EE";
    			break;
    			case 3:
    				code="ELE";
    				break;
    				case 4:
    					code="ME";
    					break;
    					case 5:
    						code="CE";
    						break;
    						case 6:
    							code="AR";
								break;
	}
      printf("\t\t\tShelfNumber:%s-%d",code,book.ShelfNo);

           }else{
			printf("\t\t\tThe Book Of Author Doesnot Exist");
		}
	printf("\t\t\tPress Enter To Continue...");
	getch();
	fclose(bookread);

}*/
void SearchBook()
{

	system("cls");
      printf("\n\n\n\t\t\t\tSearch Book");
      printf("\n\n\n\t\t\t1)Search By Id\n");
      int a;
      printf("\n\n\n\t\t\tEnter Your Choice:");
      scanf("%d",&a);
      switch(a)
      {
      	case 1:
      		SearchById();
      		break;
      		
	  }
	printf("\n\n\t\t\tWant To Search More Books:");
    char c;
    scanf("%c",&c);
    if(c=='Y' || c=='y')
    {
    	SearchBook();

	}
}
void DeleteBook(){  //Delete the book by ID of the book provided by the user
	system("cls");

	printf("Enter the BookId:");
	int a;
	scanf("%d",&a);
	struct Book book;
		FILE *bookread;
		FILE *bookwrite;
		bookwrite=fopen("duplicate.txt","a+");
		bookread=fopen("Book.txt","r+");
		int flag=0;
		book.name=(char*)malloc(100*sizeof(char));
		book.author=(char*)malloc(100*sizeof(char));
		while(fread(&book,sizeof(book),1,bookread))
		{

			if(a!=book.BookId)
			{

					fwrite(&book,sizeof(book),1,bookwrite);

			}else{
				printf("\t\t\tBook Delete Successfully");
				flag=1;
			}


		}
		if(flag==0)
		{
			printf("Book Not Avaliable");
		}
			fclose(bookwrite);
		fclose(bookread);
       
	int status=remove("Book.txt");
	
		rename("duplicate.txt","Book.txt");
       printf("\n\n\t\t\tPress Enter To Continue...");
	   getch();
	 


}
void mainmenu() //screen which appears after entering the correct user name and password
{
system("cls");

	printf("\n\n\t\t\tWelcome To Main Menu Of System\n\n");
	printf("\n\n\t\t\t1)Add The Book\n");
	printf("\t\t\t2)Edit The Book\n");
	printf("\t\t\t3)Delete Book\n");
    printf("\t\t\t4)Search Book\n");
    printf("\t\t\t5)View The Book\n");
    printf("\t\t\t6)Expensive Book");
    printf("\n\t\t\t7)Close The Program");
    printf("\n\n\n\t\t\tEnter The Choice:");
    int a;
    scanf("%d",&a);
     while(a>7 ||a<1)
     {
     	printf("\n\t\t\tYou Enter The Wrong Choice");
     	 printf("\n\t\t\tEnter The Choice:");

    scanf("%d",&a);
	 }
	 switch(a)
	 {
	 	case 1:
		 addBook();
	 		break;
	 		case 2:
	 		  EditBook();
	 			break;
	 				case 3:
	 			DeleteBook();
				 		break;
	 					case 4:
	 				SearchBook();

							 break;
	 				    case 5:
	 				    	ViewBook();
	 				    	break;
	 				    	
	 				    case 6:
	 				    	ExpensiveBook(12.00);
	 				    	break;
	 				    	case 7:
	 				    		CloseTheApplication();
	 				    		break;

	 }
}
void returnfunc() //use to go back to main menu by pressing enter
{
	printf("\nPress Key To Continue");
	getch();
	mainmenu();
}
void Password() //password to login into the system
{
	int flag=0;
	while(flag!=1)
	{
          	system("cls");
	   GotoXY(14,6);
	printf("****************************************************");
	int i=0;
	for( i=7;i<17;i++)
	{
			GotoXY(14,i);
	printf("*\n");

	}


	for( i=7;i<17;i++)
	{
			GotoXY(65,i);
	printf("*\n");

	}
	GotoXY(14,17);
		printf("****************************************************");

    		GotoXY(25,10);
	printf("Enter UserName:");
	char name[100];
	GotoXY(40,10);
	fflush(stdin);
	gets(name);
	GotoXY(25,13);
    printf("Password:(4 Character):");

    char Password[4];
    fflush(stdin);
    scanf("%s",Password);
    if(strcmp(name,"areeba")==0 && strcmp(Password,"1234")==0)
    {
    	flag=1;

     while(1)
     {
     	mainmenu();
	 }
	}else{
		GotoXY(15,20);
	    printf("Wrong UserName Or Password ");
	    printf("\n\t\t\tPress Enter To Continue....");
	    getch();

	}
	}

}

int main()
{
	remove("Book.txt");
   Password();

}
