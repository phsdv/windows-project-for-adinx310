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

#ifndef INC_SES_TEST_INIT_H_
#define INC_SES_TEST_INIT_H_

#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int32_t ses_test_init(int32_t HW_INTERFACE);
int32_t ses_test_ETH_init(void);
int32_t ses_test_SPI_init(void);
int32_t ses_test_QSPI_init(void);
int32_t ses_test_SPI_ETH_init(void);

#endif /* INC_SES_TEST_INIT_H_ */
