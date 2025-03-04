#ifndef UOTYPE_H
#define UOTYPE_H

// Compiler directives
#if  	defined(_WIN32) && !defined(__MINGW32__)
// Visual C pragma
#pragma pack(1)
#define STRUCT_PACKED
#else
// GCC packed attribute
#define STRUCT_PACKED	__attribute__ ((packed))
#endif

inline unsigned int color15to32( unsigned short color )
{
	if( !color )
		return color;

	unsigned char r = ( ( color >> 10 ) & 0x1F );
	unsigned char g = ( ( color >> 5 ) & 0x1F );
	unsigned char b = ( color & 0x1F );

	unsigned int color32 = ( r * 8 ) | ( ( g * 8 ) << 8 ) | ( ( b * 8 ) << 16 ) | 0xFF000000;

	return color32;
}


struct staticentry {
   unsigned short TileID : 16;
   char x : 8;
   char y : 8;
   signed char z : 8;
   short Hue : 16;
}  STRUCT_PACKED;

struct staticinfo {
   unsigned short TileID : 16;
   char x : 8;
   char y : 8;
   signed char z : 8;
   short Hue : 16;
   unsigned int obj_id : 32;
}  STRUCT_PACKED;


struct stIndexRecord
{
  unsigned int offset;
  unsigned int length;
  unsigned int extra;
};

struct MulCell {
 unsigned short tileid;
 signed char z;
} STRUCT_PACKED;

struct MulBlock {
 struct MulCell cells[8][8];
} STRUCT_PACKED;

struct VerDataEntry {
 unsigned int fileid;
 unsigned int blockid;
 unsigned int start;
 unsigned int len;
 unsigned int extra;
} STRUCT_PACKED;

struct TileDataStaticEntry_PreHS {
    unsigned int flags;
    unsigned char weight;
    unsigned char quality;
    unsigned short unknown;
    unsigned char unknown1;
    unsigned char quantity;
    unsigned short animid;
    unsigned short hue;
    unsigned short lightidx;
    unsigned char height;
    char name[20];
} STRUCT_PACKED;

struct TileDataStaticEntry {
 unsigned long long flags;
 unsigned char weight;
 unsigned char quality;
 unsigned short unknown;
 unsigned char unknown1;
 unsigned char quantity;
 unsigned short animid;
 unsigned short hue;
 unsigned short lightidx;
 unsigned char height;
 char name[20];
} STRUCT_PACKED;

struct StaticPatch {
	unsigned char type;
	unsigned int obj_id;
	unsigned short tileid;
	unsigned char x, y;
	unsigned short blockx, blocky;
	signed short z;
} STRUCT_PACKED;

#define TILEDATA_MAX_ID_LAND            0x4000
#define TILEDATA_MAX_ID_STATIC_PREHS    0x3FFF
#define TILEDATA_MAX_ID_STATIC_HS       0x7FFF

#define TILEDATAFLAG_BACKGROUND    0x00000001
#define TILEDATAFLAG_WEAPON        0x00000002
#define TILEDATAFLAG_TRANSPARENT   0x00000004
#define TILEDATAFLAG_TRANSLUCENT   0x00000008
#define TILEDATAFLAG_WALL          0x00000010
#define TILEDATAFLAG_DAMAGING      0x00000020
#define TILEDATAFLAG_IMPASSABLE    0x00000040
#define TILEDATAFLAG_WET           0x00000080
#define TILEDATAFLAG_UNKNOWN1      0x00000100
#define TILEDATAFLAG_SURFACE       0x00000200
#define TILEDATAFLAG_BRIDGE        0x00000400
#define TILEDATAFLAG_GENERIC       0x00000800
#define TILEDATAFLAG_WINDOW        0x00001000
#define TILEDATAFLAG_NOSHOOT       0x00002000
#define TILEDATAFLAG_ARTICLEA      0x00004000
#define TILEDATAFLAG_ARTICLEAN     0x00008000
#define TILEDATAFLAG_INTERNAL      0x00010000
#define TILEDATAFLAG_FOLIAGE       0x00020000
#define TILEDATAFLAG_PARTIALHUE    0x00040000
#define TILEDATAFLAG_UNKNOWN2      0x00080000
#define TILEDATAFLAG_MAP           0x00100000
#define TILEDATAFLAG_CONTAINER     0x00200000
#define TILEDATAFLAG_WEARABLE      0x00400000
#define TILEDATAFLAG_LIGHTSOURCE   0x00800000
#define TILEDATAFLAG_ANIMATION     0x01000000
#define TILEDATAFLAG_NODIAGONAL    0x02000000
#define TILEDATAFLAG_UNKNOWN3      0x04000000
#define TILEDATAFLAG_ARMOR         0x08000000
#define TILEDATAFLAG_ROOF          0x10000000
#define TILEDATAFLAG_DOOR          0x20000000
#define TILEDATAFLAG_STAIRBACK     0x40000000
#define TILEDATAFLAG_STAIRRIGHT    0x80000000

#define PATCH_DELETE   1
#define PATCH_ADD      2

#define VERDATAPATCH_ART  0x4
#define VERDATAPATCH_GUMP 0xC

#ifdef _WIN32
#pragma pack()
#endif

#endif
