#ifndef _HOOK_H_
#define _HOOK_H_


#include <jni.h>

#include "scoped_dl.h"


namespace hook {

enum {
    HOOK_SUCCESS = 0,
    HOOK_FAILURE = 1
};

class Bootstrap
{
  public:
    Bootstrap()
      : dex_path_(nullptr),
        handle_(nullptr)
    {}

    bool ResolveInjectorDeliveredSymbols();
    bool CraftDexPrivatePath();
    bool CreateDexPrivateDir();
    bool CacheJVM();
    bool LoadAnalysisModule();
    bool ResolveArtSymbol();
    bool DeployInstrumentGadgetComposer();

  private:
    void LogJNIException(JNIEnv*, jthrowable);

    static constexpr int kPrivateDexPerm = S_IRWXU | S_IRWXG | S_IXOTH;
    static constexpr const char* kDirDexData = "data";
    static constexpr const char* kDirInstrument = "instrument";
    static constexpr const char* kPathLibArt = "/system/lib/libart.so";
    static constexpr const char* kRecursiveExcept = "Exception occurs during "
                                                "exception message processing.";

    std::unique_ptr<char> dex_path_;
    ScopedDl handle_;
};

}

#endif