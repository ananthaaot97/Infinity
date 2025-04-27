#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char name[50], author[50];
    int available;
    struct Book* next;
};

struct Book* head = NULL;

struct Book* findBook(int id) {
    struct Book* b = head;
    while (b && b->id != id) b = b->next;
    return b;
}

void addBook() {
    struct Book* b = (struct Book*)malloc(sizeof(struct Book));
    printf("ID: "); scanf("%d", &b->id);
    printf("Name (one word): "); scanf("%s", b->name);
    printf("Author (one word): "); scanf("%s", b->author);
    printf("Available (1/0): "); scanf("%d", &b->available);
    b->next = head;
    head = b;
}

void updateBook() {
    int id;
    printf("Enter ID to update: "); scanf("%d", &id);
    struct Book* b = findBook(id);
    if (b) {
        printf("New Name (one word): "); scanf("%s", b->name);
        printf("New Author (one word): "); scanf("%s", b->author);
        printf("Available (1/0): "); scanf("%d", &b->available);
    } else {
        printf("Book not found.\n");
    }
}

void deleteBook() {
    int id;
    printf("Enter ID to delete: "); scanf("%d", &id);
    struct Book *b = head, *prev = NULL;
    while (b && b->id != id) { prev = b; b = b->next; }
    if (!b) printf("Book not found.\n");
    else {
        if (prev) prev->next = b->next;
        else head = b->next;
        free(b);
        printf("Book deleted.\n");
    }
}

void listBooks() {
    struct Book* b = head;
    if (!b) { printf("No books.\n"); return; }
    while (b) {
        printf("ID: %d, Name: %s, Author: %s, Available: %s\n",
            b->id, b->name, b->author, b->available ? "Yes" : "No");
        b = b->next;
    }
}

int main() {
    int ch;
    do {
        printf("\n1.Add 2.Update 3.Delete 4.List 0.Exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: addBook(); break;
            case 2: updateBook(); break;
            case 3: deleteBook(); break;
            case 4: listBooks(); break;
        }
    } while (ch != 0);
    return 0;
}
