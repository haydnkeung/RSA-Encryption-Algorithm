#include <stdio.h>
#include <math.h>
#define a 4
#define n 33//Can be changed
#define e 3
#define c 31
#define d 7



int main(void){
	unsigned long m = (unsigned long)pow(c,d)%n;
	printf("Cipher is C:%lu original message is M:%lu\n",c,m);

}