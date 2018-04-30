#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <gtk/gtk.h>

#include "fifo.h"

static char *FIFOfilename = "/tmp/sqrl.FIFO";


/**
 * The main entry point of this application.
 */
int main (int argc, char *argv[])
{
  // We have a URL to authenticate to.
  // Try sending it to the server via FIFO.
  //
  int fifofd = open(FIFOfilename, O_WRONLY);
  if (fifofd < 0)
  {
    // There's no FIFO.
    //
    log_error("couldn't open FIFO at %s for write-only\n", FIFOfilename);

    fifofd = open(FIFOfilename, O_WRONLY);
    if (fifofd < 0)
    {
      log_error("Failed to open FIFO the second time.  Exiting.\n");
      return(-1);
    }
  }

  log_info("sending message to server: %s\n", argv[1]);
  write(fifofd, argv[1], strlen(argv[1]));
  close(fifofd);
}

