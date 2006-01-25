#ifndef WX_PCH_H_INCLUDED
#define WX_PCH_H_INCLUDED

#if ( defined(USE_PCH) && !defined(WX_PRECOMP) )
    #define WX_PRECOMP
#endif // USE_PCH

// basic wxWidgets headers
#include <wx/wxprec.h>

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#ifdef USE_PCH
	// put here all your rarely-changing header files
	#include "wx/config.h"
    #include "wx/wfstream.h"
    #include "wx/strconv.h"
    #include <wx/fileconf.h>
#endif // USE_PCH

#endif // WX_PCH_H_INCLUDED
