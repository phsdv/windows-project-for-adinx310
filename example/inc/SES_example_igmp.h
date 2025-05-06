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

#ifndef INC_SES_TEST_IGMP_H_
#define INC_SES_TEST_IGMP_H_

#include <stdint.h>

/**
 * @brief Checks if IGMP is enabled properly or not.
 * 
 */
void SES_test_IgmpEnable(void);

/**
 * @brief Checks if IGMP is disbled properly or not.
 * 
 */
void SES_test_IgmpDisable();

/**
 * @brief Sets the group timeout value .
 * @param[in] Timer value in seconds
 */
void SES_test_IgmpSetGroupTimeout(uint32_t seconds);

/**
 * @brief Sets the router timeout value.
 * @param[in] Timer value in seconds
 */
void SES_test_IgmpSetRouterTimeout(uint32_t seconds);

/**
 * @brief Gets the full IGMP status including groupMemberTimeout and routerTimeout.
 * 
 */
void SES_test_IgmpGetStatus(void);

/**
 * @brief Enabling event example based upon parameter based in in ses_configuration.
 * @param[in] 0:disable, 1: Enable LinkEventExample, 2: Enable LLDP Event Example, 3: Timer Event Example
 */
void igmp_main(void);

#endif /* INC_SES_TEST_IGMP_H_ */
