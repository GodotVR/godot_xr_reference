extends Node3D

# Called when the node enters the scene tree for the first time.
func _ready():
	print("Interfaces: " + str(XRServer.get_interfaces()))
	
	var xr_interface = XRServer.find_interface("XR Reference")
	if xr_interface:
		print("Found " + str(xr_interface.get_name()))
		print("Capabilities " + str(xr_interface.get_capabilities()))
		print("Target size " + str(xr_interface.get_render_target_size()))

		if xr_interface.initialize():
			get_viewport().use_xr = true

			print("Initialised")
		else:
			print("Failed to initialise")
	else:
		print("Couldn't find interface")

