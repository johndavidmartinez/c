#include <stdio.h>

/* 
  Welcome to the master file.
  This file contians every function and exercise from k&r.
  It is nice when learning a language to have all your examples in one place.
  So this file is intentionally monolithic.
*/

#define LOWER 0
#define UPPER 300
#define STEP 20

void f_to_c_table(void);
void f_to_c_table2(void);
void c_to_f_table(void);
void f_to_c_table_reverse(void);
void copy_file(void);
void boolean_value_char_print(void);
void printEOF(void);
void countchar(void);

// Masterfile
// All functionality in functions.
// Main just calls one function to run the program
int main() {
    countchar();
}

void f_to_c_table(void) {
    int fahr, celsius;

    fahr = LOWER;
    while (fahr <= UPPER) {
        celsius = 5 * (fahr-32) / 9;
        printf("\%d\t%d\n", fahr, celsius);
        fahr = fahr + STEP;
    }
}

void f_to_c_table2(void) {
    float fahr, celsius;

    fahr = LOWER;
    printf("  F    C\n");
    printf("-----------\n");
    while (fahr <= UPPER) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + STEP;
    }
}

void c_to_f_table(void) {
    float fahr, celsius;

    celsius = -20;
    printf("   C     F\n");
    while (celsius <= UPPER) {
        fahr = (celsius + 32) * (9.0/5.0);
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + STEP;
    }
}

void f_to_c_table_reverse(void) {
    int fahr, celsius;

    fahr = UPPER;
    while (fahr >= LOWER) {
        celsius = 5 * (fahr-32) / 9;
        printf("\%d\t%d\n", fahr, celsius);
        fahr = fahr - STEP;
    }
}

void copy_file(void) {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}

void boolean_value_char_print(void) {
    int c;
    int val;

    while (1) {
        c = getchar();
        val = c != EOF;
        printf("char: %c, val: %d\n", c, val);
        if (c == EOF) {
            return;
        }
    }
}

void printEOF(void) {
    printf("%d", EOF);
}

void countchar(void) {
    long nc;

    nc = 0;
    while (getchar() != EOF) {
        ++nc;
    }
    printf("%ld\n", nc);
}