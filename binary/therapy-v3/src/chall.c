#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>





int size() {
    char str[5] = {0};
    read(0, str, sizeof(str)-1);
    
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    str[strcspn(str, "\n")] = '\0';


    int len = strlen(str);
    int status = 1;

    if (len >= 1 && (str[len - 1] < '0' || str[len - 1] > '9')) {
        status = 0;
    }
    if (len >= 2) {
        if (str[len - 2] < '0' || str[len - 2] > '8') {
            status = 0;
        }
        if (str[len - 1] != '0' && str[len - 2] == '8') {
            status = 0;
        }
    }
    if (len >= 3 && (str[len - 3] > '0' && str[len - 3] <= '9')) {
        status = 0;
    }
    if (len >= 4 && (str[len - 4] > '0' && str[len - 4] <= '9')) {
        status = 0;
    }

    int ret = strtol(str, 0, 0);
    if (ret <= 0) {
        status = 0;
    }
    if (status == 0) {
        puts("nah get lost, dont want no overflows");
        exit(69);
    }
    return ret;
}




int main(void) {
    
    char buf[80];
    char name[24];
    
    setvbuf(stdout, 0, _IONBF, 0);

    puts("Welcome to our therapy app, where you tell yourself how you should feel.");

    puts("but before that let me get to know you! What is your name?");

    fwrite(">> ", 3, 1, stdout);
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    
    puts("How cute! That's my dogs name.");
    sleep(2);
    printf("\033[31mHe died!\033[0m\n");
    puts("");


    printf("Let's get started %s, please enter the length of your feelings (max 80):\n", name);
    fwrite(">> ", 3, 1, stdout);

    read(0, buf, size());

    return 0;
}
