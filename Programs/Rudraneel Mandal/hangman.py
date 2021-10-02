import random
from hangman_art import *

print(logo)
lives = 9
print("You have 9 lives.")
print("You will have to guess the words.")
words = ["apple", "orange", "guava", "mango", "lemon"]
choice = random.choice(words)
length = len(choice)
display = []

for i in range(length):
    display.append('_, ')
print(display)

while (lives > 0) and "_, " in display:
    position = 0
    guess = input("Guess a word: ")
    for letter in (choice):
        position += 1
        if guess == letter:
            display.pop(position - 1)
            display.insert(position - 1, guess)
            
            
    print(display)        
    if guess not in str(choice):
        lives -= 1
        print(stages[lives])
        print("You have lost a life")
        print("The remaing lives are:", lives)
        
    if lives == 0:
        print("You have lost :(")
        print("The word was", choice)
        break
    
if lives > 0:
    print("You won.")
    print(win)
