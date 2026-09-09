#include <iostream>
#include <string>

using namespace std;

// P1 Add Number
class Number {
public:
  int num;

  Number(int num) {
    this->num = num;
  }
};

Number addNum(Number n1, Number n2) {
  return Number(n1.num + n2.num);
}

// P2 Highest Marks
class Student {
  int rollNo;
public:
  int marks;

  Student(int rollNo, int marks) {
    this->marks = marks;
    this->rollNo = rollNo;
  }
};

Student highestMarks(Student s1, Student s2) {
  if (s1.marks > s2.marks) {
    return s1;
  } else if (s1.marks < s2.marks) {
    return s2;
  } else {
    return s1;
  }
}

// P3 Distance
class Distance {
  int feet, inches;
public:
  Distance(int feet, int inches) {
    this->feet = feet;
    this->inches = inches;
  }

  Distance add(Distance d) {
    int addedInches = this->inches + d.inches;
    int addedFeet = this->feet + d.feet;

    if (addedInches >= 12) {
      addedFeet++;
      addedInches -= 12;
    }

    return Distance(addedFeet, addedInches);
  }
};

// P4 Bank Account
class BankAccount {
  long long accountNumber;
  double balance;
  public:
    BankAccount(long long accountNumber, double balance) {
      this->accountNumber = accountNumber;
      this->balance = balance;
    }

    void transfer(BankAccount &receiver, double amount) {
      if (amount <= balance) {
        balance -= amount;
        receiver.balance += amount;
      }
    }

    void display() {
      cout << "Account Number: " << accountNumber << endl;
      cout << "Balance: " << balance << endl;
    }
};

// P5 Complex Number
class Complex {
public:
  int real, imag;

  Complex(int real, int imag) {
    this->real = real;
    this->imag = imag;
  }

  Complex add(Complex c) {
    int r = real + c.real;
    int i = imag + c.imag;

    return Complex(r, i);
  }

  Complex multiply(Complex c) {
    int r = real * c.real - imag * c.imag;
    int i = real * c.imag + imag * c.real;

    return Complex(r, i);
  }
};

Complex subtract(Complex c1, Complex c2) {
  int r = c1.real - c2.real;
  int i = c1.imag - c2.imag;

  return Complex(r, i);
}

// P6 Employee Salary
class Employee {
public:
  string name;
  double salary;

  Employee(string name, double salary) {
    this->name = name;
    this->salary = salary;
  }
};

Employee highestSalary(Employee employees[], int size) {
  Employee highest = employees[0];

  for (int i = 1; i < size; i++) {
    if (employees[i].salary > highest.salary) {
      highest = employees[i];
    }
  }

  return highest;
}

Employee incrementSalary(Employee employee) {
  employee.salary = employee.salary + employee.salary * 0.10;
  return employee;
}

// P7 Rectangle
class Rectangle {
public:
  int length, width;

  Rectangle(int length, int width) {
    this->length = length;
    this->width = width;
  }

  bool equalArea(Rectangle r) {
    if (length * width == r.length * r.width) {
      return true;
    } else {
      return false;
    }
  }
};

Rectangle merge(Rectangle r1, Rectangle r2) {
  int length = r1.length + r2.length;
  int width = r1.width + r2.width;

  return Rectangle(length, width);
}

// P8 Library Book
class Book {
public:
  int bookID;
  string title;
  int copies;

  Book(int bookID, string title, int copies) {
    this->bookID = bookID;
    this->title = title;
    this->copies = copies;
  }

  void exchange(Book &other) {
    int tempID = bookID;
    bookID = other.bookID;
    other.bookID = tempID;

    string tempTitle = title;
    title = other.title;
    other.title = tempTitle;

    int tempCopies = copies;
    copies = other.copies;
    other.copies = tempCopies;
  }
};

Book moreCopies(Book b1, Book b2) {
  if (b1.copies > b2.copies) {
    return b1;
  } else {
    return b2;
  }
}

// P9 Shopping Cart
class Product {
public:
  string name;
  double price;
  int quantity;

  Product(string name, double price, int quantity) {
    this->name = name;
    this->price = price;
    this->quantity = quantity;
  }

  Product combine(Product p) {
    int totalQuantity = quantity + p.quantity;

    return Product(name, price, totalQuantity);
  }
};

Product higherValue(Product p1, Product p2) {
  double value1 = p1.price * p1.quantity;
  double value2 = p2.price * p2.quantity;

  if (value1 > value2) {
    return p1;
  } else {
    return p2;
  }
}

// P10 University Result
class Result {
public:
  int rollNumber;
  int marks[5];

  Result(int rollNumber, int marks[]) {
    this->rollNumber = rollNumber;

    for (int i = 0; i < 5; i++) {
      this->marks[i] = marks[i];
    }
  }

  int totalMarks() {
    int total = 0;

    for (int i = 0; i < 5; i++) {
      total += marks[i];
    }

    return total;
  }

  Result compare(Result r) {
    if (totalMarks() > r.totalMarks()) {
      return *this;
    } else {
      return r;
    }
  }
};

Result topper(Result r1, Result r2, Result r3) {
  Result highest = r1;

  if (r2.totalMarks() > highest.totalMarks()) {
    highest = r2;
  }

  if (r3.totalMarks() > highest.totalMarks()) {
    highest = r3;
  }

  return highest;
}

Result graceMarks(Result r) {
  int totalGrace = 0;

  for (int i = 0; i < 5; i++) {
    if (r.marks[i] < 100 && totalGrace < 20) {
      int grace = 5;

      if (100 - r.marks[i] < grace) {
        grace = 100 - r.marks[i];
      }

      if (totalGrace + grace > 20) {
        grace = 20 - totalGrace;
      }

      r.marks[i] += grace;
      totalGrace += grace;
    }
  }

  return r;
}

int main() {
  Number n1(10), n2(15);
  Number n3 = addNum(n1, n2);
  cout << "P1: " << n3.num << endl;

  Student s1(10, 99), s2(12, 98);
  Student studentWithHighestMarks = highestMarks(s1, s2);
  cout << "P2: Highest Marks = " << studentWithHighestMarks.marks << endl;

  Distance d1(10, 11), d2(9, 5);
  Distance d3 = d1.add(d2);

  BankAccount a1(1001, 5000);
  BankAccount a2(1002, 2000);
  a1.transfer(a2, 1500);
  cout << "P4:" << endl;
  a1.display();
  a2.display();

  Complex c1(5, 3), c2(2, 1);
  Complex c3 = c1.add(c2);
  Complex c4 = subtract(c1, c2);
  Complex c5 = c1.multiply(c2);

  Employee employees[3] = {
    Employee("John", 30000),
    Employee("Alex", 40000),
    Employee("Mike", 35000)
  };

  Employee highest = highestSalary(employees, 3);
  Employee revised = incrementSalary(employees[0]);
  cout << "P6: Highest Salary = " << highest.name << " " << highest.salary << endl;
  cout << "P6: Revised Salary = " << revised.name << " " << revised.salary << endl;

  Rectangle r1(10, 5), r2(5, 10);

  if (r1.equalArea(r2)) {
    cout << "P7: Both rectangles have equal area" << endl;
  } else {
    cout << "P7: Areas are different" << endl;
  }

  Rectangle r3 = merge(r1, r2);

  Book b1(1, "C++", 5), b2(2, "Java", 8);
  b1.exchange(b2);
  Book b3 = moreCopies(b1, b2);
  cout << "P8: Book with more copies = " << b3.title << endl;

  Product p1("Keyboard", 1000, 2), p2("Mouse", 500, 3);
  Product higher = higherValue(p1, p2);
  Product combined = p1.combine(p2);
  cout << "P9: Higher Value Product = " << higher.name << endl;
  cout << "P9: Combined Quantity = " << combined.quantity << endl;

  int marks1[5] = {80, 75, 90, 85, 70};
  int marks2[5] = {85, 80, 75, 90, 80};
  int marks3[5] = {70, 90, 85, 80, 75};

  Result result1(101, marks1);
  Result result2(102, marks2);
  Result result3(103, marks3);

  Result higherResult = result1.compare(result2);
  Result top = topper(result1, result2, result3);
  Result revisedResult = graceMarks(result1);

  cout << "P10: Higher Roll Number = " << higherResult.rollNumber << endl;
  cout << "P10: Topper Roll Number = " << top.rollNumber << endl;

  cout << "P10: Revised Marks = ";
  for (int i = 0; i < 5; i++) {
    cout << revisedResult.marks[i] << " ";
  }
  cout << endl;

  return 0;
}