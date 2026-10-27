#include "m2c.h"

enum {
    CHILD_ENTRY_STRIDE = 30,
    CHILD_INFO_SIZE    = 0x16,
};

/* Per-child bit masks (bit index = aid) tracking each child's progress through
   the multiboot parent states; m_a is the set of children that connected. */
typedef struct {
    void *buf0;
    void *buf4;
    u16 pad8;
    u16 m_a;
    u16 m_c;
    u16 m_e;
    u16 m_10;
    u16 m_12;
    u16 m_14;
} MbState;

extern MbState data_0210da80;
extern u8 data_0210da94[];
extern u8 data_0210daac[];
extern u8 data_0210daad[];
extern u8 data_0210daae[];
extern u8 data_0210daaf[];
extern u8 data_0210dab0[];
extern u8 data_0210dab1[];
extern u16 data_0210dab2[];

extern s32 func_020b01bc();
extern s32 func_020b01e0(s32);
extern void func_020afcac(s16);
extern void func_020afdc4(s32);
extern void func_020afe4c(s32);
extern void func_020aff04(u16);
extern void func_0205e860(s32);
extern void *MB_CommGetChildUser(s32);
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(s32);
extern void OS_Terminate(void);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void MB_EndToIdle(void);

/* Parent state callback (registered via MB_CommSetParentStateCallback):
   aid = child id, state = parent state code, arg = state-specific data. */
void func_020af9a0(u16 aid, s32 state, u8 *arg) {
    s32 off;
    void *child;
    switch (state) {
        case 2:
            if (func_020b01bc() == 2) {
                s32 irq = OS_DisableInterrupts();
                data_0210da80.m_a |= 1 << aid;
                OS_RestoreInterrupts(irq);
                off                                     = (aid - 1) * CHILD_ENTRY_STRIDE;
                data_0210daac[off]                      = arg[0xa];
                data_0210daad[off]                      = arg[0xb];
                data_0210daae[off]                      = arg[0xc];
                data_0210daaf[off]                      = arg[0xd];
                data_0210dab0[off]                      = arg[0xe];
                data_0210dab1[off]                      = arg[0xf];
                *(u16 *) (((u8 *) data_0210dab2) + off) = aid;
            }
            break;
        case 3: {
            u16 mask;
            s32 irq;
            if (func_020b01e0(aid) == 6) {
                return;
            }
            mask = ~(1 << aid);
            irq  = OS_DisableInterrupts();
            data_0210da80.m_a &= mask;
            data_0210da80.m_c &= mask;
            data_0210da80.m_e &= mask;
            data_0210da80.m_10 &= mask;
            data_0210da80.m_12 &= mask;
            data_0210da80.m_14 &= mask;
            OS_RestoreInterrupts(irq);
            break;
        }
        case 10:
            if (func_020b01bc() != 2) {
                func_020afe4c(aid);
                return;
            }
            data_0210da80.m_c |= 1 << aid;
            func_020afdc4(aid);
            child = MB_CommGetChildUser(aid);
            if (child != 0) {
                MI_CpuCopy8(child, data_0210da94 + 2 + (aid - 1) * CHILD_ENTRY_STRIDE, CHILD_INFO_SIZE);
            }
            break;
        case 14:
            data_0210da80.m_c &= ~(1 << aid);
            data_0210da80.m_e |= 1 << aid;
            func_020aff04(aid);
            break;
        case 7:
            data_0210da80.m_10 &= ~(1 << aid);
            data_0210da80.m_12 |= 1 << aid;
            break;
        case 9:
            data_0210da80.m_12 &= ~(1 << aid);
            data_0210da80.m_14 |= 1 << aid;
            if (data_0210da80.m_a == data_0210da80.m_14) {
                MB_EndToIdle();
            }
            break;
        case 12:
            if (func_020b01bc() == 4) {
                func_020afcac(5);
            } else {
                func_020afcac(0);
            }
            if (data_0210da80.buf0 != 0) {
                func_0205e860((s32) data_0210da80.buf0);
                data_0210da80.buf0 = 0;
            }
            if (data_0210da80.buf4 != 0) {
                func_0205e860((s32) data_0210da80.buf4);
                data_0210da80.buf4 = 0;
            }
            break;
        case 13:
            switch (*(u16 *) arg) {
                case 1:
                case 2:
                case 9:
                    func_020afcac(7);
                    break;
                case 8:
                    break;
            }
            break;
        case 1:
        case 4:
        case 5:
        case 6:
        case 8:
        case 11:
            break;
        default:
            OS_Terminate();
            break;
    }
}
