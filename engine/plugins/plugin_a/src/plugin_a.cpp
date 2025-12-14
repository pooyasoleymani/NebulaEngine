#include <nebula/plugin_api.hpp>
#include <iostream>


namespace nebula {

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
}; // namespace nebula

extern "C" NUBELA_API nebula::Plugin* create_plugin() {
    return new nebula::PluginA();
}
