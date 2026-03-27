#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H

#include <stddef.h>

#include "device.h"

#define MAX_DEVICES 16

struct device_manager {
	struct device devices[MAX_DEVICES];
	size_t count;
};

void device_manager_init(struct device_manager *mgr);

int device_manager_add(struct device_manager *mgr, int id,
		       const char *name, enum device_status status);

struct device *device_manager_find_by_id(struct device_manager *mgr, int id);
struct device *device_manager_find_by_name(struct device_manager *mgr,
					   const char *name);

size_t device_manager_filter_by_status(const struct device_manager *mgr,
				       enum device_status status,
				       struct device *out_array[],
				       size_t out_size);

void device_manager_print_all(const struct device_manager *mgr);
void device_manager_print_all_by_pointer(const struct device_manager *mgr);

void device_manager_sort_by_average_desc(struct device_manager *mgr);
void device_manager_load_demo_data(struct device_manager *mgr);

#endif