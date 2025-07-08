#include <stdio.h>
#include <stdlib.h>

void *original;


void win() {
    system("/bin/sh");
}

void vuln() {
    char buf[30];
    original = __builtin_return_address(0);
    puts("We have installed some protective measures ensuring that you do not break our therapists");

    puts("How would you like to feel?");
    fwrite(">> ", 3, 1, stdout);

    read(0, buf, 0x50);

    puts("You will now feel ");
    puts(buf);
    
    void *new = __builtin_return_address(0);
    // printf("new is %p, old is %p", new, original);
    if (labs(new - original) > 0x30) {
        printf("Woah calm down there buddy, send this freak to the isolation unit.\n");
        exit(69);
    }
}

int main() {
    setvbuf(stdout, 0, _IONBF, 0);
    
    puts("Welcome to our therapy app, where you tell yourself how you should feel.");
    puts("");
    vuln();
    return 0;
}