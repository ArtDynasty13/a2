#include <stdio.h>

int char_to_int(char c) {
    return c - '0';
}

int d(int digit) {
    digit = digit*2;
    if(digit>=10) {
        return digit-9;
    } else {
        return digit;
    }
}

void check(int sum, int last) {
    if(((sum*9)%10)==last) { 
        printf("Valid\n"); 
    } else {
        printf("Invalid\n");
    }
}

int main() {

    int i = char_to_int(getchar());
    unsigned long long int j = 0;

    unsigned long long int sum_even = d(i); //assume that there are an even amount of numbers -> we need to double the first number
    unsigned long long int sum_odd = i; //assume that there are an odd amount of numbers -> we do not double the first number

    i = char_to_int(getchar());
    int last = 0;

    while(i != EOF && i>=0 && i <=9) {
        if(j%2==0) {
            sum_even += i;
            sum_odd += d(i);
        } else {
            sum_odd += i;
            sum_even += d(i);
        }
        last = i;
        i=char_to_int(getchar());
        j++;
    }
    if((j+1)%2==0) {
        check(sum_even-last, last);
    } else {
        check(sum_odd-last, last);
    }
    return 0;
}