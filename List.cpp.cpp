
#include "List.h"
#include <iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>

using namespace std;

// class constractor
List::List()
{
	noItem = 0;// initial the noItem to 0
	pHead = 0; //intial pHead pointer to 0
}

//class deconstractor 
List::~List() {}

//Function to return the number of item in the list
int List::NumberOfItem()
{
	return noItem;
}

//Add function to get the data from user works when first record added
void List::AddToFront()
{
	string item1, item2, item4; //variables to stor data from user
	int item3;
	int seriesNo;
	Node* pNew = new Node;
	cout << "\nEnter student Name  : ";
	getline(cin, item1);
	cout << "Enter student ID      : ";
	getline(cin, item2);
	cout << "Enter student age     : ";
	cin >> item3;
	cout << "Enter student grade   : ";
	cin >> item4;
	noItem++;// increment noItem
	//here is the node budy 
	seriesNo = noItem;
	pNew->studentData.name = item1;
	pNew->studentData.id = item2;
	pNew->studentData.age = item3;
	pNew->studentData.grade = item4;
	pNew->studentData.bil = seriesNo;
	pNew->link = pHead;
	pHead = pNew;
}

//Add function to get data from user works when one or more students exist in the list
void List::AddToMiddle()
{
	string item1, item2, item4;
	int item3;
	int seriesNo;
	Node* pNew = new Node;
	cout << "\nEnter student name  : ";
	getline(cin, item1);
	cout << "Enter ID             : ";
	getline(cin, item2);
	cout << "Enter student age     : ";
	cin >> item3;
	cout << "Enter student grade   : ";
	cin >> item4;
	if (noItem == 1)
		pCurr = pHead;
	noItem++;
	//node here will be works if one sttudent or more esist in the list
	seriesNo = noItem;
	pNew->studentData.name = item1;
	pNew->studentData.id = item2;
	pNew->studentData.age = item3;
	pNew->studentData.grade = item4;
	pNew->studentData.bil = seriesNo;
	pNew->link = pCurr->link;
	pCurr->link = pNew;
	pCurr = pNew;
}

//Delete function to delet front
void List::removeFront()
{
	pHead = pHead->link;//increment pHead pointer to remove front
	pCurr = pHead;
	noItem--;
	for (int i = 1; i <= noItem; i++)
	{
		pCurr->studentData.id = i;
		pPrev = pCurr;
		pCurr = pCurr->link;
	}

}

//Delete function to delete after the front and above
void List::removeMiddle()
{
	pPrev->link = pCurr->link;
	noItem--;
	pCurr = pHead;
	for (int i = 1; i <= noItem; i++)
	{
		pCurr->studentData.id = i;
		pPrev = pCurr;
		pCurr = pCurr->link;
	}
}

//Remove searched item function return true if item found and false if item not found
bool List::removeSearch(string target1, int& loc)
{
	if (noItem == 0)
		cout << "THERE IS NO DETAIL, LIST IS EMPTY." << endl;
	else
	{
		pCurr = pHead;
		loc = 0;
		while (pCurr->studentData.id != target1 && pCurr->link != 0)
		{
			pPrev = pCurr;
			pCurr = pCurr->link;
			loc++;
		}
		if (pCurr->studentData.id == target1)
			return true;
		else
			return false;
	}
}

//insertion sort function
void List::sortByID()
{
	pCurr = pHead;//assinging pCurr pointer to the first node
	pPrev = pHead;
	pCurr = pCurr->link;
	while (pCurr != NULL)//walk until pCurr is Null
	{
		pPrev = pHead;
		while (pPrev != pCurr)
		{
			if (pPrev->studentData.id > pCurr->studentData.id)
			{
				string temp1, temp2, temp3;
				int temp4;
				// swaping process
				temp1 = pCurr->studentData.name;
				temp2 = pCurr->studentData.id;
				temp4 = pCurr->studentData.age;
				temp3 = pCurr->studentData.grade;

				pCurr->studentData.name = pPrev->studentData.name;
				pCurr->studentData.id = pPrev->studentData.id;
				pCurr->studentData.age = pPrev->studentData.age;
				pCurr->studentData.grade = pPrev->studentData.grade;

				pPrev->studentData.name = temp1;
				pPrev->studentData.id = temp2;
				pPrev->studentData.age = temp4;
				pPrev->studentData.grade = temp3;

			}
			else
			{
				pPrev = pPrev->link;
			}
		}
		pCurr = pCurr->link;
	}
}

//search function 
bool List::searchStudentID(string target, int& loc)
{
	bool found = false;
	if (noItem == 0)
		cout << "THERE IS NO DETAIL FOUND" << endl;
	else
	{
		pCurr = pHead;
		loc = 0;
		while (pCurr->studentData.id != target && pCurr->link != NULL)
		{
			pCurr = pCurr->link;
			loc++;
		}
		if (pCurr->studentData.id == target)
			found = true;
	}
	return found;

}

//Print search function to print searched item in the list
void List::printSearch(int location)
{
	pCurr = pHead;
	int loc = 0;
	while (loc != location && pCurr->link != 0)
	{
		pPrev = pCurr;
		pCurr = pCurr->link;
		loc++;
	}
	cout << left << setw(20) << pCurr->studentData.name;
	cout << left << setw(20) << pCurr->studentData.id;
	cout << left << setw(20) << pCurr->studentData.age;
	cout << left << setw(20) << pCurr->studentData.grade;
}

//Display all records function in the list
void List::displayData()
{
	pCurr = pHead;
	while (pCurr != 0)
	{
		cout << "  " << pCurr->studentData.bil << "     ";
		cout << left << setw(20) << pCurr->studentData.name;
		cout << left << setw(20) << pCurr->studentData.id;
		cout << left << setw(20) << pCurr->studentData.age;
		cout << left << setw(20) << pCurr->studentData.grade;
		pCurr = pCurr->link;
		cout << endl;
	}
}
//traverse function
bool List::Traverse()
{
	pCurr = pHead;
	while (pCurr->link != NULL)
	{
		pPrev = pCurr;
		pCurr = pCurr->link;
	}
	if (pCurr->link == NULL)
		return true;
	else
		return false;
}

//clear list function
void List::clearList()
{
	pCurr;
	while (pHead != NULL)
	{
		pCurr = pHead;
		pHead = pHead->link;
		delete pCurr;
	}
	pTail = NULL;
	noItem = 0;
}

//display the data from file
void List::displayOutput()
{
	outfile.open("info.txt");
	pCurr = pHead;
	while (pCurr != 0)
	{
		outfile << "  " << pCurr->studentData.bil << "     ";
		outfile << left << setw(20) << pCurr->studentData.name;
		outfile << left << setw(20) << pCurr->studentData.id;
		outfile << left << setw(20) << pCurr->studentData.age;
		outfile << left << setw(20) << pCurr->studentData.grade;
		pCurr = pCurr->link;
		outfile << endl;
	}
	outfile.close();
}

//AddToFrontInput function to input data to the file
void List::AddToFrontInput(int seriesNo, string item1, string item2, int item3, string item4)
{
	Node* pNew = new Node;
	noItem++;
	seriesNo = noItem;
	pNew->studentData.name = item1;
	pNew->studentData.id = item2;
	pNew->studentData.age = item3;
	pNew->studentData.grade = item4;
	pNew->studentData.bil = seriesNo;
	pNew->link = pHead;
	pHead = pNew;
}

//AddingTomiddleInput function to input data to the file
void List::AddToMiddleInput(int seriesNo, string item1, string item2, int item3, string item4)
{
	Node* pNew = new Node;
	if (noItem == 1)
		pCurr = pHead;
	noItem++;
	seriesNo = noItem;
	pNew->studentData.name = item1;
	pNew->studentData.id = item2;
	pNew->studentData.age = item3;
	pNew->studentData.grade = item4;
	pNew->studentData.bil = seriesNo;
	pNew->link = pCurr->link;
	pCurr->link = pNew;
	pCurr = pNew;
}



void login();

//Main function 
void main()
{
	List mylist; 
	string target, name, id, grade, target1;
	int age, bil, location, choice;
	char backOption, choice1;

	login();
	system("cls");
	system("color F5");
	Sleep(500);


	ifstream infile;
	infile.open("info.txt"); //file name
	while (infile >> bil >> name >> id >> age >> grade)
	{
		if (mylist.NumberOfItem() == 0)
			mylist.AddToFrontInput(bil, name, id, age, grade);
		else
			mylist.AddToMiddleInput(bil, name, id, age, grade);
	}
	infile.close();


	do
	{ //Main menu page
		cout << "\n\n\t\t**********" << " MENU " << "**********" << endl;
		cout << "\n\t\t============================\n\t\t1. ADD STUDENT\n\t\t2. DISPLAY RECORDS"
        "\n\t\t3. SORT BY STUDENT ID \n\t\t4. SEARCH BY STUDENT ID \n\t\t5. DELETE STUDENT\n\t\t"
	    "6. CLEAR LIST \n\t\t7. EXIT\n\t\t============================\n\n";
		cout << "\t\tPlease Enter your Option: ";
		cin >> choice;
		cin.ignore();
		cout << endl;
		system("cls");

		switch (choice)
		{
		case 1: // Add function call
			cout << "\n\t-----ADD STUDENT-----\n";
			if (mylist.NumberOfItem() == 0)
			{
				mylist.AddToFront();
				cout << "\nAdd some more? (Y=yes, N=no) : ";
				cin >> choice1;
				cin.ignore();
				if ((choice1 == 'Y') || (choice1 == 'y'))
				{
					do
					{
						mylist.AddToMiddle();
						cout << "\nAdd some more? (Y=yes, N=no) : ";
						cin >> choice1;
						cin.ignore();
					} while ((choice1 == 'Y') || (choice1 == 'y'));
				}
				else
					break;
			}
			else
				if (mylist.Traverse() == true)
				{
					do
					{
						mylist.AddToMiddle();
						cout << "\nAdd more? (Y=yes, N=no) : ";
						cin >> choice1;
						cin.ignore();
					} while ((choice1 == 'Y') || (choice1 == 'y'));
				}
			cout << "\nSTUDENT SUCCESSFULLY ADDED!\n";
			break;

		

		case 2: //Display function call
			cout << "\n\t-----STUDENT DETAILS-----\n\n";


			cout << left << setw(8) << "-----" << left << setw(20) << "----------" << left << setw(20)
				<< "----------" << left << setw(20) << "----------" << left << setw(20) << "----------" << endl;
			cout << left << setw(8) << " No. " << left << setw(20) << "Name " << left << setw(20) << "ID "
				<< left << setw(20) << "Age " << left << setw(20) << "Grade " << endl;
			cout << left << setw(8) << "-----" << left << setw(20) << "----------" << left << setw(20)
				<< "----------" << left << setw(20) << "----------" << left << setw(20) << "----------" << endl;


			mylist.displayData();
			cout << endl << "Total : " << mylist.NumberOfItem() << endl;
			break;


		case 3: //insertion sort function call
			system("cls");
			cout << "\n-----STUDENT SORTED BY ID -----\n\n";
			mylist.sortByID();


			cout << left << setw(8) << "-----" << left << setw(20) << "----------" << left << setw(20)
				<< "----------" << left << setw(20) << "----------" << left << setw(20) << "----------" << endl;
			cout << left << setw(8) << " No. " << left << setw(20) << "Name " << left << setw(20) << "ID "
				<< left << setw(20) << "Age " << left << setw(20) << "Grade " << endl;
			cout << left << setw(8) << "-----" << left << setw(20) << "----------" << left << setw(20)
				<< "----------" << left << setw(20) << "----------" << left << setw(20) << "----------" << endl;


			mylist.displayData();
			cout << endl << "Total : " << mylist.NumberOfItem() << endl;
			break;


		case 4: //Search function call
			cout << "\n-----SEARCH BY SUDENT ID -----" << "\n\nEnter Sudent ID. : ";
			getline(cin, target);
			cout << endl;


			cout << left << setw(20) << "----------" << left << setw(20) << "----------" << left << setw(20)
				<< "----------" << left << setw(20) << "----------" << endl;
			cout << left << setw(20) << "Name" << left << setw(20) << "ID" << left << setw(20)
				<< "Age" << left << setw(20) << "Grade" << endl;
			cout << left << setw(20) << "----------" << left << setw(20) << "----------" << left << setw(20)
				<< "----------" << left << setw(20) << "----------" << endl;


			if (mylist.searchStudentID(target, location) == true) {
				mylist.printSearch(location);
				cout << endl;
			}

			else
				cout << "/nSTUDENT IS NOT FOUND\n\n";
			break;


		case 5:  //Delet function call
			do
			{
				system("cls");
				cout << "\n\t\t\t-----DELETE STUDENT-----\n\n";
				cout << left << setw(8) << "-----" << left << setw(20) << "----------" << left << setw(20)
					<< "----------" << left << setw(20) << "----------" << left << setw(20) << "----------" << endl;
				cout << left << setw(8) << " No. " << left << setw(20) << "Name " << left << setw(20)
					<< "ID " << left << setw(20) << "Age " << left << setw(20) << "Grade " << endl;
				cout << left << setw(8) << "-----" << left << setw(20) << "----------" << left << setw(20)
					<< "----------" << left << setw(20) << "----------" << left << setw(20) << "----------" << endl;


				mylist.displayData();
				cout << "\nENTER STUDENT ID TO DELETE. : \n";
				cin >> target1;

				if (mylist.removeSearch(target1, location) == true)
				{
					if (location == 0)
					{
						mylist.removeFront();
					}
					else
					{
						mylist.removeMiddle();
					}
					cout << "\STUDENT SUCCESSFULLY DELETED.\n";
				}
				else
					cout << "\nYOU ENTERED WRONG ID.\n";

				cout << "\nDelete more? (Y=yes, N=no) : ";
				cin >> choice1;
				cin.ignore();
			} while ((choice1 == 'Y') || (choice1 == 'y'));
			break;


		case 6: //clear list function
			mylist.clearList();
			cout << "\n\t... LIST IS EMPTY NOW ...\n\n";
			break;


		case 7: //Exit function
			mylist.displayOutput();
			cout << "************************ THANKS ************************************\n\n\n";
			exit(EXIT_FAILURE);
			break;

		default:
			cout << "\n\tINVALID INPUT";
		}


		cout << "\nBACK TO MAIN MENU? (Y=yes, N=no) : ";
		cin >> backOption;
		system("cls");
	} while ((backOption == 'Y') || (backOption == 'y'));//end of do while loop of repeating the operation
	{
		mylist.displayOutput();
		cout << "\n. . . EXITING SYSTEM . . .\n\n";
	}
}//end of main function


// Login function 
// the user name is radwan.. password is 1234
void login()
{
	char user_in[20] = { 0 };
	double password_in;

	int i = 0;
	char name_in[20] = { 0 };

	int choi;
	system("color 4f ");
	cout << "\n\n\n\t\t****** Welcome to student informarion system ******\n" << endl;
	cout << "\n\t\t\tThis project was done by";
	cout << "\n\n\t\t\tRadwan, Abdullah, Mohammed, Zaki and Ameen ...\n\n";
	cout << "\n\t\t\tTo log in press ( 1 ) ..\n\t\t\tTo logout press ( 2 ) ..\n";
	cout << "\t\t\t\t\t";
	cin >> choi;
	if (choi == 1)
	{
		cout << "\n\t\t\tuser name: ";
		cin >> user_in;
		cout << endl;
		Sleep(200);
		cout << "\t\t\tpassword :";
		cin >> password_in;
		cout << endl;
		Sleep(600);
		char user[20];
		double password;
		int u;
		int n;


		ifstream inputFile("user_pass.txt", ios::in);

		while (inputFile >> user >> password)
		{
			u = strcmp(user, user_in);

			if ((u == 0) && (password == password_in))
				n = 0;
		}
		if (n == 0) {
			cout << " wrong user name and password\n please try again" << endl;
			return;
		}

		else

			cout << "\a";
		cout << "\a";
		system("pause");
		system("cls");
		main();
	}
	else
		exit(1);


}
