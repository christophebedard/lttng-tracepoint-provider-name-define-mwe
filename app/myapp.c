#include "tp.h"


int main()
{
    while (1)
    {
        tracepoint(my_provider, my_tracepoint_does_not_work, NULL, 42);
        // tracepoint(my_provider, my_tracepoint_works, NULL, 42);
    }

    return 0;
}