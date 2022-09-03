#include<iostream>
#include<cstdlib>				
#include<fstream>
#include<string>
#include<cstring>
#include<windows.h>
#include<algorithm>
using namespace std;

template<typename t>
void extend(t*& arr, int size)
{
	if (size > 0)
	{
		t* temp = new t[size];			
		for (int i = 0; i < size; i++)	
		{
			temp[i] = arr[i];			 
		}
		delete[] arr;
		arr = new t[size + 1];			
		
		for (int i = 0; i < size; i++)
		{
			arr[i] = temp[i];
		}
	}

	else
	{
		arr = new t[size + 1];
	}
}

class player
{
public:
	int id;
	string name;

	player()
	{
		id = 0;
		name = '0';
	}
	
	player(int _id, string n)
	{
		id = _id;
		name = n;
	}

};

class strings
{
public:
	int id = 0;
	string ss;
	
	void entry(int i, string s)
	{
		id = i;
		ss = s;
	}
	
	void print()
	{
		cout << id <<" ";
		cout << ss;
		cout << endl;
	}
};

class questions
{
public:
	int id;
	string ss;
	string ht;

	void entry(int i, string s, string h)
	{
		id = i;
		ss = s;
		ht = h;
	}
	
	void print()
	{
		cout << id << " ";
		cout << ss << endl;
		cout << ht;
		cout << endl;
	}
};

template <typename t>
class stack
{
	class node
	{
	public:
		t data;
		node* next;
	};
		
	node* head;
	int count;

public:
	stack()
	{
		head = NULL;
		count = 0;
	}

	/*int size()
	{
		return count;
	}*/

	/*bool isEmpty()
	{
		if (count == 0)
		{
			return true;
		}
		return false;
	}*/

	/*void pop()
	{
		node* temp = new node;
		temp = head;
		head = head->next;
		delete temp;
		count--;
	}*/

	void push(t const& tmp)
	{
		node* temp = new node;
		temp->data = tmp;
		temp->next = head;
		head = temp;
		count++;
	}

	void print()
	{
		node* current = new node;
		current = head;
		while (current)
		{
			cout << current->data << endl;
			current = current->next;
		}
		cout << endl;
	}

	void historyprinting(stack<t>p2, stack<t>p3, stack<t>p4)
	{
		int i = 1;
		node* c1 = new node;
		node* c2 = new node;
		node* c3 = new node;
		node* c4 = new node;
		c1 = head;
		c2 = p2.head;
		c3 = p3.head;
		c4 = p4.head;
		while (c1)
		{
			cout << i << endl;
			cout << "Question: " << c1->data << endl; 
			cout << "Answer: " << c2->data << endl;
			cout << "Activity: " << c3->data << endl; 
			cout << "Result: " << c4->data << endl;
			i++;
			c1 = c1->next;
			c2 = c2->next;
			c3 = c3->next;
			c4 = c4->next;
		}
		cout << endl;
	}
};

void readfromfileQ(questions*& arr, int& size, string filename)
{
	string temp;
	string temp1;
	int num;
	ifstream fin(filename);
	for (int i = 0; !fin.eof(); i++)
	{
		fin >> num;

		fin.ignore();

		getline(fin, temp);
		getline(fin, temp1);
		extend(arr, size);
		arr[size].entry(num, temp, temp1);
		size++;
	}
	fin.close();
}
void readfromfile(strings*& arr, int& size, string filename)
{
	string temp;
	int num;
	ifstream fin(filename);
	for (int i = 0; !fin.eof(); i++)
	{
		fin >> num;
		fin.ignore();

		getline(fin, temp);

		extend(arr, size);
		arr[size].entry(num, temp);
		size++;
	}
	fin.close();
}


template<typename t>
int questionselector(t* &arr, int size)
{
	int num = 0;
	srand(unsigned(time(NULL)));
	num = 1 + (rand() % size);
	//cout << num;
	int temp =0;
	for (int i = 0; i < size; i++)
	{
		if (num == arr[i].id)
		{
			temp = i;
		}
	}
	return temp;
}

bool answercheck(strings* &arr, string userinput, int id)
{
	if (userinput.compare(arr[id].ss) == 0)		
	{
		cout << "Answer is correct" << endl;
		return true;
	}

	else
	{
		cout << "Answer is incorrect" << endl;
		return false;
	}
}

int strlen(string s)
{
	int i = 0; 
	while (s[i] != '\0')
	{
		i++;
	}
	return i;
}


int main() 
{
	stack<int>p1scorehistory;					
	stack<int>p2scorehistory;
	stack<string>p1question;
	stack<string>p2question;
	stack<string>p1answer;
	stack<string>p2answer;
	stack<string>p1activity;
	stack<string>p2activity;
	stack<string>p1success;
	stack<string>p2success;
	
	int size = 0;
	int size1 = 0;
	int size2 = 0;

	player p1;
	player p2;
	
	int scorep1 = 0;
	int scorep2 = 0;

	questions *question = new questions[size];			////
	strings* answers = new strings[size1];
	strings* dare = new strings[size2];

	string filename = {"Questions.txt"};		
	string filename1 = { "Answers.txt" };
	string filename2 = { "DareQ.txt" };

	readfromfileQ(question, size, filename);
	readfromfile(answers, size1, filename1);
	readfromfile(dare, size2, filename2);

	/*for (int i = 0; i < size; i++)
	{
		question[i].print();
	}
	
	for (int i = 0; i < size1; i++)
	{
		answers[i].print();
	}

	for (int i = 0; i < size2; i++)
	{
		dare[i].print();
	}*/

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t  Loading ";

	for (int a = 0; a <= 15; a++)
	{
		cout << " |";

		if (a < 5)
		{
			Sleep(250);
		}

		if (a >= 5 && a < 10)
		{
			Sleep(175);
		}

		if (a >= 10 && a <= 15)
		{
			Sleep(100);
		}
	}

	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t -------------------------------------------------" << endl;
	cout << "\t\t\t\t|                Riddles & Dare Game              |" << endl;
	cout << "\t\t\t\t -------------------------------------------------";
	Sleep(3250);
	system("cls");

	cout << "\n\t\t\t\t\tEnter Player 1 name" << endl;
	cout << "\n\t\t\t\t\t";
	cin >> p1.name;
	p1.id = 1;
	cout << endl;
	cout << "\n\t\t\t\t\tEnter Player 2 name" << endl;
	cout << "\n\t\t\t\t\t";
	cin >> p2.name;
	p2.id = 2;
	cout << endl;
	cout << endl;
	cout << "\t\t\t\t\t -----------------------------------------------" << endl;
	cout << "\t\t\t\t\t              Player 1 is " << p1.name << endl;
	cout << "\t\t\t\t\t              Player 2 is " << p2.name << endl;
	cout << "\t\t\t\t\t -----------------------------------------------" << endl;
	Sleep(2000);
	system("cls");

	int var = 0;
	while (var != 3)
	{
		cout << "Press 1 to play game" << endl;
		cout << "Press 2 for the game history" << endl;
		cout << "Press 3 to exit" << endl;
		cin >> var;
		int playerchoose;
		srand(unsigned(time(NULL)));
		playerchoose = 1 + (rand() % 2);
		
		if (var == 1)
		{
			if (playerchoose == 1)
			{
				cout << p1.name << " Turns" << endl;
				cout << "Press 1 to choose riddle" << endl;
				cout << "Press 2 to choose dare" << endl;
				int userchoice;
				cin >> userchoice;
				if (userchoice == 1)
				{
					p1activity.push("riddles");
					int id = questionselector(question, size);
					cout << question[id].ss << endl;				
					cout << question[id].ht << endl;				
					p1question.push(question[id].ss);				

					string userinput;
					cout << "Please enter your answer" << endl;
					cin.ignore();
					getline(cin, userinput);
					transform(userinput.begin(), userinput.end(), userinput.begin(), ::tolower);
					p1answer.push(userinput);

					bool result = answercheck(answers, userinput, id);
					
					if (result == true)
					{
						scorep1++;
						p1success.push("Successful");
					}

					else
					{
						p1success.push("Unsuccessful");
					}
					
					cout << p1.name << " score is " << scorep1 << endl << endl;
					p1scorehistory.push(scorep1);
					Sleep(1500);
					system("cls");
				}

				else if (userchoice == 2)
				{
					p1activity.push("Dare");
					int id = questionselector(dare, size2);
					//cout << dare[id].ss << endl;
					p1question.push(dare[id].ss);
					string copy = dare[id].ss; 
					string duplicate = dare[id].ss;
					int n = strlen(copy);
					cout << "Length of Pattern: " << n << endl;
					for (int i = 0; i < n; ++i)				///Duplicates Remover
						for (int j = i + 1; j < n;)
						{
							if (copy[i] == copy[j])				////AbcAde //AbcdAe //AbcdeA ///Abcde
													/////Abbaacb		AABA
							{
								for (int k = j; k < n - 1; ++k) //abc
									copy[k] = copy[k + 1];
								--n;
							}
							else
								++j;
						}
					for (int i = 0; i < n; i++)				// n ma no of distinct elements store hain
					{
						int count = 0;
						for (int j = 0; duplicate[j] != '\0'; j++)
						{
							if (copy[i] == duplicate[j])
							{
								count++;
							}
						}
						cout << "Occurence: " << copy[i] << " " << count << endl;
					}
					string userinput;
					cout << "\nGuess the Pattern " << endl;
					cin >> userinput;
					p1answer.push(userinput);
					
					if (userinput.compare(dare[id].ss) == 0)
					{
						cout << "Answer is Correct" << endl;
						scorep1++;
						p1success.push("Successful");
					}

					else
					{
						cout << "Answer is Incorrect" << endl;
						p1success.push("Unsuccessful");
					}

					cout << p1.name << " score is " << scorep1 << endl << endl;
					p1scorehistory.push(scorep1);
					Sleep(1500);
					system("cls");
				}
				
				else
				{
					cout << "Enter Valid Number. Renter your choice" << endl;
					cin >> userchoice;
				}
			}

			else if (playerchoose == 2)
			{
				cout <<p2.name << " Turns" << endl;
				cout << "Press 1 to choose riddle" << endl;
				cout << "Press 2 to choose dare" << endl;
				int userchoice;
				cin >> userchoice;
				if (userchoice == 1)
				{
					p2activity.push("riddles");
					int id = questionselector(question, size);
					cout << question[id].ss << endl;
					cout << question[id].ht << endl;
					p2question.push(question[id].ss);

					string userinput;
					cout << "Please enter your answer" << endl;
					cin.ignore();
					getline(cin, userinput);
					transform(userinput.begin(), userinput.end(), userinput.begin(), ::tolower);
					p2answer.push(userinput);

					bool result = answercheck(answers, userinput, id);
					if (result == true)
					{
						scorep2++;
						p2success.push("Successful");
					}
					else 
					{
						p2success.push("Unsuccessful");
					}
					
					cout << p2.name << " score is " << scorep2 << endl << endl;
					p2scorehistory.push(scorep2);
					Sleep(1500);
					system("cls");
				}

				else if (userchoice == 2)
				{
					p2activity.push("Dare");
					int id = questionselector(dare, size2);
					//cout << dare[id].ss << endl;
					p2question.push(dare[id].ss);
					string copy = dare[id].ss;
					string duplicate = dare[id].ss;
					int n = strlen(copy);
					cout << "Length of Pattern: " << n << endl;
					for (int i = 0; i < n; ++i)
						for (int j = i + 1; j < n;)
						{
							if (copy[i] == copy[j])
							{
								for (int k = j; k < n - 1; ++k)
									copy[k] = copy[k + 1];
								--n;
							}
							else
								++j;
						}
					for (int i = 0; i < n; i++)
					{
						int count = 0;
						for (int j = 0; duplicate[j] != '\0'; j++)
						{
							if (copy[i] == duplicate[j])
							{
								count++;
							}
						}
						cout << "Occurence: " << copy[i] << " " << count << endl;
					}
					string userinput;
					cout << "\nGuess the Pattern " << endl;
					cin >> userinput;
					p2answer.push(userinput);
					if (userinput.compare(dare[id].ss) == 0)
					{
						cout << "Answer is Correct" << endl;
						scorep2++;
						p2success.push("Successful");
					}
					else
					{
						cout << "Answer is Incorrect" << endl;
						p2success.push("Unsuccessful");
					}
					cout << p2.name << " score is " << scorep2 << endl << endl;
					p2scorehistory.push(scorep2);
					Sleep(1500);
					system("cls");
				}
				else
				{
					cout << "Enter Valid Number. Renter your choice" << endl;
					cin >> userchoice;
				}
			}
		}

		else if (var == 2)
		{
			cout << "Press 1 to see " << p1.name << " history" << endl;
			cout << "Press 2 to see " << p2.name << " history" << endl;
			int choice = 0;
			cin >> choice;
			if (choice == 1)
			{								
				system("cls");
				p1question.historyprinting(p1answer, p1activity, p1success);
				cout << "Score History" << endl;
				p1scorehistory.print();
				Sleep(5000);
				system("cls");
			}
			
			else if(choice == 2)
			{
				system("cls");
				p2question.historyprinting(p2answer, p2activity, p2success);
				cout << "Score History" << endl;
				p2scorehistory.print();
				Sleep(5000);
				system("cls");
			}

			else
			{
				cout << "Invalid Value" << endl;
			}
		}

		else if (var == 3)
		{
			
			cout << "\n\n";
			cout << "\t\t\t\t -------------------------------------------------" << endl;
			cout << "\t\t\t\t\t\t" << p1.name << " score = " << scorep1 << endl;
			cout << "\t\t\t\t\t\t" << p2.name << " score = " << scorep2 << endl;
			cout << "\t\t\t\t -------------------------------------------------";
			if (scorep1 == scorep2)
			{
				cout << "\n\n\t\t\t\t------------------------------------------------------" << endl;
				cout << "\t\t\t\t\t\t\tMatch draw" << endl;
				cout << "\t\t\t\t------------------------------------------------------" << endl;

			}

			else if (scorep1 > scorep2)
			{
				cout << "\n\n\t\t\t\t ------------------------------------------------------" << endl;
				cout << "\t\t\t\t\t\t\t" << p1.name << " Wins" << endl;
				cout << "\t\t\t\t ------------------------------------------------------" << endl;
			}
			else
			{
				cout << "\n\n\t\t\t\t ------------------------------------------------------" << endl;
				cout << "\t\t\t\t\t\t\t" << p2.name << " Wins" << endl;
				cout << "\t\t\t\t ------------------------------------------------------" << endl;
				break;
			}
		}
		else
		{
			cout << "Enter Valid Value" << endl;
		}
	}
}