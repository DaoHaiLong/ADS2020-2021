#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include <time.h>

typedef struct _Game {
	int ListNumber;
	struct _Game* pNext;
};
 struct _Game *game;
int Push(int a) 
{
	struct _Game*gamek;
	gamek=(struct _Game*) malloc(sizeof*gamek);
	gamek-> ListNumber= a ;
	if(game==NULL) 
	{
		gamek-> pNext=NULL;
	}
	gamek->pNext=game;
	game=gamek;
}
int Pop()
 {
	if (game==NULL) 
	{
		printf("-----------*-*-*-----------*-*-*----------\n");
		printf("Game.");
	}
	else 
	{
		struct _Game * player=game;
		printf("%d", player->ListNumber);
	    game=player ->pNext;
		free(player);
	}
}

void Display()
{
    struct _Game *player= game;
    while(player->pNext != NULL)
	  {
	 	printf( "/*------------------_-_-_-_-_-_-_-_-_----------------------*/\n" );
	    printf("%d\n:",player -> ListNumber);
	    player = player-> pNext;
      }
    printf( "/*------------------_-_-_-_-_-_-_-_-_----------------------*/\n" );
	printf("%d\n:",player -> ListNumber);
}
int main() 
{
	int a;
	int thirdnumber;
	printf(" Drawing the frist number:\n");
	getchar();
	srand(time (NULL));
    int iSecret1 = rand() % 9 + 1;
    printf ("%d",iSecret1);
	Push(iSecret1);
	printf(" Drawing the second numbers:\n");
	getchar();
	int iSecret2= rand() % 9 + 1;
  while (iSecret2==iSecret1) 
	{
		printf("-----------*-*-*-----------*-*-*----------\n");
        printf("two numbers as the same\n");
		getchar();
		iSecret2= rand() % 9 + 1;
    }
	Push(iSecret2);
	printf("-----------*-*-*-----------*-*-*----------\n");
	printf("Enter the third numbers:\n");
	scanf("%d",&thirdnumber);
	printf("-----------*-*-*-----------*-*-*----------\n");
  if ((thirdnumber>iSecret1 && thirdnumber<iSecret2)||(thirdnumber>iSecret2 && thirdnumber<iSecret1)) 
	{
		printf("-----------*-*-*-----------*-*-*----------\n");
		printf("YOU WIN\n");
		printf("The two numbers are %d and %d ",iSecret1,iSecret2);
	} 
 else 
	{
     	Pop();
     	printf("-----------*-*-*-----------*-*-*----------\n");
		printf("Your number was incorrect\n");
		printf("re-draw the second numbers \n");
		getchar();
		getchar();
		int iSecret2=rand() % 9 + 1;
     while (iSecret1==iSecret2) 
	    {
	    	printf("-----------*-*-*-----------*-*-*----------\n");
            printf("2 numbers are the same, re-draw\n");
			getchar();
			iSecret2=rand() % 9 + 1;
        }
		Push(iSecret2);
		printf("-----------*-*-*-----------*-*-*----------\n");
		printf("Done\n");
		printf("Re-enter your third numbers\n");
		scanf("%d",&thirdnumber);
   	if ((thirdnumber>iSecret1 && thirdnumber<iSecret2)||(thirdnumber>iSecret2 && thirdnumber<iSecret1)) 
	{
		printf("-----------*-*-*-----------*-*-*----------\n");
		printf("YOU WIN\n");
		printf("The two numbers are %d and %d ",iSecret1,iSecret2);
	} 
	else 
	{
		printf("-----------*-*-*-----------*-*-*----------\n");
     	printf("YOU LOST\n");
	    printf("The 2 numbers are %d and %d ",iSecret1,iSecret2);
	}
}
return 0;
}
