/*
题目背景
    在BIT的网络教室里，有一位叫做大师的传奇的人物。大师卖萌卖得好，黑人黑得好，写代码更是一绝。她在轻松AC了题目之后还要故意重新交几次默默刷高自己的罚分使自己排名靠后以深藏功与名，但是由于大师压倒性的实力，她还是并列了网教的第一。在一个叫什么什么M的神秘组织里，大师的代号是07。
    大师的RP值一向很高，然而，由于最近她联合了YW大神在网教里黑掉了无辜的渣渣，大师的RP值骤减（黑人是要掉RP的哦~）。期末考试临近，大师想以一个高RP状态去参加考试（其实吧即使大师的RP为0也能拿满分），于是大师决定周五上午到理教201在陈老师的C语言课上收集RP。
   那么大师是怎样获取RP的呢？她有一个独特的技能——「嘤嘤」。美丽的大师坐到你身旁，用她那水汪汪的眼睛望着你，然后———— ”>.<嘤嘤~” 使你不忍心不分给她一些RP。
    现在已知陈老师的课堂里有N位无辜的同学/老师（不排除鹰哥被嘤嘤的可能性= =），每个人有一个固定的RP值rp[i]，大师会对Ta们使出嘤嘤技能。大师每对一个RP比自己低的人（例如李渣渣）使出嘤嘤，大师会获得1点RP值，每对一个RP值大于等于自己RP的人使出嘤嘤，大师会获得2点RP。（大师说：赚RP是多么不容易啊，大家捡到一卡通钱包什么的一定要还给失主会获得大量RP哒）。机智的大师当然会安排一个最佳的方案使得自己达到最高的RP。
大师收集完RP之后要去和渣渣玩儿猜拳。渣渣想知道大师最多能获得多少RP以估测自己获胜的几率。然而由于渣渣的IQ非常捉鸡，他找到了聪明的你，请你帮渣渣计算一下大师的RP能够达到的最大值。
PS:大师,YW大神和渣渣祝大家端午节快乐~
题目作者
 渣渣
输入
   第一行：一个数字N (0<N<=1000),代表大师准备嘤嘤的人数。
   第二行：一个数字R (0<=R<=10000)，代表大师的初始RP值。
   第三行：N个正整数，代表每个人的RP值(0<=rp[i]<=10000)。
输出
    大师能够达到的最高的RP
输入样例
    5
    100
    90 100 80 120 100
输出样例
    107
*/
#include<stdio.h>
#define N 1005
int rp[N];
int main(){
	int n,r,sign=0;
	scanf("%d%d",&n,&r);
	for(int i=0;i<n;i++)
		scanf("%d", &rp[i]);
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i;j++){
			if(rp[j]<rp[j+1]){
				int t=rp[j+1];
				rp[j+1]=rp[j];
				rp[j]=t;
			}
		}
	}
	for(int i=0;i<n-1;i++){
		if(rp[i]>=r&&rp[i+1]<=r)
			sign=i;
	}
	for(int i=sign;i>=0;i--){
		if(rp[i]>=r)
			r+=2;
		else
			r++;
	}
	r+=n-sign-1;
	printf("%d\n",r);
}
