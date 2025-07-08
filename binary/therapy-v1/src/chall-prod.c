#include <stdio.h>
#include <stdlib.h>


int main(void) {  
    char buf[50];

    puts("Welcome to our therapy app, where you tell yourself how you should feel.");
    puts("");
    
    
    char flag[40] = "RCR{p33kab00_f0rm47_s33_thr0ugh}";

    puts("How would you like to feel?");
    fwrite(">> ", 3, 1, stdout);

    fgets(buf, sizeof(buf), stdin);

    puts("You will now feel ");
    printf(buf);
    puts("");

    return 0;
}

