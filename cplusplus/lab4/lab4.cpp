#include <iostream>
using namespace std;

// P1 Area
class Area {
public:
  double calculate(int side){
    return side * side;
  }
  double calculate(int length, int breadth){
    return length * breadth;
  }
  double calculate(double radius){
    return 3.14 * (radius * radius);
  }
};

// P2 Maximum
class Maximum{
public:
  double max(int n1, int n2){
    if(n1 > n2)
      return n1;
    else
      return n2;
  }
  double max(int n1, int n2, int n3){
    if((n1 > n2) && (n1 > n3))
      return n1;
    else if((n2 > n1) && (n2 > n3))
      return n2;
    else
      return n3;
  }
  double max(double n1, double n2){
    if(n1 > n2)
      return n1;
    else
      return n2;
  }
};

// P3 Complex Number Addition
class Complex {
public:
  int real, imaginary;
  Complex(int real, int imaginary){
    this->real = real;
    this->imaginary = imaginary;
  }
  Complex operator + (Complex c){
    return Complex(this->real + c.real, this->imaginary + c.imaginary);
  }
  void view(){
    cout << this->real << " + (" << this->imaginary << "i)" << endl;
  }
};

// P4 Distance Addition
class Distance {
public:
  int feet, inches;
  Distance(int feet, int inches){
    this->feet = feet;
    this->inches = inches;
  }
  Distance operator + (Distance d){
    int totalFeet = this->feet + d.feet;
    int totalInches = this->inches + d.inches;
    if(totalInches >= 12){
      totalFeet++;
      totalInches -= 12;
    }
    return Distance(totalFeet, totalInches);
  }
  void view(){
    cout << feet << " ft " << inches << " in" << endl;
  }
};

// P5 Static Members - Student Counter
class Student {
public:
  static int count;
  Student(){
    count++;
    cout << "Student Created" << endl;
  }
  static void totalStudents(){
    cout << "Total Students = " << count << endl;
  }
};
int Student::count = 0;

// P6 Static Members - Bank Account Statistics
class BankAccount {
public:
  int accountNumber;
  string customerName;
  static int totalAccounts;
  BankAccount(int accountNumber, string customerName){
    this->accountNumber = accountNumber;
    this->customerName = customerName;
    totalAccounts++;
  }
  static void displayTotalAccounts(){
    cout << "Total Accounts = " << totalAccounts << endl;
  }
};
int BankAccount::totalAccounts = 0;

// P7 Friend Function - Largest Number
class Numbers {
private:
  int n1, n2;
public:
  Numbers(int n1, int n2){
    this->n1 = n1;
    this->n2 = n2;
  }
  friend void largest(Numbers n);
};
void largest(Numbers n){
  if(n.n1 > n.n2)
    cout << "Largest = " << n.n1 << endl;
  else
    cout << "Largest = " << n.n2 << endl;
}

// P8 Friend Function - Sum of Two Classes
class B;
class A {
private:
  int n1;
public:
  A(int n1){
    this->n1 = n1;
  }
  friend int sum(A a, B b);
};
class B {
private:
  int n2;
public:
  B(int n2){
    this->n2 = n2;
  }
  friend int sum(A a, B b);
};
int sum(A a, B b){
  return a.n1 + b.n2;
}

// P9 Inline Function - Simple Interest
class Interest {
public:
  inline double calculateSI(double P, double R, double T){
    return (P * R * T) / 100;
  }
};

// P10 Mixed Problem - Book
class Book {
public:
  int bookId;
  string bookName;
  double price;
  static int totalBooks;
  Book(int bookId, string bookName, double price){
    this->bookId = bookId;
    this->bookName = bookName;
    this->price = price;
    totalBooks++;
  }
  inline double discountedPrice(){
    return price - (price * 10 / 100);
  }
  bool operator > (Book b){
    return this->price > b.price;
  }
  friend void costlierBook(Book b1, Book b2);
  static void displayTotalBooks(){
    cout << "Total Books = " << totalBooks << endl;
  }
};
int Book::totalBooks = 0;
void costlierBook(Book b1, Book b2){
  if(b1 > b2){
    cout << "Costlier Book:" << endl;
    cout << "ID: " << b1.bookId << endl;
    cout << "Name: " << b1.bookName << endl;
    cout << "Price: " << b1.price << endl;
  }
  else{
    cout << "Costlier Book:" << endl;
    cout << "ID: " << b2.bookId << endl;
    cout << "Name: " << b2.bookName << endl;
    cout << "Price: " << b2.price << endl;
  }
}

int main() {
  // P1
  Area area;
  cout << "Area of square of side 10 is " << area.calculate(10) << endl;
  cout << "Area of rectangle of l=5, b=3 is " << area.calculate(5, 3) << endl;
  cout << "Area of circle of radius 2 is " << area.calculate(3.3) << endl;

  // P2
  Maximum maxi;
  cout << "Max of 10 and 20 is " << maxi.max(10, 20) << endl;
  cout << "Max of 5, 8 and 3 is " << maxi.max(5, 8, 3) << endl;
  cout << "Max of 3.2 and 4.5 is " << maxi.max(3.2, 4.5) << endl;

  // P3
  Complex c1(1, 3), c2(10, 3);
  Complex c3 = c1 + c2;
  c1.view();
  c2.view();
  c3.view();

  // P4
  Distance d1(5, 8), d2(3, 9);
  Distance d3 = d1 + d2;
  d1.view();
  d2.view();
  d3.view();

  // P5
  Student s1;
  Student s2;
  Student s3;
  Student::totalStudents();

  // P6
  BankAccount b1(101, "Rahul");
  BankAccount b2(102, "Aman");
  BankAccount b3(103, "Rohan");
  BankAccount::displayTotalAccounts();

  // P7
  Numbers n(25, 40);
  cout << "Numbers: 25 and 40" << endl;
  largest(n);

  // P8
  A a(10);
  B b(20);
  cout << "A = 10" << endl;
  cout << "B = 20" << endl;
  cout << "Sum = " << sum(a, b) << endl;

  // P9
  Interest interest;
  double P = 10000;
  double R = 5;
  double T = 2;
  cout << "P = " << P << endl;
  cout << "R = " << R << endl;
  cout << "T = " << T << endl;
  cout << "SI = " << interest.calculateSI(P, R, T) << endl;

  // P10
  Book book1(101, "C++ Basics", 500);
  Book book2(102, "C++ Programming", 700);
  cout << "Book 1 Price = " << book1.price << endl;
  cout << "Book 2 Price = " << book2.price << endl;
  costlierBook(book1, book2);
  Book::displayTotalBooks();
  cout << "Discounted Price = " << book2.discountedPrice() << endl;
}