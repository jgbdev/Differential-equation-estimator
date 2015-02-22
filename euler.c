#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


double diff(double x, double y);

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

void eulerMethod(double x0, double xEnd, double y0, double h){
	double x = x0;
	double y = y0;
	int reached = x<xEnd;
	
	if(!reached){
		h = -h;
	}

	int euler = 0;
	while((x<xEnd) == reached){

		if(euler){
			y += h*diff(x,y);
		}else{
			double k1,k2,k3,k4;
			k1 = diff(x,y);
			k2 = diff(x+h/2,y + h*k1*0.5);
			k3 = diff(x+h/2,y + h*k2*0.5);
			k4 = diff(x+h,y + h*k3);
			y += h/6*(k1 + 2*k2 + 2*k3 + k4);
		}
		
		x+=h;
		printf("x: %f  y: %f\n", x,y);
		
		


	}
	
}



double diff(double x,double y){
	return y;
}

int main(){

	printf("Start point");
	in = readInt();
	double h = 0.02;
	eulerMethod(0,1,1,h);
	return 0;
}

