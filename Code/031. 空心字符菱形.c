/*
输入：
    菱型起始字母和菱形的高度。
输出：
    参看测试用例，打印空心的由字符组成的菱形。
*/
#include <stdio.h>  
int main(){  
    char c;int n,i,j;  
    scanf("%c %d",&c,&n);  
    for(i=1;i<=n;i++){  
        for(j=n;j>i;j--){  
            printf(" ");  
        }  
        if(i==1) goto haha;  
        printf("%c",c);  
        for(j=1;j<(2*i-2);j++){  
            printf(" ");  
        }  
        haha:printf("%c\n",c);  
        c++;  
    }  
    c--;  
    for(i=n;i>1;i--){  
        c--;  
        for(j=n;j>=i;j--){  
            printf(" ");  
        }  
        if(i==2) goto hah;  
        printf("%c",c);  
        for(j=1;j<(2*i-4);j++){  
            printf(" ");  
        }  
        hah:printf("%c\n",c);  
    }  
}
