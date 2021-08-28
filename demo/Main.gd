extends Node3D


# Declare member variables here. Examples:
# var a = 2
# var b = "text"


# Called when the node enters the scene tree for the first time.
func _ready():
	# this needs to move into our plugin but we can't access our XRServer singleton yet...
	var interface : XRInterfaceReference = XRInterfaceReference.new()
	if interface:
		print("Adding " + str(interface.get_name()))
		print("Capabilities " + str(interface.get_capabilities()))
		print("Target size " + str(interface.get_render_target_size()))
		
		XRServer.add_interface(interface)
	else:
		print("Couldn't instantiate interface")
		return
	
	# and this is our real init, but we skip find_interface due to our get_name bug
	var xr_interface = XRServer.find_interface("XR Reference")
	# var xr_interface = XRServer.find_interface("Native mobile")
	if xr_interface:
		print("Found " + str(xr_interface.get_name()))
		if xr_interface.initialize():
			get_viewport().use_xr = true

			print("Initialised")
		else:
			print("Failed to initialise")
	else:
		print("Couldn't find interface")

