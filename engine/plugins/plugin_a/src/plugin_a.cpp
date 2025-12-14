#include <nebula/core.hpp>
#include <iostream>


namespace nebula {

    class PluginA {
        public:
            void info() {
                std::cout << "Plugin A loaded!" << std::endl;
            }
    };  
}; // namespace nebula