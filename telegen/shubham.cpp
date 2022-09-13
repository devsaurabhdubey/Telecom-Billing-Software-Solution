
#include <iostream>
#include <math.h>
#include <windows.h>                  // For gotoxy() and Sleep function
#include <ctime>		           	 // For Displaying time
#include <iomanip>
#include <limits>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>                  // For isalpha() function
#include<fstream>
#include<MMSystem.h>
using namespace std;

COORD coord = {0,0};              
void gotoxy(int x, int y)         //For Setting the position of Cursor
{
	
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition( GetStdHandle (STD_OUTPUT_HANDLE), coord ); 
}
void time()
{
	//  FOR current time and date
	gotoxy(1,10);
		time_t now;	
	time (&now);
	cout << "\n\n\t\t Current Date & Time is: "<<ctime(&now);;         // For Displaying Date and Time	
	// Creating Object of Time

}	
void loading()
{
	gotoxy(24,26);
	int i;
	for (i=0; i<5; i++)
	{
		cout << "\xdb\xdb\xdb\xdb\xdb";
		Sleep(100);
	}
	Sleep(500);
	cout << endl << endl;
	gotoxy(24,28);
}
	void mainEntrance()
{
	gotoxy(15,2);
cout<<" 00000 00000 0     00000  0000  00000 0      0"<<endl; gotoxy(15,3);
cout<<"   0   0     0     0     0      0     00     0"<<endl; gotoxy(15,4);
cout<<"   0   0     0     0     0      0     0 0    0"<<endl; gotoxy(15,5);
cout<<"   0   00000 0     00000 0  000 00000 0  0   0"<<endl; gotoxy(15,6);
cout<<"   0   0     0     0     0    0 0     0   0  0"<<endl; gotoxy(15,7);
cout<<"   0   0     0     0     0    0 0     0    0 0"<<endl; gotoxy(15,8);
cout<<"   0   00000 00000 00000  0000  00000 0      0"<<endl<<endl; gotoxy(6,9);
cout << "     **************************************************************" << endl;
gotoxy(6,10);
cout << "                     TELECOM BILL GENERATOR                     " << endl;
gotoxy(6,11);
cout << "     **************************************************************" << endl;
}
void login()
{
	system("cls");

	string username = "";
	string password = "";
	char ch,ch2,retry;
	int i = 0, j = 0;
	mainEntrance();
	time();	
	gotoxy(55,10);
	cout << "(LOGIN)";
	gotoxy(20,15);
	cout << "Enter Username: \n\t\t    Enter Password: ";
	gotoxy(36,15);
	
	ch2=getch();
	while(ch2 != 13){                  // gets input until 'Enter' key is pressed
	
		if(ch2 == '\b'){
			if(username.size() > 0 )  {
				username.erase(username.begin() + username.size() -1);
				cout << "\b \b";
				j--;
			}
			ch2 = getch();
		}
		else{
			if(j<10)
			{
				cout << ch2;
				username.push_back(ch2);
				ch2 = getch();
				j++;
			}
			else{
				ch2 = getch();
			}
		}
	}
	
	gotoxy(36,16);
	ch=getch();
	while(ch != 13){                  // gets input until 'Enter' key is pressed
	
		if(ch == '\b'){
			if(password.size() > 0){
				password.erase(password.begin() + password.size() -1);
				cout << "\b \b";
				i--;
			}
			ch = getch();
		}
		else{
			if(i<10)
			{
				password.push_back(ch);
				cout << "*"; 					  // For showing stars instead of actual alphabets
				ch = getch();
				i++;
			}
			else{
				ch = getch();
			}
		}
	}
	if (username == "shubham" && password == "12345")
	{
		gotoxy(15,16);
		cout << "\n\n Username & Password Matched !! ";
		cout << "\n\n\t Access Granted...\n\n";
		cout << "\n\n\t\t Now Loading: ";
		loading();
		return;
	}	
	else 
	{
		system("cls");
		cout << "\n\n You entered Wrong UserName/Password ";
		cout << "\n\n\t Press 'R' or 'r' to Enter Again OR any other key to exit ...\n\n";
		cin >> retry;	
			if(retry == 'r' || retry == 'R')
			{
				system("cls");
				login();
			}
			else
			{
				exit(0);
			}
	}
}


///////////////////////////USER CLASS//////////////////////////

static int height = 0;

class records
{
	private:
		struct user
		{
			int sno;
			char name[30];
			char plan[30];
			float price;
			
			user *left;
			user *right;
		};
			
		public:		
		user *root;
			records();
			void insert();
			void display(int);
			void show1 (user *&);
			void show4 (user *&);
			void search();
			void deleteRecords();
			int remove(int rn, user *&,int &found);
			void del (user *&nodeptr);
			void totalNodes();
			int findHeight(user *&);
			void findDepthOfNode();
			void userMenu();
};

records r;

records :: records()
	{
		root = NULL;
	}
	
void records :: insert()
{
	system("cls");
	
	label:	
	user *newnode, *nodeptr;
	char ch;
	
	cout << "\n\n _________________________RECORDS INSERTION_________________________";
	do 
	{
		system ("cls");	
		newnode = new user;

	cout << "\n\n Enter Sno Number of Subscriber: ";
	while(1)
	{
		cin >> newnode->sno;
		if (cin.fail() || newnode->sno < 1 )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(),'\n');
			cout << "\nInvalid Input...\nPlease Enter a Sno No. greater than or equal to 1: ";
		}
		else 
			break;
	}
	
	user *temp = new user;
	temp = root;
	while (temp != NULL)
	{
		if(newnode->sno == temp->sno)
			{
				cout << "\n\n This Sno. has already been used";
				cout << "\n\n\t Please Enter a unique Sno. \n\n";
				system("pause");
				goto label;
				break;
			}
		else if(newnode->sno > temp->sno)
			{
				temp = temp->right;
			}
			else if(newnode->sno < temp->sno)
			{
				temp = temp->left;
			}
	}
	
		label1:
	cout << "\n\n Enter Name of Subscriber: ";
	cin.ignore();
	cin.getline (newnode->name,30);

	int check1 = 0;
for(int i = 0; i < strlen(newnode->name); i++){
        if(isalpha(newnode->name[i]) == 0){
        	if (newnode->name[i] == ' ')
        	{
        		check1 = 0;
			}
			else
			{
            cout << "\n\nInvalid Input...\nPlease Enter alphabets only:";
            check1 = 1;
            break;
        	}
        }
    }
    if (check1 == 1)
    {
    	goto label1;
	}
	
	label2:
	cout << "\n\n Enter Plan of User: ";
	cin.getline(newnode->plan,30);

	int check2 = 0;
for(int j = 0; j < strlen(newnode->plan); j++){
        if(isalpha(newnode->plan[j]) == 0 ){
        	if (newnode->plan[j] == ' ')
        	{
        		check2 = 0;
			}
			else
			{
            cout << "\n\nInvalid Input...\nPlease Enter alphabets only:";
            check2 = 1;
            break;
        	}
        }
    }
    if (check2 == 1)
    {
    	goto label2;
	}

	cout << "\n\n Enter Bill of Subscriber (out of 1000): ";
	
	while(1)
	{
		cin >> newnode->price;
		if (cin.fail() || (newnode->price < 0.0) || (newnode->price > 1000) )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(),'\n');
			cout << "\nInvalid Input...\nPlease Enter Bill ranging from 0.0 to 1000: ";
		}
		else 
			break;
	}

	newnode->left = NULL;
	newnode->right = NULL;
	
	if (root == NULL)
	{
		root = newnode;
		height++;
	}
	
	else
	{
		nodeptr = root;
		while (nodeptr != NULL)
		{
			if (newnode->sno < nodeptr->sno)
			{
				if (nodeptr->left != NULL)
				{
					nodeptr = nodeptr->left;
				}
				else
				{
					nodeptr->left = newnode;
					height++;
					break;
				}
			}
			
			else if (newnode->sno > nodeptr->sno)
			{
				if(nodeptr->right != NULL)
				{
					nodeptr = nodeptr->right;
				}
				else
				{
					nodeptr->right = newnode;
					height++;
					break;
				}
			}
		}	
	}
			cout << "\n\n\t Do you want to enter more Records ? \n\n";
			cin >> ch;
				} while(ch == 'y' || ch == 'Y'); 			
	}
	
void records :: show1(user *&temp)
{
	if(temp != NULL)
	{
		show1(temp->left);
		cout << "\n\n\n\n Sno: " << temp->sno;
		cout << "\n\n Name: " << temp->name;
		cout << "\n\n Plan: " << temp->plan;
		cout << "\n\n Bill: " << temp->price;
		show1(temp->right);	
	}
}

void records :: show4(user *&temp)
{
	if(temp != NULL)
	{
		show4(temp->right);
		cout << "\n\n\n\n Sno: " << temp->sno;
		cout << "\n\n Name: " << temp->name;
		cout << "\n\n Plan: " << temp->plan;
		cout << "\n\n Bill: " << temp->price;
		show4(temp->left);	
	}
}

void records :: display(int choice)
{
	system("cls");
	if(root == NULL)
	{
		cout << "\n\n\tPlease Enter some Record First...\n\n";
		return;
	}
	cout << "\n\n _________________________RECORDS DISPLAY_________________________";
	if (choice == 1)
	{
		records :: show1(root);
	}
	else if (choice == 2)
	{
		records :: show4(root);
	}
	
}
	
void records :: search()
{
	system("cls");
	if (root == NULL)
	{
		cout << "\n\n\tPlease Enter Some Record First...\n\n";
		return;
	}
	int rn,check = 0;
	user *temp;
	cout << "\n\n _________________________RECORDS SEARCH_________________________";
	cout << "\n\n Please Enter Sno. of Subscriber to Search: ";
	while(1)
	{
		cin >> rn;
		if (cin.fail() || rn < 1 )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(),'\n');
			cout << "\nInvalid Input...\nPlease Enter a Sno. greater than or equal to 1: ";
		}
		else 
			break;
	}
	
	temp = root;
	while(temp != NULL)
	{
		if (temp->sno == rn)
		{
			cout << "\n\n\n\n Sno: " << temp->sno;
			cout << "\n\n Name: " << temp->name;
			cout << "\n\n Plan: " << temp->plan;
			cout << "\n\n Bill: " << temp->price;
			check = 1;
			break;
		}
		
		else if(rn < temp->sno)
		{
			temp = temp->left;
		}
		
		else if(rn > temp->sno)
		{
			temp = temp->right;
		}
	}
		if (check == 0)
		{
			cout << "\n\n\t Record of Subscriber with Sno. " << rn << " not Found...!\n\n";
			return;
		}
}

int records :: remove (int rn, user *&nodeptr,int &found)
{
	if (nodeptr == NULL)
	{
		return found;
	}
	
	else if(rn < nodeptr->sno)
	{
		records :: remove(rn,nodeptr->left,found);
	}
	
	else if (rn > nodeptr->sno)
	{
		records :: remove (rn,nodeptr->right,found);
	}
	else if (rn == nodeptr->sno)
	{
		found = 1;
		records :: del(nodeptr);
	}
		
		return found;
}

void records :: del (user *&nodeptr)
{
		user *temp;
		// if no Child
		if(nodeptr->left == NULL && nodeptr->right == NULL)
			{
				delete nodeptr;
				nodeptr = NULL;
			}
		// if only Left Child		
		else if (nodeptr->right == NULL)
			{
				temp = nodeptr;
				nodeptr = nodeptr->left;
				delete temp;
				height--;
				cout << "\n\n RECORD DELETED SUCCESSFULLY...\n";
			}
		// if only Right Child
		else if (nodeptr->left == NULL)
			{
				temp = nodeptr;
				nodeptr = nodeptr->right;
				delete temp;
				height--;
				cout << "\n\n RECORD DELETED SUCCESSFULLY...\n";
			}
		else if (nodeptr->right != NULL && nodeptr->left != NULL)
		{
			temp = nodeptr->right;
			
			while (temp->left != NULL)   // Traversing to find Min
			{
				temp = temp->left;
			}
				temp->left = nodeptr->left;
				
				temp = nodeptr;
				nodeptr = nodeptr->right;
				delete temp;
				
				height--;
				cout << "\n\n RECORD DELETED SUCCESSFULLY...\n";
		}
			return;
	}


void records :: deleteRecords()
{
	system("cls");
	int rn,f=0,found=0;
	
	if(r.root == NULL)
	{
		cout << "Please Enter some Record First....";
		return;
	}
	
	cout << "\n\n _________________________RECORDS DELETION_________________________";
	cout << "\n\n\tPlease Enter Sno. of Subscriber to Delete: ";
	
	while(1)
	{
		cin >> rn;
		if (cin.fail() || rn < 1 )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(),'\n');
			cout << "\nInvalid Input...\nPlease Enter a Sno. greater than or equal to 1: ";
		}
		else 
			break;
	}
	
	f=r.remove(rn,r.root,found);
	
	if( f== 0)
		{
		cout << "\n\n\t Record of Subscriber with Roll NO. " << rn << " not Found...!\n\n";
		return;
		}
	
}

void records :: totalNodes()
{
	system("cls");
	if (height == 0)
	{
		cout << "\n\n\t Please Insert Some Records First...";
		return;
	}
	else
	{
		cout << "\n\n Total Number of Subscribers are: " << height;
	}
}

void records :: findDepthOfNode()
{
	system("cls");
	int rn;
	int count = 0;
	int check = 0;
	user *temp;
	
	if (height == 0)
	{
		cout << "Please Enter some Record First....";
		return;
	}
	else
	{
		cout << "\n _________________________DEPTH OF NODE_________________________";
		cout << "\n\n Enter Sno. of User to Find the Depth of Node: ";
		
		while(1)
	{
		cin >> rn;
		if (cin.fail() || rn < 1 )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(),'\n');
			cout << "\nInvalid Input...\nPlease Enter a Sno. greater than or equal to 1: ";
		}
		else 
			break;
	}
		
		temp = root;
		while (temp != NULL)
		{
			if (temp->sno == rn)
			{
				cout << "\n\n Depth of Node you Entered starting From Zero is: " << count;
				check = 1;
				break;
			}
			else if (rn < temp->sno)
			{
				temp = temp->left;
				count++;
			}
			else if (rn > temp->sno)
			{
				temp = temp->right;
				count++;
			}
		}
			if(check == 0)
			{
				cout << "\n\nThe User with Sno. " << rn << " was not FOUND...\n\n";
			}
	}
}

void records :: userMenu()
{
	system("cls");
	
	int choice;
	while(true)
	{
		system("cls");
	cout << "\n\n  _________________________SUBSCRIBER RECORD DATABASE_________________________";
	cout << "\n\n 1: Enter Subscriber Record ";
	cout << "\n\n 2: Display Subsciber Records in Ascending Order";
	cout << "\n\n 3: Display Subscriber Records in Descending Order";
	cout << "\n\n 4: Search Subscriber ";
	cout << "\n\n 5: Delete Subscriber ";
	cout << "\n\n 6: Check Total No. of Subscriber";
	cout << "\n\n 7: Depth of Specific Node ";
	cout << "\n\n 8: Exit ";
	cout << "\n\n Enter your Choice: ";
	
	label1:
	choice = getch();
	
	if (choice >= '1' && choice <= '9')
	{
		goto label2;
	}
	goto label1;
	
	label2:
	cout << choice-48;
	
	system("cls");
	switch(choice)
	{
		case '1':
			r.insert();
			cout << "\n\n\t";
			system("pause");
			break;
		case '2':
			r.display(1);
			cout << "\n\n\t";
			system("pause");
			break;
		case '3':
			r.display(2);
			cout << "\n\n\t";
			system("pause");
			break;
		case '4':
			r.search();
			cout << "\n\n\t";
			system("pause");
			break;
		case '5':
			r.deleteRecords();
			cout << "\n\n\t";
			system("pause");
			break;
		case '6':
			r.totalNodes();
			cout << "\n\n\t";
			system("pause");
			break;
		case '7':
			r.findDepthOfNode();
			cout << "\n\n\t";
			system("pause");
			break;
		case '8':
			int ch;
			system("cls");
cout<<"\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n";
cin>>ch;
switch (ch)
{
case 1:
	system("cls");
 mainEntrance();


case 0:
		char R[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	srand(time(NULL));
    char color_string[50];

    while(1) {

        int Ra = rand() %16;
        int Rb = rand() %16;
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tThank You";      
        sprintf(color_string, "color %c%c", R[Ra], R[Rb]);
        system(color_string);  		

		system("cls"); 
};

exit(0);
}
			break;		
		default:
			cout << "\n\n Please Enter a valid Choice: \n\n";
			system ("pause");
			break;
		}
	}
}
	
int main()
{

	system("music.wav");
	system("color ce");
	login();	
	while(true)
	
	{
		
			system("cls");
			r.userMenu();
	}    		
	return 0;
}
