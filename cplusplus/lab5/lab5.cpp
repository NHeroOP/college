#include <iostream>
#include <string>
using namespace std;

// Q1. Student Information System
class Student {
protected:
  string name;
  int rollNumber;
  int age;

public:
  Student() {
  }

  Student(string name, int rollNumber, int age) {
    this->name = name;
    this->rollNumber = rollNumber;
    this->age = age;
  }
};

class EngineeringStudent : public Student {
  string branch;
  int semester;

public:
  EngineeringStudent(string name, int rollNumber, int age, string branch, int semester)
    : Student(name, rollNumber, age) {
    this->branch = branch;
    this->semester = semester;
  }

  void display() {
    cout << "Name: " << name << endl;
    cout << "Roll Number: " << rollNumber << endl;
    cout << "Age: " << age << endl;
    cout << "Branch: " << branch << endl;
    cout << "Semester: " << semester << endl;
  }
};


// Q2. Employee Management System
class Employee {
protected:
  int employeeId;
  string name;

public:
  Employee() {
  }

  Employee(int employeeId, string name) {
    this->employeeId = employeeId;
    this->name = name;
  }
};

class Manager : public Employee {
  string department;
  double salary;

public:
  Manager(int employeeId, string name, string department, double salary)
    : Employee(employeeId, name) {
    this->department = department;
    this->salary = salary;
  }

  void display() {
    cout << "Employee ID: " << employeeId << endl;
    cout << "Name: " << name << endl;
    cout << "Department: " << department << endl;
    cout << "Salary: " << salary << endl;
  }
};


// Q3. Library Management System
class Book {
protected:
  string title;
  string authorName;

public:
  Book() {
  }

  Book(string title, string authorName) {
    this->title = title;
    this->authorName = authorName;
  }
};

class EBook : public Book {
  double fileSize;
  string fileFormat;

public:
  EBook(string title, string authorName, double fileSize, string fileFormat)
    : Book(title, authorName) {
    this->fileSize = fileSize;
    this->fileFormat = fileFormat;
  }

  void display() {
    cout << "Title: " << title << endl;
    cout << "Author: " << authorName << endl;
    cout << "File Size: " << fileSize << " MB" << endl;
    cout << "File Format: " << fileFormat << endl;
  }
};


// Q4. Vehicle Registration System
class Vehicle {
protected:
  string registrationNumber;
  string companyName;

public:
  Vehicle() {
  }

  Vehicle(string registrationNumber, string companyName) {
    this->registrationNumber = registrationNumber;
    this->companyName = companyName;
  }
};

class Car : public Vehicle {
  string fuelType;
  int engineCapacity;

public:
  Car(string registrationNumber, string companyName, string fuelType, int engineCapacity)
    : Vehicle(registrationNumber, companyName) {
    this->fuelType = fuelType;
    this->engineCapacity = engineCapacity;
  }

  void display() {
    cout << "Car" << endl;
    cout << "Registration Number: " << registrationNumber << endl;
    cout << "Company Name: " << companyName << endl;
    cout << "Fuel Type: " << fuelType << endl;
    cout << "Engine Capacity: " << engineCapacity << " CC" << endl;
  }
};

class Bike : public Vehicle {
  string fuelType;
  int engineCapacity;

public:
  Bike(string registrationNumber, string companyName, string fuelType, int engineCapacity)
    : Vehicle(registrationNumber, companyName) {
    this->fuelType = fuelType;
    this->engineCapacity = engineCapacity;
  }

  void display() {
    cout << "Bike" << endl;
    cout << "Registration Number: " << registrationNumber << endl;
    cout << "Company Name: " << companyName << endl;
    cout << "Fuel Type: " << fuelType << endl;
    cout << "Engine Capacity: " << engineCapacity << " CC" << endl;
  }
};


// Q5. Banking System Using Function Overriding
class Account {
protected:
  int accountNumber;
  double balance;

public:
  Account(int accountNumber, double balance) {
    this->accountNumber = accountNumber;
    this->balance = balance;
  }

  virtual void display() {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: " << balance << endl;
  }
};

class SavingsAccount : public Account {
public:
  SavingsAccount(int accountNumber, double balance)
    : Account(accountNumber, balance) {
  }

  void display() {
    cout << "Savings Account" << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: " << balance << endl;
  }
};

class CurrentAccount : public Account {
public:
  CurrentAccount(int accountNumber, double balance)
    : Account(accountNumber, balance) {
  }

  void display() {
    cout << "Current Account" << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: " << balance << endl;
  }
};


// Q6. Template Functions
template <class T>
T larger(T firstValue, T secondValue) {
  if (firstValue > secondValue)
    return firstValue;
  else
    return secondValue;
}

template <class T>
void swapValues(T &firstValue, T &secondValue) {
  T temporaryValue = firstValue;
  firstValue = secondValue;
  secondValue = temporaryValue;
}


// Q7. Template Class for Pair
template <class T>
class Pair {
  T firstValue;
  T secondValue;

public:
  Pair(T firstValue, T secondValue) {
    this->firstValue = firstValue;
    this->secondValue = secondValue;
  }

  void display() {
    if (firstValue > secondValue) {
      cout << "Maximum: " << firstValue << endl;
      cout << "Minimum: " << secondValue << endl;
    } else {
      cout << "Maximum: " << secondValue << endl;
      cout << "Minimum: " << firstValue << endl;
    }
  }
};


// Q8. Generic Array Class
template <class T>
class Array {
  T elements[5];

public:
  void input() {
    for (int i = 0; i < 5; i++)
      cin >> elements[i];
  }

  void display() {
    for (int i = 0; i < 5; i++)
      cout << elements[i] << " ";

    cout << endl;
  }

  T largest() {
    T largestElement = elements[0];

    for (int i = 1; i < 5; i++) {
      if (elements[i] > largestElement)
        largestElement = elements[i];
    }

    return largestElement;
  }

  T smallest() {
    T smallestElement = elements[0];

    for (int i = 1; i < 5; i++) {
      if (elements[i] < smallestElement)
        smallestElement = elements[i];
    }

    return smallestElement;
  }
};


// Q9. Student Result Processing System
template <class T>
class Result {
  T marks[5];

public:
  void input() {
    for (int i = 0; i < 5; i++)
      cin >> marks[i];
  }

  T totalMarks() {
    T total = 0;

    for (int i = 0; i < 5; i++)
      total = total + marks[i];

    return total;
  }

  double averageMarks() {
    return totalMarks() / 5.0;
  }

  T highestMarks() {
    T highest = marks[0];

    for (int i = 1; i < 5; i++) {
      if (marks[i] > highest)
        highest = marks[i];
    }

    return highest;
  }

  T lowestMarks() {
    T lowest = marks[0];

    for (int i = 1; i < 5; i++) {
      if (marks[i] < lowest)
        lowest = marks[i];
    }

    return lowest;
  }

  void display() {
    cout << "Total Marks: " << totalMarks() << endl;
    cout << "Average Marks: " << averageMarks() << endl;
    cout << "Highest Marks: " << highestMarks() << endl;
    cout << "Lowest Marks: " << lowestMarks() << endl;
  }
};


// Q10. University Record Management System
class Person {
protected:
  string name;
  int age;

public:
  Person() {
  }

  Person(string name, int age) {
    this->name = name;
    this->age = age;
  }
};

class Teacher : public Person {
  string subject;

public:
  Teacher() {
  }

  Teacher(string name, int age, string subject)
    : Person(name, age) {
    this->subject = subject;
  }

  void display() {
    cout << "Teacher" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Subject: " << subject << endl;
  }
};

class ResearchScholar : public Person {
  string researchArea;

public:
  ResearchScholar() {
  }

  ResearchScholar(string name, int age, string researchArea)
    : Person(name, age) {
    this->researchArea = researchArea;
  }

  void display() {
    cout << "Research Scholar" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Research Area: " << researchArea << endl;
  }
};

template <class T>
class RecordManager {
  T records[5];
  int count;

public:
  RecordManager() {
    count = 0;
  }

  void add(T record) {
    records[count] = record;
    count++;
  }

  void display() {
    for (int i = 0; i < count; i++)
      records[i].display();
  }
};


int main() {
  // Q1
  cout << "Q1. Student Information System" << endl;

  EngineeringStudent student("Rahul", 101, 20, "CSE", 3);
  student.display();


  // Q2
  cout << "\nQ2. Employee Management System" << endl;

  Manager managers[5] = {
    Manager(1, "Aman", "IT", 50000),
    Manager(2, "Riya", "HR", 45000),
    Manager(3, "John", "Sales", 48000),
    Manager(4, "Sara", "Finance", 55000),
    Manager(5, "Alex", "Marketing", 47000)
  };

  for (int i = 0; i < 5; i++)
    managers[i].display();


  // Q3
  cout << "\nQ3. Library Management System" << endl;

  EBook books[3] = {
    EBook("C++ Basics", "Bjarne", 5.2, "PDF"),
    EBook("OOP", "Robert", 3.5, "EPUB"),
    EBook("Programming", "James", 4.1, "PDF")
  };

  for (int i = 0; i < 3; i++)
    books[i].display();


  // Q4
  cout << "\nQ4. Vehicle Registration System" << endl;

  Car car("JK01AB1234", "Toyota", "Petrol", 1500);
  Bike bike("JK02CD5678", "Honda", "Petrol", 125);

  car.display();
  bike.display();


  // Q5
  cout << "\nQ5. Banking System" << endl;

  SavingsAccount savingsAccount(1001, 25000);
  CurrentAccount currentAccount(1002, 40000);

  savingsAccount.display();
  currentAccount.display();


  // Q6
  cout << "\nQ6. Template Functions" << endl;

  cout << "Larger int: " << larger(10, 20) << endl;
  cout << "Larger float: " << larger(2.5f, 1.5f) << endl;
  cout << "Larger double: " << larger(5.5, 8.8) << endl;
  cout << "Larger char: " << larger('A', 'Z') << endl;

  int firstNumber = 10;
  int secondNumber = 20;

  swapValues(firstNumber, secondNumber);

  cout << "After swapping: "
       << firstNumber << " " << secondNumber << endl;


  // Q7
  cout << "\nQ7. Template Class for Pair" << endl;

  Pair<int> integerPair(10, 25);
  integerPair.display();

  Pair<float> floatPair(5.5f, 2.2f);
  floatPair.display();


  // Q8
  cout << "\nQ8. Generic Array Class" << endl;

  Array<int> integerArray;

  cout << "Enter 5 integers: ";
  integerArray.input();

  cout << "Elements: ";
  integerArray.display();

  cout << "Largest: " << integerArray.largest() << endl;
  cout << "Smallest: " << integerArray.smallest() << endl;

  Array<float> floatArray;

  cout << "Enter 5 floating-point values: ";
  floatArray.input();

  cout << "Elements: ";
  floatArray.display();

  cout << "Largest: " << floatArray.largest() << endl;
  cout << "Smallest: " << floatArray.smallest() << endl;


  // Q9
  cout << "\nQ9. Student Result Processing System" << endl;

  Result<int> integerResult;

  cout << "Enter 5 integer marks: ";
  integerResult.input();
  integerResult.display();

  Result<float> floatResult;

  cout << "Enter 5 floating-point marks: ";
  floatResult.input();
  floatResult.display();


  // Q10
  cout << "\nQ10. University Record Management System" << endl;

  Teacher teacher1("Taqueer", 40, "C++ & Java");
  Teacher teacher2("Yawar", 35, "Javascript");

  ResearchScholar scholar1("Harry", 25, "AI");
  ResearchScholar scholar2("Priya", 24, "Cyber Security");

  RecordManager<Teacher> teachers;
  teachers.add(teacher1);
  teachers.add(teacher2);

  RecordManager<ResearchScholar> scholars;
  scholars.add(scholar1);
  scholars.add(scholar2);

  teachers.display();
  scholars.display();

}
