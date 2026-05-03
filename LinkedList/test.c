#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

int main(int argc , char *argv[]){
    int *list = NULL;
    for(int i = 1 ; i < argc ; i++){
        Node *temp = malloc(sizeof(Node));
        if(temp == NULL){
            printf("Malloc Failed at : %d" , i);
            free(temp);
            return -1;
        }
        temp->data = atoi(argv[i]);
        temp->next = list;
        list = temp;
    }

    Node *current = list;
    while(current != NULL){
        printf("%d -> " , current->data);
        current = current->next;
    }
    printf("NULL\n");

    

}