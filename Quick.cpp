#include <iostream>

/*struct node {
    node* next;
    int  val;
};
*/
//table only
int partition(int*T,int s,int k){
    int p = T[s];
    int i=s,j=k;
    while(true) {
        while (T[j] > p) { j--; }
        while (T[i] < p) { i++; }
        if(i<j) {
            std::swap(T[i], T[j]);
            i++;j--;
        }else{
            return j;
        }
    }
}
void q_T(int *T,int s,int k){
    while(s<k){
        int p = partition(T,s,k);
        q_T(T,s,p);
        s=p+1;
    }
}
void quick_T (int*T,int size){
    q_T(T, 0, size-1);
}
