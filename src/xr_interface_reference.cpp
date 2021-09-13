#include "xr_interface_reference.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/display_server.hpp>

using namespace godot;

void XRInterfaceReference::_bind_methods() {
	// Methods.
	// ClassDB::bind_method(D_METHOD("simple_func"), &Example::simple_func);

	// Properties.
	ClassDB::bind_method(D_METHOD("get_eye_height"), &XRInterfaceReference::get_eye_height);
	ClassDB::bind_method(D_METHOD("set_eye_height", "eye_height"), &XRInterfaceReference::set_eye_height);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "eye_height"), "set_eye_height", "get_eye_height");

	ClassDB::bind_method(D_METHOD("get_intraocular_dist"), &XRInterfaceReference::get_intraocular_dist);
	ClassDB::bind_method(D_METHOD("set_intraocular_dist", "intraocular_dist"), &XRInterfaceReference::set_intraocular_dist);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "intraocular_dist"), "set_intraocular_dist", "get_intraocular_dist");

	ClassDB::bind_method(D_METHOD("get_display_width"), &XRInterfaceReference::get_display_width);
	ClassDB::bind_method(D_METHOD("set_display_width", "display_width"), &XRInterfaceReference::set_display_width);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "display_width"), "set_display_width", "get_display_width");

	ClassDB::bind_method(D_METHOD("get_display_to_lens"), &XRInterfaceReference::get_display_to_lens);
	ClassDB::bind_method(D_METHOD("set_display_to_lens", "display_to_lens"), &XRInterfaceReference::set_display_to_lens);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "display_to_lens"), "set_display_to_lens", "get_display_to_lens");

	ClassDB::bind_method(D_METHOD("get_oversample"), &XRInterfaceReference::get_oversample);
	ClassDB::bind_method(D_METHOD("set_oversample", "oversample"), &XRInterfaceReference::set_oversample);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "oversample"), "set_oversample", "get_oversample");

	ClassDB::bind_method(D_METHOD("get_k1"), &XRInterfaceReference::get_k1);
	ClassDB::bind_method(D_METHOD("set_k1", "k1"), &XRInterfaceReference::set_k1);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "k1"), "set_k1", "get_k1");

	ClassDB::bind_method(D_METHOD("get_k2"), &XRInterfaceReference::get_k2);
	ClassDB::bind_method(D_METHOD("set_k2", "k2"), &XRInterfaceReference::set_k2);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "k2"), "set_k2", "get_k2");

	// Signals.
	// ADD_SIGNAL(MethodInfo("custom_signal", PropertyInfo(Variant::STRING, "name"), PropertyInfo(Variant::INT, "value")));
	// ClassDB::bind_method(D_METHOD("emit_custom_signal", "name", "value"), &Example::emit_custom_signal);

	// Constants.
	// BIND_ENUM_CONSTANT(FIRST);
}

double XRInterfaceReference::get_eye_height() const {
	return eye_height;
}

void XRInterfaceReference::set_eye_height(const double p_eye_height) {
	eye_height = p_eye_height;
}

double XRInterfaceReference::get_intraocular_dist() const {
	return intraocular_dist;
}

void XRInterfaceReference::set_intraocular_dist(const double p_intraocular_dist) {
	intraocular_dist = p_intraocular_dist;
}

double XRInterfaceReference::get_display_width() const {
	return display_width;
}

void XRInterfaceReference::set_display_width(const double p_display_width) {
	display_width = p_display_width;
}

double XRInterfaceReference::get_display_to_lens() const {
	return display_to_lens;
}

void XRInterfaceReference::set_display_to_lens(const double p_display_to_lens) {
	display_to_lens = p_display_to_lens;
}

double XRInterfaceReference::get_oversample() const {
	return oversample;
}

void XRInterfaceReference::set_oversample(const double p_oversample) {
	oversample = p_oversample;
}

double XRInterfaceReference::get_k1() const {
	return k1;
}

void XRInterfaceReference::set_k1(const double p_k1) {
	k1 = p_k1;
}

double XRInterfaceReference::get_k2() const {
	return k2;
}

void XRInterfaceReference::set_k2(const double p_k2) {
	k2 = p_k2;
}

StringName XRInterfaceReference::_get_name() const {
	// this currently fails to return because we loose our data before it ends up in the callers hands...
	StringName name("XR Reference");
	return name;
}

int64_t XRInterfaceReference::_get_capabilities() const {
	return XR_STEREO;
}

bool XRInterfaceReference::_is_initialized() const {
	return initialised;
}

bool XRInterfaceReference::_initialize() {
	if (!initialised) {
		// do any initialisation here.. 
		xr_server = XRServer::get_singleton();
		if (xr_server == nullptr) {
			ERR_FAIL_V_MSG(false, "Couldn't obtain XRServer singleton");
		}

		xr_server->set_primary_interface(this);

		initialised = true;
	}
	return initialised;
}

void XRInterfaceReference::_uninitialize() {
	if (initialised) {
		// do any cleanup here...

		initialised = false;
		xr_server = nullptr;
	}
}

int64_t XRInterfaceReference::_get_tracking_status() const {
	return XRInterface::XR_UNKNOWN_TRACKING;
}

Vector2 XRInterfaceReference::_get_render_target_size() {
	// TODO get access to display server singleton

	// we use half our window size
	DisplayServer *display_server = DisplayServer::get_singleton();
	if (display_server == nullptr) {
		return Vector2();
	}
	Vector2 target_size = display_server->window_get_size();

	target_size.x = target_size.x * 0.5 * oversample;
	target_size.y = target_size.y * oversample;

	return target_size;
}

int64_t XRInterfaceReference::_get_view_count() {
	return 2; // stereo
}

Transform3D XRInterfaceReference::_get_camera_transform() {
	if (!initialised) {
		return Transform3D();
	}

	Transform3D hmd_transform;
	double world_scale = xr_server->get_world_scale();

	hmd_transform.origin.y = eye_height * world_scale;

	return xr_server->get_reference_frame() * hmd_transform;
}

Transform3D XRInterfaceReference::_get_transform_for_view(int64_t p_view, const Transform3D &p_cam_transform) {
	if (!initialised) {
		return Transform3D();
	}

	Transform3D hmd_transform, eye_transform;
	double world_scale = xr_server->get_world_scale();

	if (p_view == 0) {
		eye_transform.origin.x = -(intraocular_dist * 0.01 * 0.5 * world_scale);
	} else if (p_view == 1) {
		eye_transform.origin.x = intraocular_dist * 0.01 * 0.5 * world_scale;
	}

	hmd_transform.origin.y = eye_height * world_scale;

	return p_cam_transform * xr_server->get_reference_frame() * hmd_transform * eye_transform;
}

PackedFloat64Array XRInterfaceReference::_get_projection_for_view(int64_t p_view, double p_aspect, double p_z_near, double p_z_far) {
	PackedFloat64Array arr;
	arr.resize(16); // 4x4 matrix

	aspect = p_aspect;

	// We don't have access to CameraMatrix here so we'll need to duplicate some code here..
	/*
		eye.set_for_hmd(p_view + 1, p_aspect, intraocular_dist, display_width, display_to_lens, oversample, p_z_near, p_z_far);
	*/

	// we first calculate our base frustum on our values without taking our lens magnification into account.
	double f1 = (intraocular_dist * 0.5) / display_to_lens;
	double f2 = ((display_width - intraocular_dist) * 0.5) / display_to_lens;
	double f3 = (display_width / 4.0) / display_to_lens;

	// now we apply our oversample factor to increase our FOV. how much we oversample is always a balance we strike between performance and how much
	// we're willing to sacrifice in FOV.
	double add = ((f1 + f2) * (oversample - 1.0)) / 2.0;
	f1 += add;
	f2 += add;
	f3 *= oversample;

	// always apply KEEP_WIDTH aspect ratio
	f3 /= p_aspect;

	double left,right,top,bottom;
	if (p_view == 0) { // left eye
		left = -f2 * p_z_near;
		right = f1 * p_z_near;
		bottom = -f3 * p_z_near;
		top = f3 * p_z_near;
	} else {
		left = -f1 * p_z_near;
		right = f2 * p_z_near;
		bottom = -f3 * p_z_near;
		top = f3 * p_z_near;
	}

	double x = 2 * p_z_near / (right - left);
	double y = 2 * p_z_near / (top - bottom);

	double a = (right + left) / (right - left);
	double b = (top + bottom) / (top - bottom);
	double c = -(p_z_far + p_z_near) / (p_z_far - p_z_near);
	double d = -2 * p_z_far * p_z_near / (p_z_far - p_z_near);

	arr.set(0, x);
	arr.set(1, 0);
	arr.set(2, 0);
	arr.set(3, 0);
	arr.set(4, 0);
	arr.set(5, y);
	arr.set(6, 0);
	arr.set(7, 0);
	arr.set(8, a);
	arr.set(9, b);
	arr.set(10, c);
	arr.set(11, -1);
	arr.set(12, 0);
	arr.set(13, 0);
	arr.set(14, d);
	arr.set(15, 0.0);

	return arr;
}

void XRInterfaceReference::_commit_views(const RID &p_render_target, const Rect2 &p_screen_rect) {
	Rect2 src_rect(0.0f, 0.0f, 1.0f, 1.0f);
	Rect2 dst_rect = p_screen_rect;

	// halve our width
	Vector2 size = dst_rect.get_size();
	size.x = size.x * 0.5;
	dst_rect.size = size;

	Vector2 eye_center(((-intraocular_dist / 2.0) + (display_width / 4.0)) / (display_width / 2.0), 0.0);

	add_blit(p_render_target, src_rect, dst_rect, true, 0, true, eye_center, k1, k2, oversample, aspect);

	// move rect
	Vector2 pos = dst_rect.get_position();
	pos.x = size.x;
	dst_rect.position = pos;

	eye_center.x = ((intraocular_dist / 2.0) - (display_width / 4.0)) / (display_width / 2.0);
	add_blit(p_render_target, src_rect, dst_rect, true, 1, true, eye_center, k1, k2, oversample, aspect);
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

XRInterfaceReference::XRInterfaceReference() {

}

XRInterfaceReference::~XRInterfaceReference() {

}
