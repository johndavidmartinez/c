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
void linecount(void);
void countblanktabnew(void);
void singleblank(void);
void digitcount(void);
void wordlengths(void);
int min(int a, int b);
int pow(int base, int n);
float to_celsius(float fahrenheit);
float to_fahrenheit(float celsius);

// Masterfile
// All functionality in functions.
// Main just calls one function to run the program
int main() {
}

int pow(int base, int n){
  int i, p;

  p = 1;
  for (i = 1; i <= n; ++i){
    p = p * base;
  }
  return p;
}

void wordlengths(void){
  int lng[20];
  //multiples of 5
  //int division of 5?
  for(int i = 0; i < 20; i++) {
    lng[i] = 0;
  }
  int c, d, wl;
  while((c=getchar())!=EOF){
    if (c != ' ' && c != '\n') {
      // we're in a word
      wl = 1;
      while((c=getchar())!=EOF && c!=' ' && c!='\n') {
        wl++;
      }
      // out of the word
      lng[min(wl, 19)-1]++;
      wl = 0;
    }
  }
  printf("Word lengths\n\n");
  for (int i = 0; i < 19; i++) {
    printf("%d : %d\n", i+1, lng[i]);
  }
  printf("20+ : %d\n", lng[19]);
}

int min(int a, int b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}

void digitcount(void){
  int ndigit[10];
  int c;

  for(int i=0;i<10;i++){
    ndigit[i]=0;
  }

  while((c=getchar())!=EOF){
    if(c>='0'&&c<='9'){
      ndigit[c-'0']++;
    }
  }
  //and print them but
  //dont wanna right now
}

void singleblank(void){
  int c;
  int d;
  
  while((c=getchar()!=EOF)){
    if(c==' '){
      while((d=getchar())==' ')
      putchar(c);
      putchar(d);
    }else{
      putchar(c);
    }
  }
}

void countblanktabnew(void){
  int c, bl, tb, nl;
  bl = tb = nl = 0;
  while((c=getchar()!=EOF)){
    if(c=='\n'){
      nl++;
    } else if (c=='\t'){
      tb++;
    } else if (c==' '){
      bl++;
    }
  }
  printf("bl: %d tb: %d nl: %d",
    bl, tb, nl);
}

void linecount(void) {
  int c, nl;

  nl = 0;
  while((c=getchar()!=EOF)){
    if(c=='\n'){
      nl++;
    }
  }
  printf("%d\n", nl);
}

void f_to_c_table(void) {
    float fahr, celsius;

    fahr = (float) LOWER;
    while (fahr <= UPPER) {
        celsius = to_celsius(fahr);
        printf("\%d\t%d\n", 
        fahr, 
        celsius);

        fahr = fahr + STEP;
    }
}

void f_to_c_table2(void) {
    float fahr, celsius;

    fahr = (float) LOWER;
    printf("  F    C\n");
    printf("-----------\n");
    while (fahr <= UPPER) {
        celsius = to_celsius(fahr);
        printf("%3.0f %6.1f\n", 
        fahr, 
        celsius);
        fahr = fahr + STEP;
    }
}

void c_to_f_table(void) {
    float fahr, celsius;

    celsius = -20;
    printf("   C     F\n");
    while (celsius <= UPPER) {
        fahr = to_fahrenheit(celsius);
        printf("%3.0f %6.1f\n", 
        celsius, fahr);
        celsius = celsius + STEP;
    }
}

void f_to_c_table_reverse(void) {
    int fahr, celsius;

    fahr = UPPER;
    while (fahr >= LOWER) {
        celsius = 5 * (fahr-32) / 9;
        printf("\%f\t%f\n", fahr, 
        celsius);
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
        printf("char: %c, val: %d\n", 
        c, val);
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

float to_celsius(float fahrenheit){
  return (5.0/9.0) * (fahrenheit - 32.0);
}
float to_fahrenheit(float celsius){
  return (9.0/5.0) * (celsius + 32.0);
}