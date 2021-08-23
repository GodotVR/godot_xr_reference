extends Node3D


# Declare member variables here. Examples:
# var a = 2
# var b = "text"


# Called when the node enters the scene tree for the first time.
func _ready():
	# this needs to move into our plugin but we can't access our XRServer singleton yet...
	var new_interface = XRInterfaceReference.new()
	XRServer.add_interface(new_interface)
	
	# and this is our real init
	var interface : XRInterfaceReference = XRServer.find_interface("XR Reference")
	if interface:
		print("Found " + str(interface.get_name()))
		if interface.initialize():
			print("Initialised")
		else:
			print("Failed to initialise")
	else:
		print("Couldn't find interface")


# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
