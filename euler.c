#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


double diff(double x, double y);

int strContains(char * str, char c){
	char *ptr;
	ptr = str;
	int i = 1;
	while(*ptr != '\0'){
		if(*ptr == c){
			return i;
		}
		ptr++;
		i++;	
	}

	return 0;
}

/*
	Returns what power of 10 our string should start at;
*/
int startPower(char * str){
	
	int pos = strContains(str,'.');
	if(!pos){
		return strlen(str)-1;
	}
	else{
		return pos - 2;	
	}

}

/* 
	Read the stdin for an integer, return an integer 
	
*/
double readDouble(){

	double out = 0; 
	
	int linelen = 200;
	
	char * input = (char *)malloc(linelen*sizeof(char));
	
	char * ptr;
	
	ptr = input;
	fgets(input,linelen,stdin);
	
	int i = startPower(input);

	do{
		if(*ptr != '\n' && (*ptr < '0' || *ptr > '9')){
			//printf("Invalid integer input");
			//return 0;			
		}
		if(*ptr <= '9' && *ptr >= '0'){
			out += (*ptr - '0') * pow (10 , i);
			i--;
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
	double in = readDouble();
	printf("Deb: %f\n",in);
	double h = 0.02;
	//eulerMethod(0,1,1,h);
	return 0;
}

