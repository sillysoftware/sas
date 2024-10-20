/* error.h: defines error handel functions for c, cc, etc
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

#ifndef ERROR_H
#define ERROR_H

#ifdef __cplusplus
extern "C" {
#endif

/* fatal_error()
* @param char* The input string
* @return void
*/
void fatal_error(const char *message);

/* error()
* @param char* The input string
* @return void
*/
void error(const char *message);

/* warning()
* @param char* The input string
* @return void
*/
void warning(const char *message);

/* debug()
* @param tag The tag of the debug message
* @param message The input string
* @return void
*/
void debug(const char *tag, const char *message);

#ifdef __cplusplus
}
#endif
#endif
