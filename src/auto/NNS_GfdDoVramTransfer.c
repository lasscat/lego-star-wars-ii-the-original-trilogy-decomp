/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_02072824 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/gfd/gfd_vramtransfer.c (license: none),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
typedef s32 BOOL;
typedef struct {
    u32 type;
    const void *pSrc;
    u32 dstAddr;
    u32 szByte;
} UnkVramTransferTask;
typedef struct {
    UnkVramTransferTask *pTaskArray;
    u32 lengthOfArray;
    u16 idxFront;
    u16 idxRear;
    u16 numTasks;
    u32 totalSize;
} UnkVramTransferManager;
extern UnkVramTransferManager s_VramTransferManager;
void DoTransfer_(UnkVramTransferTask *task);
UnkVramTransferTask *NNSi_GfdGetFrontVramTransferTaskQueue(UnkVramTransferManager *mgr);
BOOL NNSi_GfdPopVramTransferTaskQueue(UnkVramTransferManager *mgr);
void NNS_GfdDoVramTransfer(void) {
    UnkVramTransferManager *mgr = &s_VramTransferManager;
    UnkVramTransferTask *task   = NNSi_GfdGetFrontVramTransferTaskQueue(mgr);

    while (NNSi_GfdPopVramTransferTaskQueue(mgr)) {
        DoTransfer_(task);
        mgr->totalSize -= task->szByte;
        task = NNSi_GfdGetFrontVramTransferTaskQueue(mgr);
    }
}
