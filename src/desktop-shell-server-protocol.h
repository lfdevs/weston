#ifndef DESKTOP_SERVER_PROTOCOL_H
#define DESKTOP_SERVER_PROTOCOL_H

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include "wayland-util.h"

struct wl_client;
struct wl_resource;

struct desktop_shell;
struct screensaver;

extern const struct wl_interface desktop_shell_interface;
extern const struct wl_interface screensaver_interface;

#ifndef DESKTOP_SHELL_CURSOR_ENUM
#define DESKTOP_SHELL_CURSOR_ENUM
enum desktop_shell_cursor {
	DESKTOP_SHELL_CURSOR_NONE = 0,
	DESKTOP_SHELL_CURSOR_RESIZE_TOP = 1,
	DESKTOP_SHELL_CURSOR_RESIZE_BOTTOM = 2,
	DESKTOP_SHELL_CURSOR_ARROW = 3,
	DESKTOP_SHELL_CURSOR_RESIZE_LEFT = 4,
	DESKTOP_SHELL_CURSOR_RESIZE_TOP_LEFT = 5,
	DESKTOP_SHELL_CURSOR_RESIZE_BOTTOM_LEFT = 6,
	DESKTOP_SHELL_CURSOR_MOVE = 7,
	DESKTOP_SHELL_CURSOR_RESIZE_RIGHT = 8,
	DESKTOP_SHELL_CURSOR_RESIZE_TOP_RIGHT = 9,
	DESKTOP_SHELL_CURSOR_RESIZE_BOTTOM_RIGHT = 10,
	DESKTOP_SHELL_CURSOR_BUSY = 11,
};
#endif /* DESKTOP_SHELL_CURSOR_ENUM */

/**
 * desktop_shell - create desktop widgets and helpers
 * @set_background: (none)
 * @set_panel: (none)
 * @set_lock_surface: (none)
 * @unlock: (none)
 * @set_grab_surface: set grab surface
 * @desktop_ready: desktop is ready to be shown
 *
 * Traditional user interfaces can rely on this interface to define the
 * foundations of typical desktops. Currently it's possible to set up
 * background, panels and locking surfaces.
 */
struct desktop_shell_interface {
	/**
	 * set_background - (none)
	 * @output: (none)
	 * @surface: (none)
	 */
	void (*set_background)(struct wl_client *client,
			       struct wl_resource *resource,
			       struct wl_resource *output,
			       struct wl_resource *surface);
	/**
	 * set_panel - (none)
	 * @output: (none)
	 * @surface: (none)
	 */
	void (*set_panel)(struct wl_client *client,
			  struct wl_resource *resource,
			  struct wl_resource *output,
			  struct wl_resource *surface);
	/**
	 * set_lock_surface - (none)
	 * @surface: (none)
	 */
	void (*set_lock_surface)(struct wl_client *client,
				 struct wl_resource *resource,
				 struct wl_resource *surface);
	/**
	 * unlock - (none)
	 */
	void (*unlock)(struct wl_client *client,
		       struct wl_resource *resource);
	/**
	 * set_grab_surface - set grab surface
	 * @surface: (none)
	 *
	 * The surface set by this request will receive a fake
	 * pointer.enter event during grabs at position 0, 0 and is
	 * expected to set an appropriate cursor image as described by the
	 * grab_cursor event sent just before the enter event.
	 */
	void (*set_grab_surface)(struct wl_client *client,
				 struct wl_resource *resource,
				 struct wl_resource *surface);
	/**
	 * desktop_ready - desktop is ready to be shown
	 *
	 * Tell the server, that enough desktop elements have been drawn
	 * to make the desktop look ready for use. During start-up, the
	 * server can wait for this request with a black screen before
	 * starting to fade in the desktop, for instance. If the client
	 * parts of a desktop take a long time to initialize, we avoid
	 * showing temporary garbage.
	 * @since: 2
	 */
	void (*desktop_ready)(struct wl_client *client,
			      struct wl_resource *resource);
};

#define DESKTOP_SHELL_CONFIGURE	0
#define DESKTOP_SHELL_PREPARE_LOCK_SURFACE	1
#define DESKTOP_SHELL_GRAB_CURSOR	2

static inline void
desktop_shell_send_configure(struct wl_resource *resource_, uint32_t edges, struct wl_resource *surface, int32_t width, int32_t height)
{
	wl_resource_post_event(resource_, DESKTOP_SHELL_CONFIGURE, edges, surface, width, height);
}

static inline void
desktop_shell_send_prepare_lock_surface(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, DESKTOP_SHELL_PREPARE_LOCK_SURFACE);
}

static inline void
desktop_shell_send_grab_cursor(struct wl_resource *resource_, uint32_t cursor)
{
	wl_resource_post_event(resource_, DESKTOP_SHELL_GRAB_CURSOR, cursor);
}

/**
 * screensaver - interface for implementing screensavers
 * @set_surface: set the surface type as a screensaver
 *
 * Only one client can bind this interface at a time.
 */
struct screensaver_interface {
	/**
	 * set_surface - set the surface type as a screensaver
	 * @surface: (none)
	 * @output: (none)
	 *
	 * A screensaver surface is normally hidden, and only visible
	 * after an idle timeout.
	 */
	void (*set_surface)(struct wl_client *client,
			    struct wl_resource *resource,
			    struct wl_resource *surface,
			    struct wl_resource *output);
};

#ifdef  __cplusplus
}
#endif

#endif
