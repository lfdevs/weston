#ifndef TEXT_CURSOR_POSITION_SERVER_PROTOCOL_H
#define TEXT_CURSOR_POSITION_SERVER_PROTOCOL_H

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include "wayland-util.h"

struct wl_client;
struct wl_resource;

struct text_cursor_position;

extern const struct wl_interface text_cursor_position_interface;

struct text_cursor_position_interface {
	/**
	 * notify - (none)
	 * @surface: (none)
	 * @x: (none)
	 * @y: (none)
	 */
	void (*notify)(struct wl_client *client,
		       struct wl_resource *resource,
		       struct wl_resource *surface,
		       wl_fixed_t x,
		       wl_fixed_t y);
};

#ifdef  __cplusplus
}
#endif

#endif
