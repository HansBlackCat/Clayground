#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tailrec_test(int init, int tail);
int recursion_test(int init);
int swap2(void* x, void* y, int size);
int arr_printer(int* arr, int size);
int allocator(int** iptr);
int sub_arr(int arr[][2]);

typedef struct ListElem_ {
    void* data;
    struct ListElem_ *next;
} ListElem_;

int main() {
    int arr[3][2] = {{1,2},{3,4},{5,6}};
    int onedarr[10] = {0,2,3,4,5};
    arr_printer(arr, sizeof(arr));

    sub_arr(arr);
    arr_printer(arr, sizeof(arr));

    int a = 1;
    int b = 3;
    swap2(&a, &b, 4);
    printf("%d, %d\n", a, b);

    printf("%d\n", recursion_test(5));
    printf("%d\n", tailrec_test(5, 1));

}

int arr_printer(int* arr, int size) {
    for(int i = 0; i<(size/sizeof(int)); i++) {
        printf("%d ", *(arr+i));
    }
    printf("\n");
}

// Memory Leaker
int allocator(int** iptr) {
    if((*iptr = (int*)malloc(sizeof(int))) == NULL) {
        return -1;
    }
    return 0;
}

int sub_arr(int arr[][2]) {
    arr[2][0] = 5;
    return 0;
}

int swap2(void* x, void* y, int size) {
    void* tmp;
    if ((tmp = malloc(size)) == NULL) {
        return -1;
    }
    memcpy(tmp, x, size);
    memcpy(x, y, size);
    memcpy(y, tmp, size);
    free(tmp);

    return 0;
}

int recursion_test(int init) {
    if (init < 0) return 0;
    else if (init == 0 || init == 1) return 1;
    else return init * recursion_test(init-1);
}

int tailrec_test(int init, int tail) {
    if (init < 0) return 0;
    else if (init == 0) return 1;
    else if (init == 1) return tail;
    else return tailrec_test(init-1, init*tail);
}