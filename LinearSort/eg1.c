#include<stdio.h>
int main(){
	int x[10], e, f, y, g, size;
	size = 10;
	for(y = 0; y<size; y++){
		printf("Enter a number: ");
		scanf("%d", &x[y]);
	}
	e = 0;
	while(e<=size-2){
		f = e+1;
		while(f<=size-1){
			if(x[f] < x[e]){
				g = x[f];
				x[f] = x[e];
				x[e] = g;
			}
			f++;
		}
		e++;
	}
	for(y = 0; y<size; y++){
		printf("%d\n", x[y]);
	}
	return 0;
}