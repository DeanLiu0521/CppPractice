#include <stdio.h>
void swap(int* a , int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int n = 10;
    int m;
    int numbers[10];
    int i;

    // 读入给定的数字
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    int Flag;
    do{
        Flag= 0;
        for(int j=0;j<n-1;j++){
            for(int k=0;k<n-j;k++){
                if(numbers[k] < numbers[k+1]){
                    swap(&numbers[k],&numbers[k+1]);
                    Flag = 1;
                }
                
            }
        }
    }while(Flag==1);

    for(int i=0;i<n;i++){
        if(i==n-1){
            printf("%d",numbers[i]);
        }else{
            printf("%d",numbers[i]);
        }
    }

    return 0;
}