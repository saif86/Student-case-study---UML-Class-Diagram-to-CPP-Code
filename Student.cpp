#include<iostream>
#include<cstring>

using std::cout;
using std::endl;
using std::cin;

class Student {
	char *name;
	const int ROLL_NO;
	float gpa;
	static int noOfStudents;
public:
	Student(char *, int, float);
	Student(const Student &);
	~Student();
	void setName(char *);
	void setGpa(float);
	int getROLL_NO() const;
	char * getName() const;
	float getGpa() const;
	static int getTotalStudent();
};
/*private static member cannot be accessed outside the class except for initialization*/
int Student::noOfStudents = 0;

/* Overloaded constructor with default values assigned using member initializer list*/
Student::Student(char *aName = "", int aRollNo = 0, float aGPA = 0.0) : name(aName), ROLL_NO(aRollNo), gpa(aGPA) {
	noOfStudents++;
}

/* Copy constructor with deep copy for pointer members*/
Student::Student(const Student &obj) : ROLL_NO(obj.ROLL_NO), gpa(obj.gpa) {
	int len = strlen(obj.name);
	name = new char[len + 1];
	strcpy_s(name, len + 1, obj.name);
	noOfStudents++;
}

/**/
Student::~Student() {
	noOfStudents--;
}

void Student::setName(char * aName) {


	strcpy_s(name, strlen(aName), aName);

}
void Student::setGpa(float aGPA) {
	if (aGPA < 0.0) {
		gpa = 0.0;
	}
	else
	{
		gpa = aGPA;
	}
}

int Student::getROLL_NO()const {
	return ROLL_NO;
}

char * Student::getName() const {
	return name;
}

float Student::getGpa() const {
	return gpa;
}

int Student::getTotalStudent() {
	return noOfStudents;
}

void main()
{
	cout << "Number of students in the beginning: " << Student::getTotalStudent() << endl;
	Student student1("Saif Ullah Ijaz",34,3.32); /*constructor for student1 object is implicitly called at this point*/
	Student student2("Student2");	/*constructor for student2 object is implicitly called at this point*/
	Student student3("Student3", 1);	/*constructor for student3 object is implicitly called at this point*/
	Student student4("Student4", 1, 4.0);	/*constructor for student4 object is implicitly called at this point*/
	Student *ptr;	/* constructor is NOT called for pointers*/
	ptr = &student2; /*constructor for ptr is implicitly called at this point*/

	cout << "STUDENT 1" << endl;
	cout << "Name: " << student1.getName() << endl;
	cout << "Roll No.: " << student1.getROLL_NO() << endl;
	cout << "GPA: " << student1.getGpa() << endl << endl;
	cout << "STUDENT 2" << endl;
	cout << "Name: " << student2.getName() << endl;
	cout << "Roll No.: " << student2.getROLL_NO() << endl;
	cout << "GPA: " << student2.getGpa() << endl << endl;
	cout << "STUDENT 3" << endl;
	cout << "Name: " << student3.getName() << endl;
	cout << "Roll No.: " << student3.getROLL_NO() << endl;
	cout << "GPA: " << student3.getGpa() << endl << endl;
	cout << "STUDENT 4" << endl;
	cout << "Name: " << student4.getName() << endl;
	cout << "Roll No.: " << student4.getROLL_NO() << endl;
	cout << "GPA: " << student4.getGpa() << endl << endl;
	cout << "Number of students before creating pointer to Student object: " << Student::getTotalStudent() << endl;
	cout << "STUDENT 5 (Pointer to Student2 object)" << endl;
	cout << "Name: " << ptr->getName() << endl;
	cout << "Roll No.: " << ptr->getROLL_NO() << endl;
	cout << "GPA: " << ptr->getGpa() << endl << endl;
	cout << "Number of students after creating pointer to Student object: : " << Student::getTotalStudent() << endl;

	system("pause");
}