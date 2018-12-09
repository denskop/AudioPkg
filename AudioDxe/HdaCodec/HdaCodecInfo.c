/*
 * File: HdaCodecInfo.c
 *
 * Copyright (c) 2018 John Davis
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "HdaCodec.h"

/**                                                                 
  Gets the codec's vendor ID.

  @param[in]  This              A pointer to the EFI_HDA_CODEC_INFO_PROTOCOL instance.
  @param[out] VendorId          The vendor ID of the codec.

  @retval EFI_SUCCESS           The vendor ID was retrieved.
  @retval EFI_INVALID_PARAMETER One or more parameters are invalid.                    
**/
EFI_STATUS
EFIAPI
HdaCodecInfoGetVendorId(
    IN  EFI_HDA_CODEC_INFO_PROTOCOL *This,
    OUT UINT16 *VendorId) {
    DEBUG((DEBUG_INFO, "HdaCodecInfoGetVendorId(): start\n"));
    
    // Create variables.
    HDA_CODEC_INFO_PRIVATE_DATA *HdaPrivateData;

    // If parameters are null, fail.
    if (This == NULL || VendorId == NULL)
        return EFI_INVALID_PARAMETER;

    // Get private data and fill vendor ID parameter.
    HdaPrivateData = HDA_CODEC_INFO_PRIVATE_DATA_FROM_THIS(This);
    *VendorId = HdaPrivateData->HdaCodecDev->VendorId;
    return EFI_SUCCESS;
}

/**                                                                 
  Gets the codec's device ID.

  @param[in]  This              A pointer to the EFI_HDA_CODEC_INFO_PROTOCOL instance.
  @param[out] DeviceId          The device ID of the codec.

  @retval EFI_SUCCESS           The device ID was retrieved.
  @retval EFI_INVALID_PARAMETER One or more parameters are invalid.                    
**/
EFI_STATUS
EFIAPI
HdaCodecInfoGetDeviceId(
    IN  EFI_HDA_CODEC_INFO_PROTOCOL *This,
    OUT UINT16 *DeviceId) {
    DEBUG((DEBUG_INFO, "HdaCodecInfoGetDeviceId(): start\n"));
    
    // Create variables.
    HDA_CODEC_INFO_PRIVATE_DATA *HdaPrivateData;

    // If parameters are null, fail.
    if (This == NULL || DeviceId == NULL)
        return EFI_INVALID_PARAMETER;

    // Get private data and fill device ID parameter.
    HdaPrivateData = HDA_CODEC_INFO_PRIVATE_DATA_FROM_THIS(This);
    *DeviceId = HdaPrivateData->HdaCodecDev->DeviceId;
    return EFI_SUCCESS;
}