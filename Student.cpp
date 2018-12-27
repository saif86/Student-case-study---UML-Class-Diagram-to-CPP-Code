/**
* @file Student.cpp
*
* @brief C++ Program to demostrate Student class.
*
* @author Saif Ullah Ijaz
*
*/

// SYSTEM INCLUDES
#include <iostream> 
#include <string>
using namespace std;

// Student class definition
class Student {
public:
// LIFECYCLE
	/** Default + Overloaded constructor.
	*/
	Student(const string& = "", int = 0, float = 0.0);

	/** Copy constructor.
	*/
	Student(const Student&);

	/** destructor.
	*/
	~Student();

	// Use compiler-generated assignment.
	// Student& operator=(const Student&);

// ACCESS
	// setters
	void SetName(const string& = "");
	void SetGpa(float = 0.0);
	void SetStudent(const string& = "", float = 0.0);
	/**
	# @overload void SetStudent(const Student& aStudent);
	*/
	void SetStudent(const Student& aStudent);

	// getters
	const string& GetName() const;
	int GetRollNo() const;
	float GetGpa() const;
	const Student& GetStudent()const;
	static int sGetTotalStudent();

private:

	// DATA MEMBERS
	string mName;
	const int mRollNo;
	float mGpa;
	// class variable shared by all objects of Student class
	static int msNoOfStudents;
};
// end class Student

// File scope starts here 

/////////////////////////////// PUBLIC ///////////////////////////////////////

//============================= LIFECYCLE ====================================

// Student Default+Overloaded Constructor
Student::Student(const string& aName, int aRollNo, float aGpa) : mName(aName), mRollNo(aRollNo), mGpa(aGpa) {
	cout << "Default+Overloaded constructor" << endl;
	this->SetStudent(aName, aGpa);
	Student::msNoOfStudents++;
}
// end Student constructor 

// Student Copy constructor
Student::Student(const Student& obj) : mName(obj.GetName()), mRollNo(obj.GetRollNo()), mGpa(obj.GetGpa()) {
	cout << "Copy constructor" << endl;
	Student::msNoOfStudents++; // increment no. of students within constructor 
}
// end Student constructor 

// Student destructor
Student::~Student() {
	cout << "Destructor" << endl;
	Student::msNoOfStudents--; // decrement no. of students each time destructor is called 
}
// end ~Student destructor

//============================= ACESS      ===================================

// function that sets name of Student
void Student::SetName(const string& aName) {
	this->mName = aName;
}
// end function SetName

// function that sets GPA of Student
void Student::SetGpa(float aGpa) {
	if (aGpa < 0.0 || aGpa >5.0)
		cout << "Error: Incorrect GPA entered." << endl;
	else
		this->mGpa = aGpa;
}
// end function SetGpa

// function that sets Student
void Student::SetStudent(const string& aName, float aGpa) {
	this->SetName(aName);
	this->SetGpa(aGpa);
}
// end function SetStudent

// overloaded function that sets the Student
void Student::SetStudent(const Student &obj) {
	this->SetStudent(obj.GetName(), obj.GetGpa());
}
// end function SetStudent

// function that gets the name of Student
const string& Student::GetName() const {
	return (this->mName);
}
// end function GetName

// function that gets the roll no. of Student
int Student::GetRollNo() const {
	return this->mRollNo;
}
// end function GetRollNo

// function that gets the GPA of Student
float Student::GetGpa() const {
	return this->mGpa;
}
// end function GetGpa

// function that gets the Student
const Student& Student::GetStudent()const {
	return *this;
}
// end function GetStudent

// static function that gets the total no. of Students
int Student::sGetTotalStudent() {
	return Student::msNoOfStudents;
}
// end function sGetTotalStudent

/*private static member cannot be accessed outside the class except for initialization*/
int Student::msNoOfStudents = 0;	// intitalize class variable 

/////////////////////////////// MAIN   ///////////////////////////////////////

// function main begins program execution
void main() {
	cout << "Number of students in the beginning: " << Student::sGetTotalStudent() << endl;
	Student student1("Saif Ullah Ijaz", 34, 3.32); /*constructor for student1 object is implicitly called at this point*/
	Student student2("Student2");	/*constructor for student2 object is implicitly called at this point*/
	Student student3("Student3", 1);	/*constructor for student3 object is implicitly called at this point*/
	Student student4("Student4", 1, 4.0);	/*constructor for student4 object is implicitly called at this point*/
	
	cout << "STUDENT 1" << endl;
	cout << "Name: " << student1.GetName() << endl;
	cout << "Roll No.: " << student1.GetRollNo() << endl;
	cout << "GPA: " << student1.GetGpa() << endl << endl;
	cout << "STUDENT 2" << endl;
	cout << "Name: " << student2.GetName() << endl;
	cout << "Roll No.: " << student2.GetRollNo() << endl;
	cout << "GPA: " << student2.GetGpa() << endl << endl;
	cout << "STUDENT 3" << endl;
	cout << "Name: " << student3.GetName() << endl;
	cout << "Roll No.: " << student3.GetRollNo() << endl;
	cout << "GPA: " << student3.GetGpa() << endl << endl;
	cout << "STUDENT 4" << endl;
	cout << "Name: " << student4.GetName() << endl;
	cout << "Roll No.: " << student4.GetRollNo() << endl;
	cout << "GPA: " << student4.GetGpa() << endl << endl;
	cout << "Number of students before creating pointer to Student object: " << Student::sGetTotalStudent() << endl;
	
	Student *ptr;	/* constructor is NOT called for pointers*/
	ptr = &student2; /* constructor is NOT called for pointers*/
	cout << "STUDENT 5 (Pointer to Student2 object)" << endl;
	cout << "Name: " << ptr->GetName() << endl;
	cout << "Roll No.: " << ptr->GetRollNo() << endl;
	cout << "GPA: " << ptr->GetGpa() << endl << endl;
	cout << "Number of students after creating pointer to Student object: " << Student::sGetTotalStudent() << endl;

	system("pause");
}
// end main 
