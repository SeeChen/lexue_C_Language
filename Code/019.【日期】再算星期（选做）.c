/*
再次给出任意一个年月日（年>1900），现在我们不能只是直接计算，要先判断给出的日期是否合法，对于非法的日期要给出错误提示信息，合法的日期要再计算是星期几。
输入：
    年 月 日
输出：
    0～6。
    星期日用 0 表示，星期一用 1 表示，星期二用 2 表示......星期六用 6 表示。
*/
#include <stdio.h>     
int main(){     
    int year,month,day,i,total;     
    scanf("%d %d %d",&year,&month,&day);   
       
   if(month>12){   
       printf("month is error.\n");   
 }else if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day>31){   
     printf("day is error.\n");   
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
