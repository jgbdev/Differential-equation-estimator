#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
	Replicate built in function to reverse a string	
*/
char * strrev(char *str){

	char *p1, *p2;
	if(! str || ! *str){
		return str;
	}
	for( p1 = str, p2 = str + strlen(str) -1 ; p2>p1;++p1,--p2){
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}
	return str;

}

/* 
	Read the stdin for an integer, return an integer 
	
*/
int readInt(){

	int out = 0; 
	
	int i = 0;

	int linelen = 200;
	
	char * input = (char *)malloc(linelen*sizeof(char));
	
	char * ptr;
	
	
	ptr = input;
	fgets(input,linelen,stdin);
	input = strrev(input);
	do{
		if(*ptr != '\n' && (*ptr < '0' || *ptr > '9')){
			printf("Invalid integer input");
			return 0;			
		}
		if(*ptr <= '9' && *ptr >= '0'){
			out += (*ptr - '0') * pow (10 , i);
			i++;
		}
		ptr++;
	}while(*ptr != '\0');

	return out;
}


int main(){

	int in = readInt();

		
	

	return 0;
}

