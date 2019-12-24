#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *next;
}node;

node * create_circular_link(int * arr, int len);
void printf_circular_link(node * link);
node * delete_node(node * link, int val);
node * add_node(node * link, int val);
void release_node(node * link);

int main(){
    node * circular = NULL;
    node * delete_circular = NULL;
    node * add_circular = NULL;
    int arr[] = {1, 2, 3, 4, 5};
    circular = create_circular_link(arr, sizeof(arr)/sizeof(arr[0]));
    delete_circular = delete_node(circular, 1);
    printf("Delete Node:");
    printf_circular_link(delete_circular);
    add_circular = add_node(delete_circular, 0);
    printf("\nAdd Node:");
    printf_circular_link(add_circular);
    printf("\nRelease Circular Linked List:");
    release_node(add_circular);
    return 0;
}

// 删除节点
node * delete_node(node * link, int val){
    node * head = link;
    node * tmp = NULL;
    node * k = NULL;
    int head_val = link->val;
    int count = 0;
    if(head_val == val){
        k = link->next;
    }else{
        k = link;
    }
    while(head->next){
        if(head_val == head->val){
            count += 1;
            if(count == 2){
                break;
            }
        }
        if(head->val == val){
            tmp = head;
            while(head->next){
                if(head->next->val == tmp->val){
                    head->next = tmp->next;
                    free(tmp);
                    break;
                }
                head = head->next;
            }
            break;
        }
        head = head->next;
    }
    return k;
}

// 添加新节点
node * add_node(node * link, int val){
    node * tmp = link;
    node * k = NULL;
    node * new_node = (node *)malloc(sizeof(node));
    int count = 0;
    int head_val = 0;
    new_node->val = val;
    new_node->next = NULL;
    if(tmp->val > val){
        k = new_node;
    }else{
        k = link;
    }
    while(tmp->next){
        if(tmp->val == head_val){
            count += 1;
            if(count == 2){
                break;
            }
        }
        if(tmp->val > val){
            new_node->next = tmp;
            while(tmp->next){
                if(tmp->next->val == new_node->next->val){
                    tmp->next = new_node;
                    break;
                }
                tmp = tmp->next;
            }
            break;
        }
        tmp = tmp->next;
    }
    return k;
}

// 创建循环链表
node * create_circular_link(int * arr, int len){
    node * tmp = NULL;
    node * ptr = NULL;
    node * head = (node *)malloc(sizeof(node));
    head->val = arr[0];
    head->next = NULL;
    tmp = head;
    ptr = head;

    for(int i = 1; i < len; i += 1){
        node * tmp_node = (node *)malloc(sizeof(node));
        tmp_node->val = arr[i];
        tmp_node->next = NULL;
        while(ptr->next){
            ptr = ptr->next;
        }
        ptr->next = tmp_node;
    }
    // 首尾连接
    while(ptr->next){
        ptr = ptr->next;
    }
    ptr->next = tmp;
    return tmp;
}

// 释放所有节点
void release_node(node * link){
    node * tmp = link;
    node * head = link;
    int head_val = tmp->val;
    while(tmp->next){
        if(tmp->next->val == head_val){
            tmp->next = NULL;
            break;
        }
        tmp = tmp->next;
    }
    while(head->next){
        node * k = NULL;
        k = head;
        head = head->next;
        free(k);
    }
    printf("Release Success!");
}

// 打印循环链表
void printf_circular_link(node * link){
    node * tmp = NULL;
    node * head = NULL;
    tmp = link;
    head = link;

    int count = 0;
    int head_val = link->val;
    while(tmp->next){
        if(tmp->val == head_val){
            count += 1;
        }
        if(count == 2){
            break;
        }
        printf("%d", tmp->val);
        tmp = tmp->next;
    }
}