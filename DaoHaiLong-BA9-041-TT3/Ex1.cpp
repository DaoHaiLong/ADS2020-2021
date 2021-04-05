#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Stack {
	char str;
	struct Stack *pNext;
} ;
 struct Stack *PTOP ;
char Push(char str) {
	struct Stack *n;
	n = (struct Stack*)(malloc(sizeof*n));
	n->str=str;

	if (PTOP == NULL) {
		n->pNext=NULL;
	}
	n->pNext=PTOP;
	PTOP=n;
	printf(" is %c \n",n->str);
}
char Pop(char str)
{	

   if(PTOP == NULL)
   { 
      printf("is a letter of the name .");
   }  
   else
   {
      struct Stack *name = PTOP;
      printf("%c", name->str);
      PTOP = name->pNext;
      free(name);
   }
}

int main(int argc, char *argv[]) {
	int i;
	char s[1000];
	printf("Enter the name: ");
	gets(s);
    printf("after : \n");
	for (i=0;i<strlen(s);i++) {
		Push(s[i]);
	}
    printf("The reverse : \n");
   	for (i=0;i<strlen(s);i++) 
	{
	  Pop(s[i]);
	}
 return 0;
}
