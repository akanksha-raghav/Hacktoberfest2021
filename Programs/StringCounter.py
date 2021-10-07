str="my name is bob."
space_counter = 0
counter = 0
flag = True
for i in str :
	
    if i ==" " and flag == True:
        counter + 1
        print(counter)
    
    if i != " ":
        flag = True

    else:
        flag = False    


print("the no of words in string are:",counter)
