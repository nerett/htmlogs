#include "htmlogs.h"


/*--------------------------FUNCTION------------------------------------------*/
void htmlogs_print_plaintext( HTMLog* some_log, const char* printstring )
{
	assert( some_log );

	htmlogs_logfile_keep( some_log );

	fprintf( some_log->logfile, "%s", printstring );
}


/*--------------------------FUNCTION------------------------------------------*/
void htmlogs_print_tagopen( HTMLog* some_log, const char* tag, const char* params )
{
	assert( some_log );

	htmlogs_logfile_keep( some_log );

	fprintf( some_log->logfile, "<%s %s>", tag, params );
}


/*--------------------------FUNCTION------------------------------------------*/
void htmlogs_print_tagclose( HTMLog* some_log, const char* tag )
{
	assert( some_log );

	htmlogs_logfile_keep( some_log );

	fprintf( some_log->logfile, "<%s/>", tag );
}


/*--------------------------FUNCTION------------------------------------------*/
void htmlogs_print_tagged_text( HTMLog* some_log, const char* tag, const char* params, const char* printstring )
{
	assert( some_log );

	htmlogs_logfile_keep( some_log );

	htmlogs_print_tagopen( some_log, tag, params );
	htmlogs_print_plaintext( some_log, printstring );
	htmlogs_print_tagclose( some_log, tag );
}


/*--------------------------FUNCTION------------------------------------------*/
void htmlogs_print_colored_text( HTMLog* some_log, const char* printstring, const char* color )
{
	assert( some_log );

	htmlogs_logfile_keep( some_log );
	
	fprintf( some_log->logfile, "<font color=\"%s\">%s</font>", color, printstring );
}


/*--------------------------FUNCTION------------------------------------------*/
void htmlogs_print_messagename( HTMLog* some_log, const char* message_name, const char* color )
{
	assert( some_log );

	htmlogs_logfile_keep( some_log );
	
	fprintf( some_log->logfile, "<font color=\"%s\">[%s]</font>", color, message_name );
}


/*--------------------------FUNCTION------------------------------------------*/
void htmlogs_print_msg_OK( HTMLog* some_log, const char* msg_filename, const char* msg_function, int msg_line )
{
	assert( some_log );

	htmlogs_logfile_keep( some_log );
	
	fprintf( some_log->logfile, "<font color=\"green\">[OK] at function %s at %s:%d</font>\n", msg_function, msg_filename, msg_line );
}


/*--------------------------FUNCTION------------------------------------------*/
void htmlogs_print_msg_ERROR( HTMLog* some_log, const int error_code, const char* msg_filename, const char* msg_function, int msg_line )
{
	assert( some_log );

	htmlogs_logfile_keep( some_log );
	
	fprintf( some_log->logfile, "<font color=\"red\">[ERROR] error_code = %d at function %s at %s:%d</font>\n", error_code, msg_function, msg_filename, msg_line );
}


/*--------------------------FUNCTION------------------------------------------*/
void htmlogs_print_msg_EVENT( HTMLog* some_log, const char* color, const char* event_type, const char* message, const char* msg_filename, const char* msg_function, int msg_line )
{
	assert( some_log );

	htmlogs_logfile_keep( some_log );
	
	fprintf( some_log->logfile, "<font color=\"%s\">[%s] %s at function %s at %s:%d</font>\n", color, event_type, message, msg_function, msg_filename, msg_line );
}