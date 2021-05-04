/* -*- c++ -*- */
/* 
 * Copyright 2021 Dale Ranta.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


#ifndef INCLUDED_EXTRAS_IMPULSE_H
#define INCLUDED_EXTRAS_IMPULSE_H

#include <extras/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace extras {

    /*!
     * \brief <+description of block+>
     * \ingroup extras
     *
     */
    class EXTRAS_API impulse : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<impulse> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of extras::impulse.
       *
       * To avoid accidental use of raw pointers, extras::impulse's
       * constructor is in a private implementation
       * class. extras::impulse::make is the public interface for
       * creating new instances.
       */
      static sptr make(int nfft, int nend);
    };

  } // namespace extras
} // namespace gr

#endif /* INCLUDED_EXTRAS_IMPULSE_H */

