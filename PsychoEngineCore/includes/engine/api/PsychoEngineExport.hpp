
#ifndef PE_API_H
#define PE_API_H

#ifdef PE_STATIC
#  define PE_API
#  define PE_NO_EXPORT
#else
#  ifndef PE_API
#    ifdef PsychoEngineCore_s_EXPORTS
        /* We are building this library */
#      define PE_API 
#    else
        /* We are using this library */
#      define PE_API 
#    endif
#  endif

#  ifndef PE_NO_EXPORT
#    define PE_NO_EXPORT 
#  endif
#endif

#ifndef PE_API_DEP
#  define PE_API_DEP __attribute__ ((__deprecated__))
#endif

#ifndef PE_API_DEP_EXPORT
#  define PE_API_DEP_EXPORT PE_API PE_API_DEP
#endif

#ifndef PE_API_DEP_NO_EXPORT
#  define PE_API_DEP_NO_EXPORT PE_NO_EXPORT PE_API_DEP
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef PSYCHOENGINECORE_S_NO_DEPRECATED
#    define PSYCHOENGINECORE_S_NO_DEPRECATED
#  endif
#endif

#endif /* PE_API_H */
