#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void selectionSort(void *data, int cs, int es, int (*p2f)(void *, void *));
int myComparator(void *left, void *right){
    // we know we aer working for int
    int *a, *b;
    a = (int *)left; 
    b = (int *)right; 
    return (*a)-(*b);
}
int main(){
    int *x, y, req; 
    printf("Enter your Requirment: ");
    scanf("%d", &req);
    if(req<= 0 ){
        printf("Invalid Requirment\n");
        return 0;
    }
    x = (int *)malloc(sizeof(int)*req);
    if(x == NULL){
        printf("Enable to Allocate memory for %d numbers\n", req);
        return 0;
    }
    for(y=0; y<req; y++){
        printf("Enter a number: ");
        scanf("%d", &x[y]);
    }
    selectionSort(x,req, sizeof(int), myComparator);
    for(y=0; y<req; y++){
        printf("%d\n", x[y]);
    }
    free(x);
    return 0;
}
void selectionSort(void *ptr, int cs, int es, int (*p2f)(void *, void *)){
    int e,f,si,oep, iep, weight;
    void *a, *b,*c; 
    c = (void *)malloc(es);
    oep = cs-2;
    iep = cs-1;
    for(e=0; e<=oep; e++){
        si = e;
        for(f = e+1;f<=iep; f++){
            a = ptr+(f*es);
            b = ptr+(si*es);
            weight = p2f(a,b);
            if(weight<0){
                si = f;
            }
        }
        a = ptr+(e*es);
        b = ptr+(si*es);
        memcpy(c, (const void *)a, es);
        memcpy(a, (const void *)b, es);
        memcpy(b, (const void *)c, es);
    }
    free(c);
}