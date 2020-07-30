################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Linked_list/sorting/sort_while_inserting_data.c 

OBJS += \
./Linked_list/sorting/sort_while_inserting_data.o 

C_DEPS += \
./Linked_list/sorting/sort_while_inserting_data.d 


# Each subdirectory must supply rules for building sources it contributes
Linked_list/sorting/%.o: ../Linked_list/sorting/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


