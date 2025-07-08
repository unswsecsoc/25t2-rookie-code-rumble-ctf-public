#include <stdio.h>
#include <stdlib.h>

#define FLAG "RCR{kn0W_y0Ur_L1nK3D_L15Ts_w3lL}"

struct node {
    int id;
    struct node* next;
};

struct node *createNode(int num) {
    struct node* new = malloc(sizeof(struct node));
    new->id = num;
    new->next = NULL;

    return new;
}

int main(void) {
    struct node* head = createNode(15);
    struct node* cur = head;

    for (int i = 0; i < 5; i++) {
        int carriage = cur->id;
        carriage = (carriage * 173) % 213;

        cur->next = createNode(carriage);
        cur = cur->next;
    }

    cur = head;
    printf("Choo Choo! The train is pulling up to the station! Help the conductor connect the carriages up!\n");

    for (int i = 0; i < 5; i++) {
        int input;

        printf("Give me the id of carriage %d: ", i + 1);
        scanf("%d", &input);

        if (input != cur->id) {
            printf("These links don't match up :(\n");
            exit(1);
        }

        cur = cur->next;
    }

    printf("Choo choo!!! The train is ready to go!\n%s\n", FLAG);

    return 0;
}