#include <stdio.h>
#include <math.h>
#define m 4
#define n 33//Can be changed
#define e 3




int main(void){
	unsigned long c = (int)pow(m,e)%n;
	printf("Your Message is M:%d cipher C:%d\n",m,c);
	
}


