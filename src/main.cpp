
#include <iostream>
#include <stdlib.h>

typedef enum ForkNumber {
    InvalidForkNumber = -1,
    MAIN_FORKNUM = 0,
    FSM_FORKNUM,
    VISIBILITYMAP_FORKNUM,
    INIT_FORKNUM
} ForkNumber;

typedef int File;
typedef int BlockNumber;
#define MAX_FORKNUM     INIT_FORKNUM
typedef struct _MdfdVec {
    File mdfd_vfd;
    BlockNumber mdfd_segno;
} MdfdVec;

typedef struct SMgrRelationData {
    int md_num_open_segs[MAX_FORKNUM + 1];
    struct _MdfdVec *md_seg_fds[MAX_FORKNUM + 1];
} SMgrRelationData;

int main() {
    std::cout << "haha" << std::endl;

    MdfdVec *v;
    SMgrRelationData *reln = (SMgrRelationData *)malloc(sizeof(SMgrRelationData));

    int targetseg = 0;
    int forknum = 0;

    v = &reln->md_seg_fds[forknum][targetseg];

    v = &reln->md_seg_fds[forknum][reln->md_num_open_segs[forknum] - 1];

    return 0;
}