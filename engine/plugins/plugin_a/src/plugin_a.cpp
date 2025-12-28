#include <nebula/plugin_api.hpp>
#include <iostream>


namespace nebula {

    /**
 * @brief PluginA class inherit from Plugin interface and ovrride 
 * on_load and name methods.
 */ 
    class PluginA: public Plugin {
        public:
            const char* name() const override {
                return "PluginA";
            }

            void on_load() override {
                info();
            }

        private:

            void info() {
                std::cout << "Plugin A loaded!" << std::endl;
            }
    };  

/**
 * @brief This function create Plugin.
 * @return Plugin*
 */ 
extern "C" NUBELA_API Plugin* CreatePlugin() {
    return new PluginA();
    }

/**
 * @brief This function destroy Plugin.
 * @return void
 */
extern "C" NUBELA_API void DestroyPlugin(Plugin* p) {
    delete p;
}
}; // namespace nebula