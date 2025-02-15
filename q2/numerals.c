#include <stdio.h>

#define NOT_NUMERAL c != 'I' && c != 'V' && c != 'X' && c != 'L' && c != 'C' && c != 'D' && c != 'M'

int roman(char c) {
    if (c =='I') return 1;
    else if (c =='V') return 5;
    else if (c =='X') return 10;
    else if (c =='L') return 50;
    else if (c =='C') return 100;
    else if (c =='D') return 500;
    else if (c =='M') return 1000;
    else { return 0; }
}

int main() {
    unsigned long long int sum = 0;
    char c = getchar();
    char prev, after;
    for(; c != EOF && NOT_NUMERAL ; c = getchar());
    if(c==EOF) return 0;
    prev = c;
    after = getchar();
    if (after == EOF) {
        printf("%d\n", roman(prev));
        return 0;
    }
    while(after != EOF) {
        if(roman(after)==0) { //loop until we find another roman numeral
            after = getchar();
            continue;
        }

        if(roman(prev) < roman(after)) {
            sum -= roman(prev);
        }else if (roman(prev) >= roman(after)) {
            sum += roman(prev);
        }
        prev = after;
        after = getchar();
    }
    sum += roman(prev);
    printf("%lld\n", sum);
}