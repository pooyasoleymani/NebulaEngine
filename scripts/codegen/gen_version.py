#!/usr/bin/env python3

import sys
from pathlib import Path

out = Path(sys.argv[1])

out.parent.mkdir(parents=True, exist_ok=True)

out.write_text(
    """#pragma once

    namespace nebula {
    constexpr const char* BUILD_VERSION = "0.1.0";
}
"""
)

print(f"Generated {out}")