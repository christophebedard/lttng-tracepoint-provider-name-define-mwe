# lttng-tracepoint-provider-name-define-mwe

Minimal working example (MWE) reproducing a `lttng-ust` bug: cannot use a `#define`d `TRACEPOINT_PROVIDER` name with `TRACEPOINT_EVENT_{CLASS,INSTANCE}()` macros

## How to reproduce

Install:

* `lttng-ust`

(Try to) compile:

```shell
$ git clone https://github.com/christophebedard/lttng-tracepoint-provider-name-define-mwe
$ cd lttng-tracepoint-provider-name-define-mwe
$ make
```

It should fail on `app`.

```
gcc -I/home/chris/lttng-tracepoint-provider-name-define-mwe/app/../lib -c myapp.c
gcc -o myapp myapp.o -L/home/chris/lttng-tracepoint-provider-name-define-mwe/app/../lib -Wl,-rpath=/home/chris/lttng-tracepoint-provider-name-define-mwe/app/../lib -lmytps -ldl
/usr/bin/ld: /home/chris/lttng-tracepoint-provider-name-define-mwe/app/../lib/libmytps.so: undefined reference to `__tracepoint_provider_mismatch_TRACEPOINT_PROVIDER'
collect2: error: ld returned 1 exit status
make: *** [Makefile:9: myapp] Error 1
```

However, if we switch to the code that uses the `my_provider` name itself directly (in [`lib/tp.h`](lib/tp.h) and [`app/myapp.c`](app/myapp.c)), it works fine.

Looking at the preprocessor output for `lib` confirms the problem and gives a hint as to why it's happening (on top of the error message we get when compiling):

```shell
$ cd lib/
$ make preprocessor_output
$ cat preprocessor_output
```
