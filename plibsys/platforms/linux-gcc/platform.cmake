set (PLIBSYS_THREAD_MODEL posix)
set (PLIBSYS_IPC_MODEL posix)
set (PLIBSYS_TIME_PROFILER_MODEL posix)
set (PLIBSYS_DIR_MODEL posix)

set (PLIBSYS_PLATFORM_LINK_LIBRARIES -pthread rt dl)

set (PLIBSYS_PLATFORM_DEFINES
        -D_REENTRANT
)
