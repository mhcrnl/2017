#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int fd = -1;

    // Always Reset errno before use.
    errno = 0;

    // Make sure you are opening a file that does not exist
    fd = open("abcd",O_RDONLY);
    if(fd == -1)
    {
        // Seems like some error occured. Use strerror to print it
        printf("\nStrerror() says -> [%s]\n",(char*)strerror(errno));
        return 1;
    }
    return 0;
}
