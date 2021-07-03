#include <stdio.h>
#include <string.h>

//#define __STDC_FORMAT_MACROS

#include <inttypes.h>

#include "main.h"
#include "logging/log.h"
#include "cmd_handler/cmd_hndlr.h"

int main(void){
#if 0
	log_trace("C program to learn some C basics");
	log_debug("Build date = %s, Time = %s", __DATE__, __TIME__);
	log_info("This is test information log");
	log_warn("This is test warning log");
	log_error("This is test error log");
	log_fatal("This is test fatal log");
#endif

	while(1)
	{
		run_command_handler();
	}

    return 0;
}



