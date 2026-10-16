/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_020d0ae4 from https://github.com/Yokimitsuro/khdays-decomp libs/nitro/snd/calls/func_020d0ae4.c (license: CC0-1.0),
 * reused by tools/donor_match.py */
extern int func_020ce804(void);
extern void func_020ce818(int state);
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
extern SNDCommandMgr data_02115800;
void func_020d0ae4(SNDCommand *command) {
    SNDCommand *tail;
    int state;

    state = func_020ce804();
    tail  = data_02115800.reservedTail;

    if (tail == 0) {
        data_02115800.reservedHead = command;
        data_02115800.reservedTail = command;
    } else {
        tail->next                 = command;
        data_02115800.reservedTail = command;
    }
    command->next = 0;
    func_020ce818(state);
}
