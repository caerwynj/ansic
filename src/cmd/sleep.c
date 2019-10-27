#include <u.h>
#include <libc.h>

int
main(int argc, char *argv[])
{
	long secs;

	if(argc>1)
		for(secs = atol(argv[1]); secs > 0; secs--)
			sleep(1000);
	return 0;
}
