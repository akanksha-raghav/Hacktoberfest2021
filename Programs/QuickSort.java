import java.util.Scanner ;
public class Main
{
 public static int partition(int arr[], int low, int high) 
 {
   int temp;
   int pivot = arr[high];            // assuming last element of the array as pivot element
   int i = (low - 1);               // assuming index of i pointer as one position less than the first element 
   for (int j = low; j <= high - 1; j++)   // assuming the index of j pointer as the first position
   { 
                        
     if (arr[j] <= pivot) 
     { 
       i++;                   
       temp = arr[i];
       arr[i] = arr[j];
       arr[j] = temp;
     } 
   } 

                 // swapping the pivot (last) element and element at i + 1 index
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

                // returning the index of pivot element having lesser elements to the left and greater elements to the right
    return (i + 1); 
 } 

 public static void quick_sort(int arr[], int low, int high) 
 { 
   if (low < high) 
  { 

               // partitioning the single array into two sub-arrays 
    int p = partition(arr, low, high); 

               // sorting the sub-arrays
    quick_sort(arr, low, p - 1); 
    quick_sort(arr, p + 1, high); 
  } 
 } 

 public static void print(int arr[], int n)
 {
   for(int i = 0; i < n; i++)
  {
     System.out.print(arr[i] + " ");
  }

 }

public static void main(String args[])
 {
   Scanner sc = new Scanner(System.in);
   int i;
   int n = sc.nextInt();
   int arr[] = new int[n];
   for(i = 0; i < n; i++)
   {
   arr[i] = sc.nextInt();
   }
   quick_sort(arr, 0, n - 1);
   print(arr, n); 
 }
}
