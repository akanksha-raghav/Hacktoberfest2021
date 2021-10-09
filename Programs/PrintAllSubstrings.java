import java.util.*;

public class PrintAllSubstrings {


    public static void  printing(String s)
    {
        for(int i =0 ; i<s.length();i++)
        {
            for(int j =i+1;j<=s.length();j++)
            {
                System.out.println(s.substring(i, j)); 
            }
        }
        
    }
    public static void main(String [] args)
    {
        Scanner scn =new Scanner(System.in);
        System.out.println("enter string -");
        String s=scn.next();

        printing(s);
    }
}