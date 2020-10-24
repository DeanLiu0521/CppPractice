#include <stdio.h>
#include <string.h>

int n = 1000000;
int mark[1000001];

int main() {
    int a,b,c;
    memset(mark, 0, sizeof(mark));
    mark[0] = 1;
    mark[1] = 1;
    std::scanf(a,b);
    int d;
    for (c = 2; c * c <= n; c++) {
        if(mark[c]!=1){
            for(d = 2; d < n/c; d++){
                mark[c*d] = 1;
            }
        }
    }
    
    for(int i = b; i < a; i++){
        printf("%d\n",mark[i]);
    }

    return 0;
}

