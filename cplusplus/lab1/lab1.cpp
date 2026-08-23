#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int largestOfThree(int a, int b, int c) {
  if (a >= b && a >=c){
    return a;
  } else if (b >= a && b >= c) {
    return b;
  } else
    return c;
}

bool checkPrime(int num) {
  if (num <= 1) {
    return false;
  } else if (num == 2) {
    return true;
  } else if (num % 2 == 0){
    return false;
  } else {
    for (int i = 3; i * i <= num; i+= 2) {
      if (num % i == 0) {
        return false;
      }
    }
    return true;
  }
}

int factorial(int n) {
  int result = 1;
  for (int i = n; i > 0; i--){
    result *= i;
  }
  return result;
}

int reverseNumber(int num){
  int reversed = 0;
  while (num != 0){
    int digit = num % 10;
    reversed = (reversed * 10) + digit;
    num /= 10;
  }

  return reversed;
}



bool palindrome(int num) {
  int original = num;
  int reversed = reverseNumber(num);
  if (original == reversed) {
    return true;
  } else {
    return false;
  }
}

int sumOfAllDigits(int num) {
  int sum = 0;
  while (num != 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

void printFibonacci(int n) {
  if (n <= 0) {
    cout << 0;
  } else if (n == 1) {
    cout << 0 << 1;
  } else {
    int a = 0, b = 1, c;
    cout << 0 << " " << 1 << " ";
    for (int i = 2; i <= n; i++)
    {
      c = a + b;
      a = b;
      b = c;
      cout << c << " ";
    }
  }
}

int maxInArr(int arr[], int size) {
  int max = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

int minInArr(int arr[], int size) {
  int min = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}

int linearSearch(int arr[], int size, int target) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1; 
}

int countOccurrences(int arr[], int size, int target) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] == target) {
      count++;
    }
  }
  return count;
}

int secondLargestElement(int arr[], int size) {
  int largest = arr[0];
  int secondLargest;
  for (int i = 1; i < size; i++) {
    if (arr[i] > largest) {
      secondLargest = largest;
      largest = arr[i];
    } else if (arr[i] > secondLargest && arr[i] != largest) {
      secondLargest = arr[i];
    }
  }
  return secondLargest;
}

void reverseArray(int arr[], int size) {
  int start = 0;
  int end = size - 1;
  while (start < end) {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }

  cout << "The reversed array is: [";
  for (int i = 0; i < size; i++) {
    if (i == size - 1) {
      cout << arr[i];
    } else {
      cout << arr[i] << ", ";
    }

  }
  cout << "]" << endl;
}

int binarySearch(int arr[], int size, int target) {
  sort(arr, arr + size);

  int left = 0;
  int right = size - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1; 
}

void removeDuplicatesAndPrint(int arr[], int size) {
  if (size == 0) {
    cout << "The array is empty." << endl;
  } else if (size == 1) {
    cout << "The array after removing duplicates is: [" << arr[0] << "]" << endl;
  } else if (size == 2){
    if (arr[0] == arr[1]) {
      cout << "The array after removing duplicates is: [" << arr[0] << "]" << endl;
    } else {
      cout << "The array after removing duplicates is: [" << arr[0] << ", " << arr[1] << "]" << endl;
    }
  } else {
    sort(arr, arr + size);
    int writeIndex = 1;
    for (int i = 1; i < size; i++) {
      if (arr[i] != arr[i - 1]) {
        arr[writeIndex] = arr[i];
        writeIndex++;
      }
    }

    cout << "The array after removing duplicates is: [";
    for (int i = 0; i < writeIndex; i++) {
      if (i == writeIndex - 1) {
        cout << arr[i];
      } else {
        cout << arr[i] << ", ";
      }
    }
    cout << "]" << endl;
  }

}

int main() {
  // int num1, num2, num3;
  // cout << "Enter num1: ";
  // cin >> num1;
  // cout << "Enter num2: ";
  // cin >> num2;
  // cout << "Enter num3: ";
  // cin >> num3;
  // int largest = largestOfThree(num1, num2, num3);
  // cout << "The largest number is: " << largest << endl;

  // int numberToCheck;
  // cout << "Enter a number to check if it is prime: ";
  // cin >> numberToCheck;
  // if (checkPrime(numberToCheck)) {
  //   cout << numberToCheck << " is a prime number." << endl;
  // } else {
  //   cout << numberToCheck << " is not a prime number." << endl;
  // }

  // int numberForFactorial;
  // cout << "Enter a number to calculate its factorial: ";
  // cin >> numberForFactorial;
  // int fact = factorial(numberForFactorial);
  // cout << "The factorial of " << numberForFactorial << " is: " << fact << endl;

  // int numberToReverse;
  // cout << "Enter a number to reverse: ";
  // cin >> numberToReverse;
  // int reversedNumber = reverseNumber(numberToReverse);
  // cout << "The reversed number is: " << reversedNumber << endl;

  // int numberToCheckPalindrome;
  // cout << "Enter a number to check if it is a palindrome: ";
  // cin >> numberToCheckPalindrome;
  // if (palindrome(numberToCheckPalindrome)) {
  //   cout << numberToCheckPalindrome << " is a palindrome." << endl;
  // } else {
  //   cout << numberToCheckPalindrome << " is not a palindrome." << endl;
  // }

  // int numberForSum;
  // cout << "Enter a number to calculate the sum of its digits: ";
  // cin >> numberForSum;
  // int sum = sumOfAllDigits(numberForSum);
  // cout << "The sum of the digits of " << numberForSum << " is: " << sum << endl;

  // int n;
  // cout << "Enter the number of Fibonacci terms to print: ";
  // cin >> n;
  // cout << "The first " << n << " terms of the Fibonacci series are: ";
  // printFibonacci(n);
  // cout << endl;

  int sizeOfArray;
  cout << "Enter the size of the array: ";
  cin >> sizeOfArray;
  int arr[sizeOfArray];
  int i = 0;
  while (i < sizeOfArray) {
    cout << "Enter element " << i + 1 << ": ";
    cin >> arr[i];
    i++;
  }

  // int maxElement = maxInArr(arr, sizeOfArray);
  // cout << "The maximum element in the array is: " << maxElement << endl;

  // int minElement = minInArr(arr, sizeOfArray);
  // cout << "The minimum element in the array is: " << minElement << endl;

  // int elementToSearch;
  // cout << "Enter an element to search in the array: ";
  // cin >> elementToSearch;
  // int searchResult = linearSearch(arr, sizeOfArray, elementToSearch);
  // if (searchResult != -1) {
  //   cout << "Element " << elementToSearch << " found at index: " << searchResult << endl;
  // } else {
  //   cout << "Element " << elementToSearch << " not found in the array." << endl;
  // }

  // int elementToCount;
  // cout << "Enter an element to count its occurrences in the array: ";
  // cin >> elementToCount;
  // int countResult = countOccurrences(arr, sizeOfArray, elementToCount);
  // cout << "Element " << elementToCount << " occurs " << countResult << " times in the array." << endl;

  // int secondLargest = secondLargestElement(arr, sizeOfArray);
  // cout << "The second largest element in the array is: " << secondLargest << endl;

  // reverseArray(arr, sizeOfArray);

  // int elementToBinarySearch;
  // cout << "Enter an element to perform binary search in the array: ";
  // cin >> elementToBinarySearch;
  // int binarySearchResult = binarySearch(arr, sizeOfArray, elementToBinarySearch);
  // if (binarySearchResult != -1) {
  //   cout << "Element " << elementToBinarySearch << " found at index: " << binarySearchResult << endl;
  // } else {
  //   cout << "Element " << elementToBinarySearch << " not found in the array." << endl;
  // }

  removeDuplicatesAndPrint(arr, sizeOfArray);

  return 0;
}




