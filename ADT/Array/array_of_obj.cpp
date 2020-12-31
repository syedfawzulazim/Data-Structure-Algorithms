#include <iostream>
#include <string>

using namespace std;

class Student
{
	string name;
	int marks;
	public:
		void getName()
		{
			getline( cin, name );
		}
		void getMarks()
		{
			cin >> marks;
		}
		void displayInfo()
		{
			cout << "Name : " << name << endl;
			cout << "Marks : " << marks << endl;
		}
};

int main()
{
	Student st[5]; ///array of 5 obj

	for( int i=0; i<5; i++ )
	{
		cout << "Student " << i + 1 << endl;
		cout << "Enter name" << endl;
		st[i].getName();
		cout << "Enter marks" << endl;
		st[i].getMarks();
	}

	for( int i=0; i<5; i++ )
	{
		cout << "Student " << i + 1 << endl;
		st[i].displayInfo();
	}
	return 0;
}
