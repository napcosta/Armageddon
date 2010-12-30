################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/App.cpp \
../src/BEVCamera.cpp \
../src/Controller.cpp \
../src/Hero.cpp \
../src/Particle.cpp \
../src/ParticleManager.cpp \
../src/PhysicalEntity.cpp \
../src/main.cpp 

OBJS += \
./src/App.o \
./src/BEVCamera.o \
./src/Controller.o \
./src/Hero.o \
./src/Particle.o \
./src/ParticleManager.o \
./src/PhysicalEntity.o \
./src/main.o 

CPP_DEPS += \
./src/App.d \
./src/BEVCamera.d \
./src/Controller.d \
./src/Hero.d \
./src/Particle.d \
./src/ParticleManager.d \
./src/PhysicalEntity.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/pinto/workspace/cglib/src" -O0 -g3 -pedantic -pedantic-errors -Wall -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


