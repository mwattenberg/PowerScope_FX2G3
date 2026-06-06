
Logo	
ModusToolbox USBFXStack
Toggle main menu visibility
Home
API Reference

Search
click to disable panel synchronisation
ModusToolbox USBFXStack
Supported FX Devices
Features
More information
API Reference
LVDS/LVCMOS
HB-DMA
FX Utils
FX USB common
Macros
Enumerated Types
Data Structures
Type Definitions
Functions
Functions
Functions
FX USB common
General Description
Functions
static uint32_t * 	Cy_USBHS_CalculateEpmAddr (uint32_t endpNum, cy_en_usb_endp_dir_t endpDirection)
 	Returns the base address of the Endpoint Memory region corresponding to a USBHSDEV endpoint. More...
 
uint32_t 	Cy_USBD_GetVersion (void)
 	Get the USBD middleware version information. More...
 
cy_en_usbd_ret_code_t 	Cy_USB_USBD_Init (void *pAppCtxt, cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, DMAC_Type *pCpuDmacBase, cy_stc_usb_cal_ctxt_t *pCalCtxt, cy_stc_usbss_cal_ctxt_t *pSsCalCtxt, cy_stc_hbdma_mgr_context_t *pHbDmaMgrCtxt)
 	This function initializes USBD layer and activates CAL layer initialization function for SS and HS controller. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_DebugRegisterCallback (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint8_t debugOutEp, cy_en_usb_usbd_cb_t callBackType, cy_usb_usbd_callback_t callBackFunc)
 	This API will be used by CDC (Debug) interface to register required callback. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_RegisterCallback (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_en_usb_usbd_cb_t callBackType, cy_usb_usbd_callback_t callBackFunc)
 	This API will be used by application to register required callback. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_SetDscr (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_en_usb_set_dscr_type_t dscrType, uint8_t dscrIndex, uint8_t *pDscr)
 	This API will be used by application to provide various standard descriptors to USBD layer and USBD layer will use this descriptor in "fast enumeration". More...
 
cy_en_usb_speed_t 	Cy_USBD_GetDeviceSpeed (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	This API returns device's operating speed. More...
 
const char * 	Cy_USBD_GetDeviceSpeedStr (const cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	This API returns the device's operating speed as a human-readable string. More...
 
void 	Cy_USBD_SetDeviceSpeed (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_en_usb_speed_t speed)
 	This API force operating speed of dvice. More...
 
void 	Cy_USBD_SetDeviceSpeedAtUSBDOnly (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_en_usb_speed_t speed)
 	This API is used to set device speed only at USBD layer. More...
 
cy_en_usb_device_state_t 	Cy_USBD_GetDeviceState (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	This API returns present state of device. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_FindEndp0MaxPktSize (uint8_t *pDevDscr, cy_en_usb_speed_t devSpeed, uint32_t *pMaxPktSize)
 	This API finds endpoint 0 max packet size from device descriptor. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_GetLpmBosUSBExt (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint8_t *pLpmSupp)
 	Get information about LPM support from USB ext descriptor. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_GetAttributeBosUSBExt (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint32_t *pAttribute)
 	Get attribute from USB ext descriptor. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_GetAttributeBosSS (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint8_t *pAttribute)
 	Get attribute from Super speed BoS descriptor. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_GetSpeedSuppBosSS (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint32_t *pSpeedSupp)
 	Get Speed supported from Super speed descriptor. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_GetU1U2ExitLatBosSS (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint8_t *pU1ExitLat, uint16_t *pU2ExitLat)
 	Get U1 and U2 exit latency from Super speed BoS descriptor. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_GetAttributeBosSSP (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint32_t *pAttribute)
 	Get attribute from Super speed plus descriptor. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_GetFunctSupportBosSSP (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint32_t *pFuncSupp)
 	Get functionality supported from Super speed plus descriptor. More...
 
bool 	Cy_USBD_isCfgValid (uint8_t cfgNum, const uint8_t *pCfgDscr)
 	This function checks validity of given configuration. More...
 
cy_en_usbd_ret_code_t 	Cy_USB_USBD_GetActiveCfgNum (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint8_t *pCfgNum)
 	This API called by application to know active configuration number. More...
 
uint8_t * 	Cy_USB_USBD_GetActiveCfgDscr (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	This API called by application to get active configuration descriptor. More...
 
uint8_t 	Cy_USBD_FindNumOfIntf (const uint8_t *pCfgDscr)
 	This function finds number of interface supported in given configation. More...
 
bool 	Cy_USBD_FindSelfPower (const uint8_t *pCfgDscr)
 	This function finds device supports Self power or BUS power. More...
 
bool 	Cy_USBD_FindRemoteWakeupAbility (uint8_t *pCfgDscr)
 	This function finds device supports remote wakeup or not. More...
 
bool 	Cy_USBD_GetRemoteWakeupStatus (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	This function checks L2 remote wakeup status and return information. More...
 
void 	Cy_USBD_SignalRemoteWakeup (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, bool startEnd)
 	This function triggers HW to start/end remotewakeup signaling. More...
 
uint8_t * 	Cy_USBD_GetIntfDscr (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint8_t intfNum, uint8_t altSetting)
 	This function called by application to get interface descriptor. More...
 
bool 	Cy_USBD_isIntfValid (uint16_t intf, uint8_t *pCfgDscr)
 	This function checks given interface is part of configuration descriptor or not. More...
 
uint8_t 	Cy_USBD_FindNumOfEndp (uint8_t *pIntfDscr)
 	This function gives number of Endpoints supported by given interface. More...
 
uint8_t * 	Cy_USBD_GetEndpDscr (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint8_t *pIntfDscr)
 	This function to fetch endpoint descriptor for a given interface descriptor. More...
 
uint8_t * 	Cy_USBD_GetSsEndpCompDscr (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint8_t *pEndpDscr)
 	This function to fetch super speed endpoint companion descriptor. More...
 
uint8_t * 	Cy_USBD_GetSspIsoCompDscr (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint8_t *pCompDscr)
 	This function to fetch super speed plus Iso endpoint companion descriptor from given companion descriptor. More...
 
uint8_t * 	Cy_USBD_GetSspIsoEndpCompDscr (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint8_t *pEndpDscr)
 	This function to fetch super speed plus Iso endpoint companion descriptor from given endpoint descriptor. More...
 
cy_en_usbd_ret_code_t 	Cy_USB_USBD_GetActiveAltSetting (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint8_t intfNum, uint8_t *pAltSetting)
 	This function called by application to know active altSetting for a given interface. More...
 
uint8_t 	Cy_USBD_FindAltSetting (uint8_t *pIntfDscr)
 	This API gives information about alt setting supported by given interface. More...
 
uint8_t 	Cy_USBD_GetNumOfAltSetting (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint8_t intfNum)
 	This API gets number of alt setting in an interface from USBD context data structure. More...
 
uint8_t 	Cy_USBD_UpdateNumOfAltSetting (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint8_t intfNum)
 	This API gets number of alt setting in an interface. More...
 
bool 	Cy_USBD_EndpDscrValid (uint8_t *pEndpDscr)
 	This API confirms given descriptor is endpoint descriptor or not. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_GetEndpNumMaxPktDir (uint8_t *pEndpDscr, uint32_t *pEndpNum, uint16_t *pMaxPktSize, uint32_t *pDir)
 	This function fetches endpoint number, maxPktSize and direction from endpoint descriptor. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_GetEndpMaxPktSize (uint8_t *pEndpDscr, uint16_t *pMaxPktSize)
 	This function fetches maxPktSize from endpoint descriptor. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_GetIsoBytesPerIntvl (uint8_t *pIsoCompDscr, uint32_t *pBytesPerIntvl)
 	This function fetches max bytes per interval for Iso endpoint from iso companion endpoint descriptor. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_GetEndpAttribute (uint8_t *pEndpDscr, uint8_t *pAttribute)
 	This function fetches endpoint attribute from endpoint descriptor. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_GetEndpType (uint8_t *pEndpDscr, uint32_t *pEndpType)
 	This function fetches endpoint type from endpoint descriptor. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_GetEndpInterval (uint8_t *pEndpDscr, uint8_t *pInterval)
 	This function fetches bInterval from endpoint descriptor. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_GetEndpCompnMaxburst (uint8_t *pEndpCompnDscr, uint8_t *pMaxBust)
 	This function fetches bMaxBurst from endpoint companion descriptor. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_GetEndpCompnMaxStream (uint8_t *pEndpCompnDscr, uint8_t *pMaxStream)
 	This function fetches bMaxStream from endpoint companion descriptor. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_GetEndpCompnAttribute (uint8_t *pEndpCompnDscr, uint8_t *pAttribute)
 	This function fetches attribute from endpoint companion descriptor. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_GetEndpCompnBytePerInterval (uint8_t *pEndpCompnDscr, uint16_t *pBytePerInterval)
 	This function fetches bytePerInterval from endpoint companion descriptor. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_GetEndpSspIsoCompnBytePerInterval (uint8_t *pSspIsoEndpCompnDscr, uint32_t *pBytePerInterval)
 	This function fetches bytePerInterval from endpoint SS Iso companion descriptor. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_EnableEndp (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir, bool enable)
 	This function enable/disable endpoint. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_SetEpBurstMode (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint32_t endpNumber, cy_en_usb_endp_dir_t endpDirection, bool enable)
 	This function enables/disables the MULT (allow burst across multiple DMA buffers) feature for the specified USB endpoints. More...
 
cy_en_usbd_ret_code_t 	Cy_USB_USBD_EndpConfig (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_endp_config_t endpConfig)
 	This function configures endpoint based on user requirement. More...
 
cy_en_usbd_ret_code_t 	Cy_USB_USBD_EndpSetClearStall (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir, bool setClear)
 	This function enable or disable STALL condition for the endpoint. More...
 
cy_en_usbd_ret_code_t 	Cy_USB_USBD_EndpSetClearNakNrdy (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir, bool setClear)
 	This function enable or disable NAK/NRDY condition for the endpoint. More...
 
void 	Cy_USBD_ResetEndp (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir, bool preserveSeqNo)
 	This function resets endpoint related paramters by calling appropriate function at HW level. More...
 
void 	Cy_USBD_FlushEndp (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint32_t endpNumber, cy_en_usb_endp_dir_t endpDirection)
 	This function flush endpoint data present in EPM. More...
 
void 	Cy_USBD_FlushEndpAll (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_en_usb_endp_dir_t endpDir)
 	This function flush all endpoints data endpoint data present in EPM. More...
 
void 	Cy_USBD_FlushResetEndpAll (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_en_usb_endp_dir_t endpDirection)
 	This function flush/reset all endpoint with perticular direction based on speed of device controller. More...
 
cy_en_usbd_ret_code_t 	Cy_USB_USBD_EndpSetClearNakNrdyAll (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, bool setClear)
 	This function enable or disable NAK/NRDY condition on all endpoints based on speed of device. More...
 
bool 	Cy_USBD_EndpIsNakNrdySet (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir)
 	This function checks whether the specified endpoint currently has the NAK/NRDY bit set. More...
 
bool 	Cy_USBD_EndpIsStallSet (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDirection)
 	This function checks whether the specified endpoint currently has the STALL bit set. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_EndpMapStream (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint32_t endpNumber, cy_en_usb_endp_dir_t endpDirection, uint16_t streamId, uint32_t socketNum)
 	This function maps an unused USB Ingress/Egress socket to the specified stream associated with a bulk endpoint. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_EndpUnmapStream (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir, uint32_t socketNum)
 	This function unmaps the USB ingress/egress socket to bulk stream mapping for a bulk endpoint and socket. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_EndpSetPktsPerBuffer (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint32_t endpNumber, uint8_t pktsPerBuffer)
 	This function is used to update the USB block with the number of max. More...
 
void 	Cy_USBD_UpdateXferCount (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint32_t endpNumber, cy_en_usb_endp_dir_t endpDirection, uint32_t bufferSize)
 	This function will update xfer count based on speed of device. More...
 
void 	Cy_USBD_CtrlEndp0DataOutAck (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, bool setClear)
 	Data stage ACK for endpoint0 is controlled by this function. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_EnableStatusCtrl (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, bool enable)
 	This function enable/disable status control feature which is part of SS controller. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_ClearStatusClrBusy (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	This function write "1" to STATUS_CLR_BUSY which clears the bit to initiate STATUS response. More...
 
void 	Cy_USBD_SendAckSetupDataStatusStage (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	Allow chipset to send ACK to complete control transfer. More...
 
cy_en_usbd_ret_code_t 	Cy_USB_USBD_SendEndp0Data (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint8_t *pBuffer, uint32_t bufferSize)
 	This function sends data overthe DMA for endpoint 0. More...
 
cy_en_usbd_ret_code_t 	Cy_USB_USBD_SendEndp0DataSs (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint8_t *pBuffer, uint32_t bufferSize)
 	This function sends data overthe DMA for endpoint 0 of SS device. More...
 
cy_en_usbd_ret_code_t 	Cy_USB_USBD_SendEndp0DataHs (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint8_t *pBuffer, uint32_t bufferSize)
 	This function sends data overthe DMA for endpoint 0 of HS device. More...
 
cy_en_usbd_ret_code_t 	Cy_USB_USBD_RecvEndp0Data (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint8_t *pBuffer, uint32_t bufferSize)
 	This function receives data overthe DMA for endpoint 0. More...
 
cy_en_usbd_ret_code_t 	Cy_USB_USBD_RecvEndp0DataSs (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint8_t *pBuffer, uint32_t bufferSize)
 	This function to recieve data for endpoint 0 through DMA for SS. More...
 
cy_en_usbd_ret_code_t 	Cy_USB_USBD_RecvEndp0DataHs (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint8_t *pBuffer, uint32_t bufferSize)
 	This function to recieve data for endpoint 0 through DMA for HS. More...
 
bool 	Cy_USBD_IsEp0ReceiveDone (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	This function checks whether a EP0 data receive operation is pending. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleGetDscr (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_setup_req_t setupReq, cy_stc_usb_cal_msg_t *pMsg)
 	This function handles all get descriptor command coming from host. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleGetStatus (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_setup_req_t setupReq)
 	This function handles get status request coming from host. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleSetFeature (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_setup_req_t setupReq, cy_stc_usb_cal_msg_t *pMsg)
 	This function handles set-feature request came from host. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleClearFeature (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_setup_req_t setupReq, cy_stc_usb_cal_msg_t *pMsg)
 	This function handles clear-feature request came from host. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleSetConfiguration (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_setup_req_t setupReq, cy_stc_usb_cal_msg_t *pMsg)
 	This function handles set configuration request came from host. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleGetConfiguration (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_setup_req_t setupReq)
 	This function handles get configuration request came from host. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleSetInterface (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_setup_req_t setupReq, cy_stc_usb_cal_msg_t *pMsg)
 	This function handles set interface request came from host. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleGetInterface (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_setup_req_t setupReq)
 	This function handles get interface request came from host. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleReset (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg)
 	This function handles bus reset. More...
 
void 	Cy_USBD_HandleRxFailure (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, bool enable, uint8_t retry_cnt)
 	Enables USB stack level work-around to attempt Gen2 connection start-up multiple times in case of training failure in Polling.Active or Polling.Config states. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleSsReset (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg)
 	This function handles reset in SS mode. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleHsGrant (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg)
 	High speed related switching is handled here. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleResetDone (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg)
 	This function handles reset-done message. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleCtrlXfrSetupStage (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg)
 	This function handles setup stage of control transfer. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleStatusStage (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg)
 	This function handles status stage of control transfer. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleSuspend (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg)
 	This function handles suspend functionality. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleResume (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg)
 	This function handles resume functionality. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleL1Sleep (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg)
 	This function handles L1-Sleep functionality. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleL1Resume (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg)
 	This function handles L1-Resume functionality. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleZlp (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg)
 	This function handles Zero-Length-Packet. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleDone (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg)
 	This function handles done interrupt for an endpoint. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleRateChange (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg)
 	This function handles rate change. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleSlp (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg)
 	This function handles short length packet functionality. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleSsDisconnect (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg)
 	This function handles disconnect event/message came from bottom layer. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_HandleMsg (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg)
 	This function handles all messages comes from bottom layer. More...
 
void 	Cy_USBD_InitUsbDscrPtrs (cy_stc_usb_set_dscr_ptrs_t *pDscr)
 	This function initializes all descriptor pointers to NULL. More...
 
void 	Cy_USBD_ConnectHsDevice (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	This functions connects HS device to BUS and make it visible to host. More...
 
void 	Cy_USBD_ConnectSsDevice (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	This functions connects SS device to BUS and make it visible to host. More...
 
void 	Cy_USBD_ConnectDevice (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_en_usb_speed_t usbSpeed)
 	This functions connects USB device with given speed and make it visible on BUS. More...
 
void 	Cy_USBD_ResetUsbdCommonDs (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	This functions reset all USBD common data structure. More...
 
void 	Cy_USBD_DisconnectHsDevice (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	This functions dis-connects HS device from BUS and make it invisible to host. More...
 
void 	Cy_USBD_DisconnectSsDevice (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	This functions dis-connects SS device from BUS and make it invisible to host. More...
 
void 	Cy_USBD_DisconnectDevice (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	Disconnect device from BUS. More...
 
void 	Cy_USB_USBD_InitEndp0InCpuDmaDscrConfig (cy_stc_usbd_dma_descr_conf_t *pEndp0InCpuDmaDscrConfig, bool first)
 	It initializes DMA descriptor for endpoint 0 IN transfer. More...
 
void 	Cy_USB_USBD_InitEndp0OutCpuDmaDscrConfig (cy_stc_usbd_dma_descr_conf_t *pEndp0OutdscrConfig, bool first)
 	It initializes DMA descriptor for EP0-OUT transfers. More...
 
void 	Cy_USB_USBD_InitCpuDmaChannelCfg (cy_stc_usbd_dma_chn_conf_t *pDmaChCfg, cy_stc_usbd_dma_descr_t *pDmaDscr)
 	It initializes DMA channel config. More...
 
cy_en_usbd_ret_code_t 	Cy_USB_USBD_cpuDmaInit (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	It initializes Cpu DMA functionality. More...
 
cy_en_usbd_ret_code_t 	Cy_USB_USBD_EndpInit (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	This function initializes endpoint 0 and other endpoints for HS and SS controller. More...
 
void 	Cy_USB_USBD_DisableHsDevice (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	This function disable all HS device interrupt and make device invisible on BUS. More...
 
void 	Cy_USB_USBD_EnableHsDevice (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	This function enable HS device and make it visible on BUS. More...
 
void 	Cy_USBD_CtrlHSEnableOnCompliance (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, bool hsEnable)
 	Function used to enable/disable switch to USB-HS (2.0) mode on entry into the USB 3.x Compliance LTSSM state. More...
 
void 	Cy_USBD_TaskHandler (void *pTaskParam)
 	This function handles msg coming from CAL layer. More...
 
bool 	Cy_USBD_ProcessMsg (void *pUsbd, void *pCalMgs)
 	This function sends msg to USBD thread. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_SendEgressZLP (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint32_t endpNumber)
 	This function sends ZLP for given endpoint. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_ClearZlpSlpIntrEnableMask (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir, bool zlpSlp)
 	This function clears endpoint interrupt for ingrress and egresss and enables respective mask register. More...
 
cy_en_usbd_ret_code_t 	Cy_USB_LpmSetClearNYET (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, bool setClear)
 	This is a stack internal function used to enable/disable LPM support. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_GetUSBLinkActive (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	This function ensures that the USB link is brought into the L0 (USB2) or U0 (USB3) state when the respective low power states. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_LpmDisable (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	This function disables all further transitions into a USB low power (U1, U2, or L1) state. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_LpmEnable (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	This function re-enables state based transitions into USB low power (U1, U2 and L1) modes. More...
 
void 	Cy_USB_USBD_RetireRecvEndp0DataSs (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	This function will disable dma channel for SS which was submitted to recieve data. More...
 
void 	Cy_USB_USBD_RetireRecvEndp0DataHs (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	This function will disable dma channel for HS which was submitted to recieve data. More...
 
cy_en_usbd_ret_code_t 	Cy_USB_USBD_RetireRecvEndp0Data (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	This function will disable dma channel which was submitted to recieve data. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_SendSSDeviceNotification (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_en_usbd_notification_type_t type, uint32_t param0, uint32_t param1)
 	This function sends a Device Notification Transaction Packet to the host controller on a USB 3.2 link. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_InitEventLog (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint32_t *pEvtLogBuf, uint16_t evtLogSize)
 	Enables capture of USB HS/SS driver events and state changes into RAM buffer. More...
 
void 	Cy_USBD_AddEvtToLog (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint32_t evtId)
 	Add USB event/state to the RAM log buffer. More...
 
uint16_t 	Cy_USBD_GetEvtLogIndex (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	Returns the current USB driver event log index. More...
 
void 	Cy_USBD_TickIncrement (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	Increment the timer tick variable used to timestamp the USB event logs. More...
 
uint32_t 	Cy_USBD_GetTimerTick (void)
 	Retrieve the current value of the timer tick. More...
 
void 	Cy_USBD_ResetTimerTick (void)
 	Clear the timer tick value maintained in the USB stack.
 
void 	Cy_USBD_EP0OutDma_IntrHandler (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	Handler for interrupt associated with EP0-OUT DMA transfer in USB 2.x modes. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_SetDmaClkFreq (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_en_hbdma_clk_freq_t dmaFreq)
 	Function which sets the desired DMA clock frequency during USB 3.x operation on the FX3G2 device. More...
 
void 	Cy_USBD_DisableLPMDeviceExit (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, bool devExitDisable)
 	Function to disable support for device initiated exit from USB 3.x low power modes completely. More...
 
void 	Cy_USBD_DisableSSOnBusReset (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	Function which disables the USB 3.x reconnection when USB 2.x Bus Reset is received. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_SelectConfigLane (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_en_usb_config_lane_t laneSel)
 	Function to select the USB 3.x Configuration Lane. More...
 
cy_en_usb_endp_type_t 	Cy_USBD_GetEndpointType (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint32_t endpNumber, cy_en_usb_endp_dir_t endpDirection)
 	Function to identify the type of endpoint based on its index. More...
 
void 	Cy_USBD_ResetEndpoints (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, uint32_t outEpMask, uint32_t inEpMask, uint32_t preserveOutSeqNum, uint32_t preserveInSeqNum)
 	This function resets transient state associated with the specified OUT and IN endpoints. More...
 
void 	Cy_USBD_GetDeviceStats (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usbd_devstats_t *pDevStats)
 	This function retrieves USB connection statistics maintained by the stack and driver layers. More...
 
bool 	Cy_USBD_ControlUsb2Support (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, bool enable)
 	Enable/Disable USB 2.x device operation on the device. More...
 
cy_en_usbd_usb_powerstate_t 	Cy_USBD_GetUSBPowerState (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt)
 	This function returns the current USB power state (U0/U1/U2 for USB3 and L0/SUSPEND for USB2) of the device. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_EnterDeepsleep (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, DW_Type *pCpuDw1Base)
 	This function prepares and puts the device into deepsleep. More...
 
cy_en_usbd_ret_code_t 	Cy_USBD_SelectHSCtleConfig (cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_en_hs_ctle_sel_t ctleSel)
 	Selects the HS CTLE configuration for USB 2.x operation. More...
 
void 	Cy_USBHS_Cal_Init (cy_stc_usb_cal_ctxt_t *pCalCtxt, void *pUsbdCtxt, cy_usb_cal_msg_callback_t callBackFunc)
 	Initializes the HS controller ie CAL layer and PHY. More...
 
void 	Cy_USBHS_Cal_FsHsModePhyInit (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	Initializes high speed PHY. More...
 
void 	Cy_USBHS_Cal_PhyCommonInit (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	Initializes registers common to full and high speed PHY configuration. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_HandleReset (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	During reset controller updates. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_ConnUsbPins (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	Update USB device controller register to make USB device visible on Bus. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_DisconUsbPins (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	Update Controller register to make USB device invisible on Bus. More...
 
void 	Cy_USBHS_Cal_HsHandleL1Sleep (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	L1-SLEEP request during device in high speed mode will be handled here. More...
 
void 	Cy_USBHS_Cal_HsHandleL1WakeupCommon (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	L1-Wakeup request during device in high speed mode will be handled here. More...
 
void 	Cy_USBHS_Cal_DevInitiatedL1Exit (cy_stc_usb_cal_ctxt_t *pCalCtxt, uint32_t duration)
 	Function helps device to initiate resume from L1 SleepDevice. More...
 
void 	Cy_USBHS_Cal_DevInitiatedResumeL2Sleep (cy_stc_usb_cal_ctxt_t *pCalCtxt, uint32_t duration)
 	Function helps device to initiate resume from L2 SleepDevice. More...
 
bool 	Cy_USBHS_Cal_HsHandleL2SuspendEntry (cy_stc_usb_cal_ctxt_t *pCalCtxt, bool keepPllOn)
 	This function Handles Suspend at CAL layer in High speed mode. More...
 
void 	Cy_USBHS_Cal_FsHandleSuspend (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	This function Handles Suspend at CAL layer in Full speed mode. More...
 
void 	Cy_USBHS_Cal_HsHandleL2Resume (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	This function Handles resume at CAL layer in high speed mode. More...
 
void 	Cy_USBHS_Cal_FsHandleResume (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	This function Handles resume at CAL layer in full speed mode. More...
 
bool 	Cy_USBHS_Cal_IntrHandler (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	This function Handles All interrupt related to controller. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_EnableReqDevCtrlIntr (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	This function will enable required interrupt under device ctrl reister. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_DisableAllDevCtrlIntr (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	This function will disable all possible interrupt generated by USB device. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_ClearAllDevCtrlIntr (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	This function will clear all interrupt bit in device ctrl register. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_UpdateEpIntrMask (cy_stc_usb_cal_ctxt_t *pCalCtxt, uint32_t endpNumber, cy_en_usb_endp_dir_t endpDirection, uint32_t epIntrMask, bool setClear)
 	This function updates the interrupt mask for an endpoint with the desired values. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_ClearZlpSlpIntrEnableMask (cy_stc_usb_cal_ctxt_t *pCalCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir, bool zlpSlp)
 	This function clears endpoint interrupt for ingress and egress intrrupt and enables respective mask register. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_EnableCtrlSlpIntr (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	This function enables the SLP_RCVD interrupt for EP0-OUT. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_DisableCtrlSlpIntr (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	This function disable the SLP_RCVD interrupt for EP0-OUT. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_EnableEndp (cy_stc_usb_cal_ctxt_t *pCalCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir, bool enable)
 	This function enables/disable endpoint and set/reset respective interrupt. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_EndpConfig (cy_stc_usb_cal_ctxt_t *pCalCtxt, cy_stc_usb_endp_config_t configParam)
 	This function handles configuration of endpoint. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_UpdateXferCount (cy_stc_usb_cal_ctxt_t *pCalCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir, uint32_t xferCount)
 	This function updates register with transfer count. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_EndpSetClearNak (cy_stc_usb_cal_ctxt_t *pCalCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir, bool setClear)
 	This function enable or disable NAK condition in hw. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_SetClearNakAll (cy_stc_usb_cal_ctxt_t *pCalCtxt, bool setClear)
 	This function either set or clear NAK for all endpoint. More...
 
bool 	Cy_USBHS_Cal_EndpIsNakNrdySet (cy_stc_usb_cal_ctxt_t *pCalCtxt, uint32_t endpNumber, cy_en_usb_endp_dir_t endpDirection)
 	This function checks endpoint's status related to NAK bit is set or reset. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_EndpSetClearStall (cy_stc_usb_cal_ctxt_t *pCalCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir, bool setClear)
 	This function enable or disable STALL condition in hw. More...
 
bool 	Cy_USBHS_Cal_EndpIsStallSet (cy_stc_usb_cal_ctxt_t *pCalCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir)
 	This function checks whether the specified endpoint is currently in the STALLed state. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_FlushEndp (cy_stc_usb_cal_ctxt_t *pCalCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir)
 	This function will flush data available in perticular endpoint FIFO. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_FlushAllEndp (cy_stc_usb_cal_ctxt_t *pCalCtxt, bool ingressFlush, bool egressFlush)
 	This function will flush data available in all Ingress and egress endpoint FIFO. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_SendEgressZLP (cy_stc_usb_cal_ctxt_t *pCalCtxt, uint32_t endpNum)
 	This function triggers sending of a ZLP on an Egress endpoint. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_HandleCtrlOutSlp (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	This function clears SLP ingress interrupt. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_CtrlEndp0DataOutAck (cy_stc_usb_cal_ctxt_t *pCalCtxt, bool setClear)
 	Data stage ACK for endpoint0 is controlled by this function. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_SendAckSetupDataStatusStage (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	This function update register so that device will send ACK to complete control transfer. More...
 
bool 	Cy_USBHS_Cal_GetRemoteWakeupStatus (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	This function returns status of L2 remote wakeup in HW. More...
 
bool 	Cy_USBHS_Cal_GetL1RemoteWakeupStatus (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	This function returns status of L1 remote wakeup in HW. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_SignalRemotWakup (cy_stc_usb_cal_ctxt_t *pCalCtxt, bool startEndSignal)
 	This function will update register so that device will initiate remote wakeup signaling ie it will try to comeout from L2_SUSPEND. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_SetTestMode (cy_stc_usb_cal_ctxt_t *pCalCtxt, cy_en_usbhs_cal_test_mode_t testMode)
 	This function will update register to setup required test mode. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_LpmSetClearNYET (cy_stc_usb_cal_ctxt_t *pCalCtxt, bool setClear)
 	This function either set or clear NYET bit for LPM response. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_SetControllerSpeed (cy_stc_usb_cal_ctxt_t *pCalCtxt, cy_en_usb_speed_t speed)
 	This function set controller speed to FS or HS. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_GetDevAddress (cy_stc_usb_cal_ctxt_t *pCalCtxt, uint8_t *pDevAddr)
 	This function will get device address assigned by Host. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_GetLinkActive (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	This function makes sure that the USB 2.x link gets into the L0 state if it is in L1. More...
 
bool 	Cy_USBHS_Cal_SendMsg (cy_stc_usb_cal_ctxt_t *pCalCtxt, void *pMsg)
 	This function send message to upper layer ie USBD layer. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_DeinitPLL (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	Function to de-initialize the PLL in the USBHS block. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_InitPLL (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	Function to initialize the PLL in the USBHS block to generate the 480 MHz clock required by the High BandWidth SubSystem for its operation. More...
 
bool 	Cy_USBHS_Cal_IsLinkActive (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	Check whether the USB 2.x link is in active (L0) state. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_GetXferCount (cy_stc_usb_cal_ctxt_t *pCalCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir, uint32_t *pCntPending)
 	Retrieve the remaining transfer count on the specified endpoint. More...
 
bool 	Cy_USBHS_Cal_IsNewCtrlRqtReceived (cy_stc_usb_cal_ctxt_t *pCalCtxt)
 	This function uses the SETUP_CLR_BUSY to check whether a new control request has been received while a previous send/recv data call is pending. More...
 
void 	Cy_USBHS_Cal_PreemphasisControl (cy_stc_usb_cal_ctxt_t *pCalCtxt, bool enable)
 	Function to enable/disable Pre-emphasis based on the active USB test mode. More...
 
void 	Cy_USBHS_Cal_SOFIntrUpdate (cy_stc_usb_cal_ctxt_t *pCalCtxt, bool sofIntrEnable)
 	Function to enable or disable the SOF interrupt based on user requirement. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBHS_Cal_SetCtleSelValue (cy_stc_usb_cal_ctxt_t *pCalCtxt, cy_en_hs_ctle_sel_t ctleSel)
 	Sets the HS_CTLE_SEL field in the AFE_CONTROL_1 register of the USBHS PHY. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_Init (cy_stc_usbss_cal_ctxt_t *pCalCtxt, void *pUsbdCtxt, cy_usb_cal_msg_callback_t cb)
 	Initializes the USBSS IP and relevant variables. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_Connect (cy_stc_usbss_cal_ctxt_t *pCalCtxt, cy_en_usb_speed_t usbSpeed)
 	Enables the USB3 RX terminations for connecting to the host and enables relevant USB LINK and PROTOCOL interrupts. More...
 
bool 	Cy_USBSS_Cal_SendMsg (cy_stc_usbss_cal_ctxt_t *pCalCtxt, void *pMsg)
 	Sends message to the USBD layer using a callback registered by the user. More...
 
void 	Cy_USBSS_Cal_IntrHandler (cy_stc_usbss_cal_ctxt_t *pCalCtxt)
 	Interrupt Handler function for USB3 IP. More...
 
void 	Cy_USBSS_Cal_WakeupIntrHandler (cy_stc_usbss_cal_ctxt_t *pCalCtxt)
 	Wakeup Interrupt Handler function for USB3 IP. More...
 
uint32_t 	Cy_USBSS_Cal_Get_PtmStatus (cy_stc_usbss_cal_ctxt_t *pCalCtxt)
 	Sends the PTM STATUS to the USBD layer to repsond to GET_STATUS request. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_LPMEnable (cy_stc_usbss_cal_ctxt_t *pCalCtxt, bool isResume)
 	Enables the USB3 Link layer Low Power Mode Handling. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_ForceLPMAccept (cy_stc_usbss_cal_ctxt_t *pCalCtxt, bool enable)
 	Enables the USB3 Link layer to always accept LPM requests going into U1/U2 upon receiving LGO_U1/LGO_U2. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_LPMDisable (cy_stc_usbss_cal_ctxt_t *pCalCtxt)
 	Enables the USB3 Link layer to disable accepting LPM requests going into U1/U2 upon receiving LGO_U1/LGO_U2. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_SetLinkPowerState (cy_stc_usbss_cal_ctxt_t *pCalCtxt, cy_en_usbss_lnk_power_mode_t lnkMode)
 	Forces the USB3 Link layer to a particular Link Power State by sending LGO_Ux requests. More...
 
void 	Cy_USBSS_Cal_GetUsbLinkActive (cy_stc_usbss_cal_ctxt_t *pCalCtxt)
 	Get the USB3 Link layer to U0 State if it is in U1/U2 state. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_GetLinkPowerState (cy_stc_usbss_cal_ctxt_t *pCalCtxt, cy_en_usbss_lnk_power_mode_t *pMode)
 	Retrieves the Link Power State of the device. More...
 
void 	Cy_USBSS_Cal_ProtSendTp (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint32_t *pTpData)
 	This function will send transaction packet. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_ProtSendAckTp (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir, uint8_t numP, uint16_t bulkStream)
 	This function prepares and send ACK transaction packet. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_ProtSendErdyTp (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir, uint8_t numP, uint16_t bulkStream)
 	This function prepares and send ERDY transaction packet. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_ProtSendNrdyTp (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir, uint16_t bulkStream)
 	This function prepares and send NRDY transaction packet. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_EndpReset (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir)
 	Function to reset an endpoint. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_GetSeqNum (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir, uint8_t *pSeqNum)
 	This function gets the current value of sequence number for an endpoint. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_SetSeqNum (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir, uint8_t seqNum)
 	This function sets value of sequence number in hardware for an endpoint. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_GetDevAddress (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint8_t *pDevAddr)
 	This function will get device address assigned by Host. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_EndpSetClearStall (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir, bool setClear)
 	This function enable or disable NRDY condition in hw. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_EndpSetClearNrdy (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir, bool setClear)
 	This function enable or disable NRDY condition in hw. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_SetClearNrdyAll (cy_stc_usbss_cal_ctxt_t *pCalCtxt, bool setClear)
 	This function enable or disable NRDY condition for all endpopint. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_EndpConfig (cy_stc_usbss_cal_ctxt_t *pCalCtxt, cy_stc_usb_endp_config_t configParam)
 	This function handles configuration of endpoint. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_EndpSetPktsPerBuffer (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint32_t endpNumber, uint8_t pktsPerBuffer)
 	This function sets the number of maximum sized packets that can fit into a single DMA buffer for an Ingress endpoint. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_EndpMapStream (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint32_t endpNumber, cy_en_usb_endp_dir_t endpDirection, uint16_t streamId, uint32_t socketNum)
 	This function maps an unused USB Ingress/Egress socket to the specified stream associated with a bulk endpoint. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_EndpUnmapStream (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir, uint32_t socketNum)
 	This function unmaps the DMA socket to stream mapping for a bulk endpoint. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_EnableEndp (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint32_t endpNumber, cy_en_usb_endp_dir_t endpDirection, bool enable)
 	This function enables/disable endpoint and set/reset respective interrupt. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_SetEpBurstMode (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint32_t endpNumber, cy_en_usb_endp_dir_t endpDirection, bool enable)
 	This function enables/disables the MULT (allow burst across multiple DMA buffers) feature for the specified USB endpoints. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_SetEndpRetryOffset (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint32_t endpNumber, uint16_t retryBufOffset)
 	This function sets the egress endpoint retry buffer offset for Type-2 (CTRL and BULK) endpoints. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_UpdateXferCount (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir, uint32_t xferCount)
 	This function updates xfer count in an ndpoint register. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_EnableStatusCtrl (cy_stc_usbss_cal_ctxt_t *pCalCtxt, bool enable)
 	This function enable/disable Status Control feature mentioned in PROT_CS register. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_ClearStatusClrBusy (cy_stc_usbss_cal_ctxt_t *pCalCtxt)
 	This function write "1" to STATUS_CLR_BUSY which clears the bit to initiate STATUS response. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_SendAckSetupDataStatusStage (cy_stc_usbss_cal_ctxt_t *pCalCtxt)
 	This function enable HW to send ACK in status stage. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_FlushEPM (cy_stc_usbss_cal_ctxt_t *pCalCtxt, bool force)
 	This function will flush Ingress and egress both the EPM. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_FlushEndpSocket (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir)
 	This function will flush socket associated with an endpoint. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_FlushAllEndpSocket (cy_stc_usbss_cal_ctxt_t *pCalCtxt)
 	This function will flush socket associated with all endpoints. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_EnableMainIntr (cy_stc_usbss_cal_ctxt_t *pCalCtxt, bool EnableDisable)
 	This function will enable/disable main interrupts. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_EnableLinkIntr (cy_stc_usbss_cal_ctxt_t *pCalCtxt, bool EnableDisable)
 	This function will enable/disable link interrupts. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_EnableProtIntr (cy_stc_usbss_cal_ctxt_t *pCalCtxt, bool EnableDisable)
 	This function will enable/disable protocol interrupts. More...
 
bool 	Cy_USBSS_Cal_EndpIsNakNrdySet (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint32_t endpNum, cy_en_usb_endp_dir_t endpDir)
 	This function checks whether the specified endpoint is currently in the NRDYed state. More...
 
bool 	Cy_USBSS_Cal_EndpIsStallSet (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint32_t endpNumber, cy_en_usb_endp_dir_t endpDirection)
 	This function checks whether the specified endpoint is currently in the STALLed state. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_EnableSsDevice (cy_stc_usbss_cal_ctxt_t *pCalCtxt, bool enable)
 	This function enable/disable USB device in SS mode. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_DisConnect (cy_stc_usbss_cal_ctxt_t *pCalCtxt)
 	This function handles disconnect device at CAL layer. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_PTMConfig (cy_stc_usbss_cal_ctxt_t *pCalCtxt, bool ptmControl)
 	This function handles PTM related configuration. More...
 
void 	Cy_USBSS_Cal_EnterLinkCompliance (cy_stc_usbss_cal_ctxt_t *pCalCtxt)
 	This function performs the actions required when the USB LTSSM enters the Compliance state. More...
 
void 	Cy_USBSS_Cal_NextCompliancePattern (cy_stc_usbss_cal_ctxt_t *pCalCtxt)
 	This function causes the LTSSM to move to the next compliance pattern once a Ping.LFPS has been detected. More...
 
void 	Cy_USBSS_Cal_ExitLinkCompliance (cy_stc_usbss_cal_ctxt_t *pCalCtxt)
 	This function performs the required actions when the LTSSM exits the Compliance state due to a Warm Reset. More...
 
void 	Cy_USBSS_Cal_SetGen2EBDepth (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint8_t gen2_ebdepth)
 	Function to update the Elastic Buffer Half Depth setting to be used in Gen2 USB connection. More...
 
bool 	Cy_USBSS_Cal_IsEnabled (cy_stc_usbss_cal_ctxt_t *pCalCtxt)
 	Indicates whether USB 3.x connection is enabled on the device. More...
 
uint8_t 	Cy_USBSS_Cal_MeasureCCVoltage (cy_stc_usbss_cal_ctxt_t *pCalCtxt, bool cc2select)
 	Measure the voltage on CC line and return the corresponding ADC reading. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_SetDmaClkFreq (cy_stc_usbss_cal_ctxt_t *pCalCtxt, cy_en_hbdma_clk_freq_t dmaFreq)
 	Function which sets the desired DMA clock frequency on the FX3G2 device. More...
 
bool 	Cy_USBSS_Cal_DeepSleepPrep (cy_stc_usbss_cal_ctxt_t *pCalCtxt)
 	This function prepares the USB32DEV controller IP block for entry into deep sleep state. More...
 
void 	Cy_USBSS_Cal_DeepSleepExit (cy_stc_usbss_cal_ctxt_t *pCalCtxt)
 	This function restores the USB32DEV controller IP block state after USB link has resumed from U3 (suspend) state. More...
 
void 	Cy_USBSS_Cal_DisableLPMDeviceExit (cy_stc_usbss_cal_ctxt_t *pCalCtxt, bool devExitDisable)
 	Function to disable support for device initiated exit from USB low power modes completely. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_InitEventLog (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint32_t *pEvtLogBuf, uint16_t evtLogSize)
 	Enables capture of USBSS CAL event and state changes into RAM buffer. More...
 
void 	Cy_USBSS_Cal_PostEpEnable (cy_stc_usbss_cal_ctxt_t *pCalCtxt)
 	Function to reset egress socket EOB detection function after endpoints have been enabled. More...
 
void 	Cy_USBSS_Cal_ReleaseLTSSM (cy_stc_usbss_cal_ctxt_t *pCalCtxt)
 	Function to release the LTSSM from a forced state. More...
 
void 	Cy_USBSS_Cal_ClkStopOnEpRstEnable (cy_stc_usbss_cal_ctxt_t *pCalCtxt, bool clkStopEn)
 	Function to enable stop/restart of USB block clock during EP reset. More...
 
void 	Cy_USBSS_Cal_SelectConfigLane (cy_stc_usbss_cal_ctxt_t *pCalCtxt, cy_en_usb_config_lane_t laneSel)
 	Function to select the USB 3.x Configuration Lane. More...
 
void 	Cy_USBSS_Cal_ITPIntrUpdate (cy_stc_usbss_cal_ctxt_t *pCalCtxt, bool itpIntrEnable)
 	Function to enable or disable the ITP interrupt based on user requirement. More...
 
uint8_t 	Cy_USBSS_Cal_GetTemperatureReading (cy_stc_usbss_cal_ctxt_t *pCalCtxt)
 	Get the temperature sensitive reading from ADC in the USB block. More...
 
void 	Cy_USBSS_Cal_TimerISR (cy_stc_usbss_cal_ctxt_t *pCalCtxt)
 	Function that handles the delay timer expiry based on the event This function should be called by the user when the TCPWM ISR is invoked. More...
 
cy_en_usb_cal_ret_code_t 	Cy_USBSS_Cal_ResetEndpoints (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint32_t outEpMask, uint32_t inEpMask, uint32_t preserveOutSeqNum, uint32_t preserveInSeqNum)
 	Function to flush and reset stale state and data on multiple endpoints. More...
 
void 	Cy_USBSS_SetPreShootnDeEmphasis (cy_stc_usbss_cal_ctxt_t *pCalCtxt, int8_t PS_dBx10, int8_t DE_dBx10)
 	Function to set the preshoot an de-emphasis values for USB 3.x PHY TX. More...
 
void 	Cy_USBSS_SetTransmitAmplitude (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint16_t amplitude_mV)
 	Function to set the transmitter differential amplitude in mV units. More...
 
void 	Cy_USBSS_UpdateCtleLutMask (cy_stc_usbss_cal_ctxt_t *pCalCtxt, cy_en_usb_speed_t usbSpeed, uint16_t lutMask)
 	Function to update the LUT selection mask for selected USB Speeds. More...
 
void 	Cy_USBSS_UpdateGen2CtleLutConfig (cy_stc_usbss_cal_ctxt_t *pCalCtxt, uint32_t *pLutConfigArray)
 	Function to update the CTLE configuration look up table for USB Gen2 speeds. More...
 
Function Documentation
◆ Cy_USBHS_CalculateEpmAddr()
static uint32_t * Cy_USBHS_CalculateEpmAddr	(	uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDirection 
)		
inlinestatic
Returns the base address of the Endpoint Memory region corresponding to a USBHSDEV endpoint.

Parameters
endpNum	Endpoint index (valid range is 0 to 15).
endpDirection	Direction of the endpoint
Returns
The base address of the endpoint memory region for the endpoint.
◆ Cy_USBD_GetVersion()
uint32_t Cy_USBD_GetVersion	(	void 		)	
Get the USBD middleware version information.

Returns
32-bit version information including major, minor, patch and build numbers.
◆ Cy_USB_USBD_Init()
cy_en_usbd_ret_code_t Cy_USB_USBD_Init	(	void * 	pAppCtxt,
cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
DMAC_Type * 	pCpuDmacBase,
cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
cy_stc_usbss_cal_ctxt_t * 	pSsCalCtxt,
cy_stc_hbdma_mgr_context_t * 	pHbDmaMgrCtxt 
)		
This function initializes USBD layer and activates CAL layer initialization function for SS and HS controller.

Parameters
pAppCtxt	application layer context pointer
pUsbdCtxt	USBD layer context pointer.
pCpuDmacBase	Base address for CPU DMA.
pCalCtxt	CAL layer context pointer for HS controller.
pSsCalCtxt	CAL layer context pointer for SS controller.
pHbDmaMgrCtxt	High Bandwidth DMA MgrCtxt.
Returns
CY_USBD_STATUS_SUCCESS if the operation is successful. CY_USBD_STATUS_FAILURE if the opration is failed.
◆ Cy_USBD_DebugRegisterCallback()
cy_en_usbd_ret_code_t Cy_USBD_DebugRegisterCallback	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint8_t 	debugOutEp,
cy_en_usb_usbd_cb_t 	callBackType,
cy_usb_usbd_callback_t 	callBackFunc 
)		
This API will be used by CDC (Debug) interface to register required callback.

Parameters
pUsbdCtxt	USBD Context
debugOutEp	CDC (Debug) OUT endpoint number.
callBackType	USBD callback type
callBackFunc	Registered callback function
Returns
CY_USBD_STATUS_SUCCESS if the operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_BAD_PARAM if ednpoint number is out of range CY_USBD_STATUS_INVALID_CALLBACK_TYPE if callback type not supported.
◆ Cy_USBD_RegisterCallback()
cy_en_usbd_ret_code_t Cy_USBD_RegisterCallback	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_en_usb_usbd_cb_t 	callBackType,
cy_usb_usbd_callback_t 	callBackFunc 
)		
This API will be used by application to register required callback.

Parameters
pUsbdCtxt	USBD layer context pointer.
callBackType	Base address for CPU DMA.
callBackFunc	Base address for DATAWIRE0.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_INVALID_CALLBACK_TYPE if callback type not supported.
◆ Cy_USBD_SetDscr()
cy_en_usbd_ret_code_t Cy_USBD_SetDscr	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_en_usb_set_dscr_type_t 	dscrType,
uint8_t 	dscrIndex,
uint8_t * 	pDscr 
)		
This API will be used by application to provide various standard descriptors to USBD layer and USBD layer will use this descriptor in "fast enumeration".

It is callers responsibility to provide proper descriptor with right index.

Parameters
pUsbdCtxt	USBD layer context pointer.
dscrType	Type of descriptor.
dscrIndex	Descriptor Index.
pDscr	Pointer to descriptor data based on type.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_BAD_PARAM if pointer to descriptor is NULL. CY_USBD_STATUS_INVALID_DSCR_TYPE if descriptor type not supported.
◆ Cy_USBD_GetDeviceSpeed()
cy_en_usb_speed_t Cy_USBD_GetDeviceSpeed	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
This API returns device's operating speed.

Parameters
pUsbdCtxt	USBD layer context pointer.
Returns
CY_USBD_USB_DEV_NOT_CONNECTED if device is not connected. cy_en_usb_speed_t speed of device.
◆ Cy_USBD_GetDeviceSpeedStr()
const char * Cy_USBD_GetDeviceSpeedStr	(	const cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
This API returns the device's operating speed as a human-readable string.

Parameters
pUsbdCtxt	USBD layer context pointer.
Returns
"Unknown Speed" if device speed is out of range or context is NULL. String representing the device speed otherwise.
◆ Cy_USBD_SetDeviceSpeed()
void Cy_USBD_SetDeviceSpeed	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_en_usb_speed_t 	speed 
)		
This API force operating speed of dvice.

Parameters
pUsbdCtxt	USBD layer context pointer.
speed	speed of device.
◆ Cy_USBD_SetDeviceSpeedAtUSBDOnly()
void Cy_USBD_SetDeviceSpeedAtUSBDOnly	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_en_usb_speed_t 	speed 
)		
This API is used to set device speed only at USBD layer.

This API should be used when application wants to fetch different speed dependent data even before enumaration is done. During enumeration speed field will be overwritten at USBD layer. It is application's responsibility to pass right speed.

Parameters
pUsbdCtxt	USBD layer context pointer.
speed	speed of device.
◆ Cy_USBD_GetDeviceState()
cy_en_usb_device_state_t Cy_USBD_GetDeviceState	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
This API returns present state of device.

Parameters
pUsbdCtxt	USBD layer context pointer.
Returns
CY_USB_DEVICE_STATE_INVALID if usbd context NULL. cy_en_usb_device_state_t present state of device.
◆ Cy_USBD_FindEndp0MaxPktSize()
cy_en_usbd_ret_code_t Cy_USBD_FindEndp0MaxPktSize	(	uint8_t * 	pDevDscr,
cy_en_usb_speed_t 	devSpeed,
uint32_t * 	pMaxPktSize 
)		
This API finds endpoint 0 max packet size from device descriptor.

device descriptors are different at different speed.

Parameters
pDevDscr	Pointer to device descriptor.
devSpeed	Speed of device for which endpoint 0 size is required.
pMaxPktSize	Max packet size of endpoint 0 will be stored here.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_BAD_PARAM in all other case. cy_en_usb_device_state_t present state of device.
◆ Cy_USBD_GetLpmBosUSBExt()
cy_en_usbd_ret_code_t Cy_USBD_GetLpmBosUSBExt	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint8_t * 	pLpmSupp 
)		
Get information about LPM support from USB ext descriptor.

Parameters
pUsbdCtxt	USBD layer context pointer.
pLpmSupp	Information about LPM support is stored here.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_PTR_NULL if BOS descriptor is not register OR pAttribute is NULL. CY_USBD_STATUS_FAILURE in all other cases.
◆ Cy_USBD_GetAttributeBosUSBExt()
cy_en_usbd_ret_code_t Cy_USBD_GetAttributeBosUSBExt	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint32_t * 	pAttribute 
)		
Get attribute from USB ext descriptor.

Parameters
pUsbdCtxt	USBD layer context pointer.
pAttribute	Required information related to attribute will be stored here.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_PTR_NULL if BOS descriptor is not register OR pAttribute is NULL. CY_USBD_STATUS_FAILURE in all other cases.
◆ Cy_USBD_GetAttributeBosSS()
cy_en_usbd_ret_code_t Cy_USBD_GetAttributeBosSS	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint8_t * 	pAttribute 
)		
Get attribute from Super speed BoS descriptor.

Parameters
pUsbdCtxt	USBD layer context pointer.
pAttribute	Attribute field from BOS descriptor will be stored here.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_PTR_NULL if BOS descriptor is not registered OR pAttribute is NULL. CY_USBD_STATUS_FAILURE in all other cases.
◆ Cy_USBD_GetSpeedSuppBosSS()
cy_en_usbd_ret_code_t Cy_USBD_GetSpeedSuppBosSS	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint32_t * 	pSpeedSupp 
)		
Get Speed supported from Super speed descriptor.

Parameters
pUsbdCtxt	USBD layer context pointer.
pSpeedSupp	speed information is stored here.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_PTR_NULL if BOS descriptor is not registered OR pAttribute is NULL. CY_USBD_STATUS_FAILURE in all other cases.
◆ Cy_USBD_GetU1U2ExitLatBosSS()
cy_en_usbd_ret_code_t Cy_USBD_GetU1U2ExitLatBosSS	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint8_t * 	pU1ExitLat,
uint16_t * 	pU2ExitLat 
)		
Get U1 and U2 exit latency from Super speed BoS descriptor.

Parameters
pUsbdCtxt	USBD layer context pointer.
pU1ExitLat	U1 exit latency will be stored here.
pU2ExitLat	U2 exit latency will be stored here.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_PTR_NULL if BOS descriptor is not registered OR pAttribute is NULL. CY_USBD_STATUS_FAILURE in all other cases.
◆ Cy_USBD_GetAttributeBosSSP()
cy_en_usbd_ret_code_t Cy_USBD_GetAttributeBosSSP	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint32_t * 	pAttribute 
)		
Get attribute from Super speed plus descriptor.

Parameters
pUsbdCtxt	USBD layer context pointer.
pAttribute	attribute will be store here.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_PTR_NULL if BOS descriptor is not registered. CY_USBD_STATUS_FAILURE in all other cases.
◆ Cy_USBD_GetFunctSupportBosSSP()
cy_en_usbd_ret_code_t Cy_USBD_GetFunctSupportBosSSP	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint32_t * 	pFuncSupp 
)		
Get functionality supported from Super speed plus descriptor.

Parameters
pUsbdCtxt	USBD layer context pointer.
pFuncSupp	Information about functionality supported is stored here.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_PTR_NULL if BOS descriptor is not registered. CY_USBD_STATUS_FAILURE in all other cases.
◆ Cy_USBD_isCfgValid()
bool Cy_USBD_isCfgValid	(	uint8_t 	cfgNum,
const uint8_t * 	pCfgDscr 
)		
This function checks validity of given configuration.

Parameters
cfgNum	Configuration Number.
pCfgDscr	pointer to configuration descriptor.
Returns
TRUE if config is valid. FALSE if config is not valid.
◆ Cy_USB_USBD_GetActiveCfgNum()
cy_en_usbd_ret_code_t Cy_USB_USBD_GetActiveCfgNum	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint8_t * 	pCfgNum 
)		
This API called by application to know active configuration number.

Parameters
pUsbdCtxt	USBD layer context pointer.
pCfgNum	config number will be stored here.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL.
◆ Cy_USB_USBD_GetActiveCfgDscr()
uint8_t * Cy_USB_USBD_GetActiveCfgDscr	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
This API called by application to get active configuration descriptor.

Parameters
pUsbdCtxt	USBD layer context pointer.
Returns
Pointer to active configuration descriptor.
◆ Cy_USBD_FindNumOfIntf()
uint8_t Cy_USBD_FindNumOfIntf	(	const uint8_t * 	pCfgDscr	)	
This function finds number of interface supported in given configation.

Parameters
pCfgDscr	pointer to configuration descriptor.
Returns
0x00 if Configuration descriptor is NULL. Number of interface supported by configuration.
◆ Cy_USBD_FindSelfPower()
bool Cy_USBD_FindSelfPower	(	const uint8_t * 	pCfgDscr	)	
This function finds device supports Self power or BUS power.

Parameters
pCfgDscr	pointer to configuration descriptor.
Returns
TRUE if device supports self power. FALSE if device supports only BUS power.
◆ Cy_USBD_FindRemoteWakeupAbility()
bool Cy_USBD_FindRemoteWakeupAbility	(	uint8_t * 	pCfgDscr	)	
This function finds device supports remote wakeup or not.

Parameters
pCfgDscr	pointer to configuration descriptor.
Returns
TRUE if device supports remote wakeup. FALSE if device does not support remote wakeup.
◆ Cy_USBD_GetRemoteWakeupStatus()
bool Cy_USBD_GetRemoteWakeupStatus	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
This function checks L2 remote wakeup status and return information.

Parameters
pUsbdCtxt	USBD layer context pointer.
Returns
TRUE if remote wakeup enabled in HW register. FALSE if remote wakeup disabled in HW register.
◆ Cy_USBD_SignalRemoteWakeup()
void Cy_USBD_SignalRemoteWakeup	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
bool 	startEnd 
)		
This function triggers HW to start/end remotewakeup signaling.

Parameters
pUsbdCtxt	USBD layer context pointer.
startEnd	True to start signaling and false to end signaling.
◆ Cy_USBD_GetIntfDscr()
uint8_t * Cy_USBD_GetIntfDscr	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint8_t 	intfNum,
uint8_t 	altSetting 
)		
This function called by application to get interface descriptor.

Parameters
pUsbdCtxt	USBD layer context pointer.
intfNum	Interface number.
altSetting	Alternate setting number.
Returns
NULL if USBD context pointer is NULL. pointer to Interface descriptor.
◆ Cy_USBD_isIntfValid()
bool Cy_USBD_isIntfValid	(	uint16_t 	intf,
uint8_t * 	pCfgDscr 
)		
This function checks given interface is part of configuration descriptor or not.

Parameters
intf	Interface number.
pCfgDscr	pointer to configuration descriptor.
Returns
TRUE if given interfae number is part of configuration descriptor. FALSEif given interface is not part of configuration descriptor.
◆ Cy_USBD_FindNumOfEndp()
uint8_t Cy_USBD_FindNumOfEndp	(	uint8_t * 	pIntfDscr	)	
This function gives number of Endpoints supported by given interface.

Parameters
pIntfDscr	pointer to interface descriptor.
Returns
0x00 if interface descriptor is NULL. Number of endpoints.
◆ Cy_USBD_GetEndpDscr()
uint8_t * Cy_USBD_GetEndpDscr	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint8_t * 	pIntfDscr 
)		
This function to fetch endpoint descriptor for a given interface descriptor.

Parameters
pUsbdCtxt	USBD layer context pointer.
pIntfDscr	pointer to interface descriptor.
Returns
NULL if any of the parameter is NULL. Pointer to endpoint descriptors.
◆ Cy_USBD_GetSsEndpCompDscr()
uint8_t * Cy_USBD_GetSsEndpCompDscr	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint8_t * 	pEndpDscr 
)		
This function to fetch super speed endpoint companion descriptor.

Parameters
pUsbdCtxt	USBD layer context pointer.
pEndpDscr	pointer to endpoint descriptor.
Returns
NULL if any of the parameter is NULL. Pointer to endpoint companion descriptors.
◆ Cy_USBD_GetSspIsoCompDscr()
uint8_t * Cy_USBD_GetSspIsoCompDscr	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint8_t * 	pCompDscr 
)		
This function to fetch super speed plus Iso endpoint companion descriptor from given companion descriptor.

Parameters
pUsbdCtxt	USBD layer context pointer.
pCompDscr	pointer to endpoint companion descriptor.
Returns
NULL if any of the parameter is NULL. Pointer to Iso endpoint companion descriptors.
◆ Cy_USBD_GetSspIsoEndpCompDscr()
uint8_t * Cy_USBD_GetSspIsoEndpCompDscr	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint8_t * 	pEndpDscr 
)		
This function to fetch super speed plus Iso endpoint companion descriptor from given endpoint descriptor.

Parameters
pUsbdCtxt	USBD layer context pointer.
pEndpDscr	pointer to endpoint descriptor.
Returns
NULL if any of the parameter is NULL. Pointer to super speed plus Iso endpoint companion descriptors.
◆ Cy_USB_USBD_GetActiveAltSetting()
cy_en_usbd_ret_code_t Cy_USB_USBD_GetActiveAltSetting	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint8_t 	intfNum,
uint8_t * 	pAltSetting 
)		
This function called by application to know active altSetting for a given interface.

Parameters
pUsbdCtxt	USBD layer context pointer.
intfNum	interface number.
pAltSetting	required alt setting pointer.
Returns
CY_USBD_STATUS_CTXT_NULL when context is null. CY_USBD_STATUS_FAILURE when active config descriptor is null. CY_USBD_STATUS_SUCCESS whem able to fetch altsetting number.
◆ Cy_USBD_FindAltSetting()
uint8_t Cy_USBD_FindAltSetting	(	uint8_t * 	pIntfDscr	)	
This API gives information about alt setting supported by given interface.

Parameters
pIntfDscr	pointer to interface descriptor.
Returns
number of alt setting supported by an interface.
◆ Cy_USBD_GetNumOfAltSetting()
uint8_t Cy_USBD_GetNumOfAltSetting	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint8_t 	intfNum 
)		
This API gets number of alt setting in an interface from USBD context data structure.

Parameters
pUsbdCtxt	USBD layer context pointer.
intfNum	interface number.
Returns
number of alt setting supported by interface.
◆ Cy_USBD_UpdateNumOfAltSetting()
uint8_t Cy_USBD_UpdateNumOfAltSetting	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint8_t 	intfNum 
)		
This API gets number of alt setting in an interface.

Parameters
pUsbdCtxt	USBD layer context pointer.
intfNum	interface number.
Returns
number of alt setting supported by interface.
◆ Cy_USBD_EndpDscrValid()
bool Cy_USBD_EndpDscrValid	(	uint8_t * 	pEndpDscr	)	
This API confirms given descriptor is endpoint descriptor or not.

Parameters
pEndpDscr	pointer to endpoint descriptor.
Returns
TRUE if given descriptor is endpoint descriptor. FALSE if given descriptor is not endpoint descriptor.
◆ Cy_USBD_GetEndpNumMaxPktDir()
cy_en_usbd_ret_code_t Cy_USBD_GetEndpNumMaxPktDir	(	uint8_t * 	pEndpDscr,
uint32_t * 	pEndpNum,
uint16_t * 	pMaxPktSize,
uint32_t * 	pDir 
)		
This function fetches endpoint number, maxPktSize and direction from endpoint descriptor.

Parameters
pEndpDscr	pointer to endpoint descriptor.
pEndpNum	endpoint number will be stored here.
pMaxPktSize	max packet size of endpoint will be stored here.
pDir	Direction of endpoint will be stored here.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_BAD_PARAM if endpoint descriptor is NULL. CY_USBD_STATUS_PTR_NULL if any of the parameter is NULL.
◆ Cy_USBD_GetEndpMaxPktSize()
cy_en_usbd_ret_code_t Cy_USBD_GetEndpMaxPktSize	(	uint8_t * 	pEndpDscr,
uint16_t * 	pMaxPktSize 
)		
This function fetches maxPktSize from endpoint descriptor.

Parameters
pEndpDscr	pointer to endpoint descriptor.
pMaxPktSize	max packet size of endpoint will be stored here.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_BAD_PARAM if endpoint descriptor is NULL.
◆ Cy_USBD_GetIsoBytesPerIntvl()
cy_en_usbd_ret_code_t Cy_USBD_GetIsoBytesPerIntvl	(	uint8_t * 	pIsoCompDscr,
uint32_t * 	pBytesPerIntvl 
)		
This function fetches max bytes per interval for Iso endpoint from iso companion endpoint descriptor.

Parameters
pIsoCompDscr	pointer to Iso endpoint companion descriptor.
pBytesPerIntvl	Bytes per interval field from the descriptor will be stored here.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_BAD_PARAM if ompanion descriptor is NULL.
◆ Cy_USBD_GetEndpAttribute()
cy_en_usbd_ret_code_t Cy_USBD_GetEndpAttribute	(	uint8_t * 	pEndpDscr,
uint8_t * 	pAttribute 
)		
This function fetches endpoint attribute from endpoint descriptor.

Parameters
pEndpDscr	pointer to endpoint descriptor.
pAttribute	atrribute of endpoint will be stored here.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_BAD_PARAM if endpoint descriptor is NULL.
◆ Cy_USBD_GetEndpType()
cy_en_usbd_ret_code_t Cy_USBD_GetEndpType	(	uint8_t * 	pEndpDscr,
uint32_t * 	pEndpType 
)		
This function fetches endpoint type from endpoint descriptor.

Parameters
pEndpDscr	pointer to endpoint descriptor.
pEndpType	endpoint type is stored here.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_BAD_PARAM if endpoint descriptor is NULL. CY_USBD_STATUS_BAD_PARAM if pointer to endpoint type is NULL.
◆ Cy_USBD_GetEndpInterval()
cy_en_usbd_ret_code_t Cy_USBD_GetEndpInterval	(	uint8_t * 	pEndpDscr,
uint8_t * 	pInterval 
)		
This function fetches bInterval from endpoint descriptor.

Parameters
pEndpDscr	Pointer to endpoint descriptor.
pInterval	Endpoint polling interval is stored here.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_BAD_PARAM if endpoint descriptor is NULL. CY_USBD_STATUS_BAD_PARAM if pointer to interval is NULL.
◆ Cy_USBD_GetEndpCompnMaxburst()
cy_en_usbd_ret_code_t Cy_USBD_GetEndpCompnMaxburst	(	uint8_t * 	pEndpCompnDscr,
uint8_t * 	pMaxBust 
)		
This function fetches bMaxBurst from endpoint companion descriptor.

Parameters
pEndpCompnDscr	pointer to endpoint companion descriptor.
pMaxBust	max burst information will be stored here.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_BAD_PARAM if endpoint companion descriptor is NULL. CY_USBD_STATUS_BAD_PARAM if pMaxBurst is NULL.
◆ Cy_USBD_GetEndpCompnMaxStream()
cy_en_usbd_ret_code_t Cy_USBD_GetEndpCompnMaxStream	(	uint8_t * 	pEndpCompnDscr,
uint8_t * 	pMaxStream 
)		
This function fetches bMaxStream from endpoint companion descriptor.

Parameters
pEndpCompnDscr	pointer to endpoint companion descriptor.
pMaxStream	max stream information will be stored here.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_BAD_PARAM if endpoint companion descriptor is NULL. CY_USBD_STATUS_BAD_PARAM if pMaxStream is NULL.
◆ Cy_USBD_GetEndpCompnAttribute()
cy_en_usbd_ret_code_t Cy_USBD_GetEndpCompnAttribute	(	uint8_t * 	pEndpCompnDscr,
uint8_t * 	pAttribute 
)		
This function fetches attribute from endpoint companion descriptor.

Parameters
pEndpCompnDscr	pointer to endpoint companion descriptor.
pAttribute	attribute information will be stored here.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_BAD_PARAM if endpoint companion descriptor is NULL. CY_USBD_STATUS_BAD_PARAM if pAttribute is NULL.
◆ Cy_USBD_GetEndpCompnBytePerInterval()
cy_en_usbd_ret_code_t Cy_USBD_GetEndpCompnBytePerInterval	(	uint8_t * 	pEndpCompnDscr,
uint16_t * 	pBytePerInterval 
)		
This function fetches bytePerInterval from endpoint companion descriptor.

Parameters
pEndpCompnDscr	pointer to endpoint companion descriptor.
pBytePerInterval	Byte per interval information will be stored here.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_BAD_PARAM if endpoint companion descriptor is NULL. CY_USBD_STATUS_BAD_PARAM if pBytePerInterval is NULL.
◆ Cy_USBD_GetEndpSspIsoCompnBytePerInterval()
cy_en_usbd_ret_code_t Cy_USBD_GetEndpSspIsoCompnBytePerInterval	(	uint8_t * 	pSspIsoEndpCompnDscr,
uint32_t * 	pBytePerInterval 
)		
This function fetches bytePerInterval from endpoint SS Iso companion descriptor.

Parameters
pSspIsoEndpCompnDscr	pointer to super speed Iso endpoint companion descriptor.
pBytePerInterval	Bytes per interval information will be stored here.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_BAD_PARAM if endpoint companion descriptor is NULL. CY_USBD_STATUS_PTR_NULL if pBytePerInterval is NULL.
◆ Cy_USBD_EnableEndp()
cy_en_usbd_ret_code_t Cy_USBD_EnableEndp	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir,
bool 	enable 
)		
This function enable/disable endpoint.

Based on speed, this function will call appropriate HW function to enable/disable endpoint.

Parameters
pUsbdCtxt	USBD layer context pointer.
endpNum	endpoint number.
endpDir	endpoint direction.
enable	true for enabling endpoint and false for disabling endpoint.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_FAILURE in other cases.
◆ Cy_USBD_SetEpBurstMode()
cy_en_usbd_ret_code_t Cy_USBD_SetEpBurstMode	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint32_t 	endpNumber,
cy_en_usb_endp_dir_t 	endpDirection,
bool 	enable 
)		
This function enables/disables the MULT (allow burst across multiple DMA buffers) feature for the specified USB endpoints.

Enabling the feature can improve the data transfer throughput on the respective endpoints. The settings need to be updated in the USB IP as well as at the DMA socket level.

Parameters
pUsbdCtxt	USBD layer context pointer.
endpNumber	endpoint number.
endpDirection	endpoint direction.
enable	true for enabling burst mode and false for disabling burst mode.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_FAILURE in other cases.
◆ Cy_USB_USBD_EndpConfig()
cy_en_usbd_ret_code_t Cy_USB_USBD_EndpConfig	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_endp_config_t 	endpConfig 
)		
This function configures endpoint based on user requirement.

Parameters
pUsbdCtxt	USBD layer context pointer.
endpConfig	configuration parameters passed by user.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_ENDP_CONFIG_INVALID_PARAM if any of the configuration parameter invalid. CY_USBD_STATUS_FAILURE in other cases.
◆ Cy_USB_USBD_EndpSetClearStall()
cy_en_usbd_ret_code_t Cy_USB_USBD_EndpSetClearStall	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir,
bool 	setClear 
)		
This function enable or disable STALL condition for the endpoint.

Parameters
pUsbdCtxt	USBD layer context pointer.
endpNum	endpoint number.
endpDir	endpoint direction.
setClear	true for set and false for clear stall condition.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_FAILURE in other cases.
◆ Cy_USB_USBD_EndpSetClearNakNrdy()
cy_en_usbd_ret_code_t Cy_USB_USBD_EndpSetClearNakNrdy	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir,
bool 	setClear 
)		
This function enable or disable NAK/NRDY condition for the endpoint.

Parameters
pUsbdCtxt	USBD layer context pointer.
endpNum	endpoint number.
endpDir	endpoint direction.
setClear	true for set and false for clear NAK condition.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_FAILURE in other cases.
◆ Cy_USBD_ResetEndp()
void Cy_USBD_ResetEndp	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir,
bool 	preserveSeqNo 
)		
This function resets endpoint related paramters by calling appropriate function at HW level.

This clears sticky bits e.g retry bit, flowcontrol bit.

Parameters
pUsbdCtxt	USBD layer context pointer.
endpNum	endpoint number.
endpDir	endpoint direction.
preserveSeqNo	true to preserve sequence number and false to reset sequence number.
◆ Cy_USBD_FlushEndp()
void Cy_USBD_FlushEndp	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint32_t 	endpNumber,
cy_en_usb_endp_dir_t 	endpDirection 
)		
This function flush endpoint data present in EPM.

Parameters
pUsbdCtxt	USBD layer context pointer.
endpNumber	endpoint number.
endpDirection	endpoint direction.
◆ Cy_USBD_FlushEndpAll()
void Cy_USBD_FlushEndpAll	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_en_usb_endp_dir_t 	endpDir 
)		
This function flush all endpoints data endpoint data present in EPM.

Parameters
pUsbdCtxt	USBD layer context pointer.
endpDir	Parameter is unused. Both IN and OUT endpoints will be flushed.
◆ Cy_USBD_FlushResetEndpAll()
void Cy_USBD_FlushResetEndpAll	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_en_usb_endp_dir_t 	endpDirection 
)		
This function flush/reset all endpoint with perticular direction based on speed of device controller.

Parameters
pUsbdCtxt	USBD layer context pointer.
endpDirection	endpoint direction.
◆ Cy_USB_USBD_EndpSetClearNakNrdyAll()
cy_en_usbd_ret_code_t Cy_USB_USBD_EndpSetClearNakNrdyAll	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
bool 	setClear 
)		
This function enable or disable NAK/NRDY condition on all endpoints based on speed of device.

Parameters
pUsbdCtxt	USBD layer context pointer.
setClear	set ie true to enable NAK/NRDY and clear ie false to disable NAK/NRDY.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_FAILURE in other cases.
◆ Cy_USBD_EndpIsNakNrdySet()
bool Cy_USBD_EndpIsNakNrdySet	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir 
)		
This function checks whether the specified endpoint currently has the NAK/NRDY bit set.

Parameters
pUsbdCtxt	USBD layer context pointer.
endpNum	endpoint number.
endpDir	endpoint direction.
Returns
TRUE if NAK/NRDY bit is set FALSE if NAK/NRDY bit is reset
◆ Cy_USBD_EndpIsStallSet()
bool Cy_USBD_EndpIsStallSet	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDirection 
)		
This function checks whether the specified endpoint currently has the STALL bit set.

Parameters
pUsbdCtxt	USBD layer context pointer.
endpNum	endpoint number.
endpDirection	endpoint direction.
Returns
TRUE if STALL bit is set FALSE if STALL bit is reset
◆ Cy_USBD_EndpMapStream()
cy_en_usbd_ret_code_t Cy_USBD_EndpMapStream	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint32_t 	endpNumber,
cy_en_usb_endp_dir_t 	endpDirection,
uint16_t 	streamId,
uint32_t 	socketNum 
)		
This function maps an unused USB Ingress/Egress socket to the specified stream associated with a bulk endpoint.

Parameters
pUsbdCtxt	USBD layer context pointer.
endpNumber	endpoint number.
endpDirection	endpoint direction.
streamId	stream number.
socketNum	socket number to be mapped.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_FAILURE if function is called for FS/HS device. CY_USBD_STATUS_BAD_PARAM if HW call fails due to any parameter.
◆ Cy_USBD_EndpUnmapStream()
cy_en_usbd_ret_code_t Cy_USBD_EndpUnmapStream	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir,
uint32_t 	socketNum 
)		
This function unmaps the USB ingress/egress socket to bulk stream mapping for a bulk endpoint and socket.

Parameters
pUsbdCtxt	USBD layer context pointer.
endpNum	endpoint number.
endpDir	endpoint direction.
socketNum	socket number to be mapped.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_FAILURE if function is called for FS/HS device. CY_USBD_STATUS_BAD_PARAM if HW call fails due to any parameter.
◆ Cy_USBD_EndpSetPktsPerBuffer()
cy_en_usbd_ret_code_t Cy_USBD_EndpSetPktsPerBuffer	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint32_t 	endpNumber,
uint8_t 	pktsPerBuffer 
)		
This function is used to update the USB block with the number of max.

sized packets received on a SuperSpeed OUT endpoint that can fit into one DMA buffer. Setting this value is required for proper operation in cases where the maximum packet size of the endpoint is not a power of 2.

Parameters
pUsbdCtxt	USBD layer context pointer.
endpNumber	endpoint number.
pktsPerBuffer	Number of packets that can fit in one DMA buffer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_FAILURE if function is called for FS/HS device. CY_USBD_STATUS_BAD_PARAM if HW call fails due to any parameter.
◆ Cy_USBD_UpdateXferCount()
void Cy_USBD_UpdateXferCount	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint32_t 	endpNumber,
cy_en_usb_endp_dir_t 	endpDirection,
uint32_t 	bufferSize 
)		
This function will update xfer count based on speed of device.

Parameters
pUsbdCtxt	USBD layer context pointer.
endpNumber	endpoint number.
endpDirection	endpoint direction.
bufferSize	buffer size.
◆ Cy_USBD_CtrlEndp0DataOutAck()
void Cy_USBD_CtrlEndp0DataOutAck	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
bool 	setClear 
)		
Data stage ACK for endpoint0 is controlled by this function.

In USBHS, when "CONT_TO_DATA" bit is set then controller won't send ACK till data is validated.

Parameters
pUsbdCtxt	USBD layer context pointer.
setClear	true for set and false for clear.
◆ Cy_USBD_EnableStatusCtrl()
cy_en_usbd_ret_code_t Cy_USBD_EnableStatusCtrl	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
bool 	enable 
)		
This function enable/disable status control feature which is part of SS controller.

Parameters
pUsbdCtxt	USBD layer context pointer.
enable	true for enable and false for disable.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_FAILURE if function is called for FS/HS device.
◆ Cy_USBD_ClearStatusClrBusy()
cy_en_usbd_ret_code_t Cy_USBD_ClearStatusClrBusy	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
This function write "1" to STATUS_CLR_BUSY which clears the bit to initiate STATUS response.

Parameters
pUsbdCtxt	USBD layer context pointer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_FAILURE if function is called for FS/HS device.
◆ Cy_USBD_SendAckSetupDataStatusStage()
void Cy_USBD_SendAckSetupDataStatusStage	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
Allow chipset to send ACK to complete control transfer.

Parameters
pUsbdCtxt	USBD layer context pointer.
◆ Cy_USB_USBD_SendEndp0Data()
cy_en_usbd_ret_code_t Cy_USB_USBD_SendEndp0Data	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint8_t * 	pBuffer,
uint32_t 	bufferSize 
)		
This function sends data overthe DMA for endpoint 0.

Based on speed of device, SS or HS function will be invoked.

Parameters
pUsbdCtxt	USBD layer context pointer.
pBuffer	pointer to buffer where data is available.
bufferSize	Buffer Size.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_FAILURE if operation is unsuccessful.
◆ Cy_USB_USBD_SendEndp0DataSs()
cy_en_usbd_ret_code_t Cy_USB_USBD_SendEndp0DataSs	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint8_t * 	pBuffer,
uint32_t 	bufferSize 
)		
This function sends data overthe DMA for endpoint 0 of SS device.

Parameters
pUsbdCtxt	USBD layer context pointer.
pBuffer	pointer to buffer where data is available.
bufferSize	Buffer Size.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_BAD_PARAM if pBuffer NULL or bufferSize 0x00. CY_USBD_STATUS_FAILURE if operation is unsuccessful.
◆ Cy_USB_USBD_SendEndp0DataHs()
cy_en_usbd_ret_code_t Cy_USB_USBD_SendEndp0DataHs	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint8_t * 	pBuffer,
uint32_t 	bufferSize 
)		
This function sends data overthe DMA for endpoint 0 of HS device.

Parameters
pUsbdCtxt	USBD layer context pointer.
pBuffer	pointer to buffer where data is available.
bufferSize	Buffer Size.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_BAD_PARAM if pBuffer NULL or bufferSize 0x00. CY_USBD_STATUS_FAILURE if operation is unsuccessful.
◆ Cy_USB_USBD_RecvEndp0Data()
cy_en_usbd_ret_code_t Cy_USB_USBD_RecvEndp0Data	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint8_t * 	pBuffer,
uint32_t 	bufferSize 
)		
This function receives data overthe DMA for endpoint 0.

Based on speed of device, SS or HS function will be invoked.

Parameters
pUsbdCtxt	USBD layer context pointer.
pBuffer	pointer to buffer where received data will be stored.
bufferSize	Buffer Size.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_FAILURE if operation is unsuccessful.
◆ Cy_USB_USBD_RecvEndp0DataSs()
cy_en_usbd_ret_code_t Cy_USB_USBD_RecvEndp0DataSs	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint8_t * 	pBuffer,
uint32_t 	bufferSize 
)		
This function to recieve data for endpoint 0 through DMA for SS.

Parameters
pUsbdCtxt	USBD layer context pointer.
pBuffer	pointer to buffer where received data will be stored.
bufferSize	Buffer Size.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_BAD_PARAM if pBuffer NULL or bufferSize 0x00. CY_USBD_STATUS_FAILURE if operation is unsuccessful.
◆ Cy_USB_USBD_RecvEndp0DataHs()
cy_en_usbd_ret_code_t Cy_USB_USBD_RecvEndp0DataHs	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint8_t * 	pBuffer,
uint32_t 	bufferSize 
)		
This function to recieve data for endpoint 0 through DMA for HS.

Parameters
pUsbdCtxt	USBD layer context pointer.
pBuffer	pointer to buffer where received data will be stored.
bufferSize	Buffer Size.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_BAD_PARAM if pBuffer NULL or bufferSize 0x00.
◆ Cy_USBD_IsEp0ReceiveDone()
bool Cy_USBD_IsEp0ReceiveDone	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
This function checks whether a EP0 data receive operation is pending.

Please note that the function will return true to indicate transfer done if there was no pending transfer in the first place.

Parameters
pUsbdCtxt	USBD layer context pointer.
Returns
true if there is no pending EP0 OUT data transfer. false if there is a pending EP0 OUT data transfer.
◆ Cy_USBD_HandleGetDscr()
cy_en_usbd_ret_code_t Cy_USBD_HandleGetDscr	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_setup_req_t 	setupReq,
cy_stc_usb_cal_msg_t * 	pMsg 
)		
This function handles all get descriptor command coming from host.

Parameters
pUsbdCtxt	USBD layer context pointer.
setupReq	setup request which came from host.
pMsg	pointer to message sent by bottom layer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL.
◆ Cy_USBD_HandleGetStatus()
cy_en_usbd_ret_code_t Cy_USBD_HandleGetStatus	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_setup_req_t 	setupReq 
)		
This function handles get status request coming from host.

Parameters
pUsbdCtxt	USBD layer context pointer.
setupReq	setup request which came from host.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL.
◆ Cy_USBD_HandleSetFeature()
cy_en_usbd_ret_code_t Cy_USBD_HandleSetFeature	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_setup_req_t 	setupReq,
cy_stc_usb_cal_msg_t * 	pMsg 
)		
This function handles set-feature request came from host.

Parameters
pUsbdCtxt	USBD layer context pointer.
setupReq	setup request which came from host.
pMsg	pointer to message sent by bottom layer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_FAILURE in all other failure case.
◆ Cy_USBD_HandleClearFeature()
cy_en_usbd_ret_code_t Cy_USBD_HandleClearFeature	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_setup_req_t 	setupReq,
cy_stc_usb_cal_msg_t * 	pMsg 
)		
This function handles clear-feature request came from host.

Parameters
pUsbdCtxt	USBD layer context pointer.
setupReq	setup request which came from host.
pMsg	pointer to message sent by bottom layer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_FAILURE in all other failure case.
◆ Cy_USBD_HandleSetConfiguration()
cy_en_usbd_ret_code_t Cy_USBD_HandleSetConfiguration	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_setup_req_t 	setupReq,
cy_stc_usb_cal_msg_t * 	pMsg 
)		
This function handles set configuration request came from host.

Parameters
pUsbdCtxt	USBD layer context pointer.
setupReq	setup request which came from host.
pMsg	pointer to message sent by bottom layer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_FAILURE in all other failure case.
◆ Cy_USBD_HandleGetConfiguration()
cy_en_usbd_ret_code_t Cy_USBD_HandleGetConfiguration	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_setup_req_t 	setupReq 
)		
This function handles get configuration request came from host.

Parameters
pUsbdCtxt	USBD layer context pointer.
setupReq	setup request which came from host.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_FAILURE in all other failure case.
◆ Cy_USBD_HandleSetInterface()
cy_en_usbd_ret_code_t Cy_USBD_HandleSetInterface	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_setup_req_t 	setupReq,
cy_stc_usb_cal_msg_t * 	pMsg 
)		
This function handles set interface request came from host.

Parameters
pUsbdCtxt	USBD layer context pointer.
setupReq	setup request which came from host.
pMsg	pointer to message sent by bottom layer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_FAILURE in all other failure case.
◆ Cy_USBD_HandleGetInterface()
cy_en_usbd_ret_code_t Cy_USBD_HandleGetInterface	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_setup_req_t 	setupReq 
)		
This function handles get interface request came from host.

Parameters
pUsbdCtxt	USBD layer context pointer.
setupReq	setup request which came from host.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_FAILURE in all other failure case.
◆ Cy_USBD_HandleReset()
cy_en_usbd_ret_code_t Cy_USBD_HandleReset	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_cal_msg_t * 	pMsg 
)		
This function handles bus reset.

Parameters
pUsbdCtxt	USBD layer context pointer.
pMsg	pointer to message sent by bottom layer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_FAILURE in all other failure case.
◆ Cy_USBD_HandleRxFailure()
void Cy_USBD_HandleRxFailure	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
bool 	enable,
uint8_t 	retry_cnt 
)		
Enables USB stack level work-around to attempt Gen2 connection start-up multiple times in case of training failure in Polling.Active or Polling.Config states.

Parameters
pUsbdCtxt	USBD layer context pointer.
enable	Whether work-around is to be enabled.
retry_cnt	Number of connection attempts to be made in case of Gen2 training failure.
◆ Cy_USBD_HandleSsReset()
cy_en_usbd_ret_code_t Cy_USBD_HandleSsReset	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_cal_msg_t * 	pMsg 
)		
This function handles reset in SS mode.

Parameters
pUsbdCtxt	USBD layer context pointer.
pMsg	pointer to message sent by bottom layer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_FAILURE in all other failure case.
◆ Cy_USBD_HandleHsGrant()
cy_en_usbd_ret_code_t Cy_USBD_HandleHsGrant	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_cal_msg_t * 	pMsg 
)		
High speed related switching is handled here.

Parameters
pUsbdCtxt	USBD layer context pointer.
pMsg	pointer to message sent by bottom layer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL.
◆ Cy_USBD_HandleResetDone()
cy_en_usbd_ret_code_t Cy_USBD_HandleResetDone	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_cal_msg_t * 	pMsg 
)		
This function handles reset-done message.

Parameters
pUsbdCtxt	USBD layer context pointer.
pMsg	pointer to message sent by bottom layer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_FAILURE in all other failure case.
◆ Cy_USBD_HandleCtrlXfrSetupStage()
cy_en_usbd_ret_code_t Cy_USBD_HandleCtrlXfrSetupStage	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_cal_msg_t * 	pMsg 
)		
This function handles setup stage of control transfer.

It also prepare for data/ack stage based on request.

Parameters
pUsbdCtxt	USBD layer context pointer.
pMsg	pointer to message sent by bottom layer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_FAILURE in all other failure case.
◆ Cy_USBD_HandleStatusStage()
cy_en_usbd_ret_code_t Cy_USBD_HandleStatusStage	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_cal_msg_t * 	pMsg 
)		
This function handles status stage of control transfer.

Parameters
pUsbdCtxt	USBD layer context pointer.
pMsg	pointer to message sent by bottom layer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_FAILURE in all other failure case.
◆ Cy_USBD_HandleSuspend()
cy_en_usbd_ret_code_t Cy_USBD_HandleSuspend	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_cal_msg_t * 	pMsg 
)		
This function handles suspend functionality.

Parameters
pUsbdCtxt	USBD layer context pointer.
pMsg	pointer to message sent by bottom layer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL.
◆ Cy_USBD_HandleResume()
cy_en_usbd_ret_code_t Cy_USBD_HandleResume	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_cal_msg_t * 	pMsg 
)		
This function handles resume functionality.

Parameters
pUsbdCtxt	USBD layer context pointer.
pMsg	pointer to message sent by bottom layer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL.
◆ Cy_USBD_HandleL1Sleep()
cy_en_usbd_ret_code_t Cy_USBD_HandleL1Sleep	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_cal_msg_t * 	pMsg 
)		
This function handles L1-Sleep functionality.

Parameters
pUsbdCtxt	USBD layer context pointer.
pMsg	pointer to message sent by bottom layer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL.
◆ Cy_USBD_HandleL1Resume()
cy_en_usbd_ret_code_t Cy_USBD_HandleL1Resume	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_cal_msg_t * 	pMsg 
)		
This function handles L1-Resume functionality.

Parameters
pUsbdCtxt	USBD layer context pointer.
pMsg	pointer to message sent by bottom layer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful.
◆ Cy_USBD_HandleZlp()
cy_en_usbd_ret_code_t Cy_USBD_HandleZlp	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_cal_msg_t * 	pMsg 
)		
This function handles Zero-Length-Packet.

This functionality applicable to HS controller.

Parameters
pUsbdCtxt	USBD layer context pointer.
pMsg	pointer to message sent by bottom layer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL.
◆ Cy_USBD_HandleDone()
cy_en_usbd_ret_code_t Cy_USBD_HandleDone	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_cal_msg_t * 	pMsg 
)		
This function handles done interrupt for an endpoint.

Parameters
pUsbdCtxt	USBD layer context pointer.
pMsg	pointer to message sent by bottom layer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL.
◆ Cy_USBD_HandleRateChange()
cy_en_usbd_ret_code_t Cy_USBD_HandleRateChange	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_cal_msg_t * 	pMsg 
)		
This function handles rate change.

This functionality is applicable to USB3 controller only.

Parameters
pUsbdCtxt	USBD layer context pointer.
pMsg	pointer to message sent by bottom layer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL.
◆ Cy_USBD_HandleSlp()
cy_en_usbd_ret_code_t Cy_USBD_HandleSlp	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_cal_msg_t * 	pMsg 
)		
This function handles short length packet functionality.

This functionality is applicable to HS controller only.

Parameters
pUsbdCtxt	USBD layer context pointer.
pMsg	pointer to message sent by bottom layer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL.
◆ Cy_USBD_HandleSsDisconnect()
cy_en_usbd_ret_code_t Cy_USBD_HandleSsDisconnect	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_cal_msg_t * 	pMsg 
)		
This function handles disconnect event/message came from bottom layer.

Applicable to SS controller only.

Parameters
pUsbdCtxt	USBD layer context pointer.
pMsg	pointer to message sent by bottom layer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful.
◆ Cy_USBD_HandleMsg()
cy_en_usbd_ret_code_t Cy_USBD_HandleMsg	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_cal_msg_t * 	pMsg 
)		
This function handles all messages comes from bottom layer.

Parameters
pUsbdCtxt	USBD layer context pointer.
pMsg	pointer to message sent by bottom layer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL.
◆ Cy_USBD_InitUsbDscrPtrs()
void Cy_USBD_InitUsbDscrPtrs	(	cy_stc_usb_set_dscr_ptrs_t * 	pDscr	)	
This function initializes all descriptor pointers to NULL.

Parameters
pDscr	pointer to data structure where all descriptors are stored.
◆ Cy_USBD_ConnectHsDevice()
void Cy_USBD_ConnectHsDevice	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
This functions connects HS device to BUS and make it visible to host.

Parameters
pUsbdCtxt	USBD layer context pointer.
◆ Cy_USBD_ConnectSsDevice()
void Cy_USBD_ConnectSsDevice	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
This functions connects SS device to BUS and make it visible to host.

Parameters
pUsbdCtxt	USBD layer context pointer.
◆ Cy_USBD_ConnectDevice()
void Cy_USBD_ConnectDevice	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_en_usb_speed_t 	usbSpeed 
)		
This functions connects USB device with given speed and make it visible on BUS.

Parameters
pUsbdCtxt	USBD layer context pointer.
usbSpeed	usb device speed which need to be configured in controller HW.
◆ Cy_USBD_ResetUsbdCommonDs()
void Cy_USBD_ResetUsbdCommonDs	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
This functions reset all USBD common data structure.

Parameters
pUsbdCtxt	USBD layer context pointer.
◆ Cy_USBD_DisconnectHsDevice()
void Cy_USBD_DisconnectHsDevice	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
This functions dis-connects HS device from BUS and make it invisible to host.

Parameters
pUsbdCtxt	USBD layer context pointer.
◆ Cy_USBD_DisconnectSsDevice()
void Cy_USBD_DisconnectSsDevice	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
This functions dis-connects SS device from BUS and make it invisible to host.

Parameters
pUsbdCtxt	USBD layer context pointer.
◆ Cy_USBD_DisconnectDevice()
void Cy_USBD_DisconnectDevice	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
Disconnect device from BUS.

This function should be called by module/layer who detects vbus insertion/removal.

Parameters
pUsbdCtxt	USBD layer context pointer.
◆ Cy_USB_USBD_InitEndp0InCpuDmaDscrConfig()
void Cy_USB_USBD_InitEndp0InCpuDmaDscrConfig	(	cy_stc_usbd_dma_descr_conf_t * 	pEndp0InCpuDmaDscrConfig,
bool 	first 
)		
It initializes DMA descriptor for endpoint 0 IN transfer.

Parameters
pEndp0InCpuDmaDscrConfig	dma descriptor configuration.
first	first or other descriptor.
◆ Cy_USB_USBD_InitEndp0OutCpuDmaDscrConfig()
void Cy_USB_USBD_InitEndp0OutCpuDmaDscrConfig	(	cy_stc_usbd_dma_descr_conf_t * 	pEndp0OutdscrConfig,
bool 	first 
)		
It initializes DMA descriptor for EP0-OUT transfers.

Parameters
pEndp0OutdscrConfig	dma descriptor configuration.
first	first or other descriptor.
◆ Cy_USB_USBD_InitCpuDmaChannelCfg()
void Cy_USB_USBD_InitCpuDmaChannelCfg	(	cy_stc_usbd_dma_chn_conf_t * 	pDmaChCfg,
cy_stc_usbd_dma_descr_t * 	pDmaDscr 
)		
It initializes DMA channel config.

Parameters
pDmaChCfg	dma channel configuration.
pDmaDscr	pointer to DMA descriptor.
◆ Cy_USB_USBD_cpuDmaInit()
cy_en_usbd_ret_code_t Cy_USB_USBD_cpuDmaInit	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
It initializes Cpu DMA functionality.

Parameters
pUsbdCtxt	USBD layer context pointer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful.
◆ Cy_USB_USBD_EndpInit()
cy_en_usbd_ret_code_t Cy_USB_USBD_EndpInit	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
This function initializes endpoint 0 and other endpoints for HS and SS controller.

Parameters
pUsbdCtxt	USBD layer context pointer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_FAILURE in all other case.
◆ Cy_USB_USBD_DisableHsDevice()
void Cy_USB_USBD_DisableHsDevice	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
This function disable all HS device interrupt and make device invisible on BUS.

Parameters
pUsbdCtxt	USBD layer context pointer.
◆ Cy_USB_USBD_EnableHsDevice()
void Cy_USB_USBD_EnableHsDevice	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
This function enable HS device and make it visible on BUS.

Parameters
pUsbdCtxt	USBD layer context pointer.
◆ Cy_USBD_CtrlHSEnableOnCompliance()
void Cy_USBD_CtrlHSEnableOnCompliance	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
bool 	hsEnable 
)		
Function used to enable/disable switch to USB-HS (2.0) mode on entry into the USB 3.x Compliance LTSSM state.

This transition is left enabled on start-up and can be enabled through this API when device configurations that do not support USB-HS are being used.

Parameters
pUsbdCtxt	USBD layer context pointer.
hsEnable	Whether transition into USB-HS is enabled.
◆ Cy_USBD_TaskHandler()
void Cy_USBD_TaskHandler	(	void * 	pTaskParam	)	
This function handles msg coming from CAL layer.

Parameters
pTaskParam	void pointer given to task handler.
◆ Cy_USBD_ProcessMsg()
bool Cy_USBD_ProcessMsg	(	void * 	pUsbd,
void * 	pCalMgs 
)		
This function sends msg to USBD thread.

Parameters
pUsbd	void pointer carry USBD context.
pCalMgs	message prepared by CAL layer.
Returns
Whether context switch is required at the end of the ISR which generated the message.
◆ Cy_USBD_SendEgressZLP()
cy_en_usbd_ret_code_t Cy_USBD_SendEgressZLP	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint32_t 	endpNumber 
)		
This function sends ZLP for given endpoint.

Parameters
pUsbdCtxt	USBD layer context pointer.
endpNumber	endpoint number.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_FAILURE if function is called for FS/HS device.
◆ Cy_USBD_ClearZlpSlpIntrEnableMask()
cy_en_usbd_ret_code_t Cy_USBD_ClearZlpSlpIntrEnableMask	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir,
bool 	zlpSlp 
)		
This function clears endpoint interrupt for ingrress and egresss and enables respective mask register.

Parameters
pUsbdCtxt	USBD layer context pointer.
endpNum	endpoint number.
endpDir	endpoint direction.
zlpSlp	true for zlp and false for slp.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_FAILURE if function is called for FS/HS device.
◆ Cy_USB_LpmSetClearNYET()
cy_en_usbd_ret_code_t Cy_USB_LpmSetClearNYET	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
bool 	setClear 
)		
This is a stack internal function used to enable/disable LPM support.

Applications should always use Cy_USBD_LpmEnable and Cy_USBD_LpmDisable for this purpose.

Parameters
pUsbdCtxt	USBD layer context pointer.
setClear	true for set and false for clear.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_FAILURE if status update failed.
◆ Cy_USBD_GetUSBLinkActive()
cy_en_usbd_ret_code_t Cy_USBD_GetUSBLinkActive	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
This function ensures that the USB link is brought into the L0 (USB2) or U0 (USB3) state when the respective low power states.

Parameters
pUsbdCtxt	USBD layer context pointer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_FAILURE if function is called for FS/HS device.
◆ Cy_USBD_LpmDisable()
cy_en_usbd_ret_code_t Cy_USBD_LpmDisable	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
This function disables all further transitions into a USB low power (U1, U2, or L1) state.

Parameters
pUsbdCtxt	USBD layer context pointer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_FAILURE if function is called for FS/HS device.
◆ Cy_USBD_LpmEnable()
cy_en_usbd_ret_code_t Cy_USBD_LpmEnable	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
This function re-enables state based transitions into USB low power (U1, U2 and L1) modes.

Parameters
pUsbdCtxt	USBD layer context pointer.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_FAILURE if function is called for FS/HS device.
◆ Cy_USB_USBD_RetireRecvEndp0DataSs()
void Cy_USB_USBD_RetireRecvEndp0DataSs	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
This function will disable dma channel for SS which was submitted to recieve data.

Parameters
pUsbdCtxt	USBD layer context pointer.
◆ Cy_USB_USBD_RetireRecvEndp0DataHs()
void Cy_USB_USBD_RetireRecvEndp0DataHs	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
This function will disable dma channel for HS which was submitted to recieve data.

Parameters
pUsbdCtxt	Type of notification to be sent.
◆ Cy_USB_USBD_RetireRecvEndp0Data()
cy_en_usbd_ret_code_t Cy_USB_USBD_RetireRecvEndp0Data	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
This function will disable dma channel which was submitted to recieve data.

Common function for HS and SS.

Parameters
pUsbdCtxt	Type of notification to be sent.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL.
◆ Cy_USBD_SendSSDeviceNotification()
cy_en_usbd_ret_code_t Cy_USBD_SendSSDeviceNotification	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_en_usbd_notification_type_t 	type,
uint32_t 	param0,
uint32_t 	param1 
)		
This function sends a Device Notification Transaction Packet to the host controller on a USB 3.2 link.

Parameters
pUsbdCtxt	Type of notification to be sent.
type	type of notification.
param0	24-bits of data to be added in DWORD1 of the TP.
param1	Data to be added in DWORD2 of the TP.
Returns
CY_USBD_STATUS_SUCCESS if operation is successful. CY_USBD_STATUS_CTXT_NULL if usbd context is NULL. CY_USBD_STATUS_FAILURE if function is called for FS/HS device. CY_USBD_STATUS_BAD_PARAM if type is not valid.
◆ Cy_USBD_InitEventLog()
cy_en_usbd_ret_code_t Cy_USBD_InitEventLog	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint32_t * 	pEvtLogBuf,
uint16_t 	evtLogSize 
)		
Enables capture of USB HS/SS driver events and state changes into RAM buffer.

Parameters
pUsbdCtxt	The pointer to the USBD context structure cy_stc_usb_usbd_ctxt_t allocated by the user.
pEvtLogBuf	RAM buffer pointer to log the data into. Can be NULL if logging is to be disabled.
evtLogSize	Size of RAM buffer in 32-bit words.
Returns
The status code of the function execution cy_en_usbd_ret_code_t.
◆ Cy_USBD_AddEvtToLog()
void Cy_USBD_AddEvtToLog	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint32_t 	evtId 
)		
Add USB event/state to the RAM log buffer.

Parameters
pUsbdCtxt	The pointer to the USBSS context structure cy_stc_usb_usbd_ctxt_t.
evtId	Event ID to be logged.
◆ Cy_USBD_GetEvtLogIndex()
uint16_t Cy_USBD_GetEvtLogIndex	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
Returns the current USB driver event log index.

Parameters
pUsbdCtxt	The pointer to the USBSS context structure cy_stc_usb_usbd_ctxt_t.
Returns
Current event log index.
◆ Cy_USBD_TickIncrement()
void Cy_USBD_TickIncrement	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
Increment the timer tick variable used to timestamp the USB event logs.

Should be called from SysTick interrupt handler.

Parameters
pUsbdCtxt	The pointer to the USBSS context structure cy_stc_usb_usbd_ctxt_t.
◆ Cy_USBD_GetTimerTick()
uint32_t Cy_USBD_GetTimerTick	(	void 		)	
Retrieve the current value of the timer tick.

Returns
Current value of timestamp variable.
◆ Cy_USBD_EP0OutDma_IntrHandler()
void Cy_USBD_EP0OutDma_IntrHandler	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
Handler for interrupt associated with EP0-OUT DMA transfer in USB 2.x modes.

Should be called from the ISR registered for DMAC channel 1 which is used for EP0-OUT transfers.

Parameters
pUsbdCtxt	USB stack context pointer.
◆ Cy_USBD_SetDmaClkFreq()
cy_en_usbd_ret_code_t Cy_USBD_SetDmaClkFreq	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_en_hbdma_clk_freq_t 	dmaFreq 
)		
Function which sets the desired DMA clock frequency during USB 3.x operation on the FX3G2 device.

This function should be called before USB connection is enabled. The default clock selected is 240 MHz derived from USB2 PLL.

Parameters
pUsbdCtxt	USB stack context pointer.
dmaFreq	Desired DMA clock frequency.
Returns
Status code
◆ Cy_USBD_DisableLPMDeviceExit()
void Cy_USBD_DisableLPMDeviceExit	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
bool 	devExitDisable 
)		
Function to disable support for device initiated exit from USB 3.x low power modes completely.

Parameters
pUsbdCtxt	USB stack context pointer.
devExitDisable	true to disable device initiated exit from LPM states.
◆ Cy_USBD_DisableSSOnBusReset()
void Cy_USBD_DisableSSOnBusReset	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
Function which disables the USB 3.x reconnection when USB 2.x Bus Reset is received.

This function is only provided for testing of link robustness and not expected to be used in an application.

Parameters
pUsbdCtxt	USB Stack context structure.
◆ Cy_USBD_SelectConfigLane()
cy_en_usbd_ret_code_t Cy_USBD_SelectConfigLane	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_en_usb_config_lane_t 	laneSel 
)		
Function to select the USB 3.x Configuration Lane.

This API can be used in cases where the USB connection orientation is being detected externally instead of through CC1/CC2 voltage measurement by the controller itself.

Parameters
pUsbdCtxt	USB Stack context structure.
laneSel	Desired configuration lane selection.
Returns
Whether the orientation selection has been registered successfully.
◆ Cy_USBD_GetEndpointType()
cy_en_usb_endp_type_t Cy_USBD_GetEndpointType	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint32_t 	endpNumber,
cy_en_usb_endp_dir_t 	endpDirection 
)		
Function to identify the type of endpoint based on its index.

Parameters
pUsbdCtxt	USB Stack context structure.
endpNumber	Endpoint index.
endpDirection	Endpoint direction.
Returns
Type of the endpoint.
◆ Cy_USBD_ResetEndpoints()
void Cy_USBD_ResetEndpoints	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
uint32_t 	outEpMask,
uint32_t 	inEpMask,
uint32_t 	preserveOutSeqNum,
uint32_t 	preserveInSeqNum 
)		
This function resets transient state associated with the specified OUT and IN endpoints.

The endpoints to be reset are specified through bit-mask parameters.

Parameters
pUsbdCtxt	USBD layer context pointer.
outEpMask	Bitmask representing OUT endpoints to be reset.
inEpMask	Bitmask representing IN endpoints to be reset.
preserveOutSeqNum	Bitmask representing OUT endpoints whose sequence numbers are to be preserved.
preserveInSeqNum	Bitmask representing IN endpoints whose sequence numbers are to be preserved.
◆ Cy_USBD_GetDeviceStats()
void Cy_USBD_GetDeviceStats	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usbd_devstats_t * 	pDevStats 
)		
This function retrieves USB connection statistics maintained by the stack and driver layers.

Parameters
pUsbdCtxt	USBD layer context pointer.
pDevStats	Structure through which statistics are returned.
◆ Cy_USBD_ControlUsb2Support()
bool Cy_USBD_ControlUsb2Support	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
bool 	enable 
)		
Enable/Disable USB 2.x device operation on the device.

By default, the FX device is configured to attempt both USB 3.x and 2.x connections to a USB host. The USB driver in the firmware automatically attempts a hi-speed or full speed connection, if the SuperSpeed connection fails to go through link training.

Some designs may use the FX device in USB 3.x mode alone, and require that an external controller be used in USB 2.x mode. This API can be used to modify the driver behavior to suppress the USB 2.x device operation. USB events are provided to notify the user that the 3.x connection has failed, and a 2.x connection needs to be attempted. The Cy_USBD_ConnectDevice() API should be called repeatedly to retry the USB 3.x connection.

Parameters
pUsbdCtxt	USBD layer context pointer.
enable	Whether USB 2.x support is enabled (default is enabled).
◆ Cy_USBD_GetUSBPowerState()
cy_en_usbd_usb_powerstate_t Cy_USBD_GetUSBPowerState	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt	)	
This function returns the current USB power state (U0/U1/U2 for USB3 and L0/SUSPEND for USB2) of the device.

Parameters
pUsbdCtxt	USBD layer context pointer.
Returns
Current USB power state of the device.
◆ Cy_USBD_EnterDeepsleep()
cy_en_usbd_ret_code_t Cy_USBD_EnterDeepsleep	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
DW_Type * 	pCpuDw1Base 
)		
This function prepares and puts the device into deepsleep.

Parameters
pUsbdCtxt	USBD layer context pointer.
Returns
CY_USBD_STATUS_SUCCESS if sleep entry and exit is successful, CY_USBD_STATUS_FAILURE otherwise.
◆ Cy_USBD_SelectHSCtleConfig()
cy_en_usbd_ret_code_t Cy_USBD_SelectHSCtleConfig	(	cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_en_hs_ctle_sel_t 	ctleSel 
)		
Selects the HS CTLE configuration for USB 2.x operation.

Call this API before enabling the USB connection to override the stack default (CY_USBHS_CTLE_SEL_5). Refer to cy_en_hs_ctle_sel_t for available options.

Parameters
pUsbdCtxt	USB Stack context structure.
ctleSel	Desired HS CTLE configuration selection.
Returns
CY_USBD_STATUS_SUCCESS: CTLE configuration selection registered successfully. CY_USBD_STATUS_CTXT_NULL: Invalid NULL pointer parameter. CY_USBD_STATUS_FAILURE: ctleSel out of range or lower-layer error.
◆ Cy_USBHS_Cal_Init()
void Cy_USBHS_Cal_Init	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
void * 	pUsbdCtxt,
cy_usb_cal_msg_callback_t 	callBackFunc 
)		
Initializes the HS controller ie CAL layer and PHY.

It also stores callback function and USBD layer context.

Parameters
pCalCtxt	CAL layer context pointer.
pUsbdCtxt	USBd layer context pointer.
callBackFunc	Callback function provied by Upper layer ie USBD layer.
◆ Cy_USBHS_Cal_FsHsModePhyInit()
void Cy_USBHS_Cal_FsHsModePhyInit	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
Initializes high speed PHY.

Parameters
pCalCtxt	CAL layer context pointer.
◆ Cy_USBHS_Cal_PhyCommonInit()
void Cy_USBHS_Cal_PhyCommonInit	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
Initializes registers common to full and high speed PHY configuration.

Parameters
pCalCtxt	CAL layer context pointer.
◆ Cy_USBHS_Cal_HandleReset()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_HandleReset	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
During reset controller updates.

Parameters
pCalCtxt	CAL layer context pointer.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_ConnUsbPins()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_ConnUsbPins	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
Update USB device controller register to make USB device visible on Bus.

Once device is visible, host will start reset and Enumeration.

Parameters
pCalCtxt	CAL layer context pointer.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_DisconUsbPins()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_DisconUsbPins	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
Update Controller register to make USB device invisible on Bus.

Parameters
pCalCtxt	CAL layer context pointer.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_HsHandleL1Sleep()
void Cy_USBHS_Cal_HsHandleL1Sleep	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
L1-SLEEP request during device in high speed mode will be handled here.

Parameters
pCalCtxt	CAL layer context pointer.
◆ Cy_USBHS_Cal_HsHandleL1WakeupCommon()
void Cy_USBHS_Cal_HsHandleL1WakeupCommon	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
L1-Wakeup request during device in high speed mode will be handled here.

Parameters
pCalCtxt	CAL layer context pointer.
◆ Cy_USBHS_Cal_DevInitiatedL1Exit()
void Cy_USBHS_Cal_DevInitiatedL1Exit	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
uint32_t 	duration 
)		
Function helps device to initiate resume from L1 SleepDevice.

Parameters
pCalCtxt	CAL layer context pointer.
duration	LPM timing parameter as per Specification.
◆ Cy_USBHS_Cal_DevInitiatedResumeL2Sleep()
void Cy_USBHS_Cal_DevInitiatedResumeL2Sleep	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
uint32_t 	duration 
)		
Function helps device to initiate resume from L2 SleepDevice.

Parameters
pCalCtxt	CAL layer context pointer.
duration	LPM timing parameter as per Specification.
◆ Cy_USBHS_Cal_HsHandleL2SuspendEntry()
bool Cy_USBHS_Cal_HsHandleL2SuspendEntry	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
bool 	keepPllOn 
)		
This function Handles Suspend at CAL layer in High speed mode.

Parameters
pCalCtxt	CAL layer context pointer.
keepPllOn	Whether to keep the PLL and references in the PHY ON.
Returns
True if suspend entry was done, false if suspend entry was skipped.
◆ Cy_USBHS_Cal_FsHandleSuspend()
void Cy_USBHS_Cal_FsHandleSuspend	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
This function Handles Suspend at CAL layer in Full speed mode.

Parameters
pCalCtxt	CAL layer context pointer.
◆ Cy_USBHS_Cal_HsHandleL2Resume()
void Cy_USBHS_Cal_HsHandleL2Resume	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
This function Handles resume at CAL layer in high speed mode.

Parameters
pCalCtxt	CAL layer context pointer.
◆ Cy_USBHS_Cal_FsHandleResume()
void Cy_USBHS_Cal_FsHandleResume	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
This function Handles resume at CAL layer in full speed mode.

Parameters
pCalCtxt	CAL layer context pointer.
◆ Cy_USBHS_Cal_IntrHandler()
bool Cy_USBHS_Cal_IntrHandler	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
This function Handles All interrupt related to controller.

Based on interrupt required function will be invoked.

Parameters
pCalCtxt	CAL layer context pointer.
Returns
true if yield is pending when the ISR returns, false otherwise.
◆ Cy_USBHS_Cal_EnableReqDevCtrlIntr()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_EnableReqDevCtrlIntr	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
This function will enable required interrupt under device ctrl reister.

Parameters
pCalCtxt	CAL layer context pointer.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_DisableAllDevCtrlIntr()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_DisableAllDevCtrlIntr	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
This function will disable all possible interrupt generated by USB device.

Parameters
pCalCtxt	CAL layer context pointer.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_ClearAllDevCtrlIntr()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_ClearAllDevCtrlIntr	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
This function will clear all interrupt bit in device ctrl register.

Parameters
pCalCtxt	CAL layer context pointer.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_UpdateEpIntrMask()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_UpdateEpIntrMask	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNumber,
cy_en_usb_endp_dir_t 	endpDirection,
uint32_t 	epIntrMask,
bool 	setClear 
)		
This function updates the interrupt mask for an endpoint with the desired values.

Parameters
pCalCtxt	CAL layer context pointer.
endpNumber	Endpoint number.
endpDirection	Endpoint direction.
epIntrMask	Endpoint interrupt mask.
setClear	Interrupt Mask bits to be set or cleared.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_ClearZlpSlpIntrEnableMask()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_ClearZlpSlpIntrEnableMask	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir,
bool 	zlpSlp 
)		
This function clears endpoint interrupt for ingress and egress intrrupt and enables respective mask register.

Writing 1 in intr register will clear the interrupt. writting 1 in mask register will enable that register.

Parameters
pCalCtxt	CAL layer context pointer.
endpNum	Endpoint number.
endpDir	Endpoint direction.
zlpSlp	1 for ZLP and 0 for SLP.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_EnableCtrlSlpIntr()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_EnableCtrlSlpIntr	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
This function enables the SLP_RCVD interrupt for EP0-OUT.

Parameters
pCalCtxt	CAL layer context pointer.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_DisableCtrlSlpIntr()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_DisableCtrlSlpIntr	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
This function disable the SLP_RCVD interrupt for EP0-OUT.

Parameters
pCalCtxt	CAL layer context pointer.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_EnableEndp()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_EnableEndp	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir,
bool 	enable 
)		
This function enables/disable endpoint and set/reset respective interrupt.

Parameters
pCalCtxt	CAL layer context pointer.
endpNum	Endpoint number.
endpDir	Endpoint direction.
enable	1 for enable and 0 for disable.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_BAD_PARAM if direction and endpoint number invalid. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_EndpConfig()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_EndpConfig	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
cy_stc_usb_endp_config_t 	configParam 
)		
This function handles configuration of endpoint.

Parameters
pCalCtxt	CAL layer context pointer.
configParam	Contains all config parameters.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_BAD_PARAM if direction and endpoint number invalid. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_UpdateXferCount()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_UpdateXferCount	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir,
uint32_t 	xferCount 
)		
This function updates register with transfer count.

Parameters
pCalCtxt	CAL layer context pointer.
endpNum	Endpoint number.
endpDir	Endpoint direction.
xferCount	transfer count.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_BAD_PARAM if direction and endpoint number invalid. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_EndpSetClearNak()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_EndpSetClearNak	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir,
bool 	setClear 
)		
This function enable or disable NAK condition in hw.

By setting NAK bit, endpoint will keep sending NAK till NAK bit is cleared.

Parameters
pCalCtxt	CAL layer context pointer.
endpNum	Endpoint number.
endpDir	Endpoint direction.
setClear	1 for set and 0 for clear.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_BAD_PARAM if direction and endpoint number invalid. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_SetClearNakAll()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_SetClearNakAll	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
bool 	setClear 
)		
This function either set or clear NAK for all endpoint.

Parameters
pCalCtxt	CAL layer context pointer.
setClear	1 for set and 0 for clear.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_EndpIsNakNrdySet()
bool Cy_USBHS_Cal_EndpIsNakNrdySet	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNumber,
cy_en_usb_endp_dir_t 	endpDirection 
)		
This function checks endpoint's status related to NAK bit is set or reset.

Parameters
pCalCtxt	CAL layer context pointer.
endpNumber	Endpoint number.
endpDirection	Endpoint direction.
Returns
1 if NAK bit is set. 0 if NAK bit is reset.
◆ Cy_USBHS_Cal_EndpSetClearStall()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_EndpSetClearStall	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir,
bool 	setClear 
)		
This function enable or disable STALL condition in hw.

Parameters
pCalCtxt	CAL layer context pointer.
endpNum	Endpoint number.
endpDir	Endpoint direction.
setClear	1 for set and 0 for clear.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_BAD_PARAM if direction and endpoint number invalid. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_EndpIsStallSet()
bool Cy_USBHS_Cal_EndpIsStallSet	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir 
)		
This function checks whether the specified endpoint is currently in the STALLed state.

Parameters
pCalCtxt	CAL layer context pointer.
endpNum	Endpoint number.
endpDir	Endpoint direction.
Returns
1 if NAK bit is set. 0 if NAK bit is reset.
◆ Cy_USBHS_Cal_FlushEndp()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_FlushEndp	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir 
)		
This function will flush data available in perticular endpoint FIFO.

High speed USB IP supports flush functionality only for IN endpoint.

Parameters
pCalCtxt	CAL layer context pointer.
endpNum	Endpoint number.
endpDir	Endpoint direction.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_BAD_PARAM if direction and endpoint number invalid. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_FlushAllEndp()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_FlushAllEndp	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
bool 	ingressFlush,
bool 	egressFlush 
)		
This function will flush data available in all Ingress and egress endpoint FIFO.

Parameters
pCalCtxt	CAL layer context pointer.
ingressFlush	Whether Ingress (OUT) endpoints are to be flushed.
egressFlush	Whether Egress (IN) endpoints are to be flushed.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_SendEgressZLP()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_SendEgressZLP	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNum 
)		
This function triggers sending of a ZLP on an Egress endpoint.

Parameters
pCalCtxt	CAL layer context pointer.
endpNum	Endpoint number.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_BAD_PARAM if direction and endpoint number invalid. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_HandleCtrlOutSlp()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_HandleCtrlOutSlp	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
This function clears SLP ingress interrupt.

Parameters
pCalCtxt	CAL layer context pointer.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_CtrlEndp0DataOutAck()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_CtrlEndp0DataOutAck	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
bool 	setClear 
)		
Data stage ACK for endpoint0 is controlled by this function.

In USBHS, when "CONT_TO_DATA" bit is set then controller wont send ACK till data is validated.

Parameters
pCalCtxt	CAL layer context pointer.
setClear	1 for set and 0 for clear.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_SendAckSetupDataStatusStage()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_SendAckSetupDataStatusStage	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
This function update register so that device will send ACK to complete control transfer.

Parameters
pCalCtxt	CAL layer context pointer.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_GetRemoteWakeupStatus()
bool Cy_USBHS_Cal_GetRemoteWakeupStatus	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
This function returns status of L2 remote wakeup in HW.

Parameters
pCalCtxt	CAL layer context pointer.
Returns
true if L2 remote wakeup is enabled. false if L2 remote wakeup is disabled.
◆ Cy_USBHS_Cal_GetL1RemoteWakeupStatus()
bool Cy_USBHS_Cal_GetL1RemoteWakeupStatus	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
This function returns status of L1 remote wakeup in HW.

Parameters
pCalCtxt	CAL layer context pointer.
Returns
true if L1 remote wakeup is enabled. false if L1 remote wakeup is disabled.
◆ Cy_USBHS_Cal_SignalRemotWakup()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_SignalRemotWakup	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
bool 	startEndSignal 
)		
This function will update register so that device will initiate remote wakeup signaling ie it will try to comeout from L2_SUSPEND.

Parameters
pCalCtxt	CAL layer context pointer.
startEndSignal	Input to tell either start or end signaling.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_SetTestMode()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_SetTestMode	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
cy_en_usbhs_cal_test_mode_t 	testMode 
)		
This function will update register to setup required test mode.

Parameters
pCalCtxt	CAL layer context pointer.
testMode	perticular test mode.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_LpmSetClearNYET()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_LpmSetClearNYET	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
bool 	setClear 
)		
This function either set or clear NYET bit for LPM response.

Parameters
pCalCtxt	CAL layer context pointer.
setClear	1 for set and 0 for clear.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_SetControllerSpeed()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_SetControllerSpeed	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
cy_en_usb_speed_t 	speed 
)		
This function set controller speed to FS or HS.

If explicitly FS is not mentioned then function will set speed to HS.

Parameters
pCalCtxt	CAL layer context pointer.
speed	iether HS or FS.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_GetDevAddress()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_GetDevAddress	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
uint8_t * 	pDevAddr 
)		
This function will get device address assigned by Host.

Parameters
pCalCtxt	CAL layer context pointer.
pDevAddr	Address of device will be stored here.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_BAD_PARAM if direction and endpoint number invalid. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_GetLinkActive()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_GetLinkActive	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
This function makes sure that the USB 2.x link gets into the L0 state if it is in L1.

Parameters
pCalCtxt	CAL layer context pointer.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_SendMsg()
bool Cy_USBHS_Cal_SendMsg	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
void * 	pMsg 
)		
This function send message to upper layer ie USBD layer.

Parameters
pCalCtxt	CAL layer context pointer.
pMsg	message will be given to upper layer.
Returns
Whether context switch is required at the end of the callback.
◆ Cy_USBHS_Cal_DeinitPLL()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_DeinitPLL	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
Function to de-initialize the PLL in the USBHS block.

Parameters
pCalCtxt	CAL layer context pointer.
Returns
CY_USB_CAL_STATUS_SUCCESS in case of success; error code otherwise.
◆ Cy_USBHS_Cal_InitPLL()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_InitPLL	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
Function to initialize the PLL in the USBHS block to generate the 480 MHz clock required by the High BandWidth SubSystem for its operation.

Parameters
pCalCtxt	CAL layer context pointer.
Returns
CY_USB_CAL_STATUS_SUCCESS in case of success; error code otherwise.
◆ Cy_USBHS_Cal_IsLinkActive()
bool Cy_USBHS_Cal_IsLinkActive	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
Check whether the USB 2.x link is in active (L0) state.

Parameters
pCalCtxt	CAL layer context pointer.
Returns
true if link is in L0, false if link is in L1 or L2.
◆ Cy_USBHS_Cal_GetXferCount()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_GetXferCount	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir,
uint32_t * 	pCntPending 
)		
Retrieve the remaining transfer count on the specified endpoint.

Parameters
pCalCtxt	CAL layer context pointer.
endpNum	Endpoint number.
endpDir	Endpoint direction.
pCntPending	Return parameter through which pending count is returned.
Returns
CY_USB_CAL_STATUS_SUCCESS if the operation is successful. CY_USB_CAL_STATUS_BAD_PARAM if direction and endpoint number invalid. CY_USB_CAL_STATUS_CAL_BASE_NULL if register base pointer is NULL.
◆ Cy_USBHS_Cal_IsNewCtrlRqtReceived()
bool Cy_USBHS_Cal_IsNewCtrlRqtReceived	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt	)	
This function uses the SETUP_CLR_BUSY to check whether a new control request has been received while a previous send/recv data call is pending.

Parameters
pCalCtxt	CAL layer context pointer.
Returns
true if a new request has been received, false otherwise.
◆ Cy_USBHS_Cal_PreemphasisControl()
void Cy_USBHS_Cal_PreemphasisControl	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
bool 	enable 
)		
Function to enable/disable Pre-emphasis based on the active USB test mode.

Parameters
pCalCtxt	CAL layer context pointer.
enable	Whether pre-emphasis is to be enabled or disabled.
◆ Cy_USBHS_Cal_SOFIntrUpdate()
void Cy_USBHS_Cal_SOFIntrUpdate	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
bool 	sofIntrEnable 
)		
Function to enable or disable the SOF interrupt based on user requirement.

Parameters
pCalCtxt	CAL layer library context pointer.
sofIntrEnable	Whether the SOF interrupt should be enabled.
◆ Cy_USBHS_Cal_SetCtleSelValue()
cy_en_usb_cal_ret_code_t Cy_USBHS_Cal_SetCtleSelValue	(	cy_stc_usb_cal_ctxt_t * 	pCalCtxt,
cy_en_hs_ctle_sel_t 	ctleSel 
)		
Sets the HS_CTLE_SEL field in the AFE_CONTROL_1 register of the USBHS PHY.

Parameters
pCalCtxt	CAL layer context pointer.
ctleSel	CTLE level selection (CY_USBHS_CTLE_SEL_0 .. CY_USBHS_CTLE_SEL_7).
Returns
CY_USB_CAL_STATUS_SUCCESS if successful. CY_USB_CAL_STATUS_CAL_CTXT_NULL if pCalCtxt or pCalCtxt->pPhyBase is NULL.
◆ Cy_USBSS_Cal_Init()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_Init	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
void * 	pUsbdCtxt,
cy_usb_cal_msg_callback_t 	cb 
)		
Initializes the USBSS IP and relevant variables.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
pUsbdCtxt	The pointer to the USBD context structure.
cb	Callback function registered by the user cy_usb_cal_msg_callback_t.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_Connect()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_Connect	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
cy_en_usb_speed_t 	usbSpeed 
)		
Enables the USB3 RX terminations for connecting to the host and enables relevant USB LINK and PROTOCOL interrupts.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
usbSpeed	The desired speed at which the device needs to be connected to the host cy_en_usb_speed_t.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_SendMsg()
bool Cy_USBSS_Cal_SendMsg	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
void * 	pMsg 
)		
Sends message to the USBD layer using a callback registered by the user.

This function should call only ISR safe routine.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
pMsg	Message structure pointer.
Returns
Whether context switch is required at the end of the ISR.
◆ Cy_USBSS_Cal_IntrHandler()
void Cy_USBSS_Cal_IntrHandler	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt	)	
Interrupt Handler function for USB3 IP.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
◆ Cy_USBSS_Cal_WakeupIntrHandler()
void Cy_USBSS_Cal_WakeupIntrHandler	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt	)	
Wakeup Interrupt Handler function for USB3 IP.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
◆ Cy_USBSS_Cal_Get_PtmStatus()
uint32_t Cy_USBSS_Cal_Get_PtmStatus	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt	)	
Sends the PTM STATUS to the USBD layer to repsond to GET_STATUS request.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
Returns
uint32_t The PTM status .
◆ Cy_USBSS_Cal_LPMEnable()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_LPMEnable	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
bool 	isResume 
)		
Enables the USB3 Link layer Low Power Mode Handling.

The LINK layer can accept going into U1/U2 upon receiving LGO_U1/LGO_U2.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
isResume	Whether delayed LPM entry is being resumed.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_ForceLPMAccept()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_ForceLPMAccept	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
bool 	enable 
)		
Enables the USB3 Link layer to always accept LPM requests going into U1/U2 upon receiving LGO_U1/LGO_U2.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
enable	If true, the device accept LPM requests always. If false, the device may accept or reject LPM requests.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_LPMDisable()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_LPMDisable	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt	)	
Enables the USB3 Link layer to disable accepting LPM requests going into U1/U2 upon receiving LGO_U1/LGO_U2.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_SetLinkPowerState()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_SetLinkPowerState	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
cy_en_usbss_lnk_power_mode_t 	lnkMode 
)		
Forces the USB3 Link layer to a particular Link Power State by sending LGO_Ux requests.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
lnkMode	Link Mode that needs to be set from cy_en_usbss_lnk_power_mode_t
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_GetUsbLinkActive()
void Cy_USBSS_Cal_GetUsbLinkActive	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt	)	
Get the USB3 Link layer to U0 State if it is in U1/U2 state.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
◆ Cy_USBSS_Cal_GetLinkPowerState()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_GetLinkPowerState	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
cy_en_usbss_lnk_power_mode_t * 	pMode 
)		
Retrieves the Link Power State of the device.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
*pMode	Pointer to a memory where the link power state will be stored from cy_en_usbss_lnk_power_mode_t
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_ProtSendTp()
void Cy_USBSS_Cal_ProtSendTp	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint32_t * 	pTpData 
)		
This function will send transaction packet.

It is responsibility of caller to prepare transaction packet and call this function.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
*pTpData	Pointer to a memory where transaction packet stored.
◆ Cy_USBSS_Cal_ProtSendAckTp()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_ProtSendAckTp	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir,
uint8_t 	numP,
uint16_t 	bulkStream 
)		
This function prepares and send ACK transaction packet.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
endpNum	Endpoint number.
endpDir	Endpoint direction.
numP	Number of Data packet buffer receiever can accept.
bulkStream	stream ID incase of bulk transfer
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_ProtSendErdyTp()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_ProtSendErdyTp	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir,
uint8_t 	numP,
uint16_t 	bulkStream 
)		
This function prepares and send ERDY transaction packet.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
endpNum	Endpoint number.
endpDir	Endpoint direction.
numP	Number of Data packet buffer receiever can accept.
bulkStream	stream ID incase of bulk transfer
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_ProtSendNrdyTp()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_ProtSendNrdyTp	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir,
uint16_t 	bulkStream 
)		
This function prepares and send NRDY transaction packet.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
endpNum	Endpoint number.
endpDir	Endpoint direction.
bulkStream	stream ID incase of bulk transfer
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_EndpReset()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_EndpReset	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir 
)		
Function to reset an endpoint.

This clears sticky bits e.g retry bit, flowcontrol bit.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
endpNum	Endpoint number.
endpDir	Endpoint direction.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_GetSeqNum()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_GetSeqNum	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir,
uint8_t * 	pSeqNum 
)		
This function gets the current value of sequence number for an endpoint.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
endpNum	Endpoint number.
endpDir	Endpoint direction.
pSeqNum	Current value of sequence number will be store here.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_SetSeqNum()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_SetSeqNum	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir,
uint8_t 	seqNum 
)		
This function sets value of sequence number in hardware for an endpoint.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
endpNum	Endpoint number.
endpDir	Endpoint direction.
seqNum	Sequence number need to be written in HW register.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_GetDevAddress()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_GetDevAddress	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint8_t * 	pDevAddr 
)		
This function will get device address assigned by Host.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
pDevAddr	device address will be stored here.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_EndpSetClearStall()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_EndpSetClearStall	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir,
bool 	setClear 
)		
This function enable or disable NRDY condition in hw.

By setting NRDY bit, endpoint will keep sending NRDY till NRDY bit is cleared.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
endpNum	Endpoint number.
endpDir	Endpoint direction.
setClear	true for set and false for clear.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_EndpSetClearNrdy()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_EndpSetClearNrdy	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir,
bool 	setClear 
)		
This function enable or disable NRDY condition in hw.

By setting NRDY bit, endpoint will keep sending NRDY till NRDY bit is cleared.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
endpNum	Endpoint number.
endpDir	Endpoint direction.
setClear	true for set and false for clear.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_SetClearNrdyAll()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_SetClearNrdyAll	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
bool 	setClear 
)		
This function enable or disable NRDY condition for all endpopint.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
setClear	true for set and false for clear.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_EndpConfig()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_EndpConfig	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
cy_stc_usb_endp_config_t 	configParam 
)		
This function handles configuration of endpoint.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
configParam	Configuration Parameters stored here cy_stc_usb_endp_config_t.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_EndpSetPktsPerBuffer()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_EndpSetPktsPerBuffer	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNumber,
uint8_t 	pktsPerBuffer 
)		
This function sets the number of maximum sized packets that can fit into a single DMA buffer for an Ingress endpoint.

This needs to be called in cases where the maximum packet size is not a power of 2, so that the EPM can operate correctly.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
endpNumber	Endpoint number.
pktsPerBuffer	packats per buffer.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_EndpMapStream()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_EndpMapStream	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNumber,
cy_en_usb_endp_dir_t 	endpDirection,
uint16_t 	streamId,
uint32_t 	socketNum 
)		
This function maps an unused USB Ingress/Egress socket to the specified stream associated with a bulk endpoint.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
endpNumber	Endpoint number.
endpDirection	Endpoint direction.
streamId	stream ID.
socketNum	Socket Number.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_EndpUnmapStream()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_EndpUnmapStream	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir,
uint32_t 	socketNum 
)		
This function unmaps the DMA socket to stream mapping for a bulk endpoint.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
endpNum	Endpoint number.
endpDir	Endpoint direction.
socketNum	Socket Number.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_EnableEndp()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_EnableEndp	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNumber,
cy_en_usb_endp_dir_t 	endpDirection,
bool 	enable 
)		
This function enables/disable endpoint and set/reset respective interrupt.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
endpNumber	Endpoint number.
endpDirection	Endpoint direction.
enable	true for enable and false for disable.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_SetEpBurstMode()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_SetEpBurstMode	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNumber,
cy_en_usb_endp_dir_t 	endpDirection,
bool 	enable 
)		
This function enables/disables the MULT (allow burst across multiple DMA buffers) feature for the specified USB endpoints.

Enabling the feature can improve the data transfer throughput on the respective endpoints.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
endpNumber	Endpoint number.
endpDirection	Endpoint direction.
enable	true for enable burst mode and false for disable burst mode.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_SetEndpRetryOffset()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_SetEndpRetryOffset	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNumber,
uint16_t 	retryBufOffset 
)		
This function sets the egress endpoint retry buffer offset for Type-2 (CTRL and BULK) endpoints.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
endpNumber	Endpoint number.
retryBufOffset	Retry buffer offset.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_UpdateXferCount()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_UpdateXferCount	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir,
uint32_t 	xferCount 
)		
This function updates xfer count in an ndpoint register.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
endpNum	Endpoint number.
endpDir	Endpoint direction.
xferCount	transfer count value stored here.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_EnableStatusCtrl()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_EnableStatusCtrl	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
bool 	enable 
)		
This function enable/disable Status Control feature mentioned in PROT_CS register.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
enable	true for enable and false for disable.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_ClearStatusClrBusy()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_ClearStatusClrBusy	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt	)	
This function write "1" to STATUS_CLR_BUSY which clears the bit to initiate STATUS response.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_SendAckSetupDataStatusStage()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_SendAckSetupDataStatusStage	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt	)	
This function enable HW to send ACK in status stage.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_FlushEPM()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_FlushEPM	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
bool 	force 
)		
This function will flush Ingress and egress both the EPM.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
force	Whether flush should be forcibly done even if pointers are zero.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_FlushEndpSocket()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_FlushEndpSocket	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir 
)		
This function will flush socket associated with an endpoint.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
endpNum	Endpoint number.
endpDir	Endpoint direction.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_FlushAllEndpSocket()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_FlushAllEndpSocket	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt	)	
This function will flush socket associated with all endpoints.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_EnableMainIntr()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_EnableMainIntr	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
bool 	EnableDisable 
)		
This function will enable/disable main interrupts.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
EnableDisable	true for enable and false for disable.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_EnableLinkIntr()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_EnableLinkIntr	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
bool 	EnableDisable 
)		
This function will enable/disable link interrupts.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
EnableDisable	true for enable and false for disable.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_EnableProtIntr()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_EnableProtIntr	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
bool 	EnableDisable 
)		
This function will enable/disable protocol interrupts.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
EnableDisable	true for enable and false for disable.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_EndpIsNakNrdySet()
bool Cy_USBSS_Cal_EndpIsNakNrdySet	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNum,
cy_en_usb_endp_dir_t 	endpDir 
)		
This function checks whether the specified endpoint is currently in the NRDYed state.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
endpNum	Endpoint number.
endpDir	Endpoint direction.
Returns
Whether endpoint is currently NRDYed. True means NRDYed state.
◆ Cy_USBSS_Cal_EndpIsStallSet()
bool Cy_USBSS_Cal_EndpIsStallSet	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint32_t 	endpNumber,
cy_en_usb_endp_dir_t 	endpDirection 
)		
This function checks whether the specified endpoint is currently in the STALLed state.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
endpNumber	Endpoint number.
endpDirection	Endpoint direction.
Returns
Whether endpoint is currently STALLed. True means STALLed state.
◆ Cy_USBSS_Cal_EnableSsDevice()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_EnableSsDevice	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
bool 	enable 
)		
This function enable/disable USB device in SS mode.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
enable	true for enable and false for disable.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_DisConnect()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_DisConnect	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt	)	
This function handles disconnect device at CAL layer.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_PTMConfig()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_PTMConfig	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
bool 	ptmControl 
)		
This function handles PTM related configuration.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
ptmControl	Set to 1 for enabling LDM & PTM. Set to 0 for disabling LDM and reset PTM logic.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_EnterLinkCompliance()
void Cy_USBSS_Cal_EnterLinkCompliance	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt	)	
This function performs the actions required when the USB LTSSM enters the Compliance state.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
◆ Cy_USBSS_Cal_NextCompliancePattern()
void Cy_USBSS_Cal_NextCompliancePattern	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt	)	
This function causes the LTSSM to move to the next compliance pattern once a Ping.LFPS has been detected.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
◆ Cy_USBSS_Cal_ExitLinkCompliance()
void Cy_USBSS_Cal_ExitLinkCompliance	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt	)	
This function performs the required actions when the LTSSM exits the Compliance state due to a Warm Reset.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
◆ Cy_USBSS_Cal_SetGen2EBDepth()
void Cy_USBSS_Cal_SetGen2EBDepth	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint8_t 	gen2_ebdepth 
)		
Function to update the Elastic Buffer Half Depth setting to be used in Gen2 USB connection.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
gen2_ebdepth	Elastic Buffer Half Depth setting: Valid range from 4 to 16.
◆ Cy_USBSS_Cal_IsEnabled()
bool Cy_USBSS_Cal_IsEnabled	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt	)	
Indicates whether USB 3.x connection is enabled on the device.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
Returns
true if connection is enabled, false otherwise.
◆ Cy_USBSS_Cal_MeasureCCVoltage()
uint8_t Cy_USBSS_Cal_MeasureCCVoltage	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
bool 	cc2select 
)		
Measure the voltage on CC line and return the corresponding ADC reading.

Parameters
pCalCtxt	USBSS Controller context structure.
cc2select	true to measure CC2 voltage, false for CC1.
Returns
ADC reading equivalent to the CC voltage.
◆ Cy_USBSS_Cal_SetDmaClkFreq()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_SetDmaClkFreq	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
cy_en_hbdma_clk_freq_t 	dmaFreq 
)		
Function which sets the desired DMA clock frequency on the FX3G2 device.

This function should be called before USB connection is enabled. The default clock selected is 240 MHz derived from USB2 PLL.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
dmaFreq	Desired DMA clock frequency.
Returns
Status code
◆ Cy_USBSS_Cal_DeepSleepPrep()
bool Cy_USBSS_Cal_DeepSleepPrep	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt	)	
This function prepares the USB32DEV controller IP block for entry into deep sleep state.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
Returns
true if application can proceed with deep sleep entry, false otherwise.
◆ Cy_USBSS_Cal_DeepSleepExit()
void Cy_USBSS_Cal_DeepSleepExit	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt	)	
This function restores the USB32DEV controller IP block state after USB link has resumed from U3 (suspend) state.

This function is called from the driver internally and not intended to be called directly.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
◆ Cy_USBSS_Cal_DisableLPMDeviceExit()
void Cy_USBSS_Cal_DisableLPMDeviceExit	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
bool 	devExitDisable 
)		
Function to disable support for device initiated exit from USB low power modes completely.

Parameters
pCalCtxt	USBSS Controller context structure.
devExitDisable	true to disable device initiated exit from LPM states.
◆ Cy_USBSS_Cal_InitEventLog()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_InitEventLog	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint32_t * 	pEvtLogBuf,
uint16_t 	evtLogSize 
)		
Enables capture of USBSS CAL event and state changes into RAM buffer.

This function is intended to be called by USBD and not directly from the application.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
pEvtLogBuf	RAM buffer pointer to log the data into. Can be NULL if logging is to be disabled.
evtLogSize	Size of RAM buffer in 32-bit words.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_Cal_PostEpEnable()
void Cy_USBSS_Cal_PostEpEnable	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt	)	
Function to reset egress socket EOB detection function after endpoints have been enabled.

Parameters
pCalCtxt	USBSS Controller context structure.
◆ Cy_USBSS_Cal_ReleaseLTSSM()
void Cy_USBSS_Cal_ReleaseLTSSM	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt	)	
Function to release the LTSSM from a forced state.

Parameters
pCalCtxt	USBSS Controller context structure.
◆ Cy_USBSS_Cal_ClkStopOnEpRstEnable()
void Cy_USBSS_Cal_ClkStopOnEpRstEnable	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
bool 	clkStopEn 
)		
Function to enable stop/restart of USB block clock during EP reset.

This functionality can be enabled to ensure all state related to an endpoint is cleared properly. A possible side effect is that the USB link goes through recovery cycles during the Endpoint Reset operation.

Parameters
pCalCtxt	USBSS Controller context structure.
clkStopEn	Whether to enable or disable the clock stop control.
◆ Cy_USBSS_Cal_SelectConfigLane()
void Cy_USBSS_Cal_SelectConfigLane	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
cy_en_usb_config_lane_t 	laneSel 
)		
Function to select the USB 3.x Configuration Lane.

This API can be used in cases where the USB connection orientation is being detected externally instead of through CC1/CC2 voltage measurement by the controller itself.

Parameters
pCalCtxt	USBSS Controller context structure.
laneSel	Desired configuration lane selection.
◆ Cy_USBSS_Cal_ITPIntrUpdate()
void Cy_USBSS_Cal_ITPIntrUpdate	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
bool 	itpIntrEnable 
)		
Function to enable or disable the ITP interrupt based on user requirement.

Parameters
pCalCtxt	CAL layer library context pointer.
itpIntrEnable	Whether the ITP interrupt should be enabled.
◆ Cy_USBSS_Cal_GetTemperatureReading()
uint8_t Cy_USBSS_Cal_GetTemperatureReading	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt	)	
Get the temperature sensitive reading from ADC in the USB block.

Note
The procedure to convert the ADC reading to actual temperature is TBD. The ADC reading will reduce by 1 point for a rise of approximately 5 degrees in temperature.
Parameters
pCalCtxt	USBSS Controller context structure.
Returns
ADC reading equivalent to die temperature.
◆ Cy_USBSS_Cal_TimerISR()
void Cy_USBSS_Cal_TimerISR	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt	)	
Function that handles the delay timer expiry based on the event This function should be called by the user when the TCPWM ISR is invoked.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
◆ Cy_USBSS_Cal_ResetEndpoints()
cy_en_usb_cal_ret_code_t Cy_USBSS_Cal_ResetEndpoints	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint32_t 	outEpMask,
uint32_t 	inEpMask,
uint32_t 	preserveOutSeqNum,
uint32_t 	preserveInSeqNum 
)		
Function to flush and reset stale state and data on multiple endpoints.

The endpoints to be reset are passed in through bitmask parameters.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
outEpMask	Bitmask representing OUT endpoints to be reset.
inEpMask	Bitmask representing IN endpoints to be reset.
preserveOutSeqNum	Bitmask representing OUT endpoints whose sequence numbers are to be preserved.
preserveInSeqNum	Bitmask representing IN endpoints whose sequence numbers are to be preserved.
Returns
The status code of the function execution cy_en_usb_cal_ret_code_t.
◆ Cy_USBSS_SetPreShootnDeEmphasis()
void Cy_USBSS_SetPreShootnDeEmphasis	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
int8_t 	PS_dBx10,
int8_t 	DE_dBx10 
)		
Function to set the preshoot an de-emphasis values for USB 3.x PHY TX.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
PS_dBx10	Preshoot value in dB x 10 (e.g., 2.1 dB -> 21)
DE_dBx10	De-emphasis value in dB x 10 (e.g., -3.1 dB -> -31)
◆ Cy_USBSS_SetTransmitAmplitude()
void Cy_USBSS_SetTransmitAmplitude	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint16_t 	amplitude_mV 
)		
Function to set the transmitter differential amplitude in mV units.

The default and maximum allowed value is 1150 mV.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
amplitude_mV	Desired transmitted signal amplitude in millivolt units. Valid range is from 200 mV to 1150 mV.
◆ Cy_USBSS_UpdateCtleLutMask()
void Cy_USBSS_UpdateCtleLutMask	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
cy_en_usb_speed_t 	usbSpeed,
uint16_t 	lutMask 
)		
Function to update the LUT selection mask for selected USB Speeds.

This API should be called before Cy_USBD_Connect if the changed mask is to be applied during USB RX Equalisation stage

Parameters
pCalCtxt	USBSS Controller context structure.
usbSpeed	USB Speed for which the LUT mask is to be updated
lutMask	LUT selection mask to be applied for the selected USB speed
◆ Cy_USBSS_UpdateGen2CtleLutConfig()
void Cy_USBSS_UpdateGen2CtleLutConfig	(	cy_stc_usbss_cal_ctxt_t * 	pCalCtxt,
uint32_t * 	pLutConfigArray 
)		
Function to update the CTLE configuration look up table for USB Gen2 speeds.

This API should be called before Cy_USBD_Connect() for the provided LUT configs to be used during USB RX equalization stage.

Parameters
pCalCtxt	The pointer to the USBSS context structure cy_stc_usbss_cal_ctxt_t allocated by the user.
pLutConfigArray	Pointer to array of LUT configurations