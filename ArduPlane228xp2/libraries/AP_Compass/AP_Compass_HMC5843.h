/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-
#ifndef AP_Compass_HMC5843_H
#define AP_Compass_HMC5843_H

#include "../AP_Common/AP_Common.h"
#include "../AP_Math/AP_Math.h"

#include "Compass.h"

// orientations for DIYDrones magnetometer
#define AP_COMPASS_COMPONENTS_UP_PINS_FORWARD ROTATION_NONE
#define AP_COMPASS_COMPONENTS_UP_PINS_FORWARD_RIGHT ROTATION_YAW_45
#define AP_COMPASS_COMPONENTS_UP_PINS_RIGHT ROTATION_YAW_90
#define AP_COMPASS_COMPONENTS_UP_PINS_BACK_RIGHT ROTATION_YAW_135
#define AP_COMPASS_COMPONENTS_UP_PINS_BACK ROTATION_YAW_180
#define AP_COMPASS_COMPONENTS_UP_PINS_BACK_LEFT ROTATION_YAW_225
#define AP_COMPASS_COMPONENTS_UP_PINS_LEFT ROTATION_YAW_270
#define AP_COMPASS_COMPONENTS_UP_PINS_FORWARD_LEFT ROTATION_YAW_315
#define AP_COMPASS_COMPONENTS_DOWN_PINS_FORWARD ROTATION_ROLL_180
#define AP_COMPASS_COMPONENTS_DOWN_PINS_FORWARD_RIGHT ROTATION_ROLL_180_YAW_45
#define AP_COMPASS_COMPONENTS_DOWN_PINS_RIGHT ROTATION_ROLL_180_YAW_90
#define AP_COMPASS_COMPONENTS_DOWN_PINS_BACK_RIGHT ROTATION_ROLL_180_YAW_135
#define AP_COMPASS_COMPONENTS_DOWN_PINS_BACK ROTATION_PITCH_180
#define AP_COMPASS_COMPONENTS_DOWN_PINS_BACK_LEFT ROTATION_ROLL_180_YAW_225
#define AP_COMPASS_COMPONENTS_DOWN_PINS_LEFT ROTATION_ROLL_180_YAW_270
#define AP_COMPASS_COMPONENTS_DOWN_PINS_FORWARD_LEFT ROTATION_ROLL_180_YAW_315
#define AP_COMPASS_APM2_SHIELD ROTATION_NONE

// orientations for Sparkfun magnetometer
#define AP_COMPASS_SPARKFUN_COMPONENTS_UP_PINS_FORWARD ROTATION_YAW_270
#define AP_COMPASS_SPARKFUN_COMPONENTS_UP_PINS_FORWARD_RIGHT ROTATION_YAW_315
#define AP_COMPASS_SPARKFUN_COMPONENTS_UP_PINS_RIGHT ROTATION_NONE
#define AP_COMPASS_SPARKFUN_COMPONENTS_UP_PINS_BACK_RIGHT ROTATION_YAW_45
#define AP_COMPASS_SPARKFUN_COMPONENTS_UP_PINS_BACK ROTATION_YAW_90
#define AP_COMPASS_SPARKFUN_COMPONENTS_UP_PINS_BACK_LEFT ROTATION_YAW_135
#define AP_COMPASS_SPARKFUN_COMPONENTS_UP_PINS_LEFT ROTATION_YAW_180
#define AP_COMPASS_SPARKFUN_COMPONENTS_UP_PINS_FORWARD_LEFT ROTATION_YAW_225
#define AP_COMPASS_SPARKFUN_COMPONENTS_DOWN_PINS_FORWARD ROTATION_ROLL_180_YAW_90
#define AP_COMPASS_SPARKFUN_COMPONENTS_DOWN_PINS_FORWARD_RIGHT ROTATION_ROLL_180_YAW_135
#define AP_COMPASS_SPARKFUN_COMPONENTS_DOWN_PINS_RIGHT ROTATION_PITCH_180
#define AP_COMPASS_SPARKFUN_COMPONENTS_DOWN_PINS_BACK_RIGHT ROTATION_ROLL_180_YAW_225
#define AP_COMPASS_SPARKFUN_COMPONENTS_DOWN_PINS_BACK ROTATION_ROLL_180_YAW_270
#define AP_COMPASS_SPARKFUN_COMPONENTS_DOWN_PINS_BACK_LEFT ROTATION_ROLL_180_YAW_315
#define AP_COMPASS_SPARKFUN_COMPONENTS_DOWN_PINS_LEFT ROTATION_ROLL_180
#define AP_COMPASS_SPARKFUN_COMPONENTS_DOWN_PINS_FORWARD_LEFT ROTATION_ROLL_180_YAW_45

class AP_Compass_HMC5843 : public Compass
{
  private:
	float calibration[3];
	virtual bool read_raw(void);
    uint8_t _base_config;
	virtual bool re_initialise(void);
    bool read_register(uint8_t address, uint8_t *value);
    bool write_register(uint8_t address, byte value);
    uint32_t _retry_time; // when unhealthy the millis() value to retry at

  public:
	AP_Compass_HMC5843() : Compass() {}
	virtual bool init(void);
	virtual bool read(void);
	virtual void set_orientation(const Matrix3f &rotation_matrix);

};
#endif
