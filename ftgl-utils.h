/* Freetype GL - A C OpenGL Freetype engine
 *
 * Distributed under the OSI-approved BSD 2-Clause License.  See accompanying
 * file `LICENSE` for more details.
 */
#ifndef __FTGL_UTILS_H__
#define __FTGL_UTILS_H__
#include <stdio.h>
#include <stdarg.h>

#ifndef __THREAD
#if defined(__GNUC__) || defined(__clang__)
#define __THREAD __thread
#elif defined(_MSC_VER)
#define __THREAD __declspec( thread )
#else
#define __THREAD
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
namespace ftgl {
#endif


typedef void (*error_callback_t) (const char *fmt, ...);
extern error_callback_t log_error;

/**
 * Prints input to stderr
 * This is fallback function for error reporting if ftgl_set_error_callback() wans't called
 *
 * @param fmt       cstring to be printed matching C-style printing syntax
 * @param ...       va_list fmt supplying arguments
 */
  void
  error_callback_default(const char *fmt, ...);

/**
 * Set function to call on error handling
 * This is fallback function for error reporting if ftgl_set_error_callback() wans't called
 *
 * @param error_cb  callback function to call on error, see error_callback_default for reference
 */
  void
  set_error_callback(error_callback_t error_cb);

/*********** public error API ***********/
/**
 * freetype_gl_errno    is the error number if a freetype-gl function fails
 *                      Errors < FTGL_ERR_BASE are pass-through from Freetype
 */
extern __THREAD int freetype_gl_errno;
/**
 * freetype_gl_warnings is a flag that activates output of warnings.
 *                      Default is warnings off
 */
extern __THREAD int freetype_gl_warnings;
/**
 * freetype_gl_message  is the error message if a freetype-gl function fails
 */
extern __THREAD const char * freetype_gl_message;
/**
 * freetype_gl_errhook  is a function pointer to display error number
 *                      and message, default is using fprintf on stderr
 */
extern void (*freetype_gl_errhook)(int errno, char* message, char* string, ...);
/**
 * freetype_gl_errstr   converts an errno to the message (including FT_errors)
 */
extern const char* freetype_gl_errstr(int errno);

#ifndef FTGL_ERR_PREFIX
# define FTGL_ERR_PREFIX  FTGL_Err_
#endif

#ifndef FTGL_ERR_CAT
# define FTGL_ERR_XCAT( x, y )  x ## y
# define FTGL_ERR_CAT( x, y )   FTGL_ERR_XCAT( x, y )
#endif
#define FTGL_ERR_BASE  0x100 /* Freetype GL errors start at 0x100 */
    
extern const char* freetype_gl_errstrs[];

#define freetype_gl_error(errno) {			     \
	freetype_gl_errno = FTGL_ERR_CAT( FTGL_ERR_PREFIX, errno);	\
	freetype_gl_message = freetype_gl_errstrs[freetype_gl_errno]; \
	freetype_gl_errhook(freetype_gl_errno, "FTGL Error %s:%d: %s\n", __FILE__, __LINE__, freetype_gl_message); \
    }

#define freetype_gl_error_str(errno, string) {					\
	freetype_gl_errno = FTGL_ERR_CAT( FTGL_ERR_PREFIX, errno);	\
	freetype_gl_message = freetype_gl_errstrs[freetype_gl_errno]; \
	freetype_gl_errhook(freetype_gl_errno, "FTGL Error %s:%d: %s '%s'\n", __FILE__, __LINE__, freetype_gl_message, string); \
    }

#define freetype_gl_warning(errno) {			     \
	freetype_gl_errno = FTGL_ERR_CAT( FTGL_ERR_PREFIX, errno);	\
	freetype_gl_message = freetype_gl_errstrs[freetype_gl_errno]; \
	if(freetype_gl_warnings) freetype_gl_errhook(freetype_gl_errno, "FTGL Warning %s:%d: %s\n", __FILE__, __LINE__, freetype_gl_message); \
    }

#define freetype_error(errno) {			     \
	freetype_gl_errno = errno;	\
	freetype_gl_message = freetype_gl_errstrs[errno]; \
	freetype_gl_errhook(freetype_gl_errno, "FTGL Error %s:%d: %s\n", __FILE__, __LINE__, freetype_gl_message); \
    }

#define FTGL_ERRSTR_MAX 0x100

#ifndef FTGL_ERRORDEF_
# ifndef FTGL_ERRORDEF

#  define FTGL_ERRORDEF( e, v, s )  e = v,
#  define FTGL_ERROR_START_LIST     enum {
#  define FTGL_ERROR_END_LIST       FTGL_ERR_CAT( FTGL_ERR_PREFIX, Max ) };

#  ifdef __cplusplus
#   define FTGL_NEED_EXTERN_C
  extern "C" {
#  endif
    
# endif /* !FTGL_ERRORDEF */

    /* this macro is used to define an error */
# define FTGL_ERRORDEF_( e, v, s )						\
          FTGL_ERRORDEF( FTGL_ERR_CAT( FTGL_ERR_PREFIX, e ), v + FTGL_ERR_BASE, s )
# endif /* !FTGL_ERRORDEF_ */

#include <freetype-gl-errdef.h>

#ifdef __cplusplus
}
}
#endif

#endif
