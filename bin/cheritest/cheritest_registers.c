/*-
 * Copyright (c) 2012-2014 Robert N. M. Watson
 * Copyright (c) 2014 SRI International
 * All rights reserved.
 *
 * This software was developed by SRI International and the University of
 * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)
 * ("CTSRD"), as part of the DARPA CRASH research programme.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>

#if !__has_feature(capabilities)
#error "This code requires a CHERI-aware compiler"
#endif

#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/time.h>

#include <machine/cheri.h>
#include <machine/cheric.h>
#include <machine/cpuregs.h>

#include <cheri/cheri_fd.h>
#include <cheri/sandbox.h>

#include <cheritest-helper.h>
#include <err.h>
#include <fcntl.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <unistd.h>

#include "cheritest.h"

void
cheritest_copyregs(void)
{

	CHERI_CGETDEFAULT(2);
	CHERI_CGETDEFAULT(3);
	CHERI_CGETDEFAULT(4);
	CHERI_CGETDEFAULT(5);
	CHERI_CGETDEFAULT(6);
	CHERI_CGETDEFAULT(7);
	cheritest_success();
}

void
cheritest_listregs(void)
{

	/*
	 * Because of the assembly generated by CP2_CR_GET(), can't use a loop
	 * -- register numbers must be available at compile-time.
	 */
	printf("CP2 registers:\n");
	CHERI_CAPREG_PRINT(0);
	CHERI_CAPREG_PRINT(1);
	CHERI_CAPREG_PRINT(2);
	CHERI_CAPREG_PRINT(3);
	CHERI_CAPREG_PRINT(4);
	CHERI_CAPREG_PRINT(5);
	CHERI_CAPREG_PRINT(6);
	CHERI_CAPREG_PRINT(7);
	CHERI_CAPREG_PRINT(8);
	CHERI_CAPREG_PRINT(9);
	CHERI_CAPREG_PRINT(10);
	CHERI_CAPREG_PRINT(11);
	CHERI_CAPREG_PRINT(12);
	CHERI_CAPREG_PRINT(13);
	CHERI_CAPREG_PRINT(14);
	CHERI_CAPREG_PRINT(15);
	CHERI_CAPREG_PRINT(16);
	CHERI_CAPREG_PRINT(17);
	CHERI_CAPREG_PRINT(18);
	CHERI_CAPREG_PRINT(19);
	CHERI_CAPREG_PRINT(20);
	CHERI_CAPREG_PRINT(21);
	CHERI_CAPREG_PRINT(22);
	CHERI_CAPREG_PRINT(23);
	CHERI_CAPREG_PRINT(24);
	CHERI_CAPREG_PRINT(25);
	CHERI_CAPREG_PRINT(26);
	CHERI_PCC_PRINT();
	cheritest_success();
}
