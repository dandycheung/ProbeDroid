/**
 *   The MIT License (MIT)
 *   Copyright (C) 2016 ZongXian Shen <andy.zsshen@gmail.com>
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a
 *   copy of this software and associated documentation files (the "Software"),
 *   to deal in the Software without restriction, including without limitation
 *   the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *   and/or sell copies of the Software, and to permit persons to whom the
 *   Software is furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in
 *   all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *   THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 *   IN THE SOFTWARE.
 */

#ifndef _LOGCAT_H_
#define _LOGCAT_H_


#include "log.h"
#include "macros.h"


#define CAT(severity) SpewCat(__FILE__, __LINE__, severity).stream()

class SpewCat
{
  public:
    SpewCat(const char* file, int line, LogSeverity severity)
     : severity_(severity),
       line_(line),
       file_(file)
    {}

    ~SpewCat();

    std::ostream& stream()
    {
        return buffer_;
    }

  private:
    LogSeverity severity_;
    int line_;
    const char* file_;
    std::ostringstream buffer_;

    DISALLOW_COPY_AND_ASSIGN(SpewCat);
};


#endif