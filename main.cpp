#include "htmlogs.h"
#include "htmlogs_templates.h"

int main()
{
	HTMLog log;
	HTMLogCtor( &log, "test_log.html" );
	htmlogs_remake_log( &log );
	htmlogs_print_msg_OK( &log, __FILE__, __PRETTY_FUNCTION__, __LINE__ );
	//htmlogs_print_msg_EVENT( &log, "yellow", "KEK", __FILE__, __PRETTY_FUNCTION__, __LINE__ );
	htmlogs_print_msg_EVENT( &log, "TEST", "some message", __FILE__, __PRETTY_FUNCTION__, __LINE__, "yellow" );

	htmlogs_print_structbegin( &log, "StackTest" );
	htmlogs_print_structparam( &log, "number", 15 );
	htmlogs_print_structparam( &log, "string", "test" );
	htmlogs_print_structparam( &log, "double", 15.7391 );
	htmlogs_print_structparam( &log, "ptr", ( const void* )NULL );
	htmlogs_print_structend( &log );


	HTMLogDtor( &log );
	return 0;
}