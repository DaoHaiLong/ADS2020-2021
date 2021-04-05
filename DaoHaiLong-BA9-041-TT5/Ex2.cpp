#include <stdio.h>
#include<malloc.h>
#include <stdlib.h>
struct ImplementMergeSort
{
	int Datanumber;
	struct  ImplementMergeSort*pNext;
};
struct  ImplementMergeSort*pHead;
int initImplementMergeSort(int newdatanumber)
{
	struct ImplementMergeSort*IMS= (struct ImplementMergeSort*)(malloc(sizeof*IMS));
	IMS->Datanumber=newdatanumber;
	if (pHead) 
	{
		IMS->pNext=NULL;
	}
	IMS->pNext=pHead;
	pHead=IMS;
}

struct ImplementMergeSort*SortedMerge (struct ImplementMergeSort*inumber, struct ImplementMergeSort*knumber) 
{
	if (inumber ==NULL) 
	{
	   return knumber;
    }
	if (knumber ==NULL) 
	{
	   return inumber;
	}
	/* compare 2 elements and pick the smaller one */
	struct ImplementMergeSort* resultsmerge = NULL;
	if (inumber ->Datanumber<=knumber ->Datanumber) 
	{
		resultsmerge= inumber;
		resultsmerge -> pNext=SortedMerge(inumber ->pNext, knumber);
	} 
	else
	{
		resultsmerge= knumber;
		resultsmerge-> pNext=SortedMerge(inumber ,knumber ->pNext);
	}
return resultsmerge;
}
void FUNCTIONS(struct ImplementMergeSort*head, struct ImplementMergeSort**pFronts, struct ImplementMergeSort**pBacks) 
{
	/* devide the linked list into 2 parts using 2 pointers */
	struct ImplementMergeSort* IMSifirstsNumbers;
	struct ImplementMergeSort* IMSksecondsNumbers;
	if (head==NULL || head->pNext==NULL) 
	{
		*pFronts=head;
		*pBacks=NULL;
	}
	else 
	{	IMSifirstsNumbers=head;
		IMSksecondsNumbers=head->pNext;
		while(IMSksecondsNumbers!=NULL) 
		{
			IMSksecondsNumbers=IMSksecondsNumbers->pNext;
			if (IMSksecondsNumbers!=NULL)
			 {
				IMSksecondsNumbers=IMSksecondsNumbers->pNext;
				IMSifirstsNumbers=IMSifirstsNumbers->pNext;
			 }
		}
	}
	*pFronts=head;
	*pBacks=IMSifirstsNumbers->pNext;
	IMSifirstsNumbers->pNext=NULL;
}

void Mergesort(struct ImplementMergeSort** headed) 
{
	struct ImplementMergeSort* head=*headed;
	struct ImplementMergeSort* inumber =NULL;
	struct ImplementMergeSort* knumber =NULL;
	if (head==NULL || head->pNext==NULL)
	{
	    return;
    }
	FUNCTIONS(head,&inumber ,&knumber);
	Mergesort(&inumber);
	Mergesort(&knumber);
	*headed=SortedMerge(inumber,knumber);
}

void display() 
{
   struct ImplementMergeSort *SortedNumbers =pHead;
   if (SortedNumbers==NULL) 
   {
		printf("List is empty");
   }
  else
   { 
      while (SortedNumbers!=NULL) 
     	{
           printf("%d\n",SortedNumbers->Datanumber);
	       SortedNumbers=SortedNumbers->pNext;
        }
   }
}
////    MAIN         ////
int main()
{   
    int n,Datanumber;
	printf("Enter size of link list:");
	scanf("%d",&n);
	for (int j=0; j<n; j++) 
	{
		printf("Enter the elements of link list %d:",j+1);
		scanf("%d",&Datanumber);
		initImplementMergeSort(Datanumber);
	}
	printf("\n");
	Mergesort(&pHead);
	printf("The sorted linked list is:\n ");
	display();
	printf("\n");
	printf("The complexity of this algorithm is O(log(n))");
	return 0;
}
