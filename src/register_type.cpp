#include "register_types.h"

#include <godot/gdnative_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/xr_server.hpp>

#include "xr_interface_reference.h"

using namespace godot;

void register_types() {
    UtilityFunctions::print("Hello register types!");
    
	ClassDB::register_class<XRInterfaceReference>();
}

void unregister_types() {}

extern "C" {

// Initialization.

GDNativeBool GDN_EXPORT xrreference_library_init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization) {
	GDNativeBool result = godot::GDExtensionBinding::init(p_interface, p_library, r_initialization);

	if (result) {
		register_types();
	}

	return result;
}
}
