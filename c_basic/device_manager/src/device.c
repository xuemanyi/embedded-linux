#include "device.h"

#include <stdio.h>
#include <string.h>

const char *device_status_to_string(enum device_status status)
{
	switch (status) {
	case DEVICE_OK:
		return "OK";
	case DEVICE_WARN:
		return "WARN";
	case DEVICE_ERROR:
		return "ERROR";
	default:
		return "UNKNOWN";
	}
}

void sample_buffer_init(struct sample_buffer *buffer)
{
	size_t i;

	if (!buffer)
		return;

	buffer->count = 0;

	for (i = 0; i < DEVICE_SAMPLE_COUNT; ++i)
		buffer->values[i] = 0;
}

void device_init(struct device *dev, int id, const char *name,
		 enum device_status status)
{
	if (!dev || !name)
		return;

	dev->id = id;
	dev->status = status;

	sample_buffer_init(&dev->samples);

	strncpy(dev->name, name, MAX_NAME_LEN - 1);
	dev->name[MAX_NAME_LEN - 1] = '\0';
}

int device_add_sample(struct device *dev, int value)
{
	if (!dev)
		return -1;

	if (dev->samples.count < DEVICE_SAMPLE_COUNT) {
		dev->samples.values[dev->samples.count] = value;
		dev->samples.count++;
		return 0;
	}

	memmove(&dev->samples.values[0],
		&dev->samples.values[1],
		(DEVICE_SAMPLE_COUNT - 1) * sizeof(dev->samples.values[0]));

	dev->samples.values[DEVICE_SAMPLE_COUNT - 1] = value;

	return 0;
}

double device_average_sample(const struct device *dev)
{
	size_t i;
	long sum = 0;

	if (!dev || dev->samples.count == 0)
		return 0.0;

	for (i = 0; i < dev->samples.count; ++i)
		sum += dev->samples.values[i];

	return (double)sum / (double)dev->samples.count;
}

int device_max_sample(const struct device *dev)
{
	size_t i;
	int max_value;

	if (!dev || dev->samples.count == 0)
		return 0;

	max_value = dev->samples.values[0];

	for (i = 1; i < dev->samples.count; ++i) {
		if (dev->samples.values[i] > max_value)
			max_value = dev->samples.values[i];
	}

	return max_value;
}

int device_min_sample(const struct device *dev)
{
	size_t i;
	int min_value;

	if (!dev || dev->samples.count == 0)
		return 0;

	min_value = dev->samples.values[0];

	for (i = 1; i < dev->samples.count; ++i) {
		if (dev->samples.values[i] < min_value)
			min_value = dev->samples.values[i];
	}

	return min_value;
}

void device_print_samples(const struct device *dev)
{
	size_t i;

	if (!dev)
		return;

	printf("samples: [");

	for (i = 0; i < dev->samples.count; ++i) {
		printf("%d", dev->samples.values[i]);

		if (i + 1 < dev->samples.count)
			printf(", ");
	}

	printf("]");
}

void device_print(const struct device *dev)
{
	if (!dev)
		return;

	printf("id=%d, name=%s, status=%s, avg=%.2f, min=%d, max=%d, ",
	       dev->id, dev->name, device_status_to_string(dev->status),
	       device_average_sample(dev), device_min_sample(dev),
	       device_max_sample(dev));

	device_print_samples(dev);
	printf("\n");
}