#include <stdio.h>
#include <time.h>

long long factorial_iter(int n)
{
    long long i;
    long long result = 1;
    for (i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}
long long factorial_rec(int n)
{
    long long k = 1;
    if (n == 1)
        return 1;
    else
        return n * factorial_rec(n - 1);

}

int main(void) {
    clock_t start, stop;
    double cai;
    start = clock();
    long long result_iter = factorial_iter(20);
    printf("%lld\n", result_iter);
    stop = clock();
    cai = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("반복 %f", cai);

    start = clock();
    long long result_rec = factorial_rec(20);
    printf("%lld\n", result_rec);
    stop = clock();
    cai = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("순환 %f", cai);
    return 0;
}