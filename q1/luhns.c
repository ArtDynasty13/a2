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
    int c = getchar();
    if (!(c>= '0' && c <= '9')) { //seems to return valid if first char is not an actual num
        printf("Valid\n");
        return 0;
    }

    int i = char_to_int(c);
    int is_even = 1;

    unsigned long long int sum_even = d(i); //assume that there are an even amount of numbers -> we need to double the first number
    unsigned long long int sum_odd = i; //assume that there are an odd amount of numbers -> we do not double the first number

    i = char_to_int(getchar());
    int last = 0;

    while(i>=0 && i <=9) {
        if(is_even) {
            sum_even += i;
            sum_odd += d(i);
        } else {
            sum_odd += i;
            sum_even += d(i);
        }
        last = i;
        i=char_to_int(getchar());
        is_even = !is_even;
    }
    if((is_even)%2==0) {
        check(sum_even-last, last);
    } else {
        check(sum_odd-last, last);
    }
    return 0;
}