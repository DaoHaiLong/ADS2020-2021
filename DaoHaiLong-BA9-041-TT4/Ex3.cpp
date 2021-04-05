#include<stdio.h> 
#include<math.h>

bool factorization(int number)
{
	 if(number <= 1)
	 {
	 	return false;
	 }
	 else
	 {
	 	for(int k=2; k<= sqrt(number);k++)
		 {
	 	   if (number % k == 0) 
			 {
	 		    return true;
			 }
		 }
        
	 }
	return true;
}
int main()
{
	int number,k;
	printf("Enter the integer number n=");
	scanf("%d",&number);
	printf("--------------****** OUT ******----------------\n");
	printf("--------------****** OUT ******----------------\n");
	printf("Print factorization to screen are:number = ");
	for(k=2; k<=number; k++)
	{
	   while ((number % k == 0)&& (factorization(k))) 
	   {
            printf("%d",k);
            number= number/k;
         if(number>1) 
		  { 
		    printf(" * ");
		  }
        }  	 
    }
return 0;
}
