#include <stdio.h>

// 利用通项公式计算总操作步骤数
long stepNum(int y) {
    if (y == 1)
        return 1;
    else if (y > 1)
        return 2 * stepNum(y - 1) + 1;
    else
        return 0;
}

// 递归求解
void move(int x, char orig, char targ, char trans) {
    static long i = 0;
    if (x == 1) {
        printf("STEP %-2ld : %c -> %c\n", ++i, orig, targ);
    } else {
        move(x - 1, orig, trans, targ);
        printf("STEP %-2ld : %c -> %c\n", ++i, orig, targ);
        move(x - 1, trans, targ, orig);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    long steps = stepNum(n);
    if (steps == 0) {
        printf("ERROR!\n");
    } else {
        move(n, 'A', 'C', 'B');
        printf("\nTotal %ld step(s).\n", steps);
    }
    return 0;
}