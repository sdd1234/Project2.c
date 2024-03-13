#include <stdio.h>

int main(void) {
    int i = 0;
    int j = 0;
    int cou = 0;
    int sum = 0;

    for (i = 2; i < 100; i++)
        for (j = 2; j < i; j++)
            if (i % j == 0)
                cou++;
    if (cou == 2)
        sum += i;
      printf("100까지의 소수의 합은 %d 입니다 ", j);

    return 0;
}