#include "m2c.h"

/* Object factory: dispatches resource type IDs to the corresponding allocation and initializer. */
typedef struct Vec3 {
    s32 x, y, z;
} Vec3;

static inline void SetVec(Vec3 *out, s32 x, s32 y, s32 z) {
    out->x = x;
    out->y = y;
    out->z = z;
}

typedef struct Position {
    u8 pad0[0x28];
    Vec3 value;
} Position;

typedef struct Object {
    u8 pad0[8];
    u32 flags;
    u8 pad0c[0x18];
    Position *position;
    u8 pad28[0x180];
    u16 flags1a8;
} Object;

extern void *func_0205e80c(u32 size, s32 heap, s32 alignment);
extern u8 data_0210930c[];
extern u8 func_020917b4(void *);
extern u8 func_02093fa8(s32);
extern void func_0204c594(Position *, Vec3 *);
extern Object *func_02011974(Object *, u32, u32, void *);
extern Object *func_0201d98c(Object *, u32, u32, void *);
extern Object *func_0201dbdc(Object *, u32, u32, void *);
extern Object *func_0201e2ec(Object *, u32, u32, void *);
extern Object *func_0201e754(Object *, u32, u32, void *, s32);
extern Object *func_0201ef28(Object *, u32, u32, void *);
extern Object *func_0201f5d0(Object *, u32, u32, void *);
extern Object *func_0201fb68(Object *, u32, u32, void *);
extern Object *func_0202020c(Object *, u32, u32, void *);
extern Object *func_020207fc(Object *, u32, u32, void *);
extern Object *func_02020ba8(Object *, u32, u32, void *);
extern Object *func_02020f04(Object *, u32, void *);
extern Object *func_020215a0(Object *, u32, u32, void *);
extern Object *func_02021c00(Object *, u32, u32, void *);
extern Object *func_02022138(Object *, u32, u32, void *);
extern Object *func_02022754(Object *, u32, u32, void *);
extern Object *func_02023870(Object *, u32, u32, void *);
extern Object *func_02023c80(Object *, u32, u32, void *);
extern Object *func_020240b0(Object *, u32, u32, void *);
extern Object *func_020243dc(Object *, u32, u32, void *);
extern Object *func_0202526c(Object *, u32, u32, void *);
extern Object *func_020257cc(Object *, u32, u32, void *);
extern Object *func_0202600c(Object *, u32, u32, void *);
extern Object *func_02026464(Object *, u32, u32, void *);

Object *func_02015138(u32 kind, u32 flags, void *transform) {
    Object *obj;

    switch (kind) {
        case 10:
            obj = (Object *) func_0205e80c(0x21c, 0, 4);
            if (obj != 0) {
                obj = func_02020f04(obj, flags, transform);
            }
            break;
        case 11:
        case 12:
        case 13:
        case 36:
        case 37:
        case 98:
        case 273:
        case 288:
        case 357:
        case 393:
        case 394:
        case 395:
            obj = (Object *) func_0205e80c(0x220, 0, 4);
            if (obj != 0) {
                obj = func_0201ef28(obj, kind, flags, transform);
            }
            break;
        case 30:
        case 31:
        case 32:
        case 145:
        case 147:
        case 198:
        case 220:
        case 221:
        case 289:
        case 291:
            obj = (Object *) func_0205e80c(0x218, 0, 4);
            if (obj != 0) {
                obj = func_0201f5d0(obj, kind, flags, transform);
            }
            break;
        case 3:
        case 4:
        case 25:
        case 28:
        case 33:
        case 34:
        case 44:
        case 64:
        case 70:
        case 73:
        case 83:
        case 96:
        case 97:
        case 100:
        case 105:
        case 132:
        case 137:
        case 167:
        case 171:
        case 181:
        case 182:
        case 183:
        case 199:
        case 201:
        case 202:
        case 203:
        case 242:
        case 275:
        case 276:
        case 278:
        case 279:
        case 280:
        case 290:
        case 390:
            obj = (Object *) func_0205e80c(0x220, 0, 4);
            if (obj != 0) {
                obj = func_0201e754(obj, kind, flags, transform, 0);
            }
            break;
        case 274:
            obj = (Object *) func_0205e80c(0x220, 0, 4);
            if (obj != 0) {
                obj = func_0201e754(obj, kind, flags, transform, 1);
            }
            break;
        case 177:
            obj = (Object *) func_0205e80c(0x220, 0, 4);
            if (obj != 0) {
                obj = func_0201fb68(obj, kind, flags, transform);
            }
            break;
        case 87:
        case 379:
        case 386:
        case 389:
            obj = (Object *) func_0205e80c(0x228, 0, 4);
            if (obj != 0) {
                obj = func_0202020c(obj, kind, flags, transform);
            }
            break;
        case 241:
        case 253:
        case 319:
            obj = (Object *) func_0205e80c(0x224, 0, 4);
            if (obj != 0) {
                obj = func_02020ba8(obj, kind, flags, transform);
            }
            break;
        case 178:
        case 218:
        case 333:
        case 353:
            obj = (Object *) func_0205e80c(0x220, 0, 4);
            if (obj != 0) {
                obj = func_0202526c(obj, kind, flags, transform);
            }
            obj->flags |= 0x4000000;
            break;
        case 244:
        case 246:
            obj = (Object *) func_0205e80c(0x230, 0, 4);
            if (obj != 0) {
                obj = func_02023c80(obj, kind, flags, transform);
            }
            break;
        case 113:
        case 114:
        case 115:
        case 141:
        case 169:
        case 170:
        case 179:
        case 180:
        case 204:
        case 206:
        case 208:
        case 210:
        case 215:
        case 216:
        case 217:
        case 227:
        case 250:
        case 251:
        case 252:
        case 308:
        case 310:
        case 311:
        case 321:
        case 334:
        case 356:
        case 360:
        case 361:
        case 362:
        case 363:
        case 364:
        case 365:
        case 366:
        case 367:
        case 368:
            obj = (Object *) func_0205e80c(0x218, 0, 4);
            if (obj != 0) {
                obj = func_020215a0(obj, kind, flags, transform);
            }
            break;
        case 1:
            obj = (Object *) func_0205e80c(0x228, 0, 4);
            if (obj != 0) {
                obj = func_0201dbdc(obj, kind, flags, transform);
            }
            break;
        case 41:
        case 81:
        case 82:
        case 101:
        case 236:
        case 249:
        case 300:
        case 301:
        case 302:
        case 313:
        case 320:
        case 323:
        case 352:
        case 374:
            obj = (Object *) func_0205e80c(0x218, 0, 4);
            if (obj != 0) {
                obj = func_020207fc(obj, kind, flags, transform);
            }
            break;
        case 24:
        case 43:
        case 74:
        case 133:
        case 164:
        case 197:
        case 277:
        case 391:
            obj = (Object *) func_0205e80c(0x23c, 0, 4);
            if (obj != 0) {
                obj = func_020243dc(obj, kind, flags, transform);
            }
            break;
        case 189:
        case 190:
        case 191:
        case 192:
        case 193:
        case 194:
        case 195:
        case 196:
        case 237:
        case 354:
        case 387:
            obj = (Object *) func_0205e80c(0x21c, 0, 4);
            if (obj != 0) {
                obj = func_0202600c(obj, kind, flags, transform);
            }
            break;
        case 46:
        case 47:
        case 94:
        case 144:
        case 234:
        case 235:
        case 327:
            obj = (Object *) func_0205e80c(0x22c, 0, 4);
            if (obj != 0) {
                obj = func_02026464(obj, kind, flags, transform);
            }
            break;
        case 84:
        case 85:
        case 110:
        case 140:
        case 168:
        case 304:
        case 305:
        case 306:
        case 349:
            obj = (Object *) func_0205e80c(0x24c, 0, 4);
            if (obj != 0) {
                obj = func_02022754(obj, kind, flags, transform);
            }
            break;
        case 134:
        case 154:
        case 326:
            obj = (Object *) func_0205e80c(0x218, 0, 4);
            if (obj != 0) {
                obj = func_0201e2ec(obj, kind, flags, transform);
            }
            break;
        case 129:
        case 130:
        case 131:
            obj = (Object *) func_0205e80c(0x218, 0, 4);
            if (obj != 0) {
                obj = func_02021c00(obj, kind, flags, transform);
            }
            if (kind == 129) {
                obj->flags |= 0x4000000;
            }
            break;
        case 228:
        case 229:
            obj = (Object *) func_0205e80c(0x22c, 0, 4);
            if (obj != 0) {
                obj = func_020257cc(obj, kind, flags, transform);
            }
            break;
        case 20:
        case 293:
        case 294:
        case 382:
        case 383:
            obj = (Object *) func_0205e80c(0x224, 0, 4);
            if (obj != 0) {
                obj = func_02023870(obj, kind, flags, transform);
            }
            break;
        case 384:
        case 392:
            obj = (Object *) func_0205e80c(0x228, 0, 4);
            if (obj != 0) {
                obj = func_020240b0(obj, kind, flags, transform);
            }
            break;
        case 331:
        case 332:
            obj = (Object *) func_0205e80c(0x238, 0, 4);
            if (obj != 0) {
                obj = func_02022138(obj, kind, flags, transform);
            }
            break;
        case 259:
        case 260:
        case 262:
            obj = (Object *) func_0205e80c(0x218, 0, 4);
            if (obj != 0) {
                obj = func_0201d98c(obj, kind, flags, transform);
            }
            break;
        case 436:
            obj = (Object *) func_0205e80c(0x218, 0, 4);
            if (obj != 0) {
                obj = func_02011974(obj, kind, flags, transform);
            }
            obj->flags |= 0x4000000;
            break;
        case 27:
            obj = (Object *) func_0205e80c(0x218, 0, 4);
            if (obj != 0) {
                obj = func_02011974(obj, kind, flags, transform);
            }
            if (func_02093fa8(func_020917b4(data_0210930c)) != 0) {
                Position *position = obj->position;
                Vec3 pos;
                SetVec(&pos, position->value.x, position->value.y + 0x28000, position->value.z);
                func_0204c594(position, &pos);
            }
            obj->flags1a8 |= 0x1000;
            break;
        default:
            obj = (Object *) func_0205e80c(0x218, 0, 4);
            if (obj != 0) {
                obj = func_02011974(obj, kind, flags, transform);
            }
            break;
    }
    return obj;
}
