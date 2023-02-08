# Make sure the user is not executing this script directly
if(NOT RootBuild)
	message(FATAL_ERROR "Use the top-level cmake script!")
endif(NOT RootBuild)

# Source code
set(FPSRC
	"${FTDir}/main.c"
	)
source_group("Source code" FILES ${FPSRC})

add_executable(${BuildFirstTask} ${FPSRC})
set_target_properties(${BuildFirstTask} PROPERTIES INCLUDE_DIRECTORIES "${FPSRC}")
set_target_properties(${BuildFirstTask} PROPERTIES PROJECT_LABEL "First Task")