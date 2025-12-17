#pragma once

#ifndef _WIN32
    #ifdef NEBULA_PLUGIN_EXPORTS
        #define NUBELA_API __declspec(dllexport)
    #else
        #define NUBELA_API __declspec(dllimport)
    #endif
#else
    #define NUBELA_API 
#endif

namespace nebula {

   class NUBELA_API Plugin {
    public:
        virtual ~Plugin() = default;
        virtual const char* name() const = 0;
        virtual void on_load() = 0;
    };

    using CreatePluginFunc = Plugin* (*)();
};