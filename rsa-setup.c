#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "diophantine.h"
#define e 3
#define LIMIT 100
//we will use e=(2^16)+1 for this RSA implementation
//This RSA will use the Euler totient function instead of Carmicheal's
//LIMIT is the maximum number that p or q can possible be


/*Returns a random number from 1 to n inclusive*/
int randnum(int n){

	int divisor = RAND_MAX/(n+1);
	int result;

	do{
		result= rand()/divisor;
	}while(result>n||result==0);

	return result;

}

bool isprime(int n){
	if(n<=1){
		return false;
	}
	for(int i = 2;i*i<=n;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

bool iscoprime(int a,int b){

 	int min = a>b?b:a;
 	int max = a>b?a:b;
 	if(max%min==0||a<=1||b<=1){
 		return false;
 	}
 	for(int i = 2;i*i<=min;i++){
 		if(a%i==0&&b%i==0){
 			return false;
 		}
 	}
 	return true;
 }

int inrange(int d,int phi){
	while(d<0){
		d+=phi;
	}
	while(d>=phi){
		d%=phi;
	}
	return d;
}


int main(void){
	/*char x = 'y';
	do{
		printf("Would you like to setup RSA encryption?(y/n)");
		scanf("%c",&x);
     printf("%d",x);
	}while(x!='y');*/
	

	int p;
	int q;
	

	do{
		p=randnum(LIMIT);
		q=randnum(LIMIT);
	}while((p-1)*(q-1)<=e||iscoprime((p-1)*(q-1),e)==false||isprime(q)==false||isprime(p)==false);
		
	int n = p*q;
	int phi = (p-1)*(q-1);

	//Converts the linear congruence into a diophantine equation
	//and solves using the extended Euculidian Algorithm/Bezout's
	//with backward subsitution
	int d = diophantinesolver(phi,e);

	//Ensures that 0<d<phi
	d = inrange(d,phi);

	printf("Keys generated with p:%d q:%d n:%d e:%d phi:%d\n",p,q,n,e,phi);
	printf("Your Private Key is: (%d,%d)\n",d,n);
	printf("Your Public Key is: (%d,%d)\n",e,n);
		
	
}