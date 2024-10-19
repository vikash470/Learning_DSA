#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int info;
    struct node *link;
} *start = NULL; // Start is initialized to NULL

// Function to create a node and insert it at the end of the list
void creat(int num) {
    struct node *Temp, *ptr;
    
    // Allocate memory for the new node
    Temp = (struct node *)malloc(sizeof(struct node));
    Temp->info = num;
    Temp->link = NULL;
    
    // If the list is empty, make the new node the start node
    if (start == NULL) {   // Corrected: using '==' for comparison
        start = Temp;
    } else {
        // Traverse to the end of the list
        ptr = start;
        while (ptr->link != NULL) {   // Corrected: use 'NULL' instead of '0'
            ptr = ptr->link;
        }
        // Link the new node to the last node
        ptr->link = Temp;
    }
}

int main() {
    // Creating nodes with values
    creat(10);
    creat(20);
    creat(30);
    
    // Display the linked list
    struct node *ptr = start;
    while (ptr != NULL) {
        printf("%d -> ", ptr->info);
        ptr = ptr->link;
    }
    printf("NULL\n");
    
    return 0;
}