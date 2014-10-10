//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "syslog.h"

#define	INTERNAL_NOPRI	0x10	// the "no priority" priority
				// mark "facility"
#define	INTERNAL_MARK	LOG_MAKEPRI(LOG_NFACILITIES, 0)

CODE prioritynames[] =
  {
    { "alert", LOG_ALERT },
    { "crit", LOG_CRIT },
    { "debug", LOG_DEBUG },
    { "emerg", LOG_EMERG },
    { "err", LOG_ERR },
    { "error", LOG_ERR },		/* DEPRECATED */
    { "info", LOG_INFO },
    { "none", INTERNAL_NOPRI },	/* INTERNAL */
    { "notice", LOG_NOTICE },
    { "panic", LOG_EMERG },		/* DEPRECATED */
    { "warning", LOG_WARNING },
    { "warn", LOG_WARNING },    /* DEPRECATED */
    { NULL, -1 }
  };


CODE facilitynames[] =
  {
    { "auth", LOG_AUTH },
    { "authpriv", LOG_AUTHPRIV },
    { "cron", LOG_CRON },
    { "daemon", LOG_DAEMON },
    { "ftp", LOG_FTP },
    { "kern", LOG_KERN },
    { "lpr", LOG_LPR },
    { "mail", LOG_MAIL },
    { "mark", INTERNAL_MARK },		/* INTERNAL */
    { "news", LOG_NEWS },
    { "security", LOG_AUTH },		/* DEPRECATED */
    { "syslog", LOG_SYSLOG },
    { "user", LOG_USER },
    { "uucp", LOG_UUCP },
    { "local0", LOG_LOCAL0 },
    { "local1", LOG_LOCAL1 },
    { "local2", LOG_LOCAL2 },
    { "local3", LOG_LOCAL3 },
    { "local4", LOG_LOCAL4 },
    { "local5", LOG_LOCAL5 },
    { "local6", LOG_LOCAL6 },
    { "local7", LOG_LOCAL7 },
    { NULL, -1 }
  };

//---------------------------------------------------------------------------
const char * getcodetext(int value, CODE * codetable)
{
	CODE *i;
	if (value >= 0)
		for (i = codetable; i->c_val != -1; i++)
			if (i->c_val == value)
				return (i->c_name);
	return "<unknown>";
};
//---------------------------------------------------------------------------
int gettextcode(const char * value, CODE * codetable)
{
	CODE *i;
	if (value)
		for (i = codetable; i->c_val != -1; i++)
			if (strcmp(i->c_name, value)==0)
				return (i->c_val);
	return -1;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
