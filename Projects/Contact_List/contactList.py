from genericpath import getsize
from os import close, write
import os.path

def readContacts():     # Function to display the Contact(s)
    
    choice=int(input("\nPress 1 to show ENTIRE contact list\nPress 2 to SEARCH for a contact\n\nEnter your choice: "))
    print("\n")
    if(choice==1):      # Display the entire Contact list
        with open('542.input.txt','r') as f:    # Opening file in read mode

            no_of_contacts=f.readline()     # Getting the size of the list stored at the begining of the list 
            if(int(no_of_contacts)==0):        # If contact list is empty
                print("Records are empty\n")

            for i in range(int(no_of_contacts)):    # Printing all contacts
                test_case=[""]*4
                test_case[0]=f.readline()
                test_case[1]=f.readline()
                test_case[2]=f.readline()
                test_case[3]=f.readline()
                print("Name: "+ test_case[0]+ " Contact No.: "+ test_case[1]+ " Connection: "+ test_case[2]+ " Locaion: "+test_case[3]+ "\n")
    elif(choice==2):            # Display selected contact
        read_method=int(input("To seach for specific data, Enter:\n1 for Name\n2 for Contact No.\n3 for Connection\n4 for Location\n\nEnter your choice: "))     # Getting the method to search contact    
        print("\n")
        if(read_method==1):
            method="Name"
        elif(read_method==2):
            method="Contact No."
        elif(read_method==3):
            method="Connection"
        elif(read_method==4):
            method="Location" 
        else:
            method=""
            print("Invalid Choice!\n") 
            return      
        searched_data=input("Enter the "+ method+" to be searched: ")       # Getting the data to be searched 
        res=0

        with open('542.input.txt','r') as f:    # Opening file in read mode

            no_of_contacts=f.readline()     # Copying the size of the list stored at the begining of the list 

            for i in range(int(no_of_contacts)):
                test_case=[""]*4
                test_case[0]=f.readline()
                test_case[1]=f.readline()
                test_case[2]=f.readline()
                test_case[3]=f.readline()
                tmp1=test_case[int(read_method)-1].lower()
                tmp2=searched_data.lower()
                if(tmp1.find(tmp2)!=-1):        # Matching the file data with user input data
                    res+=1
                    print("Name: "+ test_case[0]+ " Contact No.: "+ test_case[1]+ " Connection: "+ test_case[2]+ " Locaion: "+test_case[3]+ "\n")   # Printing the search results

            if(res<=0):
                print("No matches found!\n") 
    else:
        print("Invalid Choice!\n")               


def addContact():       # Function to add new contacts
    print("Adding New Contact...\n")        # Getting data of contact to be added from the user
    newContact=[""]*4
    newContact[0]=input("Enter the Name: ")+'\n'
    newContact[1]=input("Enter the Contact No: ")+'\n'
    newContact[2]=input("Enter the Connection (Eg. Friend/Teacher/Colleague): ")+'\n'
    newContact[3]=input("Enter the brief Location (Eg. Name of CITY): ")+'\n'

    
    if(os.path.getsize("542.input.txt")==0):    # If the file is empty
        with open('542.input.txt','w') as f:
            f.write("1\n")
            f.writelines(newContact[0])     # Adding the new contact 
            f.writelines(newContact[1])
            f.writelines(newContact[2])
            f.writelines(newContact[3])
        f.close()            
    else:       
        with open('542.input.txt','r') as f:    # Opening file in read mode
            
            no_of_contacts=f.readline()     # Copying the size of the list stored at the begining of the list 
            test_caseAdd=[[0 for i in range(4)] for j in range(int(no_of_contacts))]    # Declaring 2D array to store the data of the contact list
            for i in range(0, int(no_of_contacts)):
                test_caseAdd[i][0]=f.readline()     # Copying the data from the contact list to 2D array
                test_caseAdd[i][1]=f.readline()
                test_caseAdd[i][2]=f.readline()
                test_caseAdd[i][3]=f.readline()

            position_in_sorted_list=no_of_contacts
            for i in range(1, 1+int(no_of_contacts)):
                if(int(no_of_contacts)>0):      # Sorting the names of the contacts
                    if(test_caseAdd[i-1][0]>newContact[0]):
                        position_in_sorted_list=i-1     # Getting the position of the new contact in the sorted list
                        break;
        delivery=0
        f=open('542.input.txt','w')     # Creating a new empty file (contact list)
        f.write(str(int(no_of_contacts)+1)+'\n')
        for i in range(0, int(no_of_contacts)+1):
            if(i!=int(position_in_sorted_list)):
                f.writelines(test_caseAdd[i-delivery])  # Writing the data of the 2D array in the file
            else:
                delivery=1
                f.writelines(newContact)        # Writing the new contact in the file
                 
    print("Added Contact:\tName: "+ newContact[0]+ "  Contact No.: "+ newContact[1]+ "  Connection: "+ newContact[2]+ "  Location: "+ newContact[3]+ "\n")      # Printing the added contact 
    f.close()

            
def deleteContacts():       # Function to delete contact(s)
            
    with open('542.input.txt','r') as f:    # Opening file in read mode
        check_if_empty=f.readlines()        

    if(len(check_if_empty)>1):    # Checking if the contact list is empty
        whatToDelete=int(input("Enter\n1 to delete a SINGLE contact\n2 to delete the ENTIRE contact list\n\nEnter your choice: "))       # Getting the method to search contact 
        print("\n")
        if(whatToDelete==2):
            confirm_request=int(input("Are you sure you want to delete the ENTIRE contact list?\nPress 1 to DELETE\nPress 2 to CANCEL\n\nEnter your choice: "))       
            print("\n")
            if(confirm_request==1):         # Confirming the deletion request
                f=open('542.input.txt','w')         # Clearing the list and creating a new contact list
                f.write("0")
                f.close()
            else:
                print("Deletion aborted\n")    
        elif(whatToDelete==1):    
            del_method=int(input("To search for contact to be deleted, Enter:\n1 for Name\n2 for Contact No.\n3 for Connection\n4 for Location\n\nEnter your choice: "))     # Getting the method to search
            print("\n")
            if(del_method==1):
                method="Name"
            elif(del_method==2):
                method="Contact No."
            elif(del_method==3):
                method="Connection"
            elif(del_method==4):
                method="Location"
            else:
                method=""
                print("Invalid Choice!\n") 
                return

            searched_data=input("Enter the "+ method+ " to be searched: ")      # Getting the data to be searched 

            with open('542.input.txt','r') as f:    # Opening file in read mode

                no_of_contacts=f.readline()     # Copying the size of the list stored at the begining of the list 
                no_of_suspects=[""]*(1+int(no_of_contacts))
                no_of_suspects[0]=0
                print("\nPossible Contacts:\n")
                test_case=[[0 for i in range(4)] for j in range(int(no_of_contacts))]       # Declaring a 2D array1 data store data of all contacts
                suspects=[[0 for i in range(4)] for j in range(int(no_of_contacts))]        # Declaring a 2D array2 data store data of suspected contacts

                for i in range(int(no_of_contacts)):
                    test_case[i][0]=f.readline()        # Copying the data from the contact list to 2D array1
                    test_case[i][1]=f.readline()
                    test_case[i][2]=f.readline()
                    test_case[i][3]=f.readline()
                    tmp1=test_case[i][int(del_method)-1].lower()
                    tmp2=searched_data.lower()
                    if(tmp1.find(tmp2)!=-1):            # Matching the file data with user input data
                        suspects[int(no_of_suspects[0])][0]=test_case[i][0]     # Copying data from 2D array1 to 2D array2
                        suspects[int(no_of_suspects[0])][1]=test_case[i][1]
                        suspects[int(no_of_suspects[0])][2]=test_case[i][2]
                        suspects[int(no_of_suspects[0])][3]=test_case[i][3]

                        no_of_suspects[0]+=1        # Incrementing the no. of suspects by 1 if a match is found
                        no_of_suspects[no_of_suspects[0]]=i        # Storing the position of the suspects
                        print("Enter "+ str(no_of_suspects[0])+ " to delete contact:\t"+ "Name: "+ suspects[int(no_of_suspects[0])-1][0]+ " Contact No.: "+ suspects[int(no_of_suspects[0])-1][1]+ " Connection: "+ suspects[int(no_of_suspects[0])-1][2]+ " Locaion: "+suspects[int(no_of_suspects[0])-1][3]+ "\n")

                if(no_of_suspects[0]>0):        # Checking if any matches found

                    confirmed_suspect=int(input("Enter the Contact to be deleted: "))       # Getting the confirmed contact from the suspects
                    confirm_request=int(input("Are you sure you want to delete contact "+ suspects[int(confirmed_suspect)-1][0]+ " ?\nPress 1 to DELETE\nPress 2 to CANCEL\n\nEnter your choice: "))
                    print("\n")
                    if(confirm_request==1):         # Confirming the deletion request
                        confirmed_suspect=no_of_suspects[confirmed_suspect]     # Getting the position of the confirmed contact to be deleted
                        f=open('542.input.txt','w')         # Creating a new blank contact list
                        f.writelines(str(int(no_of_contacts)-1)+"\n")       # Writing the new no. of contacts
                        for i in range(int(no_of_contacts)):
                            if(i!=confirmed_suspect):           # Checking for the position of the confirmed contact to be deleted
                                f.writelines(test_case[i][0])           # Writing data from the 2D array1 to the new file (contact list)
                                f.writelines(test_case[i][1])
                                f.writelines(test_case[i][2])
                                f.writelines(test_case[i][3])
                        f.close()
                        print("Deleted Contact:\nName: "+ test_case[confirmed_suspect][0]+ "Contact No: "+ test_case[confirmed_suspect][1]+ "Connection: "+test_case[confirmed_suspect][2]+ "Location: "+ test_case[confirmed_suspect][3])      # Printing the details of the deleted contact
                    else:
                        print("Deletion aborted\n")    
                else:
                    print("No matches found!\nDeletion aborted\n")          # Aborting if no matches are found 
        else:
            print("Invalid Choice!\n")            
    else:
        print("Records are empty\n")        # If the file is empty      

def modifyContacts():
            
    with open('542.input.txt','r') as f:    # Opening file in read mode
        check_if_empty=f.readlines()

    if(len(check_if_empty)>1):          # Checking if the contact list is empty    
            
        mod_method=int(input("To search for contact to be modifed, Enter:\n1 for Name\n2 for Contact No.\n3 for Connection\n4 for Location\n\nEnter your choice: "))     # Getting the method to search
        print("\n")
        if(mod_method==1):
            method="Name"
        elif(mod_method==2):
            method="Contact No."
        elif(mod_method==3):
            method="Connection"
        elif(mod_method==4):
            method="Location" 
        else:
            method=""
            print("Invalid Choice!\n")  
            return

        searched_data=input("Enter the "+ method+ " to be searched: ")          # Getting the data to be searched 

        with open('542.input.txt','r') as f:    # Opening file in read mode

            no_of_contacts=f.readline()     # Copying the size of the list stored at the begining of the list 
            no_of_suspects=[""]*(1+int(no_of_contacts))
            no_of_suspects[0]=0
            print("\nPossible Contacts:\n")
            test_case=[[0 for i in range(4)] for j in range(int(no_of_contacts))]           # Declaring a 2D array1 data store data of all contacts
            suspects=[[0 for i in range(4)] for j in range(int(no_of_contacts))]            # Declaring a 2D array2 data store data of suspected contacts

            for i in range(int(no_of_contacts)):

                test_case[i][0]=f.readline()            # Copying the data from the contact list to 2D array1
                test_case[i][1]=f.readline()
                test_case[i][2]=f.readline()
                test_case[i][3]=f.readline()
                tmp1=test_case[i][int(mod_method)-1].lower()
                tmp2=searched_data.lower()

                if(tmp1.find(tmp2)!=-1):            # Matching the file data with user input data

                    suspects[int(no_of_suspects[0])][0]=test_case[i][0]         # Copying data from 2D array1 to 2D array2
                    suspects[int(no_of_suspects[0])][1]=test_case[i][1]
                    suspects[int(no_of_suspects[0])][2]=test_case[i][2]
                    suspects[int(no_of_suspects[0])][3]=test_case[i][3]

                    no_of_suspects[0]+=1            # Incrementing the no. of suspects by 1 if a match is found
                    no_of_suspects[no_of_suspects[0]]=i        # Storing the position of the suspects
                    print("Enter "+ str(no_of_suspects[0])+ " to modify contact:\t"+ "Name: "+ suspects[int(no_of_suspects[0])-1][0]+ " Contact No.: "+ suspects[int(no_of_suspects[0])-1][1]+ " Connection: "+ suspects[int(no_of_suspects[0])-1][2]+ " Locaion: "+suspects[int(no_of_suspects[0])-1][3]+ "\n")
            
            if(no_of_suspects[0]>0):            # Checking if any matches found

                confirmed_suspect=int(input("Enter the Contact to be modified: "))          # Getting the confirmed contact from the suspects
                confirm_request=int(input("Are you sure you want to modify contact "+ suspects[int(confirmed_suspect)-1][0]+ " ?\nPress 1 to MODIFY\nPress 2 to CANCEL\n"))
                if(confirm_request==1):             # Confirming the modification request
                    confirmed_suspect=no_of_suspects[confirmed_suspect]             # Getting the position of the confirmed contact to be modified
                    mod_method2=int(input("To search for contact to be modifed, Enter:\n1 for Name\n2 for Contact No.\n3 for Connection\n4 for Location\n\nEnter your choice: "))        # Getting the data to be modified
                    print("\n")
                    if(mod_method2==1):
                        method2="Name"
                    elif(mod_method2==2):
                        method2="Contact No."
                    elif(mod_method2==3):
                        method2="Connection"
                    elif(mod_method2==4):
                        method2="Location"  
                    else:
                        method2=""
                        print("Invalid Choice!\n") 
                        return  

                    print("Old "+method2+": "+test_case[confirmed_suspect][mod_method2-1])      # Printing the old data which is to be modified
                    searched_data2=input("Enter the new "+ method2+ "\n")           # Getting the modified data
                    test_case[confirmed_suspect][mod_method2-1]=searched_data2+"\n"         # Overwriting the old data with new data

                    f=open('542.input.txt','w')             # Creating a new blank contact list
                    f.writelines(str(int(no_of_contacts))+"\n")             # Writing the new no. of contacts
                    for i in range(int(no_of_contacts)):
                        f.writelines(test_case[i][0])           # Writing data from the 2D array1 to the new file (contact list)
                        f.writelines(test_case[i][1])
                        f.writelines(test_case[i][2])
                        f.writelines(test_case[i][3])
                    f.close()
                    print("Modified Contact:\nName: "+ test_case[confirmed_suspect][0]+ "Contact No: "+ test_case[confirmed_suspect][1]+ "Connection: "+test_case[confirmed_suspect][2]+ "Location: "+ test_case[confirmed_suspect][3])         # Printing the details of the mdified contact
                else:
                    print("Modification aborted\n")             
            else:
                print("No matches found!\nModification aborted\n")          # Aborting if no matches are found                
    else:
        print("Records are empty\n")            # If the file is empty


def main():             # Main function with menu

    path=os.path.dirname(os.path.abspath(__file__))+"/542.input.txt"        # Creating the destination record file location
    if(os.path.isfile(path)==False):         # If the file does not exist at the given location (path) then create a new file and write 0 in it
        f=open('542.input.txt','w')
        f.write("0")
        f.close()
    function=int(input("Enter:\n1 to See contact(s)\n2 to Add Contact\n3 to Delete Contact(s)\n4 to modify contact\n\nEnter your choice: "))          # Menu for the user
    print("\n")
    if(function==1):
        readContacts()          # To see any contact(s)
    elif(function==2):
        addContact()            # To add a new contact
    elif(function==3):
        deleteContacts()        # To delete any contact(s)
    elif(function==4):
        modifyContacts()        # To modify any contact
    else:
        print("Invalid Choice!\n")    

main()        # Calling the main function     