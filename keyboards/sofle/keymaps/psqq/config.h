// Copyright 2024 Santosh Kumar (@santosh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define TRI_LAYER_LOWER_LAYER 2
#define TRI_LAYER_UPPER_LAYER 3
#define TRI_LAYER_ADJUST_LAYER 4

#define ONESHOT_TAP_TOGGLE 3  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 10000  /* Time (in ms) before the one shot key is released */

#define MK_KINETIC_SPEED

// Kinetic mode settings
#define MOUSEKEY_DELAY 5
#define MOUSEKEY_INTERVAL 10
#define MOUSEKEY_MOVE_DELTA 16
#define MOUSEKEY_INITIAL_SPEED 100
#define MOUSEKEY_BASE_SPEED 5000
#define MOUSEKEY_DECELERATED_SPEED 400
#define MOUSEKEY_ACCELERATED_SPEED 3000

// Wheel settings
#define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 16
#define MOUSEKEY_WHEEL_BASE_MOVEMENTS 32
#define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS 48
#define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS 8

#define ENCODER_DIRECTION_FLIP

#define WPM_UNFILTERED
