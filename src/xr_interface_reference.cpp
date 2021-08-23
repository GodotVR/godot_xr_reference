#include "xr_interface_reference.h"

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void XRInterfaceReference::_bind_methods() {
	// Methods.
	// ClassDB::bind_method(D_METHOD("simple_func"), &Example::simple_func);

	// Properties.
	// ClassDB::bind_method(D_METHOD("get_custom_position"), &Example::get_custom_position);
	// ClassDB::bind_method(D_METHOD("set_custom_position", "position"), &Example::set_custom_position);
	// ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "custom_position"), "set_custom_position", "get_custom_position");

	// Signals.
	// ADD_SIGNAL(MethodInfo("custom_signal", PropertyInfo(Variant::STRING, "name"), PropertyInfo(Variant::INT, "value")));
	// ClassDB::bind_method(D_METHOD("emit_custom_signal", "name", "value"), &Example::emit_custom_signal);

	// Constants.
	// BIND_ENUM_CONSTANT(FIRST);
}

StringName XRInterfaceReference::_get_name() const {
    return StringName("XR Reference");
}

int64_t XRInterfaceReference::_get_capabilities() const {
    return XR_STEREO;
}

bool XRInterfaceReference::_is_initialized() const {
    return false;
}

bool XRInterfaceReference::_initialize() {
    return false;
}

void XRInterfaceReference::_uninitialize() {
    
}

int64_t XRInterfaceReference::_get_tracking_status() const {
    return XRInterface::XR_UNKNOWN_TRACKING;
}

Vector2 XRInterfaceReference::_get_render_target_size() const {
    return Vector2();
}

int64_t XRInterfaceReference::_get_view_count() const {
    return 2; // stereo
}

Transform3D XRInterfaceReference::_get_camera_transform() const {
    return Transform3D();
}

Transform3D XRInterfaceReference::_get_transform_for_view(int64_t view, const Transform3D &cam_transform) const {
    return Transform3D();
}

PackedFloat64Array XRInterfaceReference::_get_projection_for_view(int64_t view, double aspect, double z_near, double z_far) const {
    PackedFloat64Array arr;

    return arr;
}
	
void XRInterfaceReference::_process() {

}

void XRInterfaceReference::_notification(int64_t what) {

}
	
bool XRInterfaceReference::_get_anchor_detection_is_enabled() const {
    return false;
}

void XRInterfaceReference::_set_anchor_detection_is_enabled(bool enabled) {

}

int64_t XRInterfaceReference::_get_camera_feed_id() const {
    return 0;
}
