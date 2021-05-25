/*
任意给出一个年月日，求出是星期几。
输入：
    年 月 日
输出：
    0～6。
    星期日用 0 表示，星期一用 1 表示，星期二用 2 表示......星期六用 6 表示。
假设年份大于1900。先想一想：我们现在只会使用 if 语句，该如何建立数学模型？找到数学模型是解决本题的关键。
*/
#include <stdio.h>     
int main(){     
    int year,month,day,i,total;     
    scanf("%d %d %d",&year,&month,&day);   
       
   if(month>12){   
       printf("month is error.");   
 }else if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day>31){   
     printf("day is error.");   
   }else if((month==4||month==6||month==9||month==11)&&day>30){   
        printf("day is error.");   
   }else if(month==2&&((year%4==0&&year%100!=0)||(year%400==0))&&day>29){   
      printf("day is error.");   
   }else if(month==2&&!((year%4==0&&year%100!=0)||(year%400==0))&&day>28){   
     printf("day is error.");   
   }else{   
    
       day+=(year-1900)*365;     
        total=year-1900;     
     for(i=0;i<total;i++){     
         if((year%4==0&&year%100!=0)||(year%400==0)){     
             day+=1;     
          }     
            year--;     
      }     
        month-=1;     
        switch(month){     
           case 0:     
              day+=0;break;     
            case 1:     
              day+=31;break;     
           case 2:     
              day+=59;break;     
           case 3:     
              day+=90;break;     
           case 4:     
              day+=120;break;     
          case 5:     
              day+=151;break;     
          case 6:     
              day+=181;break;     
          case 7:     
              day+=212;break;     
          case 8:     
              day+=243;break;     
          case 9:     
              day+=273;break;     
          case 10:     
             day+=304;break;     
          case 11:     
             day+=334;break;     
          default:     
             break;     
       }   
      printf("%d\n",day%7);   
  }   
}  
