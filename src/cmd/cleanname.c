#include <u.h>
#include <libc.h>

int
main(int argc, char **argv)
{
	char *dir;
	char *name;
	int i;

	dir = nil;
	ARGBEGIN{
	case 'd':
		if((dir=ARGF()) == nil)
			goto Usage;
		break;
	default:
		goto Usage;
	}ARGEND;

	if(argc < 1) {
	Usage:
		fprint(2, "usage: cleanname [-d pwd] name...\n");
		return 1;
	}

	for(i=0; i<argc; i++) {
		if(dir == nil || argv[i][0] == '/') {
			cleanname(argv[i]);
			print("%s\n", argv[i]);
		} else {
			name = malloc(strlen(argv[i])+1+strlen(dir)+1);
			if(name == nil) {
				fprint(2, "cleanname: out of memory\n");
				return 1;
			}
			sprint(name, "%s/%s", dir, argv[i]);
			cleanname(name);
			print("%s\n", name);
			free(name);
		}
	}
	return 0;
}
