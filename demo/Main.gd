extends Node3D

var xr_interface : XRInterfaceReference

# Called when the node enters the scene tree for the first time.
func _ready():
	XRReferenceInterface.start_xr()

func _input(event):
	if event is InputEventKey:
		if event.pressed and event.keycode == KEY_ESCAPE:
			var xr_interface = XRReferenceInterface.get_interface()
			if xr_interface:
				xr_interface.use_mouse_for_headtracking = false
				xr_interface.use_wasd_for_movement = false
			
			# Input.set_mouse_mode(Input.MOUSE_MODE_VISIBLE)
	elif event is InputEventMouseButton:
		if event.pressed:
			var xr_interface = XRReferenceInterface.get_interface()
			if xr_interface:
				xr_interface.use_mouse_for_headtracking = true
				xr_interface.use_wasd_for_movement = true
			
			# until we can receive proper input events in our interface we don't have access to the mouse when captured
			# Input.set_mouse_mode(Input.MOUSE_MODE_CAPTURED)
