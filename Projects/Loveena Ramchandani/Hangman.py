from words import word_list
import random #module which generates random output
def getRandom():
	word=random.choice(word_list)
	return word.upper()
def play(word):
	word_completion='_ '*len(word)
	guessed=False
	guessed_letter=[]
	guessed_word=[]
	tries=6
	print("Let's play Hangman")
	print(displayHangman(tries))
	print(word_completion,end="\n")
	while not guessed and tries>0:
		guess=input("Enter your guess:").upper()
		if len(guess)==1 and guess.isalpha():
			if guess in guessed_letter:
				print("You have already guessed",guess)
			elif guess not in word:
				print(guess,"is not in word")
				tries-=1
				guessed_letter.append(guess)
			else:
				print("Good Job",guess,"is in the word")
				guessed_letter.append(guess)
				word_as_list=list(word_completion)
				indices=[i for i,letter in enumerate(word) if letter==guess]
				for index in indices:
					word_as_list[index]=guess
				word_completion=''.join(word_as_list)
				#print(word_completion)
				if '_' not in word_completion:
					guessed=True
		elif len(guess)==len(word) and guess.isalpha():
			if guess in guessed_word:
				print("You have already guessed the word",guess)
			elif guess!=word:
				print(guess,"is not the word")
				tries-=1
				guessed_word.append(guess)
			else:
				guessed=True
				word_completion=guess
		else:
			print("Not a valid guess")
		print(displayHangman(tries))
		print(word_completion)
	if guessed:
		print("Congrats,you guessed the word.You win!!!!!")
	else:
		print("Sorry you ran out of tries.The word was",word)
def displayHangman(tries):
	stages=[#6 final state:head,torso,both arms and both legs
				"""
					_ _ _ _ _ _ _
					|       |
					|       0
					|      \\|/
					|       |
					|      / \\
				""",
				#5 head,torso,both arms and one leg
				"""
					_ _ _ _ _ _ _
					|       |
					|       0
					|       |
					|      \\|/
					|      / 
				""",
				#4 head,torso,both arms
				"""
					_ _ _ _ _ _ _
					|       |
					|       0
					|      \\|/ 
					|       |
					|      
				""",
				#3 head,torso,one arm
				"""
					_ _ _ _ _ _ _
					|       |
					|       0
					|      \\|
					|       |
					|      
				""",
				#2 head with torso
				"""
					_ _ _ _ _ _ _
					|       |
					|       0
					|       |
					|       |
					|      
				""",
				#1 head with torso
				"""
					_ _ _ _ _ _ _
					|       |
					|       0
					|      
					|      
					|     
				""",
				#0 initial empty state
				"""
					_ _ _ _ _ _ _
					|       
					|      
					|     
					|   
					|   
				"""
	]
	return stages[tries]
def main():
	word=getRandom()
	play(word)
	while input("Do you want to play again(Y/N):").upper()=="Y":
		word=getRandom()
		play(word)
main()