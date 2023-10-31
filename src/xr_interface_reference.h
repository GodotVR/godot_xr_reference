#ifndef XR_INTERFACE_REFERENCE_H
#define XR_INTERFACE_REFERENCE_H

#include <godot_cpp/classes/xr_interface_extension.hpp>

#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/classes/xr_server.hpp>
#include <godot_cpp/classes/xr_positional_tracker.hpp>

namespace godot {

class XRInterfaceReference : public XRInterfaceExtension {
	GDCLASS(XRInterfaceReference, XRInterfaceExtension);

protected:
	static void _bind_methods();

private:
	bool initialised = false;
	XRServer *xr_server = nullptr;

	double eye_height = 1.85;

	double intraocular_dist = 6.0;
	double display_width = 14.5;
	double display_to_lens = 4.0;
	double oversample = 1.5;

	double k1 = 0.215;
	double k2 = 0.215;
	double aspect = 1.0;

	Ref<XRPositionalTracker> head;
	Transform3D head_transform;
	bool use_mouse_for_headtracking = false;
	bool use_wasd_for_movement = false;
	double angle_x = 0.0;
	double angle_y = 0.0;
	Rect2 screen = Rect2(0.0f,0.0f,1.0f,1.0f);

public:
	// Constants.

	// Property setters and getters
	double get_eye_height() const;
	void set_eye_height(const double p_eye_height);

	double get_intraocular_dist() const;
	void set_intraocular_dist(const double p_intraocular_dist);

	double get_display_width() const;
	void set_display_width(const double p_display_width);

	double get_display_to_lens() const;
	void set_display_to_lens(const double p_display_to_lens);

	double get_oversample() const;
	void set_oversample(const double p_oversample);

	double get_k1() const;
	void set_k1(const double p_k1);

	double get_k2() const;
	void set_k2(const double p_k2);

	bool get_use_mouse_for_headtracking() const;
	void set_use_mouse_for_headtracking(bool p_use_mouse_for_headtracking);

	bool get_use_wasd_for_movement() const;
	void set_use_wasd_for_movement(bool p_use_wasd_for_movement);

	Rect2 get_screen_size() const;
	void set_screen_size(const Rect2 screen_size);

	// Functions.
	virtual StringName _get_name() const override;
	virtual uint32_t _get_capabilities() const override;

	virtual bool _is_initialized() const override;
	virtual bool _initialize() override;
	virtual void _uninitialize() override;

	virtual XRInterface::TrackingStatus _get_tracking_status() const override;

	virtual Vector2 _get_render_target_size() override;
	virtual uint32_t _get_view_count() override;
	virtual Transform3D _get_camera_transform() override;
	virtual Transform3D _get_transform_for_view(uint32_t p_view, const Transform3D &p_cam_transform) override;
	virtual PackedFloat64Array _get_projection_for_view(uint32_t p_view, double p_aspect, double p_z_near, double p_z_far) override;
	
	virtual void _post_draw_viewport(const RID &p_render_target, const Rect2 &p_screen_rect) override;

	virtual void _process() override;
	
	virtual bool _get_anchor_detection_is_enabled() const override;
	virtual void _set_anchor_detection_is_enabled(bool enabled) override;
	virtual int32_t _get_camera_feed_id() const override;

	XRInterfaceReference();
	~XRInterfaceReference();
};
} // namespace godot

#endif // ! XR_INTERFACE_REFERENCE_H
