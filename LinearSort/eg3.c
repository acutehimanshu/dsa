#include<stdio.h>
#include<stdlib.h>
int linearSort(int *x, int collectionSize){
    int outerEndPoints, innerEndPoint, e , f, g , y;
    outerEndPoints = collectionSize-2;
    innerEndPoint = collectionSize - 1; 
    for(e = 0; e<=outerEndPoints; e++){
        for(f = e+1; f<=innerEndPoint; f++){
            if(x[f] < x[e]){
                g = x[e];
                x[e] = x[f];
                x[f] = g;
            }
        }
    }
}
int main(){
int *x, req, y;
printf("Enter your Requirment: ");
scanf("%d", &req);
if(req<= 0 ){
	printf("Invalid Requirment");
	return 0;
}
x = (int *)malloc((sizeof(int)*req));
for(y = 0; y<req ; y++){
	printf("enter a number: ");
	scanf("%d", &x[y]);
}
linearSort(x, req);
for(y = 0; y<req ; y++){
printf("%d\n", x[y]);
}
free(x);
return 0;
}