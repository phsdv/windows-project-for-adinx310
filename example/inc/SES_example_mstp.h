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

#ifndef INC_SES_TEST_MSTP_H_
#define INC_SES_TEST_MSTP_H_

#include <stdint.h>

/**
 * @brief Initialize MSTP Stack and Start.
 * 
 */
int32_t ses_mstp_stack_start(void);

/**
 * @brief This example initializes and creates multiple MST instances.
 * @return int32_t SES return status code
 */
int32_t ses_multiple_msti_example(void);

/**
 * @brief This example retrieves the mapping of VLAN IDs to MSTI.
 * @return int32_t SES return status code
 */
int32_t ses_get_vlan_to_msti_map_example(void);

/**
 * @brief This example demonstrates the bridge forward delay configuration.
 * @return int32_t SES return status code
 */
int32_t ses_bridge_forward_delay_example(void);

#endif /* INC_SES_TEST_MSTP_H_ */