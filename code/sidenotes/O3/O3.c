#include "O3.h"

return_t wraeck_havock()
{
    return_t retval;

    int i = 0, j = 1, k = 2;

    retval.i = *(&j-1);
    retval.j = *(&j);
    retval.k = *(&j+1);

    return retval;
}
