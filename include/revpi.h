#ifndef REVPI_H_
#define REVPI_H_

#include <stdint.h>
#include "piControl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct revpi_peripheral_t {
  int pi_control_fd;
  char pin_name[32];
  SDeviceInfo device_info;
  SPIValue value;
  SPIVariable variable;
} revpi_peripheral;

int revpi_init(revpi_peripheral *revpi);
int revpi_exit(revpi_peripheral *revpi);
int revpi_set_do_level(revpi_peripheral *revpi, uint8_t level);
int revpi_get_di_level(revpi_peripheral *revpi);
int revpi_set_do_push_pull(revpi_peripheral *revpi, uint16_t push_pull);
int revpi_get_ai_value(revpi_peripheral *revpi);
int revpi_read_variable(revpi_peripheral *revpi, uint8_t *data);
int revpi_write_variable(revpi_peripheral *revpi, uint8_t *data);

#ifdef __cplusplus
}
#endif

#endif /* REVPI_H_ */
