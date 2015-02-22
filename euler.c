#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int readInt(){

	int out = 0; 
	
	int i = 0;

	int linelen = 200;
	
	char * input = (char *)malloc(linelen*sizeof(char));
	
	char * ptr;
	ptr = input;
	fgets(input,linelen,stdin);
	
	do{
		if(*ptr != '\n' && (*ptr < '0' || *ptr > '9')){
			printf("Invalid integer input");
			return 0;
			
			
		}
	
		out += *ptr - '0' * pow (10 , i);
		i++;
		ptr++;
	}while(*ptr != '\0');
	return out;
}


int main(){

	int in = readInt();

		
	printf("Input: %d\n", in);

	return 0;
}

