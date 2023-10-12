cmake_minimum_required(VERSION 3.0)

project(Libft)

# Set compiler
set(CMAKE_C_COMPILER gcc)

# Set C flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")

# Set source and object directories
set(SRC_DIR "${CMAKE_SOURCE_DIR}/srcs/")
set(OBJ_DIR "${CMAKE_BINARY_DIR}/obj/")

# List of source files
set(SRC_FILES
		ft_atoi.c
		ft_isprint.c
		ft_putchar_fd.c
		ft_strdup.c
		ft_strnstr.c
		ft_bzero.c
		ft_itoa.c
		ft_putendl_fd.c
		ft_striteri.c
		ft_strrchr.c
		ft_calloc.c
		ft_memchr.c
		ft_putnbr_fd.c
		ft_strjoin.c
		ft_strtrim.c
		ft_isalnum.c
		ft_memcmp.c
		ft_putstr_fd.c
		ft_strlcpy.c
		ft_substr.c
		ft_isalpha.c
		ft_memcpy.c
		ft_split.c
		ft_strlen.c
		ft_tolower.c
		ft_isascii.c
		ft_memmove.c
		ft_strcat.c
		ft_strmapi.c
		ft_toupper.c
		ft_isdigit.c
		ft_memset.c
		ft_strchr.c
		ft_strncmp.c
		main.c
)

# List of object files
set(OBJ_FILES)
foreach(SRC_FILE ${SRC_FILES})
    get_filename_component(OBJ_NAME ${SRC_FILE} NAME_WE)
    list(APPEND OBJ_FILES "${OBJ_NAME}.o")
endforeach()

# Include directories
include_directories(includes)

# Create an object library
add_library(objlib OBJECT ${SRC_FILES})
set_property(TARGET objlib PROPERTY POSITION_INDEPENDENT_CODE 1)

# Create the executable
add_executable(${PROJECT_NAME} $<TARGET_OBJECTS:objlib>)

# Set the output directory for object files
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OBJ_DIR})

# Re rule
add_custom_target(re
    COMMAND ${CMAKE_COMMAND} -E remove -f ${PROJECT_NAME}
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${OBJ_DIR}
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR}
)

# Set the default target to be "all" (equivalent to "make all")
add_custom_target(all DEPENDS ${PROJECT_NAME})

# Define the order in which targets are built
add_dependencies(${PROJECT_NAME} objlib)

# Define a phony target (equivalent to ".PHONY" in Makefile)
add_custom_target(all_phony ALL DEPENDS all)
add_custom_target(clean_phony ALL DEPENDS clean)
add_custom_target(fclean_phony ALL DEPENDS fclean)
add_custom_target(re_phony ALL DEPENDS re)
