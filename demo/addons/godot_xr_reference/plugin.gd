@tool
extends EditorPlugin

func _enter_tree():
	# Register our autoload object
	add_autoload_singleton(
			"XRReferenceInterface",
			"res://addons/godot_xr_reference/godot_xr_reference.gd")
