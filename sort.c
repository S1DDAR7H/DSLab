#include <stdio.h>

int a[10], size;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void dispBef(){
    printf("Before Sorting:\n");
    for(int i=0; i<size;i++){
        printf("%d  ", a[i]);
    }
    printf("\n");
}

void dispAf(){
    printf("After Sorting:\n");
    for(int i=0; i<size;i++){
        printf("%d  ", a[i]);
    }
    printf("\n");
}

void read(){
    printf("Enter Size:");
    scanf("%d", &size);
    printf("Enter Array:\n");
    for(int i=0; i<size;i++){
        scanf("%d", &a[i]);
    }
}

//insertion sort
void insertionSort(){
    for(int i=0; i<size; i++){
        int key = a[i], j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j --;
        }
        a[j+1] = key;
    }
    dispAf();
}

//selection sort
void selectionSort(){
    for(int i=0; i<size-1; i++){
        int min = i;
        for(int j=i+1; j<size;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        swap(&a[min], &a[i]);
    }
    dispAf();
}

//quicksort
int partition(int low, int high){
    int pivot = a[high], i=low-1;
    for(int j=low; j<=high-1; j++){
        if(a[j] <= pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return (i+1);
}

void quicksort(int low, int high){
    if(low<high){
        int p = partition(low, high);
        quicksort(low, p-1);
        quicksort(p+1, high);
    }
}

//heapsort
void heapify(int n, int i){
    int largest = i;
    int left = 2 *i ; 
    int right = 2 * i + 1;
    if(left<n && a[left] > a[largest]){
        largest = left;
    }
    if(right<n && a[right] > a[largest]){
        largest = right;
    }
    if(largest != i){
        swap(&a[i], &a[largest]);
        heapify(n, largest);
    }
}

void heapsort(int n){
    for(int i=n/2-1; i>=0; i--){
        heapify(n,i);
    }
    for(int i=size-1; i>0; i--){
        swap(&a[0], &a[i]);
        heapify(i, 0);
    }
    dispAf();
} 

//mergesort
void merge(int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    int i, j, k;
    for(i=0; i<n1; i++){
        L[i] = a[l+1];
    }
    for(j=0; j<n2; j++){
        R[j] = a[m+j+1];
    }
    i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(L[n1] < R[n2]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int l, int r){
    if(l<r){
        int m=l+r/2;
        mergesort(l, m);
        mergesort(m+1, r);
        merge(l,m,r);
    }
    
}

void main(){
    read();
    dispBef();
    printf("Insertion Sort:\n");
    insertionSort();
    printf("Selection Sort:\n");
    selectionSort();
    printf("Quick Sort:\n");
    quicksort(0, size-1);
    dispAf(); //quicksort
    printf("Heap Sort:\n");
    int n = sizeof(a)/sizeof(a[0]);
    heapsort(n);
    printf("Merge Sort:\n");
    int k = sizeof(a)/sizeof(a[0]);
    heapsort(n);
    mergesort(0, n-1);
    dispAf(); //mergesort
}