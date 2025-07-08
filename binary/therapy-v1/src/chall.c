#include <stdio.h>
#include <stdlib.h>


int main(void) {  
    char buf[50];

    puts("Welcome to our therapy app, where you tell yourself how you should feel.");
    puts("");
    
    
    char flag[40] = "RCR{FAKE_FLAG_FOR_TESTING}";

    puts("How would you like to feel?");
    fwrite(">> ", 3, 1, stdout);

    fgets(buf, sizeof(buf), stdin);

    puts("You will now feel ");
    printf(buf);
    puts("");

    return 0;
}

