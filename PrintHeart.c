/* *************************
* FileName: PrintHeart.c
* Author: Jed Zhang
* Site: https://www.jedbit.com
* Date: 2017.9.29
* Description: 
**************************/
#include <stdio.h>
int main()
{
	double y;
	for (y = 1.5; y > -1.5; y -= 0.1) {
		double x;
		for (x = -1.5f; x < 1.5f; x += 0.05f) {
			double a = x * x + y * y - 1;
			putchar(a * a * a - x * x * y * y * y <= 0.0f ? '*' : ' ');
		}
		putchar('\n');
	}
	//system("pause");
}
