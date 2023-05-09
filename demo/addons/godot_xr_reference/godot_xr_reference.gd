@tool
extends Node

var xr_interface : XRInterfaceReference

func get_interface():
	return xr_interface

func start_xr():
	if xr_interface:
		print("Capabilities " + str(xr_interface.get_capabilities()))
		print("Target size " + str(xr_interface.get_render_target_size()))

		if xr_interface.initialize():
			get_viewport().use_xr = true

			print("Initialised")
		else:
			print("Failed to initialise")
	else:
		print("Interface was not instantiated")


func _enter_tree():
	xr_interface = XRInterfaceReference.new()
	if xr_interface:
		XRServer.add_interface(xr_interface)


func _exit_tree():
	if xr_interface:
		XRServer.remove_interface(xr_interface)
		xr_interface = null
