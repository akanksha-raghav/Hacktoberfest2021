
package javaapplication15;
import java.util.*;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

/**
 *
 * @author Rupendra
 */
public class SwingProgram {

    public static void main(String[] args) {
        // TODO code application logic here
        String emp[]={"ANDRE","JABU","HENRY"};
        HashMap<String,String> provider=new HashMap<String,String>();
        provider.put("Vodafone","072");
        provider.put("MTN","083");
        provider.put("Cell C","084");
        
        Set<String> key=provider.keySet();
        Iterator i=key.iterator();
        int c=0;
        HashMap<String,String> emp_prov=new HashMap<String,String>();        
        while(i.hasNext()){
            emp_prov.put(emp[c],i.next().toString());
            c++;
        }
        String outputDisplay="CELL PHONE NUMBER GENERATOR \n ******************************************* \n";
        for(int j=0;j<emp.length;j++){
            String empname=emp[j];
            String serviceprovider=emp_prov.get(emp[j]);
            String start=provider.get(emp_prov.get(emp[j]));
            outputDisplay += generateNumber(empname,serviceprovider,start);
        }

           JOptionPane.showMessageDialog(null, outputDisplay, "Network Provider Assignment", JOptionPane.INFORMATION_MESSAGE);

    }
    public static String generateNumber(String empname,String provider,String start){
           int firstThree = 100 + (int)(Math.random() * 900);
           int lastFour = 1000 + (int)(Math.random() * 9000);
           String s=empname+" will be on the "+provider+" network with phone number "+start+" "+firstThree+"-("+lastFour+")\n";
           return s;
    }
    
}

class CustomerPurchase{
    int customerNumber;
    String firstName;
    String surName;
    String product;
    double price;
    int quantity;

    public int getCustomerNumber() {
        return customerNumber;
    }

    public void setCustomerNumber(int customerNumber) {
        this.customerNumber = customerNumber;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getSurName() {
        return surName;
    }

    public void setSurName(String surName) {
        this.surName = surName;
    }

    public String getProduct() {
        return product;
    }

    public void setProduct(String product) {
        this.product = product;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }
    
    public CustomerPurchase(int customerNumber,String firstName,String surName,String product,double price,int quantity){
        this.customerNumber=customerNumber;
        this.firstName=firstName;
        this.surName=surName;
        this.product=product;
        this.price=price;
        this.quantity=quantity;
    }
    
}
