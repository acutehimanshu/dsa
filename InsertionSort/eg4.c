#include<stdio.h>
#include<stdlib.h>
void insertionSort(int *x, int size){
    int num, y,z;
    for (y = 1; y <= size-1; y++)
    {
        for (z = y-1, num = x[y]; z>=0 && x[z] > num; z--)
            x[z+1] = x[z];
        x[z+1] = num;
    }
}
int main(){
    int *x, i, req;
    printf("Enter requirment: ");
    scanf("%d", &req);
    if(req<=0){
        printf("Invalid reqiirments");
        return 0;
    }
    x = (int *)malloc(sizeof(int) * req);
    if(x==NULL){
        printf("Unbale to allocation memory for %d numbers\n", req);
        return 0;
    }
    for (i = 0; i < req; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &x[i]);
    }
    insertionSort(x, req);
    for (i = 0; i <req; i++)
    {
        printf("%d\n", x[i]);
    }
    free(x);
    return 0;
}