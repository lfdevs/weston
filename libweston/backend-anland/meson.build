if not get_option('backend-anland')
	subdir_done()
endif

config_h.set('BUILD_ANLAND_COMPOSITOR', '1')

srcs_anland = [
	'anland.c',
	'vendor/display_producer.c',
	'vendor/socket_utils.c',
	presentation_time_server_protocol_h,
]

plugin_anland = shared_library(
	'anland-backend',
	srcs_anland,
	include_directories: [common_inc, include_directories('vendor')],
	c_args: [
		'-O3',
		'-flto',
	],
	link_args: ['-flto'],
	dependencies: [
		dep_libweston_private,
		dep_libdrm_headers,
		dep_lib_cairo_shared,
	],
	name_prefix: '',
	install: true,
	install_dir: dir_module_libweston,
)
env_modmap += 'anland-backend.so=@0@;'.format(plugin_anland.full_path())
install_headers(backend_anland_h, subdir: dir_include_libweston_install)
