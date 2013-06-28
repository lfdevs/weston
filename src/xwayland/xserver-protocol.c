#include <stdlib.h>
#include <stdint.h>
#include "wayland-util.h"

extern const struct wl_interface wl_surface_interface;

static const struct wl_interface *types[] = {
	NULL,
	&wl_surface_interface,
	NULL,
};

static const struct wl_message xserver_requests[] = {
	{ "set_window_id", "ou", types + 1 },
};

static const struct wl_message xserver_events[] = {
	{ "client", "h", types + 0 },
	{ "listen_socket", "h", types + 0 },
};

WL_EXPORT const struct wl_interface xserver_interface = {
	"xserver", 1,
	1, xserver_requests,
	2, xserver_events,
};

