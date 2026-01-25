################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/30010_io.c \
../Src/Stopwatch.c \
../Src/asteroids.c \
../Src/charset.c \
../Src/draw.c \
../Src/gui_hud.c \
../Src/joystick.c \
../Src/lcd.c \
../Src/main.c \
../Src/rgbled.c \
../Src/spaceship.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32f30x.c 

OBJS += \
./Src/30010_io.o \
./Src/Stopwatch.o \
./Src/asteroids.o \
./Src/charset.o \
./Src/draw.o \
./Src/gui_hud.o \
./Src/joystick.o \
./Src/lcd.o \
./Src/main.o \
./Src/rgbled.o \
./Src/spaceship.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32f30x.o 

C_DEPS += \
./Src/30010_io.d \
./Src/Stopwatch.d \
./Src/asteroids.d \
./Src/charset.d \
./Src/draw.d \
./Src/gui_hud.d \
./Src/joystick.d \
./Src/lcd.d \
./Src/main.d \
./Src/rgbled.d \
./Src/spaceship.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32f30x.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F302R8Tx -DSTM32F3 -DNUCLEO_F302R8 -DDEBUG -DUSE_STDPERIPH_DRIVER=1 -c -I"C:/Users/chris/OneDrive/DTU/Semester 1/Programmeringsprojekt/Spil Filmappe/Game/30010_game_grp7/SPL/inc" -I"C:/Users/chris/OneDrive/DTU/Semester 1/Programmeringsprojekt/Spil Filmappe/Game/30010_game_grp7/Inc" -I"C:/Users/chris/OneDrive/DTU/Semester 1/Programmeringsprojekt/Spil Filmappe/Game/30010_game_grp7/cmsis" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/30010_io.d ./Src/30010_io.o ./Src/Stopwatch.d ./Src/Stopwatch.o ./Src/asteroids.d ./Src/asteroids.o ./Src/charset.d ./Src/charset.o ./Src/draw.d ./Src/draw.o ./Src/gui_hud.d ./Src/gui_hud.o ./Src/joystick.d ./Src/joystick.o ./Src/lcd.d ./Src/lcd.o ./Src/main.d ./Src/main.o ./Src/rgbled.d ./Src/rgbled.o ./Src/spaceship.d ./Src/spaceship.o ./Src/syscalls.d ./Src/syscalls.o ./Src/sysmem.d ./Src/sysmem.o ./Src/system_stm32f30x.d ./Src/system_stm32f30x.o

.PHONY: clean-Src

