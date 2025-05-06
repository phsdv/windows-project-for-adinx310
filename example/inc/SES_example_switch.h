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

#ifndef INC_SES_TEST_SWITCH_H_
#define INC_SES_TEST_SWITCH_H_

#include <stdint.h>

/**
 * @brief Read entrire dynamic table.
 * @return Print the entries.
 */

void Ses_ExampleReadDynamicTable(void);

/**
 * @brief Retrieve Port Statistics
 * @return None
 */
void SES_ExampleGetStatistics(void);

/**
 * @brief Installing extended Static table entry
 * @return None
 */
void SES_ExampleAddStaticTableEntryEx(void);

/**
 * @brief Switch Exmaple selector
 * @return None
 */
void SES_SwitchExampleMain(void);

/**
 * @brief Add extended table entry using simple static route API.
 * @return int32_t SES return status code.
 */
int32_t ses_extended_table_static_route_simple_example(void);

/**
 * @brief Update port map of existing extended table entry.
 * @return int32_t SES return status code.
 */
int32_t ses_update_extended_table_example(void);

/**
 * @brief Add IPV4 extended table entry.
 * @return int32_t SES return status code.
 */
int32_t ses_extended_table_static_route_ipv4_example(void);

/**
 * @brief Install IPV4 extended lookup entry.
 * @return int32_t SES return status code.
 */
int32_t ses_install_extended_lookup_entry_ipv4_example(void);

/**
 * @brief Add IPV6 extended table entry.
 * @return int32_t SES return status code.
 */
int32_t ses_extended_table_static_route_ipv6_example(void);

/**
 * @brief Install IPV6 extended lookup entry.
 * @return int32_t SES return status code.
 */
int32_t ses_install_extended_lookup_entry_ipv6_example(void);

/**
 * @brief Reprioritze ingress traffic based on ethertpye for all ingress traffic on specific port.
 * @return int32_t SES return status code.
 */
int32_t ses_ethertype_reprioritization_rxlookup_example(void);

/**
 * @brief Reprioritze ingress traffic based on ethertpye using static table entry.
 * @return int32_t SES return status code.
 */
int32_t ses_ethertype_reprioritization_static_table_example(void);

#endif /* INC_SES_TEST_SWITCH_H_ */
