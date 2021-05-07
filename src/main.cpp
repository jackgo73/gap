
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
    SMgrRelationData *reln = (SMgrRelationData *) malloc(sizeof(SMgrRelationData));

    MdfdVec d100, d233;
    d100.mdfd_vfd = 10;
    d100.mdfd_segno = 12;
    d233.mdfd_vfd = 20;
    d233.mdfd_segno = 25;

    reln->md_seg_fds[0] = &d100;
    reln->md_num_open_segs[0] = 100;
    reln->md_seg_fds[1] = &d233;
    reln->md_num_open_segs[1] = 233;

    MdfdVec *s100, *s233;
    s100 = (MdfdVec *) malloc(sizeof(MdfdVec));
    s100->mdfd_segno = 333;
    s100->mdfd_vfd = 344;
    s233 = (MdfdVec *) malloc(sizeof(MdfdVec));
    s233->mdfd_segno = 555;
    s233->mdfd_vfd = 50;

    reln->md_seg_fds[2] = s100;
    reln->md_seg_fds[3] = s233;

    // 堆正序生长，栈逆序生长！

    int targetseg = 1;
    int forknum = 0;

    struct _MdfdVec *s1 = reln->md_seg_fds[forknum];
    struct _MdfdVec s2 = reln->md_seg_fds[forknum][0];
    struct _MdfdVec s3 = *s1;
    struct _MdfdVec s4 = *(s1 - 1);
    struct _MdfdVec *s5 = &reln->md_seg_fds[forknum][1];


    v = &reln->md_seg_fds[forknum][targetseg];

    v = &reln->md_seg_fds[forknum][reln->md_num_open_segs[forknum] - 1];

    return 0;
}