#include <stdio.h>

#define MAX_TERMS 101

struct term {
    float coef;
    int expon;
};

struct term terms[MAX_TERMS] = {
    {4.0, 3}, {3.0, 2}, {2.0, 1}, {1.0, 0}, // A
    {3.0, 2}, {2.0, 2}, {8.0, 0}, // B
    {7.0, 6}, {5.0, 3}, {9.0, 2}, {1.0, 0}, // C
    {5.0, 3}, {2.0, 2}, {1.0, 1}, {10.0, 0} // D
};

int avail = 16;

void print_poly(int start, int end);
void poly_multiply(int As, int Ae, int Bs, int Be, int* Cs, int* Ce);

int main() {
    int Cs1, Ce1, Cs2, Ce2;

    printf("\nA=");
    print_poly(0, 3);
    printf("\nB=");
    print_poly(4, 6);

    poly_multiply(0, 3, 4, 6, &Cs1, &Ce1);
    printf("\nA*B=");
    print_poly(Cs1, Ce1);

    printf("\nC=");
    print_poly(7, 10);

    printf("\nD=");
    print_poly(11, 14);

    poly_multiply(7, 10, 11, 14, &Cs2, &Ce2);
    printf("\nC*D=");
    print_poly(Cs2, Ce2);

    return 0;
}

void poly_multiply(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) {
    int i, j, k;
    float c[MAX_TERMS] = { 0 };

    for (i = As; i <= Ae; i++) {
        for (j = Bs; j <= Be; j++) {
            k = terms[i].expon + terms[j].expon;
            c[k] += terms[i].coef * terms[j].coef;
        }
    }

    *Cs = avail;
    for (k = MAX_TERMS - 1; k >= 0; k--) {
        if (c[k] != 0) {
            terms[avail].coef = c[k];
            terms[avail].expon = k;
            avail++;
        }
    }

    *Ce = avail - 1;
}

void print_poly(int start, int end) {
    int i;

    for (i = start; i < end; i++) {
        printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
    }

    printf("%3.1fx^%d\n", terms[end].coef, terms[end].expon);
}
