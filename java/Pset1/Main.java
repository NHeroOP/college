void main() {
}

void problem1(){
  Scanner sc = new Scanner(System.in);
  IO.print("Enter a number (n): ");
  int n = sc.nextInt();

  for (int i = 1; i<=n; i++){
    IO.print("%d ".formatted(i));
  }
  IO.println("");
}

void problem2(){
  Scanner sc = new Scanner(System.in);
  IO.print("Enter a number (n): ");
  int n = sc.nextInt();

  for (int i = 2; i<=n; i+=2){
    IO.print("%d ".formatted(i));
  }
  IO.println("");
}

void problem3(){
  Scanner sc = new Scanner(System.in);
  IO.print("Enter a number (n): ");
  int n = sc.nextInt();
  int sum = 0;


  for (int i=1; i<=n; i++){
    sum += i;
  }
  IO.println("Sum of first %d natural numbers is %d".formatted(n, sum));
}

void problem4() {
  Scanner sc = new Scanner(System.in);
  IO.print("Enter a number (n): ");
  int n = sc.nextInt();
  int temp = n;
  int reversed = 0;

  while (temp != 0) {
    reversed *= 10;
    reversed += temp % 10;
    temp /= 10;
  }

  IO.println("Reverse of %d is %d".formatted(n, reversed));
}

void problem5(){
  Scanner sc = new Scanner(System.in);
  IO.print("Enter a number (n): ");
  int n = sc.nextInt();
  int factorial = 1;

  for (int i = 1; i<=n; i++){
    factorial *= i;
  }

  IO.println("Factorial of %d is %d".formatted(n, factorial));
}

void problem6(){
  Scanner sc = new Scanner(System.in);
  IO.print("Enter a number (n): ");
  int n = sc.nextInt();
  boolean isPrime = true;

  if (n <= 1 ) isPrime = false;
  if (n <= 2) isPrime = true;
  if (n % 2 == 0 || n % 3 == 0) isPrime = false;

  for (int i = 5; i * i <= n; i+= 6){
    if (n % i == 0 || n % (i+2) == 0) isPrime = false;
  }

  IO.println("Is number prime: %b ".formatted(isPrime));
}

void problem7(){
  Scanner sc = new Scanner(System.in);
  IO.print("Enter a number (n): ");
  int n = sc.nextInt();
  int temp = n;
  int sum = 0;

  while (temp != 0) {
    sum += temp % 10;
    temp /= 10;
  }

  IO.println("Sum of the digits of %d is %d".formatted(n, sum));
}

void problem8(){
  Scanner sc = new Scanner(System.in);
  IO.print("Enter a number (n): ");
  int n = sc.nextInt();
  long firstTerm = 0;
  long secondTerm = 1;

  for (int i = 1; i <= n; ++i) {
    IO.print(firstTerm + " ");
    long nextTerm = firstTerm + secondTerm;
    firstTerm = secondTerm;
    secondTerm = nextTerm;
  }

  IO.println("");
}

void problem9(){
  Scanner sc = new Scanner(System.in);
  IO.print("Enter a number (n): ");
  int n = sc.nextInt();

  for (int i = 1; i <= n; i++){
    IO.println("%s".formatted("*".repeat(i)));
  }
}

void problem10(){
  Scanner sc = new Scanner(System.in);
  IO.print("Enter a number (n1): ");
  int n1 = sc.nextInt();

  IO.print("Enter a number (n2): ");
  int n2 = sc.nextInt();

  int temp1 = n1;
  int temp2 = n2;

  while (temp2 != 0){
    int temp = temp1 % temp2;
    temp1 = temp2;
    temp2 = temp;
  }

  IO.println("The GCD(%d, %d) is %d".formatted(n1, n2, temp1));
}

void problem11(){
  int randomNumber = (int)(Math.random()* 100) + 1;
  Scanner sc = new Scanner(System.in);
  int n;

  do {
    IO.print("Enter a number (n): ");
    n = sc.nextInt();

    if (n < 1 || n >= 100){
      IO.println("Only in range (1, 100)");
    } else if (n > randomNumber){
      IO.println("Too High");
    } else if (n < randomNumber){
      IO.println("Too Low");
    } else {
      IO.println("Correct!");
    }
  } while (n != randomNumber);

}