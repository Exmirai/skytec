# Make sure the user is not executing this script directly
if(NOT RootBuild)
	message(FATAL_ERROR "Use the top-level cmake script!")
endif(NOT RootBuild)

# Source code
set(STSRC
	"${STDir}/main.c"
	)
source_group("Source code" FILES ${STSRC})

add_executable(${BuildSecondTask} ${STSRC})
set_target_properties(${BuildSecondTask} PROPERTIES INCLUDE_DIRECTORIES "${STSRC}")
set_target_properties(${BuildSecondTask} PROPERTIES PROJECT_LABEL "Second Task")