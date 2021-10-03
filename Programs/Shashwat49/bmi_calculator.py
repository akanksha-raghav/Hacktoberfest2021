h = eval(input("Enter your height(in m): "))
w = eval(input("Enter your weight(in kg): "))

bmi = w/h**2

print(f"Your BMI is: {bmi}")

if bmi > 0:
    if bmi<18.5:
        print("You are underweight.")
    elif (bmi>18.5) and (bmi<24.9):
        print("You are normal.")
    elif (bmi>24.9):
        print("You are overweight.")
else:
    print("Enter a valid value of height or weight!")