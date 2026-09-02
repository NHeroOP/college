#include <iostream>
#include <string>

using namespace std;

// P1 - Student Details
class Student {
private:
  string name;
  int rollNo;

public:
  void setData(string name, int rollNo) {
    this->name = name;
    this->rollNo = rollNo;
  }

  void displayData() {
    cout << "----- Student Class Data -----" << endl;
    cout << "Name: " << name << endl;
    cout << "RollNo: " << rollNo << endl;
  }
};

// P2 - Rectangle Area
class Rectangle {
private:
  int length;
  int breadth;

public:
  void input(int length, int breadth) {
    this->length = length;
    this->breadth = breadth;
  }

  int calculateArea() {
    return length * breadth;
  }

  void displayArea() {
    cout << "------ Displaying Area -------" << endl;
    cout << "Area: " << calculateArea() << endl;
  }
};

// P3 - Number Analyzer
class Number {
private:
  int num;

public:
  void input(int num) {
    this->num = num;
  }

  string isEven() {
    if (num % 2 == 0) {
      return "yes";
    }
    else {
      return "no";
    }
  }

  void displayResult() {
    cout << "Is " << num << " Even? " << isEven() << endl;
  }
};

// P4 - Constructor Demonstration
class Book {
private:
  string title;
  string author;

public:
  Book(string title, string author) {
    this->title = title;
    this->author = author;
  }

  void displayDetails() {
    cout << "---- Book Details ----" << endl;
    cout << "Author: " << author << endl;
    cout << "Title: " << title << endl;
  }
};

// P5 - Sum of Array Elements
class ArraySum {
private:
  int arr[10];

public:
  ArraySum(int input[10]) {
    for (int i = 0; i < 10; i++) {
      arr[i] = input[i];
    }
  }

  int findSum() {
    int sum = 0;

    for (int i = 0; i < 10; i++) {
      sum += arr[i];
    }

    return sum;
  }

  void displaySum() {
    cout << "---- Array Sum ----" << endl;
    cout << "Sum: " << findSum() << endl;
  }
};

// P6 - String Length Finder
class Text {
private:
  string str;

public:
  Text(string str) {
    this->str = str;
  }

  int calculateLength() {
    int length = 0;

    for (char ch : str) {
      length++;
    }

    return length;
  }

  void displayLength() {
    cout << "---- String Length ----" << endl;
    cout << "String: " << str << endl;
    cout << "Length: " << calculateLength() << endl;
  }
};

// P7 - Employee Salary Calculator
class Employee {
private:
  string employeeName;
  double basicSalary;

public:
  Employee(string employeeName, double basicSalary) {
    this->employeeName = employeeName;
    this->basicSalary = basicSalary;
  }

  double calculateHRA() {
    return basicSalary * 0.20;
  }

  double calculateDA() {
    return basicSalary * 0.10;
  }

  double calculateGrossSalary() {
    return basicSalary + calculateHRA() + calculateDA();
  }

  void displaySalary() {
    cout << "---- Employee Salary ----" << endl;
    cout << "Employee Name: " << employeeName << endl;
    cout << "Basic Salary: " << basicSalary << endl;
    cout << "HRA: " << calculateHRA() << endl;
    cout << "DA: " << calculateDA() << endl;
    cout << "Gross Salary: " << calculateGrossSalary() << endl;
  }
};

// P8 - Highest Marks in an Array
class Marks {
private:
  int marks[5];

public:
  Marks(int input[5]) {
    for (int i = 0; i < 5; i++) {
      marks[i] = input[i];
    }
  }

  int findHighest() {
    int highest = marks[0];

    for (int i = 1; i < 5; i++) {
      if (marks[i] > highest) {
        highest = marks[i];
      }
    }

    return highest;
  }

  void displayResult() {
    cout << "---- Highest Marks ----" << endl;
    cout << "Highest Mark: " << findHighest() << endl;
  }
};

// P9 - Bank Account
class BankAccount {
private:
  long long accountNumber;
  double balance;

public:
  BankAccount(long long accountNumber, double balance) {
    this->accountNumber = accountNumber;
    this->balance = balance;
  }

  void deposit(double amount) {
    balance += amount;
  }

  void withdraw(double amount) {
    if (amount <= balance) {
      balance -= amount;
      cout << "Withdrawal successful." << endl;
    }
    else {
      cout << "Insufficient balance. Withdrawal failed." << endl;
    }
  }

  void displayBalance() {
    cout << "---- Bank Account ----" << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: " << balance << endl;
  }
};

// P10 - Student Result Management System
class ResultStudent {
private:
  string name;
  int rollNo;
  int marks[5];

public:
  ResultStudent(string name, int rollNo, int inputMarks[5]) {
    this->name = name;
    this->rollNo = rollNo;

    for (int i = 0; i < 5; i++) {
      marks[i] = inputMarks[i];
    }
  }

  int calculateTotal() {
    int total = 0;

    for (int i = 0; i < 5; i++) {
      total += marks[i];
    }

    return total;
  }

  double calculatePercentage() {
    return calculateTotal() / 5.0;
  }

  char determineGrade() {
    double percentage = calculatePercentage();

    if (percentage >= 90) {
      return 'A';
    }
    else if (percentage >= 75) {
      return 'B';
    }
    else if (percentage >= 60) {
      return 'C';
    }
    else if (percentage >= 40) {
      return 'D';
    }
    else {
      return 'F';
    }
  }

  void displayResult() {
    cout << "---- Student Result ----" << endl;
    cout << "Name: " << name << endl;
    cout << "RollNo: " << rollNo << endl;

    cout << "Marks: ";

    for (int i = 0; i < 5; i++) {
      cout << marks[i] << " ";
    }

    cout << endl;
    cout << "Total Marks: " << calculateTotal() << endl;
    cout << "Percentage: " << calculatePercentage() << "%" << endl;
    cout << "Grade: " << determineGrade() << endl;
  }
};

// Bonus - Library
class LibraryBook {
private:
  string title;
  string author;

public:
  LibraryBook() {
    title = "";
    author = "";
  }

  LibraryBook(string title, string author) {
    this->title = title;
    this->author = author;
  }

  string getTitle() {
    return title;
  }

  void displayDetails() {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
  }
};

class Library {
private:
  LibraryBook books[10];

public:
  Library(LibraryBook input[10]) {
    for (int i = 0; i < 10; i++) {
      books[i] = input[i];
    }
  }

  void searchBook(string title) {
    bool found = false;

    cout << "---- Search Results ----" << endl;

    for (int i = 0; i < 10; i++) {
      if (books[i].getTitle() == title) {
        books[i].displayDetails();
        found = true;
      }
    }

    if (!found) {
      cout << "No matching book found." << endl;
    }
  }
};

int main() {
  // P1
  Student stu;
  stu.setData("John", 20);
  stu.displayData();

  cout << endl;

  // P2
  Rectangle rect;
  rect.input(10, 10);
  rect.displayArea();

  cout << endl;

  // P3
  Number num;
  num.input(13);
  num.displayResult();

  cout << endl;

  // P4
  Book book("Art Of War", "Sun Tzu");
  book.displayDetails();

  cout << endl;

  // P5
  int array[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  ArraySum arraySum(array);
  arraySum.displaySum();

  cout << endl;

  // P6
  Text text("Object Oriented Programming");
  text.displayLength();

  cout << endl;

  // P7
  Employee employee("John", 50000);
  employee.displaySalary();

  cout << endl;

  // P8
  int studentMarks[5] = {78, 92, 85, 67, 88};
  Marks marks(studentMarks);
  marks.displayResult();

  cout << endl;

  // P9
  BankAccount account(1234567890, 10000);
  account.deposit(5000);
  account.withdraw(3000);
  account.displayBalance();

  cout << endl;

  // P10
  int resultMarks[5] = {91, 87, 95, 89, 93};
  ResultStudent resultStudent("Alice", 25, resultMarks);
  resultStudent.displayResult();

  cout << endl;

  // Bonus
  LibraryBook libraryBooks[10] = {
    LibraryBook("The Alchemist", "Paulo Coelho"),
    LibraryBook("1984", "George Orwell"),
    LibraryBook("The Hobbit", "J.R.R. Tolkien"),
    LibraryBook("The Great Gatsby", "F. Scott Fitzgerald"),
    LibraryBook("Pride and Prejudice", "Jane Austen"),
    LibraryBook("Harry Potter", "J.K. Rowling"),
    LibraryBook("Hamlet", "William Shakespeare"),
    LibraryBook("To Kill a Mockingbird", "Harper Lee"),
    LibraryBook("Dune", "Frank Herbert"),
    LibraryBook("Moby-Dick", "Herman Melville")
  };

  Library library(libraryBooks);
  library.searchBook("1984");

  return 0;
}