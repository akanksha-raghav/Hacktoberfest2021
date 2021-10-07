import string
import random

print('--Random password generator--\n')

pLength = int(input('Enter the length of the password: '))

numbers = string.digits
uppercase = string.ascii_uppercase
lowercase = string.ascii_lowercase
symbols = string.punctuation

all = numbers+uppercase+lowercase+symbols

getPassword = random.sample(all,pLength)
password = "".join(getPassword)

print("Password: "+password)
