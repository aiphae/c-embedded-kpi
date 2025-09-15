#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char title[100];
    double price;
    int pages;
    char language[50];
    double weight;
    int year;
} Book;

typedef struct Node {
    Book book;
    struct Node *next;
} Node;

Node *create_node(Book book) {
    Node *node = malloc(sizeof(Node));
    if (!node) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    node->book = book;
    node->next = NULL;
    return node;
}

void append_node(Node** head, Book b) {
    Node* new_node = create_node(b);
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void print_books(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *current = head;
    while (current != NULL) {
        Book b = current->book;
        printf("Title: %s\n", b.title);
        printf("Price: %f\n", b.price);
        printf("Pages: %d\n", b.pages);
        printf("Language: %s\n", b.language);
        printf("Weight: %f\n", b.weight);
        printf("Year: %d\n", b.year);
        printf("\n");
        current = current->next;
    }
}

void free_list(Node *head) {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* list = NULL;

    Book b1 = {"Harry Potter and the Philosopher's Stone", 250.0, 320, "Ukrainian", 0.45, 1997};
    Book b2 = {"Harry Potter and the Chamber of Secrets", 270.0, 352, "Ukrainian", 0.48, 1998};
    Book b3 = {"Harry Potter and the Prisoner of Azkaban", 300.0, 435, "Ukrainian", 0.55, 1999};
    Book b4 = {"Harry Potter and the Goblet of Fire", 350.0, 636, "Ukrainian", 0.75, 2000};

    append_node(&list, b1);
    append_node(&list, b2);
    append_node(&list, b3);
    append_node(&list, b4);

    printf("Series of Harry Potter books:\n");
    print_books(list);

    free_list(list);
}
