#include "register_types.h"

#include <godot/gdnative_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/xr_server.hpp>

#include "xr_interface_reference.h"

using namespace godot;

Ref<XRInterfaceReference> xr_interface_reference;

void register_types() {
	ClassDB::register_class<XRInterfaceReference>();

	XRServer *xr_server = XRServer::get_singleton();
	ERR_FAIL_NULL(xr_server);

	xr_interface_reference.instantiate();
	xr_server->add_interface(xr_interface_reference);
}

void unregister_types() {
	if (xr_interface_reference.is_valid()) {
		if (xr_interface_reference->is_initialized()) {
			xr_interface_reference->uninitialize();
		}

		XRServer *xr_server = XRServer::get_singleton();
		ERR_FAIL_NULL(xr_server);
		xr_server->remove_interface(xr_interface_reference);

		xr_interface_reference.unref();
	}

	// Note: our class will be unregistered automatically
}

extern "C" {

// Initialization.

GDNativeBool GDN_EXPORT xrreference_library_init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

	init_obj.register_driver_initializer(register_types);
	init_obj.register_driver_terminator(unregister_types);

	return init_obj.init();
}
}
