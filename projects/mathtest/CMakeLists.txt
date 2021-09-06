#--------------------------------------------------------------------------
# mathtest project
#--------------------------------------------------------------------------

PROJECT(mathteste)
FILE(GLOB mathtest_headers code/*.h)
FILE(GLOB mathtest_sources code/*.cc)

SET(files_mathtest ${mathtest_headers} ${mathtest_sources})
SOURCE_GROUP("mathtest" FILES ${files_mathtest})

ADD_EXECUTABLE(mathtest ${files_mathtest})
TARGET_LINK_LIBRARIES(mathtest core render)
ADD_DEPENDENCIES(mathtest core render)