
#include<stdio.h> 
#include<math.h>
#include<stdlib.h>
#include <stdbool.h>

struct math
{
	int CONS , DEG;
	math *pNext;
};

struct polynomialFunction
{
	int N;
	math*pHead;
};

void init(polynomialFunction *polf)
{
	polf->N = 0;
	polf->pHead = NULL;
}

math *initMath(int C, int D)
{
	math *m = new(math);
	m -> CONS = C;
	m -> DEG = D;
	m -> pNext = NULL;

	return m;
}

int isEmpty(polynomialFunction*polf)
{
	return polf->N == 0;
}

int  isEmpty(math*m)
{
	return m-> CONS == 0;
}

void insert(math*mNew, polynomialFunction *polf, math*n= NULL)
{
	if (isEmpty(polf))
	{
		polf->pHead = mNew;
	}
	else
	{
		mNew -> pNext = n->pNext;
		n->pNext = mNew;
	}
	polf->N++;
}

// add term into polynomialFunction
void addofterm(polynomialFunction *polf, int C, int D)
{
    math*m= polf ->pHead;
	for (int i = 0; i< polf->N -1;i++)
	{
		if (m->DEG == D)
		{
			m->CONS += C;
			return;
		}
		m = m->pNext;
	}
	math *t = initMath(C, D);
	insert(t, polf, m);
}

void removemath(polynomialFunction *polf, int D)
{
	math*m = polf->pHead;
	
	if (m ->DEG == D)
	{
		polf->pHead = m->pNext;
		free(m);
		polf->N--;
		return;
	}
	
	math *a = m->pNext;
	
	for (int i=0; i < polf->N; i++)
	{
		if (m->DEG == D)
		{
			a->pNext = m->pNext;
			polf->N--;
			free(m);
			break;
		}
		
		a = m;
		m = m->pNext;
	}
}

int calc(int a, polynomialFunction *polf)
{
	math*m = polf->pHead;
	int SumOFpolynomialFunction =0;
	
	for (int i=0; i < polf->N; i++)
	{
		SumOFpolynomialFunction += ((m->CONS )* pow(a, m-> DEG ));
		m= m->pNext;
	}
	return SumOFpolynomialFunction;
}

void display( polynomialFunction *polf)
{
	math*m = polf->pHead;
	
	printf(  "/*------------------_-_-_-_-_-_-_-_-_----------------------*/\n" );
	
    printf(  "The polynomial function is: F(x) =" );
	
	for (int i=0; i < polf->N - 1; i++)
	{
		
		printf("%d *x^ %d +",m-> CONS,m-> DEG);
		m = m-> pNext;

	}
       printf("%d *x^ %d \n ",m-> CONS,m-> DEG);
}
int main()
{
	int N,i;
	int C,D;
	
    polynomialFunction polf;
	init(&polf);
	
	printf( " Number of terms in polynomialFunction: " );
scanf("%d",&N) ;
	
	for ( i=0; i < N; i++)
	{
		printf(  " term \n");
		
		printf( "a *x^n\n");
		printf( "Enter a :\n");
	      scanf("%d",&C) ;
	    printf( " Enter n:\n");
		scanf("%d",&D) ;
		addofterm(&polf, C, D);
	}
	
   printf( "/*------------------_-_-_-_-_-_-_-_-_----------------------*/\n" );
	
	printf( "Hello, I'm an artificial intelligence machine. I have two questions to ask you about this equation:\n");
	
	printf( "Question 1: Do you want to add a different number of term to the equation ? \n" );
	printf( "1: Yes,I have\n" );
	printf(" 2: No,I don't\n");
    scanf("%d",&C) ;
	
	if (C == 1)
	{
		
	printf(  " term \n");
		
		printf( "a *x^n\n");
		printf( "Enter a :\n");
	      scanf("%d",&C) ;
	    printf( " Enter n:\n");
		scanf("%d",&D) ;
		addofterm(&polf, C, D);
	}
	
	display(&polf );
	printf( "/*------------------_-_-_-_-_-_-_-_-_----------------------*/\n" );
	
	printf("Question 2: Do you want to removed any term of polynomialFunction ? \n" );
	printf( "1: Yes,I have \n" );
	printf("2: No,I don't \n");
    scanf("%d",&C) ;
	if (C== 1)
	{
		printf( "Enter exponential n \n:" );
		scanf("%d",&D) ;
		removemath(&polf,D);
		display(&polf);
	}
	printf( "Enter  the number x : \n" );
	scanf("%d",&C) ;
	printf( "/*------------------_-_-_-_-_-_-_-_-_----------------------*/ \n");
	
	printf("Result of CALCULATION : ROCal= %d" , calc(C, &polf) );
	return 0;
}
