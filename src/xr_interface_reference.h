#ifndef XR_INTERFACE_REFERENCE_H
#define XR_INTERFACE_REFERENCE_H

#include <godot_cpp/classes/xr_interface_extension.hpp>

#include <godot_cpp/core/binder_common.hpp>

namespace godot {

class XRInterfaceReference : public XRInterfaceExtension {
	GDCLASS(XRInterfaceReference, XRInterfaceExtension);

protected:
	static void _bind_methods();

private:

public:
	// Constants.

	// Functions.
	virtual StringName _get_name() const override;
	virtual int64_t _get_capabilities() const override;

	virtual bool _is_initialized() const override;
	virtual bool _initialize() override;
	virtual void _uninitialize() override;

	virtual int64_t _get_tracking_status() const override;

	virtual Vector2 _get_render_target_size() const override;
	virtual int64_t _get_view_count() const override;
	virtual Transform3D _get_camera_transform() const override;
	virtual Transform3D _get_transform_for_view(int64_t view, const Transform3D &cam_transform) const override;
	virtual PackedFloat64Array _get_projection_for_view(int64_t view, double aspect, double z_near, double z_far) const override;
	
    virtual void _process() override;
	virtual void _notification(int64_t what) override;
	
    virtual bool _get_anchor_detection_is_enabled() const override;
	virtual void _set_anchor_detection_is_enabled(bool enabled) override;
	virtual int64_t _get_camera_feed_id() const override;
};
} // namespace godot

#endif // ! XR_INTERFACE_REFERENCE_H
