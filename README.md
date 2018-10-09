# UML-Class-Diagram-to-CPP-Code
Example of converting a UML Class diagram to C++ class

## UML Class Diagram
![class](https://user-images.githubusercontent.com/41892175/46647021-3c434100-cbc0-11e8-8f93-d4d955c180ec.jpg)

*where*
  * *vis* = visibility (+ for public, - for private)
  * *attribute* = data member (aka field)
  * *operation* = method (or constructor)

###Note:
  * The *arg list* is a list of parameter types (e.g., int, double, String); parameter names are **not** included in the UML class diagram
  * Methods that don't return a value (i.e. void methods) should give a *return type* of void
  * Class (i.e. static) methods and fields are indicated by underlining
  * Constant (i.e. final) fields are indicated via naming convention: constants should be in ALL_CAPS
  
## Example: Student UML Class diagram
![student](https://user-images.githubusercontent.com/41892175/46647747-626ae000-cbc4-11e8-8e63-acd965239826.png)

## Corresponding C++ Class
```
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

/* Destructor*/
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
```

