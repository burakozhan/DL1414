/**
 * DL1414 - Library for writing data on a DL1414 Display module
 * Created By Burak Özhan, 2016-Nov-14
 * Released with MIT License
 */
#ifndef DL1414_h
#define DL1414_h

#include "Arduino.h"

class DL1414 
{
	public:
		DL1414(int write, int addr0, int addr1, int data0, int data1, int data2, int data3, int data4, int data5, int data6);
		void writeByte(char a, byte column);
		void clear();
		void writeStringFix(String text);
		void writeStringScrolling(String text, int speed);
		void writeStringScrollingNoDelay(String text, int speed, long now);
		bool updateScrollingString(long now);
	private:
		int _write;
		int _addr0;
		int _addr1;
		int _data0;
		int _data1;
		int _data2;
		int _data3;
		int _data4;
		int _data5;
		int _data6;
		long _start;
		long _speed;
		byte *_noDelayBuffer;
		int _noDelayBufferLength;
		bool _scrollingTextIsSet;
};

#endif