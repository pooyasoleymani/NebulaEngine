#!/usr/bin/env python3

import platform

def is_windows():
    return platform.system() == "Windows"

def is_linux():
    return platform.system() == "Linux"

def is_macos():
    return platform.system() == "Darwin"
