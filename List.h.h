#ifndef HEADER_H
#define HEADER_H
#include<fstream>
#include <string>
using namespace std;

ifstream infile;
ofstream outfile;

class List
{
private:
	struct student
	{
		int bil; //variable to hold the series number sequence in the list
		string name;
		string id;
		int age;
		string grade;
	};
	class Node
	{
	public:
		student studentData;
		Node* link;
	};
	
	//Calss pointers
	Node* pHead;
	Node* pCurr;
	Node* pPrev;
	Node* pTail;
	// Variavle to hold number of item exist in the list
	int noItem;

public:
	List();
	~List();
	void AddToFront();
	void AddToMiddle();
	void removeFront();
	void removeMiddle();
	int NumberOfItem();
	bool removeSearch(string, int&);
	bool searchStudentID(string, int&);
	void sortByID();
	void printSearch(int);
	void displayData();
	bool Traverse();
	void clearList();
	void displayOutput();
	void AddToFrontInput(int, string, string, int, string);
	void AddToMiddleInput(int, string, string, int, string);

};
#endif
