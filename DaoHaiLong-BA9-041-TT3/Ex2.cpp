#include <stdio.h>
#include <stdlib.h>
 typedef struct _Queue 
{
  int  Person;
  struct _Queue *pnext ;
} Queue;

struct _Queue *pfront;
struct _Queue *pback;

int enQueue(int p) {
	struct _Queue * node = (struct _Queue *)malloc(sizeof*node);
	node->Person=p;
	node->pnext=NULL;
	if(pfront==NULL && pback==NULL)
	{
		pfront=pback=node;	
    }
    else{ 
      pback->pnext=node;
	  pback=node;
	}
}
int deQueue()
{
   if(pfront == NULL)
      printf("\nQueue is Empty!!!\n");
   else{
      struct _Queue *temp = pfront;
      pfront = pfront -> pnext;
      printf("\nDeleted element: %d\n", temp->Person);
      free(temp);
   }
}
void display() {
    struct _Queue *prear=pfront;
	if (pfront==NULL) 
	{
		printf("------------*----------*----------*-----------*---------\n");
	}
	else 
	{
		printf("The _Queue  is :\n");
	    while (prear!= NULL) 
	    {
           printf("%d\n",prear->Person);
		   prear=prear->pnext;
	    }
    } 
}

int main() {
	int person;
	int put,into,newperson;
	int i=0,k=0;
	printf("Enter the number of people :\n ");
	scanf("%d",&person);
	printf("------------*----------*----------*-----------*---------\n");
	for (i; i<person; i++) 
	{
		enQueue(i+1);
	}
	display();
	printf("------------*----------*----------*-----------*---------\n");
	printf("Do you want to stop the train? \n");
	printf("1:Yes\n");
	printf("2:No\n");
	scanf("%d",&into);
 if (into==1) 
 {
	do {
		put=3;
		printf("------------*----------*----------*-----------*---------\n");
		printf("1: add new person\n");
		printf("2: display\n");
		printf("3: OUT\n");
		scanf("%d",&put);
	  if (put==1) 
	   {
		 printf("------------*----------*----------*-----------*---------\n");
		 printf("What's the number of passengers on board?\n");
		 scanf("%d",&newperson);
		 for (k;k<newperson;k++) 
		 {
		    i=i+1;
	        enQueue(i);
	     }
	   }
     if (put==2) 
	 {
		display();
	 }
	 if (put==3) 
	 {
		break;
	 }
	printf("------------*----------*----------*-----------*---------\n");
	printf("Do you want to stop the train? \n");
	printf("1:Yes\n");
	printf("2:No\n");
	scanf("%d",&into);
   }
	while (into==1);
 }
return 0;
}
