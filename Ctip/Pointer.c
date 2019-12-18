#include <stdio.h>

int * add(int a, int b);
int times(int a, int b);
void swap_val(int *x, int *y);
void print_arr(int *arr_ptr);
void change_ele(int * arr);

int main(int argc, char * argv[]){
    // &是取址运算符,用于获取变量地址
    int l = 1;
    int *k;
    k = &l;
    printf("%d, %d\n", *k, l);
    // 指针函数调用
    printf("%d\n", * add(1, 2));

    // 函数指针调用
    int (* ptr)(int, int);
    ptr = times;
    printf("%d\n", (* ptr)(3, 5));

    // 指针传递值
    int x = 10;
    int y = 20;
    swap_val(&x, &y);
    printf("%d %d\n", x, y);

    // 传递数组
    int arr[] = {1, 2, 3, 4, 5};
    print_arr(arr);

    // 传递指针数组
    int arr_tmp[] = {1, 2, 3, 4, 5};
    change_ele(arr_tmp);
    for(int i = 0; i < 5; i += 1){
        printf("%d\n", *(arr_tmp + i));
    }
    return 0;
}

// 指针函数
int * add(int a, int b){
    int c = a + b;
    int *d = &c;
    return d;
}

// 函数指针
int times(int a, int b){
    return a * b;
}

// 指针传递值
void swap_val(int *x, int *y){
    printf("%d %d\n", *x, *y);
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

// 传递数组并遍历数组
void print_arr(int *arr_ptr){
    for(int i = 0; i < 5; i += 1){
        printf("%d\n", *(arr_ptr + i));
    }
}

// 添加新元素,引用传递
void change_ele(int * arr_tmp){
    int * tmp = arr_tmp;
    tmp[0] = 9;
}