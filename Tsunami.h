/* ================================================================================ */
/*                                                                                 	*/
/*                         ` ` `                                                   	*/
/*                      ...... ` ` `  `               `                            	*/
/*                   ,/////\\\\\   ` `       `                                      */
/*                 ,///      `\\\\ 	` `                                             */
/*               ,////  ,       `\\\                                                */
/*             ,///   /	,,`,   	 `\\\\           `                                  */
/*            ///  	/,,/  ,`,` `   ````                     `                       */
/*           /,,  /,/  /,`/	`/``                                                    */
/*	\__..._//, 	   ___________                                .__    `              */
/*     /////// /,..\__    ___/_______ __  ____ _____    _____ |__|                  */
/*	// 	   	 ,,,,    |    | /  ___/  |  \/    \\__  \  /     \|  |                  */
/*  \_____....,	     |    | \___ \|  |  /   |  \/ __ \|  Y Y  \  |                  */
/*                   |____|/____  >____/|___|  (____  /__|_|  /__|        `         */
/*                              \/           \/     \/      \/                      */
/*                                                                                  */
/* ================================================================================ */
/* 
   Tsunami.h
   
   Defines the public interface to Tsunami
*/
/* 
   The MIT License (MIT)
   
   Copyright (c) 2014 James A. McCombe

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:
   
   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.
   
   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.   
*/

#ifndef __TSUNAMI_HEADER___
#define __TSUNAMI_HEADER__

/* ================================================================================ */
/* Master enable switch                                                             */
/* By disabling here, Tsunami disappears from your software entirely through
   empty stub macros replacing the real Tsunami APIs                                */

#ifndef TSUNAMI_ENABLE
#define TSUNAMI_ENABLE      1
#endif

/* ================================================================================ */

/* Required includes */
#include "TsunamiPrivate.h"

#ifdef __cplusplus
extern "C" {
#endif

#if TSUNAMI_ENABLE

/* ================================================================================ */
/* Public Tsunami API                                                               */
/* ================================================================================ */
void TsunamiInitialise(void);
void TsunamiStartTimeline(const char *timeline_name, const char *filename, uint32_t log_size_bytes);
void TsunamiFinishTimeline(const char *timeline_name);
void TsunamiAdvanceTimeline(const char *timeline_name);
void TsunamiUpdateTimelineToRealtime(const char *timeline_name);

#if _WIN32

#define TsunamiSetValue(_value_, _timeline_name_, _value_format_, ...) \
	TsunamiSetValue_Base_Internal(0, 0, 0, _value_, _timeline_name_, _value_format_, __VA_ARGS__)
#define TsunamiIncrementValue(_increment_, _timeline_name_, _value_format_, ...) \
	TsunamiSetValue_Base_Internal(1, 0, 0, _increment_, _timeline_name_, _value_format_, __VA_ARGS__)
#define TsunamiPulseValue(_value_, _timeline_name_, _value_format_, ...) \
	TsunamiSetValue_Base_Internal(0, 1, 0, _value_, _timeline_name_, _value_format_, __VA_ARGS__)
#define TsunamiSetRange(_range_, _timeline_name_, _value_format_, ...) \
	TsunamiSetValue_Base_Internal(0, 0, 1, _range_, _timeline_name_, _value_format_, __VA_ARGS__)	
#else
	
#define TsunamiSetValue(_value_, _timeline_name_, _value_format_, args...) \
	TsunamiSetValue_Base_Internal(0, 0, 0, _value_, _timeline_name_, _value_format_, ##args)
#define TsunamiIncrementValue(_increment_, _timeline_name_, _value_format_, args...) \
	TsunamiSetValue_Base_Internal(1, 0, 0, _increment_, _timeline_name_, _value_format_, ##args)
#define TsunamiPulseValue(_value_, _timeline_name_, _value_format_, args...) \
	TsunamiSetValue_Base_Internal(0, 1, 0, _value_, _timeline_name_, _value_format_, ##args)
#define TsunamiSetRange(_range_, _timeline_name_, _value_format_, args...) \
	TsunamiSetValue_Base_Internal(0, 0, 1, _range_, _timeline_name_, _value_format_, ##args)	

#endif

/* ================================================================================ */

#endif /* TSUNAMI_ENABLE */

#ifdef __cplusplus
}
#endif

#endif
