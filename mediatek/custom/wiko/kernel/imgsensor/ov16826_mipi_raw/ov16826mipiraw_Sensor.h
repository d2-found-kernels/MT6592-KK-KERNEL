/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*  
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABI LITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
* 
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   sensor.h
 *
 * Project:
 * --------
 *   DUMA
 *
 * Description:
 * ------------
 *   CMOS sensor header file
 *
 ****************************************************************************/
#ifndef _OV16826_SENSOR_H
#define _OV16826_SENSOR_H

#define OV16826_DEBUG
#define OV16826_DRIVER_TRACE
//#define OV16826_TEST_PATTEM
#ifdef OV16826_DEBUG
//#define SENSORDB printk
#else
//#define SENSORDB(x,...)
#endif

//#define OV16826_2_LANE  // if you use 2 lane setting on MT6589, please define it
#define OV16826_FACTORY_START_ADDR 0
#define OV16826_ENGINEER_START_ADDR 10

//#define MIPI_INTERFACE

 
typedef enum OV16826_group_enum
{
  OV16826_PRE_GAIN = 0,
  OV16826_CMMCLK_CURRENT,
  OV16826_FRAME_RATE_LIMITATION,
  OV16826_REGISTER_EDITOR,
  OV16826_GROUP_TOTAL_NUMS
} OV16826_FACTORY_GROUP_ENUM;

typedef enum OV16826_register_index
{
  OV16826_SENSOR_BASEGAIN = OV16826_FACTORY_START_ADDR,
  OV16826_PRE_GAIN_R_INDEX,
  OV16826_PRE_GAIN_Gr_INDEX,
  OV16826_PRE_GAIN_Gb_INDEX,
  OV16826_PRE_GAIN_B_INDEX,
  OV16826_FACTORY_END_ADDR
} OV16826_FACTORY_REGISTER_INDEX;

typedef enum OV16826_engineer_index
{
  OV16826_CMMCLK_CURRENT_INDEX = OV16826_ENGINEER_START_ADDR,
  OV16826_ENGINEER_END
} OV16826_FACTORY_ENGINEER_INDEX;

typedef struct _sensor_data_struct
{
  SENSOR_REG_STRUCT reg[OV16826_ENGINEER_END];
  SENSOR_REG_STRUCT cct[OV16826_FACTORY_END_ADDR];
} sensor_data_struct;


#define OV16826_COLOR_FORMAT                    SENSOR_OUTPUT_FORMAT_RAW_B

#define OV16826_MIN_ANALOG_GAIN  1   /* 1x */
#define OV16826_MAX_ANALOG_GAIN      32 /* 32x */

 
/* FRAME RATE UNIT */
#define OV16826_FPS(x)                          (10 * (x))


#define OV16826_PREVIEW_CLK   80000000
#define OV16826_CAPTURE_CLK   80000000
#define OV16826_VIDEO_CLK     80000000
#define OV16826_ZSD_PRE_CLK   80000000

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define OV16826_FULL_PERIOD_PIXEL_NUMS          6112  //  25fps
#define OV16826_FULL_PERIOD_LINE_NUMS           3490   //

#define OV16826_PV_PERIOD_PIXEL_NUMS            6080 //
#define OV16826_PV_PERIOD_LINE_NUMS             1754 //

#define OV16826_VIDEO_PERIOD_PIXEL_NUMS         6080  //
#define OV16826_VIDEO_PERIOD_LINE_NUMS          1754  //

#define OV16826_3D_FULL_PERIOD_PIXEL_NUMS       6112 /* 15 fps */
#define OV16826_3D_FULL_PERIOD_LINE_NUMS        3490
#define OV16826_3D_PV_PERIOD_PIXEL_NUMS         6080 /* 30 fps */
#define OV16826_3D_PV_PERIOD_LINE_NUMS          1754
#define OV16826_3D_VIDEO_PERIOD_PIXEL_NUMS      6080 /* 30 fps */
#define OV16826_3D_VIDEO_PERIOD_LINE_NUMS       1754
/* SENSOR START/END POSITION */
#define OV16826_FULL_X_START                    0//10
#define OV16826_FULL_Y_START                    0//10
#define OV16826_IMAGE_SENSOR_FULL_WIDTH         4608 //(4608 - 640) /* 2560 */
#define OV16826_IMAGE_SENSOR_FULL_HEIGHT        3456 //(3456 - 480) /* 1920 */

#define OV16826_PV_X_START                      0 // 2
#define OV16826_PV_Y_START                      0 // 2
#define OV16826_IMAGE_SENSOR_PV_WIDTH           2304 //(2304 - 320)
#define OV16826_IMAGE_SENSOR_PV_HEIGHT          1728 //(1728 - 240)

#define OV16826_VIDEO_X_START                   0 //9
#define OV16826_VIDEO_Y_START                   0 //11
#define OV16826_IMAGE_SENSOR_VIDEO_WIDTH        2304 //(2304 - 320) /* 1264 */
#define OV16826_IMAGE_SENSOR_VIDEO_HEIGHT       1728 //(1728 - 240) /* 948 */

#define OV16826_3D_FULL_X_START                 10   //(1+16+6)
#define OV16826_3D_FULL_Y_START                 10  //(1+12+4)
#define OV16826_IMAGE_SENSOR_3D_FULL_WIDTH      (4608 - 640) //(2592 - 16) /* 2560 */
#define OV16826_IMAGE_SENSOR_3D_FULL_HEIGHT     (3456 - 480) //(1944 - 12) /* 1920 */
#define OV16826_3D_PV_X_START                   2
#define OV16826_3D_PV_Y_START                   2
#define OV16826_IMAGE_SENSOR_3D_PV_WIDTH        (2304 - 320) /* 1600 */
#define OV16826_IMAGE_SENSOR_3D_PV_HEIGHT       (1728 - 240) /* 1200 */
#define OV16826_3D_VIDEO_X_START                2
#define OV16826_3D_VIDEO_Y_START                2
#define OV16826_IMAGE_SENSOR_3D_VIDEO_WIDTH     (2304 - 320) /* 1600 */
#define OV16826_IMAGE_SENSOR_3D_VIDEO_HEIGHT    (1728 - 240) /* 1200 */



/* SENSOR READ/WRITE ID */

#define OV16826_SLAVE_WRITE_ID_1   (0x6c)
#define OV16826_SLAVE_WRITE_ID_2   (0x20)
/************OTP Feature*********************/
//#define OV16826_USE_OTP
#define OV16826_USE_WB_OTP

#if defined(OV16826_USE_OTP)

#endif
/************OTP Feature*********************/

/* SENSOR PRIVATE STRUCT */
typedef struct OV16826_sensor_STRUCT
{
  MSDK_SENSOR_CONFIG_STRUCT cfg_data;
  sensor_data_struct eng; /* engineer mode */
  MSDK_SENSOR_ENG_INFO_STRUCT eng_info;
  kal_uint8 mirror;
  kal_bool pv_mode;
  kal_bool video_mode;  
  //kal_bool NightMode;
  kal_bool is_zsd;
  kal_bool is_zsd_cap;
  kal_bool is_autofliker;
  //kal_uint16 normal_fps; /* video normal mode max fps */
  //kal_uint16 night_fps; /* video night mode max fps */  
  kal_uint16 FixedFps;
  kal_uint16 shutter;
  kal_uint16 gain;
  kal_uint32 pv_pclk;
  kal_uint32 cap_pclk;
  kal_uint32 pclk;
  kal_uint16 frame_height;
  kal_uint16 line_length;  
  kal_uint16 write_id;
  kal_uint16 read_id;
  kal_uint16 dummy_pixels;
  kal_uint16 dummy_lines;
} OV16826_sensor_struct;

//export functions
UINT32 OV16826Open(void);
UINT32 OV16826Control(MSDK_SCENARIO_ID_ENUM ScenarioId, MSDK_SENSOR_EXPOSURE_WINDOW_STRUCT *pImageWindow, MSDK_SENSOR_CONFIG_STRUCT *pSensorConfigData);
UINT32 OV16826FeatureControl(MSDK_SENSOR_FEATURE_ENUM FeatureId, UINT8 *pFeaturePara,UINT32 *pFeatureParaLen);
UINT32 OV16826GetInfo(MSDK_SCENARIO_ID_ENUM ScenarioId, MSDK_SENSOR_INFO_STRUCT *pSensorInfo, MSDK_SENSOR_CONFIG_STRUCT *pSensorConfigData);
UINT32 OV16826GetResolution(MSDK_SENSOR_RESOLUTION_INFO_STRUCT *pSensorResolution);
UINT32 OV16826Close(void);

#define Sleep(ms) mdelay(ms)

#endif 
