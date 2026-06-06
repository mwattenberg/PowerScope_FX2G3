void 	InitUart (uint8_t scbIndex)
 	Initialize SCB as UART for printing logs. More...
 
void 	Cy_Debug_LogInit (cy_stc_debug_config_t *pDbgCfg)
 	The API initializes the debug logger module with the desired configuration. More...
 
cy_en_debug_status_t 	Cy_Debug_LogDeInit (void)
 	The API deinitializes the debug logger module. More...
 
cy_en_debug_status_t 	Cy_Debug_AddToLog (uint8_t dbgLevel, char *message,...)
 	This is the main logging function supported by this debug module. More...
 
void 	Cy_Debug_PrintLog (void)
 	This API is used to get the logger module to incrementally output a part of the saved log messages to the selected interfaces such as UART or Virtual COM port.
 
void 	Cy_Debug_ChangeLogLevel (uint8_t level)
 	This API can be used to change the verbosity level of messages enabled by the logger module at runtime. More...
 
void 	Cy_Debug_SetPrintNow (bool immed_print_en)
 	This API allows the immediate print feature of the debug module to be updated at runtime. More...
 
bool 	Cy_Debug_QueueDataRead (uint8_t *pReadBuffer, uint16_t dataLength, cy_cb_debug_data_recv_cb_t doneCbk, void *pUserCtxt)
 	If a CDC interface is being used for data logging, this function queues a read on the corresponding OUT endpoint. More...
 
void 	Cy_Debug_HandleReadIntr (void)
 	Function called from USBFS ISR corresponding to CDC OUT endpoint to read the data and pass on to user callback.
 
void 	Cy_USB_CdcEpInDmaISR (void)
 	CDC IN Endpoint DMA ISR.
 
void 	Cy_USB_CdcEpOutDmaISR (void)
 	CDC OUT Endpoint DMA ISR.
 
void 	Cy_Debug_CdcPrintNow (bool startPrint)
 	Enable Debug logs over CDC interface. More...
 
bool 	Cy_Efuse_IsBitBlown (uint32_t bitPos, uint32_t offset)
 	Check whether the specified CustomerData eFuse bit is blown. More...
 
void 	Cy_Efuse_WriteBit (uint32_t bitPos, uint32_t offset)
 	Blow one fuse bit in the CustomerData region. More...
 
void 	InitializeWDT (uint32_t timeout_ms)
 
void 	KickWDT (void)
 
void 	Cy_UsbFx_OnResetInit (void)
 	This function performs initialization that is required to enable scatter loading of data into the High BandWidth RAM during device boot-up. More...
 
bool 	Cy_UsbFx_SelectDFTFunctions (uint32_t dft0_func, uint32_t dft1_func, uint32_t usbdft0_func, uint32_t usbdft1_func, uint32_t sipdft0_func, uint32_t sipdft1_func)
 	Function used to select the Design-For-Test debug functions which are to be driven on to the P11.0, P11.1, P9.2, P9.3, P9.4 and P9.5 pins of the EZ-USB FX device. More...
 
void 	Cy_UsbFx_MemSetDword (uint32_t *pBuffer, uint32_t value, uint32_t byteCount)
 	Initialize a memory buffer with the specified 4-byte value. More...
 
void 	Cy_UsbFx_MemCpyDword (uint32_t *pDst, const uint32_t *pSrc, uint32_t byteCount)
 	Copy data from source to destination buffer using 4-byte words. More...
 
bool 	Cy_USB_CdcInit (cy_stc_debug_context_t *pDbgCtxt)
 	Function to initialize CDC interface for debug logging. More...
 
bool 	Cy_USB_CdcDeInit (cy_stc_debug_context_t *pDbgCtxt)
 	Function to de-initialize CDC interface for debug logging. More...
 
uint16_t 	Cy_Debug_LogtoUsb (cy_stc_debug_context_t *pDbgCtxt, uint16_t rdPtr, uint16_t limit)
 	The function used to output log data through USBFS CDC IN endpoint. More...
 
void 	Cy_USB_CdcClearDmaInterrupt (cy_stc_debug_context_t *pDbgCtxt, uint8_t endpDirection, uint32_t endpNumber)
 	The function clear the DMA interrrupt associated to the endpoint. More...
 
void 	Cy_USB_CdcDmaCallback (struct cy_stc_hbdma_channel *pHandle, cy_en_hbdma_cb_type_t type, cy_stc_hbdma_buff_status_t *pbufStat, void *userCtx)
 	DMA channel Callback used by the USB CDC logging interface. More...
 
void 	Cy_USB_CdcQueueRead (cy_stc_debug_context_t *pDbgCtxt, uint8_t endpNumber, uint8_t *pBuffer, uint16_t dataSize)
 	The function queue read on OUT endpoint. More...
 
void 	Cy_USB_CdcSlpCallback (void *pAppCtxt, cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg)
 	The Function will be called by USBD layer when SLP message comes on the CDC OUT endpoint. More...
 
bool 	Cy_USB_CdcChannelEnable (cy_stc_debug_context_t *pDbgCtxt)
 	The function enables the CDC Send/Receive DMA channels. More...
 
bool 	CyUsbFsCdc_Init (void)
 	The API initializes the USB interface. More...
 
bool 	CyUsbFsCdc_Enable (void)
 	The function initializes the USB hardware and enables the D+/D- lines and does a pull up on the D+ line for the external host to detect the presence of the device. More...
 
bool 	CyUsbFsCdc_Disable (void)
 	The function disables the USB hardware and disconnects the D+/D- lines. More...
 
cy_en_usbfs_devstate_t 	CyUsbFsCdc_GetState (void)
 	The API returns the current state of the USB device module. More...
 
bool 	CyUsbFsCdc_CompleteEp0Status (void)
 	The API completes the status phase of the current EP0 request. More...
 
bool 	CyUsbFsCdc_Ep0AckWait (void)
 	The function does a blocking wait until the status phase is completed. More...
 
bool 	CyUsbFsCdc_StallEp0 (void)
 	The function stalls endpoint zero to indicate error to current request. More...
 
bool 	CyUsbFsCdc_SetupEp0Read (uint8_t *data, uint16_t length, bool last)
 	The API does not wait for the read to complete. More...
 
bool 	CyUsbFsCdc_SetupEp0Write (uint8_t *data, uint16_t length, bool last)
 	The API does not wait for the write to complete. More...
 
bool 	CyUsbFsCdc_EpEnable (uint8_t ep_index, bool is_out)
 	Enable an endpoint with the selected configuration. More...
 
bool 	CyUsbFsCdc_EpDisable (uint8_t ep_index)
 	Disables a previously enabled endpoint. More...
 
bool 	CyUsbFsCdc_EpSetStall (uint8_t ep_index)
 	The endpoint shall stall all IN / OUT tokens after the function has been executed. More...
 
bool 	CyUsbFsCdc_EpClearStall (uint8_t ep_index)
 	The function shall clear a previously stalled endpoint. More...
 
bool 	CyUsbFsCdc_IsEpReady (uint8_t ep_index)
 	Checks whether the endpoint is ready for data transfer. More...
 
bool 	CyUsbFsCdc_QueueEpRead (uint8_t ep_index)
 	The function enables the selected endpoint to receive one packet of data. More...
 
bool 	CyUsbFsCdc_EpDataRead (uint8_t ep_index, uint8_t *data, uint8_t *count)
 	Retrieves the data packet available on the endpoint. More...
 
bool 	CyUsbFsCdc_SendZlp (uint8_t ep_index)
 	The function sends a zero-length packet on the selected IN endpoint. More...
 
bool 	CyUsbFsCdc_EpDataWrite (uint8_t ep_index, uint8_t *data, uint8_t count)
 	The function copies the data available in the buffer to the endpoint buffer and arms the endpoint for transfer. More...
 
bool 	CyUsbFsCdc_EpFlush (uint8_t ep_index)
 	The function resets the endpoint and re-arms an OUT endpoint to receive data if a receive was already queued. More...
 
void 	CyUsbFsCdc_ControlDataReceive (bool recvEnable)
 	Control the handling of data received through the USBFS CDC interface. More...
 
bool 	Cy_USBHS_App_EnableEpDmaSet (cy_stc_app_endp_dma_set_t *pEpDmaSet, DW_Type *pDwStruct, uint8_t channelNum, uint8_t epNumber, cy_en_usb_endp_dir_t epDir, uint16_t maxPktSize)
 	Configure the DMA resources associated with a USBHS endpoint. More...
 
void 	Cy_USBHS_App_DisableEpDmaSet (cy_stc_app_endp_dma_set_t *pEpDmaSet)
 	De-init DMA resources related to an USBHS endpoint. More...
 
void 	Cy_USBHS_App_ResetEpDma (cy_stc_app_endp_dma_set_t *pEpDmaSet)
 	Reset the DMA resources corresponding to an endpoint. More...
 
bool 	Cy_USBHS_App_QueueRead (cy_stc_app_endp_dma_set_t *pEpDmaSet, uint8_t *pBuffer, uint32_t dataSize)
 	Function to queue read operation on an OUT endpoint. More...
 
uint16_t 	Cy_USBHS_App_ReadShortPacket (cy_stc_app_endp_dma_set_t *pEpDmaSet, uint16_t pktSize)
 	Function to modify an ongoing DMA read operation to take care of a short packet. More...
 
bool 	Cy_USBHS_App_QueueWrite (cy_stc_app_endp_dma_set_t *pEpDmaSet, uint8_t *pBuffer, uint32_t dataSize)
 	Function to queue write operation on an IN endpoint. More...
 
void 	Cy_USBHS_App_ClearDmaInterrupt (cy_stc_app_endp_dma_set_t *pEpDmaSet)
 	Disable any pending DataWire channel interrupts for an endpoint. More...
 
bool 	Cy_USBHS_App_IsChannelActive (cy_stc_app_endp_dma_set_t *pEpDmaSet)
 	Check whether the DMA channel corresponding to the specified endpoint is active. More...
 
Function Documentation
◆ InitUart()
void InitUart	(	uint8_t 	scbIndex	)	
Initialize SCB as UART for printing logs.

Parameters
scbIndex	Index of SCB to be used for UART output. Only 0 and 1 supported at present.
◆ Cy_Debug_LogInit()
void Cy_Debug_LogInit	(	cy_stc_debug_config_t * 	pDbgCfg	)	
The API initializes the debug logger module with the desired configuration.

Parameters
pDbgCfg	Debug module config parameters.
◆ Cy_Debug_LogDeInit()
cy_en_debug_status_t Cy_Debug_LogDeInit	(	void 		)	
The API deinitializes the debug logger module.

Returns
cy_en_debug_status_t
◆ Cy_Debug_AddToLog()
cy_en_debug_status_t Cy_Debug_AddToLog	(	uint8_t 	dbgLevel,
char * 	message,
 	... 
)		
This is the main logging function supported by this debug module.

It takes in a variable list of arguments like the printf function, but only the "%c", "%d", "%x" format specifiers are supported. A verbosity level is associated with each message to be printed.

Parameters
dbgLevel	Verbosity level associated with the message.
message	Format string.
Returns
Success/Failure return code.
◆ Cy_Debug_ChangeLogLevel()
void Cy_Debug_ChangeLogLevel	(	uint8_t 	level	)	
This API can be used to change the verbosity level of messages enabled by the logger module at runtime.

Parameters
level	New verbosity level to be set.
◆ Cy_Debug_SetPrintNow()
void Cy_Debug_SetPrintNow	(	bool 	immed_print_en	)	
This API allows the immediate print feature of the debug module to be updated at runtime.

Parameters
immed_print_en	Whether immediate (blocking) print function is to be enabled or disabled.
◆ Cy_Debug_QueueDataRead()
bool Cy_Debug_QueueDataRead	(	uint8_t * 	pReadBuffer,
uint16_t 	dataLength,
cy_cb_debug_data_recv_cb_t 	doneCbk,
void * 	pUserCtxt 
)		
If a CDC interface is being used for data logging, this function queues a read on the corresponding OUT endpoint.

The doneCbk will be called once the requested amount of data is received or a SLP/ZLP is received on the OUT endpoint.

Parameters
pReadBuffer	Pointer to buffer into which data is to be read.
dataLength	Maximum size of data to be read. Expected to be a multiple of 64.
doneCbk	Callback function to be called on read completion.
pUserCtxt	User context structure to be passed to the callback.
Returns
true if read operation is queued, false otherwise.
◆ Cy_Debug_CdcPrintNow()
void Cy_Debug_CdcPrintNow	(	bool 	startPrint	)	
Enable Debug logs over CDC interface.

Parameters
startPrint	Enable the CDC prints.
◆ Cy_Efuse_IsBitBlown()
bool Cy_Efuse_IsBitBlown	(	uint32_t 	bitPos,
uint32_t 	offset 
)		
Check whether the specified CustomerData eFuse bit is blown.

The fuse read is done through system call made to USB-FX device ROM code.

Parameters
bitPos	Bit position of the fuse to be checked. Valid values are in the range of 0 to 7
offset	Byte offset of the fuse to be checked. Valid values are in the range of 0x52 to 0x7F
Returns
true if the fuse bit is already blown, false otherwise.
◆ Cy_Efuse_WriteBit()
void Cy_Efuse_WriteBit	(	uint32_t 	bitPos,
uint32_t 	offset 
)		
Blow one fuse bit in the CustomerData region.

The fuse programming is done through system call made to the USB-FX device ROM code.

Parameters
bitPos	Bit position of the fuse to be written. Valid values are in the range of 0 to 7
offset	Byte offset of the fuse to be written. Valid values are in the range of 0x52 to 0x7F
◆ Cy_UsbFx_OnResetInit()
void Cy_UsbFx_OnResetInit	(	void 		)	
This function performs initialization that is required to enable scatter loading of data into the High BandWidth RAM during device boot-up.

The FX10/FX20 device comes up with the High BandWidth RAM disabled and hence any attempt to read/write the RAM will cause the processor to hang. The RAM needs to be enabled with default clock settings to allow scatter loading to work. This function needs to be called from Cy_OnResetUser.

◆ Cy_UsbFx_SelectDFTFunctions()
bool Cy_UsbFx_SelectDFTFunctions	(	uint32_t 	dft0_func,
uint32_t 	dft1_func,
uint32_t 	usbdft0_func,
uint32_t 	usbdft1_func,
uint32_t 	sipdft0_func,
uint32_t 	sipdft1_func 
)		
Function used to select the Design-For-Test debug functions which are to be driven on to the P11.0, P11.1, P9.2, P9.3, P9.4 and P9.5 pins of the EZ-USB FX device.

Parameters
dft0_func	Select the debug function to be driven on the P11.0 pin. Any USB/LVDS function is supported.
dft1_func	Select the debug function to be driven on the P11.1 pin. Any USB/LVDS function is supported.
usbdft0_func	Select the debug function to be driven on the P9.2 pin. Only USB functions are supported.
usbdft1_func	Select the debug function to be driven on the P9.3 pin. Only USB functions are supported.
sipdft0_func	Select the debug function to be driven on the P9.4 pin. Only LVDS/LVCMOS functions are supported.
sipdft1_func	Select the debug function to be driven on the P9.5 pin. Only LVDS/LVCMOS functions are supported.
Returns
true if DFT configuration is done, false in case of error.
◆ Cy_UsbFx_MemSetDword()
void Cy_UsbFx_MemSetDword	(	uint32_t * 	pBuffer,
uint32_t 	value,
uint32_t 	byteCount 
)		
Initialize a memory buffer with the specified 4-byte value.

Parameters
pBuffer	Pointer to buffer to be initialized.
value	Value to initialize the memory buffer with.
byteCount	Size of the buffer in bytes.
◆ Cy_UsbFx_MemCpyDword()
void Cy_UsbFx_MemCpyDword	(	uint32_t * 	pDst,
const uint32_t * 	pSrc,
uint32_t 	byteCount 
)		
Copy data from source to destination buffer using 4-byte words.

Parameters
pDst	Pointer to destination buffer.
pSrc	Pointer to source buffer.
byteCount	Size of the buffer in bytes.
◆ Cy_USB_CdcInit()
bool Cy_USB_CdcInit	(	cy_stc_debug_context_t * 	pDbgCtxt	)	
Function to initialize CDC interface for debug logging.

Parameters
pDbgCtxt	Debug Context
Returns
True if initialization is successful, else False
◆ Cy_USB_CdcDeInit()
bool Cy_USB_CdcDeInit	(	cy_stc_debug_context_t * 	pDbgCtxt	)	
Function to de-initialize CDC interface for debug logging.

Parameters
pDbgCtxt	Debug Context
Returns
True if deinitialization is successful, else False
◆ Cy_Debug_LogtoUsb()
uint16_t Cy_Debug_LogtoUsb	(	cy_stc_debug_context_t * 	pDbgCtxt,
uint16_t 	rdPtr,
uint16_t 	limit 
)		
The function used to output log data through USBFS CDC IN endpoint.

Parameters
pDbgCtxt	Debug Context.
rdPtr	Pointer to read data
limit	Number of bytes to be read
Returns
return rdPtr pointer value
◆ Cy_USB_CdcClearDmaInterrupt()
void Cy_USB_CdcClearDmaInterrupt	(	cy_stc_debug_context_t * 	pDbgCtxt,
uint8_t 	endpDirection,
uint32_t 	endpNumber 
)		
The function clear the DMA interrrupt associated to the endpoint.

Parameters
pDbgCtxt	Debug Context.
endpDirection	IN or OUT endpoint
endpNumber	Endpoint Number
◆ Cy_USB_CdcDmaCallback()
void Cy_USB_CdcDmaCallback	(	struct cy_stc_hbdma_channel * 	pHandle,
cy_en_hbdma_cb_type_t 	type,
cy_stc_hbdma_buff_status_t * 	pbufStat,
void * 	userCtx 
)		
DMA channel Callback used by the USB CDC logging interface.

Parameters
pHandle	CDC Channel Handle.
type	Event type
pbufStat	DMA buffer pointer
userCtx	User context
◆ Cy_USB_CdcQueueRead()
void Cy_USB_CdcQueueRead	(	cy_stc_debug_context_t * 	pDbgCtxt,
uint8_t 	endpNumber,
uint8_t * 	pBuffer,
uint16_t 	dataSize 
)		
The function queue read on OUT endpoint.

Parameters
pDbgCtxt	Debug Context.
endpNumber	Out Endpoint number to queue the read
pBuffer	Buffer pointer to store the read data.
dataSize	Bytes to read on OUT endpoint
◆ Cy_USB_CdcSlpCallback()
void Cy_USB_CdcSlpCallback	(	void * 	pAppCtxt,
cy_stc_usb_usbd_ctxt_t * 	pUsbdCtxt,
cy_stc_usb_cal_msg_t * 	pMsg 
)		
The Function will be called by USBD layer when SLP message comes on the CDC OUT endpoint.

Parameters
pAppCtxt	User context
pUsbdCtxt	USBD context
pMsg	Message
◆ Cy_USB_CdcChannelEnable()
bool Cy_USB_CdcChannelEnable	(	cy_stc_debug_context_t * 	pDbgCtxt	)	
The function enables the CDC Send/Receive DMA channels.

Parameters
pDbgCtxt	Debug context
Returns
true if channel was enabled successfully, false otherwise.
◆ CyUsbFsCdc_Init()
bool CyUsbFsCdc_Init	(	void 		)	
The API initializes the USB interface.

This is mainly a software state machine initialization. The PHY is not enabled at this point. The API helps to cleanup previous state information.

Returns
true if the action is successful, false otherwise.
◆ CyUsbFsCdc_Enable()
bool CyUsbFsCdc_Enable	(	void 		)	
The function initializes the USB hardware and enables the D+/D- lines and does a pull up on the D+ line for the external host to detect the presence of the device.

The API expects that the USB block is already initialized.

Returns
true if the action is successful, false otherwise.
◆ CyUsbFsCdc_Disable()
bool CyUsbFsCdc_Disable	(	void 		)	
The function disables the USB hardware and disconnects the D+/D- lines.

Returns
true if the action is successful, false otherwise.
◆ CyUsbFsCdc_GetState()
cy_en_usbfs_devstate_t CyUsbFsCdc_GetState	(	void 		)	
The API returns the current state of the USB device module.

Returns
The current USB device/stack state.
◆ CyUsbFsCdc_CompleteEp0Status()
bool CyUsbFsCdc_CompleteEp0Status	(	void 		)	
The API completes the status phase of the current EP0 request.

The caller is expected to call the function in sequence. The status phase is handled inplicitly when the setup_read and setup_write functions are invoked correctly with the last flag set to true. The function does not wait for the transfer to complete. In case of an error, the EP0 shall be stalled by the USB module.

Returns
true if the action is successful, false otherwise.
◆ CyUsbFsCdc_Ep0AckWait()
bool CyUsbFsCdc_Ep0AckWait	(	void 		)	
The function does a blocking wait until the status phase is completed.

This function should be invoked only if the task loop can be safely blocked.

Returns
true if the action is successful, false otherwise.
◆ CyUsbFsCdc_StallEp0()
bool CyUsbFsCdc_StallEp0	(	void 		)	
The function stalls endpoint zero to indicate error to current request.

The stall is automatically cleared on receiving a new setup request.

Returns
true if the action is successful, false otherwise.
◆ CyUsbFsCdc_SetupEp0Read()
bool CyUsbFsCdc_SetupEp0Read	(	uint8_t * 	data,
uint16_t 	length,
bool 	last 
)		
The API does not wait for the read to complete.

The function just updates the state machine and queues the first packet read. The read has to be completed by repeatedly queueing packet read requests. The last parameter can be used to do multiple partial transfers. For default single tranfers, the last parameter should always be true.

Parameters
data	Buffer to write the received USB EP0 data into. The caller should ensure that the buffer is capable of receiving upto a size of length bytes.
length	Length of data to be transferred. This has to be a multiple of eight bytes.
last	Whether the request is a partial transfer or not. Set to true if the stack needs to implicily handle the status phase after completing the transfer.
Returns
true if the action is successful, false otherwise.
◆ CyUsbFsCdc_SetupEp0Write()
bool CyUsbFsCdc_SetupEp0Write	(	uint8_t * 	data,
uint16_t 	length,
bool 	last 
)		
The API does not wait for the write to complete.

The function just updates the state machine and queues the first packet. The write has to be completed by repeatedly queueing packet requests. The last parameter can be used to do multiple partial transfers. For default single tranfers, the last parameter should always be true.

Parameters
data	Buffer containing the USB EP0 data to be transferred.
length	Length of data to be transferred.
last	Whether the request is a partial transfer or not. Set to true if the stack needs to implicily handle the status phase after completing the transfer.
Returns
true if the action is successful, false otherwise.
◆ CyUsbFsCdc_EpEnable()
bool CyUsbFsCdc_EpEnable	(	uint8_t 	ep_index,
bool 	is_out 
)		
Enable an endpoint with the selected configuration.

The endpoint shall be initialized and configured with the provided parameters. The API expects the endpoint to be in disabled state.

Parameters
ep_index	Index of endpoint to be enabled. Valid values are from 1 to 8 (inclusive).
is_out	true if the endpoint is an OUT endpoint, false for IN endpoint.
Returns
true if the action is successful, false otherwise.
◆ CyUsbFsCdc_EpDisable()
bool CyUsbFsCdc_EpDisable	(	uint8_t 	ep_index	)	
Disables a previously enabled endpoint.

The endpoint shall be disabled and all data in the FIFO cleared. The endpoint shall stop responding to requests from USB host.

Parameters
ep_index	Index of endpoint to be disabled. Valid values are from 1 to 8 (inclusive).
Returns
true if the action is successful, false otherwise.
◆ CyUsbFsCdc_EpSetStall()
bool CyUsbFsCdc_EpSetStall	(	uint8_t 	ep_index	)	
The endpoint shall stall all IN / OUT tokens after the function has been executed.

Parameters
ep_index	Index of endpoint to be modified. Valid values are from 1 to 8 (inclusive).
Returns
true if the action is successful, false otherwise.
◆ CyUsbFsCdc_EpClearStall()
bool CyUsbFsCdc_EpClearStall	(	uint8_t 	ep_index	)	
The function shall clear a previously stalled endpoint.

The function shall reset the data toggle even if the endpoint was not previously stalled. This call shall also reset the endpoint to the default state. So read should be explicitly invoked for an OUT endpoint. The endpoint shall start NAKing all the IN / OUT tokens once the function gets executed.

Parameters
ep_index	Index of endpoint to be modified. Valid values are from 1 to 8 (inclusive).
Returns
true if the action is successful, false otherwise.
◆ CyUsbFsCdc_IsEpReady()
bool CyUsbFsCdc_IsEpReady	(	uint8_t 	ep_index	)	
Checks whether the endpoint is ready for data transfer.

The API expects that the endpoint is enabled and active.

Parameters
ep_index	Endpoint to be checked
Returns
Endpoint status: true - If this is an IN endpoint, then the EP is ready to send data. If there was a previous transfer then it has completed successfully. If this is an OUT endpoint, then the EP has received a packet of data from the USB host. false - If this is an IN endpoint, data is being sent out and not completed. If this is an OUT endpoint, then the data is not yet received. If the endpoint is not active or USB connection is not active, this API returns CyFalse.
◆ CyUsbFsCdc_QueueEpRead()
bool CyUsbFsCdc_QueueEpRead	(	uint8_t 	ep_index	)	
The function enables the selected endpoint to receive one packet of data.

It does not wait for the data to be received.

Parameters
ep_index	Index of endpoint on which read is to be queued.
Returns
true if the operation is successful, false otherwise.
◆ CyUsbFsCdc_EpDataRead()
bool CyUsbFsCdc_EpDataRead	(	uint8_t 	ep_index,
uint8_t * 	data,
uint8_t * 	count 
)		
Retrieves the data packet available on the endpoint.

The function expects that a data is already available and retrieves the packet from the endpoint buffer.

Parameters
ep_index	Index of endpoint on which read is to be performed.
data	Pointer to buffer into which the data should be read.
count	Size of the data to be read (in bytes).
Returns
true if the operation is successful, false otherwise.
◆ CyUsbFsCdc_SendZlp()
bool CyUsbFsCdc_SendZlp	(	uint8_t 	ep_index	)	
The function sends a zero-length packet on the selected IN endpoint.

Parameters
ep_index	Index of endpoint on which ZLP is to be sent.
Returns
true if the operation is successful, false otherwise.
◆ CyUsbFsCdc_EpDataWrite()
bool CyUsbFsCdc_EpDataWrite	(	uint8_t 	ep_index,
uint8_t * 	data,
uint8_t 	count 
)		
The function copies the data available in the buffer to the endpoint buffer and arms the endpoint for transfer.

Parameters
ep_index	Index of endpoint on which data is to be transferred.
data	Pointer to buffer containing the data to be written.
count	Size of the data to be transferred (in bytes).
Returns
true if the operation is successful, false otherwise.
◆ CyUsbFsCdc_EpFlush()
bool CyUsbFsCdc_EpFlush	(	uint8_t 	ep_index	)	
The function resets the endpoint and re-arms an OUT endpoint to receive data if a receive was already queued.

Parameters
ep_index	Index of endpoint which is to be flushed.
Returns
true if the operation is successful, false otherwise.
◆ CyUsbFsCdc_ControlDataReceive()
void CyUsbFsCdc_ControlDataReceive	(	bool 	recvEnable	)	
Control the handling of data received through the USBFS CDC interface.

When data receive is not enabled, the driver will keep discarding any data received on the OUT endpoint. When data receive is enabled, it is expected that the user will queue read operations to fetch the OUT data as required.

Parameters
recvEnable	Whether data receive handling is enabled.
◆ Cy_USBHS_App_EnableEpDmaSet()
bool Cy_USBHS_App_EnableEpDmaSet	(	cy_stc_app_endp_dma_set_t * 	pEpDmaSet,
DW_Type * 	pDwStruct,
uint8_t 	channelNum,
uint8_t 	epNumber,
cy_en_usb_endp_dir_t 	epDir,
uint16_t 	maxPktSize 
)		
Configure the DMA resources associated with a USBHS endpoint.

Parameters
pEpDmaSet	USBHS endpoint DMA wrapper structure
pDwStruct	Pointer to DataWire instance to be used for this endpoint.
channelNum	DataWire channel number to be used.
epNumber	USB endpoint number.
epDir	USB endpoint direction.
maxPktSize	Maximum packet size for the endpoint.
Returns
true if the action is successful, false otherwise.
◆ Cy_USBHS_App_DisableEpDmaSet()
void Cy_USBHS_App_DisableEpDmaSet	(	cy_stc_app_endp_dma_set_t * 	pEpDmaSet	)	
De-init DMA resources related to an USBHS endpoint.

Parameters
pEpDmaSet	USBHS endpoint DMA wrapper structure
◆ Cy_USBHS_App_ResetEpDma()
void Cy_USBHS_App_ResetEpDma	(	cy_stc_app_endp_dma_set_t * 	pEpDmaSet	)	
Reset the DMA resources corresponding to an endpoint.

Parameters
pEpDmaSet	USBHS endpoint DMA wrapper structure
◆ Cy_USBHS_App_QueueRead()
bool Cy_USBHS_App_QueueRead	(	cy_stc_app_endp_dma_set_t * 	pEpDmaSet,
uint8_t * 	pBuffer,
uint32_t 	dataSize 
)		
Function to queue read operation on an OUT endpoint.

Parameters
pEpDmaSet	USBHS endpoint DMA wrapper structure
pBuffer	Pointer to buffer into which the data should be read.
dataSize	Amount of data (in bytes) to be read.
Returns
true if the action is successful, false otherwise.
◆ Cy_USBHS_App_ReadShortPacket()
uint16_t Cy_USBHS_App_ReadShortPacket	(	cy_stc_app_endp_dma_set_t * 	pEpDmaSet,
uint16_t 	pktSize 
)		
Function to modify an ongoing DMA read operation to take care of a short packet.

Parameters
pEpDmaSet	USBHS endpoint DMA wrapper structure
pktSize	Size (in bytes) of the short packet which has been received.
Returns
Total amount of data received on the endpoint including any previous full packets.
◆ Cy_USBHS_App_QueueWrite()
bool Cy_USBHS_App_QueueWrite	(	cy_stc_app_endp_dma_set_t * 	pEpDmaSet,
uint8_t * 	pBuffer,
uint32_t 	dataSize 
)		
Function to queue write operation on an IN endpoint.

Parameters
pEpDmaSet	USBHS endpoint DMA wrapper structure
pBuffer	Pointer to buffer containing write data.
dataSize	Amount of data to be transferred (in bytes).
Returns
true if the action is successful, false otherwise.
◆ Cy_USBHS_App_ClearDmaInterrupt()
void Cy_USBHS_App_ClearDmaInterrupt	(	cy_stc_app_endp_dma_set_t * 	pEpDmaSet	)	
Disable any pending DataWire channel interrupts for an endpoint.

Parameters
pEpDmaSet	USBHS endpoint DMA wrapper structure
◆ Cy_USBHS_App_IsChannelActive()
bool Cy_USBHS_App_IsChannelActive	(	cy_stc_app_endp_dma_set_t * 	pEpDmaSet	)	
Check whether the DMA channel corresponding to the specified endpoint is active.

Parameters
pEpDmaSet	USBHS endpoint DMA wrapper structure
Returns
true if the channel is active, false otherwise.