
// Provide fake header guard for cpplint
#undef MYTP__TP_H_
#ifndef MYTP__TP_H_
#define MYTP__TP_H_

#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER my_provider

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "tp.h"

#if !defined(_MYTP__TP_H_) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _MYTP__TP_H_

#include <lttng/tracepoint.h>

#include <stdint.h>

// Does not work

TRACEPOINT_EVENT_CLASS(
  TRACEPOINT_PROVIDER,
  my_class,
  TP_ARGS(
    const void *, some_arg,
    int, some_number
  ),
  TP_FIELDS(
    ctf_integer_hex(const void *, whatever, some_arg)
    ctf_integer(int, number, some_number)
  )
)

TRACEPOINT_EVENT_INSTANCE(
  TRACEPOINT_PROVIDER,
  my_class,
  my_tracepoint_does_not_work,
  TP_ARGS(
    const void *, some_arg,
    int, some_number
  )
)

// Works

// TRACEPOINT_EVENT_CLASS(
//   my_provider,
//   my_class,
//   TP_ARGS(
//     const void *, some_arg,
//     int, some_number
//   ),
//   TP_FIELDS(
//     ctf_integer_hex(const void *, whatever, some_arg)
//     ctf_integer(int, number, some_number)
//   )
// )

// TRACEPOINT_EVENT_INSTANCE(
//   my_provider,
//   my_class,
//   my_tracepoint_works,
//   TP_ARGS(
//     const void *, some_arg,
//     int, some_number
//   )
// )

#endif  // _MYTP__TP_H_

#include <lttng/tracepoint-event.h>

#endif  // MYTP__TP_H_
