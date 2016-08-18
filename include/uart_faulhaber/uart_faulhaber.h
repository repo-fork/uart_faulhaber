#ifndef UART_FAULHABER 
#define UART_FAULHABER 

#include <sstream>
#include <string>
#include <SerialStream.h>

using namespace LibSerial ;    

class SerialHandle
{
	public:
		SerialHandle();
		~SerialHandle();
		void set_port(const char* const p_port_name);
		void set_baudRate(int p_baud_rate);
		void set_dataBits(int p_data_bits);
		void set_stopBit(int p_stop_bit);
		void set_parity(bool p_parity);
		void set_hardwareFlowControl(bool p_control);
		void writeData(std::string p_data);
		std::string readData();
		
	private:
    	SerialStream serial_port;
		int _baud_rate;
		int _data_bits;
		int _stop_bit;
		bool _flow_control;
};

#endif
