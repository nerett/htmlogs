#include "htmlogs.h"


/*--------------------------FUNCTION------------------------------------------*/
void HTMLogCtor( HTMLog* some_log, const char* log_filename )
{
	assert( some_log );

	if( some_log->log_filename ) //если уже инициализирован
	{
		return;
	}

	char* log_filename_buffer = strdup( log_filename );
	if( !log_filename_buffer )
	{
		return;
	}

	some_log->log_filename = log_filename_buffer;
	some_log->logfile = NULL;
}


/*--------------------------FUNCTION------------------------------------------*/
void HTMLogDtor( HTMLog* some_log )
{
	assert( some_log );

	if( !some_log->log_filename )
	{
		return;
	}
	free( some_log->log_filename );
	some_log->logfile = NULL;
}


/*--------------------------FUNCTION------------------------------------------*/
static void htmlogs_logfile_open( HTMLog* some_log, const char* mode )
{
	assert( some_log ); //!TODO больше проверок

	FILE* logfile_buffer = fopen( some_log->log_filename, mode );
	if( !logfile_buffer )
	{
		//error_output( error_variable, FOPEN_ERROR );
		return;
	}

	some_log->logfile = logfile_buffer;
}


/*--------------------------FUNCTION------------------------------------------*/
void htmlogs_logfile_close( HTMLog* some_log )
{
	assert(  some_log );

	if( !some_log->logfile )
	{
		return;
	}

	fclose( some_log->logfile );
}


/*--------------------------FUNCTION------------------------------------------*/
void htmlogs_logfile_keep( HTMLog* some_log )
{
	assert( some_log );

	if( !some_log->logfile )
	{
		htmlogs_logfile_open( some_log, "a" );
	}
}


/*--------------------------FUNCTION------------------------------------------*/
void htmlogs_remake_log( HTMLog* some_log )
{
	assert( some_log );

	if( some_log->logfile )
	{
		htmlogs_logfile_close( some_log );
	}
	htmlogs_logfile_open( some_log, "w" );

	fputs( "<pre>", some_log->logfile );
	//fclose( logfile );
}