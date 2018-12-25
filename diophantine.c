#include "diophantine.h"
#include <assert.h>
#include <stdio.h>


int diophantinesolver(int phi, int e){
	assert(e>1&&phi>e);
	int k1 = 1;
	int d1 = 0;
	int r1 = phi;


	int k2 = 0;
	int d2 = 1;
	int r2 = e;
	

	
	int q3;
	int k3;
	int d3;
	int r3;

	do{
		 q3 = r1/r2;
		 k3 = k1-(q3*k2);
		 d3 = d1-(q3*d2);
		 r3 = r1-(q3*r2);

		 k1=k2;
		 d1=d2;
		 r1=r2;

		 k2=k3;
		 d2=d3;
		 r2=r3;

	}while(r2!=0);
	return d1;

}
