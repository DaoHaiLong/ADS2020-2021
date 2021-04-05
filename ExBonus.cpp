#include<stdio.h>
#include<math.h>

int main(){
	int factorization ,n;
	printf("Enter the number:\n");
	scanf("%d",&n);
	
	printf("Print factorization to screen is:\n");
	for(int k=2;k<=n;k++)
	{
		factorization=0;
	   while(n%k==0)
	    {
		    ++factorization;
			n=n/k;
	    }
	 
	   if(factorization){
	      if(factorization >=1)
		    {
		     printf("%d * %d", k, factorization);	
		    } 
		   else{
             printf("%d", k);
			} 
			if(n>1) 
		    { 
		     printf(" * ");
		    }
	   }
   }
	
	return 0;
}
