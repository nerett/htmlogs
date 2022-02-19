#ifndef HTMLOGS_TEMPLATES_H_INCLUDED
#define HTMLOGS_TEMPLATES_H_INCLUDED


#include "htmlogs.h"


/*--------------------------PROTOTYPE-----------------------------------------*/
void htmlogs_print_plaintext( HTMLog* some_log, const char* printstring );
void htmlogs_print_tagopen( HTMLog* some_log, const char* tag, const char* params );
void htmlogs_print_tagclose( HTMLog* some_log, const char* tag );
void htmlogs_print_tagged_text( HTMLog* some_log, const char* tag, const char* params, const char* printstring );
void htmlogs_print_colored_text( HTMLog* some_log, const char* printstring, const char* color );
void htmlogs_print_messagename( HTMLog* some_log, const char* message_name, const char* color );
void htmlogs_print_msg_OK( HTMLog* some_log, const char* msg_filename, const char* msg_function, int msg_line );
void htmlogs_print_msg_ERROR( HTMLog* some_log, const int error_code, const char* msg_filename, const char* msg_function, int msg_line );
void htmlogs_print_msg_EVENT( HTMLog* some_log, const char* color, const char* event_type, const char* message, const char* msg_filename, const char* msg_function, int msg_line );


#endif //HTMLOGS_TEMPLATES_H_INCLUDED