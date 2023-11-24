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


#ifndef ROMEA_CORE_RTLS__RTLS_TRANSCEIVER_RANGING_RESULT_HPP_
#define ROMEA_CORE_RTLS__RTLS_TRANSCEIVER_RANGING_RESULT_HPP_

// romea
#include <romea_core_common/time/Time.hpp>

namespace romea
{
namespace core
{

struct RTLSTransceiverRangingResult
{
  Duration duration;
  double range;
  unsigned char firstPathRxPowerLevel;
  unsigned char totalRxPowerLevel;
};

bool isEmpty(const RTLSTransceiverRangingResult & result);

}  // namespace core
}  // namespace romea


#endif  // RTLS_TRANSCEIVER_RANGING_RESULT_HPP_
