#include<stdio.h> 
#include<math.h>

int multiplytwointerger( int x, int y) 
{
	if (y==0) 
	{
		return 0;
	}
	else if (y>0) 
	{
		return (x + multiplytwointerger(x,y-1));
	}
	else  
	{
	    return (- multiplytwointerger(x,-y));
	}
}

int main() 
{
   int x,y;
   printf("Enter the first number x:\n ");
   scanf("%d",&x);
   printf("Enter the first number y:\n ");
   scanf("%d",&y);
   int Program =multiplytwointerger(x,y);
   
   printf("**********----------**********----------\n");
   printf("multiply two interger are: %d",Program);   
   return 0; 
} 
// complexity of implemented algorithm are: O(1)

