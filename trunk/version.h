#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "05";
	static const char MONTH[] = "03";
	static const char YEAR[] = "2008";
	static const double UBUNTU_VERSION_STYLE = 8.03;
	
	//Software Status
	static const char STATUS[] = "Beta";
	static const char STATUS_SHORT[] = "b";
	
	//Standard Version Type
	static const long MAJOR = 0;
	static const long MINOR = 6;
	static const long BUILD = 6;
	static const long REVISION = 25;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 66;
	#define RC_FILEVERSION 0,6,6,25
	#define RC_FILEVERSION_STRING "0, 6, 6, 25\0"
	static const char FULLVERSION_STRING[] = "0.6.6.25";
	
	//SVN Version
	static const char SVN_REVISION[] = "0";
	static const char SVN_DATE[] = "unknown date";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 0;
	

}
#endif //VERSION_h
