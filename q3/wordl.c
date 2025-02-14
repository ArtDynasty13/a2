#include <stdio.h>
#include <string.h>

#define ASCII_SIZE 128

const char *GREEN = "\x1b[32m";
const char *YELLOW = "\x1b[33m";
const char *WHITE = "\x1b[0m";
const char *current;

void setColour(const char *colour) {
    if (current == colour) return;
    printf("%s", colour);
    current = colour;
}

int main(int argc, char **argv) {
    current = WHITE;
    if (argc != 2) {
        fprintf(stderr, "Invalid number of command line arguments\n");
      return 0;
    }
    char *theWord = argv[1];  // Correct word
    char guess[12];

    int num_guesses = 0;

    while (num_guesses < 6) {
        printf("Enter guess: ");
        scanf("%s", guess);

        if (strlen(guess) != strlen(theWord)) {
            fprintf(stderr, "Invalid guess, guess length must match word length\n");
            return 0;
        }

        int letter_count[ASCII_SIZE] = {0};  // Frequency of letters in theWord
        int green_count[ASCII_SIZE] = {0};   // Count of green letters
        int yellow_count[ASCII_SIZE] = {0};  // Count of yellow letters

        for (int i = 0; theWord[i] != '\0'; i++) {
            letter_count[(int)theWord[i]]++;
        }

        for (int i = 0; guess[i] != '\0'; i++) {
            if (guess[i] == theWord[i]) {
                green_count[(int)guess[i]]++;
            }
        }

        int correct_count = 0;
        for (int i = 0; guess[i] != '\0'; i++) {
            if (guess[i] == theWord[i]) {
                setColour(GREEN);
                printf("%c", guess[i]);
                ++correct_count;
            } else if (letter_count[(int)guess[i]] > green_count[(int)guess[i]] + yellow_count[(int)guess[i]]) {
                setColour(YELLOW);
                printf("%c", guess[i]);
                yellow_count[(int)guess[i]]++;
            } else {
                setColour(WHITE);
                printf("%c", guess[i]);
            }
        }
        ++num_guesses; 
        printf("\n");
        setColour(WHITE);
        if(correct_count == strlen(theWord)) {
            printf("Finished in %d guesses\n", num_guesses);
            return 1;
        }

    }
    printf("Failed to guess the word: %s\n", theWord); 
}
