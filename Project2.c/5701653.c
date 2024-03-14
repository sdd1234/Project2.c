#include <stdio.h>
#include <time.h>

int main(void) {
    int i = 0;
    int j = 0;
    int sum = 0;

    for (i = 2; i < 100; i++)
    {
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
                break;
        }


        if (i == j) {
            sum += i;
          
        }
    }

    printf("100까지의 소수의합은%d입니다", sum);
    return 0;
}