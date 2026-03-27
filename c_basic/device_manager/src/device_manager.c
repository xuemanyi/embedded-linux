#include "device_manager.h"

#include <stdio.h>
#include <string.h>

static void swap_device(struct device *a, struct device *b)
{
	struct device tmp;

	if (!a || !b)
		return;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void device_manager_init(struct device_manager *mgr)
{
	size_t i;

	if (!mgr)
		return;

	mgr->count = 0;

	for (i = 0; i < MAX_DEVICES; ++i)
		device_init(&mgr->devices[i], 0, "", DEVICE_OK);
}

int device_manager_add(struct device_manager *mgr, int id,
		       const char *name, enum device_status status)
{
	struct device *dev;

	if (!mgr || !name)
		return -1;

	if (mgr->count >= MAX_DEVICES)
		return -1;

	dev = &mgr->devices[mgr->count];
	device_init(dev, id, name, status);
	mgr->count++;

	return 0;
}

struct device *device_manager_find_by_id(struct device_manager *mgr, int id)
{
	size_t i;

	if (!mgr)
		return NULL;

	for (i = 0; i < mgr->count; ++i) {
		if (mgr->devices[i].id == id)
			return &mgr->devices[i];
	}

	return NULL;
}

struct device *device_manager_find_by_name(struct device_manager *mgr,
					   const char *name)
{
	size_t i;

	if (!mgr || !name)
		return NULL;

	for (i = 0; i < mgr->count; ++i) {
		if (!strncmp(mgr->devices[i].name, name, MAX_NAME_LEN))
			return &mgr->devices[i];
	}

	return NULL;
}

size_t device_manager_filter_by_status(const struct device_manager *mgr,
				       enum device_status status,
				       struct device *out_array[],
				       size_t out_size)
{
	size_t i;
	size_t matched = 0;

	if (!mgr || !out_array || !out_size)
		return 0;

	for (i = 0; i < mgr->count; ++i) {
		if (mgr->devices[i].status != status)
			continue;

		if (matched >= out_size)
			break;

		out_array[matched] = (struct device *)&mgr->devices[i];
		matched++;
	}

	return matched;
}

void device_manager_print_all(const struct device_manager *mgr)
{
	size_t i;
	const struct device *dev;

	if (!mgr)
		return;

	printf("device count: %zu\n", mgr->count);

	for (i = 0; i < mgr->count; ++i) {
		dev = &mgr->devices[i];
		device_print(dev);
	}
}

void device_manager_print_all_by_pointer(const struct device_manager *mgr)
{
	const struct device *pos;
	const struct device *end;

	if (!mgr)
		return;

	pos = mgr->devices;
	end = mgr->devices + mgr->count;

	printf("print with pointer traversal:\n");

	while (pos < end) {
		device_print(pos);
		pos++;
	}
}

void device_manager_sort_by_average_desc(struct device_manager *mgr)
{
	size_t i;
	size_t j;

	if (!mgr || mgr->count < 2)
		return;

	for (i = 0; i < mgr->count - 1; ++i) {
		for (j = 0; j < mgr->count - 1 - i; ++j) {
			double avg1;
			double avg2;

			avg1 = device_average_sample(&mgr->devices[j]);
			avg2 = device_average_sample(&mgr->devices[j + 1]);

			if (avg1 < avg2)
				swap_device(&mgr->devices[j],
					    &mgr->devices[j + 1]);
		}
	}
}

void device_manager_load_demo_data(struct device_manager *mgr)
{
	struct device *dev;

	if (!mgr)
		return;

	device_manager_add(mgr, 101, "sensor_front", DEVICE_OK);
	device_manager_add(mgr, 102, "sensor_rear", DEVICE_WARN);
	device_manager_add(mgr, 103, "motor_left", DEVICE_OK);
	device_manager_add(mgr, 104, "motor_right", DEVICE_ERROR);

	dev = device_manager_find_by_id(mgr, 101);
	if (dev) {
		device_add_sample(dev, 34);
		device_add_sample(dev, 35);
		device_add_sample(dev, 33);
		device_add_sample(dev, 36);
	}

	dev = device_manager_find_by_id(mgr, 102);
	if (dev) {
		device_add_sample(dev, 70);
		device_add_sample(dev, 75);
		device_add_sample(dev, 80);
		device_add_sample(dev, 78);
	}

	dev = device_manager_find_by_id(mgr, 103);
	if (dev) {
		device_add_sample(dev, 40);
		device_add_sample(dev, 41);
		device_add_sample(dev, 39);
		device_add_sample(dev, 38);
	}

	dev = device_manager_find_by_id(mgr, 104);
	if (dev) {
		device_add_sample(dev, 95);
		device_add_sample(dev, 99);
		device_add_sample(dev, 100);
		device_add_sample(dev, 98);
	}
}