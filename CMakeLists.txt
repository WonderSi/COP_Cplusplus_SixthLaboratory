cmake_minimum_required(VERSION 3.27)
project(COP_Cplusplus_SixthLaboratory)

set(CMAKE_CXX_STANDARD 23)

set(SOURCES_COMMON      # Создаёт переменную SOURCES_COMMON, содержащую следующие файлы
        src/GUIDs.cpp   # Определение GUID для COM-интерфейсов.
        src/create.cpp  # Функция CallCreateInstance для загрузки DLL
)

# add_library: Создаёт динамические библиотеки
# SHARED: Указывает, что библиотека динамическая
# Каждый компонент включает свои .cpp-файлы и общие (SOURCES_COMMON)

# Component 1
add_library(cmpnt1 SHARED src/cmpnt1.cpp ${SOURCES_COMMON})

# Component 2
add_library(cmpnt2 SHARED src/cmpnt2.cpp ${SOURCES_COMMON})

# Component 3
add_library(cmpnt3 SHARED src/cmpnt3.cpp ${SOURCES_COMMON})

# add_executable: Создаёт исполняемые файлы
# Каждый клиент включает свой .cpp-файл и общие (SOURCES_COMMON)

# Client 1
add_executable(client1 src/client1.cpp ${SOURCES_COMMON})

# Client 2
add_executable(client2 src/client2.cpp ${SOURCES_COMMON})

# Client 3
add_executable(client3 src/client3.cpp ${SOURCES_COMMON})

# target_link_libraries: Связывает клиентов с соответствующими компонентами

# Link
target_link_libraries(client1 cmpnt1)
target_link_libraries(client2 cmpnt2)
target_link_libraries(client3 cmpnt3)
