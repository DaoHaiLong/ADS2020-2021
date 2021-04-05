#include <stdio.h>
 
void swapped(int *xfirst, int *ysecond)
{
    int temp = *xfirst;
    *xfirst = *ysecond;
    *ysecond = temp;
}
void bubblesort(int str[], int n)
{
	int k,Pass=0;
	bool swap=true;
	while(swap==true)
	{
		swap=false;
	  for(k=0;k<n-1;k++)
	  {
	    	if(str[k]>str[k+1])
		   {
		    	swapped(&str[k],&str[k+1]);
		    	swap=true;
		   } 
	  }  
	  printf("Pass %d:\n",Pass+1);
	  for(k=0;k<n;k++)
	  {
	      printf("%d\n",str[k]);	
	  }
	  if(swap==false)
	  {
	  	break;
	  }
	   Pass++;
	  for(int i=0;i<=n-2;i++)
	  {
	  	if(str[i]>str[i+1])
		   {
		    	swapped(&str[i],&str[i+1]);
		    	swap=true;
		   } 
	  }
	  printf("Pass %d:\n",Pass+1);
	  for(k=0;k<n;k++)
	  {
	      printf("%d\n",str[k]);	
	  }
	  Pass++;
  }
}
int main()
{   
    int n,k;
	printf("Enter the size of array:");
	scanf("%d",&n);
	int str[n];
	printf("*****-------*****------****-----*****\n");
	for(k=0;k<n;k++) 
	{
		printf("Enter element of array %d :",k+1);
		scanf("%d",&str[k]);
	}
	printf("\n");
	bubblesort(str,n);
	printf("\n");
	printf(" The sorted array is :\n ");
	for (k=0;k<n;k++) 
	{
		printf("%d ",str[k]);  
	}
	printf("\n");
	printf("Since the algorithm must executed had 1 while loop and 1 for loop=>The complexity of program is = O(n^2)\n");
	return 0;
}
