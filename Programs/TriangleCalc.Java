import java.util.Scanner;

class TriangleCalc{
   public static void main(String args[]) { 
  
      Scanner scanner = new Scanner(System.in);

      System.out.println("Masukkan alas segitiga:");
      double alas = scanner.nextDouble();

      System.out.println("Masukkan tinggi segitiga:");
      double tinggi = scanner.nextDouble();

      double luas = (alas * tinggi)/2;
      System.out.println("Luas segitiga adalah: " + luas);      
   }
}
