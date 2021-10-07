extends Node3D

var xr_interface : XRInterfaceReference

# Called when the node enters the scene tree for the first time.
func _ready():
	print("Interfaces: " + str(XRServer.get_interfaces()))
	
	xr_interface = XRServer.find_interface("XR Reference")
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

func _input(event):
	if event is InputEventKey:
		if event.pressed and event.keycode == KEY_ESCAPE:
			if xr_interface:
				xr_interface.use_mouse_for_headtracking = false
				xr_interface.use_wasd_for_movement = false
			
			# Input.set_mouse_mode(Input.MOUSE_MODE_VISIBLE)
	elif event is InputEventMouseButton:
		if event.pressed:
			if xr_interface:
				xr_interface.use_mouse_for_headtracking = true
				xr_interface.use_wasd_for_movement = true
			
			# until we can receive proper input events in our interface we don't have access to the mouse when captured
			# Input.set_mouse_mode(Input.MOUSE_MODE_CAPTURED)
