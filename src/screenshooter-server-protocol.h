#ifndef SCREENSHOOTER_SERVER_PROTOCOL_H
#define SCREENSHOOTER_SERVER_PROTOCOL_H

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include "wayland-util.h"

struct wl_client;
struct wl_resource;

struct screenshooter;

extern const struct wl_interface screenshooter_interface;

struct screenshooter_interface {
	/**
	 * shoot - (none)
	 * @output: (none)
	 * @buffer: (none)
	 */
	void (*shoot)(struct wl_client *client,
		      struct wl_resource *resource,
		      struct wl_resource *output,
		      struct wl_resource *buffer);
};

#define SCREENSHOOTER_DONE	0

static inline void
screenshooter_send_done(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, SCREENSHOOTER_DONE);
}

#ifdef  __cplusplus
}
#endif

#endif
