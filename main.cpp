#include "htmlogs.h"
#include "htmlogs_templates.h"

int main()
{
	HTMLog log;
	HTMLogCtor( &log, "test_log.html" );
	htmlogs_remake_log( &log );
	htmlogs_print_msg_OK( &log, __FILE__, __PRETTY_FUNCTION__, __LINE__ );
	//htmlogs_print_msg_EVENT( &log, "yellow", "KEK", __FILE__, __PRETTY_FUNCTION__, __LINE__ );
	htmlogs_print_msg_EVENT( &log, "yellow", "TEST", "some message", __FILE__, __PRETTY_FUNCTION__, __LINE__ );

	HTMLogDtor( &log );
	return 0;
}