#ifndef APM_BMP085_h
#define APM_BMP085_h


class APM_BMP085_Class
{
  private:
    // State machine
    uint8_t BMP085_State;
	// Internal calibration registers
	int16_t ac1, ac2, ac3, b1, b2, mb, mc, md;
    uint16_t ac4, ac5, ac6;
	void Command_ReadPress();
	void Command_ReadTemp();
	void ReadPress();
	void ReadTemp();
	void Calculate();

  public:
	int32_t RawPress;
	int32_t RawTemp;
	int16_t Temp;
	int32_t Press;
	//int Altitude;
	uint8_t oss;
	//int32_t Press0;  // Pressure at sea level

	APM_BMP085_Class();  // Constructor
	void Init(int initialiseWireLib = 1);
	uint8_t Read();
};

class APM_BMP085_HIL_Class
{
  private:
    uint8_t BMP085_State;
  public:
	int32_t RawPress;
	int32_t RawTemp;
	int16_t Temp;
	int32_t Press;
	//int Altitude;
	uint8_t oss;
	APM_BMP085_HIL_Class();  // Constructor
	void Init(int initialiseWireLib = 1);
	uint8_t Read();
    void setHIL(float Temp, float Press);
};

#endif
