#include "metaphire.h"

i8
journal_init(Journal *j)
{
	i8 ret = EXIT_ERROR;

	GUARD_NON_NULL(j);
	j = malloc(sizeof(Journal));
	GUARD_NULL(j);

	ret = EXIT_SUCCESS;
cleanup:
	return ret;
}
