/* main.cc: defines main() for c, cc, etc
    Copyright (C) 2024-2024 Silly Software Foundation.

This file is part of SAS.

SAS is free software; you can redistribute it and/or modify it under
the terms of the BSD 3-Clause License as shown in the LICENCE file.

SAS is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warrenty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE. See the BSD 3-Clause Licence
for more details.

You should have received a copy of the BSD 3-Clause
along with SAS; see the file LICENCE. If not see
<https://raw.githubusercontent.com/sillysoftware/sas/refs/heads/master/LICENSE> */

#include "error.h"
#include <cassert>
#include <cstdio>
#include <cstring>
#include <optional>
#include <string>
#include <iostream>
#include <vector>

struct pflags {
    bool help {false};
    bool repl {false};
    bool assembly {false};
    bool verbose {false};
    bool expand {false};
    bool obj {false};
    std::optional<std::string> outfile;
};

pflags parse_args(const std::vector<std::string>& argv) {
    pflags flags;
    for (size_t i = 1; i < argv.size(); ++i) {
        const std::string& arg = argv[i];
        if (arg == "--help" || arg == "-h") {
            flags.help = true;
        } 
        else if (arg == "--repl" || arg == "-R") {
            flags.repl = true;
        } 
        else if (arg == "-S") {
            flags.assembly = true;
        }
        else if (arg == "-E") {
            flags.expand = true;
        }
        else if (arg == "-c") {
            flags.obj = true;
        }
        else if (arg == "-o") {
            if (i + 1 < argv.size()) {
                flags.outfile = argv[i + 1];
                i++;
            } else {
                error("missing filename after '-o'");
                return flags;
            }
        }
    }

    return flags;
}

int main(int argc, char *argv[]) {
    std::vector<std::string> args;
    for (int i = 0; i < argc; ++i) {
        args.push_back(std::string(argv[i]));
    }
    if (argc < 2) {
        fatal_error("no input files");
    }
    pflags flags = parse_args(args);
    if (flags.help) {
        std::string help = "Usage: scc [options] file...\n\n";
        help += "Options:\n";
        help += "  -h, --help\tPrints out the help and exit.\n";
        help += "  -R, --repl\tEnables the REPL.\n";
        help += "  -o <file>\tPlace the output into <file>.\n";
        help += "  -S\t\tCompile only; do not assemble or link.\n";
        help += "  -E\t\tPreproccess only; do not compile, assemble or link.\n";
        help += "  -c\t\tCompile and assemble, but do not link.\n";
        help += "\nIf any bugs are found during use of this software report them to:\n<https://github.com/sillysoftware/scc/issues>";
        std::cout << help << std::endl;
        exit(0);
    }
}
