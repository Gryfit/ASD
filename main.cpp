#include <iostream>

struct node {
    node* next;
    int  val;
};

void bucket_T(int*T,int size){
    int * Buckets = (int*) malloc (sizeof(int)*10*size);
    for(int i=0; i<10*size; i++){Buckets[i]=0;}
    for(int i=0; i<size; i++) {
        Buckets[T[i] * size]++;
    }
    int j=0;
    for(int i=0; i<10*size; i++){
        while(Buckets[i] !=0) {
            T[j++] =i/size;
            Buckets[i]--;
        }
    }
}
void bucket_L(node**L){
    int size=0; node*k=*L;
    while(k!=NULL){size++; k=k->next;}
    node ** Buckets = (node**) malloc (sizeof(node*)*10*size);
    for(int i=0; i<10*size; i++){Buckets[i]=new node;Buckets[i]->val=-1;Buckets[i]->next=NULL;}
    k=*L;
    while(k!=NULL){
        node* i=Buckets[k->val * size];
        node* tmp =Buckets[k->val * size]->next;
        i->next = k;
        k=k->next;
        i=i->next;
        i->next = tmp;
    }

    for(int i=0; i<10*size; i++){
        insertion_L(&(Buckets[i]->next)); //use any sorting algorithm
    }
    node* Out = new node;
    node*n =Out;
    for(int i=0; i<10*size; i++){
        if(Buckets[i]->next!=NULL) {
            n->next = Buckets[i]->next;
            while (n->next != NULL) { n = n->next; }
        }
    }
    *L=Out->next;
}

