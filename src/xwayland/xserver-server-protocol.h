#ifndef XSERVER_SERVER_PROTOCOL_H
#define XSERVER_SERVER_PROTOCOL_H

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include "wayland-util.h"

struct wl_client;
struct wl_resource;

struct xserver;

extern const struct wl_interface xserver_interface;

struct xserver_interface {
	/**
	 * set_window_id - (none)
	 * @surface: (none)
	 * @id: (none)
	 */
	void (*set_window_id)(struct wl_client *client,
			      struct wl_resource *resource,
			      struct wl_resource *surface,
			      uint32_t id);
};

#define XSERVER_CLIENT	0
#define XSERVER_LISTEN_SOCKET	1

static inline void
xserver_send_client(struct wl_resource *resource_, int32_t fd)
{
	wl_resource_post_event(resource_, XSERVER_CLIENT, fd);
}

static inline void
xserver_send_listen_socket(struct wl_resource *resource_, int32_t fd)
{
	wl_resource_post_event(resource_, XSERVER_LISTEN_SOCKET, fd);
}

#ifdef  __cplusplus
}
#endif

#endif
