# README for test FIFO client and server

## Introduction

When I tried to use g_io_channels with FIFO files in sqrl, I found that one CPU would be pegged immediately a request was received over the FIFO.  I don't know why but I'm pretty sure it's related to g_io_channels.  To prove it I built this test client and server.

## Client

The client simply opens the FIFO and sends a message to it.

## Server

The server uses the same method as sqrl to open the FIFO, add it to an event loop, then starts off the event loop.

## Conclusion

I see exactly the same response with this client and server than I did with sqrl:

1. On startup, 0% CPU
2. The first request brings the CPU to 100%
3. CPU stays at 100% until the server is killed
