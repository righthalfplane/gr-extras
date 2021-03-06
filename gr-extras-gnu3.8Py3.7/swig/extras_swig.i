/* -*- c++ -*- */

#define EXTRAS_API

%include "gnuradio.i"           // the common stuff

//load generated python docstrings
%include "extras_swig_doc.i"

%{
#include "extras/impulse.h"
#include "extras/impulse2.h"
#include "extras/s_udp.h"
#include "extras/s_tcp.h"
#include "extras/t_upd.h"
%}

%include "extras/impulse.h"
GR_SWIG_BLOCK_MAGIC2(extras, impulse);
%include "extras/impulse2.h"
GR_SWIG_BLOCK_MAGIC2(extras, impulse2);
%include "extras/s_udp.h"
GR_SWIG_BLOCK_MAGIC2(extras, s_udp);
%include "extras/s_tcp.h"
GR_SWIG_BLOCK_MAGIC2(extras, s_tcp);
%include "extras/t_upd.h"
GR_SWIG_BLOCK_MAGIC2(extras, t_upd);
