#pragma opt_rotateloops off

typedef struct SNDCommand {
    struct SNDCommand *next;
    unsigned int id;
    unsigned int arg[4];
} SNDCommand;

typedef struct SNDCommandMgr {
    SNDCommand *freeHead;
    unsigned int processedTag;
    SNDCommand *reservedHead;
    SNDCommand *reservedTail;
    SNDCommand *freeTail;
    unsigned int unk14;
    int sentRingIndex;
    int sentBlockCount;
    unsigned int nextTag;
} SNDCommandMgr;

extern SNDCommandMgr sFreeList;
extern SNDCommand *sWaitingCommandListQueue[15];
extern unsigned char sCommandArray[0x1800];

extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int);
extern int SND_RecvCommandReply(int);
extern void RequestCommandProc(void);
extern void DC_FlushRange(void *, unsigned int);
extern int PXI_SendWordByFifo(int, void *, int);
extern void OS_SpinWait(int);

int SND_FlushCommand(unsigned int flags) {
    int state;

    state = OS_DisableInterrupts();
    if (sFreeList.reservedHead == 0) {
        OS_RestoreInterrupts(state);
        return 1;
    }
    if (sFreeList.sentBlockCount >= 8) {
        if ((flags & 1) == 0) {
            OS_RestoreInterrupts(state);
            return 0;
        }
        do {
            SND_RecvCommandReply(1);
        } while (sFreeList.sentBlockCount >= 8);
    }
    DC_FlushRange(sCommandArray, 0x1800);
    if (PXI_SendWordByFifo(7, sFreeList.reservedHead, 0) < 0) {
        if ((flags & 1) == 0) {
            OS_RestoreInterrupts(state);
            return 0;
        }
        while (PXI_SendWordByFifo(7, sFreeList.reservedHead, 0) < 0) {
            OS_RestoreInterrupts(state);
            OS_SpinWait(100);
            state = OS_DisableInterrupts();
        }
    }
    if (flags & 2) {
        RequestCommandProc();
    }
    sWaitingCommandListQueue[sFreeList.sentRingIndex] = sFreeList.reservedHead;
    sFreeList.sentRingIndex                           = sFreeList.sentRingIndex + 1;
    if (sFreeList.sentRingIndex > 8) {
        sFreeList.sentRingIndex = 0;
    }
    sFreeList.reservedHead   = 0;
    sFreeList.reservedTail   = 0;
    sFreeList.sentBlockCount = sFreeList.sentBlockCount + 1;
    sFreeList.nextTag        = sFreeList.nextTag + 1;
    OS_RestoreInterrupts(state);
    return 1;
}
