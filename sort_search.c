#include <stdio.h>

int size;

void read(int arr[10]){
    printf("Enter Array Elements: \n");
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
}

void lsearch(int arr[10], int item){
    int fl = -1;
    int i=0;
    for(i=0; i<size; i++){
        if(arr[i] == item){
            fl = 1;
            break;
        }
    }
    if(fl == 1){
        printf("Found %d at %d\n", item, i);
    }
    else{
        printf("Not found\n");
    }
}

void bsearch(int arr[10], int item){
    int low=0, mid, high=size-1, fl = -1;
    while(low <= high){
        mid = (low+high)/2;
        if(arr[mid] == item){
            fl = 1;
            break;
        }
        else if(arr[mid] > item){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    if(fl == 1){
        printf("Found %d at %d\n", item, mid);
    }
    else{
        printf("Not found\n");
    }
}

void bbSort(int arr[10]){
    for(int i = 0;i<size; i++){
        for(int j = 1; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insSort(int arr[10]){
    int i = 1,j;
    for(;i<size; i++){
        int key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void disp(int arr[10]){
    for(int i=0; i<size; i++){
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void main(){
    int a[10];    
    printf("Enter Size:\n");
    scanf("%d", &size);
    read(a);
    printf("Before Sorting:\n");
    disp(a);
    printf("After Sorting:\n");
    insSort(a);
    disp(a);
}