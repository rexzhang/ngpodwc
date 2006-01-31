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
	//配置
	#include "wx/config.h"
	#include "wx/confbase.h"

	//配置文件
    #include <wx/fileconf.h>
    //文件处理
    #include "wx/wfstream.h"

    //Unicode
    #include "wx/strconv.h"

    //数据库支持
    #include "wx/db.h"
    #include "wx/dbtable.h"

    //图片处理支持
    #include <wx/image.h>
    //图片处理的 加速??
    #include <wx/quantize.h>
#endif // USE_PCH

#endif // WX_PCH_H_INCLUDED
