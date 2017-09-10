#include <iostream>

struct node {
    node* next;
    int  val;
};
void selection_T(int* T, int size){
    for(int j=0; j<size-1;j++){
        int min_index = j;
        for(int i=j+1;i<size;i++){
            if(T[i]<T[min_index]){min_index=i;}
        }
        std::swap(T[min_index],T[j]);
    }
}
node * max_L (node**b){
    node* p = new node;
    p->next =*b;
    p->val=-1;
    int m = p->next->val;
    node* ptr = p;
    while(p->next != NULL){
        if(p->next->val > m){m = p->next->val; ptr=p;}
        p=p->next;
    }
    if(ptr->val ==-1){
        *b=ptr->next->next;
        return ptr->next;
    }else{
        node * tmp = ptr->next;
        ptr->next = ptr->next->next;
        return tmp;
    }
}
void selection_L(node**L){
    node *Sorted = NULL;
    while (*L != NULL) {
        node *M = max_L(L);
        M->next = Sorted;
        Sorted = M;
    }
    *L= Sorted;
}