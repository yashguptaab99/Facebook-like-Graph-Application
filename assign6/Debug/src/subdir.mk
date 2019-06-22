################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/assign6.cpp \
../src/facebook.cpp \
../src/graph.cpp \
../src/queue.cpp \
../src/stack.cpp 

OBJS += \
./src/assign6.o \
./src/facebook.o \
./src/graph.o \
./src/queue.o \
./src/stack.o 

CPP_DEPS += \
./src/assign6.d \
./src/facebook.d \
./src/graph.d \
./src/queue.d \
./src/stack.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


