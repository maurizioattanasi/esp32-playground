set(SOURCES main.cpp driver/driver.cpp)
idf_component_register(SRCS ${SOURCES}
                    INCLUDE_DIRS . ../include/driver)