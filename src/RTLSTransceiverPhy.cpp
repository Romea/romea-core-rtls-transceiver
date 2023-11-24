// Copyright 2022 INRAE, French National Research Institute for Agriculture, Food and Environment
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include "romea_core_rtls_transceiver/RTLSTransceiverPhy.hpp"

#include <limits>
#include <algorithm>

namespace romea
{
namespace core
{

//-----------------------------------------------------------------------------
RTLSTransceiverPhy::RTLSTransceiverPhy(
  const double & centreFrequency,
  const double & dataRate,
  const double & bandWidth,
  const int & prf,
  const double & minimal_range,
  const double & maximal_range,
  const int & userPayloadMaximalLength) :

centreFrequency_(centreFrequency),
dataRate_(dataRate),
bandWidth_(bandWidth),
prf_(prf),
minimal_range_(minimal_range),
maximal_range_(maximal_range),
userPayloadMaximalLength_(userPayloadMaximalLength)
{
}

//-----------------------------------------------------------------------------
const int & RTLSTransceiverPhy::getUserPayloadMaximalLength()const
{
  return userPayloadMaximalLength_;
}

//-----------------------------------------------------------------------------
const double & RTLSTransceiverPhy::getCentreFrequency()const
{
  return centreFrequency_;
}

//-----------------------------------------------------------------------------
const double & RTLSTransceiverPhy::getDataRate()const
{
  return dataRate_;
}

//-----------------------------------------------------------------------------
const double & RTLSTransceiverPhy::getBandWidth()const
{
  return bandWidth_;
}

//-----------------------------------------------------------------------------
const int & RTLSTransceiverPhy::getPRF()const
{
  return prf_;
}

//-----------------------------------------------------------------------------
const double & RTLSTransceiverPhy::getMinimalRange()const
{
  return minimal_range_;
}

//-----------------------------------------------------------------------------
const double & RTLSTransceiverPhy::getMaximalRange()const
{
  return maximal_range_;
}

//-----------------------------------------------------------------------------
bool operator==(const RTLSTransceiverPhy & phy1, const RTLSTransceiverPhy & phy2)
{
  return std::abs(phy1.getCentreFrequency() - phy2.getCentreFrequency()) <
         std::numeric_limits<double>::epsilon() &&
         std::abs(phy1.getDataRate() - phy2.getDataRate()) <
         std::numeric_limits<double>::epsilon() &&
         std::abs(phy1.getBandWidth() - phy2.getBandWidth()) <
         std::numeric_limits<double>::epsilon() &&
         phy1.getPRF() == phy2.getPRF();
}

//-----------------------------------------------------------------------------
bool operator!=(const RTLSTransceiverPhy & phy1, const RTLSTransceiverPhy & phy2)
{
  return !(phy1 == phy2);
}

}  // namespace core
}  // namespace romea
