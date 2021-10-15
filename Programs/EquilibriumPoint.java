import java.lang.*;
import java.util.*;

public class EquilibriumPoint {
    public static boolean isEqPoint(int [] arr , int n){
        int sum=0;
        for(int i=0 ; i<n ; i++){
            sum += arr[i];
        }
        int l_sum = 0;
        for(int i=0 ; i<n ; i++){
            if(l_sum == (sum-arr[i]))
                return true;
            l_sum += arr[i];
            sum -= arr[i];
        }
        return false;
    }
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter length of array : ");
        int n = sc.nextInt();
        int [] arr = new int[n];
        System.out.println("Enter array elements");
        for(int i=0 ; i<n ; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println("Array has an equilibrium point : " + (isEqPoint(arr, n)? "Yes" : "No"));

    }
}
