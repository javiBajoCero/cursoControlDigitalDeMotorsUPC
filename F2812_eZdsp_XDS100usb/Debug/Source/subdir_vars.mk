################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../Source/DSP281x_CodeStartBranch.asm \
../Source/DSP281x_DBGIER.asm \
../Source/DSP281x_usDelay.asm 

C_SRCS += \
../Source/DAC.c \
../Source/DSP281x_Adc.c \
../Source/DSP281x_CpuTimers.c \
../Source/DSP281x_DefaultIsr.c \
../Source/DSP281x_ECan.c \
../Source/DSP281x_Ev.c \
../Source/DSP281x_GlobalVariableDefs.c \
../Source/DSP281x_Gpio.c \
../Source/DSP281x_InitPeripherals.c \
../Source/DSP281x_Mcbsp.c \
../Source/DSP281x_MemCopy.c \
../Source/DSP281x_PieCtrl.c \
../Source/DSP281x_PieVect.c \
../Source/DSP281x_Sci.c \
../Source/DSP281x_Spi.c \
../Source/DSP281x_SysCtrl.c \
../Source/DSP281x_XIntrupt.c \
../Source/DSP281x_Xintf.c \
../Source/Dec_Ini_Vars.c \
../Source/Funciones_Extres.c \
../Source/Interrupt_Timer0.c \
../Source/interruptsADC.c \
../Source/main.c 

C_DEPS += \
./Source/DAC.d \
./Source/DSP281x_Adc.d \
./Source/DSP281x_CpuTimers.d \
./Source/DSP281x_DefaultIsr.d \
./Source/DSP281x_ECan.d \
./Source/DSP281x_Ev.d \
./Source/DSP281x_GlobalVariableDefs.d \
./Source/DSP281x_Gpio.d \
./Source/DSP281x_InitPeripherals.d \
./Source/DSP281x_Mcbsp.d \
./Source/DSP281x_MemCopy.d \
./Source/DSP281x_PieCtrl.d \
./Source/DSP281x_PieVect.d \
./Source/DSP281x_Sci.d \
./Source/DSP281x_Spi.d \
./Source/DSP281x_SysCtrl.d \
./Source/DSP281x_XIntrupt.d \
./Source/DSP281x_Xintf.d \
./Source/Dec_Ini_Vars.d \
./Source/Funciones_Extres.d \
./Source/Interrupt_Timer0.d \
./Source/interruptsADC.d \
./Source/main.d 

OBJS += \
./Source/DAC.obj \
./Source/DSP281x_Adc.obj \
./Source/DSP281x_CodeStartBranch.obj \
./Source/DSP281x_CpuTimers.obj \
./Source/DSP281x_DBGIER.obj \
./Source/DSP281x_DefaultIsr.obj \
./Source/DSP281x_ECan.obj \
./Source/DSP281x_Ev.obj \
./Source/DSP281x_GlobalVariableDefs.obj \
./Source/DSP281x_Gpio.obj \
./Source/DSP281x_InitPeripherals.obj \
./Source/DSP281x_Mcbsp.obj \
./Source/DSP281x_MemCopy.obj \
./Source/DSP281x_PieCtrl.obj \
./Source/DSP281x_PieVect.obj \
./Source/DSP281x_Sci.obj \
./Source/DSP281x_Spi.obj \
./Source/DSP281x_SysCtrl.obj \
./Source/DSP281x_XIntrupt.obj \
./Source/DSP281x_Xintf.obj \
./Source/DSP281x_usDelay.obj \
./Source/Dec_Ini_Vars.obj \
./Source/Funciones_Extres.obj \
./Source/Interrupt_Timer0.obj \
./Source/interruptsADC.obj \
./Source/main.obj 

ASM_DEPS += \
./Source/DSP281x_CodeStartBranch.d \
./Source/DSP281x_DBGIER.d \
./Source/DSP281x_usDelay.d 

OBJS__QUOTED += \
"Source\DAC.obj" \
"Source\DSP281x_Adc.obj" \
"Source\DSP281x_CodeStartBranch.obj" \
"Source\DSP281x_CpuTimers.obj" \
"Source\DSP281x_DBGIER.obj" \
"Source\DSP281x_DefaultIsr.obj" \
"Source\DSP281x_ECan.obj" \
"Source\DSP281x_Ev.obj" \
"Source\DSP281x_GlobalVariableDefs.obj" \
"Source\DSP281x_Gpio.obj" \
"Source\DSP281x_InitPeripherals.obj" \
"Source\DSP281x_Mcbsp.obj" \
"Source\DSP281x_MemCopy.obj" \
"Source\DSP281x_PieCtrl.obj" \
"Source\DSP281x_PieVect.obj" \
"Source\DSP281x_Sci.obj" \
"Source\DSP281x_Spi.obj" \
"Source\DSP281x_SysCtrl.obj" \
"Source\DSP281x_XIntrupt.obj" \
"Source\DSP281x_Xintf.obj" \
"Source\DSP281x_usDelay.obj" \
"Source\Dec_Ini_Vars.obj" \
"Source\Funciones_Extres.obj" \
"Source\Interrupt_Timer0.obj" \
"Source\interruptsADC.obj" \
"Source\main.obj" 

C_DEPS__QUOTED += \
"Source\DAC.d" \
"Source\DSP281x_Adc.d" \
"Source\DSP281x_CpuTimers.d" \
"Source\DSP281x_DefaultIsr.d" \
"Source\DSP281x_ECan.d" \
"Source\DSP281x_Ev.d" \
"Source\DSP281x_GlobalVariableDefs.d" \
"Source\DSP281x_Gpio.d" \
"Source\DSP281x_InitPeripherals.d" \
"Source\DSP281x_Mcbsp.d" \
"Source\DSP281x_MemCopy.d" \
"Source\DSP281x_PieCtrl.d" \
"Source\DSP281x_PieVect.d" \
"Source\DSP281x_Sci.d" \
"Source\DSP281x_Spi.d" \
"Source\DSP281x_SysCtrl.d" \
"Source\DSP281x_XIntrupt.d" \
"Source\DSP281x_Xintf.d" \
"Source\Dec_Ini_Vars.d" \
"Source\Funciones_Extres.d" \
"Source\Interrupt_Timer0.d" \
"Source\interruptsADC.d" \
"Source\main.d" 

ASM_DEPS__QUOTED += \
"Source\DSP281x_CodeStartBranch.d" \
"Source\DSP281x_DBGIER.d" \
"Source\DSP281x_usDelay.d" 

C_SRCS__QUOTED += \
"../Source/DAC.c" \
"../Source/DSP281x_Adc.c" \
"../Source/DSP281x_CpuTimers.c" \
"../Source/DSP281x_DefaultIsr.c" \
"../Source/DSP281x_ECan.c" \
"../Source/DSP281x_Ev.c" \
"../Source/DSP281x_GlobalVariableDefs.c" \
"../Source/DSP281x_Gpio.c" \
"../Source/DSP281x_InitPeripherals.c" \
"../Source/DSP281x_Mcbsp.c" \
"../Source/DSP281x_MemCopy.c" \
"../Source/DSP281x_PieCtrl.c" \
"../Source/DSP281x_PieVect.c" \
"../Source/DSP281x_Sci.c" \
"../Source/DSP281x_Spi.c" \
"../Source/DSP281x_SysCtrl.c" \
"../Source/DSP281x_XIntrupt.c" \
"../Source/DSP281x_Xintf.c" \
"../Source/Dec_Ini_Vars.c" \
"../Source/Funciones_Extres.c" \
"../Source/Interrupt_Timer0.c" \
"../Source/interruptsADC.c" \
"../Source/main.c" 

ASM_SRCS__QUOTED += \
"../Source/DSP281x_CodeStartBranch.asm" \
"../Source/DSP281x_DBGIER.asm" \
"../Source/DSP281x_usDelay.asm" 


