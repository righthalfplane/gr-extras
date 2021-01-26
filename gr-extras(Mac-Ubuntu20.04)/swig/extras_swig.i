/* -*- c++ -*- */

#define EXTRAS_API

%include "gnuradio.i"           // the common stuff

//load generated python docstrings
%include "extras_swig_doc.i"

%{
#include "extras/impulse.h"
%}

%include "extras/impulse.h"
GR_SWIG_BLOCK_MAGIC2(extras, impulse);
