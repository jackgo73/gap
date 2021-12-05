#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <inttypes.h>

#include "slist.h"

/*  k == lists.length  0 <= k <= 10^4  */
/*  0 <= lists[i].length <= 500        */
/*  -10^4 <= lists[i][j] <= 10^4       */

#define MAX_COL_LENHTH  500

int cmp(const void *a, const void *b) {
    return *(int16_t *) a - *(int16_t *) b;
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    if (lists == NULL || listsSize == 0) {
        return NULL;
    }

    int allValsIdx = 0;
    int16_t *allVals = (int16_t *) malloc(sizeof(int16_t) * listsSize * MAX_COL_LENHTH);
    if (allVals == NULL) {
        return NULL;
    }

    for (int i = 0; i < listsSize; ++i) {
        struct ListNode *p = lists[i];
        while (p != NULL) {
            allVals[allValsIdx++] = p->val;
            p = p->next;
        }
    }

    /* in case: [[]] */
    if (allValsIdx == 0) {
        return NULL;
    }

    qsort(allVals, allValsIdx, sizeof(int16_t), cmp);

    struct ListNode *res = (struct ListNode *) malloc(sizeof(struct ListNode) * allValsIdx);
    if (res == NULL) {
        free(allVals);
        return NULL;
    }
    struct ListNode *p = res;

    for (int i = 0; i < allValsIdx - 1; ++i) {
        p->val = allVals[i];
        p->next = p + 1;
        p = p->next;
    }
    p->val = allVals[allValsIdx - 1];
    p->next = NULL;

    free(allVals);

    return res;
}