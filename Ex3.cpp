#include<stdio.h>
#include<math.h>
#include<stdlib.h> 

typedef struct{
	double x1,x2; 
	double y1,y2; 
	 
}P; 
int main(){
    P x,y; 
	printf("Enter the coordinate of point P1(x1,y1)is:");
	scanf("%lf %lf",&x.x1, &y.y1);
	printf("Enter the coordinate of point P2(x2,y2)is:");
	scanf("%lf %lf",&x.x2, &y.y2);
	double a=sqrt(pow((x.x2-x.x1),2)), b=sqrt(pow((y.y2-y.y1),2));
	double Area=a*b;
	if (x.x1 == x.x2 == y.y1 == y.y2) {
		printf("is rectangular\n");
		printf("Area of rectangular is %.1lf:",Area);
		
	}
   else if (x.x1 == y.y1 && x.x2 == y.y2){ 
      printf("is rectangular\n");
      printf("Area of rectangular is %1.lf:",Area);
   }
        
    else if (x.x1 == y.y2 && x.x2 == y.y1){
    	printf("is rectangular\n");
    	printf("Area of rectangular is %1.lf :",Area);
	}
        
    else if (x.x1 == x.x2 && y.y1 == y.y2){
    	printf("is rectangular \n");
    	printf("Area two point of rectangular is %.1lf:",Area);
	}
       
    else{
       printf("not rectangular\n");
       printf("Area two point of rectangular is 0");
    	
	}
      
	return 0;
}



