#include <stdio.h>

void substitue(int* pa, int*pb);
void increasing(int* arr, int a);

void substitute(int* pa, int* pb) {
    int a = *pa;
    int b = *pb;

    *pa = b;
    *pb = a;
}

void increasing(int* arr, int a) {
    *(arr+1) += a;
}

int main() {
    printf("Hello world!\n");
    
    int in_hex = 165;
    printf("%d in binary num: %x\n", in_hex, in_hex);

    float int_cast = 16;
    printf("float %d\n", (int)int_cast);

    int arr[10] = {};
    arr[3] = 16;
    printf("in arr[3]: %d\n", arr[3]);

    int simple_int = 17;
    int* where_int_is = &simple_int;
    printf("where int is: 0x%x\n", where_int_is);

    int a;
    int* pa = &a;
    printf("pointer minus: (0x%x) - (0x%x)\n", (pa+1), pa);
    printf("%x\n", (pa+1) - pa);
    
    int* parr = &arr;
    printf("in *(parr+3): %d\n", *(parr+3));
    *(parr+4) = 99;
    printf("in arr[4]: %d\n", arr[4]);
    printf("sizeof(parr): %d\n", sizeof(parr));
    printf("sizeof(arr): %d\n", sizeof(arr));

    int multi_dim_arr[3][2] = {1,2,3,4,5,6};
    int* mul_parr = &multi_dim_arr;
    printf("multi_dim_arr[1][0]: %d\n", multi_dim_arr[1][0]);
    printf("multi_dim_arr in pointer access: %d\n", *(mul_parr+2));

    int (*pparr)[3] = &arr;
    printf("arr: %p\n", arr);
    printf("parr: %p\n", pparr);

    int tempa = 14;
    int tempb = 12;
    substitute(&tempa, &tempb);
    printf("tempa & tempb: %d & %d\n", tempa, tempb);

    int snd_arr[2][3] = {{1,2,3},{4,5,6}};
    increasing(snd_arr[1], 30);
    printf("%d\n", sizeof(snd_arr)/sizeof(int));

    int* snd_parr = &snd_arr;
    for(int i = 0; i<(sizeof(snd_arr)/sizeof(int)); i++) {
        printf("%d ", *snd_parr);
        snd_parr++;
    }

}

