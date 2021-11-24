# Additional targets to perform clang-format
# Just run "make clang-format"
file(GLOB_RECURSE
     ALL_CXX_SOURCE_FILES
     *.[chi]pp *.[chi]xx *.cc *.hh *.ii *.[CHI]
)

find_program(CLANG_FORMAT "clang-format")
if(CLANG_FORMAT)
  add_custom_target(
    clang-format
    COMMAND clang-format
    -i
    -Werror
    -style=file
    ${ALL_CXX_SOURCE_FILES}
  )
endif()
