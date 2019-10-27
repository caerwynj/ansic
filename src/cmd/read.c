#include <u.h>
#include <libc.h>

int	multi;
int	nlines;
char	*status = nil;

int
line(int fd, char *file)
{
	char c;
	int m, n, nalloc;
	char *buf;

	nalloc = 0;
	buf = nil;
	for(m=0; ; ){
		n = read(fd, &c, 1);
		if(n < 0){
			fprint(2, "read: error reading %s: %r\n", file);
			exit(1);
		}
		if(n == 0){
			if(m == 0)
				status = "eof";
			break;
		}
		if(m == nalloc){
			nalloc += 1024;
			buf = realloc(buf, nalloc);
			if(buf == nil){
				fprint(2, "read: malloc error: %r\n");
				exit(1);
			}
		}
		buf[m++] = c;
		if(c == '\n')
			break;
	}
	if(m > 0)
		write(1, buf, m);
	free(buf);
	return m;
}

void
lines(int fd, char *file)
{
	do{
		if(line(fd, file) == 0)
			break;
	}while(multi || --nlines>0);
}

int
main(int argc, char *argv[])
{
	int i, fd;
	char *s;

	ARGBEGIN{
	case 'm':
		multi = 1;
		break;
	case 'n':
		s = ARGF();
		if(s){
			nlines = atoi(s);
			break;
		}
		/* fall through */
	default:
		fprint(2, "usage: read [-m] [-n nlines] [files...]\n");
		return 1;
	}ARGEND

	if(argc == 0)
		lines(0, "<stdin>");
	else
		for(i=0; i<argc; i++){
			fd = open(argv[i], OREAD);
			if(fd < 0){
				fprint(2, "read: can't open %s: %r\n", argv[i]);
				return 1;
			}
			lines(fd, argv[i]);
			close(fd);
		}

	return(status?1:0);
}
