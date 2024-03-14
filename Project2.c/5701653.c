#include <stdio.h>
#include <time.h>

int main(void) {
    int i = 0;
    int j = 0;
    int sum = 0;
    clock_t start, stop; //clock 함수 시작과 끝을 start stop로 지정
    double d;           //실수값이 나오기때문에 double로 생성
    start = clock();        //측정시작

    for (i = 2; i < 100; i++)    //중첩 for문  2부터 시작해서 99까지 2부터 99까지의 숫자로 나누어보고 나머지가 0이면  break 로 for문을 빠져나옴
    {
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
                break;
        }


        if (i == j) {          //빠져나왓을때 나머지가 0인 숫자가 자기자신이면 모두 sum에 값을 더해서 저장한다
            sum += i;

        }
    }
    stop = clock();                //측정을 종료 
    d = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("100까지의 소수의합은%d입니다", sum);
    printf("측정시간은 %f초이다", d);                                        //소수의 합과 측정시간을 도출
    return 0;
}

// 결과값으로 0초가 나오는데 이것의 이유는 너무적은 숫자로 계산을해서 값이나오지 않는것이다  
// 10000까지의 소수의 합의 결과를 도출했을때에는 결과값이 나오게 된다 