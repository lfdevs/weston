#ifndef TABLET_SERVER_PROTOCOL_H
#define TABLET_SERVER_PROTOCOL_H

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include "wayland-util.h"

struct wl_client;
struct wl_resource;

struct tablet_shell;
struct tablet_client;

extern const struct wl_interface tablet_shell_interface;
extern const struct wl_interface tablet_client_interface;

struct tablet_shell_interface {
	/**
	 * set_lockscreen - (none)
	 * @surface: (none)
	 */
	void (*set_lockscreen)(struct wl_client *client,
			       struct wl_resource *resource,
			       struct wl_resource *surface);
	/**
	 * set_switcher - (none)
	 * @surface: (none)
	 */
	void (*set_switcher)(struct wl_client *client,
			     struct wl_resource *resource,
			     struct wl_resource *surface);
	/**
	 * set_homescreen - (none)
	 * @surface: (none)
	 */
	void (*set_homescreen)(struct wl_client *client,
			       struct wl_resource *resource,
			       struct wl_resource *surface);
	/**
	 * show_grid - (none)
	 * @surface: (none)
	 */
	void (*show_grid)(struct wl_client *client,
			  struct wl_resource *resource,
			  struct wl_resource *surface);
	/**
	 * show_panels - (none)
	 * @surface: (none)
	 */
	void (*show_panels)(struct wl_client *client,
			    struct wl_resource *resource,
			    struct wl_resource *surface);
	/**
	 * create_client - (none)
	 * @id: (none)
	 * @name: (none)
	 * @fd: (none)
	 */
	void (*create_client)(struct wl_client *client,
			      struct wl_resource *resource,
			      uint32_t id,
			      const char *name,
			      int32_t fd);
};

#define TABLET_SHELL_SHOW_LOCKSCREEN	0
#define TABLET_SHELL_SHOW_SWITCHER	1
#define TABLET_SHELL_HIDE_SWITCHER	2

static inline void
tablet_shell_send_show_lockscreen(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, TABLET_SHELL_SHOW_LOCKSCREEN);
}

static inline void
tablet_shell_send_show_switcher(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, TABLET_SHELL_SHOW_SWITCHER);
}

static inline void
tablet_shell_send_hide_switcher(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, TABLET_SHELL_HIDE_SWITCHER);
}

struct tablet_client_interface {
	/**
	 * destroy - (none)
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
	/**
	 * activate - (none)
	 */
	void (*activate)(struct wl_client *client,
			 struct wl_resource *resource);
};

#ifdef  __cplusplus
}
#endif

#endif
