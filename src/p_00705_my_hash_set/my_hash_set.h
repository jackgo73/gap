#ifndef P_00705_MY_HASH_SET
#define P_00705_MY_HASH_SET

#include "stdlib.h"

#define MAXSIZE 769  /* 选取一个质数即可 */

typedef struct Node {
    int val;
    struct Node *next;
} List;

typedef struct {
    List *hash[MAXSIZE];
} MyHashSet;

MyHashSet* myHashSetCreate() {
    MyHashSet *obj = (MyHashSet*)malloc(sizeof(MyHashSet));
    int i;
    /* 对链表的头结点赋初值 */
    for (i = 0; i < MAXSIZE; i++) {
        obj->hash[i] = (List*)malloc(sizeof(List));
        obj->hash[i]->val  = i;
        obj->hash[i]->next = NULL;
    }
    return obj;
}

/* 链表的头插法 */
void addList(List *list, int key) {
    List *tmp     = list->next;
    List *newNode = (List*)malloc(sizeof(List));
    newNode->val  = key;
    list->next    = newNode;
    newNode->next = tmp;
    return;
}

/* 找到对应元素进行删除 */
void removeList(List *list, int key) {
    List *cur = list->next;
    List *pre = list;
    while (cur != NULL) {
        if (cur->val == key) {
            pre->next = cur->next;
            free(cur);
            return;
        }
        pre = cur;
        cur = cur->next;
    }
}

/* 判断元素是否在链表中存在 */
bool isContain(List *list, int key) {
    List *cur = list->next;
    while (cur != NULL) {
        if (cur->val == key) {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

/* 链表元素释放 */
void freeList(List *list) {
    List *cur = list;
    List *tmp = NULL;
    while (cur != NULL) {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}

/* 已经存在, 就不添加; 不存在, 则加入hash中 */
void myHashSetAdd(MyHashSet* obj, int key) {
    if (isContain(obj->hash[key % MAXSIZE], key)) {
        return;
    }
    addList(obj->hash[key % MAXSIZE], key);
}

/* 移除对应元素 */
void myHashSetRemove(MyHashSet* obj, int key) {
    removeList(obj->hash[key % MAXSIZE], key);
}

/* 判断是否包含 */
bool myHashSetContains(MyHashSet* obj, int key) {
    return isContain(obj->hash[key % MAXSIZE], key);
}

/* 空间释放 */
void myHashSetFree(MyHashSet* obj) {
    int i;
    for (i = 0; i < MAXSIZE; i++) {
        freeList(obj->hash[i]);
    }
    free(obj);
}


#endif //P_00705_MY_HASH_SET
