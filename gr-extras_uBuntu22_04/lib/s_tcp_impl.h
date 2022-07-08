/* -*- c++ -*- */
/*
 * Copyright 2022 Dale Ranta.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_EXTRAS_UBUNTU22_04_S_TCP_IMPL_H
#define INCLUDED_EXTRAS_UBUNTU22_04_S_TCP_IMPL_H

#include <gnuradio/extras_uBuntu22_04/s_tcp.h>
#include "SocketDefs.h"
#include <thread>

namespace gr {
  namespace extras_uBuntu22_04 {
    class s_tcp_impl : public s_tcp
    {
     private:
      // Nothing to declare in this block.
     std::string address;
     unsigned short Port;
     socklen_t namelen;
     SOCKET serverSocket;
     SOCKET clientSocket;
     socklen_t addrLen;
     struct sockaddr_in clientSocketAddr;
     int runMode;
     int dataType;


     public:
      s_tcp_impl(const std::string &address,int port);
      ~s_tcp_impl();

      	SOCKET createService(unsigned short *Port);
      	
      	SOCKET startService(char *name);
      	
      	SOCKET waitForService();
      	
      	int CheckSocket(SOCKET serverSocket,int *count,int ms);
      	
      	int netRead(SOCKET clientSocket,char *buff,long n);
      	
      	int Sleep2(int ms);



      // Where all the action really happens
      int work(
              int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items
      );
    };

  } // namespace extras
} // namespace gr

#endif /* INCLUDED_EXTRAS_UBUNTU22_04_S_TCP_IMPL_H */
