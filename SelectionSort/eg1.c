#include<stdio.h>
int main(){
    int x[10], y,e,f,g,si; 
    for(y=0; y<10; y++){
        printf("Enter a number: ");
        scanf("%d", &x[y]);
    }
    e = 0;
    while(e<=8){
        si = e;
        f = e+1;
        while(f<10){
            if(x[si] < x[f]){
                si = f;
            }
            f++;
        }
        g = x[si];
        x[si] = x[e];
        x[e] = g;
        e++;
    }
    for(y=0; y<10; y++){
        printf("%d - ", x[y]);
    }
}