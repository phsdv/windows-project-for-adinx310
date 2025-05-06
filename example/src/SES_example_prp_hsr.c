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
#include "SES_example_prp_hsr.h"
#include "SES_configuration.h"
#include "SES_prp_hsr.h"
#include "SES_codes.h"
#include "SES_debug.h"



int32_t ses_test_prp_start(int32_t portC) {
    int32_t result = 0;

    /*SES_PrpStart(MIB_PRP_HSR_redundancyType_t redundancyType,
        bool danpDevice,
        MIB_PRP_HSR_lrePorts_t * lrePorts_p,
        MIB_PRP_HSR_rbInterlinkPorts_t * rbInterlinkPorts_p,
        uint8_t * lreMacAddress_p,
        int32_t lreDupListResideMaxTime);*/


    MIB_PRP_HSR_redundancyType_t redundancyType = MIB_PRP_HSR_prpMode1;
    bool danpDevice = true;
    MIB_PRP_HSR_lrePorts_t lrePorts_p = { 1, 2, portC };
    MIB_PRP_HSR_rbInterlinkPorts_t rbInterlinkPorts_p = { -1,-1,-1,-1 };
    uint8_t macAddress_g[6] = { 0x11, 0x11, 0x11, 0x11, 0x11, 0x11 };

    if (-1 != portC) {
        uint8_t macAddress_g[6] = HOST_MAC;
    }

    int32_t lreDupListResideMaxTime = 161;
    result = SES_PrpStart(redundancyType, danpDevice, &lrePorts_p, &rbInterlinkPorts_p, &macAddress_g, lreDupListResideMaxTime);

    return result;
}
int32_t ses_test_prp_redBoxstart(int32_t portC) {
    int32_t result = 0;

    /*SES_PrpStart(MIB_PRP_HSR_redundancyType_t redundancyType,
        bool danpDevice,
        MIB_PRP_HSR_lrePorts_t * lrePorts_p,
        MIB_PRP_HSR_rbInterlinkPorts_t * rbInterlinkPorts_p,
        uint8_t * lreMacAddress_p,
        int32_t lreDupListResideMaxTime);*/

    MIB_PRP_HSR_redundancyType_t redundancyType = MIB_PRP_HSR_prpMode1;
    bool danpDevice = false;
    MIB_PRP_HSR_lrePorts_t lrePorts_p = { 1, 2, portC };
    MIB_PRP_HSR_rbInterlinkPorts_t rbInterlinkPorts_p = { 0,3,-1,-1 };

    uint8_t macAddress_g[6] = { 0x11, 0x11, 0x11, 0x11, 0x11, 0x11 };

    if (-1 != portC) {
        uint8_t macAddress_g[6] = HOST_MAC;
    }
    int32_t lreDupListResideMaxTime = 161;

    result = SES_PrpStart(redundancyType, danpDevice, &lrePorts_p, &rbInterlinkPorts_p, &macAddress_g, lreDupListResideMaxTime);

    return result;
}

int32_t ses_test_hsr_start(int32_t portC) {
    int32_t result = 0;

    /* int32_t SES_HsrStart(MIB_PRP_HSR_redundancyType_t redundancyType,
         MIB_PRP_HSR_switchEndNode_t lreSwitchingEndNode,
         MIB_PRP_HSR_lrePorts_t * lrePorts_p,
         MIB_PRP_HSR_rbInterlinkPorts_t * rbInterlinkPorts_p,
         uint8_t * lreMacAddress_p,
         int32_t lreDupListResideMaxTime);*/

    MIB_PRP_HSR_redundancyType_t redundancyType = MIB_PRP_HSR_hsr;
    MIB_PRP_HSR_switchEndNode_t lreSwitchingEndNode = MIB_PRP_HSR_hsrNode;
    //For SPI interface, lreDanPortC must be -1
    MIB_PRP_HSR_lrePorts_t lrePorts_p = { 2, 1, portC };
    MIB_PRP_HSR_rbInterlinkPorts_t rbInterlinkPorts_p = { 0,3,-1,-1 };
    uint8_t macAddress_g[6] = { 0x11, 0x11, 0x11, 0x11, 0x11, 0x11 };

    if (-1 != portC) {
        uint8_t macAddress_g[6] = HOST_MAC;
    }
    int32_t lreDupListResideMaxTime = 161;

    result = SES_HsrStart(redundancyType, lreSwitchingEndNode, &lrePorts_p, &rbInterlinkPorts_p, &macAddress_g, lreDupListResideMaxTime);

    return result;
}



int32_t ses_test_hsrredbox_start(int32_t portC) {
    int32_t result = 0;

    /*
     *   int32_t SES_HsrStart(MIB_PRP_HSR_redundancyType_t redundancyType,
     *   MIB_PRP_HSR_switchEndNode_t lreSwitchingEndNode,
     *   MIB_PRP_HSR_lrePorts_t * lrePorts_p,
     *   MIB_PRP_HSR_rbInterlinkPorts_t * rbInterlinkPorts_p,
     *   uint8_t * lreMacAddress_p,
     *   int32_t lreDupListResideMaxTime);
     */

    MIB_PRP_HSR_redundancyType_t redundancyType = MIB_PRP_HSR_hsr;
    MIB_PRP_HSR_switchEndNode_t lreSwitchingEndNode = MIB_PRP_HSR_hsrRedboxSan;

    /*For SPI interface, lreDanPortC must be -1 */
    MIB_PRP_HSR_lrePorts_t lrePorts_p = { 2, 1, portC };
    MIB_PRP_HSR_rbInterlinkPorts_t rbInterlinkPorts_p = { 0,-1,-1,-1 };
    uint8_t macAddress_g[6] = { 0x11, 0x11, 0x11, 0x11, 0x11, 0x11 };

    if (-1 != portC) {
        uint8_t macAddress_g[6] = HOST_MAC;
    }
    int32_t lreDupListResideMaxTime = 161;

    result = SES_HsrStart(redundancyType, lreSwitchingEndNode, &lrePorts_p, &rbInterlinkPorts_p, &macAddress_g, lreDupListResideMaxTime);

    return result;
}

int32_t  SES_test_SetLreDuplicateDiscard() {
    int32_t result = 0;
    MIB_PRP_HSR_dupDiscard_t lreDuplicateDiscard = MIB_PRP_HSR_doNotDiscard;

    result = SES_SetLreDuplicateDiscard(lreDuplicateDiscard);

    return result;


}

int32_t SES_test_AddVlanSupervisionFrame() {
    uint16_t lreSupervisionVid = 10;
    int32_t result = 0;

    result = SES_AddVlanSupervisionFrame(lreSupervisionVid);

    return result;

}

int32_t SES_test_SetHsrMode() {
    int32_t result = 0;

    MIB_PRP_HSR_operatingMode_t hsrMode = MIB_PRP_HSR_modeT;
    result = SES_SetLreHsrMode(hsrMode);


    return result;
}

int32_t SES_test_VerifyReduExecuting() {

    bool checkRedun = false;
    int32_t result = 0;
    result = SES_VerifyReduExecuting(&checkRedun);
    printf("Boolean value==>%i\n", checkRedun);

    return result;

}

int32_t SES_test_GetLreStatus() {
    int32_t result = 0;
    MIB_PRP_HSR_lreStatus_t lreStatus_p;
    result = SES_GetLreStatus(&lreStatus_p);

    printf("lreNodeType 				- %d\n", lreStatus_p.lreRedundancyType);
    printf("lreSwitchingEndNode 		- %d\n", lreStatus_p.lreSwitchingEndNode);
    printf("portA 						- %d\n", lreStatus_p.lrePorts.portA);
    printf("portB 						- %d\n", lreStatus_p.lrePorts.portB);
    printf("portC 						- %d\n", lreStatus_p.lrePorts.danPortC);
    printf("lreMacAddress 				- %d\n", lreStatus_p.lreMacAddress);
    printf("lreMacAddress 				- %d %d %d %d %d %d\n", lreStatus_p.lreMacAddress[0],
        lreStatus_p.lreMacAddress[1], lreStatus_p.lreMacAddress[2],
        lreStatus_p.lreMacAddress[3], lreStatus_p.lreMacAddress[4],
        lreStatus_p.lreMacAddress[5]);

    printf("lrePortAdminStateA 			- %d\n", lreStatus_p.lrePortAdminStateA);
    printf("lrePortAdminStateB 			- %d\n", lreStatus_p.lrePortAdminStateB);
    printf("lreDuplicateDiscard 		- %d\n", lreStatus_p.lreDuplicateDiscard);
    printf("lreTransparentReception 	- %d\n", lreStatus_p.lreTransparentReception);
    printf("lreEvaluateSupervision 		- %d\n", lreStatus_p.lreEvaluateSupervision);
    printf("lreNodesTableClear 			- %d\n", lreStatus_p.lreNodesTableClear);
    printf("lreDupListResideMaxTime 	- %d\n", lreStatus_p.lreDupListResideMaxTime);
    printf("lreSupervisionVid 			- %d\n", lreStatus_p.lreSupervisionVid);
    printf("lreLinkStatusA 				- %d\n", lreStatus_p.lreLinkStatusA);
    printf("lreLinkStatusB 				- %d\n", lreStatus_p.lreLinkStatusB);

    printf("ses_test_prp_hsr_example response = %d\n\r", result);



    return result;
}

/* Retrieve Node table entries */
void SES_test_GetNodeEntry(void) {
    
    int32_t result;
    int32_t nodeCount = 0;
    int32_t pNodeCount = 0;

    MIB_PRP_HSR_lreNodesEntry_t lreNodesEntry_p0;
    MIB_PRP_HSR_lreProxyNodeEntry_t lreProxyNodeEntry_p;

    MIB_PRP_HSR_lreStatistics_t lreStatistics_p;
    result = SES_GetLreStatistics(&lreStatistics_p);

    nodeCount = lreStatistics_p.lreCntNodes;
    pNodeCount = lreStatistics_p.lreCntProxyNodes;

    printf("NodeCount =   %d\n", nodeCount);
    printf("ProxyNodeCount =    %d\n", pNodeCount);


    if (nodeCount > 0) {
        for (int i = 1; i <= nodeCount; i++)
        {
            result = SES_GetLreNodesEntry(i, &lreNodesEntry_p0);

            printf("---------SES_GetLreNodesEntry---------::  %d \n", result);
            printf("lreNodesIndex         %d\n", lreNodesEntry_p0.lreNodesIndex);
            printf("lreTimeLastSeenA %d\n", lreNodesEntry_p0.lreTimeLastSeenA);
            printf("lreTimeLastSeenB %d\n", lreNodesEntry_p0.lreTimeLastSeenB);
            printf("lre Node Type :: %d\n", lreNodesEntry_p0.lreRemNodeType);
            printf("MAC Address:: ");
            for (int i = 0; i < 6; i++) {
                printf("%02X", lreNodesEntry_p0.lreNodesMacAddress[i]); 
                if (i < 5) {
                    printf(":");
                }
            }printf("\n");

        }
    }

    if (pNodeCount > 0) {
        for (int i = 0; i < pNodeCount; i++)
        {
            result = SES_GetLreProxyNodeEntry(i, &lreProxyNodeEntry_p);
            printf("SES_GetLrProxyeNodesEntry :: %d,  lreProxyNodesIndex :: %d \n", result, lreProxyNodeEntry_p.lreProxyNodeIndex);
            printf("MAC Address:: ");
            for (int i = 0; i < 6; i++) {
                printf("%02X", lreProxyNodeEntry_p.lreProxyNodeMacAddress[i]); 
                if (i < 5) {
                    printf(":");
                }
            }printf("\n");
        }
    }

}

/* Configure device to be in cut-through mode. */
void SES_test_SetCutThroughForward() {
    MIB_PRP_HSR_cutThrough_t cutThrough = MIB_HSR_cutThrough;
    printf("SES_SetCutThroughForward status :: %d\n", SES_SetCutThroughForward(cutThrough));
}

/* Readback what mode switch is in */
int32_t SES_test_GetCutThroughForward() {
    int32_t rv;
    MIB_PRP_HSR_cutThrough_t cutThrough_p;
    rv = SES_GetCutThroughForward(&cutThrough_p);
    printf("MIB_PRP_HSR_cutThrough_t :: %d\n", cutThrough_p);
    return rv;
}


void ses_hsr_prp_main(void) {
    printf("Initializing Redundancy protocol\n");

    int32_t PortC = 1;

    /*if (1 == CONFIG_OVER_SPI) {
        PortC = -1;
    }*/

    switch (REDUNDANCY_TYPE) {

    case 0:
        printf("Initializing HSR \n");
        ses_test_hsrredbox_start(PortC);
        break;
    case 1:
        printf("Initializing HSR Redbox\n");
        ses_test_hsr_start(PortC);
        break;

    case 2:
        printf("Initializing PRP\n");
        ses_test_prp_start(PortC);
        break;

    case 3:
        printf("Initializing PRP Redbox\n");
        ses_test_prp_redBoxstart(PortC);
        break;

    default:
        printf("Error!!!");
        break;

    }
}
