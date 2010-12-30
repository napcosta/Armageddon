################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/cg/Application.cpp \
../src/cg/DebugFile.cpp \
../src/cg/DebugNotifier.cpp \
../src/cg/DrawNotifier.cpp \
../src/cg/DrawOverlayNotifier.cpp \
../src/cg/Group.cpp \
../src/cg/KeyBuffer.cpp \
../src/cg/KeyboardEventNotifier.cpp \
../src/cg/Manager.cpp \
../src/cg/MouseEventNotifier.cpp \
../src/cg/Properties.cpp \
../src/cg/Registry.cpp \
../src/cg/ReshapeEventNotifier.cpp \
../src/cg/UpdateNotifier.cpp \
../src/cg/Util.cpp 

OBJS += \
./src/cg/Application.o \
./src/cg/DebugFile.o \
./src/cg/DebugNotifier.o \
./src/cg/DrawNotifier.o \
./src/cg/DrawOverlayNotifier.o \
./src/cg/Group.o \
./src/cg/KeyBuffer.o \
./src/cg/KeyboardEventNotifier.o \
./src/cg/Manager.o \
./src/cg/MouseEventNotifier.o \
./src/cg/Properties.o \
./src/cg/Registry.o \
./src/cg/ReshapeEventNotifier.o \
./src/cg/UpdateNotifier.o \
./src/cg/Util.o 

CPP_DEPS += \
./src/cg/Application.d \
./src/cg/DebugFile.d \
./src/cg/DebugNotifier.d \
./src/cg/DrawNotifier.d \
./src/cg/DrawOverlayNotifier.d \
./src/cg/Group.d \
./src/cg/KeyBuffer.d \
./src/cg/KeyboardEventNotifier.d \
./src/cg/Manager.d \
./src/cg/MouseEventNotifier.d \
./src/cg/Properties.d \
./src/cg/Registry.d \
./src/cg/ReshapeEventNotifier.d \
./src/cg/UpdateNotifier.d \
./src/cg/Util.d 


# Each subdirectory must supply rules for building sources it contributes
src/cg/%.o: ../src/cg/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -pedantic -pedantic-errors -Wall -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


