/*
小明手中有硬币，小红手中有若干张10元的纸币。已知 1 角硬币厚 1.8mm，5 角硬币厚 1.5mm，1 元硬币厚 2.0mm 。小红拿出若干张10元的纸币，小明要将 1 角的硬币放成一摞，将 5 角的硬币放成一摞，将 1 元的硬币放成一摞，如果 3 摞硬币一样高，且三摞硬币的金额之和正好等于小红要求的面值，则双方交换，否则没有办法交换。
输入： 
    小红希望交换几张10元的纸币
输出：
    1 角的数量,5 角的数量,1元的数量
*/
#include <stdio.h>    
int main(){    
    int n,x,y,z,i,j,h;    
    scanf("%d",&n);    
    i=100*n;    
    for(z=1;z<=n*10;z++){    
        for(y=1;y<=n*50;y++){    
            h=y*15;    
            x=h/20;    
            j=10*x+5*y+z;    
            if(x*20==y*15&&x*20==z*18&&i==j){    
                printf("%d,%d,%d\n",z,y,x);    
                goto end;    
            }    
        }    
    }    
    printf("No change.\n");    
    end:    
    return 0;
}
