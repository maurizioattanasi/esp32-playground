set(SOURCES main.cpp 
    driver/driver.cpp 
    agpio/gpio_input.cpp 
    agpio/gpio_output.cpp)

idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS . ../include/driver ../include/agpio)