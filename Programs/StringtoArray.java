import java.util.*;
  
class StringtoArray {
    
  // Main driver method
    public static void main(String[] args)
    {
        // String object that contains the student name and
        // roll number separated by a comma
        String student = "Aashish:1, Bina:2, Chintu:3";
  
        // New HashMap obj
        Map<String, String> hashMap
            = new HashMap<String, String>();
  
        // split the String by a comma
        String parts[] = student.split(",");
  
        // iterate the parts and add them to a HashMap
        for (String part : parts) {
  
            // split the student data by colon to get the
            // name and roll number
            String stuData[] = part.split(":");
  
            String stuRollNo = stuData[0].trim();
            String stuName = stuData[1].trim();
  
            // Add to map
            hashMap.put(stuRollNo, stuName);
        }
  
        // Print hashMap
        System.out.println("String to HashMap: " + hashMap);
    }
}
