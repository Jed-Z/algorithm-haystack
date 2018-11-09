/* *************************
* FileName: HanoiTower.c
* Author: Jed Zhang
* Site: https://www.jedbit.com
* Date: 2017.10.31
* Description: 汉诺塔问题的简单递归实现。
**************************/
#include <stdio.h>
void move(int x, char orig, char targ, char trans);
long stepNum(int y);
int main(void)
{
	int n, steps;
	scanf("%d", &n);
	steps = stepNum(n);
	if(steps == 0) printf("ERROR!");
	//开始输出步骤
	move(n, 'A', 'C', 'B');
	printf("\nTotal %ld step(s)!\n\n", stepNum(n));
	return 0;
}

//操作步骤数量（递归）
long stepNum(int y)
{
	if(y == 1)
		return 1;
	else if(y >1)
		return 2*stepNum(y-1) + 1;
	else return 0;
}

void move(int x, char orig, char targ, char trans)
{
	static long i = 0;
	if(1 == x) {
		printf("STEP %-2d : %c -> %c\n", ++i, orig, targ);
	} else {
		move(x-1, orig, trans, targ);
		printf("STEP %-2d : %c -> %c\n", ++i, orig, targ);
		move(x-1, trans, targ, orig);
	}
}
