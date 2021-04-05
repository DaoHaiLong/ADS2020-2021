#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct myCarcarries{
	
   int passengers;
   char name;       //data
   myCarcarries*pnext;
};

struct railwaytrain{
	
	int NumberTrain;
	myCarcarries* pHead;
};

void init(railwaytrain*RT ){
	
 RT-> NumberTrain = 0;
 RT-> pHead= NULL ;
}

myCarcarries *initmyCarcarries(int p , char n){
	
	myCarcarries * Car = new( myCarcarries);
	Car -> passengers=p;
	Car ->  name = n;
	Car-> pnext= NULL;
	return Car;
}

int isEmpty( railwaytrain*RT ) 
{
	return ( RT -> NumberTrain == 0);
}

int isEmpty( myCarcarries * n)
{
	return ( n -> passengers == 0);
}


void insert( railwaytrain*RT , myCarcarries * Carnew, myCarcarries*C = NULL)
 { 
   	if (isEmpty(RT)) 
	{  
      RT-> pHead = Carnew ;
      RT-> NumberTrain++ ;
    } 
    else
	{
       Carnew -> pnext = C-> pnext ;
       C -> pnext= Carnew ;
	}
 
   RT-> NumberTrain++;
 }
 
int charlengths(char * RT)
 {
	int n = 0;
	while (*(RT + n - 1) != 0)
	{
		n++;
	}
	return n;
 }
 
int lengths(railwaytrain*RT )
 {
	return RT -> NumberTrain ;
 }
 
void remove(railwaytrain*RT,char n)
 {
	myCarcarries * Car =RT ->pHead;
	
	if(Car -> name ==n) 
	 {
	  RT -> pHead = Car -> pnext ;
	  free(Car);
      RT-> NumberTrain--;
      return ;
	 }
	 
	myCarcarries * myCar= Car ->pnext;
	
	for(int i=0 ;i < lengths(RT);i++)
	 {
		if (Car-> name == n)
		{ 
			myCar -> pnext = Car -> pnext;
			RT -> NumberTrain-- ;
			free(Car);
			break; 
		}
		
		Car = myCar;
		Car = Car -> pnext;
	 }
 }
 
 void checkstrain(railwaytrain*RT)
 {
	myCarcarries * Car = RT -> pHead, *Temp = NULL;
	
	for (int i=0; i < lengths(RT); i++)
	{
		if (isEmpty(RT)) 
		{
			remove(RT, Car -> name);
			Car = Temp;
		}
		
		Temp = Car;
		Car = Car -> pnext;
	}
	
    printf("/*-----------------_-_-_-_-_-_-_-_-_------------------*/\n");
    
    printf("/*-----------------_-_-_-_-_-_-_-_-_------------------*/\n");
    	
    printf("/*-----------------_-_-_-_-_-_-_-_-_------------------*/\n");
 }
 
 void infodevices(railwaytrain*RT)
 {
    myCarcarries * Car = RT -> pHead;
	for (int i=0; i < lengths(RT); i++)
	{
		printf(" myCarcarrie has a passengers ", Car -> name , Car ->passengers);
	
		Car = Car -> pnext;
	}
 }
 
 int main()
 {
    int NumberTrain, NumberofCar;
	char name;
	int i;
	
	railwaytrain RT ;
	myCarcarries * Car , *Tempterm = NULL;
	init( &RT);
	
	printf("Enter the number of myCarcarries:\n");
	scanf("%d",&NumberTrain);

	for ( i=0; i < NumberTrain ; i++)
	{
		printf( "Enter the number of passengers in myCarcarries numbers ", i+1 );
		scanf("%d",&NumberofCar);
		
		printf( "Name the myCarcarries number ", i+1);
		scanf("%s",&name);
		
		Car = initmyCarcarries(NumberofCar, name);
		if (i == 0)
		 { 
		    insert(&RT,Car); 
		 }
		else
		{ 
		    insert(&RT,Car, Tempterm);
		}
		    
		Tempterm = Car;
	}
	
	printf("/*------------------_-_-_-_-_-_-_-_-_----------------------*/\n");
	

	printf("Hello, I'm the ship's captain. I have two questions to ask people\n"); 
	printf("Question 1: Do you want to add another myCarcarries ?\n");

    printf("1: Yes,I have\n");
	printf("2: No,I don't'\n");
  	scanf("%d",&NumberTrain);
    
    if (NumberTrain == 1)
	{
		printf( "Enter number passengers for this myCarcarries:");
		scanf("%d",&NumberofCar);
		
		printf(  "Name this myCarcarries: ");
		scanf("%s",&name);
		
	    Car = initmyCarcarries(NumberofCar, name);
		insert(&RT,Car, Tempterm);
	}
	
	printf("/*------------------_-_-_-_-_-_-_-_-_----------------------*/\n");
	
    printf("Question 2: Do you want to remove myCarcarries in railwaytrain ?\n ");
   
    printf("1: Yes,I have\n");
	printf("2: No,Idon;t\n");
    scanf("%d",&NumberTrain);
    
    if (NumberofCar== 1)
	{
		printf( "Enter name of car that you want to remove: ");
		scanf("%s",&name);
		remove(&RT, name);			
	}
	
	printf("/*-----Thank you to everyone who accompanied us on the train VN612-----*/\n");
	checkstrain(&RT);
	infodevices(&RT);
	return 0;
 }
 
	
	



