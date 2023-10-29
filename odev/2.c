#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Tek ba�l� liste d���m�
struct Node {
    int data;
    struct Node* next;
};

// Yeni bir d���m olu�turma
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

// Liste elemanlar�n� b�y�kten k����e s�ralama
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

    // Rastgele say�lar� liste i�ine ekleme
    for (i = 0; i < 100; i++) {
        insertNode(&head, rand() % 1000);
    }

    // Liste elemanlar�n� b�y�kten k����e s�ralama
    sortList(head);

    // S�ralanm�� liste elemanlar�n� ekrana basma
    printf("S�ralanm�� Liste:\n");
    printList(head);

    return 0;
}


	
