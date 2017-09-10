#include <iostream>

struct node {
    node* next;
    int  val;
};
void bubble_T(int* T, int size){
    bool changed = true;
    while(changed) {
        changed = false;
        for (int i = 0; i < size; i++) {

            if (T[i] > T[i + 1]) {
                std::swap(T[i], T[i + 1]);
                changed = true;
            }
        }
    }
}
void swap_L (node* ptr){
    node* one = ptr->next;
    node * two = (ptr)->next->next;
    node* tree = (ptr)->next->next->next;
    one->next = tree;
    two->next = one;
    ptr->next=two;
}
void bubble_L(node**L){
    bool changed = true;
    node* BEG =new node;
    BEG ->next = *L;
    while(changed) {
        changed = false;
        if (BEG->next->val > BEG->next->next->val) {
            swap_L(BEG);
            changed = true;
        }
        node * ptr = BEG->next;
        while(ptr->next->next != NULL){
            if (ptr->next->val > ptr->next->next->val) {
                swap_L(ptr);
                changed = true;
            }
            ptr=ptr->next;
        }
    }
    *L =BEG->next;
}