#ifndef WORKSPACES_SERVER_PROTOCOL_H
#define WORKSPACES_SERVER_PROTOCOL_H

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include "wayland-util.h"

struct wl_client;
struct wl_resource;

struct workspace_manager;

extern const struct wl_interface workspace_manager_interface;

/**
 * workspace_manager - workspaces manager
 * @move_surface: move surface to workspace
 *
 * An interface for managing surfaces in workspaces.
 */
struct workspace_manager_interface {
	/**
	 * move_surface - move surface to workspace
	 * @surface: (none)
	 * @workspace: (none)
	 *
	 * Move the given surface to the specified workspace.
	 */
	void (*move_surface)(struct wl_client *client,
			     struct wl_resource *resource,
			     struct wl_resource *surface,
			     uint32_t workspace);
};

#define WORKSPACE_MANAGER_STATE	0

static inline void
workspace_manager_send_state(struct wl_resource *resource_, uint32_t current, uint32_t count)
{
	wl_resource_post_event(resource_, WORKSPACE_MANAGER_STATE, current, count);
}

#ifdef  __cplusplus
}
#endif

#endif
