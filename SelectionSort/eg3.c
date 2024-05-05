#include<stdio.h>
#include<stdlib.h>
void selectionSort(int *data, int size);
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
    selectionSort(x,req);
    for(y=0; y<req; y++){
        printf("%d\n ", x[y]);
    }
    free(x);
    return 0;
}
void selectionSort(int *data, int size){
    int e,f,g,si,oep, iep;
    oep = size-2;
    iep = size-1;
    for(e=0; e<=oep; e++){
        si = e;
        for(f = e+1;f<=iep; f++){
            if(data[f] < data[si]){
                si = f;
            }
        }
        g = data[e];
        data[e] = data[si];
        data[si] = g;
    }
}