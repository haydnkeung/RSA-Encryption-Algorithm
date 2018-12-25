#ifndef DIOPHANTINE_H
#define DIOPHANTINE_H


/*Implementation of special case of diophatine
equation for setup of RSA encryption where the gcd(a,b)=1.
This function only returns a solution to the var associated
with e*/
// Pre-condition: 1<e<phi
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
	//printf("gcd:%d\n",r1 );
	printf("Certificate of correctness: %d*%d+%d*%d=%d\n",phi,k1,e,d1,(phi*k1+e*d1));
	return d1;

}

#endif