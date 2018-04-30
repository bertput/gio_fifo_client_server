#include <gtk/gtk.h>

#include "fifo.h"



/**
 * The main entry point of this application.
 */
int main (int argc, char *argv[])
{
  GMainLoop *g_main_loop = g_main_loop_new(NULL, TRUE);

  fifo_new();

  g_main_loop_run(g_main_loop);
}

