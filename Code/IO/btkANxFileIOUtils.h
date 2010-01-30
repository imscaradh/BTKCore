/* 
 * The Biomechanical ToolKit
 * Copyright (c) 2009-2010, Arnaud Barré
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

#ifndef __btkANxFileIOUtils_h
#define __btkANxFileIOUtils_h

#include "btkAcquisition.h"
#include "btkException.h"
#include <vector>

#ifdef _MSC_VER
  #include "../../Utilities/stdint.h"
#else
  #include <stdint.h>
#endif

namespace btk
{
  class ANxFileIOException : public Exception
  {
  public:
    explicit ANxFileIOException(const std::string& msg)
    : Exception(msg)
    {};
      
    virtual ~ANxFileIOException() throw() {};
  };
  
  void ANxFileIOCheckHeader(double preciseRate, int channelNumber, 
                            const std::vector<uint16_t>& channelRate, 
                            const std::vector<uint16_t>& channelRange);
  void ANxFileIOStoreHeader(Acquisition::Pointer output,
                            double preciseRate, int frameNumber, int channelNumber,
                            const std::vector<std::string>& channelLabel,
                            const std::vector<uint16_t>& channelRate,
                            const std::vector<uint16_t>& channelRange,
                            const std::string& boardType, int bitDepth, int gen = 2);
  void ANxFileIOExtractForcePlatformChannel(std::vector< std::vector<int16_t> >& fpChan, 
                            Acquisition::Pointer output, const char** labels, int num);
  void ANxFileIOExtractForcePlatformChannel(std::vector< std::vector<int16_t> >& fpChan, 
                            Acquisition::Pointer output, const std::string& prefix, const char** labels, int num);
  void ANxFileIOExtractForcePlatformChannel(std::vector< std::vector<int16_t> >& fpChan, 
                            Acquisition::Pointer output, const std::vector<std::string>& labels);
  int ANxFileIOFindAnalogLabeCaselInsensitive(const std::string& label, Acquisition::Pointer output);
  uint16_t ANxFileIODetectAnalogRange(double s, int bitDepth);

};

#endif // __btkANxFileIOUtils_h
