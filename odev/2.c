#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Tek baðlý liste düðümü
struct Node {
    int data;
    struct Node* next;
};

// Yeni bir düðüm oluþturma
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Listeye eleman ekleme
void insertNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Liste elemanlarýný büyükten küçüðe sýralama
void sortList(struct Node* head) {
    struct Node *current, *index;
    int temp;

    if (head == NULL) {
        return;
    } else {
        for (current = head; current->next != NULL; current = current->next) {
            for (index = current->next; index != NULL; index = index->next) {
                if (current->data < index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
            }
        }
    }
}

// Listeyi ekrana basma
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int i;

    // Rastgele sayýlarý liste içine ekleme
    for (i = 0; i < 100; i++) {
        insertNode(&head, rand() % 1000);
    }

    // Liste elemanlarýný büyükten küçüðe sýralama
    sortList(head);

    // Sýralanmýþ liste elemanlarýný ekrana basma
    printf("Sýralanmýþ Liste:\n");
    printList(head);

    return 0;
}


	
