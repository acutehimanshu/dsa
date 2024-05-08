#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insertionSort(void *x, int lb, int ub, int es, int (*p2f)(void * , void *)){
    void *block; 
    int y,z;
    block= (void *)malloc(es);
    y = lb+1;
    while (y<=ub)
    {
        memcpy(block, (void *) (x+(y*es)), es);
        z = y-1;
        while (z>= lb &&  p2f(x+(z*es) , block)>0)
        {
            memcpy(x+((z+1)*es), (const void *)( x+(z*es)), es);
            z--;
        }
        memcpy(x+((z+1)*es), (const void *) block, es);
        y++;
    }
    free(block);
}
int myComparator(void *left, void *right){
    int *a, *b;
    a = (int *)left;
    b = (int *)right;
    return (*a)-(*b);
}
int main(){
    int *x, i, req, start, end;
    printf("Enter requirment: ");
    scanf("%d", &req);
    if(req<=0){
        printf("Invalid reqiirments");
        return 0;
    }

    printf("Enter Start point: ");
    scanf("%d", &start);
    if(start<=0 && start >= req ){
        printf("Invalid start");
        return 0;
    }

    printf("Enter End point: ");
    scanf("%d", &end);
    if(end<=start && start >= req ){
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
    insertionSort(x, start, end, sizeof(int), myComparator);
    for (i = 0; i <req; i++)
    {
        printf("%d\n", x[i]);
    }
    free(x);
    return 0;
}