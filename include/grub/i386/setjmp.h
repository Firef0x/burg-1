/*
 *  GRUB  --  GRand Unified Bootloader
 *  Copyright (C) 2003,2006,2007,2009  Free Software Foundation, Inc.
 *
 *  GRUB is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  GRUB is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GRUB.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GRUB_SETJMP_CPU_HEADER
#define GRUB_SETJMP_CPU_HEADER	1

typedef unsigned long grub_jmp_buf[6];

#if defined(__MINGW32__) || defined (APPLE_CC)
int grub_setjmp (grub_jmp_buf env) __attribute__ ((cdecl, regparm (3)));
#else
int grub_setjmp (grub_jmp_buf env) __attribute__ ((returns_twice, cdecl,
						   regparm (3)));
#endif
void grub_longjmp (grub_jmp_buf env, int val) __attribute__ ((noreturn, cdecl,
							      regparm (3)));

#endif /* ! GRUB_SETJMP_CPU_HEADER */
