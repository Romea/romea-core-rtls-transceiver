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


// gtest
#include "gtest/gtest.h"

// romea
#include "romea_core_rtls_transceiver/RTLSTransceiverRangingStatus.hpp"

class TestTransceiverRangingStatus : public ::testing::Test
{
protected:
  TestTransceiverRangingStatus()
  : ranging_status_(0.5, 20.0, 20)
  {}

  romea::core::RTLSTransceiverRangingStatusEvaluator ranging_status_;
};


TEST_F(TestTransceiverRangingStatus, checkRangingIsFailed)
{
  romea::core::RTLSTransceiverRangingResult result;
  result.range = 0.;
  result.firstPathRxPowerLevel = 0;
  result.totalRxPowerLevel = 0;

  EXPECT_TRUE(
    ranging_status_.evaluate(result) ==
    romea::core::RTLSTransceiverRangingStatus::FAILED);
}

TEST_F(TestTransceiverRangingStatus, checkRangingIsUnavailableWhenRangeIsLowerThanMinimalRange)
{
  romea::core::RTLSTransceiverRangingResult result;
  result.range = 0.2;
  result.firstPathRxPowerLevel = 8;
  result.totalRxPowerLevel = 10;

  EXPECT_TRUE(
    ranging_status_.evaluate(result) ==
    romea::core::RTLSTransceiverRangingStatus::UNAVAILABLE);
}

TEST_F(TestTransceiverRangingStatus, checkRangingIsUnavailableWhenRangeIsHigherThanMaximalRange)
{
  romea::core::RTLSTransceiverRangingResult result;
  result.range = 22.;
  result.firstPathRxPowerLevel = 8;
  result.totalRxPowerLevel = 10;
  EXPECT_TRUE(
    ranging_status_.evaluate(result) ==
    romea::core::RTLSTransceiverRangingStatus::UNAVAILABLE);
}

TEST_F(TestTransceiverRangingStatus, checkRangingIsUnavailableWhenFirstPathRxPowerLevelIsTooLow)
{
  romea::core::RTLSTransceiverRangingResult result;
  result.range = 10.;
  result.firstPathRxPowerLevel = 5;
  result.totalRxPowerLevel = 30;
  EXPECT_TRUE(
    ranging_status_.evaluate(result) ==
    romea::core::RTLSTransceiverRangingStatus::UNAVAILABLE);
}

TEST_F(TestTransceiverRangingStatus, checkIsAvailable)
{
  romea::core::RTLSTransceiverRangingResult result;
  result.range = 10.;
  result.firstPathRxPowerLevel = 28;
  result.totalRxPowerLevel = 30;
  EXPECT_TRUE(
    ranging_status_.evaluate(result) ==
    romea::core::RTLSTransceiverRangingStatus::AVAILABLE);
}

//-----------------------------------------------------------------------------
int main(int argc, char ** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
