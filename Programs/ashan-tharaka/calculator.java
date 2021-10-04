import java.util.Scanner;
public class calculator {
    public static void main(String[] args) {
        int a;
        int b;
        String operation;
        int answer;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Welcome to my calculator");
        System.out.println("Enter first number:");
        a = scanner.nextInt();
        System.out.println("Enter second number:");
        b = scanner.nextInt();
        System.out.println("Enter operation:");
        operation = scanner.next();
        if ("+".equals(operation)) {
            answer = add(a, b);
            System.out.println("Answer is: " + answer);
        }
        else if("-".equals(operation)) {
            answer=minus(a,b);
            System.out.println("Answer is: "+answer);
        }
        else if("*".equals(operation)){
            answer=multy(a,b);
            System.out.println("Answer is: "+answer);
        }
        else if("/".equals(operation)){
            answer=divide(a,b);
            System.out.println("Answer is: "+answer);
        }
 
        else if("%".equals(operation)){
            answer=modulus(a,b);
            System.out.println("Answer is: "+answer);
        }
 
 
        else
         {
            System.out.println("Unsupported operation");
        }
    }
 
    private static int add(int a, int b) {
        return a + b;
    }
 
    private static int minus(int a, int b) {
        return a - b;
    }
 
     private static int multy(int a, int b) {
         return a*b;
     }
 
     private static int  divide(int a, int b) {
         return a / b;
     }
     private static int modulus(int a, int b) {
         return a % b;
     }
 }