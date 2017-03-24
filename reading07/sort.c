#include <stdlib.h>
#include <stdio.h>

/* Constants */

#define MAX_NUMBERS (1<<10)		// bitwise shift left to make 0x400

/* Functions */

size_t read_numbers(FILE *stream, int numbers[], size_t n) {
    size_t i = 0;

    while (i < n && scanf("%d", &numbers[i]) != EOF) {
        i++;
    }

    return i;
}

int sum_numbers(int numbers[], size_t n) {
    int total = 0;
    for (size_t i = 0; i < n; i++) {
        total += numbers[i];
    }

    return total;
}

void sort_numbers(int *numbers, int n) {
    int i;
    int num;

    for (i = 1; i < n; i++) {
        num = numbers[i];
        int j = i - 1;
        while (j >= 0 && numbers[j] > num) {
            numbers[j+1] = numbers[j];
            j--;
        }
        numbers[j+1] = num;
    }

}

/* Main Execution */

int main(int argc, char *argv[]) {     // arv[] is an array of pointers
    int numbers[MAX_NUMBERS];          // which point to input args
    size_t nsize;

    nsize = read_numbers(stdin, numbers, MAX_NUMBERS);
    sort_numbers(numbers, nsize);

    size_t j;
    for (j = 0; j < nsize; j++) {

        if (j == (nsize-1)) {
            printf("%d", numbers[j]);
            break;
        }
        printf("%d ", numbers[j]); 

    }
    printf("\n");

    return EXIT_SUCCESS;
}

