#include <iostream>
#include <ros/ros.h>
#include <uart_faulhaber/uart_faulhaber.h>


using namespace LibSerial ;    

//open the serial port
SerialHandle::SerialHandle()
{
}

SerialHandle::~SerialHandle()
{
    serial_port.Close();
}

void SerialHandle::set_port(const char* const p_port_name)
{
	const char* const SERIAL_PORT_DEVICE = p_port_name;
    serial_port.Open( SERIAL_PORT_DEVICE ) ;
    if ( ! serial_port.good() ) 
    {
        std::cerr << "Error: Could not open serial port " 
                  << SERIAL_PORT_DEVICE 
                  << std::endl ;
        exit(1) ;
    }
}

//set baud rate
void SerialHandle::set_baudRate(int p_baud_rate)
{
	_baud_rate= p_baud_rate;
	if(_baud_rate == 9600)
	{
		serial_port.SetBaudRate(SerialStreamBuf::BAUD_9600);
		if ( ! serial_port.good() ) 
		{
			std::cerr << "Error: Could not set the baud rate." << std::endl ;
			exit(1) ;
		}
	}
	else
	{
		ROS_ERROR("TO DO: modify code to fit other baud rate");
		exit(1);
	}
}

//set the num of data bits
void SerialHandle::set_dataBits(int p_data_bits)
{
	_data_bits= p_data_bits;
	if(_data_bits == 8)
	{
		serial_port.SetCharSize( SerialStreamBuf::CHAR_SIZE_8 ) ;
		if ( ! serial_port.good() ) 
		{
			std::cerr << "Error: Could not set the character size." << std::endl ;
			exit(1) ;
		}
	}
	else
	{
		ROS_ERROR("TO DO: modify code to fit other data bits.");
		exit(1);
	}
}

//set stop bit
void SerialHandle::set_stopBit(int p_stop_bit)
{
	_stop_bit= p_stop_bit;
	serial_port.SetNumOfStopBits(_stop_bit) ;
    if ( ! serial_port.good() ) 
    {
        std::cerr << "Error: Could not set the number of stop bits."
                  << std::endl ;
        exit(1) ;
    }

}

//set parity
void SerialHandle::set_parity(bool p_parity)
{
	//disable parity
	if(!p_parity)
	{
		serial_port.SetParity( SerialStreamBuf::PARITY_NONE ) ;
		if ( ! serial_port.good() ) 
		{
			std::cerr << "Error: Could not disable the parity." << std::endl ;
			exit(1) ;
		}
	}
	else
	{
		ROS_ERROR("TODO: enble parity");
		exit(1);
	}
}

//set hardware flow control
void SerialHandle::set_hardwareFlowControl(bool p_control)
{
	//enable hardware flow control
	if(!p_control)
	{
		serial_port.SetFlowControl( SerialStreamBuf::FLOW_CONTROL_NONE ) ;
		if ( ! serial_port.good() ) 
		{
			std::cerr << "Error: Could not use hardware flow control."
					  << std::endl ;
			exit(1) ;
		}
	}
	else
	{
		ROS_ERROR("TODO: disable flow contorl");
		exit(1);
	}
}

//write data
void SerialHandle::writeData(std::string p_data)
{
//	std::cerr << "Dumping file to serial port." << std::endl ;
//	ROS_INFO("%s\n", p_data.c_str());
	serial_port << p_data << std::endl ;
//    std::cerr << std::endl ;
//    std::cerr << "Done." << std::endl ;
}

void SerialHandle::readData()
{
#if 0
    while( serial_port.rdbuf()->in_avail() == 0 ) 
    {
        usleep(100) ;
    }
#endif
    //
    // Keep reading data from serial port and print it to the screen.
    //
    while( serial_port.rdbuf()->in_avail() > 0  ) 
    {
        char next_byte;
        serial_port.get(next_byte);
        std::cerr << next_byte;
        //usleep(100) ;
    } 
    std::cerr << std::endl ;

}
