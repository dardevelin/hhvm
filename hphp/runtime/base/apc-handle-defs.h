/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2014 Facebook, Inc. (http://www.facebook.com)     |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef incl_HPHP_APC_HANDLE_DEFS_H_
#define incl_HPHP_APC_HANDLE_DEFS_H_

#include "hphp/runtime/base/apc-handle.h"
#include "hphp/runtime/base/apc-typed-value.h"
#include "hphp/runtime/base/execution-context.h"

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

inline void APCHandle::unreferenceRoot() {
  if (!getUncounted()) {
    realDecRef();
  } else {
    g_context->enqueueAPCHandle(this);
  }
}

///////////////////////////////////////////////////////////////////////////////
}

#endif
