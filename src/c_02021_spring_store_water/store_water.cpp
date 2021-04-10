#include "store_water.h"

#include "math.h"

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int storeWater(int *bucket, int bucketSize, int *vat, int vatSize) {

    // 1 <= bucket.length == vat.length <= 100
    int vmax = vat[0];
    for (int i = 1; i < vatSize; i++) {
        if (vat[i] > vmax) {
            vmax = vat[i];
        }
    }
    if (!vmax) {
        return 0;
    }
    int res = 2147483647;
    for (int i = 1; i < vmax + 1; i++) {
        int cur = i;
        for (int j = 0; j < bucketSize; j++) {
            int needs = ceil((double) vat[j] / i);
            int times = max(0, needs - bucket[j]);
            cur += times;
        }
        res = min(res, cur);
    }
    return res;
}


int storeWater_old(int *bucket, int bucketSize, int *vat, int vatSize) {
    if (bucketSize != vatSize || bucketSize == 0 || vatSize == 0) {
        return 0;
    }
    int cnt = 0;
    int tmp[bucketSize];

    int allzero = 0;
    for (int i = 0; i < vatSize; i++) {
        if (vat[i] != 0) {
            allzero = 1;
        }
    }
    if (allzero == 0) {
        return 0;
    }

    for (int i = 0; i < bucketSize; i++) {
        if (bucket[i] == 0 && vat[i] != 0) {
            bucket[i]++;
            cnt++;
        }
        while (true) {
            int m1 = ceil(((float) vat[i]) / bucket[i]);
            int m2 = ceil(((float) vat[i]) / (bucket[i] + 1));
            if (m1 - m2 >= 1) {
                bucket[i]++;
                cnt++;
            } else {
                tmp[i] = m1;
                break;
            }
        }
    }

    int cnt_plus = tmp[0];
    for (int i = 0; i < bucketSize; i++) {
        if (tmp[i] > cnt_plus) {
            cnt_plus = tmp[i];
        }
    }

    return cnt + cnt_plus;
}
