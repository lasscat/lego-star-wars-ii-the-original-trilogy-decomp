/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */

extern int func_020ce804(void);
extern void func_020ce818(int);
extern void func_020cd098(void *);
extern void func_020cd59c(void);
typedef struct Node {
    char pad[0x68];
    struct Node *next;
    int pad2;
    int value;
} Node;
typedef struct {
    char pad[0x2c];
    Node *head;
} ListHead;
extern ListHead data_02115424;
extern Node data_02115458;

/* OSi_WaitOnExitProc from https://github.com/Yokimitsuro/khdays-decomp libs/nitro/os/calls/OSi_WaitOnExitProc.c (license:
 * CC0-1.0), reused by tools/donor_match.py */
int func_020cd664(Node *target, int newval) {
    Node *cur;
    Node *prev;
    int intr;

    prev = 0;
    cur  = data_02115424.head;
    intr = func_020ce804();
    while (cur != 0 && cur != target) {
        prev = cur;
        cur  = cur->next;
    }
    if (cur == 0 || cur == &data_02115458) {
        func_020ce818(intr);
        return 0;
    }
    if (cur->value != newval) {
        if (prev == 0) {
            data_02115424.head = target->next;
        } else {
            prev->next = target->next;
        }
        target->value = newval;
        func_020cd098(target);
        func_020cd59c();
    }
    func_020ce818(intr);
    return 1;
}
