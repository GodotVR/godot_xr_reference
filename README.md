# Godot XR Reference plugin

This is a reference plugin to use as a base to implement XR plugins for Godot 4 and later.

This is a Work In Progress and doesn't work yet.

## Building this plugin
It requires a Godot 4 build with [PR #52003](https://github.com/godotengine/godot/pull/52003) included.
The godot-cpp submodule in this project is currently set to vnen's fork that has the new GD extensions logic in it: https://github.com/vnen/godot-cpp/tree/gdnative-extensions

You will need to run `godot --dump-extension-api extension_api.json` after compiling Godot and then remove the `ClassDB` section from the generated json. Finally place this json inside of `godot-cpp/godot-headers-temp`.

Now compile `godot-cpp` as per usual (replace windows with linux if appropriate):
```
cd godot-cpp
scons platform=windows generate_bindings=yes
cd ..
```

After this compile the plugin:
```
scons platform=windows
```

# vscode
For convencience I've added my `tasks.json` build configuration for `vscode` into this repository. This included the above mentioned build instructions :)

# about the author

This repository is maintained by Bastiaan "Mux212" Olij
Further information to follow.
