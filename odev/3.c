#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


// Öğrenci bilgilerini içeren struct
struct Student {
    int studentNumber;
    char name[50];
    int age;
};

// Tek bağlı liste düğümü
struct Node {
    struct Student data;
    struct Node* next;
};

// Yeni bir düğüm oluşturma
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

// Listeyi dolaşan ve bilgileri ekrana yazan fonksiyon
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
    
    // Öğrenci bilgileri ile liste oluşturma
    struct Student student1 = {1, "Suna", 20};
    struct Student student2 = {2, "Zeynep", 22};
    struct Student student3 = {3, "Merve", 21};

    // Liste başına öğrenci ekleme
    insertNode(&head, student1);
    insertNode(&head, student2);
    insertNode(&head, student3);

    // Listeyi dolaşan ve bilgileri ekrana yazan fonksiyonu çağırma
    traverseAndPrint(head);

    return 0;
}


