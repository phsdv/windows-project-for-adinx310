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

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "SES_example_time_synchronization.h"
#include "SES_time_synchronization.h"
#include "SES_codes.h"
#include "SES_debug.h"
#include "SES_configuration.h"

uint8_t hostMac[6] = HOST_MAC;

void SES_PtpDeletePtpInstanceTest(uint32_t instanceIndex) {
	printf("PtpDeletePtpInstance :: %d ststus :: %d\n", instanceIndex, SES_PtpDeletePtpInstance(instanceIndex));
}

void SES_PtpGetNumberPtpInstancesTest(void) {
	printf("SES_PtpGetNumberPtpInstances :: %d\n", SES_PtpGetNumberPtpInstances());
}

void SES_PtpSetDefaultDsTest(void) {

	uint32_t instanceIndex = 0;
	TSN_ptp_default_ds_t default_ds;
	TSN_ptp_port_ds_t port_ds;

	printf("SES_PtpGetDefaultDs - %d\n", SES_PtpGetDefaultDs(instanceIndex, &default_ds));

	default_ds.instance_enable = 1;
	default_ds.gm_capable = 0;
	printf("SES_PtpSetDefaultDs - %d\n", SES_PtpSetDefaultDs(instanceIndex, &default_ds));

	printf("SES_PtpGetPortDs 1 - %d\n", SES_PtpGetPortDs(instanceIndex, 0, &port_ds));
	port_ds.port_state = 0;
	port_ds.delay_mechanism = TSN_ptp_delay_mechanism_p2p;
	port_ds.port_enable = 1;
	printf("SES_PtpSetPortDs 1 - %d\n", SES_PtpSetPortDs(instanceIndex, 0, &port_ds));
	
}

void SES_Test_Single_PtpInstance(void) {

	if (SES_OK == SES_PtpStart()) {

		/* Configure CMLDS, Clock identity */
		const TSN_ptp_init_cmlds_ds_t initDs = { {hostMac[0], hostMac[1], hostMac[2], hostMac[3], hostMac[4], hostMac[5],  0xff, 0xff } };
		printf("SES_PtpInitCmlds :: %d\n", SES_PtpInitCmlds(&initDs));

		/* Create instance with two ports */
		TSN_ptp_instance_type_t instanceType = TSN_ptp_instance_type_ptp_relay;
		uint16_t numberPtpPorts = 2;
		uint16_t linkPortNumber[2] = { 1,2 };

		/* initDs_p parameters:: clock_identity, clock_number, domain_number */
		TSN_ptp_init_instance_ds_t initDs_p = { {hostMac[0], hostMac[1], hostMac[2], hostMac[3], hostMac[4], hostMac[5], 0x00, 0x00 }, 0, 0 };
		uint32_t instanceIndex_p;
		printf("Create PTP instance status :: %d\n", SES_PtpCreatePtpInstance(instanceType, numberPtpPorts,
			&linkPortNumber, &initDs_p, &instanceIndex_p));

		/* Initialize default_ds */
		uint32_t instanceIndex = 0;
		TSN_ptp_default_ds_t default_ds;
		TSN_ptp_port_ds_t port_ds;

		printf("SES_PtpGetDefaultDs - %d\n", SES_PtpGetDefaultDs(instanceIndex, &default_ds));
		default_ds.instance_enable = 1;
		default_ds.gm_capable = 0;
		printf("SES_PtpSetDefaultDs - %d\n", SES_PtpSetDefaultDs(instanceIndex, &default_ds));


		/* Enable Instance 1 PTP Ports with CMLDS delay mechanism */
		printf("SES_PtpGetPortDs :: %d\n", SES_PtpGetPortDs(instanceIndex, 0, &port_ds));
		port_ds.delay_mechanism = TSN_ptp_delay_mechanism_p2p;
		port_ds.port_enable = 1;
		/* printf("SES_PtpSetPortDs 1 :: %d\n", SES_PtpSetPortDs(instanceIndex, 0, &port_ds)); */
		printf("SES_PtpSetPortDs 2 :: %d\n", SES_PtpSetPortDs(instanceIndex, 1, &port_ds));

	}
}

int32_t ses_test_as2011_example(void) {

	int32_t rv = 0;
	uint32_t instanceIndex; 

	/* Below parameters must be configured properly if using ADIN3310 */
	uint16_t numberPtpPorts = 6; 
	uint16_t linkPortNumber[6] = { 1, 2, 3, 4, 5, 6 }; 

	if (SES_OK != SES_PtpStart())
		return;

	/* Configure CMLDS, Clock identity */
	const TSN_ptp_init_cmlds_ds_t initDs = { {hostMac[0], hostMac[1], hostMac[2], hostMac[3], hostMac[4], hostMac[5], 0xff, 0xff } };

	printf("SES_PtpInitCmlds :: %d\n", SES_PtpInitCmlds(&initDs));
	TSN_ptp_init_instance_ds_t init_s = {
	.clock_identity = { 0x7a, 0xc6, 0xbb, 0x11, 0x11, 0x11, 0x00, 0x00 },
	.clock_number = 0,
	.domain_number = 0
	};

	rv = SES_PtpCreatePtpInstance(TSN_ptp_instance_type_ptp_relay, numberPtpPorts, &linkPortNumber, &init_s, &instanceIndex);

	/* Initialize default_ds */

	TSN_ptp_default_ds_t default_ds;
	rv = SES_PtpGetDefaultDs(instanceIndex, &default_ds);
	default_ds.instance_enable = 1;
	rv = SES_PtpSetDefaultDs(instanceIndex, &default_ds);
	printf("SES_PtpSetDefaultDs - %d\n", rv);

	/* Initialize port_ds with peer to peer delay */
	TSN_ptp_port_ds_t port_ds;
	rv = SES_PtpGetPortDs(instanceIndex, 0, &port_ds);
	port_ds.delay_mechanism = TSN_ptp_delay_mechanism_p2p,
		port_ds.port_enable = 1;

	/* Below parameters must be configured properly if using ADIN3310 */
	rv = SES_PtpSetPortDs(instanceIndex, 0, &port_ds);
	rv = SES_PtpSetPortDs(instanceIndex, 1, &port_ds);
	rv = SES_PtpSetPortDs(instanceIndex, 2, &port_ds);
	rv = SES_PtpSetPortDs(instanceIndex, 3, &port_ds);
	rv = SES_PtpSetPortDs(instanceIndex, 4, &port_ds);
	rv = SES_PtpSetPortDs(instanceIndex, 5, &port_ds);

	return rv;

}

int32_t ses_test_multiple_ptp_instance_example(void) {

	int32_t rv = 0;
	if (SES_OK != SES_PtpStart())
		return;

	/*Configure CMLDS, Clock identity */
	const TSN_ptp_init_cmlds_ds_t initDs = {
	.clock_identity = { hostMac[0], hostMac[1], hostMac[2], hostMac[3], hostMac[4], hostMac[5], 0xff, 0xff }
	};

	rv = SES_PtpInitCmlds(&initDs);
	printf("SES_PtpInitCmlds - %d\n", rv);

	/* Create instance with six ports */
	uint16_t numberPtpPorts1 = 6;
	uint16_t linkPortNumber1[6] = { 1, 2, 3, 4, 5, 6 };

	TSN_ptp_init_instance_ds_t initDs1 = {
	.clock_identity = { hostMac[0], hostMac[1], hostMac[2], hostMac[3], hostMac[4], hostMac[5], 0x00, 0x00 },
	/* Timer A */
	.clock_number = 0, 
	.domain_number = 0
	};

	uint32_t* instanceIndex1;
	rv = SES_PtpCreatePtpInstance(TSN_ptp_instance_type_ptp_relay, numberPtpPorts1, &linkPortNumber1, &initDs1, &instanceIndex1);
	printf("SES_PtpCreatePtpInstance - %d\n", rv);

	/* Initialize default_ds */
	TSN_ptp_default_ds_t default_ds;
	rv = SES_PtpGetDefaultDs(instanceIndex1, &default_ds);
	default_ds.instance_enable = 1;
	rv = SES_PtpSetDefaultDs(instanceIndex1, &default_ds);
	printf("SES_PtpSetDefaultDs - %d\n", rv);

	uint16_t numberPtpPorts2 = 2;
	uint16_t linkPortNumber2[2] = { 1, 2 };
	TSN_ptp_init_instance_ds_t initDs2 = {
	.clock_identity = { hostMac[0], hostMac[1], hostMac[2], hostMac[3], hostMac[4], hostMac[5], 0x00, 0x01 },
	/* Second instance must run from free running clock */
	.clock_number = 0x80000000, 
	.domain_number = 1
	};

	uint32_t* instanceIndex2;
	rv = SES_PtpCreatePtpInstance(TSN_ptp_instance_type_ptp_relay, numberPtpPorts2, &linkPortNumber2, &initDs2, &instanceIndex2);
	printf("SES_PtpCreatePtpInstance - %d\n", rv);

	rv = SES_PtpGetDefaultDs(instanceIndex2, &default_ds);
	default_ds.instance_enable = 1;
	rv = SES_PtpSetDefaultDs(instanceIndex2, &default_ds);
	printf("SES_PtpSetDefaultDs - %d\n", rv);

	/* Initialize port_ds */
	TSN_ptp_port_ds_t port_ds;
	rv = SES_PtpGetPortDs(instanceIndex1, 0, &port_ds);
	printf("SES_PtpGetPortDs 1 - %d\n", rv);

	/* Enable Instance 1 PTP Ports for all 6 ports */
	port_ds.delay_mechanism = TSN_ptp_delay_mechanism_common_p2p;
	port_ds.port_enable = 1;
	rv = SES_PtpSetPortDs(instanceIndex1, 0, &port_ds);
	printf("SES_PtpSetPortDs 1 - %d\n", rv);
	rv = SES_PtpSetPortDs(instanceIndex1, 1, &port_ds);
	printf("SES_PtpSetPortDs 6 - %d\n", rv);

	/* Enable Instance 2 PTP Ports for ports 2 & 3 */
	port_ds.delay_mechanism = TSN_ptp_delay_mechanism_common_p2p;
	port_ds.port_enable = 1;
	rv = SES_PtpSetPortDs(instanceIndex2, 0, &port_ds);
	printf("SES_PtpSetPortDs 1 - %d\n", rv);
	rv = SES_PtpSetPortDs(instanceIndex2, 1, &port_ds);
	printf("SES_PtpSetPortDs 2 - %d\n", rv);
	printf("ses_test_create_multiple_ptp_instance_example, rv - %d\n", rv);
	return rv;
}


// ================================================1588-2019 Example================================================================


/* The set of APIs to be called for creating a 1588 instance using the driver APIs are given below:
	o	SES_PtpStart() //To start the ptp-stk
	o	SES_PtpCreatePtpInstance() //To create a PTP instance
	o	SES_PtpSetDefaultDs() //To configure the default dataset
	o	SES_PtpSetPortDs() //To configure the port dataset. Must be called once per port
	o	SES_PtpSetTimestampCorrectionPortDs() //To configure the ingress and egress latency(PHY delay values). This must also be called once per port.
	o	Suggestion is to first get the PHY delay values by calling SES_GetPhyDelays() API and then call SES_PtpSetTimestampCorrectionPortDs by passing the read values.
*/

/* Configure Ordinary clcok */
void Ses_OrdinaryClock_GM(void) {

	int32_t rv = 0;
	uint32_t instanceIndex;
	TSN_ptp_default_ds_t default_ds;
	uint16_t numberPtpPorts = 1;
	uint16_t linkPortNumber[1] = { 1 };
	TSN_ptp_timestamp_correction_port_ds_t ds_p;
	int16_t rxDelay_p;
	int16_t txDelay_p;

	/* Initialize PTP Stack */
	if (SES_OK != SES_PtpStart()) {
		printf("PTP initialization failed !!\n");
		return;
	}

	/* Initialize Instance and its parameters */
	TSN_ptp_init_instance_ds_t init_s = {
	.clock_identity = { hostMac[0], hostMac[1], hostMac[2], hostMac[3], hostMac[4], hostMac[5], 0x00, 0x00 },
	.clock_number = 0,
	.domain_number = 0
	};
	rv = SES_PtpCreatePtpInstance(TSN_ptp_instance_type_oc, numberPtpPorts, linkPortNumber, &init_s, &instanceIndex);


	/* Initialize Deafault Data set */
	rv = SES_PtpGetDefaultDs(instanceIndex, &default_ds);
	default_ds.instance_type = TSN_ptp_instance_type_oc;
	default_ds.instance_enable = 1;

	/* Utilize Priority to make SES as GM, Lower value, higher priority */
	default_ds.priority1 = 128;
	default_ds.priority2 = 248;
	rv = SES_PtpSetDefaultDs(instanceIndex, &default_ds);
	printf("SES_PtpSetDefaultDs - %d\n", rv);


	/* PTP port data set Configuration */
	TSN_ptp_port_ds_t port_ds;
	rv = SES_PtpGetPortDs(instanceIndex, 0, &port_ds);
	port_ds.delay_mechanism = TSN_ptp_delay_mechanism_e2e,
		port_ds.port_enable = 1;

	printf("SES_PtpSetPortDs :: %d\n", SES_PtpSetPortDs(instanceIndex, 0, &port_ds));

	printf("Reading Phy Delays:: %d\n", SES_GetPhyDelays(SES_macPort0, &rxDelay_p, &txDelay_p));

	ds_p.egress_latency = txDelay_p;
	ds_p.ingress_latency = rxDelay_p;
	printf("Set PTP time stamp correction :: %d\n", SES_PtpSetTimestampCorrectionPortDs(instanceIndex, 0, &ds_p));


}

/* Configure Boundary clock */
void Ses_BoundaryClockExample(void) {

	int32_t rv = 0;
	uint32_t instanceIndex;
	TSN_ptp_default_ds_t default_ds;
	uint16_t numberPtpPorts = 6;
	uint16_t linkPortNumber[6] = { 1,2,3,4,5,6 };
	TSN_ptp_timestamp_correction_port_ds_t ds_p;
	int16_t rxDelay_p;
	int16_t txDelay_p;

	/* Initialize PTP Stack */
	if (SES_OK != SES_PtpStart()) {
		printf("PTP initialization failed !!\n");
		return;
	}

	/* Initialize Instance and its parameters */
	TSN_ptp_init_instance_ds_t init_s = {
	.clock_identity = { hostMac[0], hostMac[1], hostMac[2], hostMac[3], hostMac[4], hostMac[5], 0x00, 0x00 },
	.clock_number = 0,
	.domain_number = 0
	};
	rv = SES_PtpCreatePtpInstance(TSN_ptp_instance_type_bc, numberPtpPorts, linkPortNumber, &init_s, &instanceIndex);


	/* Initialize Deafault Data set */
	rv = SES_PtpGetDefaultDs(instanceIndex, &default_ds);
	default_ds.instance_type = TSN_ptp_instance_type_bc;
	default_ds.instance_enable = 1;
	default_ds.priority1 = 248;
	default_ds.priority2 = 248;
	rv = SES_PtpSetDefaultDs(instanceIndex, &default_ds);
	printf("SES_PtpSetDefaultDs - %d\n", rv);


	/* PTP port data set Configuration */
	TSN_ptp_port_ds_t port_ds;
	rv = SES_PtpGetPortDs(instanceIndex, 0, &port_ds);
	port_ds.delay_mechanism = TSN_ptp_delay_mechanism_e2e,
		port_ds.port_enable = 1;

	/* Per port PTP instance configuration */
	for (int port = 0; port < 6; port++) {
		printf("SES_PtpSetPortDs for Port :: %d and rv :: %d\n", port, SES_PtpSetPortDs(instanceIndex, port, &port_ds));

		/*To configure the ingress and egress latency(PHY delay values). This must also be called once per port.*/
		printf("Reading Phy Delays:: %d\n", SES_GetPhyDelays(port + 1, &rxDelay_p, &txDelay_p));

		ds_p.egress_latency = txDelay_p;
		ds_p.ingress_latency = rxDelay_p;

		printf("Set PTP time stamp correction :: %d\n", SES_PtpSetTimestampCorrectionPortDs(instanceIndex, port, &ds_p));

		rxDelay_p = 0;
		txDelay_p = 0;
	}

}

/* Configure Transparent clock */
void Ses_TransparentClock_E2E(void) {

	int32_t rv = 0;
	uint32_t instanceIndex;
	TSN_ptp_default_ds_t default_ds;
	uint16_t numberPtpPorts = 6;
	uint16_t linkPortNumber[6] = { 1,2,3,4,5,6 };
	TSN_ptp_timestamp_correction_port_ds_t ds_p;
	int16_t rxDelay_p;
	int16_t txDelay_p;

	/* Initialize PTP Stack */
	if (SES_OK != SES_PtpStart()) {
		printf("PTP initialization failed !!\n");
		return;
	}


	/* Initialize PTP Instance and its parameters */
	TSN_ptp_init_instance_ds_t init_s = { 
	.clock_identity = { hostMac[0], hostMac[1], hostMac[2], hostMac[3], hostMac[4], hostMac[5], 0x00, 0x00 },
	.clock_number = 0, 
	.domain_number = 0 
	};
	rv = SES_PtpCreatePtpInstance(TSN_ptp_instance_type_e2e_tc, numberPtpPorts, linkPortNumber, &init_s, &instanceIndex); 


	/* Initialize Deafault Data set */
	rv = SES_PtpGetDefaultDs(instanceIndex, &default_ds); 
	default_ds.instance_type = TSN_ptp_instance_type_e2e_tc; 
	default_ds.instance_enable = 1; 
	rv = SES_PtpSetDefaultDs(instanceIndex, &default_ds); 
	printf("SES_PtpSetDefaultDs - %d\n", rv); 


	/*PTP port Data set Configuration */
	TSN_ptp_port_ds_t port_ds; 
	rv = SES_PtpGetPortDs(instanceIndex, 0, &port_ds); 
	port_ds.delay_mechanism = TSN_ptp_delay_mechanism_e2e, 
		port_ds.port_enable = 1; 

	/* Per port PTP instance configuration */
	for (int port = 0; port < 6; port++) {
		printf("SES_PtpSetPortDs for Port :: %d and rv :: %d\n", port, SES_PtpSetPortDs(instanceIndex, port, &port_ds));

		/*To configure the ingress and egress latency(PHY delay values). This must also be called per port.*/
		printf("Reading Phy Delays:: %d\n", SES_GetPhyDelays(port + 1, &rxDelay_p, &txDelay_p));

		ds_p.egress_latency = txDelay_p;
		ds_p.ingress_latency = rxDelay_p;

		printf("Set PTP time stamp correction :: %d\n", SES_PtpSetTimestampCorrectionPortDs(instanceIndex, port, &ds_p));
		rxDelay_p = 0;
		txDelay_p = 0;
	}
}

void timeSynchMain(void) {

	switch (CLOCK_TYPE) {
	
	case 1:
		SES_Test_Single_PtpInstance();
		break;
	
	case 2:
		Ses_BoundaryClockExample();
		break;
	
	case 3: 
		Ses_OrdinaryClock_GM();
		break;
	
	case 4: 
		Ses_TransparentClock_E2E();
		break;

	default:
		printf("Invalid Input!! \n");
		break;
		
	}

}


