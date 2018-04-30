#include "prototypes.h" 

#define MAXBYTES 80

int main(int argc, char *argv[])
{

    printf("Welcome to the inescapable tomb of unknown origin.\nTry as hard you like, you are not going anywhere.\n");
    printf("Type help to learn more about the game.\n");
    //Main event-service loop
    //Get player input
    //Calculate moves of autonomous events and objects.
    //Update player with precipitable information.
    //Update all other autonomous events
    //Get ready for next player input

    fd_set readfds;
    int    num_readable;
    struct timeval tv;
    int    num_bytes;
    char   buf[MAXBYTES];
    int    fd_stdin;

    fd_stdin = fileno(stdin);

    while(1) {
            FD_ZERO(&readfds);
            FD_SET(fileno(stdin), &readfds);

            tv.tv_sec = 999999999; //wait time
            tv.tv_usec = 0;

            printf("> ");
            fflush(stdout);
            num_readable = select(fd_stdin + 1, &readfds, NULL, NULL, &tv);
            if (num_readable == -1) {
                    fprintf(stderr, "\nError in select : %s\n", strerror(errno));
                    exit(1);
            }
            if (num_readable == 0) {
                    printf("\nPerforming default action after 10 seconds\n");
                    break;  /* since I don't want to test forever */
            } else {
                    num_bytes = read(fd_stdin, buf, MAXBYTES);
                    if (num_bytes < 0) {
                            fprintf(stderr, "\nError on read : %s\n", strerror(errno));
                            exit(1);
                    }
                    command_check(buf); 
                    //printf("\nRead %d bytes\n", num_bytes);
                    break; /* to terminate loop, since I don't process anything */
            }
    }

    return 0;
}
