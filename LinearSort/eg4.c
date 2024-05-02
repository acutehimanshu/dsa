#include<stdio.h>
#include<string.h> // for memcpy
#include<stdlib.h>
// p2f pointer to function
int linearSort(void *ptr, int collectionSize, int elementSize, int (*p2f)(void *, void *)){
    int e,f, outerEndPoint, innerEndPoints, w;
    void *a, *b, *c; 
    c = (void *)malloc(elementSize);
    outerEndPoint = collectionSize-2;
    innerEndPoints = collectionSize-1;
    for(e=0; e<=outerEndPoint; e++){
        for(f = e+1; f<=innerEndPoints; f++){
            a = ptr+(f*elementSize);
            b = ptr+(e*elementSize);
            w = p2f(a,b);
            if(w<0){
                memcpy(c, (const void *)a, elementSize);
                memcpy(a, (const void *)b, elementSize);
                memcpy(b, (const void *)c, elementSize);
            }
        }
    }
    free(c);
}
// this will be written by one end user.
int myComparator(void *left, void *right){
    int *p2num1, *p2num2;
    p2num1 = (int *) left;
    p2num2 = (int * )right;
    return (*p2num1)-(*p2num2);
}
int main(){
int *x, req, y;
printf("Enter your Requirment: ");
scanf("%d", &req);
if(req<= 0 ){
	printf("Invalid Requirment\n");
	return 0;
}
x = (int *)malloc((sizeof(int)*req));
for(y = 0; y<req ; y++){
	printf("enter a number: ");
	scanf("%d", &x[y]);
}
linearSort(x, req, sizeof(int), myComparator);
for(y = 0; y<req ; y++){
printf("%d\n", x[y]);
}
free(x);
return 0;
}