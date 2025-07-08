#include <stdio.h>
#include <stdint.h>

char *flag = "NAH{try_harder}";

int main() {
    unsigned char measurements[] = "R" "\xf0" "C" "\xf0" "R" "\xf0" "{" "\xf0" "s" "\xf0" "t" "\xf0" "r" "\xf0" "i" "\xf0" "n" "\xf0" "g" "\xf0" "_" "\xf0" "t" "\xf0" "h" "\xf0" "e" "\xf0" "o" "\xf0" "r" "\xf0" "y" "\xf0" "_" "\xf0" "i" "\xf0" "s" "\xf0" "n" "\xf0" "t" "\xf0" "_" "\xf0" "s" "\xf0" "o" "\xf0" "_" "\xf0" "h" "\xf0" "a" "\xf0" "r" "\xf0" "d" "\xf0" "_" "\xf0" "a" "\xf0" "f" "\xf0" "t" "\xf0" "e" "\xf0" "r" "\xf0" "_" "\xf0" "a" "\xf0" "l" "\xf0" "l" "\xf0" "}";

    char *input = NULL;
    size_t size = 0;
    printf("Enter something or whatever: ");
    getline(&input, &size, stdin);

    uint64_t val = 0;
    for (unsigned char *c = measurements; *c; c++) {
        val += (*c) * (val + 1);
    }
    for (char *c = input; *c; c++) {
        val += (*c) * (val + 1);
    }

    printf("The solution to the universe is %lu\n", val);
}