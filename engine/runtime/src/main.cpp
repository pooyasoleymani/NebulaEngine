#include "pch.hpp"
#include "nebula/core.hpp"

int main() {
    nebula::Core core;

    std::cout << "Runtime started\n";
    std::cout << "Core version: " << core.version() << "\n";

    return 0;
}
