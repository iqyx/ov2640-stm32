/*
 * uHAL camera interface
 *
 * Copyright (C) 2016, Marek Koza, qyx@krtko.org
 *
 * This file is part of uMesh node firmware (http://qyx.krtko.org/projects/umesh)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>


typedef enum interface_camera_ret {
	INTERFACE_CAMERA_OK = 0,
	INTERFACE_CAMERA_FALED = -1,
} interface_camera_ret_t;

enum interface_camera_format {
	INTERFACE_CAMERA_FORMAT_RGB565,
};

struct interface_camera_vmt {

	interface_camera_ret_t (*enable_continuous)(void *context, bool enabled);
	interface_camera_ret_t (*one_shot)(void *context);
	interface_camera_ret_t (*set_frame_callback)(void *context);
	interface_camera_ret_t (*set_data_callback)(void *context);
	void *context;
};

typedef struct interface_camera {
	/* struct hal_interface_descriptor descriptor; */
	struct interface_camera_vmt vmt;
} ICamera;


interface_camera_ret_t interface_camera_init(ICamera *self);
interface_camera_ret_t interface_camera_free(ICamera *self);
interface_camera_ret_t interface_camera_enable_continuous(ICamera *self, bool enabled);
interface_camera_ret_t interface_camera_one_shot(ICamera *self, bool enabled);
interface_camera_ret_t interface_camera_set_format(ICamera *self);
interface_camera_ret_t interface_camera_set_size(ICamera *self);
interface_camera_ret_t interface_camera_set_frame_callback(ICamera *self);
interface_camera_ret_t interface_camera_set_data_callback(ICamera *self);
