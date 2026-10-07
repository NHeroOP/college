#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

// Problem 1: Division by Zero Exception
void problem1() {
  int numerator, denominator;

  cout << "Enter numerator: ";
  cin >> numerator;
  cout << "Enter denominator: ";
  cin >> denominator;

  try {
    if (denominator == 0)
      throw "Division by zero is not allowed.";

    cout << "Result: " << (double)numerator / denominator << endl;
  }
  catch (const char* message) {
    cout << "Error: " << message << endl;
  }
}

// Problem 2: Negative Number Exception
class NegativeNumberException {
};

void problem2() {
  double number;

  cout << "Enter a number: ";
  cin >> number;

  try {
    if (number < 0)
      throw NegativeNumberException();

    cout << "Square Root: " << sqrt(number) << endl;
  }
  catch (NegativeNumberException) {
    cout << "Error: Square root of a negative number cannot be calculated." << endl;
  }
}

// Problem 3: Bank Account Withdrawal
class BankAccount {
  double balance;

public:
  BankAccount(double balance) {
    this->balance = balance;
  }

  void withdraw(double amount) {
    if (amount > balance)
      throw "Insufficient Balance.";

    balance = balance - amount;
    cout << "Withdrawal successful." << endl;
    cout << "Remaining Balance: " << balance << endl;
  }
};

void problem3() {
  double balance, withdrawalAmount;

  cout << "Enter balance: ";
  cin >> balance;
  cout << "Enter withdrawal amount: ";
  cin >> withdrawalAmount;

  BankAccount account(balance);

  try {
    account.withdraw(withdrawalAmount);
  }
  catch (const char* message) {
    cout << "Error: " << message << endl;
  }
}

// Problem 4: Student Marks Validation
void problem4() {
  int marks;

  cout << "Enter marks: ";
  cin >> marks;

  try {
    if (marks < 0 || marks > 100)
      throw marks;

    cout << "Valid Marks: " << marks << endl;
  }
  catch (int) {
    cout << "Invalid Marks! Marks should be between 0 and 100." << endl;
  }
}

// Problem 5: Array Index Out of Bounds
void problem5() {
  int numbers[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  int index;

  cout << "Enter index: ";
  cin >> index;

  try {
    if (index < 0 || index > 9)
      throw index;

    cout << "Element: " << numbers[index] << endl;
  }
  catch (int) {
    cout << "Error: Array Index Out of Bounds." << endl;
  }
}

// Problem 6: Voting Eligibility Checker
class VotingException {
};

void problem6() {
  int age;

  cout << "Enter age: ";
  cin >> age;

  try {
    if (age < 18)
      throw VotingException();

    cout << "Eligible to vote." << endl;
  }
  catch (VotingException) {
    cout << "Exception: Not eligible for voting." << endl;
  }
}

// Problem 7: Multiple Catch Blocks
void problem7() {
  double firstNumber, secondNumber, result;
  char operation;

  cout << "Enter expression (example: 10 + 5): ";
  cin >> firstNumber >> operation >> secondNumber;

  try {
    switch (operation) {
      case '+':
        result = firstNumber + secondNumber;
        cout << "Result: " << result << endl;
        break;

      case '-':
        result = firstNumber - secondNumber;
        cout << "Result: " << result << endl;
        break;

      case '*':
        result = firstNumber * secondNumber;
        cout << "Result: " << result << endl;
        break;

      case '/':
        if (secondNumber == 0)
          throw 0;

        result = firstNumber / secondNumber;
        cout << "Result: " << result << endl;
        break;

      default:
        throw operation;
    }
  }
  catch (int) {
    cout << "Division by Zero Error." << endl;
  }
  catch (char) {
    cout << "Invalid Operator." << endl;
  }
}

// Problem 8: Student Record Writer
void problem8() {
  int rollNumber;
  string name;
  double marks;

  ofstream file("students.txt");

  if (!file) {
    cout << "Error opening file." << endl;
    return;
  }

  cout << "Enter Roll Number: ";
  cin >> rollNumber;
  cout << "Enter Name: ";
  cin >> name;
  cout << "Enter Marks: ";
  cin >> marks;

  file << rollNumber << " " << name << " " << marks << endl;
  file.close();

  cout << "Student details saved successfully." << endl;
}

// Problem 9: Count Characters, Words, and Lines
void problem9() {
  ifstream file("article.txt");

  if (!file) {
    cout << "Error opening article.txt." << endl;
    return;
  }

  char character;
  string word;
  string line;
  int characters = 0;
  int words = 0;
  int lines = 0;

  while (file.get(character))
    characters++;

  file.clear();
  file.seekg(0);

  while (file >> word)
    words++;

  file.clear();
  file.seekg(0);

  while (getline(file, line))
    lines++;

  file.close();

  cout << "Characters: " << characters << endl;
  cout << "Words: " << words << endl;
  cout << "Lines: " << lines << endl;
}

// Problem 10: Copy Contents from One File to Another
void problem10() {
  ifstream sourceFile("source.txt");
  ofstream destinationFile("destination.txt");

  if (!sourceFile || !destinationFile) {
    cout << "Error opening file." << endl;
    return;
  }

  string line;

  while (getline(sourceFile, line))
    destinationFile << line << endl;

  sourceFile.close();
  destinationFile.close();

  cout << "File copied successfully." << endl;
}

int main() {
  cout << "\n===== Problem 1: Division by Zero Exception =====" << endl;
  problem1();

  cout << "\n===== Problem 2: Negative Number Exception =====" << endl;
  problem2();

  cout << "\n===== Problem 3: Bank Account Withdrawal =====" << endl;
  problem3();

  cout << "\n===== Problem 4: Student Marks Validation =====" << endl;
  problem4();

  cout << "\n===== Problem 5: Array Index Out of Bounds =====" << endl;
  problem5();

  cout << "\n===== Problem 6: Voting Eligibility Checker =====" << endl;
  problem6();

  cout << "\n===== Problem 7: Multiple Catch Blocks =====" << endl;
  problem7();

  cout << "\n===== Problem 8: Student Record Writer =====" << endl;
  problem8();

  cout << "\n===== Problem 9: Count Characters, Words, and Lines =====" << endl;
  problem9();

  cout << "\n===== Problem 10: Copy Contents from One File to Another =====" << endl;
  problem10();

  return 0;
}
