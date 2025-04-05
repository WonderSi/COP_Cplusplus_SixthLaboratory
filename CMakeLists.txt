cmake_minimum_required(VERSION 3.27)
project(COP_Cplusplus_SixthLaboratory)

set(CMAKE_CXX_STANDARD 23)

set(SOURCES_COMMON
        src/GUIDs.cpp
        src/create.cpp
)

# Компонент 1 (поддерживает IX)
add_library(cmpnt1 SHARED src/cmpnt1.cpp ${SOURCES_COMMON})

# Компонент 2 (поддерживает IX и IY)
add_library(cmpnt2 SHARED src/cmpnt2.cpp ${SOURCES_COMMON})

# Компонент 3 (поддерживает IX, IY и IZ)
add_library(cmpnt3 SHARED src/cmpnt3.cpp ${SOURCES_COMMON})

# Клиент 1 (использует IX)
add_executable(client1 src/client1.cpp ${SOURCES_COMMON})

# Клиент 2 (использует IX и IY)
add_executable(client2 src/client2.cpp ${SOURCES_COMMON})

# Клиент 3 (использует IX, IY и IZ)
add_executable(client3 src/client3.cpp ${SOURCES_COMMON})

# Линковка клиентов с соответствующими компонентами
target_link_libraries(client1 cmpnt1)
target_link_libraries(client2 cmpnt2)
target_link_libraries(client3 cmpnt3)
