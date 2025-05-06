/*
 * Copyright 2024 Analog Devices, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

 /**
  * @file SES_example_event.h
  *
  */

#ifndef INC_SES_TEST_EVENT_H_
#define INC_SES_TEST_EVENT_H_

#include <stdint.h>

  /**
   * @brief Enabling event example based upon parameter based in in ses_configuration.
   * @param[in] 0:disable, 1: Enable LinkEventExample, 2: Enable LLDP Event Example, 3: Timer Event Example
   */
void eventExampleMain(void);

/**
 * @brief Subscribe to Link up and Link down events.
 * @return int32_t SES return status code
 */
int32_t ses_linkEvent_example(void);

/**
 * @brief Enable LLDP Event example
 * @return int32_t SES return status code
 */
int32_t ses_event_lldp_example(void);

/**
 * @brief Subscribe to Input Capture Event
 * @param[in] 0:disable, 1: Enable LinkEventExample, 2: Enable LLDP Event Example, 3: Timer Event Example
 *
 */
void SES_timer_Event_test(void);

#endif /* INC_SES_TEST_EVENT_H_ */
