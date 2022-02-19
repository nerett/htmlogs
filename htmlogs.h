#ifndef HTMLogS_H_INCLUDED
#define HTMLogS_H_INCLUDED


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>


struct HTMLog
{
	char* log_filename = NULL;
	FILE* logfile = NULL;
};


/*--------------------------PROTOTYPE-----------------------------------------*/
void HTMLogCtor( HTMLog* some_log, const char* log_filename );
void HTMLogDtor( HTMLog* some_log );

static void htmlogs_logfile_open( HTMLog* some_log );
void htmlogs_logfile_keep( HTMLog* some_log );
void htmlogs_logfile_close( HTMLog* some_log );

void htmlogs_remake_log( HTMLog* some_log );


#endif //HTMLogS_H_INCLUDED