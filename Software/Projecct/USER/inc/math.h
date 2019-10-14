/* math.h standard header */
/* Copyright 2003-2010 IAR Systems AB. */
#ifndef _MATH
#define _MATH

#ifndef _SYSTEM_BUILD
  #pragma system_include
#endif

#include <ycheck.h>
#include <ymath.h>
#include <xtgmath.h>

_C_STD_BEGIN

#if __AEABI_PORTABILITY_INTERNAL_LEVEL
  #ifndef __AEABI_PORTABLE
    #define __AEABI_PORTABLE
  #endif

  #define HUGE_VAL        _CSTD __aeabi_HUGE_VAL

  #if _DLIB_ADD_C99_SYMBOLS
    #define HUGE_VALF     _CSTD __aeabi_HUGE_VALF
    #define HUGE_VALL     _CSTD __aeabi_HUGE_VALL

    #define INFINITY      _CSTD __aeabi_INFINITY
    #define NAN           _CSTD __aeabi_NAN
  #endif /* _DLIB_ADD_C99_SYMBOLS */
#else /* __AEABI_PORTABILITY_INTERNAL_LEVEL */
  #define HUGE_VAL        (0.Infinity)

  #if _DLIB_ADD_C99_SYMBOLS
    #define HUGE_VALF     ((float) 0.Infinity)
    #define HUGE_VALL     ((long double) 0.Infinity)

    #define INFINITY      ((float) 0.Infinity)
    #define NAN           ((float) 0.NaN)
  #endif /* _DLIB_ADD_C99_SYMBOLS */
#endif /* __AEABI_PORTABILITY_INTERNAL_LEVEL */

#if _DLIB_ADD_C99_SYMBOLS
  typedef float float_t;
  typedef double double_t;
#endif /* _DLIB_ADD_C99_SYMBOLS */


_C_LIB_DECL
                /* double declarations */
__EFF_NS    __ATTRIBUTES double acos(double);
__EFF_NS    __ATTRIBUTES double asin(double);
__EFF_NS    __ATTRIBUTES double atan(double);
__EFF_NS    __ATTRIBUTES double atan2(double, double);
__EFF_NE    __ATTRIBUTES double ceil(double);
__EFF_NS    __ATTRIBUTES double exp(double);
__EFF_NE    __ATTRIBUTES double fabs(double);
__EFF_NE    __ATTRIBUTES double floor(double);
__EFF_NS    __ATTRIBUTES double fmod(double, double);
__EFF_NENR2 __ATTRIBUTES double frexp(double, int *);
__EFF_NS    __ATTRIBUTES double ldexp(double, int);
__EFF_NENR2 __ATTRIBUTES double modf(double, double *);
__EFF_NS    __ATTRIBUTES double pow(double, double);
__EFF_NS    __ATTRIBUTES double sqrt(double);
__EFF_NS    __ATTRIBUTES double tan(double);
__EFF_NS    __ATTRIBUTES double tanh(double);

__EFF_NS    __ATTRIBUTES double cos(double);
__EFF_NS    __ATTRIBUTES double cosh(double);
__EFF_NS    __ATTRIBUTES double log(double);
__EFF_NS    __ATTRIBUTES double log10(double);
__EFF_NS    __ATTRIBUTES double sin(double);
__EFF_NS    __ATTRIBUTES double sinh(double);

#if _DLIB_ADD_C99_SYMBOLS

                /* double declarations */
  __EFF_NS    __ATTRIBUTES double acosh(double);
  __EFF_NS    __ATTRIBUTES double asinh(double);
  __EFF_NS    __ATTRIBUTES double atanh(double);
  __EFF_NE    __ATTRIBUTES double cbrt(double);
  __EFF_NE    __ATTRIBUTES double copysign(double, double);
  #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
    __EFF_NS    __ATTRIBUTES double erf(double);
    __EFF_NS    __ATTRIBUTES double erfc(double);
    __EFF_NS    __ATTRIBUTES double expm1(double);
  #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
  __EFF_NS    __ATTRIBUTES double exp2(double);
  __EFF_NE    __ATTRIBUTES double fdim(double, double);
  #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
    __EFF_NS    __ATTRIBUTES double fma(double, double, double);
  #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
  __EFF_NE    __ATTRIBUTES double fmax(double, double);
  __EFF_NE    __ATTRIBUTES double fmin(double, double);
  __EFF_NS    __ATTRIBUTES double hypot(double, double);
  __EFF_NE    __ATTRIBUTES int    ilogb(double);
  #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
    __EFF_NS    __ATTRIBUTES double lgamma(double);
  #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
  #ifdef _LONGLONG
    #pragma language=save
    #pragma language=extended
    __EFF_NS __ATTRIBUTES _Longlong llrint(double);
    __EFF_NS __ATTRIBUTES _Longlong llround(double);
    #pragma language=restore
  #endif /* _LONGLONG */
  __EFF_NS    __ATTRIBUTES double log1p(double);
  __EFF_NS    __ATTRIBUTES double log2(double);
  __EFF_NS    __ATTRIBUTES double logb(double);
  __EFF_NS    __ATTRIBUTES long   lrint(double);
  __EFF_NS    __ATTRIBUTES long   lround(double);
  __EFF_NE    __ATTRIBUTES double nan(const char *);
  __EFF_NS    __ATTRIBUTES double nearbyint(double);
  __EFF_NS    __ATTRIBUTES double nextafter(double, double);
  __EFF_NS    __ATTRIBUTES double nexttoward(double, long double);
  __EFF_NS    __ATTRIBUTES double remainder(double, double);
  __EFF_NS    __ATTRIBUTES double remquo(double, double, int *);
  __EFF_NS    __ATTRIBUTES double rint(double);
  __EFF_NE    __ATTRIBUTES double round(double);
  __EFF_NS    __ATTRIBUTES double scalbn(double, int);
  __EFF_NS    __ATTRIBUTES double scalbln(double, long);
  #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
    __EFF_NS    __ATTRIBUTES double tgamma(double);
  #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
  __EFF_NE    __ATTRIBUTES double trunc(double);

                /* float declarations */
  __EFF_NS    __ATTRIBUTES float acosf(float);
  __EFF_NS    __ATTRIBUTES float asinf(float);
  __EFF_NS    __ATTRIBUTES float atanf(float);
  __EFF_NS    __ATTRIBUTES float atan2f(float, float);
  __EFF_NE    __ATTRIBUTES float ceilf(float);
  __EFF_NS    __ATTRIBUTES float expf(float);
  __EFF_NE    __ATTRIBUTES float fabsf(float);
  __EFF_NE    __ATTRIBUTES float floorf(float);
  __EFF_NS    __ATTRIBUTES float fmodf(float, float);
  __EFF_NENR2 __ATTRIBUTES float frexpf(float, int *);
  __EFF_NS    __ATTRIBUTES float ldexpf(float, int);
  __EFF_NENR2 __ATTRIBUTES float modff(float, float *);
  __EFF_NS    __ATTRIBUTES float powf(float, float);
  __EFF_NS    __ATTRIBUTES float sqrtf(float);
  __EFF_NS    __ATTRIBUTES float tanf(float);
  __EFF_NS    __ATTRIBUTES float tanhf(float);

  __EFF_NS    __ATTRIBUTES float acoshf(float);
  __EFF_NS    __ATTRIBUTES float asinhf(float);
  __EFF_NS    __ATTRIBUTES float atanhf(float);
  __EFF_NE    __ATTRIBUTES float cbrtf(float);
  __EFF_NE    __ATTRIBUTES float copysignf(float, float);
  #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
    __EFF_NS    __ATTRIBUTES float erff(float);
    __EFF_NS    __ATTRIBUTES float erfcf(float);
    __EFF_NS    __ATTRIBUTES float expm1f(float);
  #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
  __EFF_NS    __ATTRIBUTES float exp2f(float);
  __EFF_NE    __ATTRIBUTES float fdimf(float, float);
  #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
    __EFF_NS    __ATTRIBUTES float fmaf(float, float, float);
  #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
  __EFF_NE    __ATTRIBUTES float fmaxf(float, float);
  __EFF_NE    __ATTRIBUTES float fminf(float, float);
  __EFF_NS    __ATTRIBUTES float hypotf(float, float);
  __EFF_NE    __ATTRIBUTES int   ilogbf(float);
  #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
    __EFF_NS    __ATTRIBUTES float lgammaf(float);
  #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
  #ifdef _LONGLONG
    #pragma language=save
    #pragma language=extended
    __EFF_NS    __ATTRIBUTES _Longlong llrintf(float);
    __EFF_NS    __ATTRIBUTES _Longlong llroundf(float);
    #pragma language=restore
  #endif /* _LONGLONG */
  __EFF_NS    __ATTRIBUTES float log1pf(float);
  __EFF_NS    __ATTRIBUTES float log2f(float);
  __EFF_NS    __ATTRIBUTES float logbf(float);
  __EFF_NS    __ATTRIBUTES long  lrintf(float);
  __EFF_NS    __ATTRIBUTES long  lroundf(float);
  __EFF_NE    __ATTRIBUTES float nanf(const char *);
  __EFF_NS    __ATTRIBUTES float nearbyintf(float);
  __EFF_NS    __ATTRIBUTES float nextafterf(float, float);
  __EFF_NS    __ATTRIBUTES float nexttowardf(float, long double);
  __EFF_NS    __ATTRIBUTES float remainderf(float, float);
  __EFF_NS    __ATTRIBUTES float remquof(float, float, int *);
  __EFF_NS    __ATTRIBUTES float rintf(float);
  __EFF_NE    __ATTRIBUTES float roundf(float);
  __EFF_NS    __ATTRIBUTES float scalbnf(float, int);
  __EFF_NS    __ATTRIBUTES float scalblnf(float, long);
  #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
    __EFF_NS    __ATTRIBUTES float tgammaf(float);
  #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
  __EFF_NE    __ATTRIBUTES float truncf(float);

  __EFF_NS    __ATTRIBUTES float cosf(float);
  __EFF_NS    __ATTRIBUTES float coshf(float);
  __EFF_NS    __ATTRIBUTES float logf(float);
  __EFF_NS    __ATTRIBUTES float log10f(float);
  __EFF_NS    __ATTRIBUTES float sinf(float);
  __EFF_NS    __ATTRIBUTES float sinhf(float);

                /* long double declarations */
  __EFF_NS    __ATTRIBUTES long double acosl(long double);
  __EFF_NS    __ATTRIBUTES long double asinl(long double);
  __EFF_NS    __ATTRIBUTES long double atanl(long double);
  __EFF_NS    __ATTRIBUTES long double atan2l(long double, long double);
  __EFF_NE    __ATTRIBUTES long double ceill(long double);
  __EFF_NS    __ATTRIBUTES long double expl(long double);
  __EFF_NE    __ATTRIBUTES long double fabsl(long double);
  __EFF_NE    __ATTRIBUTES long double floorl(long double);
  __EFF_NS    __ATTRIBUTES long double fmodl(long double, long double);
  __EFF_NENR2 __ATTRIBUTES long double frexpl(long double, int *);
  __EFF_NS    __ATTRIBUTES long double ldexpl(long double, int);
  __EFF_NENR2 __ATTRIBUTES long double modfl(long double, long double *);
  __EFF_NS    __ATTRIBUTES long double powl(long double, long double);
  __EFF_NS    __ATTRIBUTES long double sqrtl(long double);
  __EFF_NS    __ATTRIBUTES long double tanl(long double);
  __EFF_NS    __ATTRIBUTES long double tanhl(long double);

  __EFF_NS    __ATTRIBUTES long double acoshl(long double);
  __EFF_NS    __ATTRIBUTES long double asinhl(long double);
  __EFF_NS    __ATTRIBUTES long double atanhl(long double);
  __EFF_NE    __ATTRIBUTES long double cbrtl(long double);
  __EFF_NE    __ATTRIBUTES long double copysignl(long double, long double);
  #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
    __EFF_NS    __ATTRIBUTES long double erfl(long double);
    __EFF_NS    __ATTRIBUTES long double erfcl(long double);
    __EFF_NS    __ATTRIBUTES long double expm1l(long double);
  #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
  __EFF_NS    __ATTRIBUTES long double exp2l(long double);
  __EFF_NE    __ATTRIBUTES long double fdiml(long double, long double);
  #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
    __EFF_NS    __ATTRIBUTES long double fmal(long double, long double, 
                                              long double);
  #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
  __EFF_NE    __ATTRIBUTES long double fmaxl(long double, long double);
  __EFF_NE    __ATTRIBUTES long double fminl(long double, long double);
  __EFF_NS    __ATTRIBUTES long double hypotl(long double, long double);
  __EFF_NE    __ATTRIBUTES int         ilogbl(long double);
  #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
    __EFF_NS    __ATTRIBUTES long double lgammal(long double);
  #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
  #ifdef _LONGLONG
    #pragma language=save
    #pragma language=extended
    __EFF_NS    __ATTRIBUTES _Longlong llrintl(long double);
    __EFF_NS    __ATTRIBUTES _Longlong llroundl(long double);
    #pragma language=restore
  #endif /* _LONGLONG */
  __EFF_NS    __ATTRIBUTES long double log1pl(long double);
  __EFF_NS    __ATTRIBUTES long double log2l(long double);
  __EFF_NS    __ATTRIBUTES long double logbl(long double);
  __EFF_NS    __ATTRIBUTES long        lrintl(long double);
  __EFF_NS    __ATTRIBUTES long lroundl(long double);
  __EFF_NE    __ATTRIBUTES long double nanl(const char *);
  __EFF_NS    __ATTRIBUTES long double nearbyintl(long double);
  __EFF_NS    __ATTRIBUTES long double nextafterl(long double, long double);
  __EFF_NS    __ATTRIBUTES long double nexttowardl(long double, long double);
  __EFF_NS    __ATTRIBUTES long double remainderl(long double, long double);
  __EFF_NS    __ATTRIBUTES long double remquol(long double, long double, int *);
  __EFF_NS    __ATTRIBUTES long double rintl(long double);
  __EFF_NE    __ATTRIBUTES long double roundl(long double);
  __EFF_NS    __ATTRIBUTES long double scalbnl(long double, int);
  __EFF_NS    __ATTRIBUTES long double scalblnl(long double, long);
  #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
    __EFF_NS    __ATTRIBUTES long double tgammal(long double);
  #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
  __EFF_NE    __ATTRIBUTES long double truncl(long double);

  __EFF_NS    __ATTRIBUTES long double cosl(long double);
  __EFF_NS    __ATTRIBUTES long double coshl(long double);
  __EFF_NS    __ATTRIBUTES long double logl(long double);
  __EFF_NS    __ATTRIBUTES long double log10l(long double);
  __EFF_NS    __ATTRIBUTES long double sinl(long double);
  __EFF_NS    __ATTRIBUTES long double sinhl(long double);
#endif /* _DLIB_ADD_C99_SYMBOLS */

#if !defined(_NO_DEFINITIONS_IN_HEADER_FILES) && __AEABI_PORTABILITY_INTERNAL_LEVEL == 0
  #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH && \
      !defined(_DLIB_DO_NOT_ADD_ACCURATE_FUNCTIONS)
                  /* Accurate versions of certain float functions. */
  __EFF_NS __ATTRIBUTES double __iar_tan_accurate(double);
  __EFF_NS __ATTRIBUTES double __iar_cos_accurate(double);
  __EFF_NS __ATTRIBUTES double __iar_sin_accurate(double);
  __EFF_NS __ATTRIBUTES double __iar_pow_accurate(double, double);

  __EFF_NS __ATTRIBUTES double __iar_Sin_accurate(double, unsigned int);
  __EFF_NS __ATTRIBUTES double __iar_Pow_accurate(double, double, short *pex);
    #if _DLIB_ADD_C99_SYMBOLS
      __EFF_NS __ATTRIBUTES float __iar_tan_accuratef(float);
      __EFF_NS __ATTRIBUTES float __iar_cos_accuratef(float);
      __EFF_NS __ATTRIBUTES float __iar_sin_accuratef(float);
      __EFF_NS __ATTRIBUTES float __iar_pow_accuratef(float, float);

      __EFF_NS __ATTRIBUTES float __iar_Sin_accuratef(float, unsigned int);
      __EFF_NS __ATTRIBUTES float __iar_Pow_accuratef(float, float, short *pex);

      __EFF_NS __ATTRIBUTES long double __iar_tan_accuratel(long double);
      __EFF_NS __ATTRIBUTES long double __iar_cos_accuratel(long double);
      __EFF_NS __ATTRIBUTES long double __iar_sin_accuratel(long double);
      __EFF_NS __ATTRIBUTES long double __iar_pow_accuratel(long double, 
                                                            long double);

      __EFF_NS __ATTRIBUTES long double __iar_Sin_accuratel(long double, 
                                                            unsigned int);
      __EFF_NS __ATTRIBUTES long double __iar_Pow_accuratel(long double, 
                                                            long double,
                                                            short *pex);
    #endif /* _DLIB_ADD_C99_SYMBOLS */
  #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH && 
            !defined(_DLIB_DO_NOT_ADD_ACCURATE_FUNCTIONS) */

  #ifndef _DLIB_DO_NOT_ADD_SMALL_FUNCTIONS
                  /* Small versions of certain float functions. */
  __EFF_NS __ATTRIBUTES double __iar_cos_small(double);
  __EFF_NS __ATTRIBUTES double __iar_exp_small(double);
  __EFF_NS __ATTRIBUTES double __iar_log_small(double);
  __EFF_NS __ATTRIBUTES double __iar_log2_small(double);
  __EFF_NS __ATTRIBUTES double __iar_log10_small(double);
  __EFF_NS __ATTRIBUTES double __iar_pow_small(double, double);
  __EFF_NS __ATTRIBUTES double __iar_sin_small(double);
  __EFF_NS __ATTRIBUTES double __iar_tan_small(double);
  
    #if _DLIB_ADD_C99_SYMBOLS
    __EFF_NS __ATTRIBUTES float __iar_cos_smallf(float);
    __EFF_NS __ATTRIBUTES float __iar_exp_smallf(float);
    __EFF_NS __ATTRIBUTES float __iar_log_smallf(float);
    __EFF_NS __ATTRIBUTES float __iar_log2_smallf(float);
    __EFF_NS __ATTRIBUTES float __iar_log10_smallf(float);
    __EFF_NS __ATTRIBUTES float __iar_pow_smallf(float, float);
    __EFF_NS __ATTRIBUTES float __iar_sin_smallf(float);
    __EFF_NS __ATTRIBUTES float __iar_tan_smallf(float);

    __EFF_NS __ATTRIBUTES long double __iar_cos_smalll(long double);
    __EFF_NS __ATTRIBUTES long double __iar_exp_smalll(long double);
    __EFF_NS __ATTRIBUTES long double __iar_log_smalll(long double);
    __EFF_NS __ATTRIBUTES long double __iar_log2_smalll(long double);
    __EFF_NS __ATTRIBUTES long double __iar_log10_smalll(long double);
    __EFF_NS __ATTRIBUTES long double __iar_pow_smalll(long double, long double);
    __EFF_NS __ATTRIBUTES long double __iar_sin_smalll(long double);
    __EFF_NS __ATTRIBUTES long double __iar_tan_smalll(long double);
    #endif /* _DLIB_ADD_C99_SYMBOLS */

  #endif /* _DLIB_DO_NOT_ADD_SMALL_FUNCTIONS */

#endif /* !defined(_NO_DEFINITIONS_IN_HEADER_FILES) && __AEABI_PORTABILITY_INTERNAL_LEVEL == 0 */            


_END_C_LIB_DECL

#ifdef __cplusplus
  _EXTERN_CPP
  __EFF_NE    __ATTRIBUTES double abs(double);
  __EFF_NS    __ATTRIBUTES double pow(double, int);

  __EFF_NE    __ATTRIBUTES float abs(float);
  __EFF_NS    __ATTRIBUTES float acos(float);
  __EFF_NS    __ATTRIBUTES float asin(float);
  __EFF_NS    __ATTRIBUTES float atan(float);
  __EFF_NS    __ATTRIBUTES float atan2(float, float);
  __EFF_NE    __ATTRIBUTES float ceil(float);
  __EFF_NS    __ATTRIBUTES float cos(float);
  __EFF_NS    __ATTRIBUTES float cosh(float);
  __EFF_NS    __ATTRIBUTES float exp(float);
  __EFF_NE    __ATTRIBUTES float fabs(float);
  __EFF_NE    __ATTRIBUTES float floor(float);
  __EFF_NS    __ATTRIBUTES float fmod(float, float);
  __EFF_NENR2 __ATTRIBUTES float frexp(float, int *);
  __EFF_NS    __ATTRIBUTES float ldexp(float, int);
  __EFF_NS    __ATTRIBUTES float log(float);
  __EFF_NS    __ATTRIBUTES float log10(float);
  __EFF_NENR2 __ATTRIBUTES float modf(float, float *);
  __EFF_NS    __ATTRIBUTES float pow(float, float);
  __EFF_NS    __ATTRIBUTES float pow(float, int);
  __EFF_NS    __ATTRIBUTES float sin(float);
  __EFF_NS    __ATTRIBUTES float sinh(float);
  __EFF_NS    __ATTRIBUTES float sqrt(float);
  __EFF_NS    __ATTRIBUTES float tan(float);
  __EFF_NS    __ATTRIBUTES float tanh(float);
  __EFF_NS    __ATTRIBUTES float acosh(float);
  __EFF_NS    __ATTRIBUTES float asinh(float);
  __EFF_NS    __ATTRIBUTES float atanh(float);
  __EFF_NE    __ATTRIBUTES float cbrt(float);
  __EFF_NE    __ATTRIBUTES float copysign(float, float);
  #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
    __EFF_NS    __ATTRIBUTES float erf(float);
    __EFF_NS    __ATTRIBUTES float erfc(float);
    __EFF_NS    __ATTRIBUTES float expm1(float);
  #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
  __EFF_NS    __ATTRIBUTES float exp2(float);
  __EFF_NE    __ATTRIBUTES float fdim(float, float);
  #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
    __EFF_NS    __ATTRIBUTES float fma(float, float, float);
  #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
  __EFF_NE    __ATTRIBUTES float fmax(float, float);
  __EFF_NE    __ATTRIBUTES float fmin(float, float);
  __EFF_NS    __ATTRIBUTES float hypot(float, float);
  __EFF_NE    __ATTRIBUTES int   ilogb(float);
  #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
    __EFF_NS    __ATTRIBUTES float lgamma(float);
  #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */

  #ifdef _LONGLONG
    #pragma language=save
    #pragma language=extended
    __EFF_NS    __ATTRIBUTES _Longlong llrint(float);
    __EFF_NS    __ATTRIBUTES _Longlong llround(float);
    #pragma language=restore
  #endif /* _LONGLONG */

  __EFF_NS    __ATTRIBUTES float log1p(float);
  __EFF_NS    __ATTRIBUTES float log2(float);
  __EFF_NS    __ATTRIBUTES float logb(float);
  __EFF_NS    __ATTRIBUTES long  lrint(float);
  __EFF_NS    __ATTRIBUTES long  lround(float);
  __EFF_NS    __ATTRIBUTES float nearbyint(float);
  __EFF_NS    __ATTRIBUTES float nextafter(float, float);
  __EFF_NS    __ATTRIBUTES float nexttoward(float, long double);
  __EFF_NS    __ATTRIBUTES float remainder(float, float);
  __EFF_NS    __ATTRIBUTES float remquo(float, float, int *);
  __EFF_NS    __ATTRIBUTES float rint(float);
  __EFF_NE    __ATTRIBUTES float round(float);
  __EFF_NS    __ATTRIBUTES float scalbn(float, int);
  __EFF_NS    __ATTRIBUTES float scalbln(float, long);
  #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
    __EFF_NS    __ATTRIBUTES float tgamma(float);
  #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
  __EFF_NE    __ATTRIBUTES float trunc(float);

  __EFF_NE    __ATTRIBUTES long double abs(long double);
  __EFF_NS    __ATTRIBUTES long double acos(long double);
  __EFF_NS    __ATTRIBUTES long double asin(long double);
  __EFF_NS    __ATTRIBUTES long double atan(long double);
  __EFF_NS    __ATTRIBUTES long double atan2(long double, long double);
  __EFF_NE    __ATTRIBUTES long double ceil(long double);
  __EFF_NS    __ATTRIBUTES long double cos(long double);
  __EFF_NS    __ATTRIBUTES long double cosh(long double);
  __EFF_NS    __ATTRIBUTES long double exp(long double);
  __EFF_NE    __ATTRIBUTES long double fabs(long double);
  __EFF_NE    __ATTRIBUTES long double floor(long double);
  __EFF_NS    __ATTRIBUTES long double fmod(long double, long double);
  __EFF_NENR2 __ATTRIBUTES long double frexp(long double, int *);
  __EFF_NS    __ATTRIBUTES long double ldexp(long double, int);
  __EFF_NS    __ATTRIBUTES long double log(long double);
  __EFF_NS    __ATTRIBUTES long double log10(long double);
  __EFF_NENR2 __ATTRIBUTES long double modf(long double, long double *);
  __EFF_NS    __ATTRIBUTES long double pow(long double, long double);
  __EFF_NS    __ATTRIBUTES long double pow(long double, int);
  __EFF_NS    __ATTRIBUTES long double sin(long double);
  __EFF_NS    __ATTRIBUTES long double sinh(long double);
  __EFF_NS    __ATTRIBUTES long double sqrt(long double);
  __EFF_NS    __ATTRIBUTES long double tan(long double);
  __EFF_NS    __ATTRIBUTES long double tanh(long double);
  __EFF_NS    __ATTRIBUTES long double acosh(long double);
  __EFF_NS    __ATTRIBUTES long double asinh(long double);
  __EFF_NS    __ATTRIBUTES long double atanh(long double);
  __EFF_NE    __ATTRIBUTES long double cbrt(long double);
  __EFF_NE    __ATTRIBUTES long double copysign(long double, long double);
  #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
    __EFF_NS    __ATTRIBUTES long double erf(long double);
    __EFF_NS    __ATTRIBUTES long double erfc(long double);
    __EFF_NS    __ATTRIBUTES long double expm1(long double);
  #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
  __EFF_NS    __ATTRIBUTES long double exp2(long double);
  __EFF_NE    __ATTRIBUTES long double fdim(long double, long double);
  #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
    __EFF_NS    __ATTRIBUTES long double fma(long double, long double, 
                                             long double);
  #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
  __EFF_NE    __ATTRIBUTES long double fmax(long double, long double);
  __EFF_NE    __ATTRIBUTES long double fmin(long double, long double);
  __EFF_NS    __ATTRIBUTES long double hypot(long double, long double);
  __EFF_NE    __ATTRIBUTES int         ilogb(long double);
  #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
    __EFF_NS    __ATTRIBUTES long double lgamma(long double);
  #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */

  #ifdef _LONGLONG
    #pragma language=save
    #pragma language=extended
    __EFF_NS    __ATTRIBUTES _Longlong llrint(long double);
    __EFF_NS    __ATTRIBUTES _Longlong llround(long double);
    #pragma language=restore
  #endif /* _LONGLONG */

  __EFF_NS    __ATTRIBUTES long double log1p(long double);
  __EFF_NS    __ATTRIBUTES long double log2(long double);
  __EFF_NS    __ATTRIBUTES long double logb(long double);
  __EFF_NS    __ATTRIBUTES long lrint(long double);
  __EFF_NS    __ATTRIBUTES long lround(long double);
  __EFF_NS    __ATTRIBUTES long double nearbyint(long double);
  __EFF_NS    __ATTRIBUTES long double nextafter(long double, long double);
  __EFF_NS    __ATTRIBUTES long double nexttoward(long double, long double);
  __EFF_NS    __ATTRIBUTES long double remainder(long double, long double);
  __EFF_NS    __ATTRIBUTES long double remquo(long double, long double, int *);
  __EFF_NS    __ATTRIBUTES long double rint(long double);
  __EFF_NE    __ATTRIBUTES long double round(long double);
  __EFF_NS    __ATTRIBUTES long double scalbn(long double, int);
  __EFF_NS    __ATTRIBUTES long double scalbln(long double, long);
  #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
    __EFF_NS    __ATTRIBUTES long double tgamma(long double);
  #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
  __EFF_NE    __ATTRIBUTES long double trunc(long double);

  _END_EXTERN_CPP
#endif /* __cplusplus */


#if   defined(__cplusplus)
   
  _EXTERN_CPP
  /* C++ definitions */

    #pragma inline=forced
    inline double abs(double _X)    /* OVERLOADS */
    {       /* return absolute value */
      return (fabs(_X));
    }

    #pragma inline=forced
    inline double pow(double _X, int _Y)
    {       /* raise to integer power */
      unsigned int _N = _Y;
      if (_Y < 0)
        _N = 0 - _N;
      
      for (double _Z = 1; ; _X *= _X)
      {
        if ((_N & 1) != 0)
          _Z *= _X;
        if ((_N >>= 1) == 0)
          return (_Y < 0 ? (_Z == 0.0 ? HUGE_VAL : (double)(1) / _Z) : _Z);
      }
    }

    #pragma inline=forced
    inline float abs(float _X)      /* OVERLOADS */
    {       /* return absolute value */
      return (_F_FUN(fabs)(_F_CAST _X));
    }

    #pragma inline=forced
    inline float acos(float _X)
    {       /* return arccosine */
      return (_F_FUN(acos)(_F_CAST _X));
    }

    #pragma inline=forced
    inline float asin(float _X)
    {       /* return arcsine */
      return (_F_FUN(asin)(_F_CAST _X));
    }

    #pragma inline=forced
    inline float atan(float _X)
    {       /* return arctangent */
      return (_F_FUN(atan)(_F_CAST _X));
    }

    #pragma inline=forced
    inline float atan2(float _Y, float _X)
    {       /* return arctangent */
      return (_F_FUN(atan2)(_F_CAST _Y,_F_CAST  _X));
    }

    #pragma inline=forced
    inline float ceil(float _X)
    {       /* return ceiling */
      return (_F_FUN(ceil)(_F_CAST _X));
    }

    #pragma inline=forced
    inline float cos(float _X)
    {       /* return cosine */
      return (_F_FUN(cos)(_F_CAST _X));
    }

    #pragma inline=forced
    inline float cosh(float _X)
    {       /* return hyperbolic cosine */
      return (_F_FUN(cosh)(_F_CAST _X));
    }

    #pragma inline=forced
    inline float exp(float _X)
    {       /* return exponential */
      return (_F_FUN(exp)(_F_CAST _X));
    }

    #pragma inline=forced
    inline float fabs(float _X)
    {       /* return absolute value */
      return (_F_FUN(fabs)(_F_CAST _X));
    }

    #pragma inline=forced
    inline float floor(float _X)
    {       /* return floor */
      return (_F_FUN(floor)(_F_CAST _X));
    }

    #pragma inline=forced
    inline float fmod(float _X, float _Y)
    {       /* return modulus */
      return (_F_FUN(fmod)(_F_CAST _X,_F_CAST  _Y));
    }

    #pragma inline=forced
    inline float frexp(float _X, int *_Y)
    {       /* unpack exponent */
      return (_F_FUN(frexp)(_F_CAST _X, _Y));
    }

    #pragma inline=forced
    inline float ldexp(float _X, int _Y)
    {       /* pack exponent */
      return (_F_FUN(ldexp)(_F_CAST _X, _Y));
    }

    #pragma inline=forced
    inline float log(float _X)
    {       /* return natural logarithm */
      return (_F_FUN(log)(_F_CAST _X));
    }

    #pragma inline=forced
    inline float log10(float _X)
    {       /* return base-10 logarithm */
      return (_F_FUN(log10)(_F_CAST _X));
    }

    #pragma inline=forced
    inline float modf(float _X, float *_Y)
    {       /* unpack fraction */
      return (_F_FUN(modf)(_F_CAST _X,_F_PTRCAST  _Y));
    }

    #pragma inline=forced
    inline float pow(float _X, float _Y)
    {       /* raise to power */
      return (_F_FUN(pow)(_F_CAST _X,_F_CAST  _Y));
    }

    #pragma inline=forced
    inline float pow(float _X, int _Y)
    {       /* raise to integer power */
    #ifdef _FLOAT_IS_DOUBLE
      return (float) pow((double) _X, _Y);
    #else
      unsigned int _N = _Y;
      if (_Y < 0)
        _N = 0 - _N;
  
      for (float _Z = 1; ; _X *= _X)
      {
        if ((_N & 1) != 0)
          _Z *= _X;
        if ((_N >>= 1) == 0)
          return _Y < 0 ? (_Z == 0.0F ? (float)HUGE_VAL : (float)(1) / _Z) : _Z;
      }
    #endif /* _FLOAT_IS_DOUBLE */
    }

    #pragma inline=forced
    inline float sin(float _X)
    {       /* return sine */
      return (_F_FUN(sin)(_F_CAST _X));
    }

    #pragma inline=forced
    inline float sinh(float _X)
    {       /* return hyperbolic sine */
      return (_F_FUN(sinh)(_F_CAST _X));
    }

    #pragma inline=forced
    inline float sqrt(float _X)
    {       /* return square root */
      return (_F_FUN(sqrt)(_F_CAST _X));
    }

    #pragma inline=forced
    inline float tan(float _X)
    {       /* return tangent */
      return (_F_FUN(tan)(_F_CAST _X));
    }

    #pragma inline=forced
    inline float tanh(float _X)
    {       /* return hyperbolic tangent */
      return (_F_FUN(tanh)(_F_CAST _X));
    }

    #pragma inline=forced
    inline float acosh(float _Left)
    {       // return hyperbolic arccosine
      return (_F_FUN(acosh)(_F_CAST _Left));
    }

    #pragma inline=forced
    inline float asinh(float _Left)
    {       // return hyperbolic arcsine
      return (_F_FUN(asinh)(_F_CAST _Left));
    }

    #pragma inline=forced
    inline float atanh(float _Left)
    {       // return hyperbolic arctangent
      return (_F_FUN(atanh)(_F_CAST _Left));
    }

    #pragma inline=forced
    inline float cbrt(float _Left)
    {       // return cube root
      return (_F_FUN(cbrt)(_F_CAST _Left));
    }

    #pragma inline=forced
    inline float copysign(float _Left, float _Right)
    {       // return copysign
      return (_F_FUN(copysign)(_F_CAST _Left, _F_CAST _Right));
    }

    #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
      #pragma inline=forced
      inline float erf(float _Left)
      {       // return erf
        return (_F_FUN(erf)(_F_CAST _Left)); 
      }

      #pragma inline=forced
      inline float erfc(float _Left)
      {       // return erfc
        return (_F_FUN(erfc)(_F_CAST _Left));
      }

      #pragma inline=forced
      inline float expm1(float _Left)
      {       // return expml
        return (_F_FUN(expm1)(_F_CAST _Left));
      }
    #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */

    #pragma inline=forced
    inline float exp2(float _Left)
    {       // return exp2
      return (_F_FUN(exp2)(_F_CAST _Left));
    }

    #pragma inline=forced
    inline float fdim(float _Left, float _Right)
    {       // return fdim
      return (_F_FUN(fdim)(_F_CAST _Left, _F_CAST _Right));
    }

    #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
      #pragma inline=forced
      inline float fma(float _Left, float _Right, float _Addend)
      {       // return fma
        return (_F_FUN(fma)(_F_CAST _Left, _F_CAST _Right, _F_CAST _Addend));
      }
    #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */

    #pragma inline=forced
    inline float fmax(float _Left, float _Right)
    {       // return fmax
      return (_F_FUN(fmax)(_F_CAST _Left, _F_CAST _Right));
    }

    #pragma inline=forced
    inline float fmin(float _Left, float _Right)
    {       // return fmin
      return (_F_FUN(fmin)(_F_CAST _Left, _F_CAST _Right));
    }

    #pragma inline=forced
    inline float hypot(float _Left, float _Right)
    {       // return hypot
      return (_F_FUN(hypot)(_F_CAST _Left, _F_CAST _Right));
    }

    #pragma inline=forced
    inline int ilogb(float _Left)
    {       // return ilogb
      return (_F_FUN(ilogb)(_F_CAST _Left));
    }

    #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
      #pragma inline=forced
      inline float lgamma(float _Left)
      {       // return lgamma
        return (_F_FUN(lgamma)(_F_CAST _Left));
      }
    #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */

    #ifdef _LONGLONG
      #pragma language=save
      #pragma language=extended
      #pragma inline=forced
      inline _Longlong llrint(float _Left)
      {       // return llrint
        return (_F_FUN(llrint)(_F_CAST _Left));
      }

      #pragma inline=forced
      inline _Longlong llround(float _Left)
      {       // return llround
        return (_F_FUN(llround)(_F_CAST _Left));
      }
      #pragma language=restore
    #endif /* _LONGLONG */

    #pragma inline=forced
    inline float log1p(float _Left)
    {       // return loglp
      return (_F_FUN(log1p)(_F_CAST _Left));
    }

    #pragma inline=forced
    inline float log2(float _Left)
    {       // return log2
      return (_F_FUN(log2)(_F_CAST _Left));
    }

    #pragma inline=forced
    inline float logb(float _Left)
    {       // return logb
      return (_F_FUN(logb)(_F_CAST _Left));
    }

    #pragma inline=forced
    inline long lrint(float _Left)
    {       // return lrint
      return (_F_FUN(lrint)(_F_CAST _Left));
    }

    #pragma inline=forced
    inline long lround(float _Left)
    {       // return lround
      return (_F_FUN(lround)(_F_CAST _Left));
    }

    #pragma inline=forced
    inline float nearbyint(float _Left)
    {       // return nearbyint
      return (_F_FUN(nearbyint)(_F_CAST _Left));
    }

    #pragma inline=forced
    inline float nextafter(float _Left, float _Right)
    {       // return nextafter
      return (_F_FUN(nextafter)(_F_CAST _Left, _F_CAST _Right));
    }

    #pragma inline=forced
    inline float nexttoward(float _Left, long double _Right)
    {       // return nexttoward
      return (_F_FUN(nexttoward)(_F_CAST _Left, _F_CAST _Right));
    }

    #pragma inline=forced
    inline float remainder(float _Left, float _Right)
    {       // return remainder
      return (_F_FUN(remainder)(_F_CAST _Left, _F_CAST _Right));
    }

    #pragma inline=forced
    inline float remquo(float _Left, float _Right, int *_Pval)
    {       // return remquo
      return (_F_FUN(remquo)(_F_CAST _Left, _F_CAST _Right, _Pval));
    }

    #pragma inline=forced
    inline float rint(float _Left)
    {       // return rint
      return (_F_FUN(rint)(_F_CAST _Left));
    }

    #pragma inline=forced
    inline float round(float _Left)
    {       // return round
      return (_F_FUN(round)(_F_CAST _Left));
    }

    #pragma inline=forced
    inline float scalbn(float _Left, int _Right)
    {       // return scalbn
      return (_F_FUN(scalbn)(_F_CAST _Left, _Right));
    }

    #pragma inline=forced
    inline float scalbln(float _Left, long _Right)
    {       // return scalbln
      return (_F_FUN(scalbln)(_F_CAST _Left, _Right));
    }

    #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
      #pragma inline=forced
      inline float tgamma(float _Left)
      {       // return tgamma
        return (_F_FUN(tgamma)(_F_CAST _Left));
      }
    #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */

    #pragma inline=forced
    inline float trunc(float _Left)
    {       // return trunc
      return (_F_FUN(trunc)(_F_CAST _Left));
    }

    #pragma inline=forced
    inline long double abs(long double _X)  /* OVERLOADS */
    {       /* return absolute value */
      return (_L_FUN(fabs)(_L_CAST _X));
    }

    #pragma inline=forced
    inline long double acos(long double _X)
    {       /* return arccosine */
      return (_L_FUN(acos)(_L_CAST _X));
    }

    #pragma inline=forced
    inline long double asin(long double _X)
    {       /* return arcsine */
      return (_L_FUN(asin)(_L_CAST _X));
    }

    #pragma inline=forced
    inline long double atan(long double _X)
    {       /* return arctangent */
      return (_L_FUN(atan)(_L_CAST _X));
    }

    #pragma inline=forced
    inline long double atan2(long double _Y, long double _X)
    {       /* return arctangent */
      return (_L_FUN(atan2)(_L_CAST _Y, _L_CAST _X));
    }

    #pragma inline=forced
    inline long double ceil(long double _X)
    {       /* return ceiling */
      return (_L_FUN(ceil)(_L_CAST _X));
    }

    #pragma inline=forced
    inline long double cos(long double _X)
    {       /* return cosine */
      return (_L_FUN(cos)(_L_CAST _X));
    }

    #pragma inline=forced
    inline long double cosh(long double _X)
    {       /* return hyperbolic cosine */
      return (_L_FUN(cosh)(_L_CAST _X));
    }

    #pragma inline=forced
    inline long double exp(long double _X)
    {       /* return exponential */
      return (_L_FUN(exp)(_L_CAST _X));
    }

    #pragma inline=forced
    inline long double fabs(long double _X)
    {       /* return absolute value */
      return (_L_FUN(fabs)(_L_CAST _X));
    }

    #pragma inline=forced
    inline long double floor(long double _X)
    {       /* return floor */
      return (_L_FUN(floor)(_L_CAST _X));
    }

    #pragma inline=forced
    inline long double fmod(long double _X, long double _Y)
    {       /* return modulus */
      return (_L_FUN(fmod)(_L_CAST _X,_L_CAST _Y));
    }

    #pragma inline=forced
    inline long double frexp(long double _X, int *_Y)
    {       /* unpack exponent */
      return (_L_FUN(frexp)(_L_CAST _X, _Y));
    }

    #pragma inline=forced
    inline long double ldexp(long double _X, int _Y)
    {       /* pack exponent */
      return (_L_FUN(ldexp)(_L_CAST _X, _Y));
    }

    #pragma inline=forced
    inline long double log(long double _X)
    {       /* return natural logarithm */
      return (_L_FUN(log)(_L_CAST _X));
    }

    #pragma inline=forced
    inline long double log10(long double _X)
    {       /* return base-10 logarithm */
      return (_L_FUN(log10)(_L_CAST _X));
    }

    #pragma inline=forced
    inline long double modf(long double _X, long double *_Y)
    {       /* unpack fraction */
      return (_L_FUN(modf)(_L_CAST _X, _L_PTRCAST _Y));
    }

    #pragma inline=forced
    inline long double pow(long double _X, long double _Y)
    {       /* raise to power */
      return (_L_FUN(pow)(_L_CAST _X, _L_CAST _Y));
    }

    #pragma inline=forced
    inline long double pow(long double _X, int _Y)
    {       /* raise to integer power */
    #ifdef _LONG_DOUBLE_IS_DOUBLE
      return (long double) pow((double) _X, _Y);
    #else
      unsigned int _N = _Y;
      if (_Y < 0)
        _N = 0 - _N;
      
      for (long double _Z = 1; ; _X *= _X)
      {
        if ((_N & 1) != 0)
          _Z *= _X;
        if ((_N >>= 1) == 0)
          return _Y < 0 
            ? (_Z == 0.0L 
               ? (long double)HUGE_VAL 
               : (long double)(1) / _Z) 
            : _Z;
      }
    #endif /* _LONG_DOUBLE_IS_DOUBLE */
    }

    #pragma inline=forced
    inline long double sin(long double _X)
    {       /* return sine */
      return (_L_FUN(sin)(_L_CAST _X));
    }

    #pragma inline=forced
    inline long double sinh(long double _X)
    {       /* return hyperbolic sine */
      return (_L_FUN(sinh)(_L_CAST _X));
    }

    #pragma inline=forced
    inline long double sqrt(long double _X)
    {       /* return square root */
      return (_L_FUN(sqrt)(_L_CAST _X));
    }

    #pragma inline=forced
    inline long double tan(long double _X)
    {       /* return tangent */
      return (_L_FUN(tan)(_L_CAST _X));
    }

    #pragma inline=forced
    inline long double tanh(long double _X)
    {       /* return hyperbolic tangent */
      return (_L_FUN(tanh)(_L_CAST _X));
    }

    #pragma inline=forced
    inline long double acosh(long double _Left)
    {   // return acosh
      return (_F_FUN(acosh)(_L_CAST _Left));
    }

    #pragma inline=forced
    inline long double asinh(long double _Left)
    {   // return asinh
      return (_F_FUN(asinh)(_L_CAST _Left));
    }

    #pragma inline=forced
    inline long double atanh(long double _Left)
    {       // return atanh
      return (_F_FUN(atanh)(_L_CAST _Left));
    }

    #pragma inline=forced
    inline long double cbrt(long double _Left)
    {       // return cbrt
      return (_F_FUN(cbrt)(_L_CAST _Left));
    }

    #pragma inline=forced
    inline long double copysign(long double _Left, long double _Right)
    {       // return copysign
      return (_F_FUN(copysign)(_L_CAST _Left, _L_CAST _Right));
    }

    #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
      #pragma inline=forced
      inline long double erf(long double _Left)
      {       // return erf
        return (_F_FUN(erf)(_L_CAST _Left));
      }

      #pragma inline=forced
      inline long double erfc(long double _Left)
      {       // return erfc
        return (_F_FUN(erfc)(_L_CAST _Left));
      }

      #pragma inline=forced
      inline long double expm1(long double _Left)
      {       // return expml
        return (_F_FUN(expm1)(_L_CAST _Left));
      }
    #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */

    #pragma inline=forced
    inline long double exp2(long double _Left)
    {       // return exp2
      return (_F_FUN(exp2)(_L_CAST _Left));
    }

    #pragma inline=forced
    inline long double fdim(long double _Left, long double _Right)
    {       // return fdim
      return (_F_FUN(fdim)(_L_CAST _Left, _L_CAST _Right));
    }

    #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
      #pragma inline=forced
      inline long double fma(long double _Left, long double _Right,
                             long double _Addend)
      {       // return fma
        return (_F_FUN(fma)(_L_CAST _Left, _L_CAST _Right, _L_CAST _Addend));
      }
    #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */

    #pragma inline=forced
    inline long double fmax(long double _Left, long double _Right)
    {       // return fmax
      return (_F_FUN(fmax)(_L_CAST _Left, _L_CAST _Right));
    }

    #pragma inline=forced
    inline long double fmin(long double _Left, long double _Right)
    {       // return fmin
      return (_F_FUN(fmin)(_L_CAST _Left, _L_CAST _Right));
    }

    #pragma inline=forced
    inline long double hypot(long double _Left, long double _Right)
    {       // return hypot
      return (_F_FUN(hypot)(_L_CAST _Left, _L_CAST _Right));
    }

    #pragma inline=forced
    inline int ilogb(long double _Left)
    {       // return ilogb
      return (_F_FUN(ilogb)(_L_CAST _Left));
    }

    #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
      #pragma inline=forced
      inline long double lgamma(long double _Left)
      {       // return lgamma
        return (_F_FUN(lgamma)(_L_CAST _Left));
      }
    #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */

    #ifdef _LONGLONG
      #pragma language=save
      #pragma language=extended
      #pragma inline=forced
      inline _Longlong llrint(long double _Left)
      {       // return llrint
        return (_F_FUN(llrint)(_L_CAST _Left));
      }

      #pragma inline=forced
      inline _Longlong llround(long double _Left)
      {       // return llround
        return (_F_FUN(llround)(_L_CAST _Left));
      } 
      #pragma language=restore
    #endif /* _LONGLONG */

    #pragma inline=forced
    inline long double log1p(long double _Left)
    {       // return loglp
      return (_F_FUN(log1p)(_L_CAST _Left));
    }

    #pragma inline=forced
    inline long double log2(long double _Left)
    {       // return log2
      return (_F_FUN(log2)(_L_CAST _Left));
    }

    #pragma inline=forced
    inline long double logb(long double _Left)
    {       // return logb
      return (_F_FUN(logb)(_L_CAST _Left));
    }

    #pragma inline=forced
    inline long lrint(long double _Left)
    {       // return lrint
      return (_F_FUN(lrint)(_L_CAST _Left));
    }

    #pragma inline=forced
    inline long lround(long double _Left)
    {       // return lround
      return (_F_FUN(lround)(_L_CAST _Left));
    }

    #pragma inline=forced
    inline long double nearbyint(long double _Left)
    {       // return nearbyint
      return (_F_FUN(nearbyint)(_L_CAST _Left));
    }

    #pragma inline=forced
    inline long double nextafter(long double _Left, long double _Right)
    {       // return nextafter
      return (_F_FUN(nextafter)(_L_CAST _Left, _L_CAST _Right));
    }

    #pragma inline=forced
    inline long double nexttoward(long double _Left, long double _Right)
    {       // return nexttoward
      return (_F_FUN(nexttoward)(_L_CAST _Left, _L_CAST _Right));
    }

    #pragma inline=forced
    inline long double remainder(long double _Left, long double _Right)
    {       // return remainder
      return (_F_FUN(remainder)(_L_CAST _Left, _L_CAST _Right));
    }

    #pragma inline=forced
    inline long double remquo(long double _Left, long double _Right,
                              int *_Pval)
    {       // return remquo
      return (_F_FUN(remquo)(_L_CAST _Left, _L_CAST _Right, _Pval));
    }

    #pragma inline=forced
    inline long double rint(long double _Left)
    {       // return rint
      return (_F_FUN(rint)(_L_CAST _Left));
    }

    #pragma inline=forced
    inline long double round(long double _Left)
    {       // return round
      return (_F_FUN(round)(_L_CAST _Left));
    }

    #pragma inline=forced
    inline long double scalbn(long double _Left, int _Right)
    {       // return scalbn
      return (_F_FUN(scalbn)(_L_CAST _Left, _Right));
    }

    #pragma inline=forced
    inline long double scalbln(long double _Left, long _Right)
    {       // return scalbln
      return (_F_FUN(scalbln)(_L_CAST _Left, _Right));
    }

    #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
      #pragma inline=forced
      inline long double tgamma(long double _Left)
      {       // return tgamma
        return (_F_FUN(tgamma)(_L_CAST _Left));
      }
    #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */

    #pragma inline=forced
    inline long double trunc(long double _Left)
    {       // return trunc
      return (_F_FUN(trunc)(_L_CAST _Left));
    }

  _END_EXTERN_CPP
#endif /* defined(__cplusplus) */


#if !defined(_NO_DEFINITIONS_IN_HEADER_FILES) && \
    !__AEABI_PORTABILITY_INTERNAL_LEVEL
                /* double INLINES, FOR C and C++ */

/* C inline definitions */

  #pragma inline=no_body
  double cos(double _X)
  {       /* return cosine */
    return _D_FNAME(Sin)(_X, 1);
  }

  #pragma inline=no_body
  double cosh(double _X)
  {       /* return hyperbolic cosine */
    return _D_FNAME(Cosh)(_X, 1);
  }

  #pragma inline=no_body
  double log(double _X)
  {       /* return natural logarithm */
    return _D_FNAME(Log)(_X, 0);
  }

  #pragma inline=no_body
  double log10(double _X)
  {       /* return base-10 logarithm */
    return _D_FNAME(Log)(_X, 1);
  }

  #pragma inline=no_body
  double sin(double _X)
  {       /* return sine */
    return _D_FNAME(Sin)(_X, 0);
  }

  #pragma inline=no_body
  double sinh(double _X)
  {       /* return hyperbolic sine */
    return _D_FNAME(Sinh)(_X, 1);
  }


                /* double INLINES, FOR C99 and C++ */
  #if _DLIB_ADD_C99_SYMBOLS
    #pragma inline=no_body
    double log2(double _Left)
    {   /* return base-2 logarithm */
      return (_D_FNAME(Log)(_Left, -1));
    }

    #pragma inline=no_body
    double nan(const char *s)
    {   /* construct a NaN */
      return (0.Nan);
    }

    #pragma inline=no_body
    double nextafter(double x, double y)
    {   /* compute next value after x going toward y */
      return (nexttoward(x, (long double)y));
    }

    #pragma inline=no_body
    double remainder(double x, double y)
    {   /* compute remainder of x/y */
      return (remquo(x, y, 0));
    }

  #endif /* _DLIB_ADD_C99_SYMBOLS */

                /* float INLINES, FOR C and C++ */
  #if _DLIB_ADD_C99_SYMBOLS
    #pragma inline=no_body
    float cosf(float _X)
    {       /* return cosine */
      return (_F_FNAME(Sin)(_X, 1));
    }

    #pragma inline=no_body
    float coshf(float _X)
    {       /* return hyperbolic cosine */
      return (_F_FNAME(Cosh)(_X, _F_CAST 1.0F));
    }

    #pragma inline=no_body
    float logf(float _X)
    {       /* return natural logarithm */
      return (_F_FNAME(Log)(_X, 0));
    }

    #pragma inline=no_body 
    float log2f(float _Left)
    {       /* return base-2 logarithm */
      return (_F_FNAME(Log)(_Left, -1));
    }

    #pragma inline=no_body
    float log10f(float _X)
    {       /* return base-10 logarithm */
      return (_F_FNAME(Log)(_X, 1));
    }

    #pragma inline=no_body
    float nanf(const char *s)
    {   /* construct a NaN */
      return (0.Nan);
    }

    #pragma inline=no_body
    float nextafterf(float x, float y)
    {   /* compute next value after x going toward y */
      return (nexttowardf(x, (long double)y));
    }

    #pragma inline=no_body
    float remainderf(float x, float y)
    {   /* compute remainder of x/y */
      return (remquof(x, y, 0));
    }

    #pragma inline=no_body
    float sinf(float _X)
    {       /* return sine */
      return (_F_FNAME(Sin)(_X, 0));
    }

    #pragma inline=no_body
    float sinhf(float _X)
    {       /* return hyperbolic sine */
      return (_F_FNAME(Sinh)(_X, _F_CAST 1.0F));
    }
  #endif /* _DLIB_ADD_C99_SYMBOLS */

                /* long double INLINES, FOR C and C++ */
  #if _DLIB_ADD_C99_SYMBOLS
    #pragma inline=no_body
    long double cosl(long double _X)
    {       /* return cosine */
      return (_L_FNAME(Sin)(_X, 1));
    }

    #pragma inline=no_body
    long double coshl(long double _X)
    {       /* return hyperbolic cosine */
      return (_L_FNAME(Cosh)(_X, _L_CAST 1.0L));
    }

    #pragma inline=no_body
    long double logl(long double _X)
    {       /* return natural logarithm */
      return (_L_FNAME(Log)(_X, 0));
    }

    #pragma inline=no_body 
    long double log2l(long double _Left)
    {       /* return base-2 logarithm */
      return (_L_FNAME(Log)(_Left, -1));
    }

    #pragma inline=no_body
    long double log10l(long double _X)
    {       /* return base-10 logarithm */
      return (_L_FNAME(Log)(_X, 1));
    }

    #pragma inline=no_body
    long double nanl(const char *s)
    {   /* construct a NaN */
      return (0.Nan);
    }

    #pragma inline=no_body
    long double nextafterl(long double x, long double y)
    {   /* compute next value after x going toward y */
      return (nexttowardl(x, y));
    }

    #pragma inline=no_body
    long double remainderl(long double x, long double y)
    {   /* compute remainder of x/y */
      return (remquol(x, y, 0));
    }

    #pragma inline=no_body
    long double sinl(long double _X)
    {       /* return sine */
      return (_L_FNAME(Sin)(_X, 0));
    }

    #pragma inline=no_body
    long double sinhl(long double _X)
    {       /* return hyperbolic sine */
      return (_L_FNAME(Sinh)(_X, _L_CAST 1.0L));
    }
  #endif /* _DLIB_ADD_C99_SYMBOLS */

#endif /* !defined(_NO_DEFINITIONS_IN_HEADER_FILES) && \
          !__AEABI_PORTABILITY_INTERNAL_LEVEL */

#if _DLIB_ADD_C99_SYMBOLS

  /* C99 floating point functionality */

  #define FP_INFINITE  _INFCODE
  #define FP_NAN       _NANCODE
  #define FP_NORMAL    _FINITE
  #define FP_SUBNORMAL _DENORM
  #define FP_ZERO      0

  #define _FP_ILOGBNAN __SIGNED_INT_MAX__
  #define _FP_ILOGB0   __SIGNED_INT_MIN__

  #define MATH_ERRNO 1
  #define MATH_ERREXCEPT 2
  #ifndef math_errhandling
    #define math_errhandling MATH_ERRNO
  #endif

  #if _DLIB_FAST_FMA
    #define FP_FAST_FMA  1
    #define FP_FAST_FMAF 1
    #define FP_FAST_FMAL 1
  #endif /* _DLIB_FAST_FMA */

  #define FP_ILOGB0     _FP_ILOGB0
  #define FP_ILOGBNAN   _FP_ILOGBNAN

  /* For generic C99 compare operations */
  #define _FP_LT 1
  #define _FP_EQ 2
  #define _FP_GT 4  
  
  _C_LIB_DECL
  __EFF_NS    __ATTRIBUTES int _D_FNAME(Dcomp)(double, double);
  #ifndef _FLOAT_IS_DOUBLE
    __EFF_NS    __ATTRIBUTES int _F_FNAME(Dcomp)(float, float);
  #endif
  #ifndef _LONG_DOUBLE_IS_DOUBLE
    __EFF_NS    __ATTRIBUTES int _L_FNAME(Dcomp)(long double, long double);
  #endif
  _END_C_LIB_DECL
  
  #if _HAS_GENERIC_TEMPLATES
  
    _EXTERN_CPP

//    #if !defined(_NO_DEFINITIONS_IN_HEADER_FILES) && !__AEABI_PORTABILITY_INTERNAL_LEVEL    
    
      // TEMPLATE FUNCTION _FPCOMP
      inline int _FPCOMP(float _Left, float _Right)
      {   // compare _Left and _Right
        return (_F_FNAME(Dcomp)(_Left, _Right));
      }

      inline int _FPCOMP(double _Left, double _Right)
      {   // compare _Left and _Right
        return (_D_FNAME(Dcomp)(_Left, _Right));
      }

      inline int _FPCOMP(long double _Left, long double _Right)
      {       // compare _Left and _Right
        return (_L_FNAME(Dcomp)(_Left, _Right));
      }

      template<class _T1, class _T2> inline
      int _FPCOMP(_T1 _Left, _T2 _Right)
      {       // compare _Left and _Right
        typedef typename _Combined_type<
          float,
          typename _Real_widened<
            typename _Real_type<_T1>::_Type,
            typename _Real_type<_T2>::_Type>::_Type>::_Type _Tw;
        return (_FPCOMP((_Tw)_Left, (_Tw)_Right));
      }

      // FUNCTION fpclassify
      inline int fpclassify(float _Left)
      {       // classify argument
        return (_F_FNAME(Dtest)(_Left));
      }

      inline int fpclassify(double _Left)
      {       // classify argument
        return (_D_FNAME(Dtest)(_Left));
      }

      inline int fpclassify(long double _Left)
      {       // classify argument
        return (_L_FNAME(Dtest)(_Left));
      }

      // FUNCTION signbit
      inline bool signbit(float _Left)
      {       // test sign bit
        return (_F_FNAME(Dsign)(_Left) != 0);
      }

      inline bool signbit(double _Left)
      {       // test sign bit
        return (_D_FNAME(Dsign)(_Left) != 0);
      }

      inline bool signbit(long double _Left)
      {       // test sign bit
        return (_L_FNAME(Dsign)(_Left) != 0);
      }

      template<class _Ty> inline
      bool isfinite(_Ty _Left)
      {       // test for finite
        return (fpclassify(_Left) <= 0);
      }

      template<class _Ty> inline
      bool isinf(_Ty _Left)
      {       // test for infinite
        return (fpclassify(_Left) == FP_INFINITE);
      }

      template<class _Ty> inline
      bool isnan(_Ty _Left)
      {       // test for NaN
        return (fpclassify(_Left) == FP_NAN);
      }

      template<class _Ty> inline
      bool isnormal(_Ty _Left)
      {       // test for normal
        return (fpclassify(_Left) == FP_NORMAL);
      }

      template<class _Ty1, class _Ty2> inline
      bool isgreater(_Ty1 _Left, _Ty2 _Right)
      {       // test for _Left > _Right
        return ((_FPCOMP(_Left, _Right) & _FP_GT) != 0);
      }

      template<class _Ty1, class _Ty2> inline
      bool isgreaterequal(_Ty1 _Left, _Ty2 _Right)
      {       // test for _Left >= _Right
        return ((_FPCOMP(_Left, _Right) & (_FP_EQ | _FP_GT)) != 0);
      }

      template<class _Ty1, class _Ty2> inline
      bool isless(_Ty1 _Left, _Ty2 _Right)
      {       // test for _Left < _Right
        return ((_FPCOMP(_Left, _Right) & _FP_LT) != 0);
      }

      template<class _Ty1, class _Ty2> inline
      bool islessequal(_Ty1 _Left, _Ty2 _Right)
      {       // test for _Left <= _Right
        return ((_FPCOMP(_Left, _Right) & (_FP_LT | _FP_EQ)) != 0);
      }

      template<class _Ty1, class _Ty2> inline
      bool islessgreater(_Ty1 _Left, _Ty2 _Right)
      {       // test for _Left != _Right
        return ((_FPCOMP(_Left, _Right) & (_FP_LT | _FP_GT)) != 0);
      }

      template<class _Ty1, class _Ty2> inline
      bool isunordered(_Ty1 _Left, _Ty2 _Right)
      {       // test for _Left unorderd w.r.t. _Right
        return (_FPCOMP(_Left, _Right) == 0);
      }
      
//    #endif /* !defined(_NO_DEFINITIONS_IN_HEADER_FILES) && !__AEABI_PORTABILITY_INTERNAL_LEVEL */

    #define fpclassify(x)                 (_CSTD fpclassify(x))
    #define signbit(x)                    (_CSTD signbit(x))
    #define isfinite(x)                   (_CSTD isfinite(x))
    #define isinf(x)                      (_CSTD isinf(x))
    #define isnan(x)                      (_CSTD isnan(x))
    #define isnormal(x)                   (_CSTD isnormal(x))
    #define isgreater(x, y)               (_CSTD isgreater(x, y))
    #define isgreaterequal(x, y)          (_CSTD isgreaterequal(x, y))
    #define isless(x, y)                  (_CSTD isless(x, y))
    #define islessequal(x, y)             (_CSTD islessequal(x, y))
    #define islessgreater(x, y)           (_CSTD islessgreater(x, y))
    #define isunordered(x, y)             (_CSTD isunordered(x, y))

    _END_EXTERN_CPP

  #else /* _HAS_GENERIC_TEMPLATES */
  
    #define _CARGI(x, fd, ff, fl) __c99_generic(x,,, fd, ff, fl,,,)(x)
    #define _CARG2I(x, y, fd, ff, fl) __c99_generic(x, y,, fd, ff, fl,,,)(x, y)
      
    #define _FPCOMP(x, y) _CARG2I(x, y, _D_FNAME(Dcomp), \
                                        _F_FNAME(Dcomp), \
                                        _L_FNAME(Dcomp))
    #define fpclassify(x) _CARGI(x, _D_FNAME(Dtest), \
                                    _F_FNAME(Dtest), \
                                    _L_FNAME(Dtest))
    #define signbit(x)    _CARGI(x, _D_FNAME(Dsign), \
                                    _F_FNAME(Dsign), \
                                    _L_FNAME(Dsign))

    #define isfinite(x)   (fpclassify(x) <= 0)
    #define isinf(x)      (fpclassify(x) == FP_INFINITE)
    #define isnan(x)      (fpclassify(x) == FP_NAN)
    #define isnormal(x)   (fpclassify(x) == FP_NORMAL)

    #define isgreater(x, y)       ((_FPCOMP(x, y) & _FP_GT) != 0)
    #define isgreaterequal(x, y)  ((_FPCOMP(x, y) & (_FP_EQ | _FP_GT)) != 0)
    #define isless(x, y)          ((_FPCOMP(x, y) & _FP_LT) != 0)
    #define islessequal(x, y)     ((_FPCOMP(x, y) & (_FP_LT | _FP_EQ)) != 0)
    #define islessgreater(x, y)   ((_FPCOMP(x, y) & (_FP_LT | _FP_GT)) != 0)
    #define isunordered(x, y)      (_FPCOMP(x, y) == 0)      
    
  #endif /* _HAS_GENERIC_TEMPLATES */

  #pragma inline=no_body
  int _D_FNAME(Dcomp)(double x, double y)
  {
    if (isnan(x) || isnan(y))
    {
      return 0;
    }
    if (x > y)
    {
      return _FP_GT;
    }
    if (x < y)
    {
      return _FP_LT;
    }
    if (x == y)
    {
      return _FP_EQ;
    }
    return 0;
  }

  #ifndef _FLOAT_IS_DOUBLE
    #pragma inline=no_body
    int _F_FNAME(Dcomp)(float x, float y)
    {
      if (isnan(x) || isnan(y))
      {
        return 0;
      }
      if (x > y)
      {
        return _FP_GT;
      }
      if (x < y)
      {
        return _FP_LT;
      }
      if (x == y)
      {
        return _FP_EQ;
      }
      return 0;
    }
  #endif /* _FLOAT_IS_DOUBLE */

  #ifndef _LONG_DOUBLE_IS_DOUBLE
    #pragma inline=no_body
    int _L_FNAME(Dcomp)(long double x, long double y)
    {
      if (isnan(x) || isnan(y))
      {
        return 0;
      }
      if (x > y)
      {
        return _FP_GT;
      }
      if (x < y)
      {
        return _FP_LT;
      }
      if (x == y)
      {
        return _FP_EQ;
      }
      return 0;
    }
  #endif /* _LONG_DOUBLE_IS_DOUBLE */

#endif /* _DLIB_ADD_C99_SYMBOLS */
_C_STD_END

                /* GENERIC TEMPLATES */
#if _HAS_GENERIC_TEMPLATES
  _EXTERN_CPP
  _C_STD_BEGIN
        _TGEN_RC(acos)  // real or complex generic overloads
        _TGEN_RC(acosh)
        _TGEN_RC(asin)
        _TGEN_RC(asinh)
        _TGEN_RC(atan)
        _TGEN_RC(atanh)
        _TGEN_RC(cos)
        _TGEN_RC(cosh)
        _TGEN_RC(exp)
        _TGEN_RC0(fabs)
        _TGEN_RC(log)
        _TGEN_RC(log10)
        _TGEN_RC2(pow)
        _TGEN_RC(sin)
        _TGEN_RC(sinh)
        _TGEN_RC(sqrt)
        _TGEN_RC(tan)
        _TGEN_RC(tanh)

        _TGEN_R2(atan2) // real generic overloads
        _TGEN_R(cbrt)
        _TGEN_R(ceil)
        _TGEN_R2(copysign)
        #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
          _TGEN_R(erf)
          _TGEN_R(erfc)
          _TGEN_R(expm1)
        #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
        _TGEN_R(exp2)
        _TGEN_R2(fdim)
        _TGEN_R(floor)
        #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
          _TGEN_R3(fma)
        #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
        _TGEN_R2(fmax)
        _TGEN_R2(fmin)
        _TGEN_R2(fmod)
        _TGEN_RX(frexp, int *)
        _TGEN_R2(hypot)
        _TGEN_RI(ilogb, int)
        _TGEN_RX(ldexp, int)
        #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
          _TGEN_R(lgamma)
        #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
        #ifdef _LONGLONG
          #pragma language=save
          #pragma language=extended
          _TGEN_RI(llrint, _Longlong)
          _TGEN_RI(llround, _Longlong)
          #pragma language=restore
        #endif /* _LONGLONG */
        _TGEN_R(log1p)
        _TGEN_R(log2)
        _TGEN_R(logb)
        _TGEN_RI(lrint, long)
        _TGEN_RI(lround, long)
        _TGEN_R(nearbyint)
        _TGEN_R2(nextafter)
        _TGEN_RX(nexttoward, long double)
        _TGEN_R2(remainder)
        _TGEN_R2X(remquo, int *)
        _TGEN_R(rint)
        _TGEN_R(round)
        _TGEN_RX(scalbln, long)
        _TGEN_RX(scalbn, int)
        #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
          _TGEN_R(tgamma)
        #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
        _TGEN_R(trunc)
  _C_STD_END
  _END_EXTERN_CPP
#endif /* _HAS_GENERIC_TEMPLATES */

#endif /* _MATH */


#if defined(_STD_USING) && defined(__cplusplus)
  using _CSTD abs;

  using _CSTD acos; using _CSTD asin;
  using _CSTD atan; using _CSTD atan2; using _CSTD ceil;
  using _CSTD cos; using _CSTD cosh; using _CSTD exp;
  using _CSTD fabs; using _CSTD floor; using _CSTD fmod;
  using _CSTD frexp; using _CSTD ldexp; using _CSTD log;
  using _CSTD log10; using _CSTD modf; using _CSTD pow;
  using _CSTD sin; using _CSTD sinh; using _CSTD sqrt;
  using _CSTD tan; using _CSTD tanh;

  #if _DLIB_ADD_C99_SYMBOLS
    using _CSTD acosf; using _CSTD asinf;
    using _CSTD atanf; using _CSTD atan2f; using _CSTD ceilf;
    using _CSTD cosf; using _CSTD coshf; using _CSTD expf;
    using _CSTD fabsf; using _CSTD floorf; using _CSTD fmodf;
    using _CSTD frexpf; using _CSTD ldexpf; using _CSTD logf;
    using _CSTD log10f; using _CSTD modff; using _CSTD powf;
    using _CSTD sinf; using _CSTD sinhf; using _CSTD sqrtf;
    using _CSTD tanf; using _CSTD tanhf;

    using _CSTD acosl; using _CSTD asinl;
    using _CSTD atanl; using _CSTD atan2l; using _CSTD ceill;
    using _CSTD cosl; using _CSTD coshl; using _CSTD expl;
    using _CSTD fabsl; using _CSTD floorl; using _CSTD fmodl;
    using _CSTD frexpl; using _CSTD ldexpl; using _CSTD logl;
    using _CSTD log10l; using _CSTD modfl; using _CSTD powl;
    using _CSTD sinl; using _CSTD sinhl; using _CSTD sqrtl;
    using _CSTD tanl; using _CSTD tanhl;

    using _CSTD acosh; using _CSTD asinh; using _CSTD atanh;
    using _CSTD cbrt; using _CSTD exp2;
    using _CSTD hypot; using _CSTD ilogb;
    using _CSTD log1p; using _CSTD log2; using _CSTD logb;
    #ifdef _LONGLONG
      using _CSTD llrint; using _CSTD llround; 
    #endif /* _LONGLONG */
    using _CSTD lrint; using _CSTD nearbyint;
    using _CSTD rint; using _CSTD lround;
    using _CSTD fdim; using _CSTD fmax; using _CSTD fmin;
    using _CSTD round; using _CSTD trunc;
    using _CSTD remainder; using _CSTD remquo;
    using _CSTD copysign; using _CSTD nan; using _CSTD nextafter;
    using _CSTD scalbn; using _CSTD scalbln; using _CSTD nexttoward;

    using _CSTD acoshf; using _CSTD asinhf; using _CSTD atanhf;
    using _CSTD cbrtf; using _CSTD exp2f;
    using _CSTD hypotf; using _CSTD ilogbf;
    using _CSTD log1pf; using _CSTD log2f; using _CSTD logbf;
    #ifdef _LONGLONG
      using _CSTD llrintf; using _CSTD llroundf; 
    #endif /* _LONGLONG*/
    using _CSTD lrintf; using _CSTD nearbyintf;
    using _CSTD rintf; using _CSTD lroundf;
    using _CSTD fdimf; using _CSTD fmaxf; using _CSTD fminf;
    using _CSTD roundf; using _CSTD truncf;
    using _CSTD remainderf; using _CSTD remquof;
    using _CSTD copysignf; using _CSTD nanf;
    using _CSTD nextafterf; using _CSTD scalbnf; using _CSTD scalblnf;
    using _CSTD nexttowardf;

    using _CSTD acoshl; using _CSTD asinhl; using _CSTD atanhl;
    using _CSTD cbrtl; using _CSTD exp2l;
    using _CSTD hypotl; using _CSTD ilogbl;
    using _CSTD log1pl; using _CSTD log2l; using _CSTD logbl;
    #ifdef _LONGLONG
      using _CSTD llrintl; using _CSTD llroundl; 
    #endif /* _LONGLONG */
    using _CSTD lrintl; using _CSTD nearbyintl;
    using _CSTD rintl; using _CSTD lroundl;
    using _CSTD fdiml; using _CSTD fmaxl; using _CSTD fminl;
    using _CSTD roundl; using _CSTD truncl;
    using _CSTD remainderl; using _CSTD remquol;
    using _CSTD copysignl; using _CSTD nanl;
    using _CSTD nextafterl; using _CSTD scalbnl; using _CSTD scalblnl;
    using _CSTD nexttowardl;

    using _CSTD float_t; using _CSTD double_t;

    #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH
      using _CSTD erf; using _CSTD erfc;
      using _CSTD erff; using _CSTD erfcf;
      using _CSTD erfl; using _CSTD erfcl;
      using _CSTD expm1; using _CSTD expm1f; using _CSTD expm1l;
      using _CSTD lgamma; using _CSTD lgammaf; using _CSTD lgammal;
      using _CSTD tgamma; using _CSTD tgammaf; using _CSTD tgammal;
      using _CSTD fma; using _CSTD fmaf; using _CSTD fmal;
    #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH */
    #if _HAS_GENERIC_TEMPLATES
      using _CSTD _FPCOMP; using _CSTD fpclassify;
      using _CSTD signbit; using _CSTD isfinite; using _CSTD isinf;
      using _CSTD isnan; using _CSTD isnormal;
      using _CSTD isgreater; using _CSTD isgreaterequal;
      using _CSTD isless; using _CSTD islessequal; using _CSTD islessgreater;
      using _CSTD isunordered;
    #endif /* _HAS_GENERIC_TEMPLATES */
  #endif /* _DLIB_ADD_C99_SYMBOLS */

  #if !defined(_NO_DEFINITIONS_IN_HEADER_FILES)    
  
    #if _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH && \
        !defined(_DLIB_DO_NOT_ADD_ACCURATE_FUNCTIONS)
      using _CSTD __iar_tan_accurate; using _CSTD __iar_cos_accurate;
      using _CSTD __iar_sin_accurate; using _CSTD __iar_pow_accurate;
      using _CSTD __iar_Sin_accurate; using _CSTD __iar_Pow_accurate;
      #if _DLIB_ADD_C99_SYMBOLS
        using _CSTD __iar_tan_accuratef; using _CSTD __iar_cos_accuratef;
        using _CSTD __iar_sin_accuratef; using _CSTD __iar_pow_accuratef;
        using _CSTD __iar_Sin_accuratef; using _CSTD __iar_Pow_accuratef;
        using _CSTD __iar_tan_accuratel; using _CSTD __iar_cos_accuratel;
        using _CSTD __iar_sin_accuratel; using _CSTD __iar_pow_accuratel;
        using _CSTD __iar_Sin_accuratel; using _CSTD __iar_Pow_accuratel;
      #endif /* _DLIB_ADD_C99_SYMBOLS */
    #endif /* _DLIB_ALLOW_LARGE_CONSTANT_TABLES_FOR_MATH &&
              !defined(_DLIB_DO_NOT_ADD_ACCURATE_FUNCTIONS) */

    #ifndef _DLIB_DO_NOT_ADD_SMALL_FUNCTIONS
      using _CSTD __iar_cos_small; using _CSTD __iar_exp_small;
      using _CSTD __iar_log_small; using _CSTD __iar_log10_small;
      using _CSTD __iar_pow_small; using _CSTD __iar_sin_small;
      using _CSTD __iar_tan_small; using _CSTD __iar_log2_small;
      #if _DLIB_ADD_C99_SYMBOLS
        using _CSTD __iar_cos_smallf; using _CSTD __iar_exp_smallf;
        using _CSTD __iar_log_smallf; using _CSTD __iar_log10_smallf;
        using _CSTD __iar_pow_smallf; using _CSTD __iar_sin_smallf;
        using _CSTD __iar_tan_smallf; using _CSTD __iar_log2_smallf;

        using _CSTD __iar_cos_smalll; using _CSTD __iar_exp_smalll;
        using _CSTD __iar_log_smalll; using _CSTD __iar_log10_smalll;
        using _CSTD __iar_pow_smalll; using _CSTD __iar_sin_smalll;
        using _CSTD __iar_tan_smalll; using _CSTD __iar_log2_smalll;
      #endif /* _DLIB_ADD_C99_SYMBOLS */
    #endif /* _DLIB_DO_NOT_ADD_SMALL_FUNCTIONS */

  #endif  /* !defined(_NO_DEFINITIONS_IN_HEADER_FILES) */
    
  using _CSTD _D_FNAME(Dcomp);
  using _CSTD _F_FNAME(Dcomp);
  using _CSTD _L_FNAME(Dcomp);

  #if __AEABI_PORTABILITY_INTERNAL_LEVEL
    using _CSTD __aeabi_HUGE_VAL;
    #if _DLIB_ADD_C99_SYMBOLS
      using _CSTD __aeabi_HUGE_VALF;
      using _CSTD __aeabi_HUGE_VALL;
      using _CSTD __aeabi_INFINITY;
      using _CSTD __aeabi_NAN;
    #endif /* _DLIB_ADD_C99_SYMBOLS */
  #endif

#endif /* defined(_STD_USING) && defined(__cplusplus) */

/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.04:0576 */
