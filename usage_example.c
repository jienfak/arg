#include <stdio.h>
#include "arg.h"
#include <stdlib.h>

char *argv0;

void
abort(void)
{
	puts("\"abort()\" function is called.");
	exit(1);
}

int
main(int argc, char *argv[])
{
	char *opt_a;
	char *opt_b;
	ARGBEGIN {
	case 'a' :
		puts("Got 'a' option char.");
		opt_a = EARGF(0) ;
		printf("opt_a = \"%s\"\n", opt_a);
	break;
	case 'b' :
		puts("Got 'b' option char.");
		opt_b = ARGF() ;
		if(opt_b){
			printf("opt_b = \"%s\" ;\n", opt_b);
		}else{
			puts("No argument for opt_b.");
		}
		
	break;
	default:
		puts("Got unrecognized option.");
	} ARGEND
	for( int i=0 ; i<argc ; ++i ){
		printf("argv[%d] = \"%s\" ;\n", i, argv[i]);
	}
	return 0 ;
}
