#include "tp.h"


int main()
{
    while (1)
    {
        // tracepoint(my_provider, my_tracepoint_does_not_work, NULL);
        tracepoint(my_provider, my_tracepoint_works, NULL);
    }

    return 0;
}