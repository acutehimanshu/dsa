#include<stdio.h>
#include<stdlib.h>
int main(){
int *x, e,f,g, req, y;
printf("Enter your Requirment: ");
scanf("%d", &req);
if(req<= 0 ){
	printf("Invalid Requirment");
	return 0;
}
x = (int *)malloc((sizeof(int)*req));
for(y = 0; y<req ; y++){
	printf("enter a number: ");
	scanf("%d", &x[y]);
}
e = 0;
	while(e<=req-2){
		f = e+1;
		while(f<=req-1){
			if(x[f] < x[e]){
				g = x[f];
				x[f] = x[e];
				x[e] = g;
			}
			f++;
		}
		e++;
	}



for(y = 0; y<req ; y++){
printf("%d\n", x[y]);
}

free(x);
return 0;
}