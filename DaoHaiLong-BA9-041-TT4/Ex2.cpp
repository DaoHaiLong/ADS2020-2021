#include<stdio.h> 
#include<math.h>
int findstheleastbills()
{ 
    int bills[6]={ 50,20,5,10,1,2};
	int min=bills[0];
	for(int i=0;i<6;i++)
	{ 
		if(bills[i]<min)
		{
          min=bills[i];
		}
	}
	return min;

}
int main(){
	
	int find=findstheleastbills();
	printf("Min of money is: %d",find);
	return 0;
}
// complexity of implemented algorithm are : O(n)
