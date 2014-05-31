/* 
   Example.c
   
   This is a basic use example and test of Tsunami.
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

#include <stdint.h>
#include "Tsunami.h"

int main(void)
{
	TsunamiInitialise();

	TsunamiStartTimeline("MyTimeline", "Test.vcd", (1 * 1024 * 1024));
	{
		uint32_t i, q;
		
		for (i = 0; i < 32; i ++) {
			/* Basic value dumping */
			TsunamiSetValue(i, "MyTimeline", "root.basic.value");
			
			/* Pulse values */
			if (i & 0x1)
				TsunamiPulseValue(1, "MyTimeline", "root.pulse.value");

			/* Formatted-name value dumping */
			q = 0;
			TsunamiSetValue((i * 0.25), "MyTimeline", "root.format_test.signal[%i]", q);
			q = 1;
			TsunamiSetValue((i * 0.5), "MyTimeline", "root.format_test.signal[%i]", q);

			/* Advance timeline */
			TsunamiAdvanceTimeline("MyTimeline");
		}
	}
	TsunamiFinishTimeline("MyTimeline");	

	TsunamiStartTimeline("MyTimeline2", "Test2.vcd", (1 * 1024 * 1024));
	{
		uint32_t i, q;
		
		for (i = 0; i < 32; i ++) {
			/* Basic value dumping */
			TsunamiSetValue(i, "MyTimeline2", "root.basic.value");
			
			/* Pulse values */
			if (i & 0x1)
				TsunamiPulseValue(1, "MyTimeline2", "root.pulse.value");

			/* Formatted-name value dumping */
			q = 0;
			TsunamiSetValue((i * 1), "MyTimeline2", "root.format_test.signal[%i]", q);
			q = 1;
			TsunamiSetValue((i * 2), "MyTimeline2", "root.format_test.signal[%i]", q);
			q = 2;
			TsunamiSetValue((i * 4), "MyTimeline2", "root.format_test.signal[%i]", q);

			/* Advance timeline */
			TsunamiAdvanceTimeline("MyTimeline2");
		}
	}
	TsunamiFinishTimeline("MyTimeline2");

	return 0;
}
