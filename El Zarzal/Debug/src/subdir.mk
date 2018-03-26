################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BstreeStudent.cpp \
../src/Colapreferencias.cpp \
../src/CompareStudent.cpp \
../src/EDI.cpp \
../src/Grado.cpp \
../src/ListaAdmitidos.cpp \
../src/ListaEstudiantes.cpp \
../src/Pruebas.cpp \
../src/Titulaciones.cpp \
../src/Universidad.cpp \
../src/student.cpp 

OBJS += \
./src/BstreeStudent.o \
./src/Colapreferencias.o \
./src/CompareStudent.o \
./src/EDI.o \
./src/Grado.o \
./src/ListaAdmitidos.o \
./src/ListaEstudiantes.o \
./src/Pruebas.o \
./src/Titulaciones.o \
./src/Universidad.o \
./src/student.o 

CPP_DEPS += \
./src/BstreeStudent.d \
./src/Colapreferencias.d \
./src/CompareStudent.d \
./src/EDI.d \
./src/Grado.d \
./src/ListaAdmitidos.d \
./src/ListaEstudiantes.d \
./src/Pruebas.d \
./src/Titulaciones.d \
./src/Universidad.d \
./src/student.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


