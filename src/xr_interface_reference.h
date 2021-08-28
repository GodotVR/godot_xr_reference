#ifndef XR_INTERFACE_REFERENCE_H
#define XR_INTERFACE_REFERENCE_H

#include <godot_cpp/classes/xr_interface_extension.hpp>

#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/classes/xr_server.hpp>

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

	// Functions.
	virtual StringName _get_name() const override;
	virtual int64_t _get_capabilities() const override;

	virtual bool _is_initialized() const override;
	virtual bool _initialize() override;
	virtual void _uninitialize() override;

	virtual int64_t _get_tracking_status() const override;

	virtual Vector2 _get_render_target_size() override;
	virtual int64_t _get_view_count() override;
	virtual Transform3D _get_camera_transform() override;
	virtual Transform3D _get_transform_for_view(int64_t p_view, const Transform3D &p_cam_transform) override;
	virtual PackedFloat64Array _get_projection_for_view(int64_t p_view, double p_aspect, double p_z_near, double p_z_far) override;
	
	// for some reason missing from our extension_api.json
	virtual void _commit_views(RID p_render_target, const Rect2 &p_screen_rect); // override;

	virtual void _process() override;
	virtual void _notification(int64_t what) override;
	
	virtual bool _get_anchor_detection_is_enabled() const override;
	virtual void _set_anchor_detection_is_enabled(bool enabled) override;
	virtual int64_t _get_camera_feed_id() const override;
};
} // namespace godot

#endif // ! XR_INTERFACE_REFERENCE_H
