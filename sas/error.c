/* error.c: defines error handeling functions for c, cc, etc
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

#include <stdio.h>
#include <stdlib.h>
#include "error.h"

const char *RESET = "\033[0m";
const char *RED = "\033[1;91m";
const char *PURPLE = "\033[0;95m";

void fatal_error(const char *message) {
  fprintf(stderr, "sas: %sfatal error%s: %s\ncompilation terminated.\n", RED, RESET, message);
  exit(EXIT_FAILURE);
}

void error(const char *message) {
  fprintf(stderr, "sas: %serror%s: %s\n", RED, RESET, message);
}

void warning(const char *message) {
  fprintf(stderr, "sas: %swarning%s: %s\n", PURPLE, RESET, message);
}

void debug(const char *tag, const char*message) {
  printf("debug: %s:\n%s", tag, message);
}
