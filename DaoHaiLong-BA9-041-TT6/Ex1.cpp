#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
struct NodeTrees {
    int D;
   NodeTrees* tLeft;
   NodeTrees* tRight;
};
typedef NodeTrees *Node;
void init_tree(Node&Root)
{
   Root = NULL;
}
int emptyTree(Node Root)
{
   if(Root == NULL)   
       return 1;
   else 
       return 0;
}
 NodeTrees* NewTree(int data)
{
	NodeTrees *Trees=(struct NodeTrees*) malloc(sizeof(Trees));
	Trees->D=data;
	if(!NewTree)
	{
		printf("Memory error:");
		return NULL;
	}
	Trees->tLeft=Trees->tRight=NULL;
	return Trees;
}
int insertNode(Node&Root , int D)
 {
    if(Root!=NULL){
     if ( D == Root->D )
	  {
	      return 0;
	  }
     else 
     {
        if ( D < Root ->D)
     	{
           insertNode(Root ->tLeft , D) ;
        }
        else
        {
	       insertNode (Root->tRight , D ) ;
        }
      }
  }
  else{
  	Root=new NodeTrees;
  	Root->D=D;
  	Root->tLeft=Root->tRight=NULL;
  }
      return 1;
}
int del_node(Node &Root , int D)
{
	if(Root==NULL)
	   return 0;
	else if(Root->D >D)
	   return del_node(Root->tLeft,D);
	else if(Root->D <D)
	   return del_node(Root->tRight,D);  
	else
	{
		Node N=Root;
		if (Root->tLeft==NULL)
		    Root=Root->tRight;
		else if (Root->tRight==NULL)
		    Root=Root->tLeft;
		else
		{
			Node L=Root,R=L->tLeft;
			while(N->tRight !=NULL)
			{
				L=R;
				R=R->tRight;
			}
			N->D=R->D;
			L->tRight=R->tLeft;
			delete R;
		}	   
	}
	return 1; 
}
void searchNode( Node&Root, int D) 
{ 
    if (Root == NULL || Root->D ==D ) 
	{
       return ;  
	}
    if (Root->D < D) 
    {
       return searchNode(Root->tRight, D); 
    }
    return searchNode(Root->tLeft,D); 
}
void PLR(Node Root)
{
   if(Root!=NULL)
   {
      PLR(Root->tLeft);
      printf("%d " , Root->D);
      PLR(Root->tRight);
   }
}
int main()
{
   int n,i,D;
   NodeTrees *Root=NULL;
   printf("Size:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
   	printf("Element %d:",i+1);
   	scanf("%d",&D);
   	insertNode(Root , D);
   }
    printf("//******///******///******////****///**** \n");
   printf("PLR traversal of the given tree :\n");
   PLR(Root);
   printf("\n");
   printf("//******///******///******////****///**** \n");
   
   printf("add new root:");
   scanf("%d",&D);
   insertNode(Root , D);
   printf("PLR traversal of the given tree :\n");
   PLR(Root);
   printf("\n");
   printf("//******///******///******////****///**** \n");
   
   printf("which of elemnent you want to delete?\n");
   scanf("%d",&D);
   del_node(Root,D);
   printf("PLR traversal of the modified tree: \n");
   PLR(Root);
   printf("\n");
    printf("//******///******///******////****///**** \n");
     
    printf("Search\n");
    scanf("%d",&D);
    searchNode(Root,i);
    printf("addree of element:",D);
   
   return 0;
}
