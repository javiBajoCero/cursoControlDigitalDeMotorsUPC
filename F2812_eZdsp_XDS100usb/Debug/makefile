################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./Source/DAC.obj" \
"./Source/DSP281x_Adc.obj" \
"./Source/DSP281x_CodeStartBranch.obj" \
"./Source/DSP281x_CpuTimers.obj" \
"./Source/DSP281x_DBGIER.obj" \
"./Source/DSP281x_DefaultIsr.obj" \
"./Source/DSP281x_ECan.obj" \
"./Source/DSP281x_Ev.obj" \
"./Source/DSP281x_GlobalVariableDefs.obj" \
"./Source/DSP281x_Gpio.obj" \
"./Source/DSP281x_InitPeripherals.obj" \
"./Source/DSP281x_Mcbsp.obj" \
"./Source/DSP281x_MemCopy.obj" \
"./Source/DSP281x_PieCtrl.obj" \
"./Source/DSP281x_PieVect.obj" \
"./Source/DSP281x_Sci.obj" \
"./Source/DSP281x_Spi.obj" \
"./Source/DSP281x_SysCtrl.obj" \
"./Source/DSP281x_XIntrupt.obj" \
"./Source/DSP281x_Xintf.obj" \
"./Source/DSP281x_usDelay.obj" \
"./Source/Dec_Ini_Vars.obj" \
"./Source/main.obj" \
"../Linker command files/DSP281x_Headers_nonBIOS.cmd" \
"../Linker command files/F2812_EzDSP_RAM_lnk.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include Linker\ command\ files/subdir_vars.mk
-include Source/subdir_vars.mk
-include Linker\ command\ files/subdir_rules.mk
-include Source/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
F2812_eZdsp_XDS100usb.out \

EXE_OUTPUTS__QUOTED += \
"F2812_eZdsp_XDS100usb.out" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "F2812_eZdsp_XDS100usb.out"

# Tool invocations
F2812_eZdsp_XDS100usb.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi -z -m"F2812_eZdsp_XDS100usb.map" --stack_size=0x400 --warn_sections -i"C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/lib" -i"C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --reread_libs --diag_wrap=off --display_error_number --xml_link_info="F2812_eZdsp_XDS100usb_linkInfo.xml" --rom_model -o "F2812_eZdsp_XDS100usb.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "Source\DAC.obj" "Source\DSP281x_Adc.obj" "Source\DSP281x_CodeStartBranch.obj" "Source\DSP281x_CpuTimers.obj" "Source\DSP281x_DBGIER.obj" "Source\DSP281x_DefaultIsr.obj" "Source\DSP281x_ECan.obj" "Source\DSP281x_Ev.obj" "Source\DSP281x_GlobalVariableDefs.obj" "Source\DSP281x_Gpio.obj" "Source\DSP281x_InitPeripherals.obj" "Source\DSP281x_Mcbsp.obj" "Source\DSP281x_MemCopy.obj" "Source\DSP281x_PieCtrl.obj" "Source\DSP281x_PieVect.obj" "Source\DSP281x_Sci.obj" "Source\DSP281x_Spi.obj" "Source\DSP281x_SysCtrl.obj" "Source\DSP281x_XIntrupt.obj" "Source\DSP281x_Xintf.obj" "Source\DSP281x_usDelay.obj" "Source\Dec_Ini_Vars.obj" "Source\main.obj" 
	-$(RM) "Source\DAC.d" "Source\DSP281x_Adc.d" "Source\DSP281x_CpuTimers.d" "Source\DSP281x_DefaultIsr.d" "Source\DSP281x_ECan.d" "Source\DSP281x_Ev.d" "Source\DSP281x_GlobalVariableDefs.d" "Source\DSP281x_Gpio.d" "Source\DSP281x_InitPeripherals.d" "Source\DSP281x_Mcbsp.d" "Source\DSP281x_MemCopy.d" "Source\DSP281x_PieCtrl.d" "Source\DSP281x_PieVect.d" "Source\DSP281x_Sci.d" "Source\DSP281x_Spi.d" "Source\DSP281x_SysCtrl.d" "Source\DSP281x_XIntrupt.d" "Source\DSP281x_Xintf.d" "Source\Dec_Ini_Vars.d" "Source\main.d" 
	-$(RM) "Source\DSP281x_CodeStartBranch.d" "Source\DSP281x_DBGIER.d" "Source\DSP281x_usDelay.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

