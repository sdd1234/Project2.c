#include <stdio.h>
#include <time.h>
int long factorial_iter(long m)
{
    long i; 
    long result = 1;
    for (i = 1; i <= m; i++)
    {
        result *= i;
        }
    return result;
    }
int  long factorial_rec(long n)
{
   if (n <= 1) 
        return 1;
     else{ 
        
       
          return n * factorial_rec(n - 1);
       
    }
 }
int main(int argc, char* argv[]) {
    clock_t start_iter, end_iter, start_rec, end_rec;
    long result_iter, result_rec;
     
    start_iter = clock();
    result_iter = factorial_iter(20);
    end_iter = clock();

    start_rec = clock();
    result_rec = factorial_rec(20);
    start_rec = clock();
    
    
   printf("걸린시간 %f", (float)(end_iter - start_iter) / CLOCKS_PER_SEC);
   printf("걸린시간 %f", (float)(end_rec - start_rec) / CLOCKS_PER_SEC);
   printf("%ld",result_iter);
   printf("%ld", result_rec);
       return 0;
}