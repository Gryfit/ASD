#include <iostream>

struct node {
    node* next;
    int  val;
};

void insertion_T(int* T, int size){ //for tables
    for(int i=1; i<size; i++){
        int k=i;
        for(int j=i-1; j>=0;j--){
            if(T[k]<T[j]){
                std::swap(T[k],T[j]);
            }
            k=j;
        }
    }
    return;
}
void insertion_L(node**L){ //for lists
    node *sorted = NULL;
    node *current = *L;
    while (current) {
        node *next = current->next;
        node* current2;
        if (!sorted || (sorted)->val >= current->val) {
            current->next = sorted;
            sorted = current;
        }else {
            current2 = sorted;
            while (current2->next!=NULL && current2->next->val < current->val) {
                current2 = current2->next;
            }
            current->next = current2->next;
            current2->next = current;
        }
        current = next;
    }
    *L = sorted;
}