#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

static pid_t pid = -1;

static FILE *__debug = 0;
void dbg(const char *msg, ...);
void dbg(const char *msg, ...)
{
    if (pid == -1)
        pid = getpid();

    if (!__debug) {
        __debug = fopen("/var/log/debug.txt", "ab");
        fprintf(__debug, "===============================================================================\n");
    }

    struct timeval tv;
    gettimeofday(&tv, NULL);
    char time[64];
    strftime(time, sizeof(time), "%y.%m.%d %H:%M:%S", localtime(&tv.tv_sec));
    fprintf(__debug, "%s.%06lu [%d]", time, tv.tv_usec, pid);

    va_list args;
    va_start(args, msg);
    vfprintf(__debug, msg, args);
    va_end(args);

    fprintf(__debug, "\n");

    fflush(__debug);
}
