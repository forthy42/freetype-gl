/* Freetype GL - A C OpenGL Freetype engine
 *
 * Distributed under the OSI-approved BSD 2-Clause License.  See accompanying
 * file `LICENSE` for more details.
 */

#ifndef __FREETYPE_GL_ERRORS_H__
#define __FREETYPE_GL_ERRORS_H__

FTGL_ERROR_START_LIST

FTGL_ERRORDEF_( Texture_Atlas_Full,			0xD0,
		"Texture atlas is full" )
FTGL_ERRORDEF_( Cannot_Load_File,			0xD1,
		"unable to load file" )
FTGL_ERRORDEF_( Font_Unavailable,			0xD2,
		"no font available" )
FTGL_ERRORDEF_( No_Font_File_Given,			0xD3,
		"no font file given" )
FTGL_ERRORDEF_( Out_Of_Memory,				0xD4,
		"out of memory" )
FTGL_ERRORDEF_( Unimplemented_Function,			0xD5,
		"unimplemented function" )
FTGL_ERRORDEF_( Cant_Match_Family,			0xD6,
		"fontconfig error: could not match family" )
FTGL_ERRORDEF_( No_Font_In_Markup,			0xD7,
		"Markup doesn't have a font" )
FTGL_ERRORDEF_( No_Size_Specified,			0xD8,
		"No size specified for attribute" )
FTGL_ERRORDEF_( No_Format_Specified,			0xD9,
		"No format specified for attribute" )
FTGL_ERRORDEF_( Vertex_Attribute_Format_Wrong,		0xDA,
		"Vertex attribute format not understood" )
FTGL_ERRORDEF_( Load_Color_Not_Available,		0xDB,
		"FT_LOAD_COLOR not available" )
FTGL_ERRORDEF_( No_Fixed_Size_In_Color_Font,		0xDC,
		"No fixed size in color font" )

FTGL_ERROR_END_LIST

#endif
