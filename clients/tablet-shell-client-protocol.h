#ifndef TABLET_CLIENT_PROTOCOL_H
#define TABLET_CLIENT_PROTOCOL_H

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include "wayland-client.h"

struct wl_client;
struct wl_resource;

struct tablet_shell;
struct tablet_client;

extern const struct wl_interface tablet_shell_interface;
extern const struct wl_interface tablet_client_interface;

struct tablet_shell_listener {
	/**
	 * show_lockscreen - (none)
	 */
	void (*show_lockscreen)(void *data,
				struct tablet_shell *tablet_shell);
	/**
	 * show_switcher - (none)
	 */
	void (*show_switcher)(void *data,
			      struct tablet_shell *tablet_shell);
	/**
	 * hide_switcher - (none)
	 */
	void (*hide_switcher)(void *data,
			      struct tablet_shell *tablet_shell);
};

static inline int
tablet_shell_add_listener(struct tablet_shell *tablet_shell,
			  const struct tablet_shell_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) tablet_shell,
				     (void (**)(void)) listener, data);
}

#define TABLET_SHELL_SET_LOCKSCREEN	0
#define TABLET_SHELL_SET_SWITCHER	1
#define TABLET_SHELL_SET_HOMESCREEN	2
#define TABLET_SHELL_SHOW_GRID	3
#define TABLET_SHELL_SHOW_PANELS	4
#define TABLET_SHELL_CREATE_CLIENT	5

static inline void
tablet_shell_set_user_data(struct tablet_shell *tablet_shell, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) tablet_shell, user_data);
}

static inline void *
tablet_shell_get_user_data(struct tablet_shell *tablet_shell)
{
	return wl_proxy_get_user_data((struct wl_proxy *) tablet_shell);
}

static inline void
tablet_shell_destroy(struct tablet_shell *tablet_shell)
{
	wl_proxy_destroy((struct wl_proxy *) tablet_shell);
}

static inline void
tablet_shell_set_lockscreen(struct tablet_shell *tablet_shell, struct wl_surface *surface)
{
	wl_proxy_marshal((struct wl_proxy *) tablet_shell,
			 TABLET_SHELL_SET_LOCKSCREEN, surface);
}

static inline void
tablet_shell_set_switcher(struct tablet_shell *tablet_shell, struct wl_surface *surface)
{
	wl_proxy_marshal((struct wl_proxy *) tablet_shell,
			 TABLET_SHELL_SET_SWITCHER, surface);
}

static inline void
tablet_shell_set_homescreen(struct tablet_shell *tablet_shell, struct wl_surface *surface)
{
	wl_proxy_marshal((struct wl_proxy *) tablet_shell,
			 TABLET_SHELL_SET_HOMESCREEN, surface);
}

static inline void
tablet_shell_show_grid(struct tablet_shell *tablet_shell, struct wl_surface *surface)
{
	wl_proxy_marshal((struct wl_proxy *) tablet_shell,
			 TABLET_SHELL_SHOW_GRID, surface);
}

static inline void
tablet_shell_show_panels(struct tablet_shell *tablet_shell, struct wl_surface *surface)
{
	wl_proxy_marshal((struct wl_proxy *) tablet_shell,
			 TABLET_SHELL_SHOW_PANELS, surface);
}

static inline struct tablet_client *
tablet_shell_create_client(struct tablet_shell *tablet_shell, const char *name, int32_t fd)
{
	struct wl_proxy *id;

	id = wl_proxy_create((struct wl_proxy *) tablet_shell,
			     &tablet_client_interface);
	if (!id)
		return NULL;

	wl_proxy_marshal((struct wl_proxy *) tablet_shell,
			 TABLET_SHELL_CREATE_CLIENT, id, name, fd);

	return (struct tablet_client *) id;
}

#define TABLET_CLIENT_DESTROY	0
#define TABLET_CLIENT_ACTIVATE	1

static inline void
tablet_client_set_user_data(struct tablet_client *tablet_client, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) tablet_client, user_data);
}

static inline void *
tablet_client_get_user_data(struct tablet_client *tablet_client)
{
	return wl_proxy_get_user_data((struct wl_proxy *) tablet_client);
}

static inline void
tablet_client_destroy(struct tablet_client *tablet_client)
{
	wl_proxy_marshal((struct wl_proxy *) tablet_client,
			 TABLET_CLIENT_DESTROY);

	wl_proxy_destroy((struct wl_proxy *) tablet_client);
}

static inline void
tablet_client_activate(struct tablet_client *tablet_client)
{
	wl_proxy_marshal((struct wl_proxy *) tablet_client,
			 TABLET_CLIENT_ACTIVATE);
}

#ifdef  __cplusplus
}
#endif

#endif
