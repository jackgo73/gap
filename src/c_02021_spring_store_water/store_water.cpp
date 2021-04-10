#include "store_water.h"

#include "math.h"

int storeWater(int *bucket, int bucketSize, int *vat, int vatSize) {
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
            if (m1 - m2 > 1) {
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
