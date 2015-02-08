/* libhangul
 * Copyright (C) 2004 - 2009 Choe Hwanjin
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "hangul.h"

/**
 * @defgroup hangulctype 한글 글자 조작
 * 
 * @section hangulctype 한글 글자 조작
 * libhangul은 한글 각 글자를 구분하고 조작하는데 사용할 수 있는 몇가지 함수를
 * 제공한다.  libhangul의 글자 구분 함수의 인터페이스에서 글자의 기본 단위는
 * UCS4 코드값이다.
 */

/**
 * @file hangulctype.c
 */


