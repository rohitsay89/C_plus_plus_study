################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Linked_list/compare_list.c \
../Linked_list/delete_node_list.c \
../Linked_list/double_list1.c \
../Linked_list/insert_beg.c \
../Linked_list/insert_end.c \
../Linked_list/nth_list.c \
../Linked_list/print_rev.c \
../Linked_list/reverse_list.c \
../Linked_list/stack_2.c \
../Linked_list/stack_3_linklist.c \
../Linked_list/stack_array.c \
../Linked_list/stack_basic_list.c 

OBJS += \
./Linked_list/compare_list.o \
./Linked_list/delete_node_list.o \
./Linked_list/double_list1.o \
./Linked_list/insert_beg.o \
./Linked_list/insert_end.o \
./Linked_list/nth_list.o \
./Linked_list/print_rev.o \
./Linked_list/reverse_list.o \
./Linked_list/stack_2.o \
./Linked_list/stack_3_linklist.o \
./Linked_list/stack_array.o \
./Linked_list/stack_basic_list.o 

C_DEPS += \
./Linked_list/compare_list.d \
./Linked_list/delete_node_list.d \
./Linked_list/double_list1.d \
./Linked_list/insert_beg.d \
./Linked_list/insert_end.d \
./Linked_list/nth_list.d \
./Linked_list/print_rev.d \
./Linked_list/reverse_list.d \
./Linked_list/stack_2.d \
./Linked_list/stack_3_linklist.d \
./Linked_list/stack_array.d \
./Linked_list/stack_basic_list.d 


# Each subdirectory must supply rules for building sources it contributes
Linked_list/%.o: ../Linked_list/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


