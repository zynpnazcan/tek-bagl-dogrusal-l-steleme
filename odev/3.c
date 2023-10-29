#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


// ��renci bilgilerini i�eren struct
struct Student {
    int studentNumber;
    char name[50];
    int age;
};

// Tek ba�l� liste d���m�
struct Node {
    struct Student data;
    struct Node* next;
};

// Yeni bir d���m olu�turma
struct Node* createNode(struct Student student) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = student;
    newNode->next = NULL;
    return newNode;
}

// Listeye eleman ekleme
void insertNode(struct Node** head, struct Student student) {
    struct Node* newNode = createNode(student);
    newNode->next = *head;
    *head = newNode;
}

// Listeyi dola�an ve bilgileri ekrana yazan fonksiyon
void traverseAndPrint(struct Node* head) {
    struct Node* current = head;
    int count = 0;

    while (current != NULL) {
        struct Student student = current->data;
        printf("Ogrenci No: %d, Isim: %s, Yas: %d\n", student.studentNumber, student.name, student.age);
        count++;
        current = current->next;
    }

    printf("Toplam ogrenci sayisi: %d\n", count);
}

int main() {
    struct Node* head = NULL;
    
    // ��renci bilgileri ile liste olu�turma
    struct Student student1 = {1, "Suna", 20};
    struct Student student2 = {2, "Zeynep", 22};
    struct Student student3 = {3, "Merve", 21};

    // Liste ba��na ��renci ekleme
    insertNode(&head, student1);
    insertNode(&head, student2);
    insertNode(&head, student3);

    // Listeyi dola�an ve bilgileri ekrana yazan fonksiyonu �a��rma
    traverseAndPrint(head);

    return 0;
}


