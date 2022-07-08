/* -*- c++ -*- */
/*
 * Copyright 2022 Dale Ranta.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_EXTRAS_UBUNTU22_04_IMPULSE_H
#define INCLUDED_EXTRAS_UBUNTU22_04_IMPULSE_H

#include <gnuradio/extras_uBuntu22_04/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace extras_uBuntu22_04 {

    /*!
     * \brief <+description of block+>
     * \ingroup extras_uBuntu22_04
     *
     */
    class EXTRAS_UBUNTU22_04_API impulse : virtual public gr::block
    {
     public:
      typedef std::shared_ptr<impulse> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of extras_uBuntu22_04::impulse.
       *
       * To avoid accidental use of raw pointers, extras_uBuntu22_04::impulse's
       * constructor is in a private implementation
       * class. extras_uBuntu22_04::impulse::make is the public interface for
       * creating new instances.
       */
      static sptr make(int nfft, int nend);
    };

  } // namespace extras_uBuntu22_04
} // namespace gr

#endif /* INCLUDED_EXTRAS_UBUNTU22_04_IMPULSE_H */
