
#line	2	"/home/ansic/src/cmd/grep/grep.y"
#include	"grep.h"

#line	5	"/home/ansic/src/cmd/grep/grep.y"
typedef union 
{
	int	val;
	char*	str;
	Re2	re;
} YYSTYPE;
extern	int	yyerrflag;
#ifndef	YYMAXDEPTH
#define	YYMAXDEPTH	150
#endif
YYSTYPE	yylval;
YYSTYPE	yyval;
#define	LCLASS	57346
#define	LCHAR	57347
#define	LLPAREN	57348
#define	LRPAREN	57349
#define	LALT	57350
#define	LSTAR	57351
#define	LPLUS	57352
#define	LQUES	57353
#define	LBEGIN	57354
#define	LEND	57355
#define	LDOT	57356
#define	LBAD	57357
#define	LNEWLINE	57358
#define YYEOFCODE 1
#define YYERRCODE 2

#line	115	"/home/ansic/src/cmd/grep/grep.y"


void
yyerror(char *e, ...)
{
	if(filename)
		fprint(2, "grep: %s:%ld: %s\n", filename, lineno, e);
	else
		fprint(2, "grep: %s\n", e);
	exits("syntax");
}

int
yylex(void)
{
	char *q, *eq;
	int c, s;

	if(peekc) {
		s = peekc;
		peekc = 0;
		return s;
	}
	c = getrec();
	if(literal) {
		if(c != 0 && c != '\n') {
			yylval.val = c;
			return LCHAR;
		}
		literal = 0;
	}
	switch(c) {
	default:
		yylval.val = c;
		s = LCHAR;
		break;
	case '\\':
		c = getrec();
		yylval.val = c;
		s = LCHAR;
		if(c == '\n')
			s = LNEWLINE;
		break;
	case '[':
		goto getclass;
	case '(':
		s = LLPAREN;
		break;
	case ')':
		s = LRPAREN;
		break;
	case '|':
		s = LALT;
		break;
	case '*':
		s = LSTAR;
		break;
	case '+':
		s = LPLUS;
		break;
	case '?':
		s = LQUES;
		break;
	case '^':
		s = LBEGIN;
		break;
	case '$':
		s = LEND;
		break;
	case '.':
		s = LDOT;
		break;
	case 0:
		peekc = -1;
	case '\n':
		s = LNEWLINE;
		break;
	}
	return s;

getclass:
	q = u.string;
	eq = q + nelem(u.string) - 5;
	c = getrec();
	if(c == '^') {
		q[0] = '^';
		q[1] = '\n';
		q[2] = '-';
		q[3] = '\n';
		q += 4;
		c = getrec();
	}
	for(;;) {
		if(q >= eq)
			error("class too long");
		if(c == ']' || c == 0)
			break;
		if(c == '\\') {
			*q++ = c;
			c = getrec();
			if(c == 0)
				break;
		}
		*q++ = c;
		c = getrec();
	}
	*q = 0;
	if(c == 0)
		return LBAD;
	yylval.str = u.string;
	return LCLASS;
}
static	const	short	yyexca[] =
{-1, 1,
	1, -1,
	-2, 0,
};
#define	YYNPROD	23
#define	YYPRIVATE 57344
#define	YYLAST	43
static	const	short	yyact[] =
{
   7,  13,   9,  14,  16,   3,   5,  19,   6,  10,
  11,  12,  17,  25,  13,   9,  14,   4,  18,   5,
  15,  24,  10,  11,  12,   8,  26,  19,   1,  13,
   9,  14,  23,  20,  21,  22,  27,  10,  11,  12,
  28,  17,   2
};
static	const	short	yypact[] =
{
  10,-1000, -12,-1000,   4,-1000,  25,  24,-1000,-1000,
-1000,-1000,-1000,-1000,  25,  -3,-1000,  25,  25,  24,
-1000,-1000,-1000,  33,-1000,-1000,  25,   4,-1000
};
static	const	short	yypgo[] =
{
   0,  42,  28,   5,  17,   8,   0,  25,  20,  18
};
static	const	short	yyr1[] =
{
   0,   2,   1,   1,   3,   9,   3,   4,   4,   5,
   5,   6,   6,   6,   6,   7,   7,   7,   7,   7,
   7,   8,   8
};
static	const	short	yyr2[] =
{
   0,   2,   1,   3,   1,   0,   3,   1,   3,   1,
   2,   1,   2,   2,   2,   1,   1,   1,   1,   1,
   3,   1,   2
};
static	const	short	yychk[] =
{
-1000,  -2,  -1,  -3,  -4,   9,  -5,  -6,  -7,   5,
  12,  13,  14,   4,   6,  -8,  16,   8,  -9,  -6,
   9,  10,  11,  -4,  -3,  16,  -5,  -4,   7
};
static	const	short	yydef[] =
{
   0,  -2,   0,   2,   4,   5,   7,   9,  11,  15,
  16,  17,  18,  19,   0,   1,  21,   0,   0,  10,
  12,  13,  14,   0,   3,  22,   8,   6,  20
};
static	const	short	yytok1[] =
{
   1
};
static	const	short	yytok2[] =
{
   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,
  12,  13,  14,  15,  16
};
static	const	long	yytok3[] =
{
   0
};
#define YYFLAG 		-1000
#define YYERROR		goto yyerrlab
#define YYACCEPT	return(0)
#define YYABORT		return(1)
#define	yyclearin	yychar = -1
#define	yyerrok		yyerrflag = 0

#ifdef	yydebug
#include	"y.debug"
#else
#define	yydebug		0
static	const	char*	yytoknames[1];		/* for debugging */
static	const	char*	yystates[1];		/* for debugging */
#endif

/*	parser for yacc output	*/
#ifdef YYARG
#define	yynerrs		yyarg->yynerrs
#define	yyerrflag	yyarg->yyerrflag
#define yyval		yyarg->yyval
#define yylval		yyarg->yylval
#else
int	yynerrs = 0;		/* number of errors */
int	yyerrflag = 0;		/* error recovery flag */
#endif

extern	int	fprint(int, char*, ...);
extern	int	sprint(char*, char*, ...);

static const char*
yytokname(int yyc)
{
	static char x[10];

	if(yyc > 0 && yyc <= sizeof(yytoknames)/sizeof(yytoknames[0]))
	if(yytoknames[yyc-1])
		return yytoknames[yyc-1];
	sprint(x, "<%d>", yyc);
	return x;
}

static const char*
yystatname(int yys)
{
	static char x[10];

	if(yys >= 0 && yys < sizeof(yystates)/sizeof(yystates[0]))
	if(yystates[yys])
		return yystates[yys];
	sprint(x, "<%d>\n", yys);
	return x;
}

static long
#ifdef YYARG
yylex1(struct Yyarg *yyarg)
#else
yylex1(void)
#endif
{
	long yychar;
	const long *t3p;
	int c;

#ifdef YYARG	
	yychar = yylex(yyarg);
#else
	yychar = yylex();
#endif
	if(yychar <= 0) {
		c = yytok1[0];
		goto out;
	}
	if(yychar < sizeof(yytok1)/sizeof(yytok1[0])) {
		c = yytok1[yychar];
		goto out;
	}
	if(yychar >= YYPRIVATE)
		if(yychar < YYPRIVATE+sizeof(yytok2)/sizeof(yytok2[0])) {
			c = yytok2[yychar-YYPRIVATE];
			goto out;
		}
	for(t3p=yytok3;; t3p+=2) {
		c = t3p[0];
		if(c == yychar) {
			c = t3p[1];
			goto out;
		}
		if(c == 0)
			break;
	}
	c = 0;

out:
	if(c == 0)
		c = yytok2[1];	/* unknown char */
	if(yydebug >= 3)
		fprint(2, "lex %.4lux %s\n", yychar, yytokname(c));
	return c;
}

int
#ifdef YYARG
yyparse(struct Yyarg *yyarg)
#else
yyparse(void)
#endif
{
	struct
	{
		YYSTYPE	yyv;
		int	yys;
	} yys[YYMAXDEPTH], *yyp, *yypt;
	const short *yyxi;
	int yyj, yym, yystate, yyn, yyg;
	long yychar;
#ifndef YYARG
	YYSTYPE save1, save2;
	int save3, save4;

	save1 = yylval;
	save2 = yyval;
	save3 = yynerrs;
	save4 = yyerrflag;
#endif

	yystate = 0;
	yychar = -1;
	yynerrs = 0;
	yyerrflag = 0;
	yyp = &yys[0];
	yyp--;
	goto yystack;

ret0:
	yyn = 0;
	goto ret;

ret1:
	yyn = 1;
	goto ret;

ret:
#ifndef YYARG
	yylval = save1;
	yyval = save2;
	yynerrs = save3;
	yyerrflag = save4;
#endif
	return yyn;

yystack:
	/* put a state and value onto the stack */
	if(yydebug >= 4)
		fprint(2, "char %s in %s", yytokname(yychar), yystatname(yystate));

	yyp++;
	if(yyp >= &yys[YYMAXDEPTH]) {
		yyerror("yacc stack overflow");
		goto ret1;
	}
	yyp->yys = yystate;
	yyp->yyv = yyval;

yynewstate:
	yyn = yypact[yystate];
	if(yyn <= YYFLAG)
		goto yydefault; /* simple state */
	if(yychar < 0)
#ifdef YYARG
		yychar = yylex1(yyarg);
#else
		yychar = yylex1();
#endif
	yyn += yychar;
	if(yyn < 0 || yyn >= YYLAST)
		goto yydefault;
	yyn = yyact[yyn];
	if(yychk[yyn] == yychar) { /* valid shift */
		yychar = -1;
		yyval = yylval;
		yystate = yyn;
		if(yyerrflag > 0)
			yyerrflag--;
		goto yystack;
	}

yydefault:
	/* default state action */
	yyn = yydef[yystate];
	if(yyn == -2) {
		if(yychar < 0)
#ifdef YYARG
		yychar = yylex1(yyarg);
#else
		yychar = yylex1();
#endif

		/* look through exception table */
		for(yyxi=yyexca;; yyxi+=2)
			if(yyxi[0] == -1 && yyxi[1] == yystate)
				break;
		for(yyxi += 2;; yyxi += 2) {
			yyn = yyxi[0];
			if(yyn < 0 || yyn == yychar)
				break;
		}
		yyn = yyxi[1];
		if(yyn < 0)
			goto ret0;
	}
	if(yyn == 0) {
		/* error ... attempt to resume parsing */
		switch(yyerrflag) {
		case 0:   /* brand new error */
			yyerror("syntax error");
			if(yydebug >= 1) {
				fprint(2, "%s", yystatname(yystate));
				fprint(2, "saw %s\n", yytokname(yychar));
			}
			goto yyerrlab;
		yyerrlab:
			yynerrs++;

		case 1:
		case 2: /* incompletely recovered error ... try again */
			yyerrflag = 3;

			/* find a state where "error" is a legal shift action */
			while(yyp >= yys) {
				yyn = yypact[yyp->yys] + YYERRCODE;
				if(yyn >= 0 && yyn < YYLAST) {
					yystate = yyact[yyn];  /* simulate a shift of "error" */
					if(yychk[yystate] == YYERRCODE)
						goto yystack;
				}

				/* the current yyp has no shift onn "error", pop stack */
				if(yydebug >= 2)
					fprint(2, "error recovery pops state %d, uncovers %d\n",
						yyp->yys, (yyp-1)->yys );
				yyp--;
			}
			/* there is no state on the stack with an error shift ... abort */
			goto ret1;

		case 3:  /* no shift yet; clobber input char */
			if(yydebug >= 2)
				fprint(2, "error recovery discards %s\n", yytokname(yychar));
			if(yychar == YYEOFCODE)
				goto ret1;
			yychar = -1;
			goto yynewstate;   /* try again in the same state */
		}
	}

	/* reduction by production yyn */
	if(yydebug >= 2)
		fprint(2, "reduce %d in:\n\t%s", yyn, yystatname(yystate));

	yypt = yyp;
	yyp -= yyr2[yyn];
	yyval = (yyp+1)->yyv;
	yym = yyn;

	/* consult goto table to find next state */
	yyn = yyr1[yyn];
	yyg = yypgo[yyn];
	yyj = yyg + yyp->yys + 1;

	if(yyj >= YYLAST || yychk[yystate=yyact[yyj]] != -yyn)
		yystate = yyact[yyg];
	switch(yym) {
		
case 1:
#line	22	"/home/ansic/src/cmd/grep/grep.y"
{
		yyval.re.beg = ral(Tend);
		yyval.re.end = yyval.re.beg;
		yyval.re = re2cat(re2star(re2or(re2char(0x00, '\n'-1), re2char('\n'+1, 0xff))), yyval.re);
		yyval.re = re2cat(yypt[-1].yyv.re, yyval.re);
		yyval.re = re2cat(re2star(re2char(0x00, 0xff)), yyval.re);
		topre = yyval.re;
	} break;
case 3:
#line	34	"/home/ansic/src/cmd/grep/grep.y"
{
		yyval.re = re2or(yypt[-2].yyv.re, yypt[-0].yyv.re);
	} break;
case 5:
#line	40	"/home/ansic/src/cmd/grep/grep.y"
{ literal = 1; } break;
case 6:
#line	41	"/home/ansic/src/cmd/grep/grep.y"
{
		yyval.re = yypt[-0].yyv.re;
	} break;
case 8:
#line	48	"/home/ansic/src/cmd/grep/grep.y"
{
		yyval.re = re2or(yypt[-2].yyv.re, yypt[-0].yyv.re);
	} break;
case 10:
#line	55	"/home/ansic/src/cmd/grep/grep.y"
{
		yyval.re = re2cat(yypt[-1].yyv.re, yypt[-0].yyv.re);
	} break;
case 12:
#line	62	"/home/ansic/src/cmd/grep/grep.y"
{
		yyval.re = re2star(yypt[-1].yyv.re);
	} break;
case 13:
#line	66	"/home/ansic/src/cmd/grep/grep.y"
{
		yyval.re.beg = ral(Talt);
		patchnext(yypt[-1].yyv.re.end, yyval.re.beg);
		yyval.re.beg->u.alt = yypt[-1].yyv.re.beg;
		yyval.re.end = yyval.re.beg;
		yyval.re.beg = yypt[-1].yyv.re.beg;
	} break;
case 14:
#line	74	"/home/ansic/src/cmd/grep/grep.y"
{
		yyval.re.beg = ral(Talt);
		yyval.re.beg->u.alt = yypt[-1].yyv.re.beg;
		yyval.re.end = yypt[-1].yyv.re.end;
		appendnext(yyval.re.end,  yyval.re.beg);
	} break;
case 15:
#line	83	"/home/ansic/src/cmd/grep/grep.y"
{
		yyval.re.beg = ral(Tclass);
		yyval.re.beg->u.x.lo = yypt[-0].yyv.val;
		yyval.re.beg->u.x.hi = yypt[-0].yyv.val;
		yyval.re.end = yyval.re.beg;
	} break;
case 16:
#line	90	"/home/ansic/src/cmd/grep/grep.y"
{
		yyval.re.beg = ral(Tbegin);
		yyval.re.end = yyval.re.beg;
	} break;
case 17:
#line	95	"/home/ansic/src/cmd/grep/grep.y"
{
		yyval.re.beg = ral(Tend);
		yyval.re.end = yyval.re.beg;
	} break;
case 18:
#line	100	"/home/ansic/src/cmd/grep/grep.y"
{
		yyval.re = re2class("^\n");
	} break;
case 19:
#line	104	"/home/ansic/src/cmd/grep/grep.y"
{
		yyval.re = re2class(yypt[-0].yyv.str);
	} break;
case 20:
#line	108	"/home/ansic/src/cmd/grep/grep.y"
{
		yyval.re = yypt[-1].yyv.re;
	} break;
	}
	goto yystack;  /* stack new state and value */
}
