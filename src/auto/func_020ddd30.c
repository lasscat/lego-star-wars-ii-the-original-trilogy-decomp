/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */

extern int func_020ce804(void);
extern void func_020ce818(int state);
extern void func_020cf344(void *dst, int value, int size);
extern void func_020cd494(void *queue);
extern void func_020cd384(void);
extern char data_0211e628;
typedef struct {
    int (*run)(void *);
    void (*done)(void *);
    int result;
    int rest[6];
} Ov_CardJob;

/* JobQueue_WorkerLoop from https://github.com/Yokimitsuro/khdays-decomp libs/nitro/mi/calls/JobQueue_WorkerLoop.c (license:
 * CC0-1.0), reused by tools/donor_match.py */
void func_020ddd30(char *ctx) {
    Ov_CardJob job;
    void (*done)(void *);
    int enabled;
    for (;;) {
        func_020cf344(&job, 0, 0x24);
        enabled = func_020ce804();
        while (*(char *volatile *) (ctx + 0xc0) == 0) {
            func_020cd494(0);
        }
        job = *(Ov_CardJob *) *(char *volatile *) (ctx + 0xc0);
        func_020ce818(enabled);
        if (job.run != 0) {
            job.result = job.run(&job);
        }
        enabled                           = func_020ce804();
        done                              = job.done;
        *((char *) &data_0211e628 + 0x26) = 0;
        if (done != 0) {
            done(&job);
        }
        if (*(int *) &data_0211e628 != 0) {
            *(char *volatile *) (ctx + 0xc0) = 0;
            func_020ce818(enabled);
        } else {
            func_020cd384();
            return;
        }
    }
}
