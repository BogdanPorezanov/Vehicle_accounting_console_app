cmake_minimum_required (VERSION 3.8)

project ("Vehicle_accounting_console_app")

file(GLOB 
		CPPS "src/*.cpp"
		CS "src/*.c")

include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable (${PROJECT_NAME} ${CPPS} ${CS})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Vehicle_accounting_console_app PROPERTY CXX_STANDARD 17)
endif()
