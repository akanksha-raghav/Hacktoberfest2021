#creating empty list
lis = []

#enter the number of elements in list
noofelements = int(input('How many numbers? '))

# iterating till count to append all input elements in list
for n in range(noofelements):
    number = int(input('Enter number: '))
    lis.append(number)

# displaying largest number
print("Largest number in list is :", max(lis))