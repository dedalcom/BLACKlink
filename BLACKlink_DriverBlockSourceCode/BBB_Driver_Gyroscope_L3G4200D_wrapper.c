/*
  *
  *   --- THIS FILE GENERATED BY S-FUNCTION BUILDER: 3.0 ---
  *
  *   This file is a wrapper S-function produced by the S-Function
  *   Builder which only recognizes certain fields.  Changes made
  *   outside these fields will be lost the next time the block is
  *   used to load, edit, and resave this file. This file will be overwritten
  *   by the S-function Builder block. If you want to edit this file by hand, 
  *   you must change it only in the area defined as:  
  *
  *        %%%-SFUNWIZ_wrapper_XXXXX_Changes_BEGIN 
  *            Your Changes go here
  *        %%%-SFUNWIZ_wrapper_XXXXXX_Changes_END
  *
  *   For better compatibility with the Simulink Coder, the
  *   "wrapper" S-function technique is used.  This is discussed
  *   in the Simulink Coder User's Manual in the Chapter titled,
  *   "Wrapper S-functions".
  *
  *   Created: Sun Dec 14 05:06:45 2014
  */


/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include <stdio.h>
#include <stddef.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
//#include <inttypes.h>
//#include <errno.h>


# ifndef MATLAB_MEX_FILE

	#include <linux/i2c.h>
	#include <linux/i2c-dev.h>
	#include <sys/ioctl.h>
	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	//#include <simstruc.h>
# else

	#include <mex.h>
	#include <simstruc.h>

# endif


//#define S_FUNCTION_NAME BBB_Driver_Gyroscope_L3G4200D 
//#define S_FUNCTION_LEVEL 2

// Define Gyproscope Registry Locations
# define cAngVelReg_X_LSB 0x28
# define cAngVelReg_X_MSB 0x29
# define cAngVelReg_Y_LSB 0x2A
# define cAngVelReg_Y_MSB 0x2B
# define cAngVelReg_Z_LSB 0x2C
# define cAngVelReg_Z_MSB 0x2D
# define cAmbTempReg      0x26
# define cGyro_I2C_Addr1  0x68
# define cGyro_I2C_Addr2  0x69
# define cGyro_I2C_BufferSize 0x30 // Read Only Interested Part of Register
# define cGyro_WhoAmIReg  0x0F
# define cGyro_WhoAmI	  0xD3
# define cGyro_CtrlReg1   0x20
# define cGyro_CtrlReg4   0x23
# define cGyro_NormalMode 0x0F 
# define cGyrp_StatusReg  0x27	


// Set Gyroscope Sensitivity Ratings
#define dGyro_Sens_250dps  0.00875
#define dGyro_Sens_500dps  0.0175
#define dGyro_Sens_2000dps 0.075

// Set Gyroscope Measurement Range Register Values
#define cGyro_Sens_250dps  0x00
#define cGyro_Sens_500dps  0x10
#define cGyro_Sens_2000dps 0x30

/*
// Declare Sensitivity Ratings
double dGyro_Sens_250dps = 0.00875;
double dGyro_Sens_500dps = 0.0175;
double dGyro_Sens_2000dps = 0.075;
*/

//SimStruct *S;

// Declare Error Handling
// extern int errno; 

// Function Options (1=On/0=Off)
int iOpt_TwoComplement = 0; // Data To Be Treated as Two's Complement

// Delcare Global Variables
int iLoop_Counter_DS=0;

// Define Debug Levels
typedef enum 
{
       	Debug_None,
	Debug_Level_0, // Basic Debug Info Output
        Debug_Level_1, // + Critical Info Only
	Debug_Level_2, // + Diagnostics Info
	Debug_Level_3, // + Program Flow Info
	Debug_Level_4, // + Registry Data
	Debug_Level_5  // + TBD 
}eDebugLevel;

// Initialize Debug Output Level
eDebugLevel iDebug_Level = Debug_None;

// Define Error Number
typedef enum 
{
    Error_None=0,
    Error_No_I2CComm,
    Error_No_I2CInit,
    Error_No_I2CBuffSet,
    Error_No_I2CBuffRead,
    Error_No_I2CBuffSync,
    Error_No_I2CBuffWrite,
    Error_No_ParamOutofRange
}eError_No;

// Initialize Error
// eError_No iError_No = Error_None;

// Define Error Severity Levels
typedef enum
{
    Error_Level_OK=0,
    Error_Level_Critical, // (Stop Simulation)
    Error_Level_Warning
}eError_Level;

// Initialize Error Level
// eError_Level iError_Level = Error_Level_OK;

// Define Parameter Selection: Gyro Sensitivity
typedef enum 
{
    iAngVel_250dps=1,
    iAngVel_500dps=2,
    iAngVel_2000dps=3
}eGyro_Range;

 

/*
double dGyro_SetSens(eGyro_Range iGyro_Range)
{
    //Set Sensitivity Value Based on Gyro Range Setting
    switch(iGyro_Range)
    {
        case  iAngVel_250dps: //iAngVel_250dps:
            return((double)dGyro_Sens_250dps);
            break;
        case iAngVel_500dps:
            return((double)dGyro_Sens_500dps);
            break;            
        case iAngVel_2000dps:
            return((double)dGyro_Sens_2000dps);
            break;
        default:
            // Error 
            return(-1);
    }
} 
*/
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */

double dGyro_SetSens(eGyro_Range iGyro_Range)
{
    //Set Sensitivity Value Based on Gyro Range Setting
    switch(iGyro_Range)
    {
        case  iAngVel_250dps: //iAngVel_250dps:
            return((double)dGyro_Sens_250dps);
            break;
        case iAngVel_500dps:
            return((double)dGyro_Sens_500dps);
            break;            
        case iAngVel_2000dps:
            return((double)dGyro_Sens_2000dps);
            break;
        default:
            // Error 
            return(-1);
    }
} 

char cGyro_SetRange(eGyro_Range iGyro_Range)
{
    //Set Sensitivity Value Based on Gyro Range Setting
    switch(iGyro_Range)
    {
        case  iAngVel_250dps: //iAngVel_250dps:
            return((char)cGyro_Sens_250dps);
            break;
        case iAngVel_500dps:
            return((char)cGyro_Sens_500dps);
            break;            
        case iAngVel_2000dps:
            return((char)cGyro_Sens_2000dps);
            break;
        default:
            // Error -Return Default 
            return((char)cGyro_Sens_250dps);
            break;
    }
}

const char *sGyro_SetRange(eGyro_Range iGyro_Range)
{
    //Set Sensitivity Value Based on Gyro Range Setting
    switch(iGyro_Range)
    {
        case  iAngVel_250dps: //iAngVel_250dps:
            return("250 dps\n");
            break;
        case iAngVel_500dps:
            return("500 dps\n");
            break;            
        case iAngVel_2000dps:
            return("2000 dps\n");
            break;
        default:
            // Error -Return Default 
            return("Range Request Error\n");
            break;
    }
}


const char *sGyro_ErrMessage(eError_No iGyro_ErrNo)
{
    //Set Error Message Based on Error Number
    switch(iGyro_ErrNo)
    {     
       case  Error_None:
            return("No Error Active. System A-OK!\n");
            break;
        case  Error_No_I2CComm: 
            return("Failed to Open I2C Bus\n - Check Bus Number\n - Check SCL/SCA Lines\n" 
                   " - Check Device\n - Check Device Tree on BBB\n");
            break;
        case Error_No_I2CInit:
            return("Failed to Communicate With Slave Device\n - Check Bus Number\n - Check SCL/SCA Lines\n" 
                   " - Check Device Address\n - Check Device Tree on BBB\n");        
            break;            
        case Error_No_I2CBuffSet:
            return("Failed to Set Buffer Read Range\n - Check Bus Number\n - Check SCL/SCA Lines\n" 
                   " - Check Device Address\n - Check Device Tree on BBB\n");            
            break;
        case Error_No_I2CBuffRead:
            return("Failed to Read Data in Registry Buffer\n - Check Bus Number\n - Check SCL/SCA Lines\n" 
                   " - Check Device Address\n - Check Device Tree on BBB\n");
            break;
        case Error_No_I2CBuffSync:
            return("Failed to Validate Registry Data - Inconsistent Data Stream\n"
                    " - Check For Multiple Master Access to Slave Device on I2C Bus Number\n"
                    " - Check SCL/SCA Lines\n - Check Device Address\n - Check Device Tree on BBB\n");
            break;            
        case Error_No_I2CBuffWrite:
            return("Failed to Write Data to Device Registry\n - Check Bus Traffic/Interference\n"
                   " - Check Bus Number\n - Check SCL/SCA Lines\n - Check Device Address\n - Check Device Tree on BBB\n"); 
            break;        
        case Error_No_ParamOutofRange:
            return("Parameter Out Of Range\n - Check Block Parameter Input Options\n");
            break;        
        default:
            // Error -Return Default 
            return("Error Code Not Recognized\n");
            break;
                    
 
    }
}
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void BBB_Driver_Gyroscope_L3G4200D_Outputs_wrapper(real_T *outAngVel_X,
                          real_T *outAngVel_Y,
                          real_T *outAngVel_Z,
                          int8_T *outAmbTemp,
                          boolean_T *outSimStop ,
			      const real_T  *xD,
                          const uint8_T  *prmI2C_BusNo, const int_T  p_width0, 
                          const uint8_T  *prmI2C_DeviceNo, const int_T  p_width1, 
                          const uint8_T  *prmGyro_AngVelRange, const int_T  p_width2, 
                          const uint8_T  *prmDebug_InfoLevel, const int_T p_width3)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
// Define Output Data - Simulink
int iTst=0; 
// Run Only on Target - BeagleBoneBlack */
# ifndef MATLAB_MEX_FILE

// Define File Sys Pointer - For I2C Bus#1 -> Make Parameter
int iFILE_BBB_I2C_Handle=0;
int iIOCTL_BBB_I2C_Handle=0;
int iSYNC_BBB_I2C_Handle=0;
int iWrite_BBB_I2C_Handle=0;
// Function Outputs
int iI2C_Read=0;
int iI2C_Write=0;

//Define Device Driver sysfs Location 
// const char *sBBB_I2C_BUS1_FILE ="/dev/i2c-1";
// char *sBBB_I2C_BUS1_FILE ="/dev/i2c-";
char sBBB_I2C_BUS1_FILE[100]="";

// Define Internal Variables Data
int iGyro_AngVel_X=0;
int iGyro_AngVel_Y=0;
int iGyro_AngVel_Z=0;
int iGyro_AngVel_Temp=0;

// Declare Temporary Variables For Bit Manipulation
double dGyro_AngVel_Temp=0;

// Declare Variables For Device Registry Read/Write
unsigned char cI2C_StatReg_Temp=0;
 
// Define I2C Parameters
int iI2C_BytesRead=0;
// Define I2C Buffer Size
const int iI2C_BufferSize=48;
// Define I2C Buffer Dump Variable
char cI2C_Buffer[cGyro_I2C_BufferSize]={0x00}; //unsigned
// Define I2C Buffer Dump Start Position. Note: Value = Start Address w/ MSB Set To "1"
char cI2C_Buffer_Sync[1]={0x80}; // Start at reg 0x00
// Define Write Buffer
char cI2C_Buffer_Write[2]={0x00};
// Define I2C Buffer Status 
char cI2C_Buffer_Status=0;//unsigned
// Define I2C Status Bits: 
int iI2C_STATUS_REG_ZYXOR=0;  // Bit 7 - X,Y or Z Data Overwritten 
int iI2C_STATUS_REG_ZYXDA=0;  // Bit 3 - X,Y or Z New Data Available
// Define Loop Counters
int iLoop=0;
int iLoop_Counter;
// Define Device Address
char cGyro_I2C_Addr_Para=0x00;
char cGyro_I2C_Addr=0X00;

// Initialize Error
eError_No iError_No = Error_None;

// Initialize Error Level
eError_Level iError_Level = Error_Level_OK;

// Initialize Debug Output Level
// eDebugLevel iDebug_Level = Debug_Level_1;

/*
// Set Gyroscope Sensitivity Ratings
const double dGyro_Sens_250dps = 0.00875;
const double dGyro_Sens_500dps = 0.0175;
const double dGyro_Sens_2000dps = 0.075;
*/

// Define Angular Velocity Holder Variables For Data From Gyro Registry
int iAngVel_X_Flt=0;
int iAngVel_Y_Flt=0;
int iAngVel_Z_Flt=0;
double dAngVel_X_Flt=0;
double dAngVel_Y_Flt=0;
double dAngVel_Z_Flt=0;




// Define Function iGryro_I2CReadBuff
int iGryro_I2CReadBuff()
{
    
    // Create Handle to SYSFS File Stream
    sprintf(sBBB_I2C_BUS1_FILE,"/dev/i2c-%u",prmI2C_BusNo[0]);
    
    // Check I2C Bus Concatenation
    if (iDebug_Level >=Debug_Level_2)  { printf("Gyro Msg: I2C Bus File Location: %s\n",sBBB_I2C_BUS1_FILE); }
        
    // Open Data IO Stream
    iFILE_BBB_I2C_Handle = open(sBBB_I2C_BUS1_FILE, O_RDWR);
    
    // Confirm I2C Bus Open
    if (iFILE_BBB_I2C_Handle<0)
    {
        // Error Handling
        if (iDebug_Level >=Debug_Level_1)  { printf("Gyro Error: Failed to Open I2C Bus - Check Device/Device Tree\n"); }
        // Set Error Number
        iError_No = Error_No_I2CComm;
        // Set Error Level
        iError_Level = Error_Level_Critical;
        // Return Otuput Error Level
        // return -1;
    }
    
    // Ouput Program Flow
    if (iDebug_Level >=Debug_Level_3) {printf("Gyro Msg: Program Flow State 2: Connect To I2C Bus\nError No: %i Error Level: %i\n",iError_No, iError_Level);}
   
    // Initiate I2C Communicaton
    if (iError_No == Error_None)
    {
        // Initiate Communicaiton
        iIOCTL_BBB_I2C_Handle=ioctl(iFILE_BBB_I2C_Handle,I2C_SLAVE,cGyro_I2C_Addr);
        
        // Error Handling
        if (iIOCTL_BBB_I2C_Handle<0)
        {
            if (iDebug_Level >=Debug_Level_1) {printf("Gyro Error: Failed to Communicate With Slave Device\n");}
            // Set Error Number
            iError_No = Error_No_I2CInit;
            // Set Error Level
            iError_Level = Error_Level_Critical;
            // Return Otuput Error Level
            // return -1;            
        }
    }
    
   // Ouput Program Flow
    if (iDebug_Level >=Debug_Level_3) {printf("Gyro Msg: Program Flow State 3: Connect to I2C Device\nError No: %i Error Level: %i\n",iError_No, iError_Level);}

    // Set Buffer Read Range
    if (iError_No == Error_None)
    {
        iWrite_BBB_I2C_Handle = write(iFILE_BBB_I2C_Handle, cI2C_Buffer_Sync, 1);
        // Error Handling
        if (iWrite_BBB_I2C_Handle !=1)
        {
            // Error Handling
            if (iDebug_Level >=Debug_Level_1) { printf("Gyro Error: Failed to Communicate With Device and/or Set Buffer Read Range\n");}
            // Set Error Number
            iError_No = Error_No_I2CBuffSet;
            // Set Error Level
            iError_Level = Error_Level_Critical;
            // Return Otuput Error Level
            // return -1;
        }
        else
        {
            if (iDebug_Level >=Debug_Level_1) { printf("Gyro Msg: Buffer Range Set\n");}
        }
    }

    // Ouput Program Flow
    if (iDebug_Level >=Debug_Level_3) {printf("Gyro Msg: Program Flow State 4: Write to Device Registry\nError No: %i Error Level: %i\n",iError_No, iError_Level);}

    // Read Buffer Data
    if (iError_No == Error_None)
    {
        // Read and Store Registry Data in Buffer
        iI2C_BytesRead = read(iFILE_BBB_I2C_Handle,cI2C_Buffer,iI2C_BufferSize);
        // Close File
        close(iFILE_BBB_I2C_Handle); 
        
        // Error Handling - Confirm Buffer Size
        if (iI2C_BytesRead<0)
        {
            // Error on Buffer Read!
            if (iDebug_Level >=Debug_Level_1) { printf("Gyro Error: Failed to Read Device Register. Bytes Read: %i\n",iI2C_BytesRead );}
            // Set Error Number
            iError_No = Error_No_I2CBuffRead;
            // Set Error Level
            iError_Level = Error_Level_Critical;
            // Return Otuput Error Level
            // return -1;
        }
        else
        {
            // Registry Data Read!
            if (iDebug_Level >=Debug_Level_1) { printf("Gyro Msg: Device Register Read. Bytes Read: %i\n",iI2C_BytesRead );}
            
            // Confirm Data Synced
            if (cI2C_Buffer[cGyro_WhoAmIReg]!=cGyro_WhoAmI)
            {
                // Error on Buffer Sync!
                if (iDebug_Level >=Debug_Level_1) { printf("Gyro Error: Buffer Data Invalid! Who_Am_I != 0xD3: %#04x\n",cI2C_Buffer[cGyro_WhoAmIReg]);}
                // Set Error Number
                iError_No = Error_No_I2CBuffSync;
                // Set Error Level
                iError_Level = Error_Level_Critical;
                // Return Otuput Error Level
                // return -1;
            }
        }
    }    

    // Set Return State
    if (iError_No==0){return 0;} else {return -1;}


}

// Define Function iGryro_I2CWriteBuff
int iGryro_I2CWriteBuff(char cRegister_Address, char cRegister_Value)
{
   
    // Create Handle to SYSFS File Stream
    sprintf(sBBB_I2C_BUS1_FILE,"/dev/i2c-%u",prmI2C_BusNo[0]);
        
    // Check I2C Bus Concatenation
    if (iDebug_Level >=Debug_Level_2)  { printf("Gyro Msg: I2C Bus File Location: %s\n",sBBB_I2C_BUS1_FILE); }
    
    // Open Data IO Stream
    iFILE_BBB_I2C_Handle = open(sBBB_I2C_BUS1_FILE, O_RDWR);
    
    // Confirm I2C Bus Open
    if (iFILE_BBB_I2C_Handle<0)
    {
        // Error Handling
        if (iDebug_Level >=Debug_Level_1)  { printf("Gyro Error: Failed to Open I2C Bus - Check Device/Device Tree\n"); }
        // Set Error Number
        iError_No = Error_No_I2CComm;
        // Set Error Level
        iError_Level = Error_Level_Critical;
        // Return Otuput Error Level
        // return -1;
    }
    
    // Ouput Program Flow
    if (iDebug_Level >=Debug_Level_3) {printf("Gyro Msg: Program Flow State 2: Connect To I2C Bus\nError No: %i Error Level: %i\n",iError_No, iError_Level);}

    
    // Initiate I2C Communicaton
    if (iError_No == Error_None)
    {
        // Initiate Communicaiton
        iIOCTL_BBB_I2C_Handle=ioctl(iFILE_BBB_I2C_Handle,I2C_SLAVE,cGyro_I2C_Addr);

        // Error Handling
        if (iIOCTL_BBB_I2C_Handle<0)
        {
            if (iDebug_Level >=Debug_Level_1) {printf("Gyro Error: Failed to Communicate With Slave Device\n");}
            // Set Error Number
            iError_No = Error_No_I2CInit;
            // Set Error Level
            iError_Level = Error_Level_Critical;
            // Return Otuput Error Level
            // return -1;            
        }
    }

    // Ouput Program Flow
    if (iDebug_Level >=Debug_Level_3) {printf("Gyro Msg: Program Flow State 3: Connect to I2C Device\nError No: %i Error Level: %i\n",iError_No, iError_Level);}

    // Write Data to Register
    if (iError_No == Error_None)
    {

        // Set Gyro To Register Address!
        // Set Gyro Register Value
        cI2C_Buffer_Write[0]= cRegister_Address;//Address
        cI2C_Buffer_Write[1]= cRegister_Value;//Value
        iWrite_BBB_I2C_Handle = write(iFILE_BBB_I2C_Handle, cI2C_Buffer_Write, 2);
        if (iWrite_BBB_I2C_Handle!=2)
        {
            // Error Handling
            if (iDebug_Level >=Debug_Level_1) { printf("Gyro Error: Failed to Communicate With Device and/or Write To Device Register\n");}
            // Set Error Number
            iError_No = Error_No_I2CBuffWrite;
            // Set Error Level
            iError_Level = Error_Level_Critical;
            // Return Otuput Error Level
            // return -1;
        }
        else
        {
            // Power Mode Set
            if (iDebug_Level >=Debug_Level_1){printf("Gyro Msg: Data Written to Gyro Register!\n");}
        }
    }
    // Close File
    close(iFILE_BBB_I2C_Handle);
    
    // Set Return State
    if (iError_No==0){return 0;} else {return -1;} 
}    
               
////// MAIN PROGRAM START ///////


// Read Parameter Data -Device Number
switch(prmI2C_DeviceNo[0])
{
    case  1: //iAngVel_250dps:
        cGyro_I2C_Addr=cGyro_I2C_Addr1;
        break;
    case  2:
        cGyro_I2C_Addr=cGyro_I2C_Addr2;
        break;
    default:
        cGyro_I2C_Addr=0x00;
        break;
}

// Read Parameter Data -Device Number
switch(prmDebug_InfoLevel[0])
{
    case  1:
        iDebug_Level=Debug_None;
        break;
    case  2:
        iDebug_Level=Debug_Level_0;
        break;
    case  3:
        iDebug_Level=Debug_Level_1;
        break;
    case  4:
        iDebug_Level=Debug_Level_2;
        break;
    case  5:
        iDebug_Level=Debug_Level_3;
        break;
    case  6:
        iDebug_Level=Debug_Level_4;
        break;
    case  7:
        iDebug_Level=Debug_Level_5;
        break;       
    default:
        iDebug_Level=Debug_None;
        break;
}

// Start Line
if (iDebug_Level >=Debug_Level_0){printf("**** Start of Gyro S-Function Block Execution **** \n");}

// Check Parameters
if (iDebug_Level >=Debug_Level_1){printf("Gyro Msg: Input Parameter Data: I2CBus: %#04x I2CAddress: %#04x Range: %s",prmI2C_BusNo[0],cGyro_I2C_Addr,sGyro_SetRange(prmGyro_AngVelRange[0]));}

// Ouput Program Flow
if (iDebug_Level >=Debug_Level_3) {printf("Gyro Msg: Program Flow State 1: Parameters Initialized \nError No: %i Error Level: %i\n",iError_No, iError_Level);}

// Run Init Routines
if (xD[0]==0)
{
    // Set Gyro to Normal Mode
    iI2C_Write=iGryro_I2CWriteBuff(cGyro_CtrlReg1,cGyro_NormalMode);
    // Check For Error
    if (iI2C_Write<0)
    {
        // Error Handling
        if (iDebug_Level >=Debug_Level_1){printf("Gyro Error: Failed to Set Device Power Mode\n");}
    }
    else 
    {
        // Error Handling
        if (iDebug_Level >=Debug_Level_1){printf("Gyro Msg: Device Set to Power Mode\n");}
    }

    
    if (iError_No == Error_None)
    {
        // Set Measurement Range Based on Parameter Input
        if (iDebug_Level >=Debug_Level_1){printf("Gyro Msg: User Requested Measurement Range: %s",sGyro_SetRange(prmGyro_AngVelRange[0]));}
                
        if (prmGyro_AngVelRange[0]>3)
        {
            // Error Handling
            if (iDebug_Level >=Debug_Level_1){printf("Gyro Error: Requested Device Mesaurement Range Not Vaild!\n");}
            // Set Error Number
            iError_No = Error_No_ParamOutofRange;
            // Set Error Level
            iError_Level = Error_Level_Critical;
        }
        else
        {
            // Write User Selected Range To Gyro
            iI2C_Write=iGryro_I2CWriteBuff(cGyro_CtrlReg4,cGyro_SetRange(prmGyro_AngVelRange[0]));
            // Check For Error
            if (iI2C_Write<0)
            {
                // Error Handling
                if (iDebug_Level >=Debug_Level_1){printf("Gyro Error: Failed to Set Device Measurement Range\n");}
            }
            else
            {
                // Error Handling
                if (iDebug_Level >=Debug_Level_1){printf("Gyro Msg: Device Set to Requested Measurement Range\n");}
            }
        }
        
    }
    // Ouput Program Flow
    if (iDebug_Level >=Debug_Level_3) {printf("Gyro Msg: Program Flow State 1A: Init Routine Complete\nError No: %i Error Level: %i\n",iError_No, iError_Level);}

}
if (iError_No == Error_None)
{
    // Read Gyro Buffer
    iI2C_Read=iGryro_I2CReadBuff();
}
// Good To Go! Run Initialization Routine on First Timestep

// Read Gyro Data
if (iError_No == Error_None)
{
    // Read Data Status Registry 
    cI2C_StatReg_Temp=cI2C_Buffer[cGyrp_StatusReg];
    if (iDebug_Level >=Debug_Level_2){printf("Gyro Diagnostics: STATUS_REG 0x00: %#04x \n",cI2C_Buffer[cI2C_StatReg_Temp]);}
        
    // Check For Overwritten Data
    if (cI2C_StatReg_Temp &  0b10000000)
    {
        iI2C_STATUS_REG_ZYXOR=1;
    }

    // Check For New Data
    if (cI2C_StatReg_Temp &  0b00001000)
    {
        iI2C_STATUS_REG_ZYXDA=1;
    }

    if (iDebug_Level >=Debug_Level_2) {printf("Gyro Msg: Data Available: %i Data Overwritten %i\n",iI2C_STATUS_REG_ZYXDA,iI2C_STATUS_REG_ZYXOR);}
            
    // Read Angular Velocity Data As
    if (iI2C_STATUS_REG_ZYXDA!=0)
    {
        // Write Function to Read and Combine Buffer Data
        
        // Get X-Angular Velocity Data
        iGyro_AngVel_Temp = cI2C_Buffer[cAngVelReg_X_MSB];
        iGyro_AngVel_Temp = (iGyro_AngVel_Temp<<8) | cI2C_Buffer[cAngVelReg_X_LSB];
        if (iOpt_TwoComplement == true)
        {
            iGyro_AngVel_Temp = ~iGyro_AngVel_Temp + 1; // Calculate 2's complement
        }
        // Output MBS and LSB
        if (iDebug_Level >=Debug_Level_0){printf("Gyro Msg: X AngVel Register Values Read. MSB: %#04x ; LSB: %#04x \n",cI2C_Buffer[cAngVelReg_X_MSB],cI2C_Buffer[cAngVelReg_X_LSB]);}
        // Convert Int (Int32) to Int16
        iGyro_AngVel_Temp=(short)iGyro_AngVel_Temp;
        // Convert Int16 to Double
        dGyro_AngVel_Temp = (double)(iGyro_AngVel_Temp*dGyro_SetSens(prmGyro_AngVelRange[0]));        
        // Set Output!
        outAngVel_X[0]=dGyro_AngVel_Temp;

        // Get Y-Accel Data
        iGyro_AngVel_Temp = 0;
        iGyro_AngVel_Temp = cI2C_Buffer[cAngVelReg_Y_MSB];
        iGyro_AngVel_Temp = (iGyro_AngVel_Temp<<8) | cI2C_Buffer[cAngVelReg_Y_LSB];
        if (iOpt_TwoComplement == true)
        {
            iGyro_AngVel_Temp = ~iGyro_AngVel_Temp + 1; // Calculate 2's complement
        }
        // Output MBS and LSB
        if (iDebug_Level >=Debug_Level_0){printf("Gyro Msg: Y AngVel Register Values Read. MSB: %#04x ; LSB: %#04x \n",cI2C_Buffer[cAngVelReg_Y_MSB],cI2C_Buffer[cAngVelReg_Y_LSB]);}
        // Convert Int (Int32) to Int16
        iGyro_AngVel_Temp=(short)iGyro_AngVel_Temp;
        // Convert Int16 to Double
        dGyro_AngVel_Temp = (double)(iGyro_AngVel_Temp*dGyro_SetSens(prmGyro_AngVelRange[0]));        
        // Set Output!
        outAngVel_Y[0]=dGyro_AngVel_Temp;

        // Get Z-Accel Data
        iGyro_AngVel_Temp = 0;
        iGyro_AngVel_Temp = cI2C_Buffer[cAngVelReg_Z_MSB];
        iGyro_AngVel_Temp = (iGyro_AngVel_Temp<<8) | cI2C_Buffer[cAngVelReg_Z_LSB];
        if (iOpt_TwoComplement == true)
        {
            iGyro_AngVel_Temp = ~iGyro_AngVel_Temp + 1; // Calculate 2's complement
        }
        // Output MBS and LSB
        if (iDebug_Level >=Debug_Level_0){printf("Gyro Msg: Z AngVel Register Values Read. MSB: %#04x ; LSB: %#04x \n",cI2C_Buffer[cAngVelReg_Z_MSB],cI2C_Buffer[cAngVelReg_Z_LSB]);}
        // Convert Int (Int32) to Int16
        iGyro_AngVel_Temp=(short)iGyro_AngVel_Temp;
        // Convert Int16 to Double
        dGyro_AngVel_Temp = (double)(iGyro_AngVel_Temp*dGyro_SetSens(prmGyro_AngVelRange[0]));        
        // Set Output!
        outAngVel_Z[0]=dGyro_AngVel_Temp;     
                
        // Get Temperature
        outAmbTemp[0]=cI2C_Buffer[cAmbTempReg];
        
        // Ouput Program Flow
        if (iDebug_Level >=Debug_Level_3) {printf("Gyro Msg: Program Flow State 5: Device Data Read\nError No: %i Error Level: %i\n",iError_No, iError_Level);}
        
        // Print Output
        if (iDebug_Level >=Debug_Level_0){printf("Gyro Msg: Angular Vel  X: %f Y: %f Z: %f \n",outAngVel_X[0],outAngVel_Y[0],outAngVel_Z[0]);}
        
        // Print Registry Data
        if (iDebug_Level >=Debug_Level_4)
        {
        
            // Print Select Registry Data
            printf("Gyro Diagnostics: WHO_AM_I 0x00: %#04x \n",cI2C_Buffer[0x0f]);
            printf("Gyro Diagnostics: CTRL_REG1 0x00: %#04x \n",cI2C_Buffer[0x20]);
            printf("Gyro Diagnostics: CTRL_REG2 0x00: %#04x \n",cI2C_Buffer[0x21]);
            printf("Gyro Diagnostics: CTRL_REG3 0x00: %#04x \n",cI2C_Buffer[0x22]);
            printf("Gyro Diagnostics: CTRL_REG4 0x00: %#04x \n",cI2C_Buffer[0x23]);
            printf("Gyro Diagnostics: CTRL_REG5 0x00: %#04x \n",cI2C_Buffer[0x24]);
            // Test
            for ( iLoop=0; iLoop<iI2C_BufferSize; iLoop++)
            {
                printf("Gyro Diagnostics: Data: Address %#04x = %#04x \n", iLoop, cI2C_Buffer[iLoop]);
            }
        }
        if (iI2C_STATUS_REG_ZYXOR==1)
        {
            if (iDebug_Level >=Debug_Level_0){printf("Gyro Msg: Read Rate Too Slow. Data Overwritten\n");}
        }
        
    }
    else
    {
        if (iDebug_Level >=Debug_Level_0){printf("Gyro Msg: No New Data Available\n");}
        
    }
}
// Ouput Program Flow
if (iDebug_Level >=Debug_Level_3) {printf("Gyro Msg: Program Flow State 6: Loop Step Complete\nError No: %i Error Level: %i\n",iError_No, iError_Level);}

// Check For Critical Errors and Stop Simulation  
if ((iError_No!=0)&&(iError_Level==Error_Level_Critical))
{
    
    // Stop Simulation If Critical Error
    if (iDebug_Level >=Debug_Level_0) {printf("Gyro Msg: Critical Error Detected; Simulation Stopping! \nError No: %i Error Level: %i\n",iError_No, iError_Level);}
    
    // Output Error Message:
    if (iDebug_Level >=Debug_Level_0) {printf("Gyro Error Details: %s",sGyro_ErrMessage(iError_No));}
    

    // Stop Simulation
    outSimStop[0]=true;
}
else
{
    // Carry on
    outSimStop[0]=false;
}

# else
# endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void BBB_Driver_Gyroscope_L3G4200D_Update_wrapper(const real_T *outAngVel_X,
                          const real_T *outAngVel_Y,
                          const real_T *outAngVel_Z,
                          const int8_T *outAmbTemp,
                          const boolean_T *outSimStop ,
                          real_T *xD, 
                          const uint8_T  *prmI2C_BusNo,  const int_T  p_width0,
                          const uint8_T  *prmI2C_DeviceNo,  const int_T  p_width1,
                          const uint8_T  *prmGyro_AngVelRange,  const int_T  p_width2,
                           const uint8_T *prmDebug_InfoLevel, const int_T  p_width3)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
// Run Only on Target - BeagleBoneBlack */
# ifndef MATLAB_MEX_FILE

// Update Init Bit
if (xD[0]==0)
{
    // Set Init Complete 
    xD[0]=1; 
    
    // Output Update Compete
    if (iDebug_Level >=Debug_Level_1){printf("Gyro Msg: Program Flow State 6A: Init First Scan Complete\n");}
    
    //exit(EXIT_SUCCESS);
    //ssSetStopRequested(S, 1);
    //set_param(bdroot, 'SimulationCommand', 'stop');
}

// Print Gap
if (iDebug_Level >=Debug_Level_0){printf("\n");}
 

# else

// Do Nothing


#endif
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}