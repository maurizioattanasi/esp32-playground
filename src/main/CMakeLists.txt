# idf_component_register(SRCS "main.cpp"
#                     INCLUDE_DIRS ".")

set(COMPONENT_SRCS 
    "../components/driver/driver.cpp"
    "main.cpp")
set(COMPONENT_ADD_INCLUDEDIRS 
    "../components/driver"
    ".")
                 
register_component()