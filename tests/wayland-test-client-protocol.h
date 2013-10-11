/* 
 * Copyright © 2012 Intel Corporation
 * 
 * Permission to use, copy, modify, distribute, and sell this
 * software and its documentation for any purpose is hereby granted
 * without fee, provided that the above copyright notice appear in
 * all copies and that both that copyright notice and this permission
 * notice appear in supporting documentation, and that the name of
 * the copyright holders not be used in advertising or publicity
 * pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied
 * warranty.
 * 
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS
 * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS, IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
 * THIS SOFTWARE.
 */

#ifndef WL_TEST_CLIENT_PROTOCOL_H
#define WL_TEST_CLIENT_PROTOCOL_H

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include "wayland-client.h"

struct wl_client;
struct wl_resource;

struct wl_test;

extern const struct wl_interface wl_test_interface;

struct wl_test_listener {
	/**
	 * pointer_position - (none)
	 * @x: (none)
	 * @y: (none)
	 */
	void (*pointer_position)(void *data,
				 struct wl_test *wl_test,
				 wl_fixed_t x,
				 wl_fixed_t y);
};

static inline int
wl_test_add_listener(struct wl_test *wl_test,
		     const struct wl_test_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) wl_test,
				     (void (**)(void)) listener, data);
}

#define WL_TEST_MOVE_SURFACE	0
#define WL_TEST_MOVE_POINTER	1
#define WL_TEST_SEND_BUTTON	2
#define WL_TEST_ACTIVATE_SURFACE	3
#define WL_TEST_SEND_KEY	4

static inline void
wl_test_set_user_data(struct wl_test *wl_test, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) wl_test, user_data);
}

static inline void *
wl_test_get_user_data(struct wl_test *wl_test)
{
	return wl_proxy_get_user_data((struct wl_proxy *) wl_test);
}

static inline void
wl_test_destroy(struct wl_test *wl_test)
{
	wl_proxy_destroy((struct wl_proxy *) wl_test);
}

static inline void
wl_test_move_surface(struct wl_test *wl_test, struct wl_surface *surface, int32_t x, int32_t y)
{
	wl_proxy_marshal((struct wl_proxy *) wl_test,
			 WL_TEST_MOVE_SURFACE, surface, x, y);
}

static inline void
wl_test_move_pointer(struct wl_test *wl_test, int32_t x, int32_t y)
{
	wl_proxy_marshal((struct wl_proxy *) wl_test,
			 WL_TEST_MOVE_POINTER, x, y);
}

static inline void
wl_test_send_button(struct wl_test *wl_test, int32_t button, uint32_t state)
{
	wl_proxy_marshal((struct wl_proxy *) wl_test,
			 WL_TEST_SEND_BUTTON, button, state);
}

static inline void
wl_test_activate_surface(struct wl_test *wl_test, struct wl_surface *surface)
{
	wl_proxy_marshal((struct wl_proxy *) wl_test,
			 WL_TEST_ACTIVATE_SURFACE, surface);
}

static inline void
wl_test_send_key(struct wl_test *wl_test, uint32_t key, uint32_t state)
{
	wl_proxy_marshal((struct wl_proxy *) wl_test,
			 WL_TEST_SEND_KEY, key, state);
}

#ifdef  __cplusplus
}
#endif

#endif
