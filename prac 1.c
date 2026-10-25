#include <stdio.h>

#define MAX 100

int arr[MAX];
int n = 0;

void display() {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int value, int pos) {
    if (n == MAX) {
        printf("Array is full!\n");
        return;
    }
    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    n++;
    printf("%d inserted at position %d.\n", value, pos);
}

void delete_at(int pos) {
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }
    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return;
    }
    int removed = arr[pos];

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    printf("%d deleted from position %d.\n", removed, pos);
}

void search(int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("%d found at position %d.\n", key, i);
            return;
        }
    }
    printf("%d not found in the array.\n", key);
}

int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- ARRAY MENU ---\n");
        printf("1. Insert\n2. Delete\n3. Traverse (Display)\n4. Search\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position (0 to %d): ", n);
                scanf("%d", &pos);
                insert(value, pos);
                break;
            case 2:
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);
                delete_at(pos);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 5:
                printf("Bye!\n");
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
}
