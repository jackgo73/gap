#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <inttypes.h>

typedef struct {
    int key;
    int val;

    int nextFree;
    int lruMoreRecently;
    int lruLessRecently;
} Data;

typedef struct {
    int sizeLRUCache;
    Data e[0];
} LRUCache;

#define GetLruCacheHead(obj) (&obj->e[0])
#define GetLruCacheNode(n) (&obj->e[n])

LRUCache *lRUCacheCreate(int capacity) {
    LRUCache *cache = (LRUCache *) malloc(sizeof(LRUCache) + sizeof(Data) * (capacity + 1));
    memset(cache, 0, sizeof(LRUCache) + sizeof(Data) * (capacity + 1));
    cache->sizeLRUCache = capacity;
    for (int i = 0; i < cache->sizeLRUCache; i++) {
        cache->e[i].nextFree = i + 1;
    }
    return cache;
}

int lRUCacheGet(LRUCache *obj, int key) {
    int nextFree = GetLruCacheHead(obj)->nextFree;
    GetLruCacheHead(obj)->nextFree = GetLruCacheNode(nextFree)->nextFree;

    Data *data = GetLruCacheNode(nextFree);


}

void lRUCachePut(LRUCache *obj, int key, int value) {

}

void lRUCacheFree(LRUCache *obj) {

}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);

 * lRUCachePut(obj, key, value);

 * lRUCacheFree(obj);
*/