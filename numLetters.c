#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv, char input[]) {
	input = argv[1]; //set string "input" to the argument provided
	int length = strlen(input); //set int "length" to the length of said input
	int i; //iterator
	/*these arrays hold the lengths of the word form of the various words that are
	used to describe variables. Like one, two, thousand, million, twenty, etc.*/
	int numLengths[] = {0, 3/*one*/, 3/*two*/, 5/*three*/, 4/*etc.*/, 4, 3, 5, 5, 4};
	int teenLengths[] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
	int specialLengths[] = {0, 3/*ten*/, 6/*twenty*/, 6, 5, 5, 5, 7, 6, 6};
	int total = 0; //holds the total length for printing
	int x = 0; //marks teen numbers
	int y = 0; //marks million numbers
	int z = 0; //marks thousand numbers
	
	if((input[0]-'0'==0) && length==1) {
		printf("+4 Zero\n0 is 4 long");
		return 0;
	}

	for(i=0;i<length;i++){
		int place = length-1-i;
		int j;
		for(j=0;j<10;j++) {
			if((input[i]-'0'==j) && (place==1) && (input[i]-'0'==1)) {
				printf("+%d\n", teenLengths[(input[i+1]-'0')]);
				total += teenLengths[(input[i+1]-'0')];
				j++;
				x = 1;
				break;
			} else if((input[i]-'0'==j) && (place==7||place==4||place==1) && (x==0)) {
				printf("+%d\n", specialLengths[j]);
				total += specialLengths[j];
				break;
			} else if(input[i]-'0'==j && (x==0)) {
				printf("+%d\n", numLengths[j]);
				total += numLengths[j];
				break;
			} else {
				continue;
			}
		}
		if(place==9) {
			printf("+7 billion\n");
			total += 7; //"billion"
		} else if (place==8 && input[i]-'0'!=0) {
			printf("+7 hundred\n");
			total += 7; //"hundred"
			y = 1;
		} else if (place==7 && input[i]-'0'!=0) {
			y = 1;
		} else if (place==6 && ((input[i]-'0'!=0) || (y==1))) {
			printf("+7 million\n");
			total += 7; //"million"
		} else if (place==5 && input[i]-'0'!=0) {
			printf("+7 hundred\n");
			total += 7; //"hundred
			z = 1;
		} else if (place==4 && input[i]-'0'!=0) {
			z = 1;
		} else if (place==3 && ((input[i]-'0'!=0) || (z==1))) {
			printf("+8 thousand\n");
			total += 8; //"thousand"
		} else if (place==2 && input[i]-'0'!=0) {
			printf("+7 hundred\n");
			total += 7; //"hundred"
		} else {
			continue;
		}
	}
	printf("%s takes %d letters\n", input, total);
	return 0;
}