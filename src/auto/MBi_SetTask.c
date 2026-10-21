#include "m2c.h"

/*
 * MBi_SetTask: queues a task for the mission task thread.
 *
 * MBiTaskInfo layout (offsets in bytes):
 *   0x00 next task in the queue
 *   0x04 busy : 1 and priority : 31 (bitfields)
 *   0x08 task function
 *   0x0c callback function
 *   0x10 four parameter words
 *
 * MBiTaskWork layout (offsets in bytes):
 *   0x000 the task thread (OSThread)
 *   0x0c0 head of the task list
 *   0x0c4 the end-of-thread sentinel task
 */

typedef void (*MB_TASK_FUNC)(void *);

typedef struct MBiTaskInfo_tag {
    struct MBiTaskInfo_tag *next;
    u32 busy : 1;
    u32 priority : 31;
    MB_TASK_FUNC task;
    MB_TASK_FUNC callback;
    u32 param[4];
} MBiTaskInfo;

typedef struct {
    u8 th[0xc0];
    MBiTaskInfo *volatile list;
    MBiTaskInfo end_task;
} MBiTaskWork;

extern MBiTaskWork *mbi_task_work;
extern s32 MBi_IsTaskAvailable(void);
extern void OS_Terminate(void);
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32);
extern u32 OS_GetThreadPriority(void *);
extern void OS_WakeupThreadDirect(void *);

void MBi_SetTask(MBiTaskInfo *pt, MB_TASK_FUNC task, MB_TASK_FUNC callback, u32 priority) {
    MBiTaskWork *work = mbi_task_work;
    MBiTaskInfo *cur;
    u32 prio;
    u32 curprio;
    u32 bak;

    if (MBi_IsTaskAvailable() == 0) {
        OS_Terminate();
    }
    if (pt->busy != 0) {
        OS_Terminate();
    }

    prio = priority;
    if (prio > 0x1f) {
        curprio = OS_GetThreadPriority(&work->th[0]);
        if (prio == 0x20) {
            prio = (curprio != 0) ? curprio - 1 : 0;
        } else if (prio == 0x21) {
            prio = (curprio < 0x1f) ? curprio + 1 : 0x1f;
        } else if (prio == 0x22) {
            prio = curprio;
        } else {
            prio = 0x1f;
        }
    }

    bak = OS_DisableInterrupts();

    pt->busy     = 1;
    pt->priority = prio;
    pt->task     = task;
    pt->callback = callback;

    if (work->list == 0) {
        if (pt == &work->end_task) {
            mbi_task_work = 0;
        }
        work->list = pt;
        OS_WakeupThreadDirect(work);
    } else {
        cur = work->list;
        if (pt == &work->end_task) {
            while (cur->next != 0) {
                cur = cur->next;
            }
            cur->next     = pt;
            mbi_task_work = 0;
        } else if (prio < cur->priority) {
            work->list = pt;
            pt->next   = cur;
        } else {
            while (cur->next != 0 && prio >= cur->next->priority) {
                cur = cur->next;
            }
            pt->next  = cur->next;
            cur->next = pt;
        }
    }

    OS_RestoreInterrupts(bak);
}
