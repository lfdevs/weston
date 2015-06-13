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

#ifndef WL_TEST_SERVER_PROTOCOL_H
#define WL_TEST_SERVER_PROTOCOL_H

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include "wayland-util.h"

struct wl_client;
struct wl_resource;

struct wl_test;

extern const struct wl_interface wl_test_interface;

struct wl_test_interface {
	/**
	 * move_surface - (none)
	 * @surface: (none)
	 * @x: (none)
	 * @y: (none)
	 */
	void (*move_surface)(struct wl_client *client,
			     struct wl_resource *resource,
			     struct wl_resource *surface,
			     int32_t x,
			     int32_t y);
	/**
	 * move_pointer - (none)
	 * @x: (none)
	 * @y: (none)
	 */
	void (*move_pointer)(struct wl_client *client,
			     struct wl_resource *resource,
			     int32_t x,
			     int32_t y);
	/**
	 * send_button - (none)
	 * @button: (none)
	 * @state: (none)
	 */
	void (*send_button)(struct wl_client *client,
			    struct wl_resource *resource,
			    int32_t button,
			    uint32_t state);
	/**
	 * activate_surface - (none)
	 * @surface: (none)
	 */
	void (*activate_surface)(struct wl_client *client,
				 struct wl_resource *resource,
				 struct wl_resource *surface);
	/**
	 * send_key - (none)
	 * @key: (none)
	 * @state: (none)
	 */
	void (*send_key)(struct wl_client *client,
			 struct wl_resource *resource,
			 uint32_t key,
			 uint32_t state);
	/**
	 * get_n_egl_buffers - (none)
	 */
	void (*get_n_egl_buffers)(struct wl_client *client,
				  struct wl_resource *resource);
};

#define WL_TEST_POINTER_POSITION	0
#define WL_TEST_N_EGL_BUFFERS	1

#define WL_TEST_POINTER_POSITION_SINCE_VERSION	1
#define WL_TEST_N_EGL_BUFFERS_SINCE_VERSION	1

static inline void
wl_test_send_pointer_position(struct wl_resource *resource_, wl_fixed_t x, wl_fixed_t y)
{
	wl_resource_post_event(resource_, WL_TEST_POINTER_POSITION, x, y);
}

static inline void
wl_test_send_n_egl_buffers(struct wl_resource *resource_, uint32_t n)
{
	wl_resource_post_event(resource_, WL_TEST_N_EGL_BUFFERS, n);
}

#ifdef  __cplusplus
}
#endif

#endif
