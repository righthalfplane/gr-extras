/* -*- c++ -*- */
/*
 * Copyright 2022 Dale Ranta.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <gnuradio/io_signature.h>
#include "s_tcp_impl.h"

namespace gr {
  namespace extras_uBuntu22_04 {

    s_tcp::sptr
    s_tcp::make(const std::string &address,int port)
    {
      return gnuradio::get_initial_sptr
        (new s_tcp_impl(address, port));
    }


    /*
     * The private constructor
     */
    s_tcp_impl::s_tcp_impl(const std::string &addressi,int porti)
      : gr::block("s_tcp",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(0, 1, sizeof(gr_complex))),
              address(addressi),Port(porti)
    {
    	char add[256];
    
          
		  strncpy(add,address.c_str(),sizeof(add));
          
          serverSocket=startService(add);
          
          printf("address %s Port %d serverSocket %d\n",add,Port,serverSocket);
          
          runMode=0;
    
          dataType=2;
    
    }

    /*
     * Our virtual destructor.
     */
    s_tcp_impl::~s_tcp_impl()
    {
    }






    int
    s_tcp_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
       gr_complex *out = (gr_complex *) output_items[0];
       
       if(runMode == 0){
           SOCKET sock=waitForService();
           if(sock != -1){
               printf("Connection Opened socket %d\n",sock);
               runMode=1;
        	}
       }
		if(runMode == 1){
		    long size=noutput_items*sizeof(gr_complex);
		    int ret;
		    if(dataType == 0){
	    	    ret=netRead(clientSocket,(char *)out,size);
		    }else if(dataType == 1){
	    	    ret=netRead(clientSocket,(char *)out,size/2);
	    	    if(!ret){
	    	        short int *in=(short int *)output_items[0];
	    	        for(int n=noutput_items-1;n>=0;--n){
	    	             out[n]=gr_complex{(float)in[2*n],(float)in[2*n+1]};
	    	        }
	    	    }
		    }else if(dataType == 2){
	    	    ret=netRead(clientSocket,(char *)out,size/4);
	    	    if(!ret){
	    	        signed char *in=(signed char *)output_items[0];
	    	        for(int n=noutput_items-1;n>=0;--n){
	    	             out[n]=gr_complex{(float)in[2*n],(float)in[2*n+1]};
	    	        }
	    	    }
	    	    
		    }
	    	if(ret > 0){
	    	    runMode=0;
                printf("Connection Closed\n");
                closesocket(clientSocket);
	    	}else{
	    	    ;
	    	}
		}else{
			for(int n=0;n<noutput_items;++n){
		     	out[n]=n;
		}
	}
      // Do <+signal processing+>

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }
    
    
int s_tcp_impl::Sleep2(int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
	return 0;
}

int s_tcp_impl::netRead(SOCKET clientSocket,char *buff,long n)
{
	long k;
	int isleep;

	if(!buff)return 1;
	
	// fprintf(stderr,"clientSocket %d netRead %p n %ld\n",clientSocket,buff,n);

	// Bytes += n;

	isleep=0;

	k=n;
	while(k > 0){
	    n=k;
	    n=recv(clientSocket,buff,n,0);
	    if(n > 0){
	        k -= n;
	        buff += n;
		    isleep=0;
	    }else if(n == 0){
	        if(++isleep > 20){
	            fprintf(stderr,"netRead Time Out Error\n");
	            return 1;
	        }else{
	            Sleep2(10);
	        }
	    }else{
	        fprintf(stderr,"netRead Error Reading Socket\n");
		    return 1;        
	    }
	}
	return 0;
}
    
    
    
int s_tcp_impl::CheckSocket(SOCKET serverSocket,int *count,int ms)
{
       struct timeval   tv;
       fd_set fds;

        FD_ZERO(&fds);
        FD_SET(serverSocket, &fds);

	tv.tv_sec = ms/1000;
	tv.tv_usec = (ms%1000)*1000;
	
	int ret = select((int)(serverSocket+1), &fds, NULL,  NULL, &tv);
	if (ret < 0) return ret;
	if (ret == 0) return ret;

/*
        if (select(32, &filedes, (fd_set *)NULL, (fd_set *)NULL, &timeout))  {
                ioctl(serverSocket, FIONREAD, count);
                return TRUE;
        }
	*count = 0;
*/
        return ret;
}

SOCKET s_tcp_impl::waitForService()
{
		
	addrLen=sizeof(clientSocketAddr);
	
	{
		int count;
		int ret;
		
	    ret=CheckSocket(serverSocket,&count,3000);

		if(ret <= 0){
		    fprintf(stderr,"Wait Connection %d\n",ret);
			return -1;
        }
        
		fprintf(stderr,"Try Connection %d\n",ret);
		
		clientSocket=accept(serverSocket,(struct  sockaddr  *)&clientSocketAddr,
	                        &addrLen);
/*
		this->ibuff=-2;
		launchThread((void *)this,ListenSocket);
	
		while(this->ibuff != -1){
			Sleep2(10);
		}
	                                             
 	     shutdown(clientSocket,2);
	     closesocket(clientSocket);
*/

	}
	
	return clientSocket;
}
        
    
    
SOCKET s_tcp_impl::startService(char *name)
{

	// if(getPortAndName(name,&hostAddr,&Port))return -1;
	
	serverSocket=createService(&Port);
    if(serverSocket == -1){
          fprintf(stderr,"Create Port %d Failed\n",Port);
	      return -1;
	}

	return serverSocket;
}

SOCKET s_tcp_impl::createService(unsigned short *Port)
{
	struct sockaddr_in serverSocketAddr;
	SOCKET serverSocket;
	struct sockaddr_in name;
/*
	int buf_size;
	int ret;

	buf_size=32768;
*/
	memset((char *)&serverSocketAddr,0,sizeof(serverSocketAddr));
	serverSocketAddr.sin_port=htons((unsigned short)0);
	serverSocketAddr.sin_port=htons(*Port);
	serverSocketAddr.sin_family=AF_INET;
	serverSocketAddr.sin_addr.s_addr=htonl(INADDR_ANY);
	serverSocket=socket(AF_INET,SOCK_STREAM,0);
/*
	ret=setsockopt( serverSocket, SOL_SOCKET, SO_RCVBUF, 
                  (char *)&buf_size, sizeof(int) );    
        if(ret < 0)fprintf(stderr,"setsockopt failed\n");
 */
	
	int ret = ::bind(serverSocket, (struct  sockaddr  *)&serverSocketAddr, sizeof(serverSocketAddr));
	if (ret < 0) {
		;
	}
	listen(serverSocket,SOMAXCONN);
	namelen=sizeof(struct sockaddr_in);
	getsockname(serverSocket,(struct  sockaddr  *)&name,&namelen);
		
	*Port=ntohs(name.sin_port);
	return serverSocket;
	
}

    
    

  } /* namespace extras */
} /* namespace gr */

