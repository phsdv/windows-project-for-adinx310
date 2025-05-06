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

#ifndef INC_SES_TEST_TIME_SYNCHRONIZATION_H_
#define INC_SES_TEST_TIME_SYNCHRONIZATION_H_

#include <stdint.h>


/**
 * @brief Creates the PTP Test Instance.
 * 
 */
void SES_Test_Single_PtpInstance(void);

/**
 * @brief Create ordinary clock with all 6 ports.
 *
 */
void Ses_OrdinaryClock_GM(void);

/**
 * @brief Create boundary clock with all 6 ports.
 *
 */
void Ses_BoundaryClockExample(void);

/**
 * @brief Create transparent clock with all 6 ports.
 *
 */
void Ses_TransparentClock_E2E(void);

/**
 * @brief Main time synch function.
 *
 */
void timeSynchMain(void);

/**
 * @brief Deleted the PTP instance Test.
 * @param[in]: instance index
 */
void SES_PtpDeletePtpInstanceTest(uint32_t instanceIndex);

/**
 * @brief Tells you the number of PTP instance Tests.
 * 
 */
void SES_PtpGetNumberPtpInstancesTest(void);

/**
 * @brief sets the default DSTests.
 * 
 */
void SES_PtpSetDefaultDsTest(void);

/**
 * @brief Example for Ordinary clock configuration.
 *
 */
void Ses_OrdinaryClock_GM(void);

/**
 * @brief Example for Boundary clock configuration.
 *
 */
void Ses_BoundaryClockExample(void);


/**
 * @brief Example for Transparent clock configuration.
 *
 */
void Ses_TransparentClock_E2E(void);


#endif /* INC_SES_TEST_TIME_SYNCHRONIZATION_H_ */
