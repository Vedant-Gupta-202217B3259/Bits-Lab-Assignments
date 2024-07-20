#include <stdio.h>
#include <stdlib.h> // For exit()

#define MAX 10 // Define the maximum size of the list

// Function prototypes
void create();
void insert();
void deletion();
void search();
void display();

int b[MAX], n = 0, p, e, i, pos;

int main() {
    int ch;
    char g = 'y';
    do {
        printf("\nMain Menu");
        printf("\n 1. Create");
        printf("\n 2. Delete");
        printf("\n 3. Search");
        printf("\n 4. Insert");
        printf("\n 5. Display");
        printf("\n 6. Exit");
        printf("\n Enter your Choice: ");
        scanf("%d", &ch);

        // Call appropriate function based on user choice
        switch(ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0); // Exit the program
                break;
            default:
                printf("\nEnter the correct choice.");
        }
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &g); // Note the space before %c to skip whitespace characters
    } while(g == 'y' || g == 'Y');

    return 0;
}

void create() {
    printf("\nEnter the number of nodes (<= %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("\nCannot create more than %d elements.\n", MAX);
        n = MAX;
    }

    // Input elements
    for(i = 0; i < n; i++) {
        printf("\nEnter the Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    printf("\nEnter the position you want to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("\nInvalid Position.\n");
    } else {
        for(i = pos; i < n - 1; i++) {
            b[i] = b[i + 1];
        }
        n--;

        printf("\nThe Elements after deletion:\n");
        display();
    }
}

void search() {
    printf("\nEnter the Element to be searched: ");
    scanf("%d", &e);

    for(i = 0; i < n; i++) {
        if(b[i] == e) {
            printf("Value is at position %d.\n", i);
            return;
        }
    }
    printf("Value %d is not in the list.\n", e);
}

void insert() {
    printf("\nEnter the position where you need to insert (0 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 0 || pos > n || n >= MAX) {
        printf("\nInvalid Position or List is Full.\n");
    } else {
        // Shift elements to the right
        for(i = n; i > pos; i--) {
            b[i] = b[i - 1];
        }
        printf("\nEnter the element to insert: ");
        scanf("%d", &p);
        b[pos] = p;
        n++;

        printf("\nThe list after insertion:\n");
        display();
    }
}

void display() {
    printf("\nThe Elements of the list are:");
    for(i = 0; i < n; i++) {
        printf("\n%d", b[i]);
    }
    printf("\n");
}
