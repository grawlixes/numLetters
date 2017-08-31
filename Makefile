test : numLetters
	./numLetters 99999
	./numLetters 10000301

numLetters : numLetters.c
	gcc -Wall -g -o numLetters numLetters.c
	
clean : 
	-rm numLetters hw04_$(USER).tar.gz
	
submit: numLetters.c
	mkdir hw04_$(USER)
	cp numLetters.c hw04_$(USER)
	tar -cvzf hw04_$(USER).tar.gz hw04_$(USER)
	rm -r hw04_$(USER)
	echo Turn in hw04_$(USER).tar.gz on myCourses under content, Homework Submissions		