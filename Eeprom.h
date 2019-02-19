#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct {
	uint8_t	mAddr;         //I2C address of device
	uint64_t	mSize;       //size of memory in bytes
	uint32_t  mPageSize;   //page size of memory
	mrt_i2c_handle_t mHandle;						//void pointer to periph module handle
}eeprom_t;

#ifdef __cplusplus

namespace Devices
{

class Eeprom : public eeprom_t
{
	public:
		Eeprom(mrt_i2c_handle_t handle, uint8_t addr, uint64_t size,uint32_t pageSize );
    ~Eeprom();
    void read(uint64_t address, uint8_t* data, int len);
    void write(uint64_t address, uint8_t* data, int len);

  private:
#ifdef MRT_MUTEX_TYPE
    MRT_MUTEXT_TYPE mMutex;
#endif

};

extern "C"
{
#endif

eeprom_t* new_eeprom(mrt_i2c_handle_t handle, uint8_t addr, uint64_t size,uint32_t pageSize );
void eeprom_read(eeprom_t * pEeprom, uint16_t address, uint8_t* data, uint8_t len);
void eeprom_write(eeprom_t * pEeprom, uint16_t address, uint8_t * data, uint8_t len);

#ifdef __cplusplus
}
}
#endif
