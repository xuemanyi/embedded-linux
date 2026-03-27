#ifndef DEVICE_H
#define DEVICE_H

#include <stddef.h>

#define MAX_NAME_LEN        32
#define DEVICE_SAMPLE_COUNT 8

enum device_status {
	DEVICE_OK = 0,
	DEVICE_WARN,
	DEVICE_ERROR,
};

struct sample_buffer {
	int values[DEVICE_SAMPLE_COUNT];
	size_t count;
};

struct device {
	int id;
	char name[MAX_NAME_LEN];
	enum device_status status;
	struct sample_buffer samples;
};

const char *device_status_to_string(enum device_status status);

void sample_buffer_init(struct sample_buffer *buffer);

void device_init(struct device *dev, int id, const char *name,
		 enum device_status status);
int device_add_sample(struct device *dev, int value);

double device_average_sample(const struct device *dev);
int device_max_sample(const struct device *dev);
int device_min_sample(const struct device *dev);

void device_print_samples(const struct device *dev);
void device_print(const struct device *dev);

#endif