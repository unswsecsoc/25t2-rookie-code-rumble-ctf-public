#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/random.h>
#include <sys/ptrace.h>

#define RNG_MULTIPLIER 6364136223846793005UL

uint64_t rngState;

void rngInit() {
    uint8_t rngBuf[8];
    getrandom(&rngBuf, sizeof(rngBuf), 0);

    for (int i = 0; i < sizeof(rngBuf); i++) {
        rngState |= (uint64_t)rngBuf[i] << (i * 8);
    }
}

void rngUpdate() {
    rngState = rngState * RNG_MULTIPLIER + 3;
}

uint64_t rngGet() {
    rngUpdate();
    return rngState;
}

int main() {
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1) {
        printf("Ptrace detected. Exiting.");
        exit(1);
    }

    rngInit();

    printf("Here's a number: %lu\n\n", rngState);

    printf("I'm thinking of 5 secret numbers, I bet you can't guess them all!\n");
    printf("Enter my secret numbers: ");
    for (int i = 0; i < 5; i++) {
        uint64_t guess;
        if (scanf("%lu", &guess) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        if (guess != rngGet()) {
            printf("Incorrect!\n");
            return 0;
        }
    }

    printf("RCR{w0w_you_re_v3ry_lucky}\n");

    return 0;
}
