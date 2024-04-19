//All functions can refer to RTL9021Ax_Sample_Code_Note_v0.1.pdf.

#include "mdio.h"
#include "mdio2.h"
#include "ht32f165x_it.h"

#define DEBUG 0
#if(DEBUG)
	#define DBGMSG(x) {printf x;}
#else
	#define DBGMSG(x)
#endif
	
#define SUCCESS      0
#define ERROR        -1

typedef unsigned long  u32;
typedef unsigned short u16;
typedef unsigned char  u8;
typedef short 		   s16;

s16 RTL9021Ax_Initial_Configuration(void);
s16 RTL9021Ax_Initial_Configuration_Check(void);