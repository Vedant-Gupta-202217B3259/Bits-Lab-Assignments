#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

void push();
void pop();
void display();

int main() {
    int choice, n;

    printf("\nEnter the size of STACK (MAX=%d): ", MAX);
    scanf("%d", &n);

    printf("\n\tSTACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH");
    printf("\n\t 2.POP");
    printf("\n\t 3.DISPLAY");
    printf("\n\t 4.EXIT");

    do {
        printf("\nEnter the Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\tEXIT POINT\n");
                break;
            default:
                printf("\n\tPlease Enter a Valid Choice (1/2/3/4)\n");
        }
    } while (choice != 4);

    return 0;
}

void push() {
    int x;
    if (top >= MAX - 1) {
        printf("\n\tSTACK is Overflow\n");
    } else {
        printf("Enter a value to be pushed: ");
        scanf("%d", &x);
        stack[++top] = x;
    }
}

void pop() {
    if (top < 0) {
        printf("\n\tSTACK is Underflow\n");
    } else {
        printf("\n\tThe popped element is %d", stack[top--]);
    }
}

void display() {
    if (top >= 0) {
        printf("\nThe elements in STACK\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
        printf("\nPress Next Choice");
    } else {
        printf("\nThe STACK is empty\n");
    }
}
