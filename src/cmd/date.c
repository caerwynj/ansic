#include <u.h>
#include <libc.h>

int uflg, nflg;

int
main(int argc, char *argv[])
{
	ulong now;

	ARGBEGIN{
	case 'n':	nflg = 1; break;
	case 'u':	uflg = 1; break;
	default:	fprint(2, "usage: date [-un] [seconds]\n"); exit(1);
	}ARGEND

	if(argc == 1)
		now = strtoul(*argv, 0, 0);
	else
		now = time(0);

	if(nflg)
		print("%ld\n", now);
	else if(uflg)
		print("%s", asctime(gmtime(&now)));
	else
		print("%s", ctime(&now));
	
	return 0;
}
