#include <iostream>

/*struct node {
    node* next;
    int  val;
};
*/
//table only
//based on count sort
//numbers have to have same length
void radix_T(int*T,int size,int len) {
    int Lim = 1;
    for(int i=1;i<len; i++){Lim*=10;}
    for(int k = 1;k<=Lim;k*=10) {
        int *A = (int *) malloc(sizeof(int) * 10);
        int *C = (int *) malloc(sizeof(int) * size);
        for (int i = 0; i < 10; i++) { A[i] = 0; }
        for (int i = 0; i < size; i++) { A[(T[i]%(k*10))/k]++; }
        for (int i = 1; i < 10; i++) { A[i] += A[i - 1]; }
        for (int i = size - 1; i >= 0; i--) {
            C[--A[(T[i]%(k*10))/k]] = T[i];
        }
        for (int i = 0; i < size; i++) { T[i] = C[i]; }
    }
}
