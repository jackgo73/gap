#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned short uint16;	/* == 16 bits */
typedef unsigned char uint8;	/* == 8 bits */

#define FLEXIBLE_ARRAY_MEMBER /**/
typedef size_t Size;


struct HeapTupleHeaderData
{

    uint16 t_ctid;		/* current TID of this or newer tuple (or a
								 * speculative insertion token) */

    /* Fields below here must match MinimalTupleData! */

    uint16		t_infomask2;	/* number of attributes + various flags */

    uint16		t_infomask;		/* various flag bits, see below */

    uint8		t_hoff;			/* sizeof header incl. bitmap, padding */

    /* ^ - 23 bytes - ^ */

    uint16		t_bits[FLEXIBLE_ARRAY_MEMBER];	/* bitmap of NULLs */

    /* MORE DATA FOLLOWS AT END OF STRUCT */
};

typedef struct HeapTupleHeaderData HeapTupleHeaderData;

#define offsetof(TYPE, MEMBER) __builtin_offsetof (TYPE, MEMBER)


int main() {
    Size		len;
    Size len1;

    int a[];

//
//    len = offsetof(HeapTupleHeaderData, t_bits);
//    len1 = sizeof(HeapTupleHeaderData);

    return 0;
}
