/* 
 * The Biomechanical ToolKit
 * Copyright (c) 2009-2012, Arnaud Barr�
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 *     * Redistributions of source code must retain the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 *     * Neither the name(s) of the copyright holders nor the names
 *       of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written
 *       permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef RemoveAnalogOffset_h
#define RemoveAnalogOffset_h

#include "../AbstractTool.h"

class RemoveAnalogOffset : public AbstractTool
{
public:
  static void RegisterTool(ToolsManager* manager);
  
  virtual bool run(ToolCommands* cmds, ToolsData* const data);
  
protected:
  typedef enum {FromReferenceFile = 0, FromSelectedFrames} Method;
  RemoveAnalogOffset(Method m, QWidget* parent = 0);
  
private:
  Method m_Method;
};

class RemoveAnalogOffsetFromReferenceFile : public RemoveAnalogOffset
{
public:
  RemoveAnalogOffsetFromReferenceFile(QWidget* parent = 0) : RemoveAnalogOffset(FromReferenceFile, parent) {};
};

class RemoveAnalogOffsetFromSelectedFrames : public RemoveAnalogOffset
{
public:
  RemoveAnalogOffsetFromSelectedFrames(QWidget* parent = 0) : RemoveAnalogOffset(FromSelectedFrames, parent) {};
};

#endif // RemoveAnalogOffset_h