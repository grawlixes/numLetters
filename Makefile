test : numLetters
	./numLetters 99999
	./numLetters 10000301

numLetters : numLetters.c
	gcc -Wall -g -o numLetters numLetters.c
	
clean : 
	-rm numLetters
