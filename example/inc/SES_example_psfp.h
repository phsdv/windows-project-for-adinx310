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

#ifndef INC_SES_TEST_PSFP_H_
#define INC_SES_TEST_PSFP_H_

#include <stdint.h>

/**
 * @brief Configure switch stream gate.
 * @return int32_t SES return status code.
 */
int32_t SES_streamGateExample(void);

/**
 * @brief Configure switch stream filter.
 * @return int32_t SES return status code.
 */
int32_t SES_streamFilterExample(void);

/**
 * @brief Configure switch flow meter.
 * @return int32_t SES return status code.
 */
int32_t SES_flowMeterExample(void);

/**
 * @brief Read PSFP statistics.
 */
void SES_readPsfpStatistics(void);

/**
 * @brief Reprioritive PCP of ingressing frames.
 * @return int32_t SES return status code.
 */
int32_t ses_ipv_reprioritize_example(void);

/**
 * @brief PSFP main
 */
void SES_example_psfp_main(void);


#endif /* INC_SES_TEST_EVENT_H_ */