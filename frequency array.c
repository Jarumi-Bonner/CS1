#include<stdio.h>

int main(){
    int n, t, i, j, arr[30],len, halflen,flag=0,count=0;

    printf("Enter number of elements to insert in an array:");
    scanf("%d",&len);
    printf("Enter elements to insert in an array:");
    for(i=0;i<len;i++){
        scanf("%d",&t);
        arr[i]=t;
    }
    printf("\n");

    /*****************************/
    for(i=0;i<len;i++){
        count=1;
        for(j=i+1;j<=len-1;j++){
            if(arr[i]==arr[j] && arr[i]!='\0'){
                count++;
                arr[j]='\0';
            }
        }
        if(arr[i]!='\0'){
            printf("%d is %d times.\n",arr[i],count);
        }
    }

    /*****************************/
    getch();
    return 0;
}
