#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Build System for Multi-Platform Embedded Application
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      %.i              - Generate preprocessed output of all C source files
#      %.s              - Generate assembly output of all C source files
#      %.o              - Generate object files for all C source files
#      compile-all      - Compile all source files into object files without linking
#      build            - Compile all source files and link them into a final executable
#      clean            - Remove all generated files including object files, preprocessed outputs, 
#                         assembly outputs, executable files, and map files
#
# Platform Overrides:
#      PLATFORM=HOST    - Use the native GCC compiler to build for the host environment
#      PLATFORM=MSP432  - Use the cross-compiler (arm-none-eabi-gcc) to build for the MSP432 microcontroller
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM ?= HOST

# Architecture Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = -mcpu=cortex-m4
ARCH = -mthumb -march=armv7e-m
FLOAT_ABI = -mfloat-abi=hard
FPU = -mfpu=fpv4-sp-d16
SPECS = --specs=nosys.specs

# Compiler Flags and Defines
ifeq ($(PLATFORM), HOST)
    CC = gcc
    LD = gcc
    CFLAGS = -Wall -Werror -g -O0 -std=c99
    CPPFLAGS = -DHOST
    LDFLAGS =
    SIZE = size
else ifeq ($(PLATFORM), MSP432)
    CC = arm-none-eabi-gcc
    LD = arm-none-eabi-ld
    CFLAGS = -Wall -Werror -g -O0 -std=c99 $(CPU) $(ARCH) $(FLOAT_ABI) $(FPU)
    CPPFLAGS = -DMSP432
    LDFLAGS = -T $(LINKER_FILE) $(SPECS)
    SIZE = arm-none-eabi-size
endif

# Define objects
OBJECTS = $(SOURCES:.c=.o)

# General targets
.PHONY: compile-all build clean

compile-all: $(OBJECTS)

build: compile-all
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) -o c1m2.out
	$(SIZE) c1m2.out

clean:
	rm -f src/*.o src/*.i src/*.s *.map *.out

# Rules for generating preprocessed, assembly, and object files
%.i: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -E $< -o $@

%.s: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -S $< -o $@

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -c $< -o $@


