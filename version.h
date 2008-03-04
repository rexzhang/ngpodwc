#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "16";
	static const char MONTH[] = "10";
	static const char YEAR[] = "2007";
	static const double UBUNTU_VERSION_STYLE = 7.10;
	
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
	

}
#endif //VERSION_h
