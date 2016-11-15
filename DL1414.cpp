/**
 * DL1414.cpp - Library for writing data on a DL1414 Display module
 * Created By Burak Özhan, 2016-Nov-14
 * Released with MIT License
 */
#include "Arduino.h"
#include "DL1414.h"

DL1414::DL1414(int write, int addr0, int addr1, int data0, int data1, int data2, int data3, int data4, int data5, int data6)
{
  _write = write;
  _addr0 = addr0;
  _addr1 = addr1;
  _data0 = data0;
  _data1 = data1;
  _data2 = data2;
  _data3 = data3;
  _data4 = data4;
  _data5 = data5;
  _data6 = data6;

	pinMode(write, OUTPUT);
  pinMode(addr0, OUTPUT);
  pinMode(addr1, OUTPUT);
  pinMode(data0, OUTPUT);
  pinMode(data1, OUTPUT);
  pinMode(data2, OUTPUT);
  pinMode(data3, OUTPUT);
  pinMode(data4, OUTPUT);
  pinMode(data5, OUTPUT);
  pinMode(data6, OUTPUT);
}

/**
 * Writes a Byte to a display of type DL1414.
 * Position of character is determined by the column parameter
 */
void DL1414::writeByte(char a, byte column){
  digitalWrite(_write, HIGH); // Make sure while changing pins write is disabled
  digitalWrite(_addr0, column >> 0 & B1);
  digitalWrite(_addr1, column >> 1 & B1);
  digitalWrite(_data0, a >> 0 & B1);
  digitalWrite(_data1, a >> 1 & B1);
  digitalWrite(_data2, a >> 2 & B1);
  digitalWrite(_data3, a >> 3 & B1);
  digitalWrite(_data4, a >> 4 & B1);
  digitalWrite(_data5, a >> 5 & B1);
  digitalWrite(_data6, a >> 6 & B1);
  digitalWrite(_write, LOW); // Enable write line
  delayMicroseconds(1);  // Wait at least 330ns (according to datasheet)
  digitalWrite(_write, HIGH); // Disable write again
}

/**
 * Empties screen of DL1414 Display.
 * Uses the space character.
 */
void DL1414::clear(){
    writeByte(32,0);
    writeByte(32,1);
    writeByte(32,2);
    writeByte(32,3);
}

/**
 * Writes a NON-scrolling String on the display. 
 * Only first 4 characters are displayed.
 */
void DL1414::writeStringFix(String text){
  // Add some simple padding so we don't see garbage.
  if (text.length() < 4){
    text += "    ";
  }
  byte b[text.length()];
  text.getBytes(b,text.length());
  writeByte(b[0],3);
  writeByte(b[1],2);
  writeByte(b[2],1);
  writeByte(b[3],0);
}

/**
 * Writes a scrolling String on the display. Adds spaces as padding.
 * Scrolling speed set by wait time in parameter speed.
 */
void DL1414::writeStringScrolling(String text, int speed){
  clear();
  text = "    "+text+"    ";
  int l = text.length()+1;
  byte b[l];
  text.getBytes(b,l);
  for(int i = 0; i<l-4; i++){
    writeByte(b[0+i],3);
    writeByte(b[1+i],2);
    writeByte(b[2+i],1);
    writeByte(b[3+i],0);
    delay(speed);
  }
  clear();
}

