


``` CMakeLists.txt
# Add OpCore as a subdirectory
add_subdirectory(opcore)

# Link OpCore (since it's INTERFACE, this just adds include directories)
target_link_libraries(testApp PRIVATE OpCore)
```

