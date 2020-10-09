#include "lib9.h"

char *
getwd(char *buf, int size)
{
	return getcwd(buf, size);
}
