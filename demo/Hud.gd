extends Node3D

@export var camera : NodePath

func _process(_delta):
	if camera:
		var camera_node : XRCamera3D = get_node(camera)
		
		if camera_node:
			var t = camera_node.transform
			var forward : Vector3 = -t.basis.z
			forward.y = 0.0
			forward.normalized()

			position = t.origin

			look_at(t.origin + forward)

	var fps = Performance.get_monitor(Performance.TIME_FPS)
	$FPS.text = "FPS: " + str(fps)
