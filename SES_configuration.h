#include "SES_switch.h"
#include "SES_codes.h"
#include "SES_example_igmp.h"
#include "SES_example_lldp.h"
#include "SES_example_prp_hsr.h"
#include "SES_example_firmware_update.h"
#include "SES_example_time_synchronization.h"
#include "SES_example_scheduled_traffic.h"
#include "SES_example_event.h"
#include "SES_example_frame_api.h"
#include "SES_example_preemption.h"
#include "SES_example_psfp.h"
#include "SES_example_mrp.h"
#include "SES_example_mstp.h"
#include "SES_example_switch.h"
#include "SES_example_frer.h"
#include "SES_example_psfp.h"
#include "SES_example_sendList.h"


#define TRUE 1
#define FALSE 0

/*To configure the switch over SPI, enable the following Macro and ensure all the
* dependencies are resolved as per README.MD related to SPI
*/
/* Host Strapping pins must be configured as per StandardSPI, DualSPI or QuadSPI 
*  as per datasheet under the section HOST INTERFACE*/

//#define ENABLE_SPI

//Switch configuration related controls
#define SES_PORT_COUNT 6

//COnfiguration for Field Switch 
#define  FIELD_SWITCH 0

//Primary MAC address to be assigned to the switch 
#define SES_PRIMARY_MAC { 0x7A, 0xC6, 0xBB, 0x11, 0x11, 0x11 }

//Host MAC Address, if using enertnet this is the address of network adapter 
#define HOST_MAC { 0xAC, 0x91, 0xA1, 0x91, 0xAC, 0x97 };

/*DEFAULT_SWITCH will will enable the following features:
*	--> Initialize LLDP 
*	--> Initialize PTP
*	--> Initialize MSTP
*/
#define DEFAULT_SWITCH 1


//EVENT Example
/**/
#define EVENT 0 //0:disable, 1: Enable LinkEventExample, 2: Enable LLDP Event Example, 3: Timer Event Example

//L2 Frame Example
//0:disable, 1: L2 Transmit, 2: Layer2 receive Stack Processor by MAC, 3: Layer2 receive Stack Processor by Ethertype, 
//4: Layer2 packet received with matching Ethertype, 5: Layer2 packet received with matching MAC
#define LAYER_2 0


//Frame Preemption
#define FRAME_PREEMPTION 0

//Scheduled Traffic
#define SCHEDULED_TRAFFIC 0

//IGMP Snooping
#define IGMP_SNOOPING 0

// HSR, PRP configuration
//Below configuration applied while initializing the HSR/PRP:
//Port 1: PORT A, Port 2 : PORT B,  
#define HSR_PRP 0
//0: HSR, 1: HSRREDBOX, 2: PRP, 3: PRPREDBOX
#define REDUNDANCY_TYPE 0


//Initializing MRP with ::
//Ring Role** : Client
//Recovery Rate** : 500 ms
//Ring Ports * *: Port 1 & 2
//VLAN * *: No Vlan(0x0FFF)
//Priority * *: Default Manager / AutoManager
//priorities React On Link Change * *: Disabled
#define MRP 0


//Firmware update 
#define FIRMWARE_UPDATE 0
#define MULTIPLE_BLOCK 0


//Time Synchronization
#define TIME_SYNC 0
//1: SES_Test_Single_PtpInstance
//2: Boundary clock example  
//3: Ordinary clock example
//4: Transparent clock example
#define CLOCK_TYPE 0

//VLAN Configuration
#define VLAN_CONFIG 0
#define TRUNK_ACCESS 0

//LLDP Configuration
#define LLDP_INIT 0

//FRER Configuration
#define FRER 0
#define FRER_CONFIG 0 //0: Talker, 1: Listner, 2 Both

//SendList Example
#define SENDLIST 0


//PSFP Configuration
// 0: Disable, 1: Stream Gate Example, 2: Stream Filter Example, 3: Flow Meter Example
#define PSFP 0

//MSTP Example
// 0: Disable, 1: MSTP Multiple MSTI Configuration Example
#define MSTP 0

//Switch Example
// 0: Disable, 1: Read Dynamic table Example, 2: Read Port Statistics,
#define SWITCH_EXAMPLE 0

 