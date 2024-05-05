#include<stdio.h>
void selectionSort(int *data, int size);
int main(){
    int x[5], y; 
    for(y=0; y<5; y++){
        printf("Enter a number: ");
        scanf("%d", &x[y]);
    }
    selectionSort(x,5);
    for(y=0; y<5; y++){
        printf("%d \n ", x[y]);
    }
}
void selectionSort(int *data, int size){
    int e,f,g,si,oep, iep;
    oep = size-2;
    iep = size-1;
    for(e=0; e<=oep; e++){
        si = e;
        for(f = e+1;; f<=iep; f++){
            if(data[f] < data[si]){
                si = f;
            }
        }
        g = data[e];
        data[e] = data[si];
        data[si] = g;
    }
}