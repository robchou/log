#ifndef _JNI_HELPER_H
#define _JNI_HELPER_H

#include "log.h"

#ifdef __cplusplus
extern "C" {
#endif
#define FIND_CLASS(var, className)                                                                  \
        jclass mLocalRef = env->FindClass(className);                                               \
        var = (jclass)env->NewGlobalRef(mLocalRef);                                                 \
        env->DeleteLocalRef(mLocalRef);                                                             \
        LOG_FATAL_IF(! var, "%s:%u Error:Unable to find class %s", __FILE__, __LINE__, className)

#define GET_METHOD_ID(var, clazz, methodName, fieldDescriptor)                                      \
        var = env->GetMethodID(clazz, methodName, fieldDescriptor);                                 \
        LOG_FATAL_IF(! var, "%s:%u Error:Unable to find method %s", __FILE__, __LINE__, methodName)
#ifdef __cplusplus
}
#endif
#endif /* end of include guard: _JNI_HELPER_H */
