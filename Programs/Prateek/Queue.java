import java.util.*;
public class QueueImplementation {
    public static void main(String args[]) {
       Queue<Integer> number = new LinkedList<>();
       
       for(int i=1;i<=5;i++){
           number.offer(i);
       }
 
 System.out.println("Queue is:"+number);
 for(int i=0;i<2;i++){
           number.poll();
       }
       
       System.out.println("Queue new is:"+number);
 
 
    }
}