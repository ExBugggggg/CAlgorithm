#include <stdio.h>
#include <stdlib.h>

// define struct
typedef struct Node{
    int val;
    struct Node * next;
}node;

// define functions
node * create_link();
int find_node(node * p, int val);
node * add_new_node(node * p, int val);
node * delete_node(node * p, int val);

int main(){
    node * single_link;
    single_link = create_link();
    if(find_node(single_link, 10)){
        printf("Find This Value\n");
    }else{
        printf("Can't Find This Value In This Single Link\n");
    }
    single_link = add_new_node(single_link, 103);
    if(find_node(single_link, 103)){
        printf("Find This Value\n");
    }else{
        printf("Can't Find This Value In This Single Link\n");
    }
    single_link = delete_node(single_link, 3);
    if(find_node(single_link, 3)){
        printf("Find This Value\n");
    }else{
        printf("Can't Find This Value In This Single Link\n");
    }
    return 0;
}

// 创建链表
node * create_link(){
    node * p = (node *)malloc(sizeof(node));
    // 生成一个临时节点用于遍历链表
    node * head = p;
    for(int i = 0; i < 100; i += 1){
        // 节点生成
        node * link = (node *)malloc(sizeof(node));
        link->val = i;
        link->next = NULL;
        // head的next赋值为link
        head->next = link;
        // head指向下一个
        head=head->next;
    }
    return p;
}

// 寻找值
int find_node(node * p, int val){
    node * tmp = p;
    while(tmp->next){
        tmp = tmp->next;
        if(tmp->val != val){
            continue;
        }else{
            printf("%d\n", tmp->val);
            return 1;
        }
    }
    return 0;
}

// 添加新节点
node * add_new_node(node * p, int val){
    node * tmp = p;
    node * new_node = (node *)malloc(sizeof(node));
    while(tmp->next){
        tmp = tmp->next;
        if(tmp->val < val){
            continue;
        }else{
            break;
        }
    }
    new_node->val = val;
    new_node->next = tmp->next;
    tmp->next = new_node;
    return p;
}

// 删除节点
node * delete_node(node * p, int val){
    node * tmp = p;
    node * del_node;
    node * pre_node;
    while(tmp->next){
        pre_node = tmp;
        tmp = tmp->next;
        if(tmp->val == val){
            del_node = tmp;
            if(tmp->next){
                pre_node->next = tmp->next;
            }
            free(del_node);
            break;
        }
    }
    return p;
}