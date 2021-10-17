#include<stdio.h>
void printtable(int *multable,int num, int n){
    printf("the multiplication table of %d is :\n", num);
    for (int i=0; i<n;i++){
        multable[i] = num*(i+1);
    }
    for (int i=0;i<n;i++){
        printf("%d*%d=%d\n",num,i+1,multable[i]);
    }
    printf("----------------------------------------\n\n");
}
int main(){
    int multable[3][10];
    printtable(multable[0],2,10);
    printtable(multable[1],7,10);
    printtable(multable[2],9,10);
    return 0;
}