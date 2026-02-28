cmake_minimum_required(VERSION 3.16)
project(hello-gtk-cmake VERSION 1.0.0 LANGUAGES C)

# Стандарт C
set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)  # Разрешить GNU-расширения (gnu17 вместо c17)

# Поиск pkg-config
find_package(PkgConfig REQUIRED)

# Поиск GTK 4 через pkg-config
pkg_check_modules(GTK4 REQUIRED gtk4)

# Добавление исполняемого файла
add_executable(hello-gtk src/main.c src/hello.c)

# Пути к заголовочным файлам
target_include_directories(hello-gtk PRIVATE 
  ${GTK4_INCLUDE_DIRS}
  ${CMAKE_SOURCE_DIR}/include
)

# Флаги компиляции
target_compile_options(hello-gtk PRIVATE 
  ${GTK4_CFLAGS_OTHER}
  -Wall
  -Wextra
  -Wpedantic
)

# Библиотеки для линковки
target_link_libraries(hello-gtk PRIVATE 
  ${GTK4_LIBRARIES}
)

# Пути к библиотекам
target_link_directories(hello-gtk PRIVATE 
  ${GTK4_LIBRARY_DIRS}
)

# Установка (опционально)
install(TARGETS hello-gtk DESTINATION bin)