
#ifndef GAP_BINHEAP_H
#define GAP_BINHEAP_H

#include <stdlib.h>

/*
 *
 */

typedef int ElementType;

/*
 *
 */

#define Error(str)        FatalError(str)
#define FatalError(str)   fprintf( stderr, "%s\n", str ), exit( 1 )
#define MinData (-32767)
/*
 *
 */

struct HeapStruct;

typedef struct HeapStruct *PriorityQueue;

/*
 *
 */

PriorityQueue Initialize(int MaxElements);

void Destroy(PriorityQueue H);

void MakeEmpty(PriorityQueue H);

void Insert(ElementType X, PriorityQueue H);

ElementType DeleteMin(PriorityQueue H);

ElementType FindMin(PriorityQueue H);

int IsEmpty(PriorityQueue H);

int IsFull(PriorityQueue H);

/*
 *
 */

struct HeapStruct {
    int capacity;
    int size;
    ElementType *elements;
};
//
//PriorityQueue Initialize(int maxElements) {
//    PriorityQueue H;
//    H = (HeapStruct *) malloc(sizeof(struct HeapStruct));
//    if (H == NULL) {
//        FatalError("out of memory");
//    }
//    H->elements = (ElementType *) malloc((maxElements + 1) * sizeof(ElementType));
//    if (H->elements == NULL) {
//        FatalError("out of memory");
//    }
//    H->capacity = maxElements;
//    H->size = 0;
//    H->elements[0] = MinData;
//
//    return H;
//}
//
//void MakeEmpty(PriorityQueue H) {
//    H->size = 0;
//}
//
//void Insert( ElementType X, PriorityQueue H )
//{
//    int i;
//    if( IsFull( H ) )
//    {
//        Error( "Priority queue is full" );
//        return;
//    }
//
//    for( i = ++H->size; H->elements[ i / 2 ] > X; i /= 2 )
//        H->elements[ i ] = H->elements[ i / 2 ];
//    H->elements[ i ] = X;
//}
//
//int IsFull( PriorityQueue H )
//{
//    return H->size == H->capacity;
//}


#endif //GAP_BINHEAP_H
