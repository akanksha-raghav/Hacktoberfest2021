import java.util.*;

class Solution {

	public static int[] stockSpan(int[] price) {
		//Your code goes here
        Stack<Integer> s = new Stack<>();
        int n=price.length;
        int[] ans = new int[n];
        s.push(0);
        ans[0]=1;
        for(int i=1;i<n;i++){
            while(!s.isEmpty()&&price[s.peek()]<price[i]){
                s.pop();
            }
            ans[i]=s.isEmpty()?i+1:i-s.peek();
            s.push(i);
        }
        return ans;
	}

}
public class Main
{
    public static void printArray(int[] arr) {
    	for (int i = 0 ; i < arr.length; i++) {
    		System.out.print(arr[i] + " ");
    	}

    	System.out.println();
    }
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int size = s.nextInt(); 
		int[] input = new int[size];
        for(int i = 0; i < size; i++) {
    		input[i] = s.nextInt();
    	}
    	int[] output = Solution.stockSpan(input);

    	printArray(output);
	}
}