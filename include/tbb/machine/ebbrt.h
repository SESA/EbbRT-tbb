#ifndef __TBB_machine_H
#error Do not #include this internal file directly; use public TBB headers instead.
#endif

#include <ebbrt/Debug.h>

static inline int __TBB_Yield() {
  return 0;
}
