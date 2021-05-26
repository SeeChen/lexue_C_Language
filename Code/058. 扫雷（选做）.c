/*
背景
你玩儿过扫雷游戏吧？有个操作系统中带了这个小游戏，那个系统叫什么来着？;-)在游戏中要想过关，就必须要在一个 NxM 的区域上找出所有的地雷。游戏过程中，计算机会在地图上显示一些数字从而帮助你确定哪里有地雷。例如，在下面这个有两颗地雷的 4x4 的地图（*表示地雷）：
*...
....
.*..
.... 
根据上面的地图，可以计算出应该提供给游戏者的数字如下所示：
*100
2210
1*10
1110 
每个数字表示了该方格周围到底有几个地雷，当然，一个方格周围最多的时候只会有八个。
输入
输入中将包括一系列的地图，每个地图的第一行有两个整数 n 和 m（0 <n,m <= 100），它们表示了地图的行数和列数。下面的 n 行每行都有 m 个字符，其中 "." 表示安全而 "*" 表示地雷。如果地图的 n 和 m 都为 0，则表示输入结束。
输出
针对每一个地图，首先输出一行：
Field #x:
其中 x 是当前地图的编号（从 1 开始）。下面的 n 行则将地图中的 "." 以数字表示，该数字表示该方格周围有多少颗地雷。
*/
#include<stdio.h>
int main(){
	int i,j,k,l,m,n,ji=0;
	char mine[102][102],result[100][100];
	scanf("%d %d",&m,&n);
	while(1){
		if(m==0&&n==0) break;
		else{
			for(i=0,j=0;j<=n+1;j++)
				mine[i][j]='.';
			for(i=m+1,j=0;j<=n+1;j++)
				mine[i][j]='.';
			for(j=0,i=0;i<=m+1;i++)
				mine[i][j]='.';
			for(j=n+1,i=0;i<=m+1;i++)
				mine[i][j]='.';
			for(i=1;i<=m;i++)
				scanf("%s",&mine[i][1]);
			for(i=1;i<=m;i++)
				for(j=1;j<=n;j++){
					if(mine[i][j]=='*')
						result[i][j]='*';
					else{
						result[i][j]='0';
						for(k=i-1;k<=i+1;k++)
							for(l=j-1;l<=j+1;l++)
								if(mine[k][l]=='*')
									result[i][j]++;
						}      
				}
				if(ji!=0)
					printf("\n");
				printf("Field #%d:\n",++ji);
				for(i=1;i<=m;i++){
					for(j=1;j<=n;j++)
						printf("%c",result[i][j]);
					printf("\n");
				}   
			}
			scanf("%d %d",&m,&n);
	}  
}
