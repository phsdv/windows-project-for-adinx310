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

#ifndef INC_SES_TEST_MRP_H_
#define INC_SES_TEST_MRP_H_

#include <stdint.h>

void SES_test_StartMRP(void);
void SES_test_GetInstanceConfig(void);
void SES_test_SetRingPorts(void);
int32_t SES_test_VerifyMrpEnabled(void);
void SES_test_GetDomainStatistics(void);
void  SES_test_SetMrpClient(void);
int32_t SES_test_SetMrpManager(void);
void SES_MRPConfigAndInit(void);
void MRPExample_main();


#endif /* INC_SES_TEST_MRP_H_ */
