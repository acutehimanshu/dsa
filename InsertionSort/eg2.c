#include<stdio.h>
int main(){
	int x[10], num, z, i, count;
	count = 10;
	for ( i = 0; i < count; i++)
	{
		printf("Enter a number: ");
        scanf("%d", &x[i]);
	}
	for (i = 1; i < count; i++)
	{
		for (z = i-1, num=x[i]; z >= 0 && x[z] > num; z--) x[z+1] = x[z];
		x[z+1] = num;
	}

	printf("Sorted Array : \n");
	for ( i = 0; i < count; i++)
	{
		printf("%d\n", x[i]);
	}
	
	return 0;
}