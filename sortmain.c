#include <stdio.h>
#define sizearr 50
void shift_element(int* arr, int i){
    for (int j = 0; j < i; ++j) {
        *(arr+i-j)=*(arr+i-j-1);
    }
}

void insertion_sort(int *arr, int n) {

    for (int i = 1; i < n; i++) {
        int temp = *(arr+i);
        int j = i - 1;
        int cnt=0;
        while (j >= 0 && *(arr+j) > temp) {
            cnt++;
            j--;
        }
        shift_element(arr+i-cnt,cnt);
        *(arr+j + 1) = temp;
    }
}
void print_arr(int arr[],int n){
    for (int i = 0; i < n-1; ++i) {
        printf("%d,",*(arr+i));
    }
    printf("%d",*(arr+n-1));
}

int main(){
    int arr[sizearr];
    for (int i = 0; i < sizearr; ++i) {
        scanf("%d",(arr+i));
    }
    insertion_sort(arr,sizearr);
    print_arr(arr,sizearr);

    return 0;
}