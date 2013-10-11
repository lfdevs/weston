#include <stdlib.h>
#include <stdint.h>
#include "wayland-util.h"

extern const struct wl_interface wl_surface_interface;
extern const struct wl_interface wl_surface_interface;
extern const struct wl_interface wl_surface_interface;
extern const struct wl_interface wl_surface_interface;
extern const struct wl_interface wl_surface_interface;
extern const struct wl_interface tablet_client_interface;

static const struct wl_interface *types[] = {
	&wl_surface_interface,
	&wl_surface_interface,
	&wl_surface_interface,
	&wl_surface_interface,
	&wl_surface_interface,
	&tablet_client_interface,
	NULL,
	NULL,
};

static const struct wl_message tablet_shell_requests[] = {
	{ "set_lockscreen", "o", types + 0 },
	{ "set_switcher", "o", types + 1 },
	{ "set_homescreen", "o", types + 2 },
	{ "show_grid", "o", types + 3 },
	{ "show_panels", "o", types + 4 },
	{ "create_client", "nsh", types + 5 },
};

static const struct wl_message tablet_shell_events[] = {
	{ "show_lockscreen", "", types + 0 },
	{ "show_switcher", "", types + 0 },
	{ "hide_switcher", "", types + 0 },
};

WL_EXPORT const struct wl_interface tablet_shell_interface = {
	"tablet_shell", 1,
	6, tablet_shell_requests,
	3, tablet_shell_events,
};

static const struct wl_message tablet_client_requests[] = {
	{ "destroy", "", types + 0 },
	{ "activate", "", types + 0 },
};

WL_EXPORT const struct wl_interface tablet_client_interface = {
	"tablet_client", 1,
	2, tablet_client_requests,
	0, NULL,
};

