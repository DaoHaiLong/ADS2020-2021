#include<stdio.h>
#include<math.h>

int main() {
	int number,i,Sumof;
	printf("Enter the number is:");
	scanf("%d",&number);
	
    printf("---------------out-----------------\n");
    printf("All perfect numbers are:\n", number);
	for(i = 1; i <= number; i++)
    {
    	Sumof =0;
    	for(int k=1;k<i;k++){
    		if(i%k == 0)
        {
            Sumof = Sumof+k;
        } 
      }
     
    if(Sumof == i){
       printf("%d ",i);
    }
    
 }

 return 0; 
}

//pseudo-code
// Step1: Given that munber,Sumof and index i,k
// Step2: Using the While loop is i=1 less than or equal number and assign Sumof equal to 0
// Step3: using the while loop is k=1 less than i.If i%k==0 then Sumof = Sumof+k
// Step 4: if Sumof ==i then print i
// Step 5: Return number

