#include <iostream>

struct node {
    node* next;
    int  val;
};
void Scal_T(int*T,int b,int p,int e){
    int *tab_pom = new int[(e-b)];
    int i=b, j = p+1, k=0;
    while (i<= p && j<=e){
        if (T[j] < T[i]) {
            tab_pom[k++] = T[j++];
        }else{
            tab_pom[k++] = T[i++];
        }
    }
    while (i <= p) {
        tab_pom[k++] = T[i++];
    }
    while (j <= e){
        tab_pom[k++] = T[j++];
    }
    for (i = 0; i <= e-b; i++)
        T[b+i] = tab_pom[i];
}
void M_sort_T(int *T,int b,int e){
    if(b<e) {
        int p = (b + e) / 2;
        M_sort_T(T,b,p);
        M_sort_T(T,p+1,e);
        Scal_T(T,b,p,e);
    }
}
void merge_T(int*T,int size){
    M_sort_T(T,0,size-1);
}

void split_L(node**ONE,node**TWO,node**L){
    node*i = *ONE;
    node*j = *TWO;
    node*k = *L;
    bool X = true;
    while(k!= NULL){
        if(X){
            i->next = k;
            k=k->next;
            i=i->next;
            i->next = NULL;
        }else{
            j->next = k;
            k=k->next;
            j=j->next;
            j->next = NULL;
        }
        X = (!X);
    }
    node *tmp = *ONE;
    (*ONE)=(*ONE)->next;
    delete(tmp);
    tmp = *TWO;
    (*TWO)=(*TWO)->next;
    delete(tmp);
    *L=new node;
}
void M_L(node**ONE,node**TWO,node**L){
    node*i = *ONE;
    node*j = *TWO;
    node*k = *L;
    while(i!=NULL && j!=NULL){
        if(i->val <j->val){
            k->next = i;
            i=i->next;
        }else{
            k->next = j;
            j=j->next;
        }
        k=k->next;
        k->next =NULL;
    }
    while(i!=NULL){
        k->next = i;
        i=i->next;
        k=k->next;
        k->next =NULL;
    }
    while(j!=NULL){
        k->next = j;
        j=j->next;
        k=k->next;
        k->next =NULL;
    }
    node *tmp = *L;
    (*L)=(*L)->next;
    delete(tmp);
}
void merge_L(node **L){
    node *ONE = new node;
    node *TWO = new node;
    if(*L &&(*L)->next){
        split_L(&ONE,&TWO,L);
        merge_L(&ONE);
        merge_L(&TWO);
        M_L(&ONE,&TWO,L);
    }
}
