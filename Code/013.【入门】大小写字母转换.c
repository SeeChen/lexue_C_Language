/*
我们知道，英文字母是分大小写的，下面我们需要编写一个简单的程序，将输入的全部小写字母变换为大写字母，大写字母变换为小写字母，非写字母保持不变。
输入：
    一个字符
输出：
    变换后的字符
*/
#include<stdio.h>  
int main(){  
    char x;  
    scanf("%c",&x);  
    if(x>='A'&&x<='Z'){  
        x=x+32;  
    }else if(x>='a'&&x<='z'){  
        x=x-32; }        
    printf("%c\n",x); 
}
