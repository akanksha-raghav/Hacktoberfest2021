
#functions to perform the neccessary calculations
def addNumber(x, y):
    return x + y

def subtractNumber(x, y):
    return x - y

def multiplyNumber(x, y):
    return x * y

def divideNumber(x, y):
    if y!=0: #checking if the second number is not to zero
        return x / y
    else:
        print("Cannot be divided by 0")

#printing out the options
print("Select operation.")
print("1.Add")
print("2.Subtract")
print("3.Multiply")
print("4.Divide")

while True:
        #prompting user to enter their choice
        answer = input("Enter your choice(1/2/3/4): ")

        #checking if the input is valid
        if answer in ('1', '2', '3', '4'):
        
         num1 = float(input("Enter number one: "))
         num2 = float(input("Enter number two: "))
         
         if answer == '1':
             print(num1, "+", num2, "=", addNumber(num1,num2))

         elif answer == '2':
                print(num1, "-", num2, "=", subtractNumber(num1,num2))

         elif answer == '3':
          print(num1, "*", num2, "=", multiplyNumber(num1,num2))

         elif answer == '4':
            print(num1, "/", num2, "=", divideNumber(num1,num2))

        #Checking if the user wants to perform another calculation or no

         choice=input("Do you want to continue? y/n :")
         if choice=="y":
            continue
         else:
            print("You decided to leave!")
            break
        else:
            print("Invalid input!Try again..")
            continue


        

       
              
 



   