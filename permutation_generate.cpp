#include <stdio.h>
#include <stdlib.h>
/*headers*/
void permu(int *, int[], int);
void swap(int *, int *);
void printout(int[], int);
void bsort(int[], int);
/*end headers*/

int t;  // global variable (too lazy to use another pointer)
int main(void) {
    scanf("%d", &t);
    int *data = (int *)malloc(t * sizeof(int));
    for (int i = 0; i < t; i++) {
        data[i] = i + 1;
    }

    permu(data, data, t);  // look at the function declaration

    free(data);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printout(int test[], int size) {
    printf("%d", test[0]);  // without space
    for (int i = 1; i < size; i++) {
        printf(" %d", test[i]);  // with space
    }
    putchar('\n');
}

void bsort(int test[], int size) {
    for (int pass = 1; pass < size; pass++) {
        for (int i = 0; i < size - pass; i++) {
            if (test[i] > test[i + 1]) {
                swap(&test[i], &test[i + 1]);
            }
        }
    }
}

void permu(int *origin, int test[], int size)  //"origin" is a pointer to the original data,
{
    // which is the array "data" in [main].
    if (1 == size) {
        printout(origin, t);
    } else {
        for (int i = 0; i < size; i++) {
            int temp[size];  // the array "temp" is used to [backup] the data before swapping
            for (int j = 0; j < size; j++) {
                temp[j] = test[j];
            }
            /*permutation*/
            swap(&test[i], &test[0]);
            bsort(test + 1, size - 1);          // dictionary sequence
            permu(origin, test + 1, size - 1);  // recursion
            /*end permutation*/
            for (int j = 0; j < size; j++) {  // restore the data to those before swapping
                test[j] = temp[j];
            }
        }
    }
}
