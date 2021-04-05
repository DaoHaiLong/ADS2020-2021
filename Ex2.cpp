#include<stdio.h>
#include<math.h>
#include <malloc.h>
int main(){
   int i, n,S=0;
   int *l;
    printf("Enter the length of array L:");
	scanf("%d", &n);
    l= (int *) malloc(n * sizeof(int));
    printf("Enter elements of the array:\n");
    for (i = 0; i < n; i++) {
		scanf("%d", l + i);
	}
    for (i = 0; i < n; i++){
		S = S + *(l + i);          
	}
	
	printf("---------------out-----------------\n");
    printf("Sum of all elements in array:S= %d\n", S);
    return 0;
}

//pseudo-code
//Step1: Give that variables: n ,S=0 and index i
//Step2: declare an int pointer name l and use Malloc to memory allocation for l
//Step3: Using the While Loop is i=0 less than n.Read address l+i and save to malloc 
//Step4:Using the While Loop is i=0 less than n.Give that S=S+ *(l+i)
    //( *(l+i) is to take out the saved value in step 3)
//Step5:Return S .Stop 


// The complexity is: O(1+1+n+n+n+1)=O(3n+3)=O(n)
