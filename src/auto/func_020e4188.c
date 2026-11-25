/* Called from func_020e41e8 (case 15) when func_020e4104 returns 0: calls func_020e3700, fills the
 * record at context->FP + cinfo_ref from the context and the catcher, then hands control to func_020e4bd8,
 * which reloads r4-r11 and sp from the context and jumps to code_start + catch_pcoffset (it does not return). */
#include "m2c.h"

typedef struct {
    void *throwtype;
    void *location;
    void *dtor;
    void *f0c;
    void *f10;
    void *f14;
    char *FP;
} ThrowContext;

typedef struct {
    char *code_start;
} ExceptionInfo;

typedef struct {
    s32 f00;
    s32 catch_pcoffset;
    s32 cinfo_ref;
} ex_catchblock;

typedef struct {
    void *location;
    void *typeinfo;
    void *dtor;
    void *sublocation;
    s32 pointercopy;
    void *stacktop;
} CatchInfo;

void func_020e3700(ThrowContext *context, ExceptionInfo *info, char *catcher);
void func_020e4bd8(ThrowContext *context, ExceptionInfo *info, char *target);

void func_020e4188(ThrowContext *context, ExceptionInfo *info, ex_catchblock *catchblock, char *catcher) {
    CatchInfo *catchinfo;

    func_020e3700(context, info, catcher);
    goto setup; // FAKE: post-unwind code must start a new block while scheduling (keeps the catcher arg move ahead of the
                // context save)
done:
    return;
setup:
    catchinfo           = (CatchInfo *) &context->FP[catchblock->cinfo_ref];
    catchinfo->location = context->location;
    catchinfo->typeinfo = context->throwtype;
    catchinfo->dtor     = context->dtor;
    catchinfo->stacktop = catcher;
    func_020e4bd8(context, info, info->code_start + catchblock->catch_pcoffset);
    goto done; // FAKE: removed after scheduling; the jump lands on the epilogue
}
