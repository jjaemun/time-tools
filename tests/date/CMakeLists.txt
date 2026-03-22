# --date.

set(
    directories
    gregorian
    ops
)

foreach(directory ${directories})

    # --mirroring...

    add_subdirectory(${directory})
endforeach()
