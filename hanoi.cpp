#include <cstdio>

// get the fewest number of steps
long stepNum(int y) {
    if (y < 1)
        return 0;
    else if (y == 1)
        return 1;
    else
        return 2 * stepNum(y - 1) + 1;
}

// solve hanoi recursively
void move(int x, char orig, char targ, char trans) {
    static long step = 0;
    if (x == 1) {
        printf("STEP %-2ld : %c -> %c\n", ++step, orig, targ);
    } else {
        move(x - 1, orig, trans, targ);
        printf("STEP %-2ld : %c -> %c\n", ++step, orig, targ);
        move(x - 1, trans, targ, orig);
    }
}

int main() {
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