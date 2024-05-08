#include<stdio.h>
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
    int x[5], i;
    for (i = 0; i < 5; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &x[i]);
    }
    insertionSort(x, 5);
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", x[i]);
    }
    
    return 0;
}