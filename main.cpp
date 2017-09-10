#include <iostream>

/*struct node {
    node* next;
    int  val;
};
*/
//table only
void heapify(int*TABLE,int size, int i){
    int l= 2*i+1,r=2*i+2,max;
    if(l<=size && TABLE[l]>TABLE[i]){
        max=l;
    }else{max=i;}
    if(r<=size && TABLE[r]>TABLE[max]){
        max=r;
    }
    if(max != i){
        std::swap(TABLE[i], TABLE[max]);
        heapify(TABLE,size,max);
    }
}
void make_heap(int*TABLE,int size){
    for(int i=size/2;i>=0;i--){
        heapify(TABLE,size-1,i);
    }
}
void heap_T(int*T,int size){
    make_heap(T,size-1);
    for(int i=size-1;i>0;i--){
        std::swap(T[0],T[i]);
        size--;
        heapify(T,size-1,0);
    }
}
