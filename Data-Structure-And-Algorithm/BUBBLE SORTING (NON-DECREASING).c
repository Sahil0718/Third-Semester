
#include <stdio.h>
#include <stdlib.h>
int temp,i,j;
bubbleSort(int A[20], int n){
for( i = 0; i<n-1; i++){
    for( j = 0; j<n-i-1; j++){
        if(A[j]>A[j+1]){ //index value must be smaller
 temp = A[j];
 A[j] = A[j+1];
 A[j + 1] = temp;
        }
    }
}
}

int main(){
int A[20],n,i;
printf("ENTER THE N VALUE:");
scanf("%d", &n);
printf("ENTER THE DATA ITEMS: \n");
for(i=0; i<n; i++){
    scanf("%d", &A[i]);
}
printf("THE VALUES AFTER DATA SORTED IN NON_DECREASING WAY IS: \n");
bubbleSort(A,n);
for(i = 0; i<n; i++){
    printf("%d\t",A[i]);
}
free(A);
return 0;
}
