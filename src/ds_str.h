
#ifndef H_DS_STR
#define H_DS_STR

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

   // Make a copy of the src string, caller must free the result, NULL
   // returned on error.
   char *ds_str_dup (const char *src);

   // Concatenate all the strings given (ending the parameter list with a
   // NULL) into a single string that is returned which the caller must
   // free. NULL is returned on error
   char *ds_str_cat (const char *src, ...);

   // Append all the strings given in '...' (ending with a NULL) to
   // parameter '(*dst)'. Parameter '(*dst)' is reallocated as necessary
   // and therefore must be reallocatable (returned by free() or similar).
   // The reallocated '(*dst)' is also returned on success.
   //
   // NULL is returned on error.
   char *ds_str_append (char **dst, const char *s1, ...);

   // Perform a printf into a buffer allocated on demand. The parameter
   // '*dst' is allocated by this function and must be freed by the caller.
   // On success the length of '*dst' is returned, on failure zero is
   // returned.
   size_t ds_str_printf (char **dst, const char *fmt, ...);
   size_t ds_str_vprintf (char **dst, const char *fmt, va_list ap);

#ifdef __cplusplus
};
#endif

#endif
