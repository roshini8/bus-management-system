#pragma once

#ifndef Class_H
#define Class_H

#include<fstream>
#include <string>
using namespace std;

// input and output file
ifstream infile;
ofstream outfile;

class Class
{
private:
	struct student
	{ //variables for students data
		int bil;
		string name;
		string id;
		int age;
		string grade;
	};

	//class for node 
	class Node
	{
	public:
		student busdata;
		Node* link;
	};

	//the calss pointers
	Node* pHead;
	Node* pCurr;
	Node* pPrev;
	Node* pTail;


	int noItem; // Variavle for number of item exist in the Class

public:

	// The methods

	Class(); //constractor

	~Class(); //deconstractor

	void InsertToFront();

	void InsertToFrontInput(int, string, string, int, string);

	void deleteFront();

	void InsertToMiddle();

	void InsertToMiddleInput(int, string, string, int, string);

	void deleteMiddle();

	int NumberOfItem();

	bool removeSearch(string, int&);

	bool searchStudentBy_ID(string, int&);

	void printSearch(int);

	void sortBy_ID();

	bool Traverse();

	void displayData();

	void displayOutput();

	void clearClass();

};
#endif


