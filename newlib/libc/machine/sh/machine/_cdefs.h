/*-
 * Copyright (c) 2012-2026 Israel Jacquez <mrkotfw@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef _SYS_CDEFS_H_
#error "must be included via <sys/cdefs.h>"
#endif /* !_SYS_CDEFS_H_ */

/* These attributes are supported on the SH family of processors: */

#ifndef __interrupt_handler
#define __interrupt_handler __attribute__ ((interrupt_handler))
#endif /* !__interrupt_handler */

#ifndef __nosave_low_regs
#define __nosave_low_regs __attribute__ ((nosave_low_regs))
#endif /* !__nosave_low_regs */

#ifndef __trap_exit
#define __trap_exit __attribute__ ((trap_exit))
#endif /* !__trap_exit */

#ifndef __trapa_handler
#define __trapa_handler __attribute__ ((trapa_handler))
#endif /* !__trapa_handler */
