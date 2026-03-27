#include <stdio.h>

#include "device_manager.h"

static void demo_find_and_update(struct device_manager *mgr)
{
	struct device *dev;

	if (!mgr)
		return;

	dev = device_manager_find_by_name(mgr, "sensor_front");
	if (dev) {
		printf("\nfound device by name:\n");
		device_print(dev);

		device_add_sample(dev, 37);

		printf("after adding one sample:\n");
		device_print(dev);
	}
}

static void demo_filter(const struct device_manager *mgr)
{
	struct device *filtered[MAX_DEVICES];
	size_t i;
	size_t count;

	if (!mgr)
		return;

	count = device_manager_filter_by_status(mgr, DEVICE_OK,
						filtered, MAX_DEVICES);

	printf("\nfiltered devices with status OK:\n");

	for (i = 0; i < count; ++i)
		device_print(filtered[i]);
}

static void demo_array_and_pointer_basics(void)
{
	int values[5] = { 10, 20, 30, 40, 50 };
	int *ptr = values;
	size_t i;

	printf("\narray and pointer basics:\n");

	for (i = 0; i < 5; ++i) {
		printf("values[%zu]=%d, *(ptr + %zu)=%d, address=%p\n",
		       i, values[i], i, *(ptr + i), (void *)&values[i]);
	}
}

int main(void)
{
	struct device_manager mgr;

	device_manager_init(&mgr);
	device_manager_load_demo_data(&mgr);

	printf("initial data:\n");
	device_manager_print_all(&mgr);

	printf("\n");
	device_manager_print_all_by_pointer(&mgr);

	demo_find_and_update(&mgr);
	demo_filter(&mgr);
	demo_array_and_pointer_basics();

	printf("\nbefore sort by average desc:\n");
	device_manager_print_all(&mgr);

	device_manager_sort_by_average_desc(&mgr);

	printf("\nafter sort by average desc:\n");
	device_manager_print_all(&mgr);

	return 0;
}