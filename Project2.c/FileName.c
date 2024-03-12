#include <stdio.h>

int main(void) {
	int i = 0;
	int j = 2;
	int k = 3;
	printf("1에서 100까지 소수의 합은? 1제외");
	
	for (i = 2; i <= 100; i++)
	    if (i % j == 0)
			return 0;
	    else if (i % k == 0);
	        return 0;
		else printf("%4d", i);
	     
    return 0;
}