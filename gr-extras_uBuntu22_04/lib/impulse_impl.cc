/* -*- c++ -*- */
/*
 * Copyright 2022 Dale Ranta.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <gnuradio/io_signature.h>
#include "impulse_impl.h"

namespace gr {
  namespace extras_uBuntu22_04 {
    impulse::sptr
    impulse::make(int nfft, int nend)
    {
      return gnuradio::get_initial_sptr
        (new impulse_impl(nfft, nend));
    }


    /*
     * The private constructor
     */
    impulse_impl::impulse_impl(int nfft, int nend)
      : gr::block("impulse",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(1, 1, nfft*sizeof(gr_complex))),
              d_nfft(nfft),d_nend(nend)
    {}

    /*
     * Our virtual destructor.
     */
    impulse_impl::~impulse_impl()
    {
    }
    
    int impulse_impl::fft(float *data,int nn,int isign)
	{
		double twopi,tempr,tempi,wstpr,wstpi;
		double wr,wi,theta,sinth,fni;
		int i,j,n,m,mmax,istep;
	
		  data -= 1;
		  j=1;
		  n=2*nn;
		  twopi=8.*atan(1.);
		   for(i=1;i<=n;i += 2){
		   if(i-j >= 0)goto L200;
		   tempr=data[j];
		   tempi=data[j+1];
		   data[j]=data[i];
		   data[j+1]=data[i+1];
		   data[i]=tempr;
		   data[i+1]=tempi;
	L200:    m=n/2;
	L300:    if(j-m > 0)goto L400;
			goto L500;
	L400:    j=j-m;
		   m=m/2;
		   if(m-2 >= 0)goto L300;
	L500:  j=j+m;
		   }
		  mmax=2;
	L600:   if(mmax-n >= 0)goto L1000;
		  istep=2*mmax;
		  theta=twopi/(double)(isign*mmax);
		  sinth=sin(theta/2.);
		  wstpr=-2.*sinth*sinth;
		  wstpi=sin(theta);
		  wr=1.;
		  wi=0.;
			for(m=1;m<=mmax;m+=2){
				for( i=m;i<=n;i+=istep){
					j=i+mmax;
					tempr=wr*data[j]-wi*data[j+1];
					tempi=wr*data[j+1]+wi*data[j];
					data[j]=data[i]-tempr;
					data[j+1]=data[i+1]-tempi;
					data[i]=data[i]+tempr;
					data[i+1]=data[i+1]+tempi;
				}
				tempr=wr;
				wr=wr*wstpr-wi*wstpi+wr;
				wi=wi*wstpr+tempr*wstpi+wi;
			}
		  mmax=istep;
		  goto L600;
	L1000: 

		if(isign > 0){
			fni=2.0/(double)nn;
		}else{
			fni=0.5;
		}
		double amax=-1e33;
		double amin=1e33;
		for( i=1;i<=2*nn;++i){
			data[i]=data[i]*fni;
			double v=data[i];
			if(v > amax)amax=v;
			if(v < amin)amin=v;
		}
/*		
		static int p=0;
		
		if(++p > 20){
		   fprintf(stderr,"amin %g amax %g\n",amin,amax);
		   p=0;
		}
*/		
		
		return 0;
	}

    int
    impulse_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      gr_complex *out = (gr_complex *) output_items[0];
      
      
      	int nout=d_nfft;
      	      
		int nw=0;
		int nend=d_nend;
        for(int n = 0; n < nout; n++)
         {
         		out[n]=0;
                if(nw++ >= nend){
                  nw=0;
                  out[n]=1;
                 }
         }
         
         fft((float *)out,d_nfft,-1);
         

      // Tell runtime system how many output items we produced.
      return 1;
    }

  } /* namespace extras */
} /* namespace gr */

