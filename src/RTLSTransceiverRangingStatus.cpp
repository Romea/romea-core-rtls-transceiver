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

// std
#include <limits>
// romea
#include "romea_core_rtls_transceiver/RTLSTransceiverRangingStatus.hpp"


namespace romea
{
namespace core
{


//-----------------------------------------------------------------------------
RTLSTransceiverRangingStatusEvaluator::RTLSTransceiverRangingStatusEvaluator(
  const double & minimalRange,
  const double & maximalRange,
  const uint8_t & rxPowerRejectionThreshold)
: minimalRange_(minimalRange),
  maximalRange_(maximalRange),
  rxPowerRejectionThreshold_(rxPowerRejectionThreshold)
{
}

//-----------------------------------------------------------------------------
RTLSTransceiverRangingStatus RTLSTransceiverRangingStatusEvaluator::evaluate(
  const RTLSTransceiverRangingResult & result)
{
  if (isEmpty(result)) {
    return RTLSTransceiverRangingStatus::FAILED;
  }

  if (result.range >= minimalRange_ && result.range <= maximalRange_ &&
    result.totalRxPowerLevel - result.firstPathRxPowerLevel < rxPowerRejectionThreshold_)
  {
    return RTLSTransceiverRangingStatus::AVAILABLE;
  } else {
    return RTLSTransceiverRangingStatus::UNAVAILABLE;
  }
}


}  // namespace core
}  // namespace romea
