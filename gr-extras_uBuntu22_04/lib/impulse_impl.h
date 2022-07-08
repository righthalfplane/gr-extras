/* -*- c++ -*- */
/*
 * Copyright 2022 Dale Ranta.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_EXTRAS_UBUNTU22_04_IMPULSE_IMPL_H
#define INCLUDED_EXTRAS_UBUNTU22_04_IMPULSE_IMPL_H

#include <gnuradio/extras_uBuntu22_04/impulse.h>

namespace gr {
  namespace extras_uBuntu22_04 {

    class impulse_impl : public impulse
    {
     private:
     int d_nfft;
     int d_nend;
     // Nothing to declare in this block.

     public:
      impulse_impl(int nfft, int nend);
      ~impulse_impl();
      
        int fft(float *data,int nn,int isign);

      // Where all the action really happens
      int work(
              int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items
      );
    };

  } // namespace extras
} // namespace gr

#endif /* INCLUDED_EXTRAS_UBUNTU22_04_IMPULSE_IMPL_H */
