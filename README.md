# Godot XR Reference plugin

This is a reference plugin to use as a base to implement XR plugins for Godot 4 and later.

This is a Work In Progress.

## Building this plugin
Make sure that when you clone this repository you initialise the submodules recursively.

Compile `godot-cpp` as per usual:
```
cd godot-cpp
scons target=debug generate_bindings=yes
cd ..
```

After this compile the plugin:
```
scons target=debug
```

> It is important to build debug builds as the editor requires debug builds to run.

# vscode
For convencience I've added my `tasks.json` build configuration for `vscode` into this repository. This included the above mentioned build instructions :)

# about the author

This repository is maintained by Bastiaan "Mux212" Olij
Further information to follow.
