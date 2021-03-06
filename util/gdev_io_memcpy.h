/*
 * Copyright (C) Shinpei Kato and Yusuke Suzuki
 *
 * Nagoya University
 * Keio University
 *
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __GDEV_IO_MEMCPY_H__
#define __GDEV_IO_MEMCPY_H__

/* this ensures that SSE is not applied to memcpy. */
static inline void* gdev_io_memcpy(void* s1, const void* s2, size_t n)
{
    volatile char* out = (volatile char*)s1;
    const volatile char* in = (const volatile char*)s2;
    size_t i;
    for (i = 0; i < n; ++i) out[i] = in[i];
    return s1;
}

#endif  /* __GDEV_IO_MEMCPY_H__ */
